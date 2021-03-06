// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AGP_InventoryModifier.generated.h"

class AInventory;
class AAGP_Pawn;

UCLASS()
class AAGP_InventoryModifier : public ATrigger
{
	GENERATED_BODY()
public:
	AAGP_InventoryModifier();

	UPROPERTY(EditAnywhere)		bool					bEmptyInventory;	//var() bool bEmptyInventory;
	UPROPERTY(EditAnywhere)		bool					bAddInventory;		//var() bool bAddInventory;
	UPROPERTY(EditAnywhere)		bool					bGiveNVG;			//var() bool bGiveNVG;
	UPROPERTY(EditAnywhere)		TArray<AInventory*>		InventoryList;		//var() class<Inventory> InventoryList[16];
	UPROPERTY()					AAGP_Pawn*				agpPawn;			//var AGP_Pawn agpPawn;

	void Touch(AActor* Other);
	void Run(AActor* Other);
	void AddInventory();
};
