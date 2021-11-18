// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Base3pAmmoRound/Base3pAmmoRound.h"
#include "AmmoRound_3P_Javelin.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAmmoRound_3P_Javelin : public ABase3pAmmoRound
{
	GENERATED_BODY()
public:
	AAmmoRound_3P_Javelin();

	virtual void ShowRound(bool bShouldShowRound) override;
};



