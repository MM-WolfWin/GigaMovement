// Fill out your copyright notice in the Description page of Project Settings.


#include "GigaMovementComponent.h"


UGigaMovementComponent::UGigaMovementComponent()
{

}

void UGigaMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	GravityScale = CalculateNewGravityScale();
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

float UGigaMovementComponent::CalculateNewGravityScale()
{
	switch (GravityScaleType)
	{
	case GST_DEFAULT:
		return CalculateDefaultGravityScale();
		break;
	case GST_CUSTOM:
		return CalculateCustomGravityScale();
		break;
	default:
		return BaseGravityScale;
		break;
	}
}

float UGigaMovementComponent::CalculateJumpingGravityScale()
{
	return JumpingScale * BaseGravityScale;
}

float UGigaMovementComponent::CalculateFallingGravityScale()
{
	return FallingScale * BaseGravityScale;
}

float UGigaMovementComponent::CalculateDefaultGravityScale()
{
	if (this->IsFalling() && Velocity.Z < 0) {
		return CalculateFallingGravityScale();
	}

	return CalculateJumpingGravityScale();
}
