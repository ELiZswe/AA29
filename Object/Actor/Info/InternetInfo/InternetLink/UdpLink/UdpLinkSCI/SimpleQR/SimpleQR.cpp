// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpLinkSCI/SimpleQR/SimpleQR.h"
#include "AA29/AA2_WorldSettings.h"

ASimpleQR::ASimpleQR()
{
	bNeedResolve = true;
	simplembsdomain = "simplembs.armygame.com";
	bRespondToPings = true;
	//bAlwaysTick = true;
}

void ASimpleQR::PreBeginPlay()
{
	//Super::PreBeginPlay();
	myIdx = FMath::RandRange(0,2147483647) + FMath::RandRange(0,2147483647);
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer())
	{
		UE_LOG(LogTemp, Warning, TEXT("SimpleQR: This is a LAN server."));
		//Disable('Tick');
		return;
	}
	bNeedResolve = true;
	Resolve(simplembsdomain);
}
void ASimpleQR::Resolved(FIpAddr Addr)
{
	bNeedResolve = false;
	mbsIP = Addr.Addr;
	//SetTimer(0.1, false);		// heartbeat immediately.
}
void ASimpleQR::ResolveFailed()
{
	bNeedResolve = true;
	mbsIP = 0;
	//SetTimer(3600, false);// look it up again later...
}
void ASimpleQR::Destroyed()
{
	UE_LOG(LogTemp, Warning, TEXT("SimpleQR: Destroying..."));
	//SetTimer(0, false);
	//Disable('Tick');
	bRespondToPings = false;		// just in case.
	Super::Destroyed();				
}
void ASimpleQR::Tick(float DeltaTime)
{
	int32 IP;
	int32 idx;
	while (GetPing(IP, idx))
	{
		// no-op...GetPing will dole out responses.
	}
}
void ASimpleQR::Timer()
{
	if (bNeedResolve)
	{
		Resolve(simplembsdomain);
		//SetTimer(3600, false);		// if DNS fails, wait an hour to try again.
		return;
	}
	SendPing(mbsIP, myIdx);
	//SetTimer(60, false);				// ping once a minute.
}