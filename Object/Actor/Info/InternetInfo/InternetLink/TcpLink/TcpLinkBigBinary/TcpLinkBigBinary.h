// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"
#include "TcpLinkBigBinary.generated.h"

UCLASS()
class ATcpLinkBigBinary : public ATcpLink
{
	GENERATED_BODY()
public:
	ATcpLinkBigBinary();

	UPROPERTY()			bool			bUseBigBinaryBuffer;		//var bool bUseBigBinaryBuffer;
	UPROPERTY()			TArray<uint8>	BigBinaryBuffer;			//var const array<byte> BigBinaryBuffer;

	int32 SendBigBinary(int32 Count);
	void ReceivedBigBinary(int32 Count);
};
