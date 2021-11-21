// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_Rules/AAGameMenu_CP_Rules.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"

UAAGameMenu_CP_Rules::UAAGameMenu_CP_Rules()
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
	SaveChanges->TabOrder = 23;
	//SaveChanges->OnClick=AAGameMenu_CP_Rules.ButtonClick;
	//SaveChanges->OnKeyEvent=SaveChanges.InternalOnKeyEvent;
	UmoCheckBox* HideHUDOpticsCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideHUDOpticsCheckbox->Caption = "Hide Optics";
	//HideHUDOpticsCheckbox->OnCreateComponent=HideHUDOpticsCheckbox.InternalOnCreateComponent;
	HideHUDOpticsCheckbox->IniOption = "@Internal";
	HideHUDOpticsCheckbox->Hint = "Check this to not show players the binoculars symbol for enhanced difficulty.";
	HideHUDOpticsCheckbox->WinTop = 0.87;
	HideHUDOpticsCheckbox->WinLeft = 0.69;
	HideHUDOpticsCheckbox->WinWidth = 0.3;
	HideHUDOpticsCheckbox->WinHeight = 0.05;
	HideHUDOpticsCheckbox->TabOrder = 21;
	HideHUDOpticsCheckbox->bStandardized = false;
	//HideHUDOpticsCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* HideHUDRadarCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideHUDRadarCheckbox->Caption = "Hide Radar";
	//HideHUDRadarCheckbox->OnCreateComponent=HideHUDRadarCheckbox.InternalOnCreateComponent;
	HideHUDRadarCheckbox->IniOption = "@Internal";
	HideHUDRadarCheckbox->Hint = "Check this to not show players the radar.";
	HideHUDRadarCheckbox->WinTop = 0.87;
	HideHUDRadarCheckbox->WinLeft = 0.37;
	HideHUDRadarCheckbox->WinWidth = 0.3;
	HideHUDRadarCheckbox->WinHeight = 0.05;
	HideHUDRadarCheckbox->TabOrder = 22;
	HideHUDRadarCheckbox->bStandardized = false;
	//HideHUDRadarCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* HideHUDTimerCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideHUDTimerCheckbox->Caption = "Hide Timer";
	//HideHUDTimerCheckbox->OnCreateComponent=HideHUDTimerCheckbox.InternalOnCreateComponent;
	HideHUDTimerCheckbox->IniOption = "@Internal";
	HideHUDTimerCheckbox->Hint = "Check this to not show players the round timer for enhanced difficulty.";
	HideHUDTimerCheckbox->WinTop = 0.87;
	HideHUDTimerCheckbox->WinLeft = 0.05;
	HideHUDTimerCheckbox->WinWidth = 0.3;
	HideHUDTimerCheckbox->WinHeight = 0.05;
	HideHUDTimerCheckbox->TabOrder = 19;
	HideHUDTimerCheckbox->bStandardized = false;
	//HideHUDTimerCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* HideHUDCEMCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideHUDCEMCheckbox->Caption = "Hide CE Meter";
	//HideHUDCEMCheckbox->OnCreateComponent=HideHUDCEMCheckbox.InternalOnCreateComponent;
	HideHUDCEMCheckbox->IniOption = "@Internal";
	HideHUDCEMCheckbox->Hint = "Check this to not show players the Combat Effectiveness Meter for enhanced difficulty.";
	HideHUDCEMCheckbox->WinTop = 0.82;
	HideHUDCEMCheckbox->WinLeft = 0.69;
	HideHUDCEMCheckbox->WinWidth = 0.3;
	HideHUDCEMCheckbox->WinHeight = 0.05;
	HideHUDCEMCheckbox->TabOrder = 18;
	HideHUDCEMCheckbox->bStandardized = false;
	//HideHUDCEMCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* HideHUDHealthCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideHUDHealthCheckbox->Caption = "Hide Health/Medic Info";
	//HideHUDHealthCheckbox->OnCreateComponent=HideHUDHealthCheckbox.InternalOnCreateComponent;
	HideHUDHealthCheckbox->IniOption = "@Internal";
	HideHUDHealthCheckbox->Hint = "Check this to not show players their current health status and medic indicator (if player is medic) for enhanced difficulty.";
	HideHUDHealthCheckbox->WinTop = 0.82;
	HideHUDHealthCheckbox->WinLeft = 0.37;
	HideHUDHealthCheckbox->WinWidth = 0.3;
	HideHUDHealthCheckbox->WinHeight = 0.05;
	HideHUDHealthCheckbox->TabOrder = 17;
	HideHUDHealthCheckbox->bStandardized = false;
	//HideHUDHealthCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* HideHUDGrenadesCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideHUDGrenadesCheckbox->Caption = "Hide Grenade Info";
	//HideHUDGrenadesCheckbox->OnCreateComponent=HideHUDGrenadesCheckbox.InternalOnCreateComponent;
	HideHUDGrenadesCheckbox->IniOption = "@Internal";
	HideHUDGrenadesCheckbox->Hint = "Check this to not show players their grenade information for enhanced difficulty.";
	HideHUDGrenadesCheckbox->WinTop = 0.82;
	HideHUDGrenadesCheckbox->WinLeft = 0.05;
	HideHUDGrenadesCheckbox->WinWidth = 0.3;
	HideHUDGrenadesCheckbox->WinHeight = 0.05;
	HideHUDGrenadesCheckbox->TabOrder = 16;
	HideHUDGrenadesCheckbox->bStandardized = false;
	//HideHUDGrenadesCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* HideHUDWeaponSelectionCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideHUDWeaponSelectionCheckbox->CaptionWidth = 0.3;
	HideHUDWeaponSelectionCheckbox->Caption = "Hide Weapon Info";
	//HideHUDWeaponSelectionCheckbox->OnCreateComponent=HideHUDWeaponSelectionCheckbox.InternalOnCreateComponent;
	HideHUDWeaponSelectionCheckbox->IniOption = "@Internal";
	HideHUDWeaponSelectionCheckbox->Hint = "Check this to not show players their current weapon selection for enhanced difficulty.";
	HideHUDWeaponSelectionCheckbox->WinTop = 0.77;
	HideHUDWeaponSelectionCheckbox->WinLeft = 0.69;
	HideHUDWeaponSelectionCheckbox->WinWidth = 0.3;
	HideHUDWeaponSelectionCheckbox->WinHeight = 0.05;
	HideHUDWeaponSelectionCheckbox->TabOrder = 15;
	HideHUDWeaponSelectionCheckbox->bStandardized = false;
	//HideHUDWeaponSelectionCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* HideHUDWeaponStatusCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideHUDWeaponStatusCheckbox->Caption = "Hide Weapon Status";
	//HideHUDWeaponStatusCheckbox->OnCreateComponent=HideHUDWeaponStatusCheckbox.InternalOnCreateComponent;
	HideHUDWeaponStatusCheckbox->IniOption = "@Internal";
	HideHUDWeaponStatusCheckbox->Hint = "Check this to not show players their current weapon status for enhanced difficulty.";
	HideHUDWeaponStatusCheckbox->WinTop = 0.77;
	HideHUDWeaponStatusCheckbox->WinLeft = 0.37;
	HideHUDWeaponStatusCheckbox->WinWidth = 0.3;
	HideHUDWeaponStatusCheckbox->WinHeight = 0.05;
	HideHUDWeaponStatusCheckbox->TabOrder = 14;
	HideHUDWeaponStatusCheckbox->bStandardized = false;
	//HideHUDWeaponStatusCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* HideHUDAmmoCountCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	HideHUDAmmoCountCheckbox->Caption = "Hide Ammo Count";
	//HideHUDAmmoCountCheckbox->OnCreateComponent=HideHUDAmmoCountCheckbox.InternalOnCreateComponent;
	HideHUDAmmoCountCheckbox->IniOption = "@Internal";
	HideHUDAmmoCountCheckbox->Hint = "Check this to not show players their current ammunition count for enhanced difficulty.";
	HideHUDAmmoCountCheckbox->WinTop = 0.77;
	HideHUDAmmoCountCheckbox->WinLeft = 0.05;
	HideHUDAmmoCountCheckbox->WinWidth = 0.3;
	HideHUDAmmoCountCheckbox->WinHeight = 0.05;
	HideHUDAmmoCountCheckbox->TabOrder = 13;
	HideHUDAmmoCountCheckbox->bStandardized = false;
	//HideHUDAmmoCountCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoComboBox* IdleKickRoundsDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	IdleKickRoundsDropDown->CaptionWidth = 0.4;
	IdleKickRoundsDropDown->Caption = "Idle Player Kick Rounds:";
	//IdleKickRoundsDropDown->OnCreateComponent=IdleKickRoundsDropDown.InternalOnCreateComponent;
	IdleKickRoundsDropDown->IniOption = "@Internal";
	IdleKickRoundsDropDown->Hint = "Select what you would like to happen to players are idle for a specific number of rounds. Note that player administrators cannot be kicked for idleness.";
	IdleKickRoundsDropDown->WinTop = 0.62;
	IdleKickRoundsDropDown->WinLeft = 0.5;
	IdleKickRoundsDropDown->WinWidth = 0.45;
	IdleKickRoundsDropDown->WinHeight = 0.04;
	IdleKickRoundsDropDown->TabOrder = 12;
	IdleKickRoundsDropDown->bStandardized = false;
	//IdleKickRoundsDropDown->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoComboBox* IdleKickMinutesDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	IdleKickMinutesDropDown->CaptionWidth = 0.57;
	IdleKickMinutesDropDown->Caption = "Idle Player Kick Minutes:";
	//IdleKickMinutesDropDown->OnCreateComponent=IdleKickMinutesDropDown.InternalOnCreateComponent;
	IdleKickMinutesDropDown->IniOption = "@Internal";
	IdleKickMinutesDropDown->Hint = "Select what you would like to happen to players are idle for a specific number of minutes. Note that player administrators cannot be kicked for idleness.";
	IdleKickMinutesDropDown->WinTop = 0.62;
	IdleKickMinutesDropDown->WinLeft = 0.05;
	IdleKickMinutesDropDown->WinWidth = 0.43;
	IdleKickMinutesDropDown->WinHeight = 0.04;
	IdleKickMinutesDropDown->TabOrder = 11;
	IdleKickMinutesDropDown->bStandardized = false;
	//IdleKickMinutesDropDown->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoComboBox* ROEKickDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	ROEKickDropDown->CaptionWidth = 0.4;
	ROEKickDropDown->Caption = "ROE Violation Options:";
	//ROEKickDropDown->OnCreateComponent=ROEKickDropDown.InternalOnCreateComponent;
	ROEKickDropDown->IniOption = "@Internal";
	ROEKickDropDown->Hint = "Select what you would like to happen to players that violate the Rules of Engagement. Note that player administrators cannot be kicked for ROE violations.";
	ROEKickDropDown->WinTop = 0.56;
	ROEKickDropDown->WinLeft = 0.05;
	ROEKickDropDown->WinWidth = 0.63;
	ROEKickDropDown->WinHeight = 0.04;
	ROEKickDropDown->TabOrder = 10;
	ROEKickDropDown->bStandardized = false;
	//ROEKickDropDown->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* EnableROETimerCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	EnableROETimerCheckbox->CaptionWidth = 0.9;
	EnableROETimerCheckbox->Caption = "Kick Players For Early ROE";
	//EnableROETimerCheckbox->OnCreateComponent=EnableROETimerCheckbox.InternalOnCreateComponent;
	EnableROETimerCheckbox->IniOption = "@Internal";
	EnableROETimerCheckbox->Hint = "Checking this box will activate automatic kicking of players that commit ROE in the first 20 seconds of a round.";
	EnableROETimerCheckbox->WinTop = 0.5;
	EnableROETimerCheckbox->WinLeft = 0.5;
	EnableROETimerCheckbox->WinWidth = 0.35;
	EnableROETimerCheckbox->WinHeight = 0.05;
	EnableROETimerCheckbox->TabOrder = 9;
	EnableROETimerCheckbox->bStandardized = false;
	//EnableROETimerCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoNumericEdit* ROEKickEditField = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	ROEKickEditField->CaptionWidth = 0.7;
	ROEKickEditField->Caption = "Friendly Fire ROE Limit:";
	//ROEKickEditField->OnCreateComponent=ROEKickEditField.InternalOnCreateComponent;
	ROEKickEditField->IniOption = "@Internal";
	ROEKickEditField->Hint = "This is the number of ROE points that must be accumulated to activate the \"ROE Kick\" feature.  Note that player administrators cannot be kicked for ROE violations.";
	ROEKickEditField->WinTop = 0.5;
	ROEKickEditField->WinLeft = 0.05;
	ROEKickEditField->WinWidth = 0.39;
	ROEKickEditField->WinHeight = 0.04;
	ROEKickEditField->TabOrder = 8;
	ROEKickEditField->bStandardized = false;
	//ROEKickEditField->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoComboBox* ChatLoggingLevelDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	ChatLoggingLevelDropDown->CaptionWidth = 0.3;
	ChatLoggingLevelDropDown->Caption = "Chat Logging:";
	//ChatLoggingLevelDropDown->OnCreateComponent=ChatLoggingLevelDropDown.InternalOnCreateComponent;
	ChatLoggingLevelDropDown->IniOption = "@Internal";
	ChatLoggingLevelDropDown->Hint = "Use this to enable logging all chat text to the \"System\\ChatLogs\" folder on the server.";
	ChatLoggingLevelDropDown->WinTop = 0.39;
	ChatLoggingLevelDropDown->WinLeft = 0.5;
	ChatLoggingLevelDropDown->WinWidth = 0.4;
	ChatLoggingLevelDropDown->WinHeight = 0.05;
	ChatLoggingLevelDropDown->TabOrder = 6;
	ChatLoggingLevelDropDown->bStandardized = false;
	//ChatLoggingLevelDropDown->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* DisableAllClientShadowsCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DisableAllClientShadowsCheckbox->Caption = "Disable Player Shadows";
	//DisableAllClientShadowsCheckbox->OnCreateComponent=DisableAllClientShadowsCheckbox.InternalOnCreateComponent;
	DisableAllClientShadowsCheckbox->IniOption = "@Internal";
	DisableAllClientShadowsCheckbox->Hint = "Check this to disable allowing any player shadows on clients (useful for tournaments to prevent video drivers from allowing shadow exploits).";
	DisableAllClientShadowsCheckbox->WinTop = 0.39;
	DisableAllClientShadowsCheckbox->WinLeft = 0.05;
	DisableAllClientShadowsCheckbox->WinWidth = 0.3;
	DisableAllClientShadowsCheckbox->WinHeight = 0.05;
	DisableAllClientShadowsCheckbox->TabOrder = 7;
	DisableAllClientShadowsCheckbox->bStandardized = false;
	//DisableAllClientShadowsCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoComboBox* ScoreboardRulesDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	ScoreboardRulesDropDown->CaptionWidth = 0.35;
	ScoreboardRulesDropDown->Caption = "Scoreboard Display Rules:";
	//ScoreboardRulesDropDown->OnCreateComponent=ScoreboardRulesDropDown.InternalOnCreateComponent;
	ScoreboardRulesDropDown->IniOption = "@Internal";
	ScoreboardRulesDropDown->Hint = "Select the spectating rules you would like to use for players on this server.  Note that admin and player admin scoreboard viewing is not affected by this option.";
	ScoreboardRulesDropDown->WinTop = 0.33;
	ScoreboardRulesDropDown->WinLeft = 0.05;
	ScoreboardRulesDropDown->WinWidth = 0.84;
	ScoreboardRulesDropDown->WinHeight = 0.04;
	ScoreboardRulesDropDown->TabOrder = 6;
	ScoreboardRulesDropDown->bStandardized = false;
	//ScoreboardRulesDropDown->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoComboBox* SpectatingRulesDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	SpectatingRulesDropDown->CaptionWidth = 0.28;
	SpectatingRulesDropDown->Caption = "Spectating Rules:";
	//SpectatingRulesDropDown->OnCreateComponent=SpectatingRulesDropDown.InternalOnCreateComponent;
	SpectatingRulesDropDown->IniOption = "@Internal";
	SpectatingRulesDropDown->Hint = "Select the spectating rules you would like to use for players on this server.";
	SpectatingRulesDropDown->WinTop = 0.27;
	SpectatingRulesDropDown->WinLeft = 0.05;
	SpectatingRulesDropDown->WinWidth = 0.75;
	SpectatingRulesDropDown->WinHeight = 0.04;
	SpectatingRulesDropDown->TabOrder = 5;
	SpectatingRulesDropDown->bStandardized = false;
	//SpectatingRulesDropDown->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* ESSDisableCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	ESSDisableCheckbox->Caption = "Disable ES2 Features";
	//ESSDisableCheckbox->OnCreateComponent=ESSDisableCheckbox.InternalOnCreateComponent;
	ESSDisableCheckbox->IniOption = "@Internal";
	ESSDisableCheckbox->Hint = "Check this to disable the Every Soldier Is A Sensor (ES2) map features, if present.";
	ESSDisableCheckbox->WinTop = 0.21;
	ESSDisableCheckbox->WinLeft = 0.75;
	ESSDisableCheckbox->WinWidth = 0.24;
	ESSDisableCheckbox->WinHeight = 0.05;
	ESSDisableCheckbox->TabOrder = 2;
	ESSDisableCheckbox->bStandardized = false;
	//ESSDisableCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoComboBox* TimeLimitDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	TimeLimitDropDown->CaptionWidth = 0.6;
	TimeLimitDropDown->Caption = "Round Time Limit:";
	//TimeLimitDropDown->OnCreateComponent=TimeLimitDropDown.InternalOnCreateComponent;
	TimeLimitDropDown->IniOption = "@Internal";
	TimeLimitDropDown->Hint = "Enter the length of each round (in minutes).  Note this will not take effect until the next round starts.";
	TimeLimitDropDown->WinTop = 0.21;
	TimeLimitDropDown->WinLeft = 0.4;
	TimeLimitDropDown->WinWidth = 0.3;
	TimeLimitDropDown->WinHeight = 0.04;
	TimeLimitDropDown->TabOrder = 4;
	TimeLimitDropDown->bStandardized = false;
	//TimeLimitDropDown->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoComboBox* RoundsPerMatchDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	RoundsPerMatchDropDown->CaptionWidth = 0.6;
	RoundsPerMatchDropDown->Caption = "Rounds Per Match:";
	//RoundsPerMatchDropDown->OnCreateComponent=RoundsPerMatchDropDown.InternalOnCreateComponent;
	RoundsPerMatchDropDown->IniOption = "@Internal";
	RoundsPerMatchDropDown->Hint = "Enter the number of rounds to play for each match.";
	RoundsPerMatchDropDown->WinTop = 0.21;
	RoundsPerMatchDropDown->WinLeft = 0.05;
	RoundsPerMatchDropDown->WinWidth = 0.3;
	RoundsPerMatchDropDown->WinHeight = 0.04;
	RoundsPerMatchDropDown->TabOrder = 3;
	RoundsPerMatchDropDown->bStandardized = false;
	//RoundsPerMatchDropDown->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* OpenAllWeaponSlotsCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	OpenAllWeaponSlotsCheckbox->Caption = "Open All Weapon Slots";
	//OpenAllWeaponSlotsCheckbox->OnCreateComponent=OpenAllWeaponSlotsCheckbox.InternalOnCreateComponent;
	OpenAllWeaponSlotsCheckbox->IniOption = "@Internal";
	OpenAllWeaponSlotsCheckbox->Hint = "Check this to open all weapon slots regardless of the number of players.";
	OpenAllWeaponSlotsCheckbox->WinTop = 0.15;
	OpenAllWeaponSlotsCheckbox->WinLeft = 0.7;
	OpenAllWeaponSlotsCheckbox->WinWidth = 0.25;
	OpenAllWeaponSlotsCheckbox->WinHeight = 0.05;
	OpenAllWeaponSlotsCheckbox->TabOrder = 2;
	OpenAllWeaponSlotsCheckbox->bStandardized = false;
	//OpenAllWeaponSlotsCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* EnableDeathMessagesCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	EnableDeathMessagesCheckbox->Caption = "Show Death Messages";
	//EnableDeathMessagesCheckbox->OnCreateComponent=EnableDeathMessagesCheckbox.InternalOnCreateComponent;
	EnableDeathMessagesCheckbox->IniOption = "@Internal";
	EnableDeathMessagesCheckbox->Hint = "Uncheck this to hide death messages for enhanced difficulty.";
	EnableDeathMessagesCheckbox->WinTop = 0.15;
	EnableDeathMessagesCheckbox->WinLeft = 0.4;
	EnableDeathMessagesCheckbox->WinWidth = 0.25;
	EnableDeathMessagesCheckbox->WinHeight = 0.05;
	EnableDeathMessagesCheckbox->TabOrder = 2;
	EnableDeathMessagesCheckbox->bStandardized = false;
	//EnableDeathMessagesCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UmoCheckBox* EnableCheatsCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	EnableCheatsCheckbox->Caption = "Enable Multiplayer Cheats";
	//EnableCheatsCheckbox->OnCreateComponent=EnableCheatsCheckbox.InternalOnCreateComponent;
	EnableCheatsCheckbox->IniOption = "@Internal";
	EnableCheatsCheckbox->Hint = "Checking this box will enable multiplayer cheats for anyone playing on the server.  It will disable all honor updates.";
	EnableCheatsCheckbox->WinTop = 0.15;
	EnableCheatsCheckbox->WinLeft = 0.05;
	EnableCheatsCheckbox->WinWidth = 0.3;
	EnableCheatsCheckbox->WinHeight = 0.05;
	EnableCheatsCheckbox->TabOrder = 1;
	EnableCheatsCheckbox->bStandardized = false;
	//EnableCheatsCheckbox->OnChange=AAGameMenu_CP_Rules.InternalOnChange;
	UGUILabel* InstructionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InstructionsLabel->TextColor = FColor(255, 255, 255, 255);
	InstructionsLabel->StyleName = "TextLabel";
	InstructionsLabel->WinTop = 0.07;
	InstructionsLabel->WinLeft = 0.05;
	InstructionsLabel->WinWidth = 0.9;
	InstructionsLabel->WinHeight = 0.05;
	UGUILabel* ROEKickOptionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ROEKickOptionsLabel->Caption = "Rules of Engagement (ROE) and Player Kick Options";
	ROEKickOptionsLabel->TextAlign = ETextAlign::TXTA_Center;
	ROEKickOptionsLabel->TextColor = FColor(255, 255, 255, 255);
	ROEKickOptionsLabel->StyleName = "TextLabel";
	ROEKickOptionsLabel->WinTop = 0.44;
	ROEKickOptionsLabel->WinLeft = 0.05;
	ROEKickOptionsLabel->WinWidth = 0.9;
	ROEKickOptionsLabel->WinHeight = 0.05;
	UGUILabel* HUDOptionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	HUDOptionsLabel->Caption = "HUD Options For Enhanced Difficulty";
	HUDOptionsLabel->TextAlign = ETextAlign::TXTA_Center;
	HUDOptionsLabel->TextColor = FColor(255, 255, 255, 255);
	HUDOptionsLabel->StyleName = "TextLabel";
	HUDOptionsLabel->WinTop = 0.71;
	HUDOptionsLabel->WinLeft = 0.05;
	HUDOptionsLabel->WinWidth = 0.9;
	HUDOptionsLabel->WinHeight = 0.05;
	mchkbEnableCheats = EnableCheatsCheckbox;
	mcbRoundsPerMatch = RoundsPerMatchDropDown;
	mcbTimeLimit = TimeLimitDropDown;
	mcbSpectatingMode = SpectatingRulesDropDown;
	mchkbEnableDeathMessages = EnableDeathMessagesCheckbox;
	mchkbOpenAllWeaponSlots = OpenAllWeaponSlotsCheckbox;
	mchkbDisableAllClientShadows = DisableAllClientShadowsCheckbox;
	mcbChatLoggingLevel = ChatLoggingLevelDropDown;
	mcbScoreboardMode = ScoreboardRulesDropDown;
	mneROELimit = ROEKickEditField;
	mcbROEKick = ROEKickDropDown;
	mchkbROEKickTimer = EnableROETimerCheckbox;
	guibSaveChanges = SaveChanges;
	mchkbESSDisable = ESSDisableCheckbox;
	mcbIdleKickMinutes = IdleKickMinutesDropDown;
	mcbIdleKickRounds = IdleKickRoundsDropDown;
	mchkbHUDHideAmmoCount = HideHUDAmmoCountCheckbox;
	mchkbHUDHideWeaponStatus = HideHUDWeaponStatusCheckbox;
	mchkbHUDHideWeaponSelection = HideHUDWeaponSelectionCheckbox;
	mchkbHUDHideGrenades = HideHUDGrenadesCheckbox;
	mchkbHUDHideHealth = HideHUDHealthCheckbox;
	mchkbHUDHideCEM = HideHUDCEMCheckbox;
	mchkbHUDHideTimer = HideHUDTimerCheckbox;
	mchkbHUDHideRadar = HideHUDRadarCheckbox;
	mchkbHUDHideOptics = HideHUDOpticsCheckbox;
	gulInstructions = InstructionsLabel;
	gulHUDOptionsTitle = HUDOptionsLabel;
	gulROEKickOptionsTitle = ROEKickOptionsLabel;

	sInstructions = "Use this to customize game-play rules.";
	sHUDOptionsTitle = "HUD Options For Enhanced Difficulty";
	WinHeight = 1;
}

void UAAGameMenu_CP_Rules::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int iTimeEntry;
	local int iRounds;
	InitComponent(MyController, MyOwner);
	gulInstructions.Caption = sInstructions;
	gulHUDOptionsTitle.Caption = sHUDOptionsTitle;
	mcbRoundsPerMatch.MyComboBox.Edit.bReadOnly = True;
	mcbTimeLimit.MyComboBox.Edit.bReadOnly = True;
	mcbSpectatingMode.MyComboBox.Edit.bReadOnly = True;
	mcbScoreboardMode.MyComboBox.Edit.bReadOnly = True;
	mcbROEKick.MyComboBox.Edit.bReadOnly = True;
	mcbIdleKickMinutes.MyComboBox.Edit.bReadOnly = True;
	mcbIdleKickRounds.MyComboBox.Edit.bReadOnly = True;
	for (iTimeEntry = 1; iTimeEntry <= 20; iTimeEntry++)
	{
		mcbTimeLimit.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry $ " minutes", , "" $ iTimeEntry);
	}
	mcbIdleKickMinutes.MyComboBox.List.Insert(0, "Disabled", , "0");
	for (iTimeEntry = 1; iTimeEntry <= 10; iTimeEntry++)
	{
		mcbIdleKickMinutes.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry, , "" $ iTimeEntry);
	}
	for (iRounds = 1; iRounds <= 30; iRounds++)
	{
		mcbRoundsPerMatch.MyComboBox.List.Insert(iRounds - 1, "" $ iRounds $ " rounds", , "" $ iRounds);
	}
	if (HumanController(PlayerOwner()).TournamentIsTournament())
	{
		if (HumanController(PlayerOwner()).GameReplicationInfo.sTournamentState != "Setup")
		{
			mcbRoundsPerMatch.DisableMe();
			mcbRoundsPerMatch.MyComboBox.Hint = "You may only adjust rounds per match for tournaments before the tournament starts.";
			mcbTimeLimit.DisableMe();
			mcbTimeLimit.MyComboBox.Hint = "You may only adjust round length for tournaments before the tournament starts.";
		}
	}
	mcbIdleKickRounds.MyComboBox.List.Insert(0, "Disabled");
	for (iRounds = 1; iRounds <= 10; iRounds++)
	{
		mcbIdleKickRounds.MyComboBox.List.Insert(iRounds - 1, "" $ iRounds, , "" $ iRounds);
	}
	mcbSpectatingMode.MyComboBox.List.Insert(0, "Players Only First Person View");
	mcbSpectatingMode.MyComboBox.List.Insert(1, "Players Only First and Third Person Views");
	mcbSpectatingMode.MyComboBox.List.Insert(2, "Viewpoints and Same Team Players' Views");
	mcbSpectatingMode.MyComboBox.List.Insert(3, "Viewpoints and All Players' Views");
	mcbScoreboardMode.MyComboBox.List.Insert(0, "Scoreboard Always Available", , "SSM_On");
	mcbScoreboardMode.MyComboBox.List.Insert(1, "Scoreboard Never Available", , "SSM_Off");
	mcbScoreboardMode.MyComboBox.List.Insert(2, "Scoreboard Available At End of Round Only", , "SSM_Round");
	mcbScoreboardMode.MyComboBox.List.Insert(3, "Scoreboard Available At End of Match Only", , "SSM_Match");
	mcbChatLoggingLevel.MyComboBox.List.Insert(0, "Logging Disabled", , "0");
	mcbChatLoggingLevel.MyComboBox.List.Insert(1, "Basic Chat Text Only", , "1");
	mcbChatLoggingLevel.MyComboBox.List.Insert(2, "Admin Actions + Chat Text", , "2");
	mcbChatLoggingLevel.MyComboBox.List.Insert(3, "System, Admin, and Chat", , "3");
	mcbScoreboardMode.MyComboBox.List.SetIndex(0);
	mneROELimit.MyNumericEdit.MinValue = 0;
	mneROELimit.MyNumericEdit.MaxValue = 5000;
	mcbROEKick.MyComboBox.List.Insert(0, "Kick player to Leavenworth");
	mcbROEKick.MyComboBox.List.Insert(1, "Kill Player");
	mcbROEKick.MyComboBox.List.Insert(2, "Ignore Violations");
	*/
}

void UAAGameMenu_CP_Rules::InitializeDataFields()
{
	/*
	if (aagpCommandPost == None)
	{
		Log("Warning: The CP Rules page does not have a valid Command Post page.");
		Return;
	}
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameMultiPlayer bMPCheatsEnabled");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam FFScoreLimit");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch RoundsPerMatch");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameInfo TimeLimit");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bForceShadowsOff");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "BroadcastHandler iLogChatLevel");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bSpectatePlayersOnly");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bSpectateFirstPersonOnly");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bSpectateFriendsOnly");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch IdlePlayerKickTime");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch bKickIdlePlayersTimed");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch IdlePlayerKickRounds");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch bKickIdlePlayersRounds");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bEnableROEKickTimer");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bEnableROEKickDeath");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bEnableROEKick");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameInfo ScoreMode");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameInfo bDeathMessages");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameInfo bOpenAllWeaponClassSlots");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameInfo bDisableESS");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideAmmoCount");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideWeaponStatus");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideWeapon");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideGrenades");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideHealth");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideCombatEffect");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideOptics");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideTimer");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideMedical");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideRadar");
	*/
}

bool UAAGameMenu_CP_Rules::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;    //FAKE    /ELiZ
}

bool UAAGameMenu_CP_Rules::CanShowPanel()
{
	return true;
}

void UAAGameMenu_CP_Rules::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			default:
				guibSaveChanges.EnableMe();
				break;
	}
	*/
}

bool UAAGameMenu_CP_Rules::ButtonClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case guibSaveChanges:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameMultiPlayer bMPCheatsEnabled " $ mchkbEnableCheats.IsChecked());
				if (mcbRoundsPerMatch.GetComponentValue() > 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch RoundsPerMatch " $ mcbRoundsPerMatch.GetComponentValue());
					HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameDeathMatch RoundsPerMatch", mcbRoundsPerMatch.GetComponentValue());
				}
				if (mcbTimeLimit.GetComponentValue() > 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("GameInfo TimeLimit " $ mcbTimeLimit.GetComponentValue());
					HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("GameInfo TimeLimit", mcbTimeLimit.GetComponentValue());
				}
				Switch(mcbSpectatingMode.GetIndex())
				{
			case 0:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectatePlayersOnly true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFirstPersonOnly true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFriendsOnly true");
				break;
			case 1:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectatePlayersOnly true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFirstPersonOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFriendsOnly true");
				break;
			case 2:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectatePlayersOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFirstPersonOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFriendsOnly true");
				break;
			case 3:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectatePlayersOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFirstPersonOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFriendsOnly false");
				break;
			default:
				}
				HumanController(PlayerOwner()).ServerSetINISetting("GameInfo bDeathMessages " $ mchkbEnableDeathMessages.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameInfo bDisableESS " $ mchkbESSDisable.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameInfo bOpenAllWeaponClassSlots " $ mchkbOpenAllWeaponSlots.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bForceShadowsOff " $ mchkbDisableAllClientShadows.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("BroadcastHandler iLogChatLevel " $ mcbChatLoggingLevel.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("GameInfo ScoreMode " $ mcbScoreboardMode.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam FFScoreLimit " $ mneROELimit.GetComponentValue());
				Switch(mcbROEKick.GetIndex())
				{
			case 0:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKickDeath false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKick true");
				break;
			case 1:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKickDeath true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKick true");
				break;
			case 2:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKickDeath false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKick false");
				break;
			default:
				}
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKickTimer " $ mchkbROEKickTimer.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch IdlePlayerKickTime " $ mcbIdleKickMinutes.GetExtra());
				if (mcbIdleKickMinutes.GetExtra() > 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch bKickIdlePlayersTimed true");
				}
				else
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch bKickIdlePlayersTimed false");
				}
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch IdlePlayerKickRounds " $ mcbIdleKickRounds.GetExtra());
				if (mcbIdleKickRounds.GetExtra() > 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch bKickIdlePlayersRounds true");
				}
				else
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch bKickIdlePlayersRounds false");
				}
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideAmmoCount " $ mchkbHUDHideAmmoCount.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideWeaponStatus " $ mchkbHUDHideWeaponStatus.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideWeapon " $ mchkbHUDHideWeaponSelection.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideGrenades " $ mchkbHUDHideGrenades.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideHealth " $ mchkbHUDHideHealth.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideCombatEffect " $ mchkbHUDHideCEM.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideOptics " $ mchkbHUDHideOptics.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideTimer " $ mchkbHUDHideTimer.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideMedical " $ mchkbHUDHideHealth.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideRadar " $ mchkbHUDHideRadar.GetComponentValue());
				guibSaveChanges.DisableMe();
				GOTO JL0CCF;
			default:
			JL0CCF:
				Return True;
	}
	*/
	return false;    //FAKE  /EliZ
}

void UAAGameMenu_CP_Rules::NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3)
{
	/*
	if (sParam1 ~= "INIEntry")
	{
		if (sParam2 ~= "AGP_GameMultiPlayer bMPCheatsEnabled")
		{
			mchkbEnableCheats.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bSpectatePlayersOnly")
		{
			bSpectatePlayersOnly = sParam3;
			UpdateSpectatingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bSpectateFirstPersonOnly")
		{
			bSpectateFirstPersonOnly = sParam3;
			UpdateSpectatingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bSpectateFriendsOnly")
		{
			bSpectateFriendsOnly = sParam3;
			UpdateSpectatingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch RoundsPerMatch")
		{
			if (sParam3 > 1)
			{
				sParam3 = sParam3 $ " rounds";
			}
			else
			{
				sParam3 = sParam3 $ " round";
			}
			mcbRoundsPerMatch.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo TimeLimit")
		{
			if (sParam3 > 1)
			{
				sParam3 = sParam3 $ " minutes";
			}
			else
			{
				sParam3 = sParam3 $ " minute";
			}
			mcbTimeLimit.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam FFScoreLimit")
		{
			mneROELimit.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bEnableROEKickTimer")
		{
			mchkbROEKickTimer.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bEnableROEKickDeath")
		{
			bROEKickDeath = sParam3;
			UpdateROEKickOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bEnableROEKick")
		{
			bEnableROEKick = sParam3;
			UpdateROEKickOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo ScoreMode")
		{
			if (sParam3 ~= "SSM_On")
			{
				mcbScoreboardMode.MyComboBox.List.SetIndex(0);
				guibSaveChanges.DisableMe();
				Return;
			}
			if (sParam3 ~= "SSM_Off")
			{
				mcbScoreboardMode.MyComboBox.List.SetIndex(1);
				guibSaveChanges.DisableMe();
				Return;
			}
			if (sParam3 ~= "SSM_Round")
			{
				mcbScoreboardMode.MyComboBox.List.SetIndex(2);
				guibSaveChanges.DisableMe();
				Return;
			}
			if (sParam3 ~= "SSM_Match")
			{
				mcbScoreboardMode.MyComboBox.List.SetIndex(3);
				guibSaveChanges.DisableMe();
				Return;
			}
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideAmmoCount")
		{
			mchkbHUDHideAmmoCount.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideWeaponStatus")
		{
			mchkbHUDHideWeaponStatus.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideWeapon")
		{
			mchkbHUDHideWeaponSelection.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideGrenades")
		{
			mchkbHUDHideGrenades.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideHealth")
		{
			mchkbHUDHideHealth.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideCombatEffect")
		{
			mchkbHUDHideCEM.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideOptics")
		{
			mchkbHUDHideOptics.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideTimer")
		{
			mchkbHUDHideTimer.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideMedical")
		{
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideRadar")
		{
			mchkbHUDHideRadar.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "BroadcastHandler iLogChatLevel")
		{
			mcbChatLoggingLevel.MyComboBox.List.SetIndex(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameInfo bDisableESS")
		{
			mchkbESSDisable.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo bDeathMessages")
		{
			mchkbEnableDeathMessages.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameInfo bOpenAllWeaponClassSlots")
		{
			Log("Param passed in is " $ sParam2 $ " value is " $ sParam3);
			mchkbOpenAllWeaponSlots.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bForceShadowsOff")
		{
			mchkbDisableAllClientShadows.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch IdlePlayerKickRounds")
		{
			iIdlePlayerKickRounds = sParam3;
			UpdateIdlePlayerOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch bKickIdlePlayersRounds")
		{
			bKickIdlePlayersRounds = sParam3;
			UpdateIdlePlayerOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch bKickIdlePlayersTimed")
		{
			bKickIdlePlayersTimed = sParam3;
			UpdateIdlePlayerOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch IdlePlayerKickTime")
		{
			iIdlePlayerKickMinutes = sParam3;
			UpdateIdlePlayerOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
	}
	*/
}

void UAAGameMenu_CP_Rules::UpdateIdlePlayerOptions()
{
	/*
	if (bKickIdlePlayersTimed && iIdlePlayerKickMinutes > 0)
	{
		mcbIdleKickMinutes.SetText("" $ iIdlePlayerKickMinutes);
	}
	else
	{
		mcbIdleKickMinutes.SetText("Disabled");
	}
	if (bKickIdlePlayersRounds && iIdlePlayerKickRounds > 0)
	{
		mcbIdleKickRounds.SetText("" $ iIdlePlayerKickRounds);
	}
	else
	{
		mcbIdleKickRounds.SetText("Disabled");
	}
	*/
}

void UAAGameMenu_CP_Rules::UpdateROEKickOptions()
{
	/*
	if (!bEnableROEKick)
	{
		mcbROEKick.MyComboBox.List.SetIndex(2);
		Return;
	}
	if (!bROEKickDeath)
	{
		mcbROEKick.MyComboBox.List.SetIndex(0);
	}
	else
	{
		mcbROEKick.MyComboBox.List.SetIndex(1);
	}
	*/
}

void UAAGameMenu_CP_Rules::UpdateSpectatingRulesField()
{
	/*
	if (!bSpectatePlayersOnly && !bSpectateFriendsOnly)
	{
		mcbSpectatingMode.MyComboBox.List.SetIndex(3);
		Return;
	}
	if (!bSpectatePlayersOnly && bSpectateFriendsOnly)
	{
		mcbSpectatingMode.MyComboBox.List.SetIndex(2);
		Return;
	}
	if (bSpectatePlayersOnly && !bSpectateFirstPersonOnly)
	{
		mcbSpectatingMode.MyComboBox.List.SetIndex(1);
		Return;
	}
	if (bSpectatePlayersOnly && bSpectateFirstPersonOnly)
	{
		mcbSpectatingMode.MyComboBox.List.SetIndex(0);
		Return;
	}
	mcbSpectatingMode.MyComboBox.List.SetIndex(1);
	*/
}