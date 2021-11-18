// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIMenuItem.generated.h"

class UUIMenu;

UCLASS()
class AA29_API UUIMenuItem : public UUIControl
{
	GENERATED_BODY()
public:
	UUIMenuItem();


	UPROPERTY()										USoundBase* _sndClick;					//var Sound _sndClick;
	UPROPERTY()										USoundBase* _sndOver;					//var Sound _sndOver;
	UPROPERTY()										bool bFirstOver;						//var bool bFirstOver;
	UPROPERTY()										bool bButtonDown;						//var bool bButtonDown;
	UPROPERTY()										FString _sInfo;							//var string _sInfo;
	UPROPERTY()										int32 iState;							//var int iState;
	UPROPERTY()										FString sTexture;						//var string sTexture;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;
	UPROPERTY()										UUIMenu* cParentMenu;					//var UIMenu cParentMenu;
	UPROPERTY()										UUIMenuItem* cPrevItem;					//var UIMenuItem cPrevItem;
	UPROPERTY()										UUIMenuItem* cNextItem;					//var UIMenuItem cNextItem;


	void Destroyed();
	void CreateTexture();
	void SetSounds(USoundBase* sOver, USoundBase* sClick);
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetParentMenu(UUIMenu* Parent);
	void SetTextureString(FString tString);
	void SetTooltip(FString sToolTip);
	FString GetToolTip();
	void PlaySound(USoundBase* pSound);
};
