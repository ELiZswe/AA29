// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISettingsList/UISettingsList.h"

UUISettingsList::UUISettingsList()
{
	Type.SetNum(64);
	Value.SetNum(64);
	Setting.SetNum(64);
	Section.SetNum(64);
	_iSelected = -1;
}

void UUISettingsList::MouseMove(int32 mX, int32 mY)
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
bool UUISettingsList::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
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
					if (iNumSettings > 0)
					{
						iSelected = _iNumOver;
						if (iSelected >= iNumSettings)
						{
							iSelected = -1;
						}
						SetSelectedSetting(iSelected);
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

void UUISettingsList::Draw(UCanvas* Canvas)
{
	/*
	UFont* temp_font = nullptr;
	int32 old_style;
	FColor OldColor = FColor(0,0,0,0);
	int32 i = 0;
	int32 Index = 0;
	if (!_bEnabled)
	{
		_iSelected = -1;
		return;
	}
	old_style = Canvas.Style;
	Canvas.Style = 1;
	OldColor.R = Canvas.DrawColor.R;
	OldColor.G = Canvas.DrawColor.G;
	OldColor.B = Canvas.DrawColor.B;
	temp_font = Canvas.Font;
	Canvas.Font = cFrame->Fonts[0];
	Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
	Canvas.DrawTile(_tBackground, _ScaledPos.W, _ScaledPos.H, 0, 0, 32, 32);
	for (i = 0; i < 16; i++)
	{
		Index = i + iCurrPage * 16;
		if (Setting[Index] != "")
		{
			if (Index == _iSelected)
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + i * 16);
				Canvas.DrawTile(_tSelected, _ScaledPos.W, 16, 0, 0, 16, 16);
			}
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + i * 16);
			Canvas.DrawText(Setting[Index] + "=" + Value[Index]);
		}
	}
	Canvas.Font = temp_font;
	Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	Canvas.Style = old_style;
	*/
}
void UUISettingsList::CreateTexture()
{
	//_tSelected = Texture(DynamicLoadObject("T_AA2_UI.menu.hud2_menu_greyfill_dk", Class'Texture'));
	//_tBackground = Texture(DynamicLoadObject("T_AA2_UI.menu.hud_menu_blackfill", Class'Texture'));
}
int32 UUISettingsList::GetSelected()
{
	return _iSelected;
}
void UUISettingsList::ClearList()
{
	/*
	int32 X;
	for (X = 0; X < 64; X++)
	{
		Section[X] = "";
		Setting[X] = "";
		Type[X] = 0;
	}
	iNumSettings = 0;
	*/
}
void UUISettingsList::SetSetting(int32 Index, FString szSection, FString szSetting, FString szValue, int32 iType)
{
	/*
	if (Index < 64 && Index >= 0)
	{
		Section[Index] = szSection;
		Setting[Index] = szSetting;
		Value[Index] = szValue;
		Type[Index] = iType;
		iNumSettings = Index + 1;
	}
	*/
}
void UUISettingsList::UpdateSettingValue(int32 Index, FString szValue)
{
	/*
	if (Index < 64 && Index >= 0)
	{
		Value[Index] = szValue;
	}
	*/
}
void UUISettingsList::SetSelectedSetting(int32 iSetting)
{
	/*
	_iSelected = iSetting + iCurrPage * 16;
	if (_iSelected == -1)
	{
		cFrame->SetSettingsValue("");
	}
	else
	{
		cFrame->SetSettingsValue(Value[_iSelected]);
	}
	*/
}
FString UUISettingsList::GetSelectedSection()
{
	FString szSection="";
	if (_iSelected != -1)
	{
		//szSection = Section[_iSelected];
	}
	return szSection;
}
FString UUISettingsList::GetSelectedSetting()
{
	FString szSetting="";
	if (_iSelected != -1)
	{
		//szSetting = Setting[_iSelected];
	}
	return szSetting;
}

void UUISettingsList::NextPage()
{
	/*
	if (iCurrPage < iNumSettings - 1 / 16 && iCurrPage < 4)
	{
		iCurrPage++;
	}
	*/
}
void UUISettingsList::PrevPage()
{
	/*
	if (iCurrPage > 0)
	{
		iCurrPage--;
	}
	*/
}

int32 UUISettingsList::GetSelectedIndex()
{
	return _iSelected;
}
