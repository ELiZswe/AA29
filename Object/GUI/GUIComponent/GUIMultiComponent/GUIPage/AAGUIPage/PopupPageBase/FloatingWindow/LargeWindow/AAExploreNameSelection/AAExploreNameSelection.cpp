// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/AAExploreNameSelection/AAExploreNameSelection.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAExploreNameSelection::UAAExploreNameSelection()
{
	UGUIButton* PlayNowButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PlayNowButton->Caption = "Launch!";
	PlayNowButton->StyleName = "SquareMenuButton";
	PlayNowButton->Hint = "Display the list of official 'Explorer' servers (via the AA Browser).";
	PlayNowButton->WinTop = 0.67;
	PlayNowButton->WinLeft = 0.22;
	PlayNowButton->WinWidth = 0.16;
	PlayNowButton->WinHeight = 0.053476;
	PlayNowButton->RenderWeight = 0.6;
	//PlayNowButton->OnClick=AAExploreNameSelection.OnPlayClick;
	//PlayNowButton->OnKeyEvent=PlayNowButton.InternalOnKeyEvent;
	UGUIButton* PlayLANNowButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PlayLANNowButton->Caption = "LAN Games";
	PlayLANNowButton->StyleName = "SquareMenuButton";
	PlayLANNowButton->Hint = "Find LAN games (ETA by default)";
	PlayLANNowButton->WinTop = 0.67;
	PlayLANNowButton->WinLeft = 0.42;
	PlayLANNowButton->WinWidth = 0.16;
	PlayLANNowButton->WinHeight = 0.053476;
	PlayLANNowButton->RenderWeight = 0.6;
	//PlayLANNowButton->OnClick=AAExploreNameSelection.OnPlayLANClick;
	//PlayLANNowButton->OnKeyEvent=PlayLANNowButton.InternalOnKeyEvent;
	UGUIButton* CancelButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelButton->Caption = "Cancel";
	CancelButton->StyleName = "SquareMenuButton";
	CancelButton->WinTop = 0.67;
	CancelButton->WinLeft = 0.62;
	CancelButton->WinWidth = 0.16;
	CancelButton->WinHeight = 0.053476;
	CancelButton->RenderWeight = 0.6;
	//CancelButton->OnClick=AAExploreNameSelection.OnCancelClick;
	//CancelButton->OnKeyEvent=CancelButton.InternalOnKeyEvent;
	UmoComboBox* NickNameComboBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	NickNameComboBox->CaptionWidth = 0.34;
	NickNameComboBox->Caption = "Nick Name:";
	//NickNameComboBox->OnCreateComponent=NickNameComboBox.InternalOnCreateComponent;
	NickNameComboBox->IniOption = "@Internal";
	NickNameComboBox->Hint = "Select an ETA nickname from this list.";
	NickNameComboBox->WinTop = 0.45;
	NickNameComboBox->WinLeft = 0.25;
	NickNameComboBox->WinHeight = 0.05;
	NickNameComboBox->TabOrder = 1;
	NickNameComboBox->bStandardized = false;
	UmoComboBox* LastNameComboBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	LastNameComboBox->CaptionWidth = 0.34;
	LastNameComboBox->Caption = "Last Name:";
	//LastNameComboBox->OnCreateComponent=LastNameComboBox.InternalOnCreateComponent;
	LastNameComboBox->IniOption = "@Internal";
	LastNameComboBox->Hint = "Select an ETA surname from this list (a first name will be generated on the server)";
	LastNameComboBox->WinTop = 0.52;
	LastNameComboBox->WinLeft = 0.25;
	LastNameComboBox->WinHeight = 0.05;
	LastNameComboBox->TabOrder = 2;
	LastNameComboBox->bStandardized = false;
	UGUIImage* Bg = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Bg->WinTop = 0.103281;
	Bg->WinLeft = 0.262656;
	Bg->WinWidth = 0.343359;
	Bg->WinHeight = 0.766448;
	UGUILabel* Instructions = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Instructions->Caption = "While playing on Explorer servers you will be assigned a randomly chosen identity. If you have logged in with an active America's Army player account your username will not be seen on the server. To create a persistent ETA ID (saved to local system only) choose a nickname and last name from the pulldown menus below. If you do not choose a name one will be randomly selected for you.";
	Instructions->TextColor = FColor(114, 140, 121, 255);
	Instructions->bMultiLine = true;
	Instructions->StyleName = "TextLabel";
	Instructions->WinTop = 0.25;
	Instructions->WinLeft = 0.25;
	Instructions->WinWidth = 0.5;
	Instructions->WinHeight = 0.2;
	UGUILabel* lblNoXPMessage = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblNoXPMessage->Caption = "Explorer Servers do not accrue experience (XP/HONOR).|This game mode is intended as a way to experience Quick Missions/Instant Action before beginning specialized training.";
	lblNoXPMessage->TextAlign = ETextAlign::TXTA_Center;
	lblNoXPMessage->TextColor = FColor(114, 140, 121, 255);
	lblNoXPMessage->bMultiLine = true;
	lblNoXPMessage->StyleName = "NMLSmallText";
	lblNoXPMessage->WinTop = 0.59;
	lblNoXPMessage->WinLeft = 0.25;
	lblNoXPMessage->WinWidth = 0.5;
	lblNoXPMessage->WinHeight = 0.2;
	i_Background =Bg;
	btnPlayNow = PlayNowButton;
	btnPlayLANNow = PlayLANNowButton;
	btnCancel = CancelButton;
	guilInstructions = Instructions;
	guilNoXPMessage = lblNoXPMessage;
	mcbNickName = NickNameComboBox;
	mcbLastName = LastNameComboBox;
	WindowName = "Select Your Instant Action Identity";
	WinHeight = 0.55;
}

void UAAExploreNameSelection::InitComponent(UGUIController* MyC, UGUIComponent* MyO)
{
	/*
	int32 iName = 0;
	bool bSavedSurnameValid = false;
	bool bSavedNickNameValid = false;
	Super::InitComponent(MyC, MyO);
	for (iName = 0; iName < Class'LevelInfo'.Default.asETANickNames.Length; iName++)
	{
		if (HumanController(PlayerOwner()).sETAUserSelectedNickName == Class'LevelInfo'.Default.asETANickNames[iName])
		{
			bSavedNickNameValid = true;
		}
		mcbNickName.MyComboBox.List.Insert(iName, Class'LevelInfo'.Default.asETANickNames[iName]);
	}
	for (iName = 0; iName < Class'LevelInfo'.Default.asETASurNames.Length; iName++)
	{
		if (HumanController(PlayerOwner()).sETAUserSelectedSurName == Class'LevelInfo'.Default.asETASurNames[iName])
		{
			bSavedSurnameValid = true;
		}
		mcbLastName.MyComboBox.List.Insert(iName, Class'LevelInfo'.Default.asETASurNames[iName]);
	}
	if (bSavedNickNameValid && (Len(HumanController(PlayerOwner()).sETAUserSelectedNickName) > 0))
	{
		mcbNickName.SetText(HumanController(PlayerOwner()).sETAUserSelectedNickName);
	}
	else
	{
		mcbNickName.SetIndex(Rand(Class'LevelInfo'.Default.asETANickNames.Length));
	}
	if (bSavedSurnameValid && (Len(HumanController(PlayerOwner()).sETAUserSelectedSurName) > 0))
	{
		mcbLastName.SetText(HumanController(PlayerOwner()).sETAUserSelectedSurName);
	}
	else
	{
		mcbLastName.SetIndex(Rand(Class'LevelInfo'.Default.asETASurNames.Length));
	}
	if (bSavedSurnameValid && bSavedNickNameValid)
	{
		guilInstructions.Caption = "While playing on 'Explorer' servers you will be assigned a temporary ETA identity. " $ "To create an ETA ID (saved to local system only) choose a nickname and surname from the lists below. " $ "If you do not choose a name one will be randomly selected for you. " $ " " $ "NOTE: If you have logged in with an active America's Army player account your username will not be seen on the server. ";
	}
	mcbLastName.MyComboBox.Edit.bReadOnly = true;
	mcbNickName.MyComboBox.Edit.bReadOnly = true;
	*/
}

bool UAAExploreNameSelection::OnPlayClick(UGUIComponent* Sender)
{
	/*
	HumanController(PlayerOwner()).sETAUserSelectedNickName = mcbNickName.GetText();
	HumanController(PlayerOwner()).sETAUserSelectedSurName = mcbLastName.GetText();
	HumanController(PlayerOwner()).SaveConfig();
	Controller.CloseMenu(true);
	ExploreTheArmySubPanel.DisplayBrowser();
	*/
	return true;
}

bool UAAExploreNameSelection::OnPlayLANClick(UGUIComponent* Sender)
{
	/*
	HumanController(PlayerOwner()).sETAUserSelectedNickName = mcbNickName.GetText();
	HumanController(PlayerOwner()).sETAUserSelectedSurName = mcbLastName.GetText();
	HumanController(PlayerOwner()).SaveConfig();
	Controller.CloseMenu(true);
	ExploreTheArmySubPanel.DisplayLANBrowser();
	*/
	return true;
}

bool UAAExploreNameSelection::OnCancelClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}