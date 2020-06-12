// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GigaMovementComponent.generated.h"


UENUM(BlueprintType)
enum EGravityScaleType {
	GST_DEFAULT UMETA(DisplayName = "Default = Jumping and falling scale set by user"),
	GST_CUSTOM UMETA(DisplayName = "Custom = Gravity Scale set by CalculateCustomGravityScale function in blueprints"),
	GST_NORMAL UMETA(DisplayName = "Normal = use UE4's gravity scale"),
};



/**
 * 
 */
UCLASS()
class GIGAMOVEMENT_API UGigaMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:

	/**
	 * Default UObject constructor.
	 */
	UGigaMovementComponent();

public:

	UPROPERTY(Category = "Advanced Movement", EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EGravityScaleType> GravityScaleType = EGravityScaleType::GST_DEFAULT;

	//Base gravity scale. Use this instead of GravityScale in base component
	UPROPERTY(Category = "Advanced Movement", EditAnywhere, BlueprintReadWrite)
		float BaseGravityScale = 1.0f;
	UPROPERTY(Category = "Advanced Movement", EditAnywhere, BlueprintReadWrite)
		float JumpingScale = 1.0f;
	UPROPERTY(Category = "Advanced Movement", EditAnywhere, BlueprintReadWrite)
		float FallingScale = 2.0f;


public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:


	UFUNCTION(Category = "Advanced Movement", BlueprintCallable)
		float CalculateNewGravityScale();


	UFUNCTION(Category = "Advanced Movement", BlueprintCallable)
		float CalculateJumpingGravityScale();

	UFUNCTION(Category = "Advanced Movement", BlueprintCallable)
		float CalculateFallingGravityScale();


	UFUNCTION(Category = "Advanced Movement", BlueprintCallable)
		float CalculateDefaultGravityScale();

	UFUNCTION(Category = "Advanced Movement", BlueprintImplementableEvent)
		float CalculateCustomGravityScale();


	// public:
	// 	//Sets the base gravity scale
	// 	UFUNCTION(Category = "Advanced Movement", BlueprintCallable)
	// 	void SetBaseGravityScale(float NewGravityScale) {BaseGravityScale = NewGravityScale;};
	// 	//Gets the base gravity scale
	// 	UFUNCTION(Category = "Advanced Movement", BlueprintCallable)
	// 	float GetBaseGravityScale() {return BaseGravityScale;};
};
