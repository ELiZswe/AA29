// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UIQuickLan/UIQuickLan.h"

UUIQuickLan::UUIQuickLan()
{

}


void UUIQuickLan::MouseMove(int32 mX, int32 mY)
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
			_iNumOver = mY - _ScaledPos.Y / 20;
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
bool UUIQuickLan::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
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
					ConnectToLanServer();
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
	*/
	return false;
}

void UUIQuickLan::Draw(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local int old_style;
	local Object.Color OldColor;
	local IpDrv.ClientBeaconReceiver ClientBeacon;
	local int i;
	local string Server;
	if (!_bEnabled)
	{
		Return;
	}
	ClientBeacon = cFrame.GetClientBeacon();
	if (ClientBeacon == None)
	{
		Return;
	}
	old_style = Canvas.Style;
	Canvas.Style = 1;
	OldColor.R = Canvas.DrawColor.R;
	OldColor.G = Canvas.DrawColor.G;
	OldColor.B = Canvas.DrawColor.B;
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.Fonts[2];
	for (i = 0; i < 8; i++)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + i * 20);
		if (_iNumOver == i)
		{
			Canvas.SetDrawColor(255, 255, 255);
		}
		else
		{
			Canvas.SetDrawColor(196, 190, 141);
		}
		Server = ClientBeacon.GetBeaconText(i);
		if (Server != "")
		{
			Canvas.DrawText(ClientBeacon.GetBeaconAddress(i) $ " - " $ ClientBeacon.GetBeaconText(i));
		}
		else
		{
			Canvas.DrawText("-");
		}
	}
	Canvas.Font = temp_font;
	Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	Canvas.Style = old_style;
	*/
}
void UUIQuickLan::ConnectToLanServer()
{
	/*
	local IpDrv.ClientBeaconReceiver ClientBeacon;
	local int Addr;
	ClientBeacon = cFrame.GetClientBeacon();
	if (ClientBeacon == None)
	{
		Return;
	}
	Addr = ClientBeacon.GetBeaconAddressAddr(_iNumOver);
	if (Addr != 0)
	{
		cFrame.OpenQuickLan(ClientBeacon.GetBeaconAddress(_iNumOver));
	}
	*/
}
