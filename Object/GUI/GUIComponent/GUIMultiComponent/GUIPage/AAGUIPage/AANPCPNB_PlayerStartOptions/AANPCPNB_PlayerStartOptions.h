// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AANPCPNB_PlayerStartOptions.generated.h"

class UGUIButton;
class UGUILabel;
class UmoEditBox;
class UmoComboBox;
class UmoCheckBox;

UCLASS()
class AA29_API UAANPCPNB_PlayerStartOptions : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAANPCPNB_PlayerStartOptions();

	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnSaveChanges;			//var() automated XInterface.GUIButton guibtnSaveChanges;
	UPROPERTY(EditAnywhere)		UGUIButton*		guibtnClose;				//var() automated XInterface.GUIButton guibtnClose;
	UPROPERTY(EditAnywhere)		UGUILabel*		guilTitle;					//var() automated XInterface.GUILabel guilTitle;
	UPROPERTY(EditAnywhere)		UmoEditBox*		mebDisplayName;				//var() automated XInterface.moEditBox mebDisplayName;
	UPROPERTY(EditAnywhere)		UmoEditBox*		mebWaypointTag;				//var() automated XInterface.moEditBox mebWaypointTag;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbFace;					//var() automated XInterface.moComboBox mcbFace;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbShirt;					//var() automated XInterface.moComboBox mcbShirt;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbPants;					//var() automated XInterface.moComboBox mcbPants;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbHands;					//var() automated XInterface.moComboBox mcbHands;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbHeadgear;				//var() automated XInterface.moComboBox mcbHeadgear;
	UPROPERTY(EditAnywhere)		UmoCheckBox*	mchkbSpawnAsReserve;		//var() automated XInterface.moCheckBox mchkbSpawnAsReserve;
	UPROPERTY(EditAnywhere)		UmoCheckBox*	mchkbSpawnRandomLocation;	//var() automated XInterface.moCheckBox mchkbSpawnRandomLocation;
	UPROPERTY(EditAnywhere)		UmoCheckBox*	mchkbAutoReversePath;		//var() automated XInterface.moCheckBox mchkbAutoReversePath;
	UPROPERTY(EditAnywhere)		UmoCheckBox*	mchkbPatrolAscending;		//var() automated XInterface.moCheckBox mchkbPatrolAscending;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbSpawnChance;				//var() automated XInterface.moComboBox mcbSpawnChance;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbInitialOrders;			//var() automated XInterface.moComboBox mcbInitialOrders;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbPrimaryWeapon;			//var() automated XInterface.moComboBox mcbPrimaryWeapon;
	UPROPERTY(EditAnywhere)		UmoCheckBox*	mchkbHasBinoculars;			//var() automated XInterface.moCheckBox mchkbHasBinoculars;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbSecondaryWeapon;			//var() automated XInterface.moComboBox mcbSecondaryWeapon;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbPrimaryWeaponReloads;	//var() automated XInterface.moComboBox mcbPrimaryWeaponReloads;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbSecondaryWeaponReloads;	//var() automated XInterface.moComboBox mcbSecondaryWeaponReloads;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbFragGrenades;			//var() automated XInterface.moComboBox mcbFragGrenades;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbSmokeGrenades;			//var() automated XInterface.moComboBox mcbSmokeGrenades;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbWeaponSkill;				//var() automated XInterface.moComboBox mcbWeaponSkill;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbVisionSkill;				//var() automated XInterface.moComboBox mcbVisionSkill;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbHearingRange;			//var() automated XInterface.moComboBox mcbHearingRange;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbExperience;				//var() automated XInterface.moComboBox mcbExperience;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbPlatoon;					//var() automated XInterface.moComboBox mcbPlatoon;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbSquad;					//var() automated XInterface.moComboBox mcbSquad;
	UPROPERTY(EditAnywhere)		UmoComboBox*	mcbFireteam;				//var() automated XInterface.moComboBox mcbFireteam;
	UPROPERTY()					bool			fCloseRequested;			//var bool fCloseRequested;
	UPROPERTY()					bool			bPlayerHUD;					//var bool bPlayerHUD;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	int32 WeaponClassToIndex(UObject* nameWeaponClass);
	FString WeaponClassToLabel(UObject* nameWeaponClass);
	void OnOpen();
	void OnClose(bool bCanceled);
	bool OnCanClose(bool bCancelled);
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
};
