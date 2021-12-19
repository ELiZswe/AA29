// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/AABrowser_ServerListBox/AABrowser_ServerListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"

UAABrowser_ServerListBox::UAABrowser_ServerListBox()
{

	UGUIContextMenu* RCMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	RCMenu->ContextItems = { "Join %NAME%","Join %NAME% As Spectator","Join %NAME% As Player Admin","Join %NAME% As Admin","-","Refresh Server Info","Refresh List","-","Add %IP% to Favorites List","Remove %IP% from Favorites List","-","Copy %NAME%'s Address","Open IP" };
	//RCMenu->OnOpen=AABrowser_ServerListBox.InternalOnOpen;
	//RCMenu->OnClose=AABrowser_ServerListBox.InternalOnClose;
	//RCMenu->OnSelect=AABrowser_ServerListBox.InternalOnClick;
	RCMenu->StyleName = "ServerListContextMenu";
	UGUIToolTip* ServerListToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());
	ServerListToolTip->ExpirationSeconds = 8;
	//ServerListToolTip->OnPreDraw=AABrowser_ServerListBox.PreDrawHint;
	//ServerListToolTip->OnDraw = AABrowser_ServerListBox.DrawHint;
	OpenIPPage = "AGP_Interface.AABrowser_OpenIP";
	SPECIDX = 1;
	JOINASPLAYERADMIN = 2;
	JOINASADMINIDX = 3;
	REPINGIDX = 5;
	REFRESHIDX = 6;
	ADDFAVIDX = 8;
	REMOVEFAVIDX = 9;
	COPYIDX = 11;
	OPENIPIDX = 12;
	PingTooltipText = "Ping: Measured Ping To Server / Average Player Ping";
	DefaultListClass = "AGP_Interface.AABrowser_ServersList";
	ContextMenu = RCMenu;
	ToolTip = ServerListToolTip;
}

void UAABrowser_ServerListBox::OnUpdateServerList()
{
}

void UAABrowser_ServerListBox::OnUpdateServerRulesAndPlayerList(int32 ServerIndex)
{
}

void UAABrowser_ServerListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	ContextItems = ContextMenu.ContextItems;
	MyScrollBar.MyGripButton.__OnMousePressed__Delegate = InternalOnMousePressed;
	MyScrollBar.MyGripButton.__OnMouseRelease__Delegate = InternalOnMouseReleased;
	*/
}

void UAABrowser_ServerListBox::InternalOnMousePressed(UGUIComponent* Sender, bool bRepeat)
{
	/*
	local IpDrv.ServerBrowserBase sbBase;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(AABrowser_ServersList(List).bIsLAN);
	if (None != ServerBrowserDBMBS(sbBase))
	{
		ServerBrowserDBMBS(sbBase).SuppressPings();
	}
	if (GUIVertScrollBar(Sender.MenuOwner) != None)
	{
		GUIVertScrollBar(Sender.MenuOwner).GripPressed(Sender, bRepeat);
	}
	*/
}
void UAABrowser_ServerListBox::InternalOnMouseReleased(UGUIComponent* Sender)
{
	/*
	local IpDrv.ServerBrowserBase sbBase;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(AABrowser_ServersList(List).bIsLAN);
	if (None != ServerBrowserDBMBS(sbBase))
	{
		ServerBrowserDBMBS(sbBase).UnsuppressPings();
	}
	*/
}
void UAABrowser_ServerListBox::SetToolTipText(FString NewToolTipText)
{
}

bool UAABrowser_ServerListBox::PreDrawHint(UCanvas* C)
{
	/*
	if (MousingOverIcons())
	{
		return PreDrawIconsHint(C);
	}
	else
	{
		if (MousingOverPing())
		{
			return PreDrawPingHint(C);
		}
	}
	ToolTip.bResetPosition = True;
	*/
	return true;
}

bool UAABrowser_ServerListBox::PreDrawIconsHint(UCanvas* C)
{
	/*
	local AABrowser_ServersList L;
	local int IconW;
	local int i;
	local float XL;
	local float YL;
	local float MaxWidth;
	local float TotalHeight;
	local XInterface.GUIStyles S;
	L = AABrowser_ServersList(List);
	if (L == None || Controller == None || !MousingOverIcons() || ToolTip == None || ToolTip.Style == None)
	{
		return true;
	}
	if (ToolTip.bResetPosition || ToolTip.bTrackMouse)
	{
		S = ToolTip.Style;
		for (i = 0; i < L.Icons.Length; i++)
		{
			IconW = L.Icons[i].MaterialUSize();
			S.TextSize(C, L.MenuState, L.IconDescriptions[i], XL, YL, L.FontScale);
			XL += IconW + 0.2 * IconW;
			if (XL > MaxWidth)
			{
				MaxWidth = XL;
			}
			YL = Max(YL, L.Icons[i].MaterialVSize());
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

bool UAABrowser_ServerListBox::PreDrawPingHint(UCanvas* C)
{
	//ToolTip.SetTip(PingTooltipText);
	return false;
}

bool UAABrowser_ServerListBox::DrawHint(UCanvas* C)
{
	/*
	if (MousingOverIcons())
	{
		return DrawIconsHint(C);
	}
	else
	{
		if (MousingOverPing())
		{
			return DrawPingHint(C);
		}
	}
	*/
	return true;
}

bool UAABrowser_ServerListBox::DrawIconsHint(UCanvas* C)
{
	/*
	local XInterface.GUIStyles S;
	local AABrowser_ServersList L;
	local Object.Plane NormMod;
	local int i;
	local int IconW;
	local int IconH;
	local float X;
	local float Y;
	local float XL;
	local float YL;
	L = AABrowser_ServersList(List);
	if (L == None || Controller == None || !MousingOverIcons() || ToolTip == None || ToolTip.Style == None)
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
	for (i = 0; i < L.Icons.Length; i++)
	{
		IconW = L.Icons[i].MaterialUSize();
		IconH = L.Icons[i].MaterialVSize();
		S.TextSize(C, L.MenuState, L.IconDescriptions[i], XL, YL, L.FontScale);
		YL = FMax(YL, IconH);
		C.SetPos(X, Y);
		C.DrawTile(L.Icons[i], IconW, YL, 0, 0, IconW, IconH);
		S.DrawText(C, L.MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, L.IconDescriptions[i], L.FontScale);
		Y += YL;
	}
	*/
	return true;
}

bool UAABrowser_ServerListBox::DrawPingHint(UCanvas* C)
{
	return false;
}

bool UAABrowser_ServerListBox::MousingOverIcons()
{
	/*
	local float IconRight;
	local float IconLeft;
	local float IconWidth;
	if (List == None || Controller == None)
	{
		return false;
	}
	List.GetCellLeftWidth(0, IconLeft, IconWidth);
	IconRight = IconLeft + IconWidth;
	return Controller.MouseX >= IconLeft && Controller.MouseX <= IconRight;
	*/
	return false;    //FAKE    /ELiZ
}

bool UAABrowser_ServerListBox::MousingOverPing()
{
	/*
	local float IconRight;
	local float IconLeft;
	local float IconWidth;
	if (List == None || Controller == None)
	{
		return false;
	}
	List.GetCellLeftWidth(4, IconLeft, IconWidth);
	IconRight = IconLeft + IconWidth;
	return Controller.MouseX >= IconLeft && Controller.MouseX <= IconRight;
	*/
	return false;    //FAKE    /ELiZ
}

bool UAABrowser_ServerListBox::ShouldAddContextChoice(int32 ContextIndex, FGameSpyServerItem ServerItem)
{
	bool ShouldAdd=false;
	/*
	local IpDrv.ServerBrowserBase sbBase;
	
	local Favorites.FavoriteServer FavoriteServer;
	local FString IPAddress;
	ShouldAdd = True;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(AABrowser_ServersList(List).bIsLAN);
	IPAddress = sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port);
	FavoriteServer.IPAddress = Left(IPAddress, InStr(IPAddress, ":"));
	FavoriteServer.Port = ServerItem.Port;
	Switch(ContextIndex)
	{
			case ADDFAVIDX:
				if (!sbBase.IsSupportsFavorites() || 1 == ServerItem.bExploreTheArmy || -1 != 'AABrowser_FavoritesPanel'.Default.Favorites.GetIndexOfFavoriteServer(FavoriteServer))
				{
					ShouldAdd = False;
				}
				break;
			case REMOVEFAVIDX:
				if (!sbBase.IsSupportsFavorites() || -1 == 'AABrowser_FavoritesPanel'.Default.Favorites.GetIndexOfFavoriteServer(FavoriteServer))
				{
					ShouldAdd = False;
				}
				break;
			default:
				break;
	}
	*/
	return ShouldAdd;
}

bool UAABrowser_ServerListBox::InternalOnOpen(UGUIContextMenu* Sender)
{
	/*
	local IpDrv.ServerBrowserBase sbBase;
	local FGameSpyServerItem ServerItem;
	local int ContextIndex;
	local int ChoiceIndex;
	Sender.ContextItems.remove(0, Sender.ContextItems.Length);
	if (List.IsValid())
	{
		sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(AABrowser_ServersList(List).bIsLAN);
		if (sbBase != None)
		{
			sbBase.GetSpecificServer(List.Index, ServerItem);
		}
		for (ContextIndex = 0; ContextIndex < ContextItems.Length; ContextIndex++)
		{
			if (ShouldAddContextChoice(ContextIndex, ServerItem))
			{
				Sender.ContextItems[ChoiceIndex] = Repl(ContextItems[ContextIndex], "%NAME%", Eval(HumanController(PlayerOwner()).bDisableServerColorsInBrowser, StripColorCodes(ServerItem.Name), ServerItem.Name $ Chr(27) $ Chr(217) $ Chr(180) $ Chr(52)));
				Sender.ContextItems[ChoiceIndex] = Repl(Sender.ContextItems[ChoiceIndex], "%IP%", sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port));
				ContextChoiceToActionIndex[ChoiceIndex] = ContextIndex;
				++ChoiceIndex;
			}
		}
	}
	else
	{
		Sender.ContextItems[0] = ContextItems[OPENIPIDX];
		ContextChoiceToActionIndex[0] = OPENIPIDX;
		Sender.ContextItems[1] = ContextItems[REFRESHIDX];
		ContextChoiceToActionIndex[1] = REFRESHIDX;
	}
	*/
	return true;
}

void UAABrowser_ServerListBox::OpenFavoritesOperationDialog(FString Action, FString Message)
{
	/*
	if (None == AAFavoritesOperationModalDialog(Controller.TopPage()))
	{
		Controller.OpenMenu("AGP_Interface.AAFavoritesOperationModalDialog", Action, Message);
	}
	*/
}

void UAABrowser_ServerListBox::InternalOnFavoritesOperationComplete(int32 ResultCode, FString Message)
{
	/*
	if (None != AAFavoritesOperationModalDialog(Controller.TopPage()))
	{
		Controller.CloseMenu(1 != ResultCode);
	}
	if (1 != ResultCode)
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Favorites Update Failed", Message);
	}
	*/
}

void UAABrowser_ServerListBox::InternalOnClick(UGUIContextMenu* Sender, int32 Index)
{
	/*
	local int idx;
	local IpDrv.ServerBrowserBase sbBase;
	local FGameSpyServerItem ServerItem;
	local AABrowser_ServersList L;
	local Favorites.FavoriteServer FavoriteServer;
	local FString IPAddress;
	L = AABrowser_ServersList(List);
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(AABrowser_ServersList(List).bIsLAN);
	if (sbBase != None && List.IsValid())
	{
		sbBase.GetSpecificServer(List.Index, ServerItem);
	}
	if (Sender != None)
	{
		if (NotifyContextSelect(Sender, Index))
		{
			Return;
		}
		Switch(ContextChoiceToActionIndex[Index])
		{
			case JOINIDX:
				L.Connect(False);
				break;
			case SPECIDX:
				L.Connect(True);
				break;
			case JOINASADMINIDX:
				if (Controller.OpenMenu("AGP_Interface.AAGetDataMenu", "Joining a server as an admin requires a password.", "Please enter a valid password."))
				{
					Controller.ActivePage.__OnClose__Delegate = InternalOnCloseGetAdminPassword;
				}
				break;
			case JOINASPLAYERADMIN:
				if (Controller.OpenMenu("AGP_Interface.AAGetDataMenu", "Joining a server as a player admin requires a password.", "Please enter a valid password."))
				{
					Controller.ActivePage.__OnClose__Delegate = InternalOnCloseGetPlayerAdminPassword;
				}
				break;
			case REPINGIDX:
				idx = List.CurrentListId();
				OnUpdateServerRulesAndPlayerList(idx);
				break;
			case REFRESHIDX:
				OnUpdateServerList();
				break;
			case ADDFAVIDX:
				IPAddress = sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port);
				FavoriteServer.IPAddress = Left(IPAddress, InStr(IPAddress, ":"));
				FavoriteServer.Port = ServerItem.Port;
				OpenFavoritesOperationDialog("Adding Server", IPAddress);
				'AABrowser_FavoritesPanel'.Default.Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
				'AABrowser_FavoritesPanel'.Default.Favorites.AddFavoriteServer(FavoriteServer, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
				break;
			case REMOVEFAVIDX:
				IPAddress = sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port);
				FavoriteServer.IPAddress = Left(IPAddress, InStr(IPAddress, ":"));
				FavoriteServer.Port = ServerItem.Port;
				OpenFavoritesOperationDialog("Removing Server", IPAddress);
				'AABrowser_FavoritesPanel'.Default.Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
				'AABrowser_FavoritesPanel'.Default.Favorites.RemoveFavoriteServer(FavoriteServer, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
				break;
			case COPYIDX:
				L.CopyServerToClipboard();
				break;
			case OPENIPIDX:
				if (L.IsValid())
				{
					Controller.OpenMenu(OpenIPPage, sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port));
				}
				else
				{
					Controller.OpenMenu(OpenIPPage);
				}
			default:
				Log("Unknown context menu choice" @ Index @ Sender.ContextItems[Index]);
		}
	}
	*/
}

void UAABrowser_ServerListBox::InternalOnCloseGetAdminPassword(bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		AABrowser_ServersList(List).Connect(False, AAGetDataMenu(Controller.ActivePage).ed_Data.GetText());
	}
	*/
}

void UAABrowser_ServerListBox::InternalOnCloseGetPlayerAdminPassword(bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		AABrowser_ServersList(List).Connect(False, AAGetDataMenu(Controller.ActivePage).ed_Data.GetText(), True);
	}
	*/
}

void UAABrowser_ServerListBox::InitBaseList(UGUIListBase* LocalList)
{
	/*
	local XInterface.GUIMultiColumnList L;
	L = GUIMultiColumnList(LocalList);
	if (L == None || List == LocalList)
	{
		Return;
	}
	if (List != None)
	{
		List.SetTimer(0, False);
		RemoveComponent(List, True);
		AppendComponent(L, False);
		List = L;
	}
	else
	{
		List = L;
		AppendComponent(L, False);
	}
	Header.MyList = List;
	InitBaseList(LocalList);
	*/
}
