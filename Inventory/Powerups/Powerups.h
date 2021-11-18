// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Inventory.h"
#include "Powerups.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APowerups : public AInventory
{
	GENERATED_BODY()
public:
	APowerups();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)								USoundBase* DeActivateSound;							//var() Sound DeActivateSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								USoundBase* ActivateSound;								//var() Sound ActivateSound;
	UPROPERTY()																int32 NumCopies;										//var travel int NumCopies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bCanHaveMultipleCopies;							//var() bool bCanHaveMultipleCopies;    // if player can possess more than one of this
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bAutoActivate;										//var() bool bAutoActivate;				// automatically activated when picked up
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bActivatable;										//var() bool bActivatable;				// Whether item can be activated/deactivated (if true, must auto activate)
	UPROPERTY()																bool bActive;											//var	travel bool   bActive;			// Whether item is currently activated.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FString ExpireMessage;									//var() localized String ExpireMessage; // Messages shown when powerup charge runs out


	void TravelPreAccept();
	void PickupFunction(APawn* Other);
	void SelectNext();
	void Activate();
	void HandlePickupQuery(APickup* Item);
	void UseCharge(float Amount);
	void FireEffect();
	void UsedUp();
	//void GetLocalString(int32 Switch, AAA2_PlayerState*  RelatedPRI_1, AAA2_PlayerState*  RelatedPRI_2);

};
