// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/InternetLink.h"
#include "TcpLink.generated.h"

UCLASS()
class ATcpLink : public AInternetLink
{
	GENERATED_BODY()
public:
	ATcpLink();

	UPROPERTY()			bool			bReceiveLongMessages;			//var bool bReceiveLongMessages;
	UPROPERTY()			FString			RecvBuf;						//var const string RecvBuf;
	UPROPERTY()			TArray<uint8>	SendFIFO;						//var const array<byte> SendFIFO;
	UPROPERTY()			ATcpLink*		AcceptClass;					//var class<TcpLink> AcceptClass;
	UPROPERTY()			FIpAddr			RemoteAddr;						//var InternetLink.IpAddr RemoteAddr;

	int32 BindPort(int32 aPort, bool bUseNextAvailable);
	bool Listen();
	bool Open(FIpAddr Addr);
	bool Close();
	bool HardClose(bool bPerformClosedEventCallback);
	bool IsConnected();
	int32 SendText(FString str);
	int32 SendBinary(int32 Count, uint8 B);
	int32 SendLongBinary(int32 Count, int32 B);
	int32 ReadText(FString& str);
	int32 ReadBinary(int32 Count, uint8& B);
	int32 ReadLongBinary(int32 Count, int32& B);
	void Accepted();
	void Opened();
	void Closed();
	void ReceivedText(FString Text);
	void ReceivedLine(FString Line);
	void ReceivedBinary(int32 Count, uint8 B);
	void ReceivedLongBinary(int32 Count, int32 B);
};
