// Fill out your copyright notice in the Description page of Project Settings.


#include "Math/MathComponent.h"

#include "MathHelper.h"


UMathComponent::UMathComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void UMathComponent::BeginPlay()
{
	Super::BeginPlay();
   Debug::PrintMessage(TEXT("Debug Works"));
}



void UMathComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

