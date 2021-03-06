// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAUnitGMCList/AATournamentUnitGMCList/AATournamentUnitGMCList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "Engine/Canvas.h"

UAATournamentUnitGMCList::UAATournamentUnitGMCList()
{
	MinVisibleTeamEntries = 12;
}

void UAATournamentUnitGMCList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
}

void UAATournamentUnitGMCList::DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	int32 j = 0;
	EMenuState PlayerState = EMenuState::MSAT_Blurry;
	AAA2_PlayerState* PRI = nullptr;
	AAA2_PlayerState* PlayerListItem = nullptr;
	AAGP_PlayerStart* PS = nullptr;
	FColor OldColors = FColor(0,0,0,0);
	FColor MyColor = FColor(0,0,0,0);
	bool bSpecialColor = false;
	int32 CurrentGroup = 0;
	int32 CurrentPosition = 0;
	bSpecialColor = false;
	CurrentGroup = GetGroup(i);
	CurrentPosition = GetPositionInGroup(CurrentGroup, i);
	/*
	PRI = PlayerOwner().PlayerReplicationInfo;
	PlayerListItem = Team.GetNoRequest(0);
	PS = Team.GetPlayerStart(CurrentGroup, CurrentPosition);
	if (PlayerItem != nullptr)
	{
		PlayerState = GetPlayerState(PlayerItem);
		if (PRI != nullptr && PlayerItem != nullptr && PlayerItem == PRI)
		{
			if (PRI.isDead())
			{
				MyColor.R = 149;
				MyColor.G = 135;
				MyColor.B = 83;
				MyColor.A = 255;
				bSpecialColor = true;
			}
			else
			{
				MyColor.R = 240;
				MyColor.G = 196;
				MyColor.B = 27;
				MyColor.A = 255;
				bSpecialColor = true;
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
				bSpecialColor = true;
			}
		}
		if (Cast<AHumanController>(PlayerOwner()) != nullptr && Cast<AHumanController>(PlayerOwner())->bTournamentServer)
		{
			if (PlayerItem.bAdmin)
			{
				MyColor.R = 255;
				MyColor.G = 0;
				MyColor.B = 0;
				MyColor.A = 255;
				bSpecialColor = true;
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
						bSpecialColor = true;
					}
					else
					{
						MyColor.R = 82;
						MyColor.G = 82;
						MyColor.B = 159;
						MyColor.A = 255;
						bSpecialColor = true;
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
		if (PlayerItem != nullptr)
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
	AAA2_PlayerState* PRI = nullptr;
	AAA2_PlayerState* CurrentPRI = nullptr;
	AAA2_PlayerState* PlayerListItem = nullptr;
	AAGP_PlayerStart* PS = nullptr;
	int32 CurrentGroup = 0;
	int32 CurrentPosition = 0;
	/*
	if (i < 0 || i > Buttons.Num() || Buttons.Num() <= 0 || IsSeparator(i))
	{
		return;
	}
	CurrentGroup = GetGroup(i);
	CurrentPosition = GetPositionInGroup(CurrentGroup, i);
	PRI = PlayerOwner().PlayerReplicationInfo;
	PlayerListItem = Team.GetNoRequest(0);
	PS = Team.GetPlayerStart(CurrentGroup, CurrentPosition);
	if (PS != nullptr)
	{
		if (Cast<AHumanController>(PlayerOwner()) != nullptr && Cast<AHumanController>(PlayerOwner())->bTournamentServer)
		{
			CurrentPRI = nullptr;
			if (!IsSlotEnabled(i))
			{
				DisableComponent(Buttons[i]);
			}
			else
			{
				if (!PlayerOwner().PlayerReplicationInfo.bAdmin && !PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain && Cast<AHumanController>(PlayerOwner())->TournamentIsTeamRosterLocked(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex))
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
				if (PlayerItem != nullptr)
				{
					CurrentPRI = PlayerItem;
				}
				else
				{
					if (PlayerListItem != nullptr)
					{
						CurrentPRI = PlayerListItem;
					}
				}
			}
			else
			{
				if (PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain)
				{
					if (PlayerItem != nullptr)
					{
						CurrentPRI = PlayerItem;
					}
					else
					{
						if (PlayerListItem != nullptr)
						{
							CurrentPRI = PlayerListItem;
						}
					}
				}
				else
				{
					if (PRI != nullptr && PlayerListItem != nullptr && PRI == PlayerListItem)
					{
						CurrentPRI = PRI;
					}
				}
			}
			if (PlayerItem != nullptr)
			{
				Buttons[i].Caption = RemoveCaption;
				Buttons[i].Hint = RemoveHint;
			}
			else
			{
				Buttons[i].Caption = SelectCaption;
				Buttons[i].Hint = SelectHint;
			}
			if (CurrentPRI != nullptr)
			{
				if (PS != nullptr && !IsQualified(PS, CurrentPRI))
			}
		}
	}
	{
		Buttons[i].WinLeft = Bounds[2] - Buttons[i].WinWidth - 4;
		Buttons[i].WinTop = Y;
		Buttons[i].bVisible = true;
	}
	*/
}

bool UAATournamentUnitGMCList::ButtonClick(UGUIComponent* Sender)
{
	int32 i = 0;
	int32 RealIndex = 0;
	AAA2_PlayerState* PRI = nullptr;
	AHumanController* HC = nullptr;
	int32 CurrentGroup = 0;
	int32 CurrentPosition = 0;
	/*
	for (i = 0; i < Buttons.Num(); i++)
	{
		if (Buttons[i] != nullptr)
		{
			if (Sender == Buttons[i])
			{
				CurrentGroup = GetGroup(i);
				CurrentPosition = GetPositionInGroup(CurrentGroup, i);
				HC = Cast<AHumanController>(PlayerOwner());
				if (HC != nullptr && HC.bTournamentServer)
				{
					if (Team != nullptr && HC.PlayerReplicationInfo != nullptr && HC.PlayerReplicationInfo.Team != nullptr && Team.TeamIndex == HC.PlayerReplicationInfo.Team.TeamIndex || HC.PlayerReplicationInfo.bAdmin)
					{
						if (Buttons[i].Caption == RemoveCaption)
						{
							Buttons[i].Caption = SelectCaption;
							Buttons[i].Hint = SelectHint;
							RealIndex = Team.GetRealIndex(CurrentGroup, CurrentPosition);
							PRI = Team.GetPlayerRequest(CurrentGroup, CurrentPosition);
							if (PRI != nullptr)
							{
								if (PlayerOwner().PlayerReplicationInfo.bAdmin || PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain || !HumanController(PlayerOwner()).TournamentIsTeamRosterLocked(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex) && PRI != nullptr && PRI == PlayerOwner().PlayerReplicationInfo)
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
								if (PRI != nullptr)
								{
									if (PlayerOwner().PlayerReplicationInfo.bAdmin || PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain || !HumanController(PlayerOwner()).TournamentIsTeamRosterLocked(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex) && PRI != nullptr && PRI == PlayerOwner().PlayerReplicationInfo)
									{
										HC.TournamentAssignClass(PRI.PlayerName, CurrentGroup, CurrentPosition);
									}
								}
							}
						}
					}
				}
				return true;
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
		return breturn;
	}
	if (Index >= 0 && Buttons[Index] != nullptr)
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
