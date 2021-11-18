// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/PopupPageBase.h"
#include "AADemoPlayback.generated.h"

class UStateButton;
class UGUILabel;
class UGUIList;

UCLASS()
class AA29_API UAADemoPlayback : public UPopupPageBase
{
	GENERATED_BODY()
public:
	UAADemoPlayback();

	UPROPERTY(EditAnywhere)			UStateButton*		b_FF;					//var() automated XInterface.StateButton b_FF;
	UPROPERTY(EditAnywhere)			UStateButton*		b_PlayPause;			//var() automated XInterface.StateButton b_PlayPause;
	UPROPERTY(EditAnywhere)			UStateButton*		b_Stop;					//var() automated XInterface.StateButton b_Stop;
	UPROPERTY(EditAnywhere)			UGUILabel*			lb_MapName;				//var() automated XInterface.GUILabel lb_MapName;
	UPROPERTY(EditAnywhere)			UGUILabel*			lb_Mod;					//var() automated XInterface.GUILabel lb_Mod;
	UPROPERTY(EditAnywhere)			UGUIList*			_ViewTargets;			//var XInterface.GUIList l_ViewTargets;
	UPROPERTY()						bool				bIsClosing;				//var bool bIsClosing;
	UPROPERTY()						bool				bIsPaused;				//var bool bIsPaused;
	UPROPERTY()						float				OriginalGameSpeed;		//var float OriginalGameSpeed;
	UPROPERTY()						int32				GameSpeedModifier;		//var int32 GameSpeedModifier;
	UPROPERTY()						TArray<float>		GameSpeedMods;			//var float GameSpeedMods[4];
	UPROPERTY()						float				modfade;				//var float modfade;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Free();
	void Arrival(UGUIComponent* Sender, EAnimationType Type);
	bool StopClick(UGUIComponent* Sender);
	bool PlayPauseClick(UGUIComponent* Sender);
	bool FastForwardClick(UGUIComponent* Sender);
	bool ModDraw(UCanvas* C);
};
