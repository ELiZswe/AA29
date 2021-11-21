// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_FavoritesPanel/AABrowser_FavoritesPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/Favorites/Favorites.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/ServerBrowserMCListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"

UAABrowser_FavoritesPanel::UAABrowser_FavoritesPanel()
{

	UGUIButton* ServersButtonObject = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ServersButtonObject->Caption = "Favorite Servers";
	ServersButtonObject->WinWidth = 0.5;
	ServersButtonObject->WinHeight = 0.07;
	ServersButtonObject->bBoundToParent = true;
	//ServersButtonObject->OnClick=AABrowser_FavoritesPanel.InternalOnClick;
	//ServersButtonObject->OnKeyEvent=ServersButtonObject.InternalOnKeyEvent;
	UGUIButton* BuddiesButtonObject = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BuddiesButtonObject->Caption = "Battle Buddies";
	BuddiesButtonObject->WinLeft = 0.5;
	BuddiesButtonObject->WinWidth = 0.5;
	BuddiesButtonObject->WinHeight = 0.07;
	BuddiesButtonObject->bBoundToParent = true;
	//BuddiesButtonObject->OnClick=AABrowser_FavoritesPanel.InternalOnClick;
	//BuddiesButtonObject->OnKeyEvent=BuddiesButtonObject.InternalOnKeyEvent;
	UFavorites* FavoritesObject = NewObject<UFavorites>(UFavorites::StaticClass());
	UServerBrowserMCListBox* ListBox = NewObject<UServerBrowserMCListBox>(UServerBrowserMCListBox::StaticClass());
	//ListBox->OnCreateComponent=AABrowser_FavoritesPanel.InternalOnCreateComponent;
	ListBox->WinTop = 0.07;
	ListBox->WinHeight = 0.93;
	UGUIContextMenu* FavoritesListMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	//FavoritesListMenu->OnOpen=AABrowser_FavoritesPanel.InternalOnOpenContextMenu;
	//FavoritesListMenu->OnSelect=AABrowser_FavoritesPanel.InternalOnClickContextMenu;
	FavoritesListMenu->StyleName = "ServerListContextMenu";
	ServersButton = ServersButtonObject;
	BuddiesButton = BuddiesButtonObject;
	FavoritesListBox = ListBox;
	ListHeadings = { "Favorite Servers", "Battle Buddies" };
	FavoritesContextMenu = FavoritesListMenu;
	Favorites = FavoritesObject;
}


void UAABrowser_FavoritesPanel::OnUpdateServerList()
{
}

void UAABrowser_FavoritesPanel::OnFavoriteServerSelectionChanged(FFavoriteServer Server)
{
}

void UAABrowser_FavoritesPanel::OnBuddySelectionChanged(FString Buddy)
{
}

void UAABrowser_FavoritesPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	FavoritesListBox.ContextMenu = FavoritesContextMenu;
	*/
}

void UAABrowser_FavoritesPanel::SetVisibility(bool bIsVisible)
{
	/*
	SetVisibility(bIsVisible);
	UpdateList();
	*/
}

void UAABrowser_FavoritesPanel::InternalFavoritesListSelectionChanged(UGUIComponent* Sender)
{
	/*
	Assert(Sender == FavoritesList);
	if (-1 == FavoritesList.Index)
	{
		Return;
	}
	Switch(DisplayMode)
	{
			case 0:
				OnFavoriteServerSelectionChanged(Favorites.GetFavoriteServer(FavoritesList.Index));
				break;
			case 1:
				OnBuddySelectionChanged(Favorites.GetBattleBuddy(FavoritesList.Index));
				break;
			default:
	}
	*/
}

void UAABrowser_FavoritesPanel::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (Sender == FavoritesListBox)
	{
		FavoritesList = GUIMultiColumnList(NewComp);
		if (None != FavoritesList)
		{
			FavoritesList.InitColumnPerc[0] = 1;
			FavoritesList.ColumnHeadings[0] = ListHeadings[0];
			FavoritesList.__OnDrawItem__Delegate = InternalOnDrawItem;
			FavoritesList.__OnChange__Delegate = InternalFavoritesListSelectionChanged;
		}
	}
	*/
}

void UAABrowser_FavoritesPanel::AddFavoriteServer(FString IPAddress)
{
	/*
	local Favorites.FavoriteServer Server;
	if (!Favorites.StringToFavoriteServer(Server, IPAddress))
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Invalid IP Address", "Please enter an IP address in the form 'a.b.c.d'  Optionally, a port can be specified by appending ':port'");
		Return;
	}
	OpenDialog("Adding Server", Server.IPAddress $ ":" $ Server.Port);
	Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
	Favorites.AddFavoriteServer(Server, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
	*/
}

void UAABrowser_FavoritesPanel::AddBattleBuddy(FString Buddy)
{
	/*
	OpenDialog("Adding Battle Buddy", Buddy);
	Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
	Favorites.AddBattleBuddy(Buddy, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
	*/
}

void UAABrowser_FavoritesPanel::RemoveSelected()
{
	/*
	if (-1 != FavoritesList.Index)
	{
		RemoveFavorite(DisplayMode, FavoritesList.Index);
	}
	*/
}

void UAABrowser_FavoritesPanel::RemoveFavorite(EFavoritesDisplayMode FavoritesType, int32 Choice)
{
	/*
	if (-1 != Choice)
	{
		Switch(FavoritesType)
		{
			case 0:
				OpenDialog("Removing Server", Favorites.GetFavoriteServer(Choice).IPAddress $ ":" $ Favorites.GetFavoriteServer(Choice).Port);
				Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
				Favorites.RemoveFavoriteServer(Favorites.GetFavoriteServer(Choice), HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
				break;
			case 1:
				OpenDialog("Removing Battle Buddy", Favorites.GetBattleBuddy(Choice));
				Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
				Favorites.RemoveBattleBuddy(Favorites.GetBattleBuddy(Choice), HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
				break;
			default:
		}
	}
	*/
}

bool UAABrowser_FavoritesPanel::IsValidDBMBSFilterList()
{
	/*
	Switch(DisplayMode)
	{
			case 1:
				Return Favorites.NumBattleBuddies() > 0;
				break;
			case 0:
			default:
				Return Favorites.NumFavoriteServers() > 0;
				break;
	}
	*/
	return false;
}

void UAABrowser_FavoritesPanel::GetDBMBSFilterList()
{
	/*
	Switch(DisplayMode)
	{
			case 1:
				Return Favorites.MakeBattleBuddyFilter(HumanController(PlayerOwner()).UserName);
				break;
			case 0:
			default:
				Return Favorites.MakeFavoriteServersFilter(HumanController(PlayerOwner()).UserName);
				break;
	}
	*/
}

void UAABrowser_FavoritesPanel::OpenDialog(FString Action, FString Message)
{
	/*
	if (None == AAFavoritesOperationModalDialog(Controller.TopPage()))
	{
		Controller.OpenMenu("AGP_Interface.AAFavoritesOperationModalDialog", Action, Message);
	}
	*/
}

void UAABrowser_FavoritesPanel::InternalOnFavoritesOperationComplete(int32 ResultCode, FString Message)
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
	else
	{
		UpdateList();
	}
	*/
}

void UAABrowser_FavoritesPanel::InternalOnOpenContextMenu(UGUIContextMenu* Sender)
{
	/*
	Sender.ContextItems.remove(0, Sender.ContextItems.Length);
	Log("SJJ:InternalOnOpenContextMenu" @ FavoritesList.Index);
	Switch(DisplayMode)
	{
			case 0:
				Sender.ContextItems[0] = "Add new Favorite Server";
				Sender.ContextItems[1] = "Update Current Status";
				break;
			case 1:
				Sender.ContextItems[0] = "Add new Battle Buddy";
				Sender.ContextItems[1] = "Update Current Status";
				break;
			default:
	}
	if (-1 != FavoritesList.Index)
	{
		Sender.ContextItems.insert(1, 1);
		Sender.ContextItems[1] = "Remove" @ GetItemToDraw(FavoritesList.Index);
	}
	Return Sender.ContextItems.Length > 0;
	*/
}

void UAABrowser_FavoritesPanel::InternalOnClickContextMenu(UGUIContextMenu* Sender, int32 Index)
{
	/*
	if (0 == Index)
	{
		Switch(DisplayMode)
		{
			case 0:
				if (Controller.OpenMenu("AGP_Interface.AAGetDataMenu", "Add a favorite server"))
				{
					Controller.ActivePage.__OnClose__Delegate = AddFavoriteServerClosed;
				}
				break;
			case 1:
				if (Controller.OpenMenu("AGP_Interface.AAGetDataMenu", "Add a buddy"))
				{
					Controller.ActivePage.__OnClose__Delegate = AddBuddyClosed;
				}
				break;
			default:
		}
	}
	else
	{
		if (1 == Index)
		{
			RemoveFavorite(DisplayMode, FavoritesList.Index);
		}
		else
		{
			OnUpdateServerList();
		}
	}
	*/
}

void UAABrowser_FavoritesPanel::AddFavoriteServerClosed(bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		AddFavoriteServer(AAGetDataMenu(Controller.ActivePage).ed_Data.GetText());
	}
	*/
}

void UAABrowser_FavoritesPanel::AddBuddyClosed(bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		AddBattleBuddy(AAGetDataMenu(Controller.ActivePage).ed_Data.GetText());
	}
	*/
}

void UAABrowser_FavoritesPanel::UpdateList()
{
	/*
	local int Index;
	local int numFavorites;
	Switch(DisplayMode)
	{
			case 0:
				numFavorites = Favorites.NumFavoriteServers();
				break;
			case 1:
				numFavorites = Favorites.NumBattleBuddies();
				break;
			default:
	}
	FavoritesList.Clear();
	for (Index = 0; Index < numFavorites; Index++)
	{
		FavoritesList.AddedItem();
	}
	*/
}

bool UAABrowser_FavoritesPanel::InternalOnClick(UGUIComponent* Sender)
{
	bool Handled=false;
	/*
	Switch(Sender)
	{
			case ServersButton:
				DisplayMode = 0;
				FavoritesList.ColumnHeadings[0] = ListHeadings[0];
				UpdateList();
				if (FavoritesList.ItemCount > 0)
				{
					OnUpdateServerList();
				}
				Handled = True;
				break;
			case BuddiesButton:
				DisplayMode = 1;
				FavoritesList.ColumnHeadings[0] = ListHeadings[1];
				UpdateList();
				if (FavoritesList.ItemCount > 0)
				{
					OnUpdateServerList();
				}
				Handled = True;
				break;
			default:
	}
	*/
	return Handled;
}

FString UAABrowser_FavoritesPanel::GetItemToDraw(int32 Index)
{
	FString Item="";
	/*
	local Favorites.FavoriteServer Server;
	
	Switch(DisplayMode)
	{
			case 0:
				Server = Favorites.GetFavoriteServer(Index);
				Item = Server.IPAddress;
				if (1716 != Server.Port)
				{
					Item = Server.IPAddress $ ":" $ Server.Port;
				}
				break;
			case 1:
				Item = Favorites.GetBattleBuddy(Index);
				break;
			default:
	}
	*/
	return Item;
}

void UAABrowser_FavoritesPanel::InternalOnDrawItem(UCanvas* Canvas, int32 i, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	local float CellLeft;
	local float CellWidth;
	local XInterface.GUIStyles DrawStyle;
	local string Item;
	Item = GetItemToDraw(i);
	if (bSelected)
	{
		FavoritesList.SelectedStyle.Draw(Canvas, MenuState, X, Y, W, H + 1);
		DrawStyle = FavoritesList.SelectedStyle;
	}
	else
	{
		DrawStyle = FavoritesList.Style;
	}
	FavoritesList.GetCellLeftWidth(0, CellLeft, CellWidth);
	DrawStyle.DrawText(Canvas, FavoritesList.MenuState, CellLeft, Y, CellWidth, H, 1, Item, FavoritesList.FontScale);
	*/
}