// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_BanlistManagement/AAGameMenu_CP_BanlistManagement.h"

UAAGameMenu_CP_BanlistManagement::UAAGameMenu_CP_BanlistManagement()
{
	//guilInstructions = GUILabel'AGP_Interface.AAGameMenu_CP_BanlistManagement.InstructionsLabel';
	//guilPlayerListTitle = GUILabel'AGP_Interface.AAGameMenu_CP_BanlistManagement.PlayersListTitle';
	//guilbPlayersList = GUIListBox'AGP_Interface.AAGameMenu_CP_BanlistManagement.PlayersListBox';
	//guilBanListTitle = GUILabel'AGP_Interface.AAGameMenu_CP_BanlistManagement.BanListTitle';
	//guilbBanList = GUIListBox'AGP_Interface.AAGameMenu_CP_BanlistManagement.BanListBox';
	//mcbBanLength = moComboBox'AGP_Interface.AAGameMenu_CP_BanlistManagement.BanLengthDropDown';
	//mcbBanType = moComboBox'AGP_Interface.AAGameMenu_CP_BanlistManagement.BanTypeDropDown';
	//guibUnbanPlayer = GUIButton'AGP_Interface.AAGameMenu_CP_BanlistManagement.UnBanButton';
	//guibBan = GUIButton'AGP_Interface.AAGameMenu_CP_BanlistManagement.BanButton';
	//guilPlayerDetailsTitle = GUILabel'AGP_Interface.AAGameMenu_CP_BanlistManagement.BanDetailsTitle';
	//guilPlayerDetailsName = GUILabel'AGP_Interface.AAGameMenu_CP_BanlistManagement.PlayerDetailsName';
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