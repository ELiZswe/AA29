// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetPlayerInventory.generated.h"

//class AAGP_InventoryModifier;
class AHumanController;

UCLASS()
class AA29_API UDir_SetPlayerInventory : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetPlayerInventory();

	//UPROPERTY()						AAGP_InventoryModifier* _InvMod;				//var AGP_Gameplay.AGP_InventoryModifier _InvMod;
	UPROPERTY()						AHumanController* _HumanController;				//var HumanController _HumanController;
	
	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();

};
