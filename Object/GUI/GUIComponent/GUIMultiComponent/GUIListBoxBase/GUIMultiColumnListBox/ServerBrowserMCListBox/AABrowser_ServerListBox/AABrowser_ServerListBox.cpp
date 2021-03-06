// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/AABrowser_ServerListBox/AABrowser_ServerListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_ServersList/AABrowser_ServersList.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAFavoritesOperationModalDialog/AAFavoritesOperationModalDialog.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserDBMBS/ServerBrowserDBMBS.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIVertScrollBar/GUIVertScrollBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGetDataMenu/AAGetDataMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiColumnListHeader/GUIMultiColumnListHeader.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "Engine/Canvas.h"

UAABrowser_ServerListBox::UAABrowser_ServerListBox()
{
	ContextChoiceToActionIndex.SetNum(12);

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
	Super::InitComponent(MyController, MyOwner);
	ContextItems = ContextMenu->ContextItems;
	//MyScrollBar->MyGripButton->__OnMousePressed__Delegate = InternalOnMousePressed;
	//MyScrollBar->MyGripButton->__OnMouseRelease__Delegate = InternalOnMouseReleased;
}

void UAABrowser_ServerListBox::InternalOnMousePressed(UGUIComponent* Sender, bool bRepeat)
{
	AServerBrowserBase* sbBase = nullptr;
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->MyHUD)->GetCurrentServerBrowser(Cast<UAABrowser_ServersList>(List)->bIsLAN);
	if (Cast<AServerBrowserDBMBS>(sbBase) != nullptr)
	{
		Cast<AServerBrowserDBMBS>(sbBase)->SuppressPings();
	}
	if (Cast<UGUIVertScrollBar>(Sender->MenuOwner) != nullptr)
	{
		Cast<UGUIVertScrollBar>(Sender->MenuOwner)->GripPressed(Sender, bRepeat);
	}
}

void UAABrowser_ServerListBox::InternalOnMouseReleased(UGUIComponent* Sender)
{
	AServerBrowserBase* sbBase = nullptr;
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->MyHUD)->GetCurrentServerBrowser(Cast<UAABrowser_ServersList>(List)->bIsLAN);
	if (Cast<AServerBrowserDBMBS>(sbBase) != nullptr)
	{
		Cast<AServerBrowserDBMBS>(sbBase)->UnsuppressPings();
	}
}

void UAABrowser_ServerListBox::SetToolTipText(FString NewToolTipText)
{
}

bool UAABrowser_ServerListBox::PreDrawHint(UCanvas* C)
{
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
	ToolTip->bResetPosition = true;
	return true;
}

bool UAABrowser_ServerListBox::PreDrawIconsHint(UCanvas* C)
{
	UAABrowser_ServersList* L = nullptr;
	int32 IconW = 0;
	int32 i = 0;
	float XL = 0;
	float YL = 0;
	float MaxWidth = 0;
	float TotalHeight = 0;
	UGUIStyles* S = nullptr;
	L = Cast<UAABrowser_ServersList>(List);
	if (L == nullptr || Controller == nullptr || !MousingOverIcons() || ToolTip == nullptr || ToolTip->Style == nullptr)
	{
		return true;
	}
	if (ToolTip->bResetPosition || ToolTip->bTrackMouse)
	{
		S = ToolTip->Style;
		for (i = 0; i < L->Icons.Num(); i++)
		{
			//IconW = L->Icons[i]->MaterialUSize();
			S->TextSize(C, L->MenuState, L->IconDescriptions[i], XL, YL, L->FontScale);
			XL += IconW + 0.2 * IconW;
			if (XL > MaxWidth)
			{
				MaxWidth = XL;
			}
			//YL = FMath::Max(YL, L->Icons[i].MaterialVSize());
			TotalHeight += YL;
		}
		TotalHeight += S->BorderOffsets[1] + S->BorderOffsets[3];
		ToolTip->WinWidth = MaxWidth + S->BorderOffsets[0] + S->BorderOffsets[2];
		ToolTip->WinHeight = TotalHeight;
		ToolTip->WinTop = ToolTip->GetTop(C);
		ToolTip->WinLeft = ToolTip->GetLeft(C);
		ToolTip->bResetPosition = false;
	}
	return true;
}

bool UAABrowser_ServerListBox::PreDrawPingHint(UCanvas* C)
{
	ToolTip->SetTip(PingTooltipText);
	return false;
}

bool UAABrowser_ServerListBox::DrawHint(UCanvas* C)
{
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
	return true;
}

bool UAABrowser_ServerListBox::DrawIconsHint(UCanvas* C)
{
	UGUIStyles* S = nullptr;
	UAABrowser_ServersList* L = nullptr;
	FPlane NormMod;
	int32 i = 0;
	int32 IconW = 0;
	int32 IconH = 0;
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	L = Cast<UAABrowser_ServersList>(List);
	if (L == nullptr || Controller == nullptr || !MousingOverIcons() || ToolTip == nullptr || ToolTip->Style == nullptr)
	{
		return true;
	}
	S = ToolTip->Style;
	//C.DrawColor.R = 127;
	//C.DrawColor.G = 127;
	//C.DrawColor.B = 127;
	//C.DrawColor.A = 255;
	X = ToolTip->WinLeft;
	Y = ToolTip->WinTop;
	XL = ToolTip->WinWidth;
	YL = ToolTip->WinHeight;
	NormMod = C->ColorModulate;
	C->ColorModulate.W = 0.3;
	C->ColorModulate.X = 0.2;
	C->ColorModulate.Y = 0.2;
	C->ColorModulate.Z = 0.2;
	//S->Draw(C, 0, X + 2, Y + 2, XL, YL);
	C->ColorModulate = NormMod;
	//S->Draw(C, 0, X, Y, XL, YL);
	X += S->BorderOffsets[0];
	Y += S->BorderOffsets[1];
	for (i = 0; i < L->Icons.Num(); i++)
	{
		//IconW = L->Icons[i].MaterialUSize();
		//IconH = L->Icons[i].MaterialVSize();
		S->TextSize(C, L->MenuState, L->IconDescriptions[i], XL, YL, L->FontScale);
		//YL = FMax(YL, IconH);
		//C->SetPos(X, Y);
		//C->DrawTile(L->Icons[i], IconW, YL, 0, 0, IconW, IconH);
		//S->DrawText(C, L->MenuState, X + IconW + 0.2 * IconW, Y, XL, YL, 0, L->IconDescriptions[i], L->FontScale);
		Y += YL;
	}
	return true;
}

bool UAABrowser_ServerListBox::DrawPingHint(UCanvas* C)
{
	return false;
}

bool UAABrowser_ServerListBox::MousingOverIcons()
{
	float IconRight = 0;
	float IconLeft = 0;
	float IconWidth = 0;
	if (List == nullptr || Controller == nullptr)
	{
		return false;
	}
	List->GetCellLeftWidth(0, IconLeft, IconWidth);
	IconRight = IconLeft + IconWidth;
	return Controller->MouseX >= IconLeft && Controller->MouseX <= IconRight;
}

bool UAABrowser_ServerListBox::MousingOverPing()
{
	float IconRight = 0;
	float IconLeft = 0;
	float IconWidth = 0;
	if (List == nullptr || Controller == nullptr)
	{
		return false;
	}
	List->GetCellLeftWidth(4, IconLeft, IconWidth);
	IconRight = IconLeft + IconWidth;
	return Controller->MouseX >= IconLeft && Controller->MouseX <= IconRight;
}

bool UAABrowser_ServerListBox::ShouldAddContextChoice(int32 ContextIndex, FGameSpyServerItem ServerItem)
{
	bool ShouldAdd=false;
	AServerBrowserBase* sbBase = nullptr;
	FFavoriteServer aFavoriteServer = FFavoriteServer({});
	FString IPAddress = "";
	ShouldAdd = true;
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->MyHUD)->GetCurrentServerBrowser(Cast<UAABrowser_ServersList>(List)->bIsLAN);
	IPAddress = sbBase->IpAddrToString(ServerItem.IP, ServerItem.Port);
	//aFavoriteServer.IPAddress = Left(IPAddress, InStr(IPAddress, ":"));
	aFavoriteServer.Port = ServerItem.Port;

	if (ContextIndex == ADDFAVIDX)
	{
		/*
		if (!sbBase-<IsSupportsFavorites() || 1 == ServerItem.bExploreTheArmy || -1 != 'AABrowser_FavoritesPanel'.Default.Favorites.GetIndexOfFavoriteServer(aFavoriteServer))
		{
			ShouldAdd = false;
		}
			*/
	}
	if (ContextIndex == REMOVEFAVIDX)
	{
		/*
		if (!sbBase.IsSupportsFavorites() || -1 == 'AABrowser_FavoritesPanel'.Default.Favorites.GetIndexOfFavoriteServer(aFavoriteServer))
		{
			ShouldAdd = false;
		}
		*/
	}
	return ShouldAdd;
}

bool UAABrowser_ServerListBox::InternalOnOpen(UGUIContextMenu* Sender)
{
	AServerBrowserBase* sbBase = nullptr;
	FGameSpyServerItem ServerItem;
	int32 ContextIndex = 0;
	int32 ChoiceIndex = 0;
	/*
	Sender.ContextItems.RemoveAt(0, Sender.ContextItems.Num());
	if (List.IsValid())
	{
		sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(Cast<UAABrowser_ServersList>(List).bIsLAN);
		if (sbBase != nullptr)
		{
			sbBase.GetSpecificServer(List.Index, ServerItem);
		}
		for (ContextIndex = 0; ContextIndex < ContextItems.Num(); ContextIndex++)
		{
			if (ShouldAddContextChoice(ContextIndex, ServerItem))
			{
				Sender.ContextItems[ChoiceIndex] = Repl(ContextItems[ContextIndex], "%NAME%", Eval(Cast<AHumanController>(PlayerOwner())->bDisableServerColorsInBrowser, StripColorCodes(ServerItem.Name), ServerItem.Name + Chr(27) + Chr(217) + Chr(180) + Chr(52)));
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
	if (Cast<UAAFavoritesOperationModalDialog>(Controller->TopPage()) == nullptr)
	{
		Controller->OpenMenu("AGP_Interface.AAFavoritesOperationModalDialog", Action, Message);
	}
}

void UAABrowser_ServerListBox::InternalOnFavoritesOperationComplete(int32 ResultCode, FString Message)
{
	if (Cast<UAAFavoritesOperationModalDialog>(Controller->TopPage()) != nullptr)
	{
		Controller->CloseMenu(1 != ResultCode);
	}
	if (ResultCode != 1)
	{
		Controller->OpenMenu("AGP_Interface.AAGenericMessageBox", "Favorites Update Failed", Message);
	}
}

void UAABrowser_ServerListBox::InternalOnClick(UGUIContextMenu* Sender, int32 Index)
{
	int32 idx = 0;
	AServerBrowserBase* sbBase = nullptr;
	FGameSpyServerItem ServerItem;
	UAABrowser_ServersList* L = nullptr;
	FFavoriteServer aFavoriteServer = FFavoriteServer({});
	FString IPAddress = "";
	/*
	L = AABrowser_ServersList(List);
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(Cast<UAABrowser_ServersList>(List).bIsLAN);
	if (sbBase != nullptr && List.IsValid())
	{
		sbBase.GetSpecificServer(List.Index, ServerItem);
	}
	if (Sender != nullptr)
	{
		if (NotifyContextSelect(Sender, Index))
		{
			return;
		}
		switch(ContextChoiceToActionIndex[Index])
		{
			case JOINIDX:
				L.Connect(false);
				break;
			case SPECIDX:
				L.Connect(true);
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
				aFavoriteServer.IPAddress = Left(IPAddress, InStr(IPAddress, ":"));
				aFavoriteServer.Port = ServerItem.Port;
				OpenFavoritesOperationDialog("Adding Server", IPAddress);
				'AABrowser_FavoritesPanel'.Default.Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
				'AABrowser_FavoritesPanel'.Default.Favorites.AddFavoriteServer(aFavoriteServer, Cast<AHumanController>(PlayerOwner())->UserName, Cast<AHumanController>(PlayerOwner())->UserPassword, PlayerOwner());
				break;
			case REMOVEFAVIDX:
				IPAddress = sbBase.IpAddrToString(ServerItem.IP, ServerItem.Port);
				aFavoriteServer.IPAddress = Left(IPAddress, InStr(IPAddress, ":"));
				aFavoriteServer.Port = ServerItem.Port;
				OpenFavoritesOperationDialog("Removing Server", IPAddress);
				'AABrowser_FavoritesPanel'.Default.Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
				'AABrowser_FavoritesPanel'.Default.Favorites.RemoveFavoriteServer(aFavoriteServer, Cast<AHumanController>(PlayerOwner())->UserName, Cast<AHumanController>(PlayerOwner())->UserPassword, PlayerOwner());
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
	if (!bCancelled)
	{
		Cast<UAABrowser_ServersList>(List)->Connect(false, Cast<UAAGetDataMenu>(Controller->ActivePage)->ed_Data->GetText(),false);
	}
}

void UAABrowser_ServerListBox::InternalOnCloseGetPlayerAdminPassword(bool bCancelled)
{
	if (!bCancelled)
	{
		Cast<UAABrowser_ServersList>(List)->Connect(false, Cast<UAAGetDataMenu>(Controller->ActivePage)->ed_Data->GetText(), true);
	}
}

void UAABrowser_ServerListBox::InitBaseList(UGUIListBase* LocalList)
{
	UGUIMultiColumnList* L = nullptr;
	L = Cast<UGUIMultiColumnList>(LocalList);
	if (L == nullptr || List == LocalList)
	{
		return;
	}
	if (List != nullptr)
	{
		List->SetTimer(0, false);
		RemoveComponent(List, true);
		AppendComponent(L, false);
		List = L;
	}
	else
	{
		List = L;
		AppendComponent(L, false);
	}
	Header->MyList = List;
	InitBaseList(LocalList);
}
