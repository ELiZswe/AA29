// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "Powerups.generated.h"

class APickup;
UCLASS()
class APowerups : public AInventory
{
	GENERATED_BODY()
public:
	APowerups();

	UPROPERTY(EditAnywhere)								USoundBase* DeActivateSound;							//var() Sound DeActivateSound;
	UPROPERTY(EditAnywhere)								USoundBase* ActivateSound;								//var() Sound ActivateSound;
	UPROPERTY()																int32 NumCopies;										//var travel int NumCopies;
	UPROPERTY(EditAnywhere)								bool bCanHaveMultipleCopies;							//var() bool bCanHaveMultipleCopies;    // if player can possess more than one of this
	UPROPERTY(EditAnywhere)								bool bAutoActivate;										//var() bool bAutoActivate;				// automatically activated when picked up
	UPROPERTY(EditAnywhere)								bool bActivatable;										//var() bool bActivatable;				// Whether item can be activated/deactivated (if true, must auto activate)
	UPROPERTY()																bool bActive;											//var travel bool bActive;			// Whether item is currently activated.
	UPROPERTY(EditAnywhere)								FString ExpireMessage;									//var() localized String ExpireMessage; // Messages shown when powerup charge runs out

	void TravelPreAccept();
	void PickupFunction(APawn* Other);
	APowerups* SelectNext();
	void Activate();
	bool HandlePickupQuery(APickup* Item);
	float UseCharge(float Amount);
	void FireEffect();
	void UsedUp();
	FString GetLocalString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2);
};
