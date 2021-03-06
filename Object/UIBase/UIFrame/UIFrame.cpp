// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"
#include "AA29/Object/UIInvDef/UIInvDef.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpBeacon/ClientBeaconReceiver/ClientBeaconReceiver.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvList/UIInvList.h"
#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvSlotBase.h"
#include "AA29/Object/UIBase/UIControl/UIListItems/UIListItems.h"
#include "Engine/Canvas.h"

UUIFrame::UUIFrame()
{
	Fonts.SetNum(10);
	_bToolTipActive = true;
}

static const float kResX = 800.0;
static const float kResY = 600.0;

void UUIFrame::Destroyed()
{
	UUIScreen* screen = nullptr;
	UUIScreen* nextscreen = nullptr;
	cActor = nullptr;
	_cInvItem = nullptr;
	_cInvContainer = nullptr;
	cInvDef = nullptr;
	_cInvList = nullptr;
	_cMouseOver = nullptr;
	cActiveScreen = nullptr;
	cStaticScreen = nullptr;
	cTitleScreen = nullptr;
	cSubScreen = nullptr;
	cFocus = nullptr;
	cMouse = nullptr;
	cHUD = nullptr;
	cMessageBox = nullptr;
	screen = cScreenList;
	if (screen != nullptr)
	{
		nextscreen = screen->cNextScreen;
		screen->Destroyed();
		screen = nextscreen;
	}
	cScreenList = nullptr;
}

void UUIFrame::SetMouse(int32 mX, int32 mY)
{
	if (cMouse != nullptr)
	{
		cMouse->SetMouse(mX, mY);
	}
}

void UUIFrame::ScaleControls(UCanvas* Canvas)
{
	UUIScreen* screen = nullptr;
	if ((_iOldSizeX == Canvas->SizeX) && (_iOldSizeY == Canvas->SizeY))
	{
		return;
	}
	fScaleX = (float(Canvas->SizeX) / 800);
	fScaleY = (float(Canvas->SizeY) / 600);
	if (_bAllowScaling)
	{
		offset.X = int((float(_Pos.X) * fScaleX));
		offset.Y = int((float(_Pos.Y) * fScaleY));
	}
	else
	{
		if ((Canvas->SizeX >= 800) && (Canvas->SizeY >= 600))
		{
			offset.X = ((Canvas->SizeX - 800) / 2);
			offset.Y = ((Canvas->SizeY - 600) / 2);
		}
	}
	for (screen = cScreenList; screen != nullptr; screen = screen->cNextScreen)
	{
		screen->ScaleControls(Canvas);
	}
	if (cMouse != nullptr)
	{
		cMouse->ScaleControl(Canvas);
	}
	if (_bAllowScaling)
	{
		_ScaledToolTipLoc.X = int(((float(_ToolTipLoc.X) * fScaleX) + float(offset.X)));
		_ScaledToolTipLoc.Y = int(((float(_ToolTipLoc.Y) * fScaleY) + float(offset.Y)));
	}
	else
	{
		_ScaledToolTipLoc.X = (_ToolTipLoc.X + offset.X);
		_ScaledToolTipLoc.Y = (_ToolTipLoc.Y + offset.Y);
	}
	_iOldSizeX = Canvas->SizeX;
	_iOldSizeY = Canvas->SizeY;
}

void UUIFrame::Create(AAA2_HUD* pHUD)
{
	cHUD = pHUD;
	SetupFonts();
	cInvDef = Cast<UUIInvDef>(CreateUIObject("AGP_UI.UIInvDef"));
}

bool UUIFrame::KeyType(int32 Key)
{
	if (_bMessageBox)
	{
		if (cMessageBox != nullptr)
		{
			return cMessageBox->KeyType(Key);
		}
	}
	if (cFocus != nullptr)
	{
		return cFocus->KeyType(Key);
	}
	if (cStaticScreen != nullptr)
	{
		return cStaticScreen->KeyType(Key);
	}
	if (cTitleScreen != nullptr)
	{
		return cTitleScreen->KeyType(Key);
	}
	if (cSubScreen != nullptr)
	{
		return cSubScreen->KeyType(Key);
	}
	if (cActiveScreen != nullptr)
	{
		return cActiveScreen->KeyType(Key);
	}
	return false;
}

bool UUIFrame::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	if (_bMessageBox)
	{
		if (cMessageBox != nullptr)
		{
			cMessageBox->ProcessKeyEvent(Key, Action, Delta);
			return true;
		}
	}
	if (cFocus != nullptr)
	{
		if (cFocus->ProcessKeyEvent(Key, Action, Delta))
		{
			return true;
		}
	}
	if (cStaticScreen != nullptr)
	{
		if (cStaticScreen->ProcessKeyEvent(Key, Action, Delta))
		{
			return true;
		}
	}
	if (cTitleScreen != nullptr)
	{
		if (cTitleScreen->ProcessKeyEvent(Key, Action, Delta))
		{
			return true;
		}
	}
	if (cSubScreen != nullptr)
	{
		if (cSubScreen->ProcessKeyEvent(Key, Action, Delta))
		{
			return true;
		}
	}
	if (cActiveScreen != nullptr)
	{
		if (cActiveScreen->ProcessKeyEvent(Key, Action, Delta))
		{
			return true;
		}
	}
	return false;
}

void UUIFrame::Draw(UCanvas* Canvas)
{
	int32 i = 0;
	UFont* oldfont = nullptr;
	FColor OldColor = FColor(0,0,0);
	int32 oldstyle = 0;
	//oldfont = Canvas->Font;
	//OldColor = Canvas->DrawColor;
	//oldstyle = Canvas->Style;
	//Canvas->Font = GetProperSizeFont(Canvas);
	ScaleControls(Canvas);
	//Canvas->Style = 1;
	i = 1;
	if (cStaticScreen != nullptr)
	{
		cStaticScreen->DrawScreen(Canvas, true);
		if (cActiveScreen != nullptr)
		{
			//Canvas->SetPos(111 + offset.X, 65 + offset.Y);
			OldColor = Canvas->DrawColor;
			//oldfont = Canvas->Font;
			//Canvas->SetDrawColor(196, 190, 141);
			//Canvas->Font = Fonts[4];
			//Canvas->DrawText(cActivescreen->_sTitle, , -90);
			//Canvas->Font = oldfont;
			Canvas->DrawColor = OldColor;
		}
	}
	if (cTitleScreen != nullptr)
	{
		cTitleScreen->DrawScreen(Canvas, true);
	}
	if (cSubScreen != nullptr)
	{
		cSubScreen->DrawScreen(Canvas, true);
	}
	//Canvas->DrawColor = OldColor;
	//Canvas->Style = oldstyle;
	if (cActiveScreen != nullptr)
	{
		if (_bMessageBox)
		{
			cActiveScreen->DrawScreen(Canvas, false);
			if (cMessageBox != nullptr)
			{
				cMessageBox->DrawScreen(Canvas, true);
				_bMessageBoxVisible = true;
			}
			else
			{
				_bMessageBoxVisible = false;
			}
		}
		else
		{
			cActiveScreen->DrawScreen(Canvas, true);
			_bMessageBoxVisible = false;
		}
	}
	if (cMouse != nullptr)
	{
		//Canvas->Style = 6;
		cMouse->Draw(Canvas);
	}
	if (cFocus != nullptr)
	{
		cFocus->MouseMove(cMouse->iMouseX, cMouse->iMouseY);
	}
	if (_bToolTipActive)
	{
		if (_cMouseOver != nullptr)
		{
			//Canvas->SetPos(_ScaledToolTipLoc.X, _ScaledToolTipLoc.Y);
			//Canvas->DrawText(_cMouseOver->GetToolTip());
		}
	}
	//Canvas->Font = oldfont;
}

void UUIFrame::Notify(int32 pUIEvent)
{
}

UUIListItems* UUIFrame::CreateUIListItems(FString ListItemsName)
{
	UUIListItems* myListItems = nullptr;
	UUIListItems* cUIListItems = nullptr; 
	/*
	cUIListItems = class<UIListItems>(DynamicLoadObject(ListItemsName, Class'Class'));
	myListItems = new (None) classcUIListItems;
	*/
	return myListItems;
}

UUIInvList* UUIFrame::CreateUIInvList(FString ListName)
{
	UUIInvList* MyList = nullptr;
	UUIInvList* cUIInvList = nullptr;
	/*
	cUIInvList = class<UIInvList>(DynamicLoadObject(ListName, Class'Class'));
	MyList = new (None) classcUIInvList;
	*/
	return MyList;
}

UUIControl* UUIFrame::CreateUIControl(FString ControlName)
{
	UUIControl* myControl = nullptr;
	UUIControl* cUIControl = nullptr;
	/*
	cUIControl = class<UIControl>(DynamicLoadObject(ControlName, Class'Class'));
	myControl = new (None) classcUIControl;
	*/
	return myControl;
}

UUIMouse* UUIFrame::CreateUIMouse(FString MouseName)
{
	UUIMouse* myMouse = nullptr;
	UUIMouse* cUIMouse = nullptr;
	/*
	cUIMouse = class<UIMouse>(DynamicLoadObject(MouseName, Class'Class'));
	myMouse = new (None) classcUIMouse;
	*/
	return myMouse;
}

void UUIFrame::AddMouse(FString szMouse, int32 pX, int32 pY, int32 pW, int32 pH, FString szTex)
{
	cMouse = CreateUIMouse(szMouse);
	cMouse->_Pos.X = pX;
	cMouse->_Pos.Y = pY;
	cMouse->_Pos.W = pW;
	cMouse->_Pos.H = pH;
	cMouse->SetBitmapString(szTex);
	cMouse->Create(this, nullptr, 0, 0, 0);
}

void UUIFrame::SetFocus(UUIControl* Control)
{
	if (cFocus != nullptr && cFocus != Control)
	{
		cFocus->Focus(false);
	}
	cFocus = Control;
	if (cFocus != nullptr)
	{
		cFocus->Focus(true);
	}
}

void UUIFrame::SetupFonts()
{
	/*
	Fonts[0] = Font(DynamicLoadObject("T_AA2_Fonts.ArialBold10", Class'Font'));
	Fonts[1] = Font(DynamicLoadObject("T_AA2_Fonts.ArialBold10", Class'Font'));
	Fonts[2] = Font(DynamicLoadObject("T_AA2_Fonts.ArialBold10", Class'Font'));
	Fonts[3] = Font(DynamicLoadObject("T_AA2_Fonts.ArialBold14", Class'Font'));
	Fonts[4] = Font(DynamicLoadObject("T_AA2_Fonts.ArialBold18", Class'Font'));
	Fonts[5] = Font(DynamicLoadObject("T_AA2_Fonts.ArialBold22", Class'Font'));
	Fonts[6] = Font(DynamicLoadObject("T_AA2_Fonts.ArialBold14", Class'Font'));
	Fonts[7] = Font(DynamicLoadObject("T_AA2_Fonts.Arial14", Class'Font'));
	Fonts[8] = Font(DynamicLoadObject("T_AA2_Fonts.ArialBlack10", Class'Font'));
	*/
}

UFont* UUIFrame::GetLargeFont()
{
	return Fonts[2];
}

UFont* UUIFrame::GetProperSizeFont(UCanvas* Canvas)
{
	if (_bAllowScaling)
	{
		if (Canvas->SizeX <= 640)
		{
			return Fonts[0];
		}
		else
		{
			if (Canvas->SizeX <= 800)
			{
				return Fonts[1];
			}
			else
			{
				if (Canvas->SizeX <= 1024)
				{
					return Fonts[2];
				}
				else
				{
					if (Canvas->SizeX <= 1280)
					{
						return Fonts[3];
					}
					else
					{
						if (Canvas->SizeX <= 1600)
						{
							return Fonts[4];
						}
						else
						{
							return Fonts[5];
						}
					}
				}
			}
		}
	}
	else
	{
		return Fonts[3];
	}
	return nullptr;
}

UFont* UUIFrame::GetProperSizeFontPrivate(UCanvas* Canvas)
{
	if (Canvas->SizeX <= 640)
	{
		return Fonts[0];
	}
	else
	{
		if (Canvas->SizeX <= 800)
		{
			return Fonts[1];
		}
		else
		{
			if (Canvas->SizeX <= 1024)
			{
				return Fonts[2];
			}
			else
			{
				if (Canvas->SizeX <= 1280)
				{
					return Fonts[3];
				}
				else
				{
					return Fonts[3];
				}
			}
		}
	}
	return nullptr;
}

void UUIFrame::DumpScreenLog()
{
	UUIScreen* screen = nullptr;
	int32 i = 0;
	UILog("#### DUMP SCREEN LOG START ####");
	screen = cScreenList;
	if (screen != nullptr)
	{
		//UILog("screen #" + i + " is ID " + screen->GetID());
		screen = screen->cNextScreen;
		i++;
	}
	UILog("#### DUMP SCREEN LOG END ####");
}

void UUIFrame::UILog(FString S)
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("%s"), *S);//Log(S);
	}
}

UUIScreen* UUIFrame::CreateUIScreen(FString ScreenName)
{
	UUIScreen* myScreen = nullptr;
	UUIScreen* cUIScreen = nullptr;
	/*
	cUIScreen = class<UIScreen>(DynamicLoadObject(ScreenName, Class'Class'));
	myScreen = new (None) classcUIScreen;
	*/
	return myScreen;
}

void UUIFrame::AddScreen(int32 pID, FString Title)
{
	UUIScreen* screen = nullptr;
	screen = CreateUIScreen("AGP_UI.UIScreen");
	screen->Create(this, pID, Title);
	//UILog("AddScreen " + pID + " result: " + screen);
	if (screen == nullptr)
	{
		UILog("ERROR screen == nullptr");
	}
	AddScreenToTail(screen);
}

UUIScreen* UUIFrame::GetScreen(int32 Id)
{
	UUIScreen* screen = nullptr;
	for (screen = cScreenList; screen != nullptr; screen = screen->cNextScreen)
	{
		if (screen->GetID() == Id)
		{
			return screen;
		}
	}
	return nullptr;
}

void UUIFrame::SetActiveScreen(int32 Id)
{
	_cMouseOver = nullptr;
	DropHeldItem();
	cActiveScreen = GetScreen(Id);
}

void UUIFrame::SetActiveScreen2(int32 Id)
{
	cActiveScreen = GetScreen(Id);
}

UUIScreen* UUIFrame::GetActiveScreen()
{
	return cActiveScreen;
}

void UUIFrame::ResetActiveScreen()
{
	cActiveScreen = nullptr;
}

UUIScreen* UUIFrame::GetLastScreen()
{
	UUIScreen* screen = nullptr;
	for (screen = cScreenList; screen != nullptr; screen = screen->cNextScreen)
	{
		if (screen->cNextScreen == nullptr)
		{
			return screen;
		}
	}
	return screen;
}

void UUIFrame::AddScreenToTail(UUIScreen* screen)
{
	UUIScreen* lastscreen = nullptr;
	lastscreen = GetLastScreen();
	if (lastscreen == nullptr)
	{
		cScreenList = screen;
		UILog("AddScreenToTail - Adding first node");
	}
	else
	{
		lastscreen->cNextScreen = screen;
		UILog("AddCreenToTail - Adding node");
	}
}

void UUIFrame::AddStaticScreen(int32 Id)
{
	cStaticScreen = GetScreen(Id);
}

void UUIFrame::RemoveStaticScreen()
{
	cStaticScreen = nullptr;
}

void UUIFrame::SetTitleScreen(int32 Id)
{
	cTitleScreen = GetScreen(Id);
}

void UUIFrame::RemoveTitleScreen()
{
	cTitleScreen = nullptr;
}

void UUIFrame::SetSubScreen(int32 Id)
{
	cSubScreen = GetScreen(Id);
}

void UUIFrame::RemoveSubScreen()
{
	cSubScreen = nullptr;
}

void UUIFrame::SetItemID(int32 Item)
{
	_InvItem.iItemID = Item;
}

int32 UUIFrame::GetItemID()
{
	return _InvItem.iItemID;
}

int32 UUIFrame::GetItemSize()
{
	return cInvDef->GetItemSize(_InvItem.iItemID);
}

void UUIFrame::SetItem(UUIInvSlotBase* List, int32 Slot, int32 Item)
{
	_InvItem.iItemID = Item;
	_cInvList = List;
	_iInvSlot = Slot;
}

AInventory* UUIFrame::GetHeldItem()
{
	return _cInvItem;
}

AInvContainer* UUIFrame::GetHeldContainer()
{
	return _cInvContainer;
}

void UUIFrame::SetHeldItem(AInventory* Item)
{
	_cInvItem = Item;
}

void UUIFrame::SetHeldContainer(AInvContainer* container)
{
	_cInvContainer = container;
}

void UUIFrame::DropHeldItem()
{
}

void UUIFrame::ReloadWeapon()
{
}

void UUIFrame::Hide()
{
	DropHeldItem();
	_cInvList = nullptr;
	_iInvSlot = -1;
	_InvItem.iItemID = 0;
}

void UUIFrame::EnableControl(int32 Id, bool State)
{
	UUIScreen* screen;
	screen = cScreenList;
	for (screen = cScreenList; screen != nullptr; screen = screen->cNextScreen)
	{
		if (screen->EnableControl(Id, State))
		{
			return;
		}
	}
}

FPoint UUIFrame::GetToolTipLocation()
{
	return _ToolTipLoc;
}

void UUIFrame::SetToolTipLocation(FPoint pLoc)
{
	_ToolTipLoc = pLoc;
}

bool UUIFrame::SetMouseOver(UUIControl* Control)
{
	if (cMouse->HasMouseMoved())
	{
		_cMouseOver = Control;
		return true;
	}
	else
	{
		return false;
	}
}

float UUIFrame::GetLastDrawTime()
{
	//return cHUD->Level->RealSeconds;
	return 0;     //FAKE   /ELiZ
}

void UUIFrame::AddMessageBox()
{
	UUIScreen* screen = nullptr;
	screen = CreateUIScreen("AGP_UI.UIScreen");
	screen->Create(this, 0, "MessageBox");
	//UILog("AddMessageBox " + 0 + " result: " + screen);
	if (screen == nullptr)
	{
		UILog("ERROR screen == nullptr");
	}
	if (cMessageBox == nullptr)
	{
		cMessageBox = screen;
	}
}

UUIScreen* UUIFrame::GetMessageBox()
{
	return cMessageBox;
}

void UUIFrame::OpenMessageBox()
{
	_bMessageBox = true;
	SetFocus(nullptr);
}

void UUIFrame::CloseMessageBox()
{
	_bMessageBox = false;
}

void UUIFrame::SetMouseBusy(bool busy)
{
	if (cMouse != nullptr)
	{
		cMouse->SetBusy(busy);
	}
}

bool UUIFrame::IsMouseBusyDrawing()
{
	if (cMouse != nullptr)
	{
		return cMouse->bDrawnBusy;
	}
	else
	{
		return false;
	}
}

void UUIFrame::PlayMenuSoundSpecific(USoundBase* Sound)
{
}

AClientBeaconReceiver* UUIFrame::GetClientBeacon()
{
	return nullptr;    //FAKE  /ELiZ
}

AServerBrowserBase* UUIFrame::GetCurrentServerBrowser()
{
	return nullptr;    //FAKE  /ELiZ
}

void UUIFrame::RunConsoleCommand(FString comm)
{
}

void UUIFrame::OpenQuickLan(FString serveraddr)
{
}

void UUIFrame::UnbindKey(int32 Key, FString Command)
{
}

void UUIFrame::SetResolution(int32 X, int32 Y)
{
}

int32 UUIFrame::GetDesiredX()
{
	return 0;     //FAKE   /ELiZ
}

int32 UUIFrame::GetDesiredY()
{
	return 0;     //FAKE   /ELiZ
}
void UUIFrame::SetSkinTone()
{
}

void UUIFrame::SetGameSpyPos(int32 pos)
{
}

int32 UUIFrame::GetGameSpyPos()
{
	return 0;     //FAKE   /ELiZ
}

void UUIFrame::UpdateGameSpyPos(int32 pos)
{
}

void UUIFrame::ConnectToGameSpyServer(int32 Index)
{
}

void UUIFrame::SetSettingsValue(FString Value)
{
}
