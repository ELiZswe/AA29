// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AAGUIMultiColumnList/AAGroupMCList/AATeamList/AAUnitGMCList/AAUnitGMCList.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"

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
	//Team = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
}

void UAAUnitGMCList::Initialize()
{
	/*
	local int32 i;
	if (bInitialized)
	{
		Return;
	}
	Initialize();
	for (i = 0; i < ItemCount; i++)
	{
		if (!IsSeparator(i))
		{
			Buttons[i] = new () classClass'GUIButton';
			Buttons[i].RenderWeight = 4;
			Buttons[i].StyleName = "MainMenuButton";
			Buttons[i].Caption = ButtonCaption;
			Buttons[i].Hint = ButtonHint;
			Buttons[i].bScaleToParent = True;
			Buttons[i].WinWidth = 0.25;
			Buttons[i].WinLeft = 0.999;
			Buttons[i].WinTop = 0.999;
			Buttons[i].InitComponent(Controller, Self);
			Buttons[i].Opened(Self);
			Buttons[i].__OnClick__Delegate = ButtonClick;
			Buttons[i].__OnPreDraw__Delegate = PreDrawButtons;
			Buttons[i].bVisible = False;
			AttachedComponents[i] = Buttons[i];
		}
	}
	*/
}

bool UAAUnitGMCList::PreDrawButtons(UCanvas* C)
{
	/*
	local int32 i;
	local float XL;
	local float YL;
	for (i = 0; i < Buttons.Length; i++)
	{
		if (Buttons[i] != None)
		{
			Buttons[i].bVisible = False;
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
	if (Team != None)
	{
		if (TeamIndex != Team.TeamIndex)
		{
			TeamIndex = Team.TeamIndex;
			SetGroupSize(0, Team.FTCount[0]);
			SetGroupSize(1, Team.FTCount[1]);
			SetGroupSize(2, Team.FTCount[2]);
			SetGroupSize(3, Team.FTCount[3]);
			SetGroupSize(4, Team.FTCount[4]);
			bInitialized = False;
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
	/*
	local float CellLeft;
	local float CellWidth;
	local AAA2_PlayerState* PlayerItem;
	local int32 CurrentGroup;
	local int32 CurrentPosition;
	local float IconX;
	local float IconY;
	CurrentGroup = GetGroup(i);
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
	/*
	local Material Icon;
	local float IH;
	local float IconX;
	local float IconY;
	local AGP.AGP_PlayerStart PS;
	local int32 CurrentGroup;
	local int32 CurrentPosition;
	CurrentGroup = GetGroup(i);
	CurrentPosition = GetPositionInGroup(CurrentGroup, i);
	IH = ItemHeight / 2 + ItemHeight / 4;
	IconX = X + 3;
	IconY = Y + ItemHeight - IH / 2;
	PS = Team.GetPlayerStart(CurrentGroup, CurrentPosition);
	if (PS != None)
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
	if (PlayerItem != None)
	{
		Icon = GetSubClassIcon(PlayerItem);
		if (Icon != None)
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
	/*
	local int32 j;
	local GUI.eMenuState PlayerState;
	local AAA2_PlayerState* PRI;
	local AAA2_PlayerState* PlayerListItem;
	local AGP.AGP_PlayerStart PS;
	local Object.Color OldColors;
	local Object.Color MyColor;
	local bool bSpecialColor;
	local int32 CurrentGroup;
	local int32 CurrentPosition;
	bSpecialColor = False;
	CurrentGroup = GetGroup(i);
	CurrentPosition = GetPositionInGroup(CurrentGroup, i);
	PRI = PlayerOwner().PlayerReplicationInfo;
	PlayerListItem = Team.GetNoRequest(0);
	PS = Team.GetPlayerStart(CurrentGroup, CurrentPosition);
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
	/*
	local AGP.AGP_PlayerStart PS;
	local int32 CurrentGroup;
	local int32 CurrentPosition;
	if (i < 0 || i > Buttons.Length || Buttons.Length <= 0 || IsSeparator(i))
	{
		Return;
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
		if (PS != None && PlayerItem != None && !IsQualified(PS, PlayerItem))
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
	Buttons[i].bVisible = True;
	Buttons[i].Caption = SelectCaption;
	Buttons[i].Hint = SelectHint;
	if (PlayerItem != None)
	{
		if (PlayerItem == PlayerOwner().PlayerReplicationInfo)
		{
			Buttons[i].bVisible = False;
		}
		else
		{
			Buttons[i].bVisible = True;
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
	/*
	local int32 i;
	local int32 CurrentGroup;
	local int32 CurrentPosition;
	local AAA2_PlayerState* PlayerItem;
	for (i = 0; i < Buttons.Length; i++)
	{
		if (Buttons[i] != None)
		{
			if (Sender == Buttons[i])
			{
				CurrentGroup = GetGroup(i);
				CurrentPosition = GetPositionInGroup(CurrentGroup, i);
				PlayerItem = Team.GetPlayerRequest(CurrentGroup, CurrentPosition);
				if (Team.FTEnabled[CurrentGroup] != 0 && PlayerItem == None || PlayerItem != PlayerOwner().PlayerReplicationInfo)
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
		Return bReturn;
	}
	if (Buttons[Index] != None)
	{
		Buttons[Index].OnClick(Buttons[Index]);
	}
	*/
	return bReturn;
}

bool UAAUnitGMCList::PreDrawHint(UCanvas* C)
{
	/*
	local int32 IconW;
	local int32 i;
	local float XL;
	local float YL;
	local float MaxWidth;
	local float TotalHeight;
	local XInterface.GUIStyles S;
	local bool bDrawSFIcons;
	local bool bDrawExtraSFIcons;
	local AGP.AGP_PlayerStart PS;
	bDrawSFIcons = False;
	bDrawExtraSFIcons = False;
	for (i = 0; i < ItemCount; i++)
	{
		if (!IsSeparator(i))
		{
			PS = Team.GetPlayerStart(GetGroup(i), GetPositionInGroup(GetGroup(i), i));
			if (PS != None && PS.bSpecialForces)
			{
				bDrawSFIcons = True;
			}
		}
	}
	i = 0;
	if (i < ItemCount)
	{
		if (!IsSeparator(i))
		{
			PS = Team.GetPlayerStart(GetGroup(i), GetPositionInGroup(GetGroup(i), i));
			if (PS != None && PS.bExtraSpecialForces)
			{
				bDrawExtraSFIcons = True;
				bDrawSFIcons = False;
			}
		}
		else
		{
			i++;
		}
	}
	if (Controller == None || !MousingOverIcons() || ToolTip == None || ToolTip.Style == None)
	{
		Return True;
	}
	if (ToolTip.bResetPosition || ToolTip.bTrackMouse)
	{
		S = ToolTip.Style;
		if (bDrawExtraSFIcons)
		{
			for (i = 0; i < ExtraSpecialForces.Length; i++)
			{
				IconW = ExtraSpecialForces[i].MaterialUSize();
				S.TextSize(C, MenuState, ExtraSpecialForcesDescriptions[i], XL, YL, FontScale);
				XL += IconW + 0.2 * IconW;
				if (XL > MaxWidth)
				{
					MaxWidth = XL;
				}
				YL = Max(YL, ExtraSpecialForces[i].MaterialVSize());
				TotalHeight += YL;
			}
			for (i = 0; i < Guerrilla.Length; i++)
			{
				IconW = Guerrilla[i].MaterialUSize();
				S.TextSize(C, MenuState, GuerrillaDescriptions[i], XL, YL, FontScale);
				XL += IconW + 0.2 * IconW;
				if (XL > MaxWidth)
				{
					MaxWidth = XL;
				}
				YL = Max(YL, Guerrilla[i].MaterialVSize());
				TotalHeight += YL;
			}
		}
		else
		{
			if (!bDrawSFIcons)
			{
				for (i = 0; i < rank.Length; i++)
				{
					IconW = rank[i].MaterialUSize();
					S.TextSize(C, MenuState, RankDescriptions[i], XL, YL, FontScale);
					XL += IconW + 0.2 * IconW;
					if (XL > MaxWidth)
					{
						MaxWidth = XL;
					}
					YL = Max(YL, rank[i].MaterialVSize());
					TotalHeight += YL;
				}
				for (i = 0; i < Class.Length; i++)
				{
					IconW = Class[i].MaterialUSize();
					S.TextSize(C, MenuState, ClassDescriptions[i], XL, YL, FontScale);
					XL += IconW + 0.2 * IconW;
					if (XL > MaxWidth)
					{
						MaxWidth = XL;
					}
					YL = Max(YL, Class[i].MaterialVSize());
					TotalHeight += YL;
				}
			}
			if (bDrawSFIcons)
			{
				for (i = 0; i < SpecialForces.Length; i++)
				{
					IconW = SpecialForces[i].MaterialUSize();
					S.TextSize(C, MenuState, SpecialForcesDescriptions[i], XL, YL, FontScale);
					XL += IconW + 0.2 * IconW;
					if (XL > MaxWidth)
					{
						MaxWidth = XL;
					}
					YL = Max(YL, SpecialForces[i].MaterialVSize());
					TotalHeight += YL;
				}
				for (i = 0; i < Guerrilla.Length; i++)
				{
					IconW = Guerrilla[i].MaterialUSize();
					S.TextSize(C, MenuState, GuerrillaDescriptions[i], XL, YL, FontScale);
					XL += IconW + 0.2 * IconW;
					if (XL > MaxWidth)
					{
						MaxWidth = XL;
					}
					YL = Max(YL, Guerrilla[i].MaterialVSize());
					TotalHeight += YL;
				}
			}
		}
		for (i = 0; i < SubClass.Length; i++)
		{
			IconW = SubClass[i].MaterialUSize();
			S.TextSize(C, MenuState, SubClassDescriptions[i], XL, YL, FontScale);
			XL += IconW + 0.2 * IconW;
			if (XL > MaxWidth)
			{
				MaxWidth = XL;
			}
			YL = Max(YL, SubClass[i].MaterialVSize());
			TotalHeight += YL;
		}
		TotalHeight += S.BorderOffsets[1] + S.BorderOffsets[3];
		ToolTip.WinWidth = MaxWidth + S.BorderOffsets[0] + S.BorderOffsets[2];
		ToolTip.WinHeight = TotalHeight;
		ToolTip.WinTop = ToolTip.GetTop(C);
		ToolTip.WinLeft = ToolTip.GetLeft(C);
		ToolTip.bResetPosition = False;
	}
	*/
	return true;
}

bool UAAUnitGMCList::DrawHint(UCanvas* C)
{
	/*
	local XInterface.GUIStyles S;
	local Object.Plane NormMod;
	local int32 i;
	local int32 IconW;
	local int32 IconH;
	local float X;
	local float Y;
	local float XL;
	local float YL;
	local bool bDrawSFIcons;
	local bool bDrawExtraSFIcons;
	local AGP.AGP_PlayerStart PS;
	bDrawSFIcons = False;
	bDrawExtraSFIcons = False;
	for (i = 0; i < ItemCount; i++)
	{
		if (!IsSeparator(i))
		{
			PS = Team.GetPlayerStart(GetGroup(i), GetPositionInGroup(GetGroup(i), i));
			if (PS != None && PS.bSpecialForces)
			{
				bDrawSFIcons = True;
			}
		}
	}
	i = 0;
	if (i < ItemCount)
	{
		if (!IsSeparator(i))
		{
			PS = Team.GetPlayerStart(GetGroup(i), GetPositionInGroup(GetGroup(i), i));
			if (PS != None && PS.bExtraSpecialForces)
			{
				bDrawExtraSFIcons = True;
				bDrawSFIcons = False;
			}
		}
		else
		{
			i++;
		}
	}
	if (Controller == None || !MousingOverIcons() || ToolTip == None || ToolTip.Style == None)
	{
		Return True;
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
		for (i = 0; i < ExtraSpecialForces.Length; i++)
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
		for (i = 0; i < Guerrilla.Length; i++)
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
			for (i = 0; i < rank.Length; i++)
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
			for (i = 0; i < Class.Length; i++)
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
			for (i = 0; i < SpecialForces.Length; i++)
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
			for (i = 0; i < Guerrilla.Length; i++)
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
	for (i = 0; i < SubClass.Length; i++)
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

void UAAUnitGMCList::MousingOverIcons()
{
	/*
	local float IconRight;
	local float CellLeft;
	local float CellWidth;
	if (Controller == None)
	{
		Return False;
	}
	GetCellLeftWidth(0, CellLeft, CellWidth);
	IconRight = CellLeft + CellWidth;
	Return Controller.MouseX >= CellLeft && Controller.MouseX <= IconRight;
	*/
}

void UAAUnitGMCList::IsSlotEnabled(int32 i)
{
	//local int32 CurrentGroup;
	//CurrentGroup = GetGroup(i);
	//Return Team.FTEnabled[CurrentGroup] != 0;
}

void UAAUnitGMCList::IsGroupEnabled(int32 i)
{
	//Return Team.FTEnabled[i] != 0;
}

void UAAUnitGMCList::IsPSEnabled(AAGP_PlayerStart* PS)
{
	//Return Team.FTEnabled[PS.FireTeam] != 0;
}

void UAAUnitGMCList::IsEnabled()
{
	//Return IsGroupEnabled(Index);
}

bool UAAUnitGMCList::CanSelect()
{
	return true;
}

void UAAUnitGMCList::InternalGetItemHeight(UCanvas* C)
{
	/*
	MaxVisibleTeamEntries = ItemCount + 1;
	if (MaxVisibleTeamEntries < MinVisibleTeamEntries)
	{
		MaxVisibleTeamEntries = MinVisibleTeamEntries;
	}
	Return InternalGetItemHeight(C);
	*/
}