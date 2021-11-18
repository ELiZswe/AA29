// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AAMissionsOverviewSubPanel/AAMissionsOverviewSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAMissionsOverviewSubPanel::UAAMissionsOverviewSubPanel()
{
	
	UmoComboBox* MyTourCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MyTourCombo->bReadOnly=true;
	//MyTourCombo->CaptionWidth=0.2;
	//MyTourCombo->Caption="Tours";
	//MyTourCombo->LabelFont="AAFontLabel";
	//MyTourCombo->OnCreateComponent=MyTourCombo.InternalOnCreateComponent;
	MyTourCombo->IniOption="@Internal";
	MyTourCombo->Hint="Select the tour you would like to see missions for.";
	MyTourCombo->WinTop=0.07;
	MyTourCombo->WinLeft=0.01;
	MyTourCombo->WinWidth=0.48;
	MyTourCombo->WinHeight=0.053476;
	MyTourCombo->bStandardized=false;
	//MyTourCombo->OnChange=AAMissionsOverviewSubPanel.InternalOnChange;
	//MyTourCombo->OnLoadINI=AAMissionsOverviewSubPanel.InternalOnLoadINI;
	UGUIButton* MyDetailsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyDetailsButton->Caption="DETAILS";
	MyDetailsButton->StyleName="SquareMenuButton";
	MyDetailsButton->Hint="Click here to begin mission.";
	MyDetailsButton->WinTop=0.07;
	MyDetailsButton->WinLeft=0.51;
	MyDetailsButton->WinWidth=0.15;
	MyDetailsButton->WinHeight=0.053476;
	MyDetailsButton->RenderWeight=0.6;
	//MyDetailsButton->OnClick=AAMissionsOverviewSubPanel.ButtonClick;
	//MyDetailsButton->OnKeyEvent=MyDetailsButton.InternalOnKeyEvent;
	UGUIImage* tourIcon = NewObject<UGUIImage>(UGUIImage::StaticClass());
	tourIcon->ImageStyle = EImgStyle::ISTY_Justified;
	tourIcon->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	tourIcon->WinTop=0.14;
	tourIcon->WinLeft=0.05;
	tourIcon->WinWidth=0.21;
	tourIcon->WinHeight=0.28;
	tourIcon->RenderWeight=0.9;
	UGUILabel* MyTourLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyTourLabel->TextColor=FColor(255, 255, 255, 255);
	MyTourLabel->StyleName="Header";
	MyTourLabel->WinTop=0.2;
	MyTourLabel->WinLeft=0.27;
	MyTourLabel->WinWidth=0.5;
	MyTourLabel->WinHeight=0.04;
	UGUILabel* MyRequirementsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyRequirementsLabel->TextColor=FColor(255, 255, 255, 255);
	MyRequirementsLabel->TextFont="AAFontLabel";
	MyRequirementsLabel->WinTop=0.28;
	MyRequirementsLabel->WinLeft=0.27;
	MyRequirementsLabel->WinWidth=0.5;
	MyRequirementsLabel->WinHeight=0.04;
	UGUILabel* MyStatusLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyStatusLabel->TextColor=FColor(255, 255, 255, 255);
	MyStatusLabel->TextFont="AAFontLabel";
	MyStatusLabel->WinTop=0.32;
	MyStatusLabel->WinLeft=0.27;
	MyStatusLabel->WinWidth=0.5;
	MyStatusLabel->WinHeight=0.04;
	
	co_Tour = MyTourCombo;
	i_Tour = tourIcon;
	l_Tour = MyTourLabel;
	l_Requirements = MyRequirementsLabel;
	l_Status = MyStatusLabel;
	b_Details = MyDetailsButton;
	NotAvailableText = "Not Available";
	AvailableText = "Available";
	CompletedText = "Completed";
	NotAvailableColor = FColor(0, 0, 192, 255);
	AvailableColor = FColor(64, 255, 0, 255);
	CompletedColor = FColor(255, 255, 255, 255);
	ToursFile = "Tours.ini";

}

void UAAMissionsOverviewSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
}

void UAAMissionsOverviewSubPanel::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	switch (Sender)
	{
	case co_Tour:
		LoadToursAndMissions();
		break;
	default:
	}
	*/
}

void UAAMissionsOverviewSubPanel::LoadToursAndMissions()
{
	/*
	local int32 NumTours;
	local int32 i;
	local FString File;
	local AAGUIController C;
	C = AAGUIController(Controller);
	File = GetBaseDir() $ ToursFile;
	co_Tour.ResetComponent();
	NumTours = GetPrivateProfileInt(File, "Tours", "NumTours");
	for (i = 0; i < NumTours; i++)
	{
		if (UseTraining(i) && ((i != C.4) || (!C.bFilterNoSniper)))
		{
			co_Tour.addItem(PlayerOwner().Level.GetTourName(i), , string(i));
		}
	}
	TourID = int(co_Tour.GetExtra());
	ReloadMissions();
	UpdateTourInfo();
	UpdateTourStatus();
	*/
}

void UAAMissionsOverviewSubPanel::ReloadMissions()
{
}

void UAAMissionsOverviewSubPanel::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if (Sender == co_Tour)
	{
		TourID = int(co_Tour.GetExtra());
		ReloadMissions();
	}
	UpdateTourInfo();
	UpdateTourStatus();
	*/
}

bool UAAMissionsOverviewSubPanel::UseTraining(int32 Tour)
{
	return true;
}

bool UAAMissionsOverviewSubPanel::ShouldDisableSniper()
{
	/*
	if (AAGUIController(Controller) != None)
	{
		return ((TourID == AAGUIController(Controller).4) && AAGUIController(Controller).bFilterNoSniper);
	}
	*/
	return false;
}

bool UAAMissionsOverviewSubPanel::ShouldDisableLifeFire()
{
	/*
	if (AAGUIController(Controller) != None)
	{
		return AAGUIController(Controller).bFilterMilesOnly;
	}
	*/
	return false;
}

void UAAMissionsOverviewSubPanel::SetStatusCaption(int32 Status)
{
	/*
	if (ShouldDisableSniper() || ((AAGUIController(Controller) != None) && (!AAGUIController(Controller).LoggedIn())))
	{
		l_Status.TextColor = NotAvailableColor;
		l_Status.Caption = NotAvailableText;
	}
	*/
}

void UAAMissionsOverviewSubPanel::UpdateTourStatus()
{
	//SetStatusCaption(PlayerOwner().Level.GetTourStatus(TourID));
}

bool UAAMissionsOverviewSubPanel::ButtonClick(UGUIComponent* Sender)
{
	/*
	if (AAMainMenu(PageOwner) != None)
	{
		if (AAMainPanel(AAMainMenu(PageOwner).c_Tab.BorrowPanel(DetailsPanelName)) != None)
		{
			AAMainPanel(AAMainMenu(PageOwner).c_Tab.BorrowPanel(DetailsPanelName)).c_Tabs.ActivateTabByName("Details", true);
		}
	}
	*/
	return true;
}

void UAAMissionsOverviewSubPanel::UpdateTourInfo()
{
	/*
	local AAGUIController C;
	local FString S;
	local int32 i;
	C = AAGUIController(Controller);
	i_Tour.Image = Material(DynamicLoadObject(PlayerOwner().Level.GetTourImage(TourID), Class'Material', true));
	l_Tour.Caption = PlayerOwner().Level.GetTourName(TourID);
	i = PlayerOwner().Level.GetTourDependency(TourID);
	S = PlayerOwner().Level.GetTourName(i);
	if (S == "")
	{
		l_Requirements.Caption = "Requirements: None";
	}
	else
	{
		l_Requirements.Caption = "Requirements: " $ S;
	}
	*/
}
