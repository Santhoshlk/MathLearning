// Fill out your copyright notice in the Description page of Project Settings.


#include "Math/MathComponent.h"
#include "DrawDebugHelpers.h"
#include "MathHelper.h"
#include "Actors/MathActor.h"


UMathComponent::UMathComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void UMathComponent::BeginPlay()
{
	Super::BeginPlay();
	 Owner = GetOwner();
	checkf(Owner,TEXT("There must always be a valid owner for the actor component"));
	checkf(Actor1 && Actor2,TEXT("There must always be a valid Actor 1 and 2 hard referneces"));
	// const FVector Dir = (Actor1->GetActorLocation() - Owner->GetActorLocation()).GetSafeNormal();
 //    const FVector Actor2Location = Actor2->GetActorLocation() - Owner->GetActorLocation();
	// float length = FVector::DotProduct(Dir,Actor2Location);
 //
	//
	// const FVector Position = Owner->GetActorLocation()+ Dir*length;
	// if (GEngine)
	// {
	//    UWorld* World = 	GEngine->GetWorldFromContextObject(this,EGetWorldErrorMode::LogAndReturnNull);
	// 	if (World)
	// 	{
	// 		
	// 		DrawDebugLine(World,Owner->GetActorLocation(),Actor1->GetActorLocation(),FColor::Green,true);
	// 		DrawDebugLine(World,Owner->GetActorLocation(),Actor2->GetActorLocation(),FColor::Green,true);
	// 		DrawDebugPoint(World,Position,10.f,FColor::Red,true);
	// 	}
	// }
	
	
}



void UMathComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UMathComponent::FacingTrigger()
{
	// here we are gonna use the owner and actor2
	checkf(Owner && Actor2,TEXT("Both the Character and the Actor need to be valid"));

	const FVector CharacterForward = Owner->GetActorForwardVector();
	const FVector Direction = (Actor2->GetActorLocation()-Owner->GetActorLocation()).GetSafeNormal();

	const float value = FVector::DotProduct(CharacterForward,Direction);

	const float angle = FMath::RadiansToDegrees(FMath::Acos(value));

	Debug::PrintDebugData(angle,TEXT("The Angle : "));
	if (angle <90.f)
	{
		UWorld* World = GetWorld();
		check(World);
		DrawDebugLine(World,Owner->GetActorLocation(),Actor2->GetActorLocation(),FColor::Green,false,2.f,0,1.f);
	}
	else
	{
		UWorld* World = GetWorld();
		check(World);
		DrawDebugLine(World,Owner->GetActorLocation(),Actor2->GetActorLocation(),FColor::Red,false,2.f,0,1.f);
	}
}

