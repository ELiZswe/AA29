// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAUnitGMCList/AAUnitGMCList.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "Engine/Canvas.h"

UAAUnitGMCList::UAAUnitGMCList()
{
	UGUIToolTip* ServerListToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());
	ServerListToolTip->ExpirationSeconds = 8;
	//ServerListToolTip->OnPreDraw=AAUnitGMCList.PreDrawHint;
	//ServerListToolTip->OnDraw = AAUnitGMCList.DrawHint;

	ButtonHint = "Click here to select this slot";
	ButtonCaption = "Select";
	SelectHint = "Click here to select this slot";
	SelectCaption = "Select";
	RemoveHint = "Click here to leave this slot";
	RemoveCaption = "Remove";
	RequestHint = "Requesting this slot";
	RequestCaption = "Request";
	PendingHint = "This selection is pending";
	PendingCaption = "Pending";
	SwapHint = "Click here to request a swap for this slot";
	SwapCaption = "Swap";
	SwapRequestHint = "Requesting this slot";
	SwapRequestCaption = "Requesting";
	AcceptSwapHint = "Click here to accept a swap for this slot";
	AcceptSwapCaption = "Accept Swap";
	TeamIndex = 255;
	MinVisibleTeamEntries = 16;
	ColumnHeadings = { "Class", "Player Name", "" };
	InitColumnPerc = { 0.37, 0.43, 0.2 };
	SortColumn = -1;
	//__OnDrawItem__Delegate = "AAUnitGMCList.InternalOnDrawItem";
	//ToolTip = GUIToolTip'AGP_Interface.AAUnitGMCList.ServerListToolTip';
	//__OnPreDraw__Delegate = "AAUnitGMCList.InternalOnPreDraw";
}

void UAAUnitGMCList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	//GRI = PlayerOwner().GameReplicationInfo;
	//Team = Cast<AGP_TeamInfo>(PlayerOwner().PlayerReplicationInfo.Team);
}

void UAAUnitGMCList::Initialize()
{
	/*
	int32 i = 0;
	if (bInitialized)
	{
		return;
	}
	Initialize();
	for (i = 0; i < ItemCount; i++)
	{
		if (!IsSeparator(i))
		{
			Buttons[i] = new () UGUIButton::StaticClass();
			Buttons[i].RenderWeight = 4;
			Buttons[i].StyleName = "MainMenuButton";
			Buttons[i].Caption = ButtonCaption;
			Buttons[i].Hint = ButtonHint;
			Buttons[i].bScaleToParent = true;
			Buttons[i].WinWidth = 0.25;
			Buttons[i].WinLeft = 0.999;
			Buttons[i].WinTop = 0.999;
			Buttons[i].InitComponent(Controller, this);
			Buttons[i].Opened(this);
			Buttons[i].__OnClick__Delegate = ButtonClick;
			Buttons[i].__OnPreDraw__Delegate = PreDrawButtons;
			Buttons[i].bVisible = false;
			AttachedComponents[i] = Buttons[i];
		}
	}
	*/
}

bool UAAUnitGMCList::PreDrawButtons(UCanvas* C)
{
	int32 i = 0;
	float XL = 0;
	float YL = 0;
	/*
	for (i = 0; i < Buttons.Num(); i++)
	{
		if (Buttons[i] != nullptr)
		{
			Buttons[i].bVisible = false;
			Buttons[i].WinHeight = ItemHeight;
			Buttons[i].Style.TextSize(C, MenuState, ".Accept Swap.", XL, YL, FontScale);
			Buttons[i].WinWidth = XL;
		}
	}
	*/
	return true;
}

bool UAAUnitGMCList::InternalOnPreDraw(UCanvas* Canvas)
{
	/*
	if (Team != nullptr)
	{
		if (TeamIndex != Team.TeamIndex)
		{
			TeamIndex = Team.TeamIndex;
			SetGroupSize(0, Team.FTCount[0]);
			SetGroupSize(1, Team.FTCount[1]);
			SetGroupSize(2, Team.FTCount[2]);
			SetGroupSize(3, Team.FTCount[3]);
			SetGroupSize(4, Team.FTCount[4]);
			bInitialized = false;
			Initialize();
		}
	}
	*/
	return true;
}

void UAAUnitGMCList::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	if (!IsSeparator(i))
	{
		DrawItem(Canvas, i, X, Y, W, H, bSelected, bPending);
	}
	*/
}

void UAAUnitGMCList::DrawSeparator(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
}

void UAAUnitGMCList::DrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	float CellLeft = 0;
	float CellWidth = 0;
	AAA2_PlayerState* PlayerItem = nullptr;
	int32 CurrentGroup = 0;
	int32 CurrentPosition = 0;
	float IconX = 0;
	float IconY = 0;
	CurrentGroup = GetGroup(i);
	/*
	CurrentPosition = GetPositionInGroup(CurrentGroup, i);
	PlayerItem = Team.GetPlayerRequest(CurrentGroup, CurrentPosition);
	if (GetPositionInGroup(GetGroup(i), i) == 0)
	{
		IconX = X + CellLeft;
		IconY = Y + ItemHeight - ItemHeight / 2;
		Canvas.SetPos(IconX, IconY);
		Canvas.SetDrawColor(255, 255, 255, 50);
		Canvas.Style = 6;
		if (GetGroup(i) - 1 >= 0)
		{
			Canvas.DrawTile(tFT[GetGroup(i) - 1], ItemHeight * 2, ItemHeight * 2, 0, 0, 32, 32);
		}
		Canvas.SetDrawColor(251, 248, 229, 255);
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	X += ActualWidth() * 0.15;
	DrawIcons(Canvas, PlayerItem, i, X, Y, CellLeft, CellWidth);
	GetCellLeftWidth(1, CellLeft, CellWidth);
	DrawPlayer(Canvas, PlayerItem, i, X, Y, CellLeft, CellWidth);
	GetCellLeftWidth(2, CellLeft, CellWidth);
	DrawButtons(Canvas, PlayerItem, i, X, Y, CellLeft, CellWidth);
	*/
}

void UAAUnitGMCList::DrawIcons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
	UMaterialInstance* Icon = nullptr;
	float IH = 0;
	float IconX = 0;
	float IconY = 0;
	AAGP_PlayerStart* PS = nullptr;
	int32 CurrentGroup = 0;
	int32 CurrentPosition = 0;
	CurrentGroup = GetGroup(i);
	/*
	CurrentPosition = GetPositionInGroup(CurrentGroup, i);
	IH = ItemHeight / 2 + ItemHeight / 4;
	IconX = X + 3;
	IconY = Y + ItemHeight - IH / 2;
	PS = Team.GetPlayerStart(CurrentGroup, CurrentPosition);
	if (PS != nullptr)
	{
		if (!PS.bSpecialForces && !PS.bGuerrilla && !PS.bIFVIP)
		{
			Icon = GetRankIcon(PS);
			Canvas.SetPos(IconX, IconY);
			Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
			IconX += IH + 1;
			Icon = GetClassIcon(PS);
			Canvas.SetPos(IconX, IconY);
			Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
			IconX += IH + 1;
		}
		else
		{
			Icon = GetSFIcon(PS);
			Canvas.SetPos(IconX, IconY);
			Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
			IconX += IH + 1;
		}
	}
	if (PlayerItem != nullptr)
	{
		Icon = GetSubClassIcon(PlayerItem);
		if (Icon != nullptr)
		{
			Canvas.SetPos(IconX, IconY);
			Canvas.DrawTile(Icon, IH, IH, 0, 0, 32, 32);
		}
		IconX += IH + 1;
	}
	*/
}

void UAAUnitGMCList::DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
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
	/*
	CurrentPosition = GetPositionInGroup(CurrentGroup, i);
	PRI = PlayerOwner().PlayerReplicationInfo;
	PlayerListItem = Team.GetNoRequest(0);
	PS = Team.GetPlayerStart(CurrentGroup, CurrentPosition);
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
		PlayerState = GetPlayerState(PlayerItem);
		Style.DrawText(Canvas, PlayerState, CellLeft, Y, CellWidth, ItemHeight, 0, PlayerItem.PlayerName, FontScale);
	}
	if (bSpecialColor)
	{
		for (j = 0; j < 5; j++)
		{
			Style.FontColors[j] = OldColors[j];
		}
	}
	*/
}

void UAAUnitGMCList::DrawButtons(UCanvas* Canvas, AAA2_PlayerState* PlayerItem, int32 i, float X, float Y, float CellLeft, float CellWidth)
{
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
	PS = Team.GetPlayerStart(CurrentGroup, CurrentPosition);
	if (!IsSlotEnabled(i))
	{
		DisableComponent(Buttons[i]);
	}
	else
	{
		if (PS != nullptr && PlayerItem != nullptr && !IsQualified(PS, PlayerItem))
		{
			DisableComponent(Buttons[i]);
		}
		else
		{
			if (!Team.CanSelect(PlayerOwner().PlayerReplicationInfo))
			{
				DisableComponent(Buttons[i]);
			}
			else
			{
				EnableComponent(Buttons[i]);
			}
		}
	}
	Buttons[i].WinLeft = Bounds[2] - Buttons[i].WinWidth - 4;
	Buttons[i].WinTop = Y;
	Buttons[i].bVisible = true;
	Buttons[i].Caption = SelectCaption;
	Buttons[i].Hint = SelectHint;
	if (PlayerItem != nullptr)
	{
		if (PlayerItem == PlayerOwner().PlayerReplicationInfo)
		{
			Buttons[i].bVisible = false;
		}
		else
		{
			Buttons[i].bVisible = true;
			if (Team.GetPendingRequestIndex(PlayerItem) != -1)
			{
				Buttons[i].Caption = PendingCaption;
				Buttons[i].Hint = PendingHint;
				if (MenuState == 4)
				{
					Buttons[i].MenuStateChange(0);
				}
			}
			if (Team.WantsToSwap(PlayerItem, PlayerOwner().PlayerReplicationInfo))
			{
				Buttons[i].Caption = AcceptSwapCaption;
				Buttons[i].Hint = AcceptSwapHint;
				if (MenuState == 4)
				{
					Buttons[i].MenuStateChange(0);
				}
			}
			else
			{
				if (Team.WantsToSwap(PlayerOwner().PlayerReplicationInfo, PlayerItem))
				{
					Buttons[i].Caption = SwapRequestCaption;
					Buttons[i].Hint = SwapRequestHint;
					if (MenuState == 4)
					{
						Buttons[i].MenuStateChange(0);
					}
				}
				else
				{
					Buttons[i].Caption = SwapCaption;
					Buttons[i].Hint = SwapHint;
					if (MenuState == 4)
					{
						Buttons[i].MenuStateChange(0);
					}
				}
			}
		}
	}
	*/
}

bool UAAUnitGMCList::ButtonClick(UGUIComponent* Sender)
{
	int32 i = 0;
	int32 CurrentGroup = 0;
	int32 CurrentPosition = 0;
	AAA2_PlayerState* PlayerItem = nullptr;
	/*
	for (i = 0; i < Buttons.Num(); i++)
	{
		if (Buttons[i] != nullptr)
		{
			if (Sender == Buttons[i])
			{
				CurrentGroup = GetGroup(i);
				CurrentPosition = GetPositionInGroup(CurrentGroup, i);
				PlayerItem = Team.GetPlayerRequest(CurrentGroup, CurrentPosition);
				if (Team.FTEnabled[CurrentGroup] != 0 && PlayerItem == nullptr || PlayerItem != PlayerOwner().PlayerReplicationInfo)
				{
					PlayerOwner().PlayerReplicationInfo.SubmitPlayerRequest(CurrentGroup, CurrentPosition);
					DisableComponent(Buttons[i]);
				}
			}
			else
			{
				EnableComponent(Buttons[i]);
			}
		}
	}
	*/
	return true;
}

bool UAAUnitGMCList::InternalOnClick(UGUIComponent* Sender)
{
	bool bReturn= false;
	/*
	bReturn = InternalOnClick(Sender);
	if (IsSeparator(Index))
	{
		return breturn;
	}
	if (Buttons[Index] != nullptr)
	{
		Buttons[Index].OnClick(Buttons[Index]);
	}
	*/
	return bReturn;
}

bool UAAUnitGMCList::PreDrawHint(UCanvas* C)
{
	int32 IconW = 0;
	int32 i = 0;
	float XL = 0;
	float YL = 0;
	float MaxWidth = 0;
	float TotalHeight = 0;
	UGUIStyles* S = nullptr;
	bool bDrawSFIcons = false;
	bool bDrawExtraSFIcons = false;
	AAGP_PlayerStart* PS = nullptr;
	bDrawSFIcons = false;
	bDrawExtraSFIcons = false;
	/*
	for (i = 0; i < ItemCount; i++)
	{
		if (!IsSeparator(i))
		{
			PS = Team.GetPlayerStart(GetGroup(i), GetPositionInGroup(GetGroup(i), i));
			if (PS != nullptr && PS.bSpecialForces)
			{
				bDrawSFIcons = true;
			}
		}
	}
	i = 0;
	if (i < ItemCount)
	{
		if (!IsSeparator(i))
		{
			PS = Team.GetPlayerStart(GetGroup(i), GetPositionInGroup(GetGroup(i), i));
			if (PS != nullptr && PS.bExtraSpecialForces)
			{
				bDrawExtraSFIcons = true;
				bDrawSFIcons = false;
			}
		}
		else
		{
			i++;
		}
	}
	if (Controller == nullptr || !MousingOverIcons() || ToolTip == nullptr || ToolTip.Style == nullptr)
	{
		return true;
	}
	if (ToolTip.bResetPosition || ToolTip.bTrackMouse)
	{
		S = ToolTip.Style;
		if (bDrawExtraSFIcons)
		{
			for (i = 0; i < ExtraSpecialForces.Num(); i++)
			{
				IconW = ExtraSpecialForces[i].MaterialUSize();
				S.TextSize(C, MenuState, ExtraSpecialForcesDescriptions[i], XL, YL, FontScale);
				XL += IconW + 0.2 * IconW;
				if (XL > MaxWidth)
				{
					MaxWidth = XL;
				}
				YL = FMath::Max(YL, ExtraSpecialForces[i].MaterialVSize());
				TotalHeight += YL;
			}
			for (i = 0; i < Guerrilla.Num(); i++)
			{
				IconW = Guerrilla[i].MaterialUSize();
				S.TextSize(C, MenuState, GuerrillaDescriptions[i], XL, YL, FontScale);
				XL += IconW + 0.2 * IconW;
				if (XL > MaxWidth)
				{
					MaxWidth = XL;
				}
				YL = FMath::Max(YL, Guerrilla[i].MaterialVSize());
				TotalHeight += YL;
			}
		}
		else
		{
			if (!bDrawSFIcons)
			{
				for (i = 0; i < rank.Num(); i++)
				{
					IconW = rank[i].MaterialUSize();
					S.TextSize(C, MenuState, RankDescriptions[i], XL, YL, FontScale);
					XL += IconW + 0.2 * IconW;
					if (XL > MaxWidth)
					{
						MaxWidth = XL;
					}
					YL = FMath::Max(YL, rank[i].MaterialVSize());
					TotalHeight += YL;
				}
				for (i = 0; i < Class.Num(); i++)
				{
					IconW = Class[i].MaterialUSize();
					S.TextSize(C, MenuState, ClassDescriptions[i], XL, YL, FontScale);
					XL += IconW + 0.2 * IconW;
					if (XL > MaxWidth)
					{
						MaxWidth = XL;
					}
					YL = FMath::Max(YL, Class[i].MaterialVSize());
					TotalHeight += YL;
				}
			}
			if (bDrawSFIcons)
			{
				for (i = 0; i < SpecialForces.Num(); i++)
				{
					IconW = SpecialForces[i].MaterialUSize();
					S.TextSize(C, MenuState, SpecialForcesDescriptions[i], XL, YL, FontScale);
					XL += IconW + 0.2 * IconW;
					if (XL > MaxWidth)
					{
						MaxWidth = XL;
					}
					YL = FMath::Max(YL, SpecialForces[i].MaterialVSize());
					TotalHeight += YL;
				}
				for (i = 0; i < Guerrilla.Num(); i++)
				{
					IconW = Guerrilla[i].MaterialUSize();
					S.TextSize(C, MenuState, GuerrillaDescriptions[i], XL, YL, FontScale);
					XL += IconW + 0.2 * IconW;
					if (XL > MaxWidth)
					{
						MaxWidth = XL;
					}
					YL = FMath::Max(YL, Guerrilla[i].MaterialVSize());
					TotalHeight += YL;
				}
			}
		}
		for (i = 0; i < SubClass.Num(); i++)
		{
			IconW = SubClass[i].MaterialUSize();
			S.TextSize(C, MenuState, SubClassDescriptions[i], XL, YL, FontScale);
			XL += IconW + 0.2 * IconW;
			if (XL > MaxWidth)
			{
				MaxWidth = XL;
			}
			YL = FMath::Max(YL, SubClass[i].MaterialVSize());
			TotalHeight += YL;
		}
		TotalHeight += S.BorderOffsets[1] + S.BorderOffsets[3];
		ToolTip.WinWidth = MaxWidth + S.BorderOffsets[0] + S.BorderOffsets[2];
		ToolTip.WinHeight = TotalHeight;
		ToolTip.WinTop = ToolTip.GetTop(C);
		ToolTip.WinLeft = ToolTip.GetLeft(C);
		ToolTip.bResetPosition = false;
	}
	*/
	return true;
}

bool UAAUnitGMCList::DrawHint(UCanvas* C)
{
	UGUIStyles* S = nullptr;
	FPlane NormMod = FPlane({});
	int32 i = 0;
	int32 IconW = 0;
	int32 IconH = 0;
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	bool bDrawSFIcons = false;
	bool bDrawExtraSFIcons = false;
	AAGP_PlayerStart* PS = nullptr;
	bDrawSFIcons = false;
	bDrawExtraSFIcons = false;
	/*
	for (i = 0; i < ItemCount; i++)
	{
		if (!IsSeparator(i))
		{
			PS = Team.GetPlayerStart(GetGroup(i), GetPositionInGroup(GetGroup(i), i));
			if (PS != nullptr && PS.bSpecialForces)
			{
				bDrawSFIcons = true;
			}
		}
	}
	i = 0;
	if (i < ItemCount)
	{
		if (!IsSeparator(i))
		{
			PS = Team.GetPlayerStart(GetGroup(i), GetPositionInGroup(GetGroup(i), i));
			if (PS != nullptr && PS.bExtraSpecialForces)
			{
				bDrawExtraSFIcons = true;
				bDrawSFIcons = false;
			}
		}
		else
		{
			i++;
		}
	}
	if (Controller == nullptr || !MousingOverIcons() || ToolTip == nullptr || ToolTip.Style == nullptr)
	{
		return true;
	}
	S = ToolTip.Style;
	C.DrawColor.R = 127;
	C.DrawColor.G = 127;
	C.DrawColor.B = 127;
	C.DrawColor.A = 255;
	X = ToolTip.WinLeft;
	Y = ToolTip.WinTop;
	XL = ToolTip.WinWidth;
	YL = ToolTip.WinHeight;
	NormMod = C.ColorModulate;
	C.ColorModulate.W = 0.3;
	C.ColorModulate.X = 0.2;
	C.ColorModulate.Y = 0.2;
	C.ColorModulate.Z = 0.2;
	S.Draw(C, 0, X + 2, Y + 2, XL, YL);
	C.ColorModulate = NormMod;
	S.Draw(C, 0, X, Y, XL, YL);
	X += S.BorderOffsets[0];
	Y += S.BorderOffsets[1];
	if (bDrawExtraSFIcons)
	{
		for (i = 0; i < ExtraSpecialForces.Num(); i++)
		{
			IconW = ExtraSpecialForces[i].MaterialUSize();
			IconH = ExtraSpecialForces[i].MaterialVSize();
			S.TextSize(C, MenuState, ExtraSpecialForcesDescriptions[i], XL, YL, FontScale);
			YL = FMax(YL, IconH);
			C.SetPos(X, Y);
			C.DrawTile(ExtraSpecialForces[i], IconW, YL, 0, 0, IconW, IconH);
			S.DrawText(C, MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, ExtraSpecialForcesDescriptions[i], FontScale);
			Y += YL;
		}
		for (i = 0; i < Guerrilla.Num(); i++)
		{
			IconW = Guerrilla[i].MaterialUSize();
			IconH = Guerrilla[i].MaterialVSize();
			S.TextSize(C, MenuState, GuerrillaDescriptions[i], XL, YL, FontScale);
			YL = FMax(YL, IconH);
			C.SetPos(X, Y);
			C.DrawTile(Guerrilla[i], IconW, YL, 0, 0, IconW, IconH);
			S.DrawText(C, MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, GuerrillaDescriptions[i], FontScale);
			Y += YL;
		}
	}
	else
	{
		if (!bDrawSFIcons)
		{
			for (i = 0; i < rank.Num(); i++)
			{
				IconW = rank[i].MaterialUSize();
				IconH = rank[i].MaterialVSize();
				S.TextSize(C, MenuState, RankDescriptions[i], XL, YL, FontScale);
				YL = FMax(YL, IconH);
				C.SetPos(X, Y);
				C.DrawTile(rank[i], IconW, YL, 0, 0, IconW, IconH);
				S.DrawText(C, MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, RankDescriptions[i], FontScale);
				Y += YL;
			}
		}
		if (!bDrawSFIcons)
		{
			for (i = 0; i < Class.Num(); i++)
			{
				IconW = Class[i].MaterialUSize();
				IconH = Class[i].MaterialVSize();
				S.TextSize(C, MenuState, ClassDescriptions[i], XL, YL, FontScale);
				YL = FMax(YL, IconH);
				C.SetPos(X, Y);
				C.DrawTile(Class[i], IconW, YL, 0, 0, IconW, IconH);
				S.DrawText(C, MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, ClassDescriptions[i], FontScale);
				Y += YL;
			}
		}
		if (bDrawSFIcons)
		{
			for (i = 0; i < SpecialForces.Num(); i++)
			{
				IconW = SpecialForces[i].MaterialUSize();
				IconH = SpecialForces[i].MaterialVSize();
				S.TextSize(C, MenuState, SpecialForcesDescriptions[i], XL, YL, FontScale);
				YL = FMax(YL, IconH);
				C.SetPos(X, Y);
				C.DrawTile(SpecialForces[i], IconW, YL, 0, 0, IconW, IconH);
				S.DrawText(C, MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, SpecialForcesDescriptions[i], FontScale);
				Y += YL;
			}
			for (i = 0; i < Guerrilla.Num(); i++)
			{
				IconW = Guerrilla[i].MaterialUSize();
				IconH = Guerrilla[i].MaterialVSize();
				S.TextSize(C, MenuState, GuerrillaDescriptions[i], XL, YL, FontScale);
				YL = FMax(YL, IconH);
				C.SetPos(X, Y);
				C.DrawTile(Guerrilla[i], IconW, YL, 0, 0, IconW, IconH);
				S.DrawText(C, MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, GuerrillaDescriptions[i], FontScale);
				Y += YL;
			}
		}
	}
	for (i = 0; i < SubClass.Num(); i++)
	{
		IconW = SubClass[i].MaterialUSize();
		IconH = SubClass[i].MaterialVSize();
		S.TextSize(C, MenuState, SubClassDescriptions[i], XL, YL, FontScale);
		YL = FMax(YL, IconH);
		C.SetPos(X, Y);
		C.DrawTile(SubClass[i], IconW, YL, 0, 0, IconW, IconH);
		S.DrawText(C, MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, SubClassDescriptions[i], FontScale);
		Y += YL;
	}
	*/
	return true;
}

bool UAAUnitGMCList::MousingOverIcons()
{
	float IconRight = 0;
	float CellLeft = 0;
	float CellWidth = 0;
	/*
	if (Controller == nullptr)
	{
		return false;
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	IconRight = CellLeft + CellWidth;
	return Controller.MouseX >= CellLeft && Controller.MouseX <= IconRight;
	*/
	return false;    //FAKE   /ELiZ
}

bool UAAUnitGMCList::IsSlotEnabled(int32 i)
{
	int32 CurrentGroup = 0;
	CurrentGroup = GetGroup(i);
	return Team->FTEnabled[CurrentGroup] != 0;
}

bool UAAUnitGMCList::IsGroupEnabled(int32 i)
{
	return Team->FTEnabled[i] != 0;
}

bool UAAUnitGMCList::IsPSEnabled(AAGP_PlayerStart* PS)
{
	return Team->FTEnabled[(uint8)PS->FireTeam] != 0;
}

bool UAAUnitGMCList::IsEnabled()
{
	return IsGroupEnabled(Index);
}

bool UAAUnitGMCList::CanSelect()
{
	return true;
}

float UAAUnitGMCList::InternalGetItemHeight(UCanvas* C)
{
	MaxVisibleTeamEntries = ItemCount + 1;
	if (MaxVisibleTeamEntries < MinVisibleTeamEntries)
	{
		MaxVisibleTeamEntries = MinVisibleTeamEntries;
	}
	return Super::InternalGetItemHeight(C);
}
