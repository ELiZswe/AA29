// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseAmmoRound/BaseAmmoRound.h"
#include "AmmoRound_Javelin.generated.h"

UCLASS()
class AAmmoRound_Javelin : public ABaseAmmoRound
{
	GENERATED_BODY()
public:
	AAmmoRound_Javelin();

	void AdjustAmmoRound(int32 total_ammo);
};
