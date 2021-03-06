// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "Javelin_BST_Tube.generated.h"

class AInvContainer;
UCLASS()
class AJavelin_BST_Tube : public AJavelin_Tube
{
	GENERATED_BODY()
public:
	AJavelin_BST_Tube();
	
	UPROPERTY()		bool bCanDrop;					//var bool bCanDrop;

	bool CanUseWeapon(int32 DesiredAction);
	AInvContainer* GetSwapContainer();
};
