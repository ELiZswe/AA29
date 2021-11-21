// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_BanlistManagement/AAGameMenu_CP_BanlistManagement.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"

UAAGameMenu_CP_BanlistManagement::UAAGameMenu_CP_BanlistManagement()
{
	UGUIButton* BanButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BanButton->Caption = "Add Ban";
	BanButton->MenuState = EMenuState::MSAT_Disabled;
	BanButton->StyleName = "SquareMenuButton";
	BanButton->Hint = "Click here to add the ban using the options you have selected.";
	BanButton->WinTop = 0.32;
	BanButton->WinLeft = 0.89;
	BanButton->WinWidth = 0.1;
	BanButton->WinHeight = 0.053476;
	//BanButton->OnClick=AAGameMenu_CP_BanlistManagement.ButtonClick;
	//BanButton->OnKeyEvent=BanButton.InternalOnKeyEvent;
	UmoComboBox* BanTypeDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	BanTypeDropDown->bReadOnly = true;
	BanTypeDropDown->CaptionWidth = 0.22;
	BanTypeDropDown->Caption = "Ban Type:";
	//BanTypeDropDown->OnCreateComponent=BanTypeDropDown.InternalOnCreateComponent;
	BanTypeDropDown->MenuState = EMenuState::MSAT_Disabled;
	BanTypeDropDown->IniOption = "@Internal";
	BanTypeDropDown->StyleName = "STY_AAComboListBox";
	BanTypeDropDown->Hint = "Select the type of ban.  Banning by name on a PB Enabled server will use a PBGUID ban.";
	BanTypeDropDown->WinTop = 0.38;
	BanTypeDropDown->WinLeft = 0.5;
	BanTypeDropDown->WinWidth = 0.38;
	BanTypeDropDown->WinHeight = 0.05;
	BanTypeDropDown->TabOrder = 2;
	BanTypeDropDown->bStandardized = false;
	//BanTypeDropDown->OnChange=AAGameMenu_CP_BanlistManagement.InternalOnChange;
	UmoComboBox* BanLengthDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	BanLengthDropDown->bReadOnly = true;
	BanLengthDropDown->CaptionWidth = 0.22;
	BanLengthDropDown->Caption = "Ban Length:";
	//BanLengthDropDown->OnCreateComponent=BanLengthDropDown.InternalOnCreateComponent;
	BanLengthDropDown->MenuState = EMenuState::MSAT_Disabled;
	BanLengthDropDown->IniOption = "@Internal";
	BanLengthDropDown->StyleName = "STY_AAComboListBox";
	BanLengthDropDown->Hint = "Select the length of time for banning.";
	BanLengthDropDown->WinTop = 0.32;
	BanLengthDropDown->WinLeft = 0.5;
	BanLengthDropDown->WinWidth = 0.38;
	BanLengthDropDown->WinHeight = 0.05;
	BanLengthDropDown->TabOrder = 2;
	BanLengthDropDown->bStandardized = false;
	//BanLengthDropDown->OnChange=AAGameMenu_CP_BanlistManagement.InternalOnChange;
	UGUIButton* UnBanButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	UnBanButton->Caption = "Remove Ban";
	UnBanButton->MenuState = EMenuState::MSAT_Disabled;
	UnBanButton->StyleName = "SquareMenuButton";
	UnBanButton->Hint = "Click here to remove the selected ban entry.";
	UnBanButton->WinTop = 0.86;
	UnBanButton->WinLeft = 0.17;
	UnBanButton->WinWidth = 0.15;
	UnBanButton->WinHeight = 0.053476;
	//UnBanButton->OnClick=AAGameMenu_CP_BanlistManagement.ButtonClick;
	//UnBanButton->OnKeyEvent=UnBanButton.InternalOnKeyEvent;
	UGUIListBox* BanListBox = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	BanListBox->bVisibleWhenEmpty = true;
	//BanListBox->OnCreateComponent=BanListBox.InternalOnCreateComponent;
	BanListBox->StyleName = "ServerBrowserGrid";
	BanListBox->WinTop = 0.6;
	BanListBox->WinLeft = 0.05;
	BanListBox->WinWidth = 0.65;
	BanListBox->WinHeight = 0.25;
	BanListBox->bAcceptsInput = false;
	BanListBox->bNeverFocus = true;
	//BanListBox->OnClick=AAGameMenu_CP_BanlistManagement.OnPlayerListClick;
	UGUIListBox* PlayersListBox = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	PlayersListBox->bVisibleWhenEmpty = true;
	PlayersListBox->bSorted = true;
	//PlayersListBox->OnCreateComponent=PlayersListBox.InternalOnCreateComponent;
	PlayersListBox->StyleName = "ServerBrowserGrid";
	PlayersListBox->Hint = "Left click on a player to manage bans for that player.";
	PlayersListBox->WinTop = 0.2;
	PlayersListBox->WinLeft = 0.05;
	PlayersListBox->WinWidth = 0.4;
	PlayersListBox->WinHeight = 0.3;
	PlayersListBox->bAcceptsInput = false;
	PlayersListBox->bNeverFocus = true;
	//PlayersListBox->OnClick=AAGameMenu_CP_BanlistManagement.OnPlayerListClick;
	//PlayersListBox->OnChange=AAGameMenu_CP_BanlistManagement.InternalOnChange;
	UGUILabel* InstructionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InstructionsLabel->TextColor = FColor(255, 255, 255, 255);
	InstructionsLabel->bMultiLine = true;
	InstructionsLabel->StyleName = "TextLabel";
	InstructionsLabel->WinTop = 0.07;
	InstructionsLabel->WinLeft = 0.05;
	InstructionsLabel->WinWidth = 0.9;
	InstructionsLabel->WinHeight = 0.1;
	UGUILabel* PlayersListTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayersListTitle->Caption = "Active Players";
	PlayersListTitle->TextAlign = ETextAlign::TXTA_Center;
	PlayersListTitle->TextColor = FColor(255, 255, 255, 255);
	PlayersListTitle->StyleName = "TextLabel";
	PlayersListTitle->WinTop = 0.15;
	PlayersListTitle->WinLeft = 0.05;
	PlayersListTitle->WinWidth = 0.4;
	PlayersListTitle->WinHeight = 0.05;
	UGUILabel* BanListTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	BanListTitle->Caption = "Current Bans";
	BanListTitle->TextAlign = ETextAlign::TXTA_Center;
	BanListTitle->TextColor = FColor(255, 255, 255, 255);
	BanListTitle->StyleName = "TextLabel";
	BanListTitle->WinTop = 0.55;
	BanListTitle->WinLeft = 0.05;
	BanListTitle->WinWidth = 0.4;
	BanListTitle->WinHeight = 0.05;
	UGUILabel* BanDetailsTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	BanDetailsTitle->Caption = "Ban Options";
	BanDetailsTitle->TextAlign = ETextAlign::TXTA_Center;
	BanDetailsTitle->TextColor = FColor(255, 255, 255, 255);
	BanDetailsTitle->StyleName = "TextLabel";
	BanDetailsTitle->WinTop = 0.2;
	BanDetailsTitle->WinLeft = 0.5;
	BanDetailsTitle->WinWidth = 0.5;
	BanDetailsTitle->WinHeight = 0.05;
	UGUILabel* PlayerDetailsName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayerDetailsName->Caption = "Name: ";
	PlayerDetailsName->TextColor = FColor(255, 255, 255, 255);
	PlayerDetailsName->MenuState = EMenuState::MSAT_Disabled;
	PlayerDetailsName->StyleName = "TextLabel";
	PlayerDetailsName->WinTop = 0.26;
	PlayerDetailsName->WinLeft = 0.5;
	PlayerDetailsName->WinWidth = 0.5;
	PlayerDetailsName->WinHeight = 0.05;
	guilInstructions = InstructionsLabel;
	guilPlayerListTitle = PlayersListTitle;
	guilbPlayersList = PlayersListBox;
	guilBanListTitle = BanListTitle;
	guilbBanList = BanListBox;
	mcbBanLength = BanLengthDropDown;
	mcbBanType = BanTypeDropDown;
	guibUnbanPlayer = UnBanButton;
	guibBan = BanButton;
	guilPlayerDetailsTitle = BanDetailsTitle;
	guilPlayerDetailsName = PlayerDetailsName;

	sInstructions = "Use this to manage your list of banned players.";
	sPlayerListBoxTitle = "Players";
	sBanDetailsTitle = "Ban Options";
	WinHeight = 1;
	bTabStop = true;
}

void UAAGameMenu_CP_BanlistManagement::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	guilInstructions.Caption = sInstructions;
	guilPlayerListTitle.Caption = sPlayerListBoxTitle;
	guilbPlayersList.List.TextAlign = 0;
	guilbBanList.List.TextAlign = 0;
	mcbBanLength.addItem("5 minutes", , "5m");
	mcbBanLength.addItem("30 minutes", , "30m");
	mcbBanLength.addItem("1 hour", , "1h");
	mcbBanLength.addItem("1 day", , "1d");
	mcbBanLength.addItem("3 days", , "3d");
	mcbBanLength.addItem("1 week", , "1w");
	mcbBanLength.addItem("1 month", , "4w");
	mcbBanLength.addItem("Permanently", , "0");
	mcbBanType.addItem("Player (or PBGUID)", , "NAME");
	mcbBanType.addItem("IP Address", , "IP");
	mcbBanType.addItem("MAC Address", , "MAC");
	RefreshPlayerList();
	iCurrentlySelectedPlayerID = 0;
	OnPlayerListClick(guilbPlayersList);
	SetTimer(2, True);
	*/
}

void UAAGameMenu_CP_BanlistManagement::InitializeDataFields()
{
	/*
	guilbBanList.List.Clear();
	if (aagpCommandPost != None)
	{
		HumanController(PlayerOwner()).RequestBanList(aagpCommandPost);
	}
	*/
}

void UAAGameMenu_CP_BanlistManagement::OnPlayerListDrawItem(UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending)
{
	//DrawListItem(guilbPlayersList, Canvas, iItemIndex, fpX, fpY, fpWidth, fpHeight, bSelected, bPending);
}

void UAAGameMenu_CP_BanlistManagement::OnSpectatorListDrawItem(UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending)
{
	//DrawListItem(guilbBanList, Canvas, iItemIndex, fpX, fpY, fpWidth, fpHeight, False, bPending);
}

void UAAGameMenu_CP_BanlistManagement::DrawListItem(UGUIListBox* guilb, UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending)
{
	/*
	local FString sItemText;
	local XInterface.GUIStyles guistyle;
	sItemText = guilb.List.getItemAtIndex(iItemIndex);
	if (bSelected && guilb.List.SelectedStyle != None)
	{
		guistyle.Draw(Canvas, guilb.List.MenuState, fpX, fpY, fpWidth, fpHeight);
	}
	else
	{
		guistyle = guilb.List.Style;
	}
	guistyle.DrawText(Canvas, 0, fpX, fpY, fpWidth, fpHeight, 0, sItemText, guilb.FontScale);
	*/
}

void UAAGameMenu_CP_BanlistManagement::RefreshPlayerList()
{
	/*
	local FString sPlayerEntry;
	local FString sTeamName;
	local GameReplicationInfo GRI;
	local int32 iPlayerIndex;
	local int32 iFoundPlayers;
	local bool bRefillList;
	bRefillList = False;
	GRI = PlayerOwner().GameReplicationInfo;
	for (iPlayerIndex = 0; iPlayerIndex < GRI.PRIArray.Length; iPlayerIndex++)
	{
		if (GRI.PRIArray[iPlayerIndex] != None)
		{
			if (GRI.PRIArray[iPlayerIndex].bOnlySpectator == False && GRI.PRIArray[iPlayerIndex].PlayerName != "Recruit")
			{
				iFoundPlayers++;
			}
		}
	}
	if (iFoundPlayers != guilbPlayersList.List.Elements.Length)
	{
		bRefillList = True;
	}
	else
	{
		iPlayerIndex = 0;
		if (iPlayerIndex < GRI.PRIArray.Length)
		{
			if (GRI.PRIArray[iPlayerIndex] != None && GRI.PRIArray[iPlayerIndex].bOnlySpectator == False && GRI.PRIArray[iPlayerIndex].PlayerName != "Recruit")
			{
				if (guilbPlayersList.List.FindExtra(GRI.PRIArray[iPlayerIndex].PlayerID) == -1)
				{
					bRefillList = True;
				}
			}
			else
			{
				iPlayerIndex++;
			}
		}
	}
	if (!bRefillList)
	{
		Return;
	}
	guilbPlayersList.List.Clear();
	for (iPlayerIndex = 0; iPlayerIndex < GRI.PRIArray.Length; iPlayerIndex++)
	{
		if (GRI.PRIArray[iPlayerIndex] != None)
		{
			if (GRI.PRIArray[iPlayerIndex].bOnlySpectator == False && GRI.PRIArray[iPlayerIndex].PlayerName != "Recruit")
			{
				if (GRI.PRIArray[iPlayerIndex].Team.TeamIndex == 0)
				{
					sTeamName = "Assault";
				}
				else
				{
					if (GRI.PRIArray[iPlayerIndex].Team.TeamIndex == 1)
					{
						sTeamName = "Defense";
					}
					else
					{
						sTeamName = "Unassigned";
					}
				}
				sPlayerEntry = GRI.PRIArray[iPlayerIndex].PlayerName $ " (" $ sTeamName $ ")";
				if (GRI.PRIArray[iPlayerIndex].bAdmin)
				{
					sPlayerEntry = sPlayerEntry $ " (Player Admin)";
				}
				guilbPlayersList.List.Add(sPlayerEntry, , GRI.PRIArray[iPlayerIndex].PlayerID);
			}
		}
	}
	*/
}

void UAAGameMenu_CP_BanlistManagement::ComparePlayerListItems(FGUIListElem* ElemA, FGUIListElem* ElemB)
{
	//Return StrCmp(ElemA.Item, ElemB.Item, , False);
}

void UAAGameMenu_CP_BanlistManagement::Timer()
{
	/*
	RefreshPlayerList();
	if (FindPRIFromID(iCurrentlySelectedPlayerID) != None)
	{
		guilbPlayersList.List.SetIndex(guilbPlayersList.List.FindExtra(iCurrentlySelectedPlayerID));
	}
	else
	{
		OnPlayerListClick(guilbPlayersList);
	}
	*/
}

void UAAGameMenu_CP_BanlistManagement::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
}

bool UAAGameMenu_CP_BanlistManagement::CanShowPanel()
{
	return true;
}

bool UAAGameMenu_CP_BanlistManagement::ButtonClick(UGUIComponent* Sender)
{
	/*
	local FString sCmd;
	Switch(Sender)
	{
			case guibBan:
				if (Len(guilbPlayersList.List.GetExtra()) > 0 && FindPRIFromID(guilbPlayersList.List.GetExtra()) != None)
				{
					iCurrentlySelectedPlayerID = guilbPlayersList.List.GetExtra();
					sCmd = "admin ban " $ FindPRIFromID(guilbPlayersList.List.GetExtra()).PlayerName $ " " $ mcbBanLength.GetExtra() $ " " $ mcbBanType.GetExtra();
					HumanController(PlayerOwner()).ConsoleCommand(sCmd);
					InitializeDataFields();
				}
				guibBan.DisableMe();
				break;
			case guibUnbanPlayer:
				HumanController(PlayerOwner()).ConsoleCommand("admin unban " $ guilbBanList.List.GetExtra());
				guilbBanList.List.Remove(guilbBanList.List.Index);
				guibUnbanPlayer.DisableMe();
				break;
			default:
	}
	*/
	return true;
}

void UAAGameMenu_CP_BanlistManagement::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case mcbBanLength:
				guibBan.EnableMe();
				Return;
			default:
	}
	*/
}

bool UAAGameMenu_CP_BanlistManagement::OnPlayerListClick(UGUIComponent* Sender)
{
	/*
	local PlayerReplicationInfo priSelected;
	if (Sender == guilbPlayersList)
	{
		if (Len(guilbPlayersList.List.GetExtra()) > 0 && FindPRIFromID(guilbPlayersList.List.GetExtra()) != None)
		{
			iCurrentlySelectedPlayerID = guilbPlayersList.List.GetExtra();
			priSelected = FindPRIFromID(iCurrentlySelectedPlayerID);
			guilPlayerDetailsName.Caption = "Name: " $ priSelected.PlayerName;
			guilPlayerDetailsName.EnableMe();
			mcbBanLength.EnableMe();
			mcbBanType.EnableMe();
			guibBan.EnableMe();
			guilPlayerDetailsTitle.EnableMe();
		}
		else
		{
			guilPlayerDetailsName.DisableMe();
			mcbBanLength.DisableMe();
			mcbBanType.DisableMe();
			guibBan.DisableMe();
			guilPlayerDetailsTitle.DisableMe();
		}
	}
	if (Sender == guilbBanList)
	{
		guilbBanList.List.Hint = "Ban information: " $ guilbBanList.List.Get();
		guibUnbanPlayer.EnableMe();
	}
	*/
	return true;
}

void UAAGameMenu_CP_BanlistManagement::NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3)
{
	/*
	if (sParam1 ~= "BanListEntry")
	{
		guilbBanList.List.Add(sParam2 @ sParam3, , "" $ guilbBanList.List.Elements.Length + 1);
	}
	*/
}

void UAAGameMenu_CP_BanlistManagement::FindPRIFromID(int32 iPlayerID)
{
	/*
	local GameReplicationInfo GRI;
	local int32 iPlayerIndex;
	GRI = PlayerOwner().GameReplicationInfo;
	if (GRI == None)
	{
		Return None;
	}
	for (iPlayerIndex = 0; iPlayerIndex < GRI.PRIArray.Length; iPlayerIndex++)
	{
		if (GRI.PRIArray[iPlayerIndex] != None && GRI.PRIArray[iPlayerIndex].PlayerID == iPlayerID)
		{
			Return GRI.PRIArray[iPlayerIndex];
		}
	}
	Return None;
	*/
}