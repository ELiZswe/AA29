// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpLink.h"
#include "UdpGamespyUplink.generated.h"

class AUdpGamespyQuery;

UCLASS()
class AA29_API AUdpGamespyUplink : public AUdpLink
{
	GENERATED_BODY()
public:
	AUdpGamespyUplink();


	UPROPERTY()						int32 CurrentQueryNum;						//var int CurrentQueryNum;
	UPROPERTY()						AUdpGamespyQuery* Query;					//var UdpGamespyQuery Query;
	UPROPERTY()						FString HeartbeatMessage;					//var string HeartbeatMessage;
	UPROPERTY()						FIpAddr MasterServerIpAddr;					//var InternetLink.IpAddr MasterServerIpAddr;
	UPROPERTY()						FName TargetQueryName;						//var() name TargetQueryName;
	UPROPERTY(Config)				int32 ServerRegion;							//var() config int ServerRegion;
	UPROPERTY(Config)				int32 MasterServerPort;						//var() config int MasterServerPort;
	UPROPERTY(Config)				FString MasterServerAddress;				//var() string MasterServerAddress;
	UPROPERTY(Config)				int32 UpdateMinutes;						//var() config int UpdateMinutes;

	void PreBeginPlay();
	void Resolved(FIpAddr Addr);
	void ResolveFailed();
	void Timer();
	void Halt();
	void Resume();
	void ReceivedText(FIpAddr Addr, FString Text);
	void ParseNextQuery(FString aQuery, FString &QueryType, FString &QueryValue, FString &QueryRest, FString &FinalPacket);
	void ParseQuery(FIpAddr Addr, FString QueryStr, int32 QueryNum, int32 &PacketNum);
	void SendQueryPacket(FIpAddr Addr, FString SendString, int32 QueryNum, int32 PacketNum, FString FinalPacket);

};
