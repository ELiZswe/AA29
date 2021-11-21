// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2ArenaConfig.generated.h"

class AWeapon;
class UmoComboBox;

UCLASS()
class AA29_API UUT2ArenaConfig : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2ArenaConfig();

	UPROPERTY()				AWeapon*			WeaponClass;			//var TArray<class<Weapon> > WeaponClass;
	UPROPERTY()				TArray<FString>		WeaponDesc;				//var TArray<FString> WeaponDesc;
	UPROPERTY()				UmoComboBox*		WeaponCombo;			//var moComboBox WeaponCombo;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
};
