// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	auto ElavationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElavation = RelativeRotation.Pitch + ElavationChange;
	auto Elavation = FMath::Clamp<float>(RawNewElavation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elavation, 0, 0));
}


