// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HttpLinkItem.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHttpLinkItem : public UObject
{
	GENERATED_BODY()
public:
	UHttpLinkItem();

	UPROPERTY()									TArray<uint8> BinaryFromServer;			//var array<byte> BinaryFromServer;
	UPROPERTY()									FString TextFromServer;					//var string TextFromServer;
	UPROPERTY()									bool bIsBinary;							//var bool bIsBinary;
	UPROPERTY()									FString HTTPHeader;						//var string HTTPHeader;
	UPROPERTY()									FString GetRequest;						//var string GetRequest;
	UPROPERTY()									FString Filename;						//var string Filename;

	void OnReceivedBinary(FString ReceivedFileName, TArray<uint8> ReceivedFile);
	void OnReceivedText(FString ReceivedFileName, FString ReceivedFile);
	void OnReceivedCachedFile(FString ReceivedFileName);
};
