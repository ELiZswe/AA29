// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIMenu/UIMenu.h"

UUIMenu::UUIMenu()
{
	//	\\_ToolTipLoc =
	_bAllowScaling = false;
}


void UUIMenu::Destroyed()
{
	/*
	local UIMenuItem menuitem;
	local UIMenuItem nextmenuitem;
	Destroyed();
	cNextMenu = None;
	cPrevMenu = None;
	cFocus = None;
	cActiveItem = None;
	cLastMenuItem = None;
	menuitem = cFirstMenuItem;
	if (menuitem != None)
	{
		nextmenuitem = menuitem.cNextItem;
		menuitem.Destroyed();
		menuitem = nextmenuitem;
	}
	cFirstMenuItem = None;
	*/
}
void UUIMenu::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	local UIMenuItem menuitem;
	if (cFocus != None)
	{
		if (cFocus.ProcessKeyEvent(Key, Action, Delta))
		{
			Return True;
		}
	}
	menuitem = cFirstMenuItem;
	if (menuitem != None)
	{
		if (menuitem.ProcessKeyEvent(Key, Action, Delta))
		{
			Return True;
		}
		menuitem = menuitem.cNextItem;
	}
	Return False;
	*/
}
void UUIMenu::MouseMove(int32 mX, int32 mY)
{
	/*
	local UIMenuItem menuitem;
	cActiveItem = None;
	menuitem = cFirstMenuItem;
	if (menuitem != None)
	{
		menuitem.MouseMove(mX, mY);
		menuitem = menuitem.cNextItem;
	}
	*/
}
void UUIMenu::Draw(UCanvas* Canvas)
{
	/*
	local UIMenuItem menuitem;
	local int i;
	Canvas.Style = 1;
	i = 1;
	menuitem = cFirstMenuItem;
	if (menuitem != None)
	{
		if (_bDebug)
		{
			Canvas.DrawText("UIMenu - Drawing control " $ i);
		}
		menuitem.Draw(Canvas);
		menuitem = menuitem.cNextItem;
		i++;
	}
	i--;
	if (cActiveItem != None)
	{
		Canvas.SetPos(_ToolTipLoc.X, _ToolTipLoc.Y);
		Canvas.DrawText(cActiveItem.GetToolTip());
	}
	if (_bDebug)
	{
		Canvas.SetPos(0, 100);
		Canvas.DrawText("UIMenu - Controls drawn: " $ i);
		Canvas.DrawText("cFirstMenuItem ID: " $ cFirstMenuItem.GetID());
		Canvas.DrawText("cLastMenuItem ID : " $ cLastMenuItem.GetID());
	}
	*/
}
void UUIMenu::CreateUIMenuItem(FString ControlName)
{
	/*
	local UIMenuItem myMenuItem;
	local class<UIMenuItem>  cUIMenuItem;
	cUIMenuItem = class<UIMenuItem>(DynamicLoadObject(ControlName, Class'Class'));
	myMenuItem = new (None) classcUIMenuItem;
	Return myMenuItem;
	*/
}
void UUIMenu::AddMenuItem(FString sItem, int32 pID, int32 pUIEvent, FPosition pPos, FString tString, int32 pParams, FString sToolTip)
{
	/*
	local UIMenuItem menuitem;
	menuitem = CreateUIMenuItem(sItem);
	menuitem._Pos.X = pPos.X;
	menuitem._Pos.Y = pPos.Y;
	menuitem._Pos.W = pPos.W;
	menuitem._Pos.H = pPos.H;
	menuitem.SetTextureString(tString);
	menuitem.Create(cFrame, cScreen, pID, pUIEvent, pParams);
	menuitem.SetParentMenu(Self);
	menuitem.SetAllowScaling(_bAllowScaling);
	menuitem.SetTooltip(sToolTip);
	if (cFirstMenuItem == None)
	{
		cFirstMenuItem = menuitem;
		cLastMenuItem = menuitem;
	}
	else
	{
		cLastMenuItem.cNextItem = menuitem;
		menuitem.cPrevItem = cLastMenuItem;
		cLastMenuItem = menuitem;
	}
	*/
}
void UUIMenu::ScaleControl(UCanvas* Canvas)
{
	/*
	local UIMenuItem menuitem;
	ScaleControl(Canvas);
	menuitem = cFirstMenuItem;
	if (menuitem != None)
	{
		menuitem.ScaleControl(Canvas);
		menuitem = menuitem.cNextItem;
	}
	*/
}
FPoint UUIMenu::GetToolTipLocation()
{
	return _ToolTipLoc;
}
void UUIMenu::SetToolTipLocation(FPoint pLoc)
{
	_ToolTipLoc = pLoc;
}