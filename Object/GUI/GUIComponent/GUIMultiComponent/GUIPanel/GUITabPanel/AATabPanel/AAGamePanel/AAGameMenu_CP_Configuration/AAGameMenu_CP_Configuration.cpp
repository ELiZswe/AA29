// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_Configuration/AAGameMenu_CP_Configuration.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGameMenu_CP_Configuration::UAAGameMenu_CP_Configuration()
{
	UGUIButton* SaveChanges = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SaveChanges->Caption = "Apply Changes";
	SaveChanges->MenuState = EMenuState::MSAT_Disabled;
	SaveChanges->StyleName = "SquareMenuButton";
	SaveChanges->Hint = "Click here to save changes you have made.";
	SaveChanges->WinTop = 0.065344;
	SaveChanges->WinLeft = 0.83625;
	SaveChanges->WinWidth = 0.15;
	SaveChanges->WinHeight = 0.05;
	SaveChanges->TabOrder = 14;
	//SaveChanges->OnClick=AAGameMenu_CP_Configuration.ButtonClick;
	//SaveChanges->OnKeyEvent=SaveChanges.InternalOnKeyEvent;
	UmoNumericEdit* MOTDDisplayTimeEditField = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MOTDDisplayTimeEditField->CaptionWidth = 0.65;
	MOTDDisplayTimeEditField->Caption = "Display Message of the Day for ";
	//MOTDDisplayTimeEditField->OnCreateComponent=MOTDDisplayTimeEditField.InternalOnCreateComponent;
	MOTDDisplayTimeEditField->IniOption = "@Internal";
	MOTDDisplayTimeEditField->Hint = "Use this to select how long, in seconds, players joining your server should see the message of the day displayed.";
	MOTDDisplayTimeEditField->WinTop = 0.8;
	MOTDDisplayTimeEditField->WinLeft = 0.05;
	MOTDDisplayTimeEditField->WinWidth = 0.55;
	MOTDDisplayTimeEditField->WinHeight = 0.05;
	MOTDDisplayTimeEditField->TabOrder = 13;
	MOTDDisplayTimeEditField->bStandardized = false;
	//MOTDDisplayTimeEditField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoEditBox* MOTD4EntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MOTD4EntryField->CaptionWidth = 0.1;
	MOTD4EntryField->Caption = "Line 4";
	//MOTD4EntryField->OnCreateComponent=MOTD4EntryField.InternalOnCreateComponent;
	MOTD4EntryField->IniOption = "@Internal";
	MOTD4EntryField->Hint = "Use this to display announcements to users joining your server.";
	MOTD4EntryField->WinTop = 0.74;
	MOTD4EntryField->WinLeft = 0.05;
	MOTD4EntryField->WinWidth = 0.9;
	MOTD4EntryField->WinHeight = 0.05;
	MOTD4EntryField->TabOrder = 12;
	MOTD4EntryField->bStandardized = false;
	//MOTD4EntryField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoEditBox* MOTD3EntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MOTD3EntryField->CaptionWidth = 0.1;
	MOTD3EntryField->Caption = "Line 3";
	//MOTD3EntryField->OnCreateComponent=MOTD3EntryField.InternalOnCreateComponent;
	MOTD3EntryField->IniOption = "@Internal";
	MOTD3EntryField->Hint = "Use this to display announcements to users joining your server.";
	MOTD3EntryField->WinTop = 0.68;
	MOTD3EntryField->WinLeft = 0.05;
	MOTD3EntryField->WinWidth = 0.9;
	MOTD3EntryField->WinHeight = 0.05;
	MOTD3EntryField->TabOrder = 11;
	MOTD3EntryField->bStandardized = false;
	//MOTD3EntryField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoEditBox* MOTD2EntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MOTD2EntryField->CaptionWidth = 0.1;
	MOTD2EntryField->Caption = "Line 2";
	//MOTD2EntryField->OnCreateComponent=MOTD2EntryField.InternalOnCreateComponent;
	MOTD2EntryField->IniOption = "@Internal";
	MOTD2EntryField->Hint = "Use this to display announcements to users joining your server.";
	MOTD2EntryField->WinTop = 0.62;
	MOTD2EntryField->WinLeft = 0.05;
	MOTD2EntryField->WinWidth = 0.9;
	MOTD2EntryField->WinHeight = 0.05;
	MOTD2EntryField->TabOrder = 10;
	MOTD2EntryField->bStandardized = false;
	//MOTD2EntryField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoEditBox* MOTD1EntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MOTD1EntryField->CaptionWidth = 0.1;
	MOTD1EntryField->Caption = "Line 1";
	//MOTD1EntryField->OnCreateComponent=MOTD1EntryField.InternalOnCreateComponent;
	MOTD1EntryField->IniOption = "@Internal";
	MOTD1EntryField->Hint = "Use this to display announcements to users joining your server.";
	MOTD1EntryField->WinTop = 0.57;
	MOTD1EntryField->WinLeft = 0.05;
	MOTD1EntryField->WinWidth = 0.9;
	MOTD1EntryField->WinHeight = 0.05;
	MOTD1EntryField->TabOrder = 9;
	MOTD1EntryField->bStandardized = false;
	//MOTD1EntryField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoComboBox* FireModeComboListBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	FireModeComboListBox->bReadOnly = true;
	FireModeComboListBox->CaptionWidth = 0.25;
	FireModeComboListBox->Caption = "Game Play Mode:";
	//FireModeComboListBox->OnCreateComponent=FireModeComboListBox.InternalOnCreateComponent;
	FireModeComboListBox->IniOption = "@Internal";
	FireModeComboListBox->StyleName = "STY_AAComboListBox";
	FireModeComboListBox->Hint = "Select the type of game-play you would like to use.  Note: Modifying this setting requires reloading the map or switching to a new map to have it take effect.";
	FireModeComboListBox->WinTop = 0.46;
	FireModeComboListBox->WinLeft = 0.05;
	FireModeComboListBox->WinWidth = 0.66;
	FireModeComboListBox->WinHeight = 0.05;
	FireModeComboListBox->TabOrder = 8;
	FireModeComboListBox->bStandardized = false;
	//FireModeComboListBox->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoComboBox* AutoBalanceComboListBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	AutoBalanceComboListBox->bReadOnly = true;
	AutoBalanceComboListBox->CaptionWidth = 0.3;
	AutoBalanceComboListBox->Caption = "Auto-Balance Option:";
	//AutoBalanceComboListBox->OnCreateComponent=AutoBalanceComboListBox.InternalOnCreateComponent;
	AutoBalanceComboListBox->IniOption = "@Internal";
	AutoBalanceComboListBox->StyleName = "STY_AAComboListBox";
	AutoBalanceComboListBox->Hint = "Select the auto-balancing option you would like to use to balance out teams.";
	AutoBalanceComboListBox->WinTop = 0.4;
	AutoBalanceComboListBox->WinLeft = 0.05;
	AutoBalanceComboListBox->WinWidth = 0.65;
	AutoBalanceComboListBox->WinHeight = 0.05;
	AutoBalanceComboListBox->TabOrder = 7;
	AutoBalanceComboListBox->bStandardized = false;
	//AutoBalanceComboListBox->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoNumericEdit* MaxAdminsEditField = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MaxAdminsEditField->CaptionWidth = 0.7;
	MaxAdminsEditField->Caption = "Maximum Admins:";
	//MaxAdminsEditField->OnCreateComponent=MaxAdminsEditField.InternalOnCreateComponent;
	MaxAdminsEditField->IniOption = "@Internal";
	MaxAdminsEditField->Hint = "Enter the maximum number of administrators that can connect at the same time on this server.";
	MaxAdminsEditField->WinTop = 0.33;
	MaxAdminsEditField->WinLeft = 0.5;
	MaxAdminsEditField->WinWidth = 0.3;
	MaxAdminsEditField->WinHeight = 0.04;
	MaxAdminsEditField->TabOrder = 6;
	MaxAdminsEditField->bStandardized = false;
	//MaxAdminsEditField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoNumericEdit* MaxPlayersEditField = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MaxPlayersEditField->CaptionWidth = 0.7;
	MaxPlayersEditField->Caption = "Maximum Players:";
	//MaxPlayersEditField->OnCreateComponent=MaxPlayersEditField.InternalOnCreateComponent;
	MaxPlayersEditField->IniOption = "@Internal";
	MaxPlayersEditField->Hint = "Enter the maximum number of players allowed on the server.";
	MaxPlayersEditField->WinTop = 0.33;
	MaxPlayersEditField->WinLeft = 0.05;
	MaxPlayersEditField->WinWidth = 0.3;
	MaxPlayersEditField->WinHeight = 0.04;
	MaxPlayersEditField->TabOrder = 5;
	MaxPlayersEditField->bStandardized = false;
	//MaxPlayersEditField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoComboBox* DelayedStartTimeComboListBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DelayedStartTimeComboListBox->bReadOnly = true;
	DelayedStartTimeComboListBox->Caption = "Delayed Start Options:";
	//DelayedStartTimeComboListBox->OnCreateComponent=DelayedStartTimeComboListBox.InternalOnCreateComponent;
	DelayedStartTimeComboListBox->IniOption = "@Internal";
	DelayedStartTimeComboListBox->StyleName = "STY_AAComboListBox";
	DelayedStartTimeComboListBox->Hint = "Select whether or not to enable delayed starting which can help create an even playing field.";
	DelayedStartTimeComboListBox->WinTop = 0.27;
	DelayedStartTimeComboListBox->WinLeft = 0.5;
	DelayedStartTimeComboListBox->WinWidth = 0.45;
	DelayedStartTimeComboListBox->WinHeight = 0.05;
	DelayedStartTimeComboListBox->TabOrder = 5;
	DelayedStartTimeComboListBox->bStandardized = false;
	//DelayedStartTimeComboListBox->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoNumericEdit* MaxHonorEditField = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MaxHonorEditField->CaptionWidth = 0.38;
	MaxHonorEditField->Caption = "Maximum Player Honor Level:";
	//MaxHonorEditField->OnCreateComponent=MaxHonorEditField.InternalOnCreateComponent;
	MaxHonorEditField->IniOption = "@Internal";
	MaxHonorEditField->Hint = "Enter the maximum honor level for players that you want to allow to play on this server.";
	MaxHonorEditField->WinTop = 0.27;
	MaxHonorEditField->WinLeft = 0.05;
	MaxHonorEditField->WinWidth = 0.45;
	MaxHonorEditField->WinHeight = 0.04;
	MaxHonorEditField->TabOrder = 4;
	MaxHonorEditField->bStandardized = false;
	//MaxHonorEditField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoNumericEdit* MinHonorEditField = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MinHonorEditField->CaptionWidth = 0.45;
	MinHonorEditField->Caption = "Minimum Player Honor Level:";
	//MinHonorEditField->OnCreateComponent=MinHonorEditField.InternalOnCreateComponent;
	MinHonorEditField->IniOption = "@Internal";
	MinHonorEditField->Hint = "Enter the minimum honor level for players that you want to allow to play on this server.";
	MinHonorEditField->WinTop = 0.21;
	MinHonorEditField->WinLeft = 0.05;
	MinHonorEditField->WinWidth = 0.4;
	MinHonorEditField->WinHeight = 0.04;
	MinHonorEditField->TabOrder = 3;
	MinHonorEditField->bStandardized = false;
	//MinHonorEditField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoEditBox* GamePasswordEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	GamePasswordEntryField->CaptionWidth = 0.3;
	GamePasswordEntryField->Caption = "Game Password: ";
	//GamePasswordEntryField->OnCreateComponent=GamePasswordEntryField.InternalOnCreateComponent;
	GamePasswordEntryField->IniOption = "@Internal";
	GamePasswordEntryField->Hint = "Enter the server's password here to make your server private.";
	GamePasswordEntryField->WinTop = 0.15;
	GamePasswordEntryField->WinLeft = 0.38125;
	GamePasswordEntryField->WinWidth = 0.4;
	GamePasswordEntryField->WinHeight = 0.05;
	GamePasswordEntryField->TabOrder = 2;
	GamePasswordEntryField->bStandardized = false;
	//GamePasswordEntryField->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UmoCheckBox* PrivateServerCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	PrivateServerCheckbox->CaptionWidth = 0.9;
	PrivateServerCheckbox->Caption = "Make Server Private";
	//PrivateServerCheckbox->OnCreateComponent=PrivateServerCheckbox.InternalOnCreateComponent;
	PrivateServerCheckbox->IniOption = "@Internal";
	PrivateServerCheckbox->Hint = "Check this box be able to set a game password to make your server private.";
	PrivateServerCheckbox->WinTop = 0.15;
	PrivateServerCheckbox->WinLeft = 0.05;
	PrivateServerCheckbox->WinWidth = 0.28;
	PrivateServerCheckbox->WinHeight = 0.05;
	PrivateServerCheckbox->TabOrder = 1;
	PrivateServerCheckbox->bStandardized = false;
	//PrivateServerCheckbox->OnChange=AAGameMenu_CP_Configuration.InternalOnChange;
	UGUILabel* InstructionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InstructionsLabel->TextColor = FColor(255, 255, 255, 255);
	InstructionsLabel->StyleName = "TextLabel";
	InstructionsLabel->WinTop = 0.07;
	InstructionsLabel->WinLeft = 0.05;
	InstructionsLabel->WinWidth = 0.9;
	InstructionsLabel->WinHeight = 0.05;
	UGUILabel* MOTDOptionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MOTDOptionsLabel->Caption = "Message of the Day Text and Options";
	MOTDOptionsLabel->TextAlign = ETextAlign::TXTA_Center;
	MOTDOptionsLabel->TextColor = FColor(255, 255, 255, 255);
	MOTDOptionsLabel->StyleName = "TextLabel";
	MOTDOptionsLabel->WinTop = 0.61;
	MOTDOptionsLabel->WinLeft = 0.05;
	MOTDOptionsLabel->WinWidth = 0.9;
	MOTDOptionsLabel->WinHeight = 0.05;
	mchkbPrivateServer = PrivateServerCheckbox;
	mebGamePassword = GamePasswordEntryField;
	mcbDelayedStartTime = DelayedStartTimeComboListBox;
	mcbAutoBalanceOptions = AutoBalanceComboListBox;
	mcbFireMode = FireModeComboListBox;
	gulInstructions = InstructionsLabel;
	guibSaveChanges = SaveChanges;
	mneMinHonor = MinHonorEditField;
	mneMaxHonor = MaxHonorEditField;
	gulMOTDTitle = MOTDOptionsLabel;
	mebMOTD1 = MOTD1EntryField;
	mebMOTD2 = MOTD2EntryField;
	mebMOTD3 = MOTD3EntryField;
	mebMOTD4 = MOTD4EntryField;
	mneMOTDDisplayTime = MOTDDisplayTimeEditField;
	mneMaxPlayers = MaxPlayersEditField;
	mneMaxAdmins = MaxAdminsEditField;

	sInstructions = "Use this to customize your server settings.";
	sMOTDTitle = "Message of the Day Text and Options";
	WinHeight = 1;
}

void UAAGameMenu_CP_Configuration::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	mneMinHonor.MyNumericEdit.MinValue = 1;
	mneMinHonor.MyNumericEdit.MaxValue = 100;
	mneMaxHonor.MyNumericEdit.MinValue = 1;
	mneMaxHonor.MyNumericEdit.MaxValue = 100;
	mneMaxPlayers.MyNumericEdit.MinValue = 1;
	mneMaxPlayers.MyNumericEdit.MaxValue = 26;
	mneMaxAdmins.MyNumericEdit.MinValue = 1;
	mneMaxAdmins.MyNumericEdit.MaxValue = 8;
	mcbAutoBalanceOptions.MyComboBox.Edit.bReadOnly = True;
	mcbFireMode.MyComboBox.Edit.bReadOnly = True;
	mcbDelayedStartTime.MyComboBox.Edit.bReadOnly = True;
	mcbDelayedStartTime.MyComboBox.Edit.bReadOnly = True;
	mcbDelayedStartTime.MyComboBox.List.Insert(0, "Disabled (Pre 2.8.3 Start)", , "0");
	mcbDelayedStartTime.MyComboBox.List.Insert(1, "5 Seconds", , "5");
	mcbDelayedStartTime.MyComboBox.List.Insert(2, "6 Seconds", , "6");
	mcbDelayedStartTime.MyComboBox.List.Insert(3, "7 Seconds", , "7");
	mcbDelayedStartTime.MyComboBox.List.Insert(4, "8 Seconds", , "8");
	mcbDelayedStartTime.MyComboBox.List.Insert(5, "9 Seconds", , "9");
	mcbDelayedStartTime.MyComboBox.List.Insert(6, "10 Seconds", , "10");
	mcbDelayedStartTime.MyComboBox.List.Insert(7, "11 Seconds", , "11");
	mcbDelayedStartTime.MyComboBox.List.Insert(8, "12 Seconds", , "12");
	mcbDelayedStartTime.MyComboBox.List.Insert(9, "13 Seconds", , "13");
	mcbDelayedStartTime.MyComboBox.List.Insert(10, "14 Seconds", , "14");
	mcbDelayedStartTime.MyComboBox.List.Insert(11, "15 Seconds", , "15");
	mcbAutoBalanceOptions.MyComboBox.List.Insert(0, "Auto-balance Teams");
	mcbAutoBalanceOptions.MyComboBox.List.Insert(1, "Never Auto-balance Teams");
	mcbFireMode.MyComboBox.List.Insert(0, "Force MILES Weapons", , "FORCE_MILES");
	mcbFireMode.MyComboBox.List.Insert(1, "Force Live-Fire Weapons", , "FORCE_Normal");
	mcbFireMode.MyComboBox.List.Insert(2, "Use Standard Weapons For Mission", , "FORCE_None");
	gulInstructions.Caption = sInstructions;
	*/
}

void UAAGameMenu_CP_Configuration::InitializeDataFields()
{
	/*
	if (aagpCommandPost == nullptr)
	{
		Log("Warning: The CP Configuration page does not have a valid Command Post page.");
		Return;
	}
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameInfo ForceGameplay");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameInfo MaxPlayers");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameInfo AbsoluteMaxPlayers");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameInfo MaxAdmins");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AccessControl GamePassword");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameTeam bPlayersBalanceTeams");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameTeam bAutoBalanceBetweenRounds");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameTeam bNeverAutoBalance");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameMultiPlayer MinHonor");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameMultiPlayer MaxHonor");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDLine1");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDLine2");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDLine3");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDLine4");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDDisplaySeconds");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameInfo iDelayedRoundStartTimeSeconds");
	*/
}

void UAAGameMenu_CP_Configuration::NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3)
{
	/*
	if (sParam1 ~= "INIEntry")
	{
		if (sParam2 ~= "AccessControl GamePassword")
		{
			if (Len(sParam3) > 0)
			{
				mchkbPrivateServer.SetComponentValue(True);
				mebGamePassword.SetText(sParam3);
				mebGamePassword.EnableMe();
			}
			else
			{
				mchkbPrivateServer.SetComponentValue(False);
				mebGamePassword.DisableMe();
			}
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bPlayersBalanceTeams")
		{
			bPlayersBalanceTeams = sParam3;
			UpdateAutoBalanceOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bAutoBalanceBetweenRounds")
		{
			bAutoBalanceBetweenRounds = sParam3;
			UpdateAutoBalanceOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameInfo iDelayedRoundStartTimeSeconds")
		{
			UpdateDelayedStartSelection(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bNeverAutoBalance")
		{
			bNeverAutoBalance = sParam3;
			UpdateAutoBalanceOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameMultiPlayer MinHonor")
		{
			mneMinHonor.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameMultiPlayer MaxHonor")
		{
			mneMaxHonor.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo MaxAdmins")
		{
			mneMaxAdmins.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo MaxPlayers")
		{
			mneMaxPlayers.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo AbsoluteMaxPlayers")
		{
			mneMaxPlayers.SetComponentValue(Min(sParam3, mneMaxPlayers.GetComponentValue()));
			mneMaxPlayers.MyNumericEdit.MaxValue = sParam3;
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDLine1")
		{
			mebMOTD1.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDLine2")
		{
			mebMOTD2.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDLine3")
		{
			mebMOTD3.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDLine4")
		{
			mebMOTD4.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDDisplaySeconds")
		{
			mneMOTDDisplayTime.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameInfo ForceGameplay")
		{
			if (sParam3 ~= "FORCE_MILES")
			{
				mcbFireMode.MyComboBox.List.SetIndex(0);
				guibSaveChanges.DisableMe();
				Return;
			}
			else
			{
				if (sParam3 ~= "FORCE_Normal")
				{
					mcbFireMode.MyComboBox.List.SetIndex(1);
					guibSaveChanges.DisableMe();
					Return;
				}
				else
				{
					mcbFireMode.MyComboBox.List.SetIndex(2);
					guibSaveChanges.DisableMe();
					Return;
				}
			}
		}
	}
	*/
}

void UAAGameMenu_CP_Configuration::UpdateDelayedStartSelection(int32 iDelayedStartTime)
{
	/*
	if (iDelayedStartTime == 0)
	{
		mcbDelayedStartTime.MyComboBox.List.SetIndex(0);
	}
	else
	{
		if (iDelayedStartTime < 5)
		{
			iDelayedStartTime = 5;
		}
		mcbDelayedStartTime.MyComboBox.List.SetIndex(iDelayedStartTime - 4);
	}
	*/
}

void UAAGameMenu_CP_Configuration::UpdateAutoBalanceOptions()
{
	/*
	if (bNeverAutoBalance)
	{
		mcbAutoBalanceOptions.MyComboBox.List.SetIndex(1);
		Return;
	}
	if (bPlayersBalanceTeams || bAutoBalanceBetweenRounds)
	{
		mcbAutoBalanceOptions.MyComboBox.List.SetIndex(0);
		Return;
	}
	mcbAutoBalanceOptions.MyComboBox.List.SetIndex(2);
	Return;
	*/
}

bool UAAGameMenu_CP_Configuration::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;    //FAKE    /ELiZ
}

bool UAAGameMenu_CP_Configuration::CanShowPanel()
{
	return true;
}

void UAAGameMenu_CP_Configuration::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case mchkbPrivateServer:
				if (mchkbPrivateServer.IsChecked())
				{
					mebGamePassword.EnableMe();
					mebGamePassword.SetText("");
					break;
				}
				mebGamePassword.DisableMe();
				mebGamePassword.SetText("");
	}
	GOTO JL007C;
		default:
			guibSaveChanges.EnableMe();
			GOTO JL007C;
		JL007C:
		*/
}

bool UAAGameMenu_CP_Configuration::ButtonClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case guibSaveChanges:
				HumanController(PlayerOwner()).ServerSetINISetting("GameInfo MaxPlayers " $ mneMaxPlayers.GetComponentValue());
				if (mneMaxPlayers.GetComponentValue() % 2 == 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam MaxTeamSize " $ mneMaxPlayers.GetComponentValue() / 2);
					break;
				}
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam MaxTeamSize " $ mneMaxPlayers.GetComponentValue() / 2 + 1);
	}
	HumanController(PlayerOwner()).ServerSetINISetting("GameInfo MaxAdmins " $ mneMaxAdmins.GetComponentValue());
	HumanController(PlayerOwner()).ServerSetINISetting("AccessControl GamePassword " $ mebGamePassword.GetText());
	Switch(mcbAutoBalanceOptions.GetIndex())
	{
			case 0:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bPlayersBalanceTeams true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bAutoBalanceBetweenRounds true ");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bNeverAutoBalance false");
				break;
			case 1:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bPlayersBalanceTeams false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bAutoBalanceBetweenRounds false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bNeverAutoBalance true");
				break;
			default:
	}
	HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameInfo ForceGameplay " $ mcbFireMode.GetExtra());
	HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameMultiPlayer MinHonor " $ mneMinHonor.GetComponentValue());
	HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameMultiPlayer MaxHonor " $ mneMaxHonor.GetComponentValue());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDLine1 " $ mebMOTD1.GetText());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDLine2 " $ mebMOTD2.GetText());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDLine3 " $ mebMOTD3.GetText());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDLine4 " $ mebMOTD4.GetText());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDDisplaySeconds " $ mneMOTDDisplayTime.GetComponentValue());
	HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameInfo iDelayedRoundStartTimeSeconds " $ mcbDelayedStartTime.GetExtra());
	guibSaveChanges.DisableMe();
	GOTO JL057A;
		default:
		JL057A:
			return true;

	*/

	return false;    //FAKE   /ELiZ
}