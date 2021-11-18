// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/InternetInfo/InternetLink/UdpLink/UdpLink.h"
#include "UdpLinkSCI.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AUdpLinkSCI : public AUdpLink
{
	GENERATED_BODY()
public:
		AUdpLinkSCI();

		UPROPERTY()			uint8 packet;								//var byte packet;
		UPROPERTY()			bool bRespondToPings;						//var bool bRespondToPings;
		UPROPERTY()			int32 udpport;								//var int udpport;




		void PostBeginPlay();
		void SendPing(int32 IP, int32 idx);
		bool SendPong(FIpAddr Addr, int32 idx);
		bool GetPingPacket(int32 &IP, int32 &idx, int32 &packetSize);
		bool GetPing(int32 &IP, int32 &idx);
};
