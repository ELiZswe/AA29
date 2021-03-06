// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/InternetLink.h"
#include "UdpLink.generated.h"

UCLASS()
class AUdpLink : public AInternetLink
{
	GENERATED_BODY()
public:
	AUdpLink();

	UPROPERTY()						FString RecvBuf;								//var const string RecvBuf;
	UPROPERTY(EditAnywhere)			int32 BroadcastAddr;							//var() const int BroadcastAddr;

	int32 BindPort(int32 APort, bool bUseNextAvailable);
	bool SendText(FIpAddr Addr, FString str);
	bool SendBinary(FIpAddr Addr, int32 Count, TArray<uint8> B);
	int32 ReadText(FIpAddr &Addr, FString &str);
	int32 ReadBinary(FIpAddr &Addr, int32 Count, uint8 &B);
	void ReceivedText(FIpAddr Addr, FString Text);
	void ReceivedLine(FIpAddr Addr, FString Line);
	void ReceivedBinary(FIpAddr Addr, int32 Count, uint8 B);
};

