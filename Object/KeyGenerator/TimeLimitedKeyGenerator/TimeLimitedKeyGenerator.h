// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/KeyGenerator/KeyGenerator.h"
#include "TimeLimitedKeyGenerator.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTimeLimitedKeyGenerator : public UKeyGenerator
{
	GENERATED_BODY()
public:
	UTimeLimitedKeyGenerator();

	UPROPERTY()				bool			KeyGenerationIsComplete;	//var bool KeyGenerationIsComplete;
	UPROPERTY()				float			StartTime;					//var float StartTime;
	UPROPERTY()				float			TimeLimit;					//var float TimeLimit;
	UPROPERTY()				FString			PregeneratedKeyName;		//var FString PregeneratedKeyName;

	float GetTime();
	bool CopyFile(FString Dest, FString Source);
	void CancelKeyGeneration();
	void BeginKeyGeneration();
	bool IsKeyGenerationComplete();
	void InstallPregeneratedKey();
};
