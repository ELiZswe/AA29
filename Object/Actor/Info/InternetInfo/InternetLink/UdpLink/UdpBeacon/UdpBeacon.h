// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpLink.h"
#include "UdpBeacon.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AUdpBeacon : public AUdpLink
{
	GENERATED_BODY()
public:
	AUdpBeacon();


	UPROPERTY()						int32 boundport;							//var int boundport;
	UPROPERTY()						int32 UdpServerQueryPort;					//var int UdpServerQueryPort;
	UPROPERTY(globalconfig)			FString BeaconProduct;						//var() globalconfig string BeaconProduct;
	UPROPERTY(globalconfig)			float BeaconTimeout;						//var() globalconfig float BeaconTimeout;
	UPROPERTY(globalconfig)			int32 BeaconPort;							//var() globalconfig int BeaconPort;
	UPROPERTY(globalconfig)			int32 ServerBeaconPort;						//var() globalconfig int ServerBeaconPort;
	UPROPERTY(globalconfig)			bool DoBeacon;								//var() globalconfig bool DoBeacon;

	void BeginPlay();
	void BroadcastBeacon(FIpAddr Addr);
	void BroadcastBeaconQuery(FIpAddr Addr);
	void ReceivedText(FIpAddr Addr, FString Text);
	void Destroyed();

};
