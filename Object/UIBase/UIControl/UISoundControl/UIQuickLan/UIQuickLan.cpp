// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UIQuickLan/UIQuickLan.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpBeacon/ClientBeaconReceiver/ClientBeaconReceiver.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"
#include "Engine/Canvas.h"

UUIQuickLan::UUIQuickLan()
{

}

void UUIQuickLan::MouseMove(int32 mX, int32 mY)
{
	if (!_bEnabled)
	{
		return;
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
				cFrame->PlayMenuSoundSpecific(_sMouseOver);
			}
		}
		if (!cFrame->SetMouseOver(this))
		{
			_iState = 0;
		}
	}
	else
	{
		_iState = 0;
		_bButtonDown = false;
		_bFirstOver = false;
		_iNumOver = -1;
	}
}

bool UUIQuickLan::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	if (!_bEnabled)
	{
		return false;
	}
	if (Key == 13)
	{
		if (cFrame->_cMouseOver == this)
		{
			cFrame->Notify(_iUIEvent);
			return true;
		}
	}
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				_bButtonDown = true;
				_iState = 2;
				cFrame->PlayMenuSoundSpecific(_sMouseClick);
			}
			if (Action == 3)
			{
				if (_bButtonDown == true)
				{
					_bButtonDown = false;
					_iState = 1;
					ConnectToLanServer();
				}
			}
			return true;
		}
		if (_bButtonDown == true && Action == 3 && cFrame->cFocus == this)
		{
			_bButtonDown = false;
			cFrame->SetFocus(nullptr);
			return true;
		}
	}
	return false;
}

void UUIQuickLan::Draw(UCanvas* Canvas)
{
	UFont* temp_font = nullptr;
	int32 old_style = 0;
	FColor OldColor = FColor(0, 0, 0, 0);
	AClientBeaconReceiver* ClientBeacon = nullptr;
	int32 i = 0;
	FString Server = "";
	if (!_bEnabled)
	{
		return;
	}
	ClientBeacon = cFrame->GetClientBeacon();
	if (ClientBeacon == nullptr)
	{
		return;
	}
	//old_style = Canvas.Style;
	//Canvas.Style = 1;
	//OldColor.R = Canvas.DrawColor.R;
	//OldColor.G = Canvas.DrawColor.G;
	//OldColor.B = Canvas.DrawColor.B;
	//temp_font = Canvas.Font;
	//Canvas.Font = cFrame->Fonts[2];
	for (i = 0; i < 8; i++)
	{
		//Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + i * 20);
		if (_iNumOver == i)
		{
			//Canvas.SetDrawColor(255, 255, 255);
		}
		else
		{
			//Canvas.SetDrawColor(196, 190, 141);
		}
		Server = ClientBeacon->GetBeaconText(i);
		if (Server != "")
		{
			//Canvas->DrawText(ClientBeacon->GetBeaconAddress(i) + " - " + ClientBeacon->GetBeaconText(i));
		}
		else
		{
			//Canvas->DrawText("-");
		}
	}
	//Canvas.Font = temp_font;
	//Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	//Canvas.Style = old_style;
}

void UUIQuickLan::ConnectToLanServer()
{
	AClientBeaconReceiver* ClientBeacon = nullptr;
	int32 Addr = 0;
	ClientBeacon = cFrame->GetClientBeacon();
	if (ClientBeacon == nullptr)
	{
		return;
	}
	Addr = ClientBeacon->GetBeaconAddressAddr(_iNumOver);
	if (Addr != 0)
	{
		cFrame->OpenQuickLan(ClientBeacon->GetBeaconAddress(_iNumOver));
	}
}
