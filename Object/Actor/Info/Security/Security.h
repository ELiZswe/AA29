// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "Security.generated.h"

UCLASS()
class ASecurity : public AAA2_Info
{
	GENERATED_BODY()
public:
	ASecurity();

	UPROPERTY()			TArray<FString> LastParams;					//var string LastParams;
	UPROPERTY()			int32 LastType;						//var int LastType;

	void NativePerform(int32 SecType, FString Param1, FString Param2);
	void LocalPerform(int32 SecType, FString Param1, FString Param2, TArray<FString>& Results);
	void ClientPerform(int32 SecType, FString Param1, FString Param2);
	void ServerCallback(int32 SecType, FString Data);
	void Perform(int32 SecType, FString Param1, FString Param2, float TimeOut);
	void BadClient(int32 Code, FString Data);
	void ClientMessage(FString S);
};
