// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/TestPanelBase/JoeTestPanelB/JoeTestPanelB.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"

UJoeTestPanelB::UJoeTestPanelB()
{
	UGUIEditBox* TestEditB = NewObject<UGUIEditBox>(UGUIEditBox::StaticClass());
	TestEditB->TextStr="DAMN HOT";
	TestEditB->WinTop=0.5;
	TestEditB->WinLeft=0.1;
	TestEditB->WinWidth=0.8;
	TestEditB->WinHeight=48;
	//TestEditB->OnActivate=TestEditB.InternalActivate;
	//TestEditB->OnDeActivate=TestEditB.InternalDeactivate;
	//TestEditB->OnKeyType=TestEditB.InternalOnKeyType;
	//TestEditB->OnKeyEvent=TestEditB.InternalOnKeyEvent;

	Controls = { TestEditB };
	WinTop = 0.6;
	WinHeight = 0.4;
}

void UJoeTestPanelB::InitPanel()
{
}
