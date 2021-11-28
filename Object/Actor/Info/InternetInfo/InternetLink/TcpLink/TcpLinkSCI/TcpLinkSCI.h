// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"
#include "TcpLinkSCI.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATcpLinkSCI : public ATcpLink
{
	GENERATED_BODY()
public:
	ATcpLinkSCI();


	UPROPERTY()			FIpAddr IP;										//var InternetLink.IpAddr IP;
	UPROPERTY()			FString responseString;							//var string responseString;
	UPROPERTY()			uint8 responseHeader;							//var byte responseHeader;
	UPROPERTY()			int32 expectedBytes;							//var int expectedBytes;
	UPROPERTY()			int32 incomingBytesLeft;						//var int incomingBytesLeft;
	UPROPERTY()			bool bShouldBeConnected;						//var bool bShouldBeConnected;
	UPROPERTY()			bool bWorking;									//var bool bWorking;
	UPROPERTY()			bool bError;									//var bool bError;
	UPROPERTY()			int32 masterPort;								//var int masterPort;
	UPROPERTY()			FString masterHostname;							//var string masterHostname;
	UPROPERTY()			bool debugging;									//var bool debugging;


	void dlog(FString str);
	void convFromMetaChars(FString& S);
	void convToMetaChars(FString& S);
	bool StillProcessing();
	bool HadError();
	void Connect();
	void RequestRawXML(FString xml);
	void RequestServerCount(FString aGameType, FString extraxml);
	void RequestServerInfo(FString aGameType, FString Guid);
	void RequestServerList(FString aGameType, int32 page, int32 pagesize, FString extraxml);
	void RequestRegistration(FString aGameType, FString version, FString hostname, FString Addr, int32 aPort, int32 QueryPort, FString Map, int32 bPrivate, int32 NumPlayers, int32 MaxPlayers, FString modname, FString extraxml);
	void RequestHeartbeat(FString Guid);
	void GetCurrentResponseSize();
	void GetResponseString();
	void Disconnect();
	void PreBeginPlay();
	void Resolved(FIpAddr Addr);
	void ResolveFailed();
	void Opened();
	void SendRequestRawXML(FString xml);
	void SendRequest(FString aGameType, FString Action, FString extraxml);
	void ReceivedBinary(int32 Count, uint8 B);
	void ReceivedText(FString Text);
	void Closed();

};
