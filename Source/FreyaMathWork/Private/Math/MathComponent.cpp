// Fill out your copyright notice in the Description page of Project Settings.


#include "Math/MathComponent.h"
#include "DrawDebugHelpers.h"
#include "Actors/MathActor.h"


UMathComponent::UMathComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void UMathComponent::BeginPlay()
{
	Super::BeginPlay();
	AActor* Owner = GetOwner();
	checkf(Owner,TEXT("There must always be a valid owner for the actor component"));
	checkf(Actor1 && Actor2,TEXT("There must always be a valid Actor 1 and 2 hard referneces"));
	const FVector Dir = (Actor1->GetActorLocation() - Owner->GetActorLocation()).GetSafeNormal();
    const FVector Actor2Location = Actor2->GetActorLocation() - Owner->GetActorLocation();
	float length = FVector::DotProduct(Dir,Actor2Location);

	
	const FVector Position = Owner->GetActorLocation()+ Dir*length;
	if (GEngine)
	{
	   UWorld* World = 	GEngine->GetWorldFromContextObject(this,EGetWorldErrorMode::LogAndReturnNull);
		if (World)
		{
			
			DrawDebugLine(World,Owner->GetActorLocation(),Actor1->GetActorLocation(),FColor::Green,true);
			DrawDebugLine(World,Owner->GetActorLocation(),Actor2->GetActorLocation(),FColor::Green,true);
			DrawDebugPoint(World,Position,10.f,FColor::Red,true);
		}
	}
	
	
}



void UMathComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

