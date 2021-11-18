// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_CP_PunkBuster.generated.h"

class UmoCheckBox;
class UGUILabel;
class UAAGameMenu_CommandPost;

UCLASS()
class AA29_API UAAGameMenu_CP_PunkBuster : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_CP_PunkBuster();

	UPROPERTY()								FString								sInstructions;					//var localized string sInstructions;
	UPROPERTY()								UAAGameMenu_CommandPost*			aagpCommandPost;				//var AAGameMenu_CommandPost aagpCommandPost;
	UPROPERTY(EditAnywhere)					UGUILabel*							gulInstructions;				//var() XInterface.GUILabel gulInstructions;
	UPROPERTY(EditAnywhere)					UmoCheckBox*						mchkbPBEnabled;					//var() XInterface.moCheckBox mchkbPBEnabled;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeDataFields();
	bool IsAdmin();
	bool CanShowPanel();
	void InternalOnChange(UGUIComponent* Sender);
	void NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3);
};
