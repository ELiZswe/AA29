// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/AAListBox_AssaultTeam/AAListBox_AssaultTeam.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "Engine/Canvas.h"

UAAListBox_AssaultTeam::UAAListBox_AssaultTeam()
{
	//DefaultListClass = "AGP_Interface.AAScoreboard_AssaultTeam";
	bVisibleWhenEmpty = true;
	bDrawFocusedLast = false;
	StyleName = "ScoreboardUnitText";
	WinTop = 0.06;
	WinLeft = 0.02;
	WinWidth = 0.95;
	WinHeight = 0.8;
	RenderWeight = 0.001;
	bBoundToParent = true;
	bScaleToParent = true;
	bAcceptsInput = false;
	bNeverFocus = true;
	//__OnDraw__Delegate = "AAListBox_AssaultTeam.InternalOnDraw";
}

void UAAListBox_AssaultTeam::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Header.bNeverFocus = true;
	bNeverFocus = true;
	Header.bAcceptsInput = false;
	InitComponent(MyController, MyOwner);
	MenuStateChange(4);
	*/
}

bool UAAListBox_AssaultTeam::InternalOnDraw(UCanvas* C)
{
	MenuStateChange(EMenuState::MSAT_Blurry);
	return OnDraw(C);
}
