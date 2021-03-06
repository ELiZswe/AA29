// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_GabrielGoArmy.generated.h"

class AHttpGet;
class ALinksParser;
class ATriggerURL;

class AAGP_UseTrigger;
class ANPC_SpecialForces;
UCLASS()
class AEL_GabrielGoArmy : public AEventLab
{
	GENERATED_BODY()

public:
	AEL_GabrielGoArmy();

	UPROPERTY()												AAGP_UseTrigger* UseTrigger_GoArmyGuy;		//var AGP.AGP_UseTrigger UseTrigger_GoArmyGuy;
	UPROPERTY()												AAGP_UseTrigger* Trigger_GOARMY;			//var AGP.AGP_UseTrigger Trigger_GOARMY;
	UPROPERTY()												ATriggerVolume* GoArmyGuy_Trigger;			//var AGP_Gameplay.TriggerVolume GoArmyGuy_Trigger;
	UPROPERTY()												ANPC_SpecialForces* GoArmyGuy;				//var AGP_Characters.NPC_SpecialForces GoArmyGuy;
	UPROPERTY()												TArray<ATriggerURL*> URLTriggers;			//var array<TriggerURL> URLTriggers;
	UPROPERTY()												bool _HttpError;							//var bool _HttpError;
	UPROPERTY()												ALinksParser* _Links;						//var LinksParser _Links;
	UPROPERTY()												AHttpGet* _Http;							//var IpDrv.HttpGet _Http;

	ALinksParser* GetLinksParser();
	bool TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool GoArmyGuy_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool TriggerVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool GoArmyGuy_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool Trigger_GOARMY_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool GoArmyGuy_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	void PreInit();
	void Init();
	void PostInit();
	void PostPostInit();
	void DestroyHttp();
	AHttpGet* EstablishHttp();
	ALinksParser* ParseLinks();
	void WriteLinks();
	bool Timer_Timer(FName Name);
	void Destroyed();
};
