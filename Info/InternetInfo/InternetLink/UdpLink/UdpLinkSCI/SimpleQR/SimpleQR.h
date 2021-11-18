// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/InternetInfo/InternetLink/UdpLink/UdpLinkSCI/UdpLinkSCI.h"
#include "SimpleQR.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASimpleQR : public AUdpLinkSCI
{
	GENERATED_BODY()
public:
	ASimpleQR();

	UPROPERTY()			int32 mbsIP;								//var int mbsIP;
	UPROPERTY()			FString simplembsdomain;					//var string simplembsdomain;
	UPROPERTY()			bool bNeedResolve;							//var bool bNeedResolve;
	UPROPERTY()			int32 myIdx;								//var int myIdx;

	void PreBeginPlay();
	void Resolved(FIpAddr Addr);
	void ResolveFailed();
	void Destroyed();
	void Tick(float DeltaTime);
	void Timer();
};


