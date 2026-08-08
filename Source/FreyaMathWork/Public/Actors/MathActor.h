// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MathActor.generated.h"

UCLASS()
class FREYAMATHWORK_API AMathActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AMathActor();

protected:
	
	virtual void BeginPlay() override;



};
