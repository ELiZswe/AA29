// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/TestPanelBase/JoeTestPanelA/JoeTestPanelA.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UJoeTestPanelA::UJoeTestPanelA()
{
	UGUIButton* TestButtonB = NewObject<UGUIButton>(UGUIButton::StaticClass());
	TestButtonB->Caption="Damn";
	TestButtonB->WinTop=0.55;
	TestButtonB->WinLeft=0.25;
	TestButtonB->WinWidth=0.5;
	TestButtonB->WinHeight=48;
	//TestButtonB->OnKeyEvent=TestButtonB.InternalOnKeyEvent;
	UGUIButton* TestButtonA = NewObject<UGUIButton>(UGUIButton::StaticClass());
	TestButtonA->Caption="Wow";
	TestButtonA->WinTop=0.25;
	TestButtonA->WinLeft=0.25;
	TestButtonA->WinWidth=0.5;
	TestButtonA->WinHeight=48;
	//TestButtonA->OnKeyEvent=TestButtonA.InternalOnKeyEvent;
	
	Controls = { TestButtonA,TestButtonB };
	WinTop = 0.65;
	WinHeight = 0.3;
}

void UJoeTestPanelA::InitPanel()
{
}
