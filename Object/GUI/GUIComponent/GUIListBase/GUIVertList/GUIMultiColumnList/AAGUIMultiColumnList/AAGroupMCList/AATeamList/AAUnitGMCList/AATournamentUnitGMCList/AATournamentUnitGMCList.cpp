// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAUnitGMCList/AATournamentUnitGMCList/AATournamentUnitGMCList.h"

UAATournamentUnitGMCList::UAATournamentUnitGMCList()
{
	MinVisibleTeamEntries = 12;
}

void UAATournamentUnitGMCList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
}

void UAATournamentUnitGMCList::DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	/*
	local int j;
	local GUI.eMenuState PlayerState;
	local AAA2_PlayerState* PRI;
	local AAA2_PlayerState* PlayerListItem;
	local AGP.AGP_PlayerStart PS;
	local Object.Color OldColors;
	local Object.Color MyColor;
	local bool bSpecialColor;
	local int CurrentGroup;
	local int CurrentPosition;
	bSpecialColor = False;
	CurrentGroup = GetGroup(i);
	CurrentPosition = GetPositionInGroup(CurrentGroup, i);
	PRI = PlayerOwner().PlayerReplicationInfo;
	PlayerListItem = Team.GetNoRequest(0);
	PS = Team.GetPlayerStart(CurrentGroup, CurrentPosition);
	if (PlayerItem != None)
	{
		PlayerState = GetPlayerState(PlayerItem);
		if (PRI != None && PlayerItem != None && PlayerItem == PRI)
		{
			if (PRI.isDead())
			{
				MyColor.R = 149;
				MyColor.G = 135;
				MyColor.B = 83;
				MyColor.A = 255;
				bSpecialColor = True;
			}
			else
			{
				MyColor.R = 240;
				MyColor.G = 196;
				MyColor.B = 27;
				MyColor.A = 255;
				bSpecialColor = True;
			}
		}
		else
		{
			if (!PRI.isDead())
			{
				MyColor.R = 166;
				MyColor.G = 202;
				MyColor.B = 156;
				MyColor.A = 255;
				bSpecialColor = True;
			}
		}
		if (HumanController(PlayerOwner()) != None && HumanController(PlayerOwner()).bTournamentServer)
		{
			if (PlayerItem.bAdmin)
			{
				MyColor.R = 255;
				MyColor.G = 0;
				MyColor.B = 0;
				MyColor.A = 255;
				bSpecialColor = True;
			}
			else
			{
				if (PlayerItem.bTournamentTeamCaptain)
				{
					if (PRI.isDead())
					{
						MyColor.R = 56;
						MyColor.G = 56;
						MyColor.B = 99;
						MyColor.A = 255;
						bSpecialColor = True;
					}
					else
					{
						MyColor.R = 82;
						MyColor.G = 82;
						MyColor.B = 159;
						MyColor.A = 255;
						bSpecialColor = True;
					}
				}
			}
		}
		if (bSpecialColor)
		{
			for (j = 0; j < 5; j++)
			{
				OldColors[j] = Style.FontColors[j];
				Style.FontColors[j] = MyColor;
			}
		}
		if (PlayerItem != None)
		{
			Style.DrawText(Canvas, MenuState, CellLeft, Y, CellWidth, ItemHeight, 0, PlayerItem.PlayerName, FontScale);
		}
		if (bSpecialColor)
		{
			for (j = 0; j < 5; j++)
			{
				Style.FontColors[j] = OldColors[j];
			}
		}
	}
	*/
}

void UAATournamentUnitGMCList::DrawButtons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	/*
	local AAA2_PlayerState* PRI;
	local AAA2_PlayerState* CurrentPRI;
	local AAA2_PlayerState* PlayerListItem;
	local AGP.AGP_PlayerStart PS;
	local int CurrentGroup;
	local int CurrentPosition;
	if (i < 0 || i > Buttons.Length || Buttons.Length <= 0 || IsSeparator(i))
	{
		Return;
	}
	CurrentGroup = GetGroup(i);
	CurrentPosition = GetPositionInGroup(CurrentGroup, i);
	PRI = PlayerOwner().PlayerReplicationInfo;
	PlayerListItem = Team.GetNoRequest(0);
	PS = Team.GetPlayerStart(CurrentGroup, CurrentPosition);
	if (PS != None)
	{
		if (HumanController(PlayerOwner()) != None && HumanController(PlayerOwner()).bTournamentServer)
		{
			CurrentPRI = None;
			if (!IsSlotEnabled(i))
			{
				DisableComponent(Buttons[i]);
			}
			else
			{
				if (!PlayerOwner().PlayerReplicationInfo.bAdmin && !PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain && HumanController(PlayerOwner()).TournamentIsTeamRosterLocked(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex))
				{
					DisableComponent(Buttons[i]);
				}
				else
				{
					EnableComponent(Buttons[i]);
				}
			}
			if (PlayerOwner().PlayerReplicationInfo.bAdmin)
			{
				if (PlayerItem != None)
				{
					CurrentPRI = PlayerItem;
				}
				else
				{
					if (PlayerListItem != None)
					{
						CurrentPRI = PlayerListItem;
					}
				}
			}
			else
			{
				if (PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain)
				{
					if (PlayerItem != None)
					{
						CurrentPRI = PlayerItem;
					}
					else
					{
						if (PlayerListItem != None)
						{
							CurrentPRI = PlayerListItem;
						}
					}
				}
				else
				{
					if (PRI != None && PlayerListItem != None && PRI == PlayerListItem)
					{
						CurrentPRI = PRI;
					}
				}
			}
			if (PlayerItem != None)
			{
				Buttons[i].Caption = RemoveCaption;
				Buttons[i].Hint = RemoveHint;
			}
			else
			{
				Buttons[i].Caption = SelectCaption;
				Buttons[i].Hint = SelectHint;
			}
			if (CurrentPRI != None)
			{
				if (PS != None && !IsQualified(PS, CurrentPRI))
			}
		}
	}
	{
		Buttons[i].WinLeft = Bounds[2] - Buttons[i].WinWidth - 4;
		Buttons[i].WinTop = Y;
		Buttons[i].bVisible = True;
	}
	*/
}

bool UAATournamentUnitGMCList::ButtonClick(UGUIComponent* Sender)
{
	/*
	local int i;
	local int RealIndex;
	local AAA2_PlayerState* PRI;
	local AGP.HumanController HC;
	local int CurrentGroup;
	local int CurrentPosition;
	for (i = 0; i < Buttons.Length; i++)
	{
		if (Buttons[i] != None)
		{
			if (Sender == Buttons[i])
			{
				CurrentGroup = GetGroup(i);
				CurrentPosition = GetPositionInGroup(CurrentGroup, i);
				HC = HumanController(PlayerOwner());
				if (HC != None && HC.bTournamentServer)
				{
					if (Team != None && HC.PlayerReplicationInfo != None && HC.PlayerReplicationInfo.Team != None && Team.TeamIndex == HC.PlayerReplicationInfo.Team.TeamIndex || HC.PlayerReplicationInfo.bAdmin)
					{
						if (Buttons[i].Caption == RemoveCaption)
						{
							Buttons[i].Caption = SelectCaption;
							Buttons[i].Hint = SelectHint;
							RealIndex = Team.GetRealIndex(CurrentGroup, CurrentPosition);
							PRI = Team.GetPlayerRequest(CurrentGroup, CurrentPosition);
							if (PRI != None)
							{
								if (PlayerOwner().PlayerReplicationInfo.bAdmin || PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain || !HumanController(PlayerOwner()).TournamentIsTeamRosterLocked(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex) && PRI != None && PRI == PlayerOwner().PlayerReplicationInfo)
								{
									PlayerOwner().PlayerReplicationInfo.RemovePlayerRequest(PRI);
								}
							}
						}
						else
						{
							if (Buttons[i].MenuState != 4)
							{
								Buttons[i].Caption = RemoveCaption;
								Buttons[i].Hint = RemoveHint;
								PRI = Team.GetNoRequest(0);
								if (PRI != None)
								{
									if (PlayerOwner().PlayerReplicationInfo.bAdmin || PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain || !HumanController(PlayerOwner()).TournamentIsTeamRosterLocked(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex) && PRI != None && PRI == PlayerOwner().PlayerReplicationInfo)
									{
										HC.TournamentAssignClass(PRI.PlayerName, CurrentGroup, CurrentPosition);
									}
								}
							}
						}
					}
				}
				Return True;
			}
		}
	}
	*/
	return false;
}

bool UAATournamentUnitGMCList::InternalOnClick(UGUIComponent* Sender)
{
	bool bReturn=false;
	/*
	bReturn = InternalOnClick(Sender);
	if (IsSeparator(Index))
	{
		Return bReturn;
	}
	if (Index >= 0 && Buttons[Index] != None)
	{
		Buttons[Index].OnClick(Buttons[Index]);
	}
	*/
	return bReturn;
}

bool UAATournamentUnitGMCList::CanSelect()
{
	return true;
}
