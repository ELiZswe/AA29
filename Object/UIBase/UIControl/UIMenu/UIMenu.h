// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIMenu.generated.h"

class UUIMenuItem;

UCLASS()
class UUIMenu : public UUIControl
{
	GENERATED_BODY()
public:
	UUIMenu();

	UPROPERTY()				FPoint _ToolTipLoc;					//var UIBase.Point _ToolTipLoc;
	UPROPERTY()				UUIMenuItem* cActiveItem;			//var UIMenuItem cActiveItem;
	UPROPERTY()				UUIMenuItem* cFocus;				//var UIMenuItem cFocus;
	UPROPERTY()				UUIMenuItem* cLastMenuItem;			//var UIMenuItem cLastMenuItem;
	UPROPERTY()				UUIMenuItem* cFirstMenuItem;		//var UIMenuItem cFirstMenuItem;
	UPROPERTY()				UUIMenu* cPrevMenu;					//var UIMenu cPrevMenu;
	UPROPERTY()				UUIMenu* cNextMenu;					//var UIMenu cNextMenu;

	void Destroyed();
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void MouseMove(int32 mX, int32 mY);
	void Draw(UCanvas* Canvas);
	UUIMenuItem* CreateUIMenuItem(FString ControlName);
	void AddMenuItem(FString sItem, int32 pID, int32 pUIEvent, FPosition pPos, FString tString, int32 pParams, FString sToolTip);
	void ScaleControl(UCanvas* Canvas);
	FPoint GetToolTipLocation();
	void SetToolTipLocation(FPoint pLoc);
};
