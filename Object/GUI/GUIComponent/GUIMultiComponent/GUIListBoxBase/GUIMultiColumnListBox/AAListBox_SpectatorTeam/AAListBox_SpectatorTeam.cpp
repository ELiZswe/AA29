// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/AAListBox_SpectatorTeam/AAListBox_SpectatorTeam.h"

UAAListBox_SpectatorTeam::UAAListBox_SpectatorTeam()
{
	//DefaultListClass = "AGP_Interface.AAScoreboard_AutoScaleSpectatorTeam";
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
	//__OnDraw__Delegate = "AAListBox_SpectatorTeam.InternalOnDraw";
}

void UAAListBox_SpectatorTeam::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Header.bNeverFocus = True;
	Header.bAcceptsInput = False;
	bNeverFocus = True;
	InitComponent(MyController, MyOwner);
	MenuStateChange(4);
	*/
}

void UAAListBox_SpectatorTeam::InternalOnDraw(UCanvas* C)
{
	/*
	MenuStateChange(0);
	Return OnDraw(C);
	*/
}

