// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AAGameMenu_DemoControls.generated.h"

class UGUIButton;

UCLASS()
class AA29_API UAAGameMenu_DemoControls : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAAGameMenu_DemoControls();



	UPROPERTY(EditAnywhere)			UGUIButton* btnPlayPause;			//var() automated XInterface.GUIButton btnPlayPause;
	UPROPERTY(EditAnywhere)			UGUIButton* btnFastForward;			//var() automated XInterface.GUIButton btnFastForward;
	UPROPERTY(EditAnywhere)			UGUIButton* btnRewind;				//var() automated XInterface.GUIButton btnRewind;
	UPROPERTY()						bool bDemoPaused;					//var bool bDemoPaused;
	UPROPERTY()						float OriginalGameSpeed;			//var float OriginalGameSpeed;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClick(UGUIComponent* Sender);

};
