// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DamageType/AGP_DamageType/RocketImpact/RocketImpact.h"
#include "JavelinImpactDamage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UJavelinImpactDamage : public URocketImpact
{
	GENERATED_BODY()
public:
	UJavelinImpactDamage();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString AltDeathString;			//var() localized string AltDeathString;


	//void DeathMessage(PlayerReplicationInfo Killer, PlayerReplicationInfo Victim)
};
