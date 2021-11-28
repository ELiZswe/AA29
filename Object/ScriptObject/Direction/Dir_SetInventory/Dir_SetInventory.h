// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Direction/Direction.h"
#include "Dir_SetInventory.generated.h"

class AAGP_InventoryModifier;
class AAGP_Pawn;

/**
 * 
 */
UCLASS()
class AA29_API UDir_SetInventory : public UDirection
{
	GENERATED_BODY()
public:
	UDir_SetInventory();

	UPROPERTY()						AAGP_InventoryModifier* _InvMod;		//var AGP_Gameplay.AGP_InventoryModifier _InvMod;
	UPROPERTY()						AAGP_Pawn* _Pawn;						//var AGP_Pawn _Pawn;
	UPROPERTY()						AActor* _Actor;							//var Actor _Actor;

	void Destroyed();
	void DirectionStart();
	void DirectionFinish();
	bool ProcessParams();
	void SetInventoryModifier(AAGP_InventoryModifier* invmod);
	void SetPawn(AAGP_Pawn* Pawn);
	void SetActor(AActor* Actor);
};
