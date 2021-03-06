// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIPlayerList/UIPlayerList.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"
#include "Engine/Canvas.h"

UUIPlayerList::UUIPlayerList()
{
	Ordered.SetNum(80);
	_iSelected = -1;
	//DevIcons(0) = nullptr
	//DevIcons(1) = Texture'T_AA2_UI.HUD.hud_icon_dev'
	//DevIcons(2) = Texture'T_AA2_UI.HUD.hud_icon_dev_army'
	fDevColorGreenDelta = -2.5;
	fDevColorGreen = 255;

}

void UUIPlayerList::MouseMove(int32 mX, int32 mY)
{
	/*
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
			_iNumOver = mY - _ScaledPos.Y / 16;
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
	*/
}
bool UUIPlayerList::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	int32 iSelected;
	int32 pos;
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
					if (_iNumPlayers > 0)
					{
						iSelected = _iNumOver + _iFirstPlayer;
						if (iSelected >= PlayerCount)
						{
							iSelected = 0;
						}
						SetSelectedPlayer(iSelected);
					}
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
	if (Key == 236 && Action == 3)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			pos = cFrame->GetGameSpyPos();
			cFrame->UpdateGameSpyPos(pos - 1);
			return true;
		}
	}
	if (Key == 237 && Action == 3)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			pos = cFrame->GetGameSpyPos();
			cFrame->UpdateGameSpyPos(pos + 1);
			return true;
		}
	}
	*/
	return false;
}
void UUIPlayerList::UpdatePlayerList()
{
	int32 i = 0;
	ALevelInfo* LI = nullptr;
	AAA2_PlayerState* PRI = nullptr;
	/*
	LI = cFrame->cHUD.Level;
	if (LI == nullptr)
	{
		return;
	}
	if (LI.TimeSeconds - fLastPlayerUpdateTime < 0.5)
	{
		return;
	}
	fLastPlayerUpdateTime = LI.TimeSeconds;
	for (i = 0; i < 80; i++)
	{
		Ordered[i] = nullptr;
	}
	PlayerCount = 0;
	ForEach LI.AllActors(APlayerReplicationInfo::StaticClass(), PRI)
	{
		if (!PRI.bIsSpectator || PRI.bWaitingPlayer)
		{
			Ordered[PlayerCount] = PRI;
			PlayerCount++;
			if (PlayerCount == 80)
			{
			}
		}
		else
		{
		}
	}
	*/
}
void UUIPlayerList::Draw(UCanvas* Canvas)
{
	UFont* temp_font = nullptr;
	int32 old_style = 0;
	FColor OldColor = FColor(0, 0, 0, 0);
	FColor NewColor = FColor(0, 0, 0, 0);
	FColor DevColor = FColor(0,0,0,0);
	int32 i = 0;
	ALevelInfo* LI = nullptr;
	int32 Index = 0;
	AAA2_PlayerState* PRI = nullptr;
	int32 fOffset = 0;
	/*
	if (!_bEnabled)
	{
		_iFirstPlayer = -1;
		_iSelected = -1;
		_iNumPlayers = 0;
		return;
	}
	LI = cFrame->cHUD.Level;
	if (LI == nullptr)
	{
		_iFirstPlayer = -1;
		_iSelected = -1;
		_iNumPlayers = 0;
		return;
	}
	UpdatePlayerList();
	old_style = Canvas.Style;
	Canvas.Style = 1;
	OldColor.R = Canvas.DrawColor.R;
	OldColor.G = Canvas.DrawColor.G;
	OldColor.B = Canvas.DrawColor.B;
	temp_font = Canvas.Font;
	Canvas.Font = cFrame->Fonts[0];
	Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
	Canvas.DrawTile(_tBackground, _ScaledPos.W, _ScaledPos.H, 0, 0, 32, 32);
	NewColor.R = Canvas.DrawColor.R;
	NewColor.G = Canvas.DrawColor.G;
	NewColor.B = Canvas.DrawColor.B;
	DevColor.R = 0;
	DevColor.B = 0;
	DevColor.G = 0;
	_iNumPlayers = 0;
	for (i = 0; i < 16; i++)
	{
		Index = i + iCurrPage * 16;
		if (Ordered[Index] != nullptr)
		{
			fOffset = 0;
			if (Index == _iSelected)
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + i * 16);
				Canvas.DrawTile(_tSelected, _ScaledPos.W, 16, 0, 0, 16, 16);
			}
			PRI = Ordered[Index];
			if (PRI != nullptr && DevIcons[PRI.GetGroup()] != nullptr)
			{
				fDevColorGreen += fDevColorGreenDelta;
				if (fDevColorGreen > 255)
				{
					fDevColorGreenDelta = -fDevColorGreenDelta;
					fDevColorGreen = 255;
				}
				else
				{
					if (fDevColorGreen < 120)
					{
						fDevColorGreenDelta = -fDevColorGreenDelta;
						fDevColorGreen = 120;
					}
				}
				DevColor.G = fDevColorGreen;
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + i * 16);
				Canvas.DrawTile(DevIcons[PRI.GetGroup()], 12, 12, 0, 0, 32, 32);
				Canvas.DrawColor.R = DevColor.R;
				Canvas.DrawColor.G = DevColor.G;
				Canvas.DrawColor.B = DevColor.B;
				fOffset = 26;
				Canvas.SetPos(_ScaledPos.X + fOffset, _ScaledPos.Y + i * 16);
				Canvas.DrawText(Index @ Ordered[Index].PlayerName);
				Canvas.DrawColor.R = NewColor.R;
				Canvas.DrawColor.G = NewColor.G;
				Canvas.DrawColor.B = NewColor.B;
			}
			else
			{
				Canvas.SetPos(_ScaledPos.X + fOffset, _ScaledPos.Y + i * 16);
				Canvas.DrawText(Index @ Ordered[Index].PlayerName);
			}
			_iNumPlayers++;
		}
	}
	Canvas.Font = temp_font;
	Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	Canvas.Style = old_style;
	*/
}

void UUIPlayerList::CreateTexture()
{
	//_tSelected = Texture(DynamicLoadObject("T_AA2_UI.menu.hud2_menu_greyfill_dk", Class'Texture'));
	//_tBackground = Texture(DynamicLoadObject("T_AA2_UI.menu.hud_menu_blackfill", Class'Texture'));
}

int32 UUIPlayerList::GetSelected()
{
	return _iSelected;
}

void UUIPlayerList::SetSelectedPlayer(int32 selected)
{
	_iSelected = selected;
}
FString UUIPlayerList::GetSelectedPlayer()
{
	FString szPlayer="";
	/*
	
	if (_iSelected != -1)
	{
		szPlayer = Ordered[_iSelected].PlayerName;
	}
	*/
	return szPlayer;
}
void UUIPlayerList::PrevPage()
{
	/*
	int32 num_pages;
	num_pages = PlayerCount / 16 + 1 + 1;
	if (num_pages > 1)
	{
		iCurrPage--;
		if (iCurrPage < 0)
		{
			iCurrPage = 0;
		}
	}
	else
	{
		iCurrPage = 0;
	}
	_iFirstPlayer = iCurrPage * 16;
	*/
}
void UUIPlayerList::NextPage()
{
	/*
	int32 num_pages;
	num_pages = PlayerCount / 16 + 1 + 1;
	if (num_pages > 1)
	{
		iCurrPage++;
		if (iCurrPage >= num_pages)
		{
			iCurrPage = num_pages - 1;
		}
		if (iCurrPage >= 4)
		{
			iCurrPage = 4 - 1;
		}
	}
	else
	{
		iCurrPage = 0;
	}
	_iFirstPlayer = iCurrPage * 16;
	*/
}
