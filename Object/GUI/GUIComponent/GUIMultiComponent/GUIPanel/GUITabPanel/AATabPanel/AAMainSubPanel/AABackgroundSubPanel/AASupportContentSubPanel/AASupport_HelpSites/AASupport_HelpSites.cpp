// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupport_HelpSites/AASupport_HelpSites.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAASupport_HelpSites::UAASupport_HelpSites()
{
	SupportFile = "Help.ini";
	PanelCaption = "Help Links";
}

void UAASupport_HelpSites::LoadContent()
{
	FString Text = "";
	UAAGUILabel* Lbl = nullptr;
	//Text = "Version " + FString::FromInt(GetVersionAGPMajor()) + "." + FString::FromInt(GetVersionAGPMinor()) + "." + FString::FromInt(GetVersionAGPTiny()) + "." + FString::FromInt(GetVersionAGPSubTiny());
	Lbl = Cast<UAAGUILabel>(cob_Panel->addItem("AGP_Interface.AAGUILabel"));
	Lbl->Style = Controller->GetStyle("TextLabel", FontScale);
	Lbl->Caption = Text;
	Super::LoadContent();
}
