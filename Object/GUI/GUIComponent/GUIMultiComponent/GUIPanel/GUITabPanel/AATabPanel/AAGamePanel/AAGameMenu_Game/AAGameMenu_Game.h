// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_Game.generated.h"

class UGUIButton;
class UGUIImage;

UCLASS()
class AA29_API UAAGameMenu_Game : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_Game();

	UPROPERTY()								FString						DisconnectHint;					//var localized string DisconnectHint;
	UPROPERTY()								FString						DisconnectCaption;				//var localized string DisconnectCaption;
	UPROPERTY(EditAnywhere)					UGUIButton*					b_Exit;							//var() XInterface.GUIButton b_Exit;
	UPROPERTY(EditAnywhere)					UGUIButton*					b_Leave;						//var() XInterface.GUIButton b_Leave;
	UPROPERTY(EditAnywhere)					UGUIButton*					b_Settings;						//var() XInterface.GUIButton b_Settings;
	UPROPERTY(EditAnywhere)					UGUIImage*					i_Background;					//var() XInterface.GUIImage i_Background;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClick(UGUIComponent* Sender);
};
