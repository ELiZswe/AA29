// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_GabrielGoArmy.generated.h"

class AHttpGet;
class ALinksParser;
class ATriggerURL;

UCLASS()
class AA29_API AEL_GabrielGoArmy : public AEventLab
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
};
