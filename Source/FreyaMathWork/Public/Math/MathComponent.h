// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MathComponent.generated.h"


class AMathActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FREYAMATHWORK_API UMathComponent : public UActorComponent
{
	GENERATED_BODY()

   UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess = "true"),Category = "math")
	TObjectPtr<AMathActor> Actor1;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess = "true"),Category = "math")
	TObjectPtr<AMathActor> Actor2;
	
protected:
	
	virtual void BeginPlay() override;

public:	
	UMathComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
