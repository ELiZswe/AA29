// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_Tournament/AAGameMenu_CP_Tournament.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"

UAAGameMenu_CP_Tournament::UAAGameMenu_CP_Tournament()
{
	UGUIButton* SwitchServerModes = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SwitchServerModes->Caption = "Activate TM";
	SwitchServerModes->StyleName = "SquareMenuButton";
	SwitchServerModes->Hint = "Click here to restart the server in Tournament mode.";
	SwitchServerModes->WinTop = 0.21;
	SwitchServerModes->WinLeft = 0.74;
	SwitchServerModes->WinWidth = 0.25;
	SwitchServerModes->WinHeight = 0.05;
	SwitchServerModes->TabOrder = 24;
	//SwitchServerModes->OnClick=AAGameMenu_CP_Tournament.ButtonClick;
	//SwitchServerModes->OnKeyEvent=SwitchServerModes.InternalOnKeyEvent;
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
	//SaveChanges->OnClick=AAGameMenu_CP_Tournament.ButtonClick;
	//SaveChanges->OnKeyEvent=SaveChanges.InternalOnKeyEvent;
	UmoCheckBox* Disable203ReloadsCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	Disable203ReloadsCheckbox->CaptionWidth = 0.85;
	Disable203ReloadsCheckbox->Caption = "No 203 Reloads";
	//Disable203ReloadsCheckbox->OnCreateComponent=Disable203ReloadsCheckbox.InternalOnCreateComponent;
	Disable203ReloadsCheckbox->IniOption = "@Internal";
	Disable203ReloadsCheckbox->Hint = "Check this to disable all 203 reloads and 203 Mods in Tournament matches.  Note: Players with the M16/M203 will still keep the original 203 round in the launcher.";
	Disable203ReloadsCheckbox->WinTop = 0.86;
	Disable203ReloadsCheckbox->WinLeft = 0.81;
	Disable203ReloadsCheckbox->WinWidth = 0.19;
	Disable203ReloadsCheckbox->WinHeight = 0.05;
	Disable203ReloadsCheckbox->TabOrder = 22;
	Disable203ReloadsCheckbox->bStandardized = false;
	//Disable203ReloadsCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoCheckBox* DisableThermiteGrenadeCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DisableThermiteGrenadeCheckbox->CaptionWidth = 0.85;
	DisableThermiteGrenadeCheckbox->Caption = "No Thermites";
	//DisableThermiteGrenadeCheckbox->OnCreateComponent=DisableThermiteGrenadeCheckbox.InternalOnCreateComponent;
	DisableThermiteGrenadeCheckbox->IniOption = "@Internal";
	DisableThermiteGrenadeCheckbox->Hint = "Check this to disable thermite grenades in Tournament matches.  WARNING: Disabling this may affect players' ability to complete missions.";
	DisableThermiteGrenadeCheckbox->WinTop = 0.86;
	DisableThermiteGrenadeCheckbox->WinLeft = 0.62;
	DisableThermiteGrenadeCheckbox->WinWidth = 0.16;
	DisableThermiteGrenadeCheckbox->WinHeight = 0.05;
	DisableThermiteGrenadeCheckbox->TabOrder = 21;
	DisableThermiteGrenadeCheckbox->bStandardized = false;
	//DisableThermiteGrenadeCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoCheckBox* DisableFlashbangGrenadeCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DisableFlashbangGrenadeCheckbox->CaptionWidth = 0.9;
	DisableFlashbangGrenadeCheckbox->Caption = "No Flash";
	//DisableFlashbangGrenadeCheckbox->OnCreateComponent=DisableFlashbangGrenadeCheckbox.InternalOnCreateComponent;
	DisableFlashbangGrenadeCheckbox->IniOption = "@Internal";
	DisableFlashbangGrenadeCheckbox->Hint = "Check this to disable flashbang grenades in Tournament matches.";
	DisableFlashbangGrenadeCheckbox->WinTop = 0.86;
	DisableFlashbangGrenadeCheckbox->WinLeft = 0.43;
	DisableFlashbangGrenadeCheckbox->WinWidth = 0.12;
	DisableFlashbangGrenadeCheckbox->WinHeight = 0.05;
	DisableFlashbangGrenadeCheckbox->TabOrder = 20;
	DisableFlashbangGrenadeCheckbox->bStandardized = false;
	//DisableFlashbangGrenadeCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoCheckBox* DisableSmokeGrenadeCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DisableSmokeGrenadeCheckbox->CaptionWidth = 0.9;
	DisableSmokeGrenadeCheckbox->Caption = "No Smoke";
	//DisableSmokeGrenadeCheckbox->OnCreateComponent=DisableSmokeGrenadeCheckbox.InternalOnCreateComponent;
	DisableSmokeGrenadeCheckbox->IniOption = "@Internal";
	DisableSmokeGrenadeCheckbox->Hint = "Check this to disable smoke grenades in Tournament matches.";
	DisableSmokeGrenadeCheckbox->WinTop = 0.86;
	DisableSmokeGrenadeCheckbox->WinLeft = 0.24;
	DisableSmokeGrenadeCheckbox->WinWidth = 0.13;
	DisableSmokeGrenadeCheckbox->WinHeight = 0.05;
	DisableSmokeGrenadeCheckbox->TabOrder = 19;
	DisableSmokeGrenadeCheckbox->bStandardized = false;
	//DisableSmokeGrenadeCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoCheckBox* DisableFragGrenadeCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	DisableFragGrenadeCheckbox->CaptionWidth = 0.9;
	DisableFragGrenadeCheckbox->Caption = "No Frags";
	//DisableFragGrenadeCheckbox->OnCreateComponent=DisableFragGrenadeCheckbox.InternalOnCreateComponent;
	DisableFragGrenadeCheckbox->IniOption = "@Internal";
	DisableFragGrenadeCheckbox->Hint = "Check this to disable frag grenades in Tournament matches.";
	DisableFragGrenadeCheckbox->WinTop = 0.86;
	DisableFragGrenadeCheckbox->WinLeft = 0.05;
	DisableFragGrenadeCheckbox->WinWidth = 0.12;
	DisableFragGrenadeCheckbox->WinHeight = 0.05;
	DisableFragGrenadeCheckbox->TabOrder = 18;
	DisableFragGrenadeCheckbox->bStandardized = false;
	//DisableFragGrenadeCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoCheckBox* OpenAllWeaponSlotsCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	OpenAllWeaponSlotsCheckbox->Caption = "Open All Weapon Slots";
	//OpenAllWeaponSlotsCheckbox->OnCreateComponent=OpenAllWeaponSlotsCheckbox.InternalOnCreateComponent;
	OpenAllWeaponSlotsCheckbox->IniOption = "@Internal";
	OpenAllWeaponSlotsCheckbox->Hint = "Check this to open all weapon slots regardless as to the number of players on each team.";
	OpenAllWeaponSlotsCheckbox->WinTop = 0.8;
	OpenAllWeaponSlotsCheckbox->WinLeft = 0.5;
	OpenAllWeaponSlotsCheckbox->WinWidth = 0.3;
	OpenAllWeaponSlotsCheckbox->WinHeight = 0.05;
	OpenAllWeaponSlotsCheckbox->TabOrder = 17;
	OpenAllWeaponSlotsCheckbox->bStandardized = false;
	//OpenAllWeaponSlotsCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoCheckBox* EnableMercyRuleCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	EnableMercyRuleCheckbox->Caption = "Use ENDEX Rule";
	//EnableMercyRuleCheckbox->OnCreateComponent=EnableMercyRuleCheckbox.InternalOnCreateComponent;
	EnableMercyRuleCheckbox->IniOption = "@Internal";
	EnableMercyRuleCheckbox->Hint = "Checking this box will activate the \"End of Exercise\" rule that will end matches when one team is statistically eliminated from winning.";
	EnableMercyRuleCheckbox->WinTop = 0.8;
	EnableMercyRuleCheckbox->WinLeft = 0.05;
	EnableMercyRuleCheckbox->WinWidth = 0.3;
	EnableMercyRuleCheckbox->WinHeight = 0.05;
	EnableMercyRuleCheckbox->TabOrder = 16;
	EnableMercyRuleCheckbox->bStandardized = false;
	//EnableMercyRuleCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoCheckBox* RandomTeamAssignmentsCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	RandomTeamAssignmentsCheckbox->Caption = "Random Side Starts";
	//RandomTeamAssignmentsCheckbox->OnCreateComponent=RandomTeamAssignmentsCheckbox.InternalOnCreateComponent;
	RandomTeamAssignmentsCheckbox->IniOption = "@Internal";
	RandomTeamAssignmentsCheckbox->Hint = "Check this hav the game server randomly pick team starting sides.";
	RandomTeamAssignmentsCheckbox->WinTop = 0.74;
	RandomTeamAssignmentsCheckbox->WinLeft = 0.5;
	RandomTeamAssignmentsCheckbox->WinWidth = 0.3;
	RandomTeamAssignmentsCheckbox->WinHeight = 0.05;
	RandomTeamAssignmentsCheckbox->TabOrder = 19;
	RandomTeamAssignmentsCheckbox->bStandardized = false;
	//RandomTeamAssignmentsCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoCheckBox* AllowTeamCaptainsCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AllowTeamCaptainsCheckbox->Caption = "Allow Team Captains";
	//AllowTeamCaptainsCheckbox->OnCreateComponent=AllowTeamCaptainsCheckbox.InternalOnCreateComponent;
	AllowTeamCaptainsCheckbox->IniOption = "@Internal";
	AllowTeamCaptainsCheckbox->Hint = "Check this to allow one player on each team to be a \"Team Captain\" to manage their team.";
	AllowTeamCaptainsCheckbox->WinTop = 0.74;
	AllowTeamCaptainsCheckbox->WinLeft = 0.05;
	AllowTeamCaptainsCheckbox->WinWidth = 0.3;
	AllowTeamCaptainsCheckbox->WinHeight = 0.05;
	AllowTeamCaptainsCheckbox->TabOrder = 18;
	AllowTeamCaptainsCheckbox->bStandardized = false;
	//AllowTeamCaptainsCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoComboBox* TieBreakingRulesDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	TieBreakingRulesDropDown->CaptionWidth = 0.35;
	TieBreakingRulesDropDown->Caption = "Tie-Breaking Rules:";
	//TieBreakingRulesDropDown->OnCreateComponent=TieBreakingRulesDropDown.InternalOnCreateComponent;
	TieBreakingRulesDropDown->IniOption = "@Internal";
	TieBreakingRulesDropDown->Hint = "Select how ties should be handled.";
	TieBreakingRulesDropDown->WinTop = 0.68;
	TieBreakingRulesDropDown->WinLeft = 0.05;
	TieBreakingRulesDropDown->WinWidth = 0.55;
	TieBreakingRulesDropDown->WinHeight = 0.04;
	TieBreakingRulesDropDown->TabOrder = 15;
	TieBreakingRulesDropDown->bStandardized = false;
	//TieBreakingRulesDropDown->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoComboBox* RoundDelayTimeDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	RoundDelayTimeDropDown->CaptionWidth = 0.35;
	RoundDelayTimeDropDown->Caption = "Delay Between Rounds Time:";
	//RoundDelayTimeDropDown->OnCreateComponent=RoundDelayTimeDropDown.InternalOnCreateComponent;
	RoundDelayTimeDropDown->IniOption = "@Internal";
	RoundDelayTimeDropDown->Hint = "Select how many seconds the tournament pauses between rounds.";
	RoundDelayTimeDropDown->WinTop = 0.62;
	RoundDelayTimeDropDown->WinLeft = 0.05;
	RoundDelayTimeDropDown->WinWidth = 0.52;
	RoundDelayTimeDropDown->WinHeight = 0.04;
	RoundDelayTimeDropDown->TabOrder = 14;
	RoundDelayTimeDropDown->bStandardized = false;
	//RoundDelayTimeDropDown->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoComboBox* RequestDelayTimeDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	RequestDelayTimeDropDown->CaptionWidth = 0.6;
	RequestDelayTimeDropDown->Caption = "Captain Request Delay:";
	//RequestDelayTimeDropDown->OnCreateComponent=RequestDelayTimeDropDown.InternalOnCreateComponent;
	RequestDelayTimeDropDown->IniOption = "@Internal";
	RequestDelayTimeDropDown->Hint = "Select how long each Team Captain must wait (in seconds) between pause and side-swapping requests that aren't granted.";
	RequestDelayTimeDropDown->WinTop = 0.56;
	RequestDelayTimeDropDown->WinLeft = 0.5;
	RequestDelayTimeDropDown->WinWidth = 0.46;
	RequestDelayTimeDropDown->WinHeight = 0.04;
	RequestDelayTimeDropDown->TabOrder = 13;
	RequestDelayTimeDropDown->bStandardized = false;
	//RequestDelayTimeDropDown->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoComboBox* WarmupTimeDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	WarmupTimeDropDown->CaptionWidth = 0.62;
	WarmupTimeDropDown->Caption = "Mission Planning Time:";
	//WarmupTimeDropDown->OnCreateComponent=WarmupTimeDropDown.InternalOnCreateComponent;
	WarmupTimeDropDown->IniOption = "@Internal";
	WarmupTimeDropDown->Hint = "Select the time (in minutes) to allow players and teams to prepare for play.";
	WarmupTimeDropDown->WinTop = 0.56;
	WarmupTimeDropDown->WinLeft = 0.05;
	WarmupTimeDropDown->WinWidth = 0.43;
	WarmupTimeDropDown->WinHeight = 0.04;
	WarmupTimeDropDown->TabOrder = 12;
	WarmupTimeDropDown->bStandardized = false;
	//WarmupTimeDropDown->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoNumericEdit* SwapTimeLimitNumEditField = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	SwapTimeLimitNumEditField->CaptionWidth = 0.6;
	SwapTimeLimitNumEditField->Caption = "Swap Delay:";
	//SwapTimeLimitNumEditField->OnCreateComponent=SwapTimeLimitNumEditField.InternalOnCreateComponent;
	SwapTimeLimitNumEditField->IniOption = "@Internal";
	SwapTimeLimitNumEditField->Hint = "Enter the number of seconds Team Captains have to adjust their rosters following swapping sides.";
	SwapTimeLimitNumEditField->WinTop = 0.51;
	SwapTimeLimitNumEditField->WinLeft = 0.5;
	SwapTimeLimitNumEditField->WinWidth = 0.26;
	SwapTimeLimitNumEditField->WinHeight = 0.04;
	SwapTimeLimitNumEditField->TabOrder = 11;
	SwapTimeLimitNumEditField->bStandardized = false;
	//SwapTimeLimitNumEditField->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoComboBox* SwapLimitDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	SwapLimitDropDown->CaptionWidth = 0.58;
	SwapLimitDropDown->Caption = "Swap Sides Every:";
	//SwapLimitDropDown->OnCreateComponent=SwapLimitDropDown.InternalOnCreateComponent;
	SwapLimitDropDown->IniOption = "@Internal";
	SwapLimitDropDown->Hint = "Select the number of rounds to complete before automatically swapping sides.";
	SwapLimitDropDown->WinTop = 0.51;
	SwapLimitDropDown->WinLeft = 0.05;
	SwapLimitDropDown->WinWidth = 0.38;
	SwapLimitDropDown->WinHeight = 0.04;
	SwapLimitDropDown->TabOrder = 10;
	SwapLimitDropDown->bStandardized = false;
	//SwapLimitDropDown->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoNumericEdit* PauseTimeLimitNumEditField = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	PauseTimeLimitNumEditField->CaptionWidth = 0.75;
	PauseTimeLimitNumEditField->Caption = "Requested Pause Length:";
	//PauseTimeLimitNumEditField->OnCreateComponent=PauseTimeLimitNumEditField.InternalOnCreateComponent;
	PauseTimeLimitNumEditField->IniOption = "@Internal";
	PauseTimeLimitNumEditField->Hint = "Enter the number of seconds pause when Team Captains request \"Pause\".";
	PauseTimeLimitNumEditField->WinTop = 0.45;
	PauseTimeLimitNumEditField->WinLeft = 0.05;
	PauseTimeLimitNumEditField->WinWidth = 0.4;
	PauseTimeLimitNumEditField->WinHeight = 0.04;
	PauseTimeLimitNumEditField->TabOrder = 9;
	PauseTimeLimitNumEditField->bStandardized = false;
	//PauseTimeLimitNumEditField->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoEditBox* Team1PasswordEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	Team1PasswordEntryField->CaptionWidth = 0.6;
	Team1PasswordEntryField->Caption = "\"Away\" Team Password:";
	//Team1PasswordEntryField->OnCreateComponent=Team1PasswordEntryField.InternalOnCreateComponent;
	Team1PasswordEntryField->MenuState = EMenuState::MSAT_Disabled;
	Team1PasswordEntryField->IniOption = "@Internal";
	Team1PasswordEntryField->Hint = "Use this to enter the password required to join the visiting team for this match.";
	Team1PasswordEntryField->WinTop = 0.39;
	Team1PasswordEntryField->WinLeft = 0.5;
	Team1PasswordEntryField->WinWidth = 0.4;
	Team1PasswordEntryField->WinHeight = 0.05;
	Team1PasswordEntryField->TabOrder = 8;
	Team1PasswordEntryField->bStandardized = false;
	//Team1PasswordEntryField->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoEditBox* Team0PasswordEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	Team0PasswordEntryField->CaptionWidth = 0.6;
	Team0PasswordEntryField->Caption = "\"Home\" Team Password:";
	//Team0PasswordEntryField->OnCreateComponent=Team0PasswordEntryField.InternalOnCreateComponent;
	Team0PasswordEntryField->MenuState = EMenuState::MSAT_Disabled;
	Team0PasswordEntryField->IniOption = "@Internal";
	Team0PasswordEntryField->Hint = "Use this to enter the password to join the hosting team for this match.";
	Team0PasswordEntryField->WinTop = 0.39;
	Team0PasswordEntryField->WinLeft = 0.05;
	Team0PasswordEntryField->WinWidth = 0.4;
	Team0PasswordEntryField->WinHeight = 0.05;
	Team0PasswordEntryField->TabOrder = 7;
	Team0PasswordEntryField->bStandardized = false;
	//Team0PasswordEntryField->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoCheckBox* TeamPasswordsRequiredCheckbox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	TeamPasswordsRequiredCheckbox->CaptionWidth = 0.75;
	TeamPasswordsRequiredCheckbox->Caption = "Require Team Passwords";
	//TeamPasswordsRequiredCheckbox->OnCreateComponent=TeamPasswordsRequiredCheckbox.InternalOnCreateComponent;
	TeamPasswordsRequiredCheckbox->IniOption = "@Internal";
	TeamPasswordsRequiredCheckbox->Hint = "Check this to require team passwords in order for players to join a team.";
	TeamPasswordsRequiredCheckbox->WinTop = 0.33;
	TeamPasswordsRequiredCheckbox->WinLeft = 0.05;
	TeamPasswordsRequiredCheckbox->WinWidth = 0.35;
	TeamPasswordsRequiredCheckbox->WinHeight = 0.05;
	TeamPasswordsRequiredCheckbox->TabOrder = 6;
	TeamPasswordsRequiredCheckbox->bStandardized = false;
	//TeamPasswordsRequiredCheckbox->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoEditBox* Team1NameEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	Team1NameEntryField->CaptionWidth = 0.4;
	Team1NameEntryField->Caption = "\"Away\" Team:";
	//Team1NameEntryField->OnCreateComponent=Team1NameEntryField.InternalOnCreateComponent;
	Team1NameEntryField->IniOption = "@Internal";
	Team1NameEntryField->Hint = "Use this to enter the name of the visiting team for this match.";
	Team1NameEntryField->WinTop = 0.27;
	Team1NameEntryField->WinLeft = 0.5;
	Team1NameEntryField->WinWidth = 0.44;
	Team1NameEntryField->WinHeight = 0.05;
	Team1NameEntryField->TabOrder = 5;
	Team1NameEntryField->bStandardized = false;
	//Team1NameEntryField->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoEditBox* Team0NameEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	Team0NameEntryField->CaptionWidth = 0.4;
	Team0NameEntryField->Caption = "\"Home\" Team:";
	//Team0NameEntryField->OnCreateComponent=Team0NameEntryField.InternalOnCreateComponent;
	Team0NameEntryField->IniOption = "@Internal";
	Team0NameEntryField->Hint = "Use this to enter the name of the hosting team for this match.";
	Team0NameEntryField->WinTop = 0.27;
	Team0NameEntryField->WinLeft = 0.05;
	Team0NameEntryField->WinWidth = 0.44;
	Team0NameEntryField->WinHeight = 0.05;
	Team0NameEntryField->TabOrder = 4;
	Team0NameEntryField->bStandardized = false;
	//Team0NameEntryField->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoEditBox* TournamentNameEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	TournamentNameEntryField->CaptionWidth = 0.39;
	TournamentNameEntryField->Caption = "Tournament Name:";
	//TournamentNameEntryField->OnCreateComponent=TournamentNameEntryField.InternalOnCreateComponent;
	TournamentNameEntryField->IniOption = "@Internal";
	TournamentNameEntryField->Hint = "Use this to enter the name of the tournament (if any) match is associated with (used in reporting results).";
	TournamentNameEntryField->WinTop = 0.21;
	TournamentNameEntryField->WinLeft = 0.05;
	TournamentNameEntryField->WinWidth = 0.44;
	TournamentNameEntryField->WinHeight = 0.05;
	TournamentNameEntryField->TabOrder = 3;
	TournamentNameEntryField->bStandardized = false;
	//TournamentNameEntryField->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoEditBox* LeagueNameEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	LeagueNameEntryField->CaptionWidth = 0.39;
	LeagueNameEntryField->Caption = "League Name:";
	//LeagueNameEntryField->OnCreateComponent=LeagueNameEntryField.InternalOnCreateComponent;
	LeagueNameEntryField->IniOption = "@Internal";
	LeagueNameEntryField->Hint = "Use this to enter the name of the league match is associated with (used in reporting results).";
	LeagueNameEntryField->WinTop = 0.15;
	LeagueNameEntryField->WinLeft = 0.5;
	LeagueNameEntryField->WinWidth = 0.44;
	LeagueNameEntryField->WinHeight = 0.05;
	LeagueNameEntryField->TabOrder = 2;
	LeagueNameEntryField->bStandardized = false;
	//LeagueNameEntryField->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UmoEditBox* MatchNameEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MatchNameEntryField->CaptionWidth = 0.4;
	MatchNameEntryField->Caption = "Match Name:";
	//MatchNameEntryField->OnCreateComponent=MatchNameEntryField.InternalOnCreateComponent;
	MatchNameEntryField->IniOption = "@Internal";
	MatchNameEntryField->Hint = "Use this to enter the name of the match to be played (used in reporting results).";
	MatchNameEntryField->WinTop = 0.15;
	MatchNameEntryField->WinLeft = 0.05;
	MatchNameEntryField->WinWidth = 0.45;
	MatchNameEntryField->WinHeight = 0.05;
	MatchNameEntryField->TabOrder = 1;
	MatchNameEntryField->bStandardized = false;
	//MatchNameEntryField->OnChange=AAGameMenu_CP_Tournament.InternalOnChange;
	UGUILabel* InstructionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InstructionsLabel->TextColor = FColor(255, 255, 255, 255);
	InstructionsLabel->StyleName = "TextLabel";
	InstructionsLabel->WinTop = 0.07;
	InstructionsLabel->WinLeft = 0.05;
	InstructionsLabel->WinWidth = 0.9;
	InstructionsLabel->WinHeight = 0.05;
	mebMatchName = MatchNameEntryField;
	mebLeagueName = LeagueNameEntryField;
	mebTournamentName = TournamentNameEntryField;
	mebTournamentTeamName0 = Team0NameEntryField;
	mebTournamentTeamName1 = Team1NameEntryField;
	mebTournamentTeamPassword0 = Team0PasswordEntryField;
	mebTournamentTeamPassword1 = Team1PasswordEntryField;
	mchkbDisableFragGrenade = DisableFragGrenadeCheckbox;
	mchkbDisableSmokeGrenade = DisableSmokeGrenadeCheckbox;
	mchkbDisableThermiteGrenade = DisableThermiteGrenadeCheckbox;
	mchkbDisableFlashbangGrenade = DisableFlashbangGrenadeCheckbox;
	mchkbDisable203Reloads = Disable203ReloadsCheckbox;
	mneTournamentPauseLimit = PauseTimeLimitNumEditField;
	mcbTournamentSwapLimit = SwapLimitDropDown;
	mneTournamentSwapTime = SwapTimeLimitNumEditField;
	mcbTournamentWarmupDuration = WarmupTimeDropDown;
	guibSaveChanges = SaveChanges;
	guibSwitchServerMode = SwitchServerModes;
	mcbTournamentRequestDelayTime = RequestDelayTimeDropDown;
	mcbTournamentRoundDelayTime = RoundDelayTimeDropDown;
	mchkbMercyRule = EnableMercyRuleCheckbox;
	mchkbTournamentOpenAllWeaponClassSlots = OpenAllWeaponSlotsCheckbox;
	mchkbTournamentTeamCaptainsAllowed = AllowTeamCaptainsCheckbox;
	mchkbTournamentTeamPasswordsRequired = TeamPasswordsRequiredCheckbox;
	mchkbTournamentEnableRandomTeamAssignments = RandomTeamAssignmentsCheckbox;
	mcbTournamentTieBreakingRules = TieBreakingRulesDropDown;
	gulInstructions = InstructionsLabel;

	//sInstructions = "Use this to customize tournament options.";
	//WinHeight = 1;

}

void UAAGameMenu_CP_Tournament::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int iTimeEntry;
	local int iRounds;
	InitComponent(MyController, MyOwner);
	gulInstructions.Caption = sInstructions;
	mcbTournamentSwapLimit.MyComboBox.Edit.bReadOnly = True;
	mcbTournamentWarmupDuration.MyComboBox.Edit.bReadOnly = True;
	mcbTournamentRequestDelayTime.MyComboBox.Edit.bReadOnly = True;
	mcbTournamentRoundDelayTime.MyComboBox.Edit.bReadOnly = True;
	mcbTournamentTieBreakingRules.MyComboBox.Edit.bReadOnly = True;
	mneTournamentPauseLimit.MinValue = 0;
	mneTournamentPauseLimit.MinValue = 120;
	mneTournamentSwapTime.MinValue = 0;
	mneTournamentSwapTime.MinValue = 120;
	mcbTournamentSwapLimit.MyComboBox.List.Insert(0, "Disabled", , "0");
	for (iRounds = 1; iRounds <= 20; iRounds++)
	{
		if (iRounds > 1)
		{
			mcbTournamentSwapLimit.MyComboBox.List.Insert(iRounds, "" $ iRounds $ " rounds", , "" $ iRounds);
		}
		else
		{
			mcbTournamentSwapLimit.MyComboBox.List.Insert(iRounds, "" $ iRounds $ " round", , "" $ iRounds);
		}
	}
	mcbTournamentWarmupDuration.MyComboBox.List.Insert(0, "Disabled", , "0");
	for (iTimeEntry = 1; iTimeEntry <= 10; iTimeEntry++)
	{
		if (iTimeEntry > 1)
		{
			mcbTournamentWarmupDuration.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry $ " minutes", , "" $ iTimeEntry);
		}
		else
		{
			mcbTournamentWarmupDuration.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry $ " minute", , "" $ iTimeEntry);
		}
	}
	mcbTournamentRequestDelayTime.MyComboBox.List.Insert(0, "30 seconds", , "30");
	mcbTournamentRequestDelayTime.MyComboBox.List.Insert(1, "45 seconds", , "45");
	mcbTournamentRequestDelayTime.MyComboBox.List.Insert(2, "1 minute", , "60");
	mcbTournamentRequestDelayTime.MyComboBox.List.Insert(3, "2 minutes", , "120");
	for (iTimeEntry = 1; iTimeEntry <= 12; iTimeEntry++)
	{
		if (iTimeEntry > 1)
		{
			mcbTournamentRoundDelayTime.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry * 5 $ " seconds", , "" $ iTimeEntry * 5);
		}
		else
		{
			mcbTournamentRoundDelayTime.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry * 5 $ " seconds", , "" $ iTimeEntry * 5);
		}
	}
	mcbTournamentTieBreakingRules.MyComboBox.List.Insert(0, "Allow Ties");
	mcbTournamentTieBreakingRules.MyComboBox.List.Insert(1, "Overtime");
	mcbTournamentTieBreakingRules.MyComboBox.List.Insert(2, "By Team Scores (points)");
	if (HumanController(PlayerOwner()).TournamentIsTournament())
	{
		guibSwitchServerMode.Caption = "Activate Standard Play";
		guibSwitchServerMode.Hint = "Click here to restart the server in standard non-Tournament Mode.";
	}
	else
	{
		guibSwitchServerMode.Caption = "Activate Tournament Mode";
		guibSwitchServerMode.Hint = "Click here to restart the server in Tournament Mode (changes will be saved).";
	}
	*/
}

void UAAGameMenu_CP_Tournament::InitializeDataFields()
{
	/*
	if (aagpCommandPost == None)
	{
		Log("Warning: The CP Rules page does not have a valid Command Post page.");
		Return;
	}
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentRequestDelayTime");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentRoundDelayTime");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentSwapTime");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentSwapLimit");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentPauseLimit");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentWarmupDuration");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentMercyRule");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentOpenAllWeaponClassSlots");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTeamCaptainsAllowed");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTeamCaptainsAllowed");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTieSuddenDeath");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTieScore");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentEnableRandomTeamAssignments");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTeamPasswordsRequired");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament sMatchName");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament sTournamentName");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament sLeagueName");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament asTournamentTeamName[0]");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament asTournamentTeamName[1]");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AccessControl asTeamPasswords[0]");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AccessControl asTeamPasswords[1]");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisableFragGrenades");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisableFlashbangs");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisableSmokeGrenades");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisableThermiteGrenades");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisable203Grenades");
	*/
}

bool UAAGameMenu_CP_Tournament::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;   //FAKE   /ELiZ
}

bool UAAGameMenu_CP_Tournament::CanShowPanel()
{
	return true;
}

void UAAGameMenu_CP_Tournament::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case mchkbTournamentTeamPasswordsRequired:
				if (mchkbTournamentTeamPasswordsRequired.IsChecked())
				{
					mebTournamentTeamPassword0.EnableMe();
					mebTournamentTeamPassword1.EnableMe();
					break;
				}
				mebTournamentTeamPassword0.SetText("");
				mebTournamentTeamPassword0.DisableMe();
				mebTournamentTeamPassword1.SetText("");
				mebTournamentTeamPassword1.DisableMe();
	}
	GOTO JL009A;
		default:
			guibSaveChanges.EnableMe();
			GOTO JL009A;
		JL009A:

	*/
}

void UAAGameMenu_CP_Tournament::Timer()
{
	/*
	if (--iSwitchTimer == 0)
	{
		SetTimer(0, False);
		guibSwitchServerMode.DisableMe();
		if (HumanController(PlayerOwner()).TournamentIsTournament())
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Standard Play Mode now.");
			HumanController(PlayerOwner()).ChangeServerToStandardMode();
		}
		else
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Tournament Mode now.");
			HumanController(PlayerOwner()).ChangeServerToTournamentMode();
		}
		aagpCommandPost.fCloseRequested = True;
		HumanController(PlayerOwner()).ClientCloseMenu(True);
		Return;
	}
	if (HumanController(PlayerOwner()).TournamentIsTournament())
	{
		guibSwitchServerMode.Caption = "Cancel Switch To SPM in " $ iSwitchTimer;
		if (iSwitchTimer > 1)
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Standard Play Mode in " $ iSwitchTimer $ " seconds");
		}
		else
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Standard Play Mode in " $ iSwitchTimer $ " second");
		}
	}
	else
	{
		if (iSwitchTimer > 1)
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Tournament Mode in " $ iSwitchTimer $ " seconds");
		}
		else
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Tournament Mode in " $ iSwitchTimer $ " second");
		}
		guibSwitchServerMode.Caption = "Cancel Switch To TM in " $ iSwitchTimer;
	}
	*/
}

bool UAAGameMenu_CP_Tournament::ButtonClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case guibSwitchServerMode:
				if (iSwitchTimer > 0)
				{
					SetTimer(0, False);
					iSwitchTimer = 0;
					aagpCommandPost.guibtnClose.EnableMe();
					if (HumanController(PlayerOwner()).TournamentIsTournament())
					{
						HumanController(PlayerOwner()).ConsoleCommand("admin message Administrator has cancelled the switch to Standard Play Mode.");
						guibSwitchServerMode.Caption = "Activate Standard Play";
						guibSwitchServerMode.Hint = "Click here to restart the server in standard non-Tournament Mode.";
						break;
					}
					HumanController(PlayerOwner()).ConsoleCommand("admin message Administrator has cancelled the switch to Tournament Mode.");
					guibSwitchServerMode.Caption = "Activate Tournament Mode";
					guibSwitchServerMode.Hint = "Click here to restart the server in Tournament Mode (changes will be saved).";
				}
	}
		else
		{
		ButtonClick(guibSaveChanges);
		aagpCommandPost.guibtnClose.DisableMe();
		iSwitchTimer = 10;
		SetTimer(1, True);
		if (HumanController(PlayerOwner()).TournamentIsTournament())
		{
			guibSwitchServerMode.Caption = "Cancel Switch To SPM in 10";
		}
		else
		{
			guibSwitchServerMode.Caption = "Cancel Switch To TM in 10";
		}
		guibSwitchServerMode.Hint = "Click here to cancel the server mode change.";
			case guibSaveChanges:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament sMatchName " $ mebMatchName.GetText());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament sLeagueName " $ mebLeagueName.GetText());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament sLeagueName", mebLeagueName.GetText());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament sTournamentName " $ mebTournamentName.GetText());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament sTournamentName", mebTournamentName.GetText());
				HumanController(PlayerOwner()).ServerSetTournamentINITeamName(0, mebTournamentTeamName0.GetText());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament asTournamentTeamName[0]", mebTournamentTeamName0.GetText());
				HumanController(PlayerOwner()).ServerSetTournamentINITeamName(1, mebTournamentTeamName1.GetText());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament asTournamentTeamName[1]", mebTournamentTeamName1.GetText());
				HumanController(PlayerOwner()).ServerSetTournamentINITeamPassword(0, mebTournamentTeamPassword0.GetText());
				HumanController(PlayerOwner()).ServerSetTournamentINITeamPassword(1, mebTournamentTeamPassword1.GetText());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentRequestDelayTime " $ mcbTournamentRequestDelayTime.GetExtra());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentRequestDelayTime", mcbTournamentRequestDelayTime.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentRoundDelayTime " $ mcbTournamentRoundDelayTime.GetExtra());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentRoundDelayTime", mcbTournamentRoundDelayTime.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentSwapTime " $ mneTournamentSwapTime.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentSwapTime", mneTournamentSwapTime.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentSwapLimit " $ mcbTournamentSwapLimit.GetExtra());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentSwapLimit", mcbTournamentSwapLimit.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentWarmupDuration " $ mcbTournamentWarmupDuration.GetExtra());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentWarmupDuration", mcbTournamentWarmupDuration.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentPauseLimit " $ mneTournamentPauseLimit.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentPauseLimit", mneTournamentPauseLimit.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentMercyRule " $ mchkbMercyRule.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentMercyRule", mchkbMercyRule.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentOpenAllWeaponClassSlots " $ mchkbTournamentOpenAllWeaponClassSlots.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentOpenAllWeaponClassSlots", mchkbTournamentOpenAllWeaponClassSlots.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTeamCaptainsAllowed " $ mchkbTournamentTeamCaptainsAllowed.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTeamCaptainsAllowed", mchkbTournamentTeamCaptainsAllowed.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTeamPasswordsRequired " $ mchkbTournamentTeamPasswordsRequired.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTeamPasswordsRequired", mchkbTournamentTeamPasswordsRequired.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentEnableRandomTeamAssignments " $ mchkbTournamentEnableRandomTeamAssignments.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentEnableRandomTeamAssignments", mchkbTournamentEnableRandomTeamAssignments.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisableFragGrenades " $ mchkbDisableFragGrenade.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisableFlashbangs " $ mchkbDisableFlashbangGrenade.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisableSmokeGrenades " $ mchkbDisableSmokeGrenade.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisableThermiteGrenades " $ mchkbDisableThermiteGrenade.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisable203Grenades " $ mchkbDisable203Reloads.GetComponentValue());
				Switch(mcbTournamentTieBreakingRules.GetIndex())
				{
			case 0:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieScore false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieSuddenDeath false");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieScore", "false");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieSuddenDeath", "false");
				break;
			case 1:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieScore false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieSuddenDeath true");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieScore", "false");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieSuddenDeath", "true");
				break;
			case 2:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieScore true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieSuddenDeath false");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieScore", "true");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieSuddenDeath", "false");
				break;
			default:
				}
				guibSaveChanges.DisableMe();
			default:
		}
	*/
	return true;
}

void UAAGameMenu_CP_Tournament::NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3)
{
	/*
	if (sParam1 ~= "INIEntry")
	{
		if (sParam2 ~= "AGP_GameTournament bTournamentMercyRule")
		{
			mchkbMercyRule.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentOpenAllWeaponClassSlots")
		{
			mchkbTournamentOpenAllWeaponClassSlots.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentTeamCaptainsAllowed")
		{
			mchkbTournamentTeamCaptainsAllowed.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentTeamPasswordsRequired")
		{
			mchkbTournamentTeamPasswordsRequired.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbTournamentTeamPasswordsRequired);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentEnableRandomTeamAssignments")
		{
			mchkbTournamentEnableRandomTeamAssignments.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentTieSuddenDeath")
		{
			bTournamentTieSuddenDeath = sParam3;
			UpdateTieBreakingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentTieScore")
		{
			bTournamentTieScore = sParam3;
			UpdateTieBreakingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisableFragGrenades")
		{
			mchkbDisableFragGrenade.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisableFragGrenade);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisableFlashbangs")
		{
			mchkbDisableFlashbangGrenade.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisableFlashbangGrenade);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisableSmokeGrenades")
		{
			mchkbDisableSmokeGrenade.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisableSmokeGrenade);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisableThermiteGrenades")
		{
			mchkbDisableThermiteGrenade.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisableThermiteGrenade);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisable203Grenades")
		{
			mchkbDisable203Reloads.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisable203Reloads);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentPauseLimit")
		{
			mneTournamentPauseLimit.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentRoundDelayTime")
		{
			if (sParam3 > 1)
			{
				mcbTournamentRoundDelayTime.SetText(sParam3 $ " seconds");
			}
			else
			{
				mcbTournamentRoundDelayTime.SetText(sParam3 $ " second");
			}
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentSwapTime")
		{
			mneTournamentSwapTime.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentSwapLimit")
		{
			if (sParam3 > 0)
			{
				if (sParam3 > 1)
				{
					mcbTournamentSwapLimit.SetText(sParam3 $ " rounds", True);
				}
				else
				{
					mcbTournamentSwapLimit.SetText(sParam3 $ " round", True);
				}
			}
			else
			{
				mcbTournamentSwapLimit.SetText("Disabled", True);
			}
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentWarmupDuration")
		{
			if (sParam3 > 0)
			{
				if (sParam3 > 1)
				{
					mcbTournamentWarmupDuration.SetText(sParam3 $ " minutes", True);
				}
				else
				{
					mcbTournamentWarmupDuration.SetText(sParam3 $ " minute", True);
				}
			}
			else
			{
				mcbTournamentWarmupDuration.SetText("Disabled", True);
			}
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament sMatchName")
		{
			mebMatchName.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament sLeagueName")
		{
			mebLeagueName.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament sTournamentName")
		{
			mebTournamentName.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament asTournamentTeamName[0]")
		{
			mebTournamentTeamName0.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament asTournamentTeamName[1]")
		{
			mebTournamentTeamName1.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AccessControl asTeamPasswords[0]")
		{
			mebTournamentTeamPassword0.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AccessControl asTeamPasswords[1]")
		{
			mebTournamentTeamPassword1.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
	}
	*/
}

void UAAGameMenu_CP_Tournament::UpdateTieBreakingRulesField()
{
	/*
	if (!bTournamentTieScore && !bTournamentTieSuddenDeath)
	{
		mcbTournamentTieBreakingRules.MyComboBox.List.SetIndex(0);
		Return;
	}
	if (!bTournamentTieScore && bTournamentTieSuddenDeath)
	{
		mcbTournamentTieBreakingRules.MyComboBox.List.SetIndex(1);
		Return;
	}
	if (bTournamentTieScore && !bTournamentTieSuddenDeath)
	{
		mcbTournamentTieBreakingRules.MyComboBox.List.SetIndex(2);
		Return;
	}
	mcbTournamentTieBreakingRules.MyComboBox.List.SetIndex(1);
	*/
}
