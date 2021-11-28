// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpBeacon/UdpBeacon.h"
#include "ClientBeaconReceiver.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AClientBeaconReceiver : public AUdpBeacon
{
	GENERATED_BODY()
public:
	AClientBeaconReceiver();

	UPROPERTY()						TArray<FBeaconInfo> Beacons;			//var BeaconInfo Beacons;
	UPROPERTY()						bool _bSleep;							//var bool _bSleep;

	int32 GetBeaconCount();
	FString GetBeaconAddress(int32 i);
	FString GetBeaconText(int32 i);
	void BeginPlay();
	void Timer();
	void BroadcastQuery();
	void ReceivedText(FIpAddr Addr, FString Text);
	void UpdateUI();
	void BroadcastBeacon(FIpAddr Addr);
	void StartBeacon();
	void StopBeacon();
	int32 GetBeaconAddressAddr(int32 i);

};





