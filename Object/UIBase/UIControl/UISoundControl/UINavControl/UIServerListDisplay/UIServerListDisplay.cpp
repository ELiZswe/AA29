// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIServerListDisplay/UIServerListDisplay.h"

UUIServerListDisplay::UUIServerListDisplay()
{
	_iFirstServer = -1;
	_iSelected = -1;
}


void UUIServerListDisplay::MouseMove(int32 mX, int32 mY)
{
	/*
	if (!_bEnabled)
	{
		Return;
	}
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		if (_bButtonDown)
		{
			_iState = 2;
		}
		else
		{
			_iState = 1;
			_iNumOver = mY - _ScaledPos.Y / 16;
			if (!_bFirstOver)
			{
				_bFirstOver = true;
				cFrame.PlayMenuSoundSpecific(_sMouseOver);
			}
		}
		if (!cFrame.SetMouseOver(Self))
		{
			_iState = 0;
		}
	}
	else
	{
		_iState = 0;
		_bButtonDown = False;
		_bFirstOver = False;
		_iNumOver = -1;
	}
	*/
}
bool UUIServerListDisplay::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	local int iSelected;
	local int pos;
	local float fCurrentClickTime;
	if (!_bEnabled)
	{
		Return False;
	}
	if (Key == 13)
	{
		if (cFrame._cMouseOver == Self)
		{
			cFrame.Notify(_iUIEvent);
			Return True;
		}
	}
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				_bButtonDown = true;
				_iState = 2;
				cFrame.PlayMenuSoundSpecific(_sMouseClick);
			}
			if (Action == 3)
			{
				if (_bButtonDown == True)
				{
					_bButtonDown = False;
					_iState = 1;
					if (_iNumServers > 0)
					{
						iSelected = _iNumOver + _iFirstServer;
						if (iSelected >= _iNumServers)
						{
							iSelected = 0;
						}
						SetSelectedServer(iSelected);
						fCurrentClickTime = cFrame.cHUD.Level.RealSeconds;
						if (fCurrentClickTime - fLastClickTime <= 0.3)
						{
							cFrame.ConnectToGameSpyServer(_iSelected);
						}
						fLastClickTime = fCurrentClickTime;
					}
				}
			}
			Return True;
		}
		if (_bButtonDown == True && Action == 3 && cFrame.cFocus == Self)
		{
			_bButtonDown = False;
			cFrame.SetFocus(None);
			Return True;
		}
	}
	if (Key == 236 && Action == 3)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			pos = cFrame.GetGameSpyPos();
			cFrame.UpdateGameSpyPos(pos - 1);
			Return True;
		}
	}
	if (Key == 237 && Action == 3)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			pos = cFrame.GetGameSpyPos();
			cFrame.UpdateGameSpyPos(pos + 1);
			Return True;
		}
	}
	*/
	return false;
}
void UUIServerListDisplay::Draw(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local int oldclipx;
	local int oldClipY;
	local int old_style;
	local Object.Color OldColor;
	local ServerBrowserBase.GameSpyServerItem Item;
	local IpDrv.ServerBrowserBase sbBase;
	local int i;
	local int iPos;
	local int iOffset;
	local int NewClipY;
	local int iTempNumServers;
	local bool bSelectedInfoDisplayed;
	local int num_players;
	if (!_bEnabled)
	{
		_iFirstServer = -1;
		_iSelected = -1;
		_iNumServers = 0;
		Return;
	}
	sbBase = cFrame.GetCurrentServerBrowser();
	if (sbBase == None)
	{
		_iFirstServer = -1;
		_iSelected = -1;
		_iNumServers = 0;
		Return;
	}
	_iNumServers = sbBase.GetNumServers();
	if (_iNumServers == 0)
	{
		if (_iSelected != -1)
		{
			_iFirstServer = -1;
			_iSelected = -1;
			sbBase.SetSelectedServer(_iSelected);
		}
		Return;
	}
	iTempNumServers = _iNumServers;
	if (iTempNumServers > 14)
	{
		iTempNumServers -= 14;
	}
	iPos = cFrame.GetGameSpyPos();
	_iFirstServer = iTempNumServers * iPos * 0.01;
	old_style = Canvas.Style;
	Canvas.Style = 1;
	OldColor.R = Canvas.DrawColor.R;
	OldColor.G = Canvas.DrawColor.G;
	OldColor.B = Canvas.DrawColor.B;
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.Fonts[8];
	Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y - 15);
	Canvas.DrawText("Servers: " $ _iNumServers @ "progress:" @ sbBase.GetProgress() $ "%");
	i = 0;
	oldclipx = Canvas.ClipX;
	oldClipY = Canvas.ClipY;
	Canvas.SetDrawColor(255, 255, 255);
	ForEach sbBase.AllServersInRange(Item, _iFirstServer, _iFirstServer + 13)
	{
		iOffset = i * 16;
		NewClipY = _ScaledPos.Y + iOffset + 16;
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + iOffset);
		if (Item.bValid != 0)
		{
			Canvas.Style = 6;
			if (Item.Index == _iSelected)
			{
				Canvas.DrawTile(_tSelected, _ScaledPos.W, 16, 0, 0, 16, 16);
				DisplaySelectedInfo(Canvas, Item, sbBase.IpAddrToString(Item.IP, Item.Port));
				num_players = Item.NumPlayers;
				DisplaySelectedPlayers(Canvas, sbBase, _iSelected, num_players);
				bSelectedInfoDisplayed = true;
			}
			if (Item.bLeased == 1)
			{
				if (Item.bOfficial == 1)
				{
					Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + iOffset);
					Canvas.DrawTile(_tLeasedOfficial, 16, 16, 0, 0, 16, 16);
				}
				else
				{
					Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + iOffset);
					Canvas.DrawTile(_tLeased, 16, 16, 0, 0, 16, 16);
				}
			}
			else
			{
				if (Item.bOfficial == 1)
				{
					Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + iOffset);
					Canvas.DrawTile(_tOfficial, 16, 16, 0, 0, 16, 16);
				}
			}
			if (Item.bMiles == 1)
			{
				Canvas.SetPos(_ScaledPos.X + 16, _ScaledPos.Y + iOffset);
				Canvas.DrawTile(_tMiles, 16, 16, 0, 0, 16, 16);
			}
			if (Item.bPassword == 1)
			{
				Canvas.SetPos(_ScaledPos.X + 32, _ScaledPos.Y + iOffset);
				Canvas.DrawTile(_tPassword, 16, 16, 0, 0, 16, 16);
			}
			Canvas.SetPos(_ScaledPos.X + 64, _ScaledPos.Y + iOffset);
			Canvas.SetClip(_ScaledPos.X + 300, NewClipY);
			Canvas.DrawTextClipped(Item.Name);
			Canvas.SetPos(_ScaledPos.X + 325, _ScaledPos.Y + iOffset);
			Canvas.SetClip(_ScaledPos.X + 375, NewClipY);
			Canvas.DrawText(Item.NumPlayers $ "/" $ Item.MaxPlayers);
			Canvas.SetPos(_ScaledPos.X + 375, _ScaledPos.Y + iOffset);
			Canvas.SetClip(_ScaledPos.X + 425, NewClipY);
			Canvas.DrawTextClipped(Item.Ping);
			if (Item.Tour >= 0 && Item.Tour < 32 && _tTour[Item.Tour] != None)
			{
				Canvas.SetPos(_ScaledPos.X + 425, _ScaledPos.Y + iOffset);
				Canvas.SetClip(_ScaledPos.X + 475, NewClipY);
				Canvas.DrawTile(_tTour[Item.Tour], 16, 16, 0, 0, 16, 16);
			}
			Canvas.SetPos(_ScaledPos.X + 475, _ScaledPos.Y + iOffset);
			Canvas.SetClip(_ScaledPos.X + 620, NewClipY);
			Canvas.DrawTextClipped(Item.MapName);
		}
		else
		{
			Canvas.DrawText("Error: Invalid Server Item");
		}
		i++;
	}
	if (!bSelectedInfoDisplayed && _iSelected != -1)
	{
		sbBase.GetSpecificServer(_iSelected, Item);
		if (Item.bValid != 0)
		{
			DisplaySelectedInfo(Canvas, Item, sbBase.IpAddrToString(Item.IP, Item.Port));
			num_players = Item.NumPlayers;
			DisplaySelectedPlayers(Canvas, sbBase, _iSelected, num_players);
		}
	}
	Canvas.SetClip(oldclipx, oldClipY);
	Canvas.Font = temp_font;
	Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	Canvas.Style = old_style;
	*/
}
void UUIServerListDisplay::DisplaySelectedInfo(UCanvas* Canvas, FGameSpyServerItem Item, FString sAddress)
{
	/*
	local Font oldfont;
	oldfont = Canvas.Font;
	Canvas.SetClip(_ScaledPos.X + 310, _ScaledPos.Y + 324);
	Canvas.Font = cFrame.Fonts[0];
	Canvas.SetPos(_ScaledPos.X + 2, _ScaledPos.Y + 240);
	Canvas.DrawTextClipped("hostname:" @ Item.Name);
	Canvas.SetPos(_ScaledPos.X + 2, _ScaledPos.Y + 252);
	Canvas.DrawTextClipped("address: " @ sAddress);
	Canvas.SetPos(_ScaledPos.X + 2, _ScaledPos.Y + 264);
	Canvas.DrawTextClipped("players: " @ Item.NumPlayers $ "/" $ Item.MaxPlayers);
	Canvas.SetPos(_ScaledPos.X + 2, _ScaledPos.Y + 276);
	Canvas.DrawTextClipped("official: " @ Item.bOfficial);
	Canvas.SetPos(_ScaledPos.X + 100, _ScaledPos.Y + 276);
	Canvas.DrawTextClipped("miles:    " @ Item.bMiles);
	Canvas.SetPos(_ScaledPos.X + 202, _ScaledPos.Y + 276);
	Canvas.DrawTextClipped("leased:    " @ Item.bLeased);
	Canvas.SetPos(_ScaledPos.X + 2, _ScaledPos.Y + 288);
	Canvas.DrawTextClipped("minhonor:    " @ Item.MinHonor);
	Canvas.SetPos(_ScaledPos.X + 100, _ScaledPos.Y + 288);
	Canvas.DrawTextClipped("maxhonor:    " @ Item.MaxHonor);
	Canvas.SetPos(_ScaledPos.X + 2, _ScaledPos.Y + 300);
	Canvas.DrawTextClipped("mapname:  " @ Item.MapName);
	Canvas.SetPos(_ScaledPos.X + 2, _ScaledPos.Y + 312);
	Canvas.DrawTextClipped("ping:     " @ Item.Ping);
	Canvas.SetPos(_ScaledPos.X + 100, _ScaledPos.Y + 312);
	Canvas.DrawTextClipped("gamever:     " @ Item.GameVer);
	Canvas.Font = oldfont;
	*/
}
void UUIServerListDisplay::DisplaySelectedPlayers(UCanvas* Canvas, AServerBrowserBase* sbBase, int32 server_index, int32 num_players)
{
	/*
	local Font oldfont;
	local int i;
	local int Position;
	local ServerBrowserBase.GameSpyPlayerInfo player_info;
	if (_iLastSelected != server_index)
	{
		_iFirstPlayer = 0;
	}
	if (_iNavPlayerList != 0)
	{
		if (_iNavPlayerList == 1)
		{
			if (_iFirstPlayer + 7 < num_players)
			{
				_iFirstPlayer += 7;
			}
		}
		else
		{
			if (_iNavPlayerList == -1)
			{
				if (_iFirstPlayer > 0)
				{
					_iFirstPlayer -= 7;
				}
			}
		}
		_iNavPlayerList = 0;
	}
	oldfont = Canvas.Font;
	Canvas.Font = cFrame.Fonts[0];
	Position = 0;
	i = _iFirstPlayer;
	if (i < _iFirstPlayer + 7)
	{
		if (i < num_players)
		{
			Canvas.SetClip(_ScaledPos.X + 630, _ScaledPos.Y + 240 + Position + 1 * 12);
			sbBase.GetPlayerInfo(server_index, i, player_info);
			if (player_info.Name != "")
			{
				Canvas.SetPos(_ScaledPos.X + 320, _ScaledPos.Y + 240 + Position * 12);
				Canvas.DrawText(i);
				Canvas.SetPos(_ScaledPos.X + 336, _ScaledPos.Y + 240 + Position * 12);
				Canvas.DrawText(player_info.Name);
				Canvas.SetPos(_ScaledPos.X + 510, _ScaledPos.Y + 240 + Position * 12);
				Canvas.DrawText(player_info.Enemy);
				Canvas.SetPos(_ScaledPos.X + 540, _ScaledPos.Y + 240 + Position * 12);
				Canvas.DrawText(player_info.KIA);
				Canvas.SetPos(_ScaledPos.X + 570, _ScaledPos.Y + 240 + Position * 12);
				Canvas.DrawText(player_info.ROE);
				Canvas.SetPos(_ScaledPos.X + 600, _ScaledPos.Y + 240 + Position * 12);
				Canvas.DrawTextClipped(player_info.Ping);
			}
			Position++;
		}
		i++;
	}
	_iLastSelected = server_index;
	Canvas.Font = oldfont;
	*/
}
void UUIServerListDisplay::CreateTexture()
{
}

int32 UUIServerListDisplay::GetSelected()
{
	return _iSelected;
}

void UUIServerListDisplay::SetSelectedServer(int32 selected)
{
	/*
	local IpDrv.ServerBrowserBase sbBase;
	local ServerBrowserBase.GameSpyServerItem Item;
	sbBase = cFrame.GetCurrentServerBrowser();
	if (sbBase == None)
	{
		Return;
	}
	sbBase.GetSpecificServer(selected, Item);
	if (Item.bValid != 0)
	{
		_iSelected = selected;
		sbBase.SetSelectedServer(_iSelected);
	}
	else
	{
		Return;
	}
	*/
}
void UUIServerListDisplay::NextPlayerList()
{
	_iNavPlayerList = 1;
}
void UUIServerListDisplay::PrevPlayerList()
{
	_iNavPlayerList = -1;
}