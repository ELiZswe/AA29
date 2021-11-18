// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportSubPanel/AASupportSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"

UAASupportSubPanel::UAASupportSubPanel()
{
	UGUIScrollTextBox* MyPanel = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	MyPanel->bNoTeletype=true;
	MyPanel->bVisibleWhenEmpty=true;
	//MyPanel->OnCreateComponent=MyPanel.InternalOnCreateComponent;
	MyPanel->StyleName="MediumText";
	MyPanel->WinTop=0.065;
	MyPanel->WinLeft=0.02;
	MyPanel->WinWidth=0.98;
	MyPanel->WinHeight=0.85;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;
	
	stb_Panel = MyPanel;
}

void UAASupportSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	stb_Panel.SetContent(AAGUIController(Controller).LoadTextFromFile(GetBaseDir() $ SupportFile));
	*/
}
