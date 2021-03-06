// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/AGP_InventoryModifier/AGP_InventoryModifier.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/InventoryAttachment/BaseOptics/BaseOptics.h"

AAGP_InventoryModifier::AAGP_InventoryModifier()
{
	bGiveNVG = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Editor/Engine/AGP_InvMod_Mat.AGP_InvMod_Mat'"), NULL, LOAD_None, NULL);
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	bBlockBulletTraces = false;
	InventoryList.SetNum(16);
}

void AAGP_InventoryModifier::Touch(AActor* Other)
{
	//Super::Touch(Other);
	if (IsRelevant(Other))
	{
		Run(Other);
	}
}

void AAGP_InventoryModifier::Run(AActor* Other)
{
	if (Other == nullptr)
	{
		//DebugLog(DEBUG_Inv, "AGP_InventoryModifier::Run() Other == nullptr");
		return;
	}
	if (Other->IsA(AAGP_Pawn::StaticClass()))
	{
		agpPawn = Cast<AAGP_Pawn>(Other);
		//DebugLog(DEBUG_Inv, "AGP_InventoryModifier::Run() " + FString::FromInt(Self.Tag) + " running on " + FString::FromInt(agpPawn.Tag));
		if (bEmptyInventory)
		{
			//DebugLog(DEBUG_Inv, "AGP_InventoryModifier::Run() Emptying Inventory");
			agpPawn->EmptyInventory(false);
		}
		if (bAddInventory)
		{
			//DebugLog(DEBUG_Inv, "AGP_InventoryModifier::Run() Adding Inventory");
			AddInventory();
			if (bGiveNVG && (agpPawn->_OpticsDevice == nullptr))
			{
				//agpPawn->_OpticsDevice = Spawn(class<BaseOptics>(DynamicLoadObject("AGP_Inventory.NightOpticsDevice", Class'Class')), agpPawn);
				agpPawn->_OpticsDevice->DoAttachStuffWhichShouldBeDoneInInventory();
			}
		}
	}
	else
	{
		//DebugLog(DEBUG_Inv, "AGP_InventoryModifier::Run() " + FString::FromInt(Self.Tag) + " received " + FString::FromInt(Other) + " instead of an AGP_Pawn target.");
	}
}

void AAGP_InventoryModifier::AddInventory()
{
	int32 i = 0;
	for (i = 0; i < 16; i++)
	{
		agpPawn->CreateInventory(InventoryList[i],false,false);
	}
}
