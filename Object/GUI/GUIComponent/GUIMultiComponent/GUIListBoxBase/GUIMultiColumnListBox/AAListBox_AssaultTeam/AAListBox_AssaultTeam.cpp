// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/AAListBox_AssaultTeam/AAListBox_AssaultTeam.h"

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
	Header.bNeverFocus = True;
	bNeverFocus = True;
	Header.bAcceptsInput = False;
	InitComponent(MyController, MyOwner);
	MenuStateChange(4);
	*/
}

void UAAListBox_AssaultTeam::InternalOnDraw(UCanvas* C)
{
	/*
	MenuStateChange(0);
	Return OnDraw(C);
	*/
}