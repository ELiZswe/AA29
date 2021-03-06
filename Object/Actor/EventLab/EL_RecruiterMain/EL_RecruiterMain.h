// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_RecruiterMain.generated.h"

class AHttpGet;
class ATriggerVolume;
class ATriggerURL;
class ALinksParser;
UCLASS()
class AEL_RecruiterMain : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_RecruiterMain();

	UPROPERTY()						ATriggerVolume* VolumeBuilding;										//var AGP_Gameplay.TriggerVolume VolumeBuilding;
	UPROPERTY()						AHttpGet* _Http;													//var IpDrv.HttpGet _Http;
	UPROPERTY()						ALinksParser* _Links;												//var LinksParser _Links;
	UPROPERTY()						bool _HttpError;													//var bool _HttpError;
	UPROPERTY()						TArray<ATriggerURL*> URLTriggers;									//var array<TriggerURL> URLTriggers;

	bool TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool TriggerVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	void PreInit();
	void Init();
	void PostInit();
	void PostPostInit();
	void DestroyHttp();
	AHttpGet* EstablishHttp();
	ALinksParser* ParseLinks();
	void WriteLinks();
	bool Timer_Timer(FName Name);
	bool VolumeBuilding_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool VolumeBuilding_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	void Destroyed();
};
