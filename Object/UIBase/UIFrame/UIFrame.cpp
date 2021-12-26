// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"

UUIFrame::UUIFrame()
{
	_bToolTipActive = true;
}

//const kResX = 800.0;
//const kResY = 600.0;

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
	/*
	if (_iOldSizeX == Canvas.SizeX && _iOldSizeY == Canvas.SizeY)
	{
		Return;
	}
	fScaleX = Canvas.SizeX / 800;
	fScaleY = Canvas.SizeY / 600;
	if (_bAllowScaling)
	{
		offset.X = _Pos.X * fScaleX;
		offset.Y = _Pos.Y * fScaleY;
	}
	else
	{
		if (Canvas.SizeX >= 800 && Canvas.SizeY >= 600)
		{
			offset.X = Canvas.SizeX - 800 / 2;
			offset.Y = Canvas.SizeY - 600 / 2;
		}
	}
	screen = cScreenList;
	if (screen != None)
	{
		screen.ScaleControls(Canvas);
		screen = screen.cNextScreen;
	}
	if (cMouse != None)
	{
		cMouse.ScaleControl(Canvas);
	}
	if (_bAllowScaling)
	{
		_ScaledToolTipLoc.X = _ToolTipLoc.X * fScaleX + offset.X;
		_ScaledToolTipLoc.Y = _ToolTipLoc.Y * fScaleY + offset.Y;
	}
	else
	{
		_ScaledToolTipLoc.X = _ToolTipLoc.X + offset.X;
		_ScaledToolTipLoc.Y = _ToolTipLoc.Y + offset.Y;
	}
	_iOldSizeX = Canvas.SizeX;
	_iOldSizeY = Canvas.SizeY;
	*/
}
void UUIFrame::Create(AHUD* pHUD)
{
	cHUD = pHUD;
	SetupFonts();
	//cInvDef = UIInvDef(CreateUIObject("AGP_UI.UIInvDef"));
}

bool UUIFrame::KeyType(int32 Key)
{
	if (_bMessageBox)
	{
		if (cMessageBox != nullptr)
		{
			//return cMessageBox.KeyType(Key);
		}
	}
	if (cFocus != nullptr)
	{
		//return cFocus.KeyType(Key);
	}
	if (cStaticScreen != nullptr)
	{
		//return cStaticScreen.KeyType(Key);
	}
	if (cTitleScreen != nullptr)
	{
		//return cTitleScreen.KeyType(Key);
	}
	if (cSubScreen != nullptr)
	{
		//return cSubScreen.KeyType(Key);
	}
	if (cActiveScreen != nullptr)
	{
		//return cActiveScreen.KeyType(Key);
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
	/*
	local int i;
	local Font oldfont;
	local Object.Color OldColor;
	local int oldstyle;
	oldfont = Canvas.Font;
	OldColor = Canvas.DrawColor;
	oldstyle = Canvas.Style;
	Canvas.Font = GetProperSizeFont(Canvas);
	ScaleControls(Canvas);
	Canvas.Style = 1;
	i = 1;
	if (cStaticScreen != None)
	{
		cStaticScreen.DrawScreen(Canvas, True);
		if (cActiveScreen != None)
		{
			Canvas.SetPos(111 + offset.X, 65 + offset.Y);
			OldColor = Canvas.DrawColor;
			oldfont = Canvas.Font;
			Canvas.SetDrawColor(196, 190, 141);
			Canvas.Font = Fonts[4];
			Canvas.DrawText(cActiveScreen._sTitle, , -90);
			Canvas.Font = oldfont;
			Canvas.DrawColor = OldColor;
		}
	}
	if (cTitleScreen != None)
	{
		cTitleScreen.DrawScreen(Canvas, True);
	}
	if (cSubScreen != None)
	{
		cSubScreen.DrawScreen(Canvas, True);
	}
	Canvas.DrawColor = OldColor;
	Canvas.Style = oldstyle;
	if (cActiveScreen != None)
	{
		if (_bMessageBox)
		{
			cActiveScreen.DrawScreen(Canvas, False);
			if (cMessageBox != None)
			{
				cMessageBox.DrawScreen(Canvas, True);
				_bMessageBoxVisible = true;
			}
			else
			{
				_bMessageBoxVisible = False;
			}
		}
		else
		{
			cActiveScreen.DrawScreen(Canvas, True);
			_bMessageBoxVisible = False;
		}
	}
	if (cMouse != None)
	{
		Canvas.Style = 6;
		cMouse.Draw(Canvas);
	}
	if (cFocus != None)
	{
		cFocus.MouseMove(cMouse.iMouseX, cMouse.iMouseY);
	}
	if (_bToolTipActive)
	{
		if (_cMouseOver != None)
		{
			Canvas.SetPos(_ScaledToolTipLoc.X, _ScaledToolTipLoc.Y);
			Canvas.DrawText(_cMouseOver.GetToolTip());
		}
	}
	Canvas.Font = oldfont;
	*/
}
void UUIFrame::Notify(int32 pUIEvent)
{
}
void UUIFrame::CreateUIListItems(FString ListItemsName)
{
	/*
	local UIListItems myListItems;
	local class<UIListItems>  cUIListItems;
	cUIListItems = class<UIListItems>(DynamicLoadObject(ListItemsName, Class'Class'));
	myListItems = new (None) classcUIListItems;
	return myListItems;
	*/
}
void UUIFrame::CreateUIInvList(FString ListName)
{
	/*
	local UIInvList MyList;
	local class<UIInvList>  cUIInvList;
	cUIInvList = class<UIInvList>(DynamicLoadObject(ListName, Class'Class'));
	MyList = new (None) classcUIInvList;
	return MyList;
	*/
}
void UUIFrame::CreateUIControl(FString ControlName)
{
	/*
	local UIControl myControl;
	local class<UIControl>  cUIControl;
	cUIControl = class<UIControl>(DynamicLoadObject(ControlName, Class'Class'));
	myControl = new (None) classcUIControl;
	return myControl;
	*/
}
void UUIFrame::CreateUIMouse(FString MouseName)
{
	/*
	local UIMouse myMouse;
	local class<UIMouse>  cUIMouse;
	cUIMouse = class<UIMouse>(DynamicLoadObject(MouseName, Class'Class'));
	myMouse = new (None) classcUIMouse;
	return myMouse;
	*/
}

void UUIFrame::AddMouse(FString szMouse, int32 pX, int32 pY, int32 pW, int32 pH, FString szTex)
{
/*
	cMouse = CreateUIMouse(szMouse);
	cMouse._Pos.X = pX;
	cMouse._Pos.Y = pY;
	cMouse._Pos.W = pW;
	cMouse._Pos.H = pH;
	cMouse.SetBitmapString(szTex);
	cMouse.Create(Self, None, 0, 0, 0);
*/
}

void UUIFrame::SetFocus(UUIControl* Control)
{
	/*
	if (cFocus != None && cFocus != Control)
	{
		cFocus.Focus(False);
	}
	cFocus = Control;
	if (cFocus != None)
	{
		cFocus.Focus(True);
	}
	*/
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

void UUIFrame::GetLargeFont()
{
	//Return Fonts[2];
}

void UUIFrame::GetProperSizeFont(UCanvas* Canvas)
{
	/*
	if (_bAllowScaling)
	{
		if (Canvas.SizeX <= 640)
		{
			return Fonts[0];
		}
		else
		{
			if (Canvas.SizeX <= 800)
			{
				return Fonts[1];
			}
			else
			{
				if (Canvas.SizeX <= 1024)
				{
					return Fonts[2];
				}
				else
				{
					if (Canvas.SizeX <= 1280)
					{
						return Fonts[3];
					}
					else
					{
						if (Canvas.SizeX <= 1600)
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
	*/
}

void UUIFrame::GetProperSizeFontPrivate(UCanvas* Canvas)
{
	/*
	if (Canvas.SizeX <= 640)
	{
		return Fonts[0];
	}
	else
	{
		if (Canvas.SizeX <= 800)
		{
			return Fonts[1];
		}
		else
		{
			if (Canvas.SizeX <= 1024)
			{
				return Fonts[2];
			}
			else
			{
				if (Canvas.SizeX <= 1280)
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
	*/
}

void UUIFrame::DumpScreenLog()
{
	/*
	local UIScreen screen;
	local int i;
	UILog("#### DUMP SCREEN LOG START ####");
	screen = cScreenList;
	if (screen != None)
	{
		UILog("screen #" $ i $ " is ID " $ screen.GetID());
		screen = screen.cNextScreen;
		i++;
	}
	UILog("#### DUMP SCREEN LOG END ####");
	*/
}

void UUIFrame::UILog(FString S)
{
	if (_bDebug)
	{
		//Log(S);
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
	/*
	screen = CreateUIScreen("AGP_UI.UIScreen");
	screen.Create(Self, pID, Title);
	UILog("AddScreen " $ pID $ " result: " $ screen);
	*/
	if (screen == nullptr)
	{
		UILog("ERROR screen == nullptr");
	}
	AddScreenToTail(screen);
}

UUIScreen* UUIFrame::GetScreen(int32 Id)
{
	UUIScreen* screen = nullptr;
	screen = cScreenList;
	if (screen != nullptr)
	{
		if (screen->GetID() == Id)
		{
			return screen;
		}
		screen = screen->cNextScreen;
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
	screen = cScreenList;
	if (screen != nullptr)
	{
		if (screen->cNextScreen == nullptr)
		{
			return screen;
		}
		screen = screen->cNextScreen;
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
	//_InvItem.iItemID = Item;
}
void UUIFrame::GetItemID()
{
	//return _InvItem.iItemID;
}
void UUIFrame::GetItemSize()
{
	//Return cInvDef.GetItemSize(_InvItem.iItemID);
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
	if (screen != nullptr)
	{
		if (screen->EnableControl(Id, State))
		{
			return;
		}
		screen = screen->cNextScreen;
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
void UUIFrame::GetLastDrawTime()
{
	//Return cHUD.Level.RealSeconds;
}
void UUIFrame::AddMessageBox()
{
	UUIScreen* screen = nullptr;
	screen = CreateUIScreen("AGP_UI.UIScreen");
	screen->Create(this, 0, "MessageBox");
	//UILog("AddMessageBox " $ 0 $ " result: " $ screen);
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
void UUIFrame::GetClientBeacon()
{
}
void UUIFrame::GetCurrentServerBrowser()
{
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
void UUIFrame::GetDesiredX()
{
}
void UUIFrame::GetDesiredY()
{
}
void UUIFrame::SetSkinTone()
{
}
void UUIFrame::SetGameSpyPos(int32 pos)
{
}
void UUIFrame::GetGameSpyPos()
{
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
