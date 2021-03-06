// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/DamageType/AGP_DamageType/RocketImpact/RocketImpact.h"
#include "JavelinImpactDamage.generated.h"

UCLASS()
class UJavelinImpactDamage : public URocketImpact
{
	GENERATED_BODY()
public:
	UJavelinImpactDamage();
	
	UPROPERTY(EditAnywhere)		FString AltDeathString;			//var() localized string AltDeathString;

	FString DeathMessage(AAA2_PlayerState* Killer, AAA2_PlayerState* Victim);
};
