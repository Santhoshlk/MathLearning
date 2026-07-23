#pragma once
#include "CoreMinimal.h"

namespace Debug
{
	static void PrintMessage(const FString& DebugMessage,uint64 key = -1,float DisplayTime = 5.f,FColor Color = FColor::MakeRandomColor())
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(key,DisplayTime,Color,DebugMessage);
		}
		UE_LOG(LogTemp,Warning,TEXT("%s"),*DebugMessage);
	}

	static void PrintDebugData(float Data ,const FString& DebugMessage,uint64 key = -1,float DisplayTime = 5.f,FColor Color = FColor::MakeRandomColor())
	{
		const FString Message = DebugMessage + FString::Printf(TEXT("%s"),*FString::SanitizeFloat(Data));
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(key,DisplayTime,Color,Message);
		}
		UE_LOG(LogTemp,Warning,TEXT("%s"),*Message);
	}
}