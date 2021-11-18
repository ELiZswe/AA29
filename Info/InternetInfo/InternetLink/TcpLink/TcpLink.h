// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/InternetInfo/InternetLink/InternetLink.h"
#include "TcpLink.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATcpLink : public AInternetLink
{
	GENERATED_BODY()
public:
	ATcpLink();

	UPROPERTY()			bool bReceiveLongMessages;						//var bool bReceiveLongMessages;
	UPROPERTY()			FString RecvBuf;								//var const string RecvBuf;
	UPROPERTY()			TArray<uint8> SendFIFO;							//var const array<byte> SendFIFO;
	UPROPERTY()			ATcpLink* AcceptClass;							//var class<TcpLink> AcceptClass;
	UPROPERTY()			FIpAddr RemoteAddr;								//var InternetLink.IpAddr RemoteAddr;

	void BindPort(int32 aPort, bool bUseNextAvailable);
	void Listen();
	void Open(FIpAddr Addr);
	void Close();
	void HardClose(bool bPerformClosedEventCallback);
	void IsConnected();
	void SendText(FString str);
	void SendBinary(int32 Count, uint8 B);
	void SendLongBinary(int32 Count, int32 B);
	void ReadText(FString str);
	void ReadBinary(int32 Count, uint8 B);
	void ReadLongBinary(int32 Count, int32& B);
	void Accepted();
	void Opened();
	void Closed();
	void ReceivedText(FString Text);
	void ReceivedLine(FString Line);
	void ReceivedBinary(int32 Count, uint8 B);
	void ReceivedLongBinary(int32 Count, int32 B);

};
