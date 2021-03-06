// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIMenu/UIMenu.h"
#include "AA29/Object/UIBase/UIControl/UIMenuItem/UIMenuItem.h"
#include "Engine/Canvas.h"

UUIMenu::UUIMenu()
{
	_bAllowScaling = false;
}

void UUIMenu::Destroyed()
{
	UUIMenuItem* menuitem = nullptr;
	UUIMenuItem* nextmenuitem = nullptr;
	Super::Destroyed();
	cNextMenu = nullptr;
	cPrevMenu = nullptr;
	cFocus = nullptr;
	cActiveItem = nullptr;
	cLastMenuItem = nullptr;
	menuitem = cFirstMenuItem;
	if (menuitem != nullptr)
	{
		nextmenuitem = menuitem->cNextItem;
		menuitem->Destroyed();
		menuitem = nextmenuitem;
	}
	cFirstMenuItem = nullptr;
}

bool UUIMenu::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	UUIMenuItem* menuitem = nullptr;
	if (cFocus != nullptr)
	{
		if (cFocus->ProcessKeyEvent(Key, Action, Delta))
		{
			return true;
		}
	}
	for (menuitem = cFirstMenuItem; menuitem != nullptr; menuitem = menuitem->cNextItem)
	{
		if (menuitem->ProcessKeyEvent(Key, Action, Delta))
		{
			return true;
		}
	}
	return false;
}

void UUIMenu::MouseMove(int32 mX, int32 mY)
{
	UUIMenuItem* menuitem = nullptr;
	cActiveItem = nullptr;
	for (menuitem = cFirstMenuItem; menuitem != nullptr; menuitem = menuitem->cNextItem)
	{
		menuitem->MouseMove(mX, mY);
	}
}

void UUIMenu::Draw(UCanvas* Canvas)
{
	UUIMenuItem* menuitem = nullptr;
	int32 i = 0;
	/*
	Canvas.Style = 1;
	i = 1;
	menuitem = cFirstMenuItem;
	if (menuitem != nullptr)
	{
		if (_bDebug)
		{
			Canvas.DrawText("UIMenu - Drawing control " + i);
		}
		menuitem.Draw(Canvas);
		menuitem = menuitem.cNextItem;
		i++;
	}
	i--;
	if (cActiveItem != nullptr)
	{
		Canvas.SetPos(_ToolTipLoc.X, _ToolTipLoc.Y);
		Canvas.DrawText(cActiveItem.GetToolTip());
	}
	if (_bDebug)
	{
		Canvas.SetPos(0, 100);
		Canvas.DrawText("UIMenu - Controls drawn: " + i);
		Canvas.DrawText("cFirstMenuItem ID: " + cFirstMenuItem.GetID());
		Canvas.DrawText("cLastMenuItem ID : " + cLastMenuItem.GetID());
	}
	*/
}

UUIMenuItem* UUIMenu::CreateUIMenuItem(FString ControlName)
{
	UUIMenuItem* myMenuItem = nullptr;
	UUIMenuItem* cUIMenuItem = nullptr;
	//cUIMenuItem = class<UIMenuItem>(DynamicLoadObject(ControlName, Class'Class'));
	//myMenuItem = new (nullptr) classcUIMenuItem;
	return myMenuItem;
}

void UUIMenu::AddMenuItem(FString sItem, int32 pID, int32 pUIEvent, FPosition pPos, FString tString, int32 pParams, FString sToolTip)
{
	UUIMenuItem* menuitem = nullptr;
	menuitem = CreateUIMenuItem(sItem);
	menuitem->_Pos.X = pPos.X;
	menuitem->_Pos.Y = pPos.Y;
	menuitem->_Pos.W = pPos.W;
	menuitem->_Pos.H = pPos.H;
	menuitem->SetTextureString(tString);
	menuitem->Create(cFrame, cScreen, pID, pUIEvent, pParams);
	menuitem->SetParentMenu(this);
	menuitem->SetAllowScaling(_bAllowScaling);
	menuitem->SetTooltip(sToolTip);
	if (cFirstMenuItem == nullptr)
	{
		cFirstMenuItem = menuitem;
		cLastMenuItem = menuitem;
	}
	else
	{
		cLastMenuItem->cNextItem = menuitem;
		menuitem->cPrevItem = cLastMenuItem;
		cLastMenuItem = menuitem;
	}
}

void UUIMenu::ScaleControl(UCanvas* Canvas)
{
	UUIMenuItem* menuitem = nullptr;
	Super::ScaleControl(Canvas);
	for (menuitem = cFirstMenuItem; menuitem != nullptr; menuitem = menuitem->cNextItem)
	{
		menuitem->ScaleControl(Canvas);
	}
}
FPoint UUIMenu::GetToolTipLocation()
{
	return _ToolTipLoc;
}
void UUIMenu::SetToolTipLocation(FPoint pLoc)
{
	_ToolTipLoc = pLoc;
}
