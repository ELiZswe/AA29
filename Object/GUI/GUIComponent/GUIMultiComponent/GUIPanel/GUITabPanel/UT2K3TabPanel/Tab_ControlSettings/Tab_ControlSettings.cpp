// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_ControlSettings/Tab_ControlSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_ControlSettings::UTab_ControlSettings()
{
	UGUIButton* KeyResetButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	KeyResetButton->Caption="RESET";
	KeyResetButton->StyleName="SquareMenuButton";
	KeyResetButton->Hint="Reset keys to default values";
	KeyResetButton->WinTop=0.933333;
	KeyResetButton->WinLeft=0.6875;
	KeyResetButton->WinWidth=0.23125;
	KeyResetButton->WinHeight=0.06875;
	//KeyResetButton->OnClick=Tab_ControlSettings.ResetClicked;
	//KeyResetButton->OnKeyEvent=KeyResetButton.InternalOnKeyEvent;
	UGUIListBox* KeyConfigKeyList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	KeyConfigKeyList->bVisibleWhenEmpty=true;
	//KeyConfigKeyList->OnCreateComponent=KeyConfigKeyList.InternalOnCreateComponent;
	KeyConfigKeyList->StyleName="BindBox";
	KeyConfigKeyList->Hint="Select Control to config";
	KeyConfigKeyList->WinTop=0.094218;
	KeyConfigKeyList->WinLeft=0.027188;
	KeyConfigKeyList->WinWidth=0.929493;
	KeyConfigKeyList->WinHeight=0.82004;
	UGUIImage* KeyConfigBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//KeyConfigBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	KeyConfigBK1->ImageColor=FColor(255, 255, 255, 160);
	KeyConfigBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	KeyConfigBK1->WinTop=0.083281;
	KeyConfigBK1->WinLeft=0.021641;
	KeyConfigBK1->WinWidth=0.431248;
	KeyConfigBK1->WinHeight=0.834063;
	KeyConfigBK1->bAcceptsInput=true;
	KeyConfigBK1->bNeverFocus=true;
	UGUIImage* KeyConfigBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//KeyConfigBK2->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	KeyConfigBK2->ImageColor=FColor(255, 255, 255, 160);
	KeyConfigBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	KeyConfigBK2->WinTop=0.083281;
	KeyConfigBK2->WinLeft=0.460078;
	KeyConfigBK2->WinWidth=0.230937;
	KeyConfigBK2->WinHeight=0.834063;
	UGUIImage* KeyConfigBK3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//KeyConfigBK3->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	KeyConfigBK3->ImageColor=FColor(255, 255, 255, 160);
	KeyConfigBK3->ImageStyle = EImgStyle::ISTY_Stretched;
	KeyConfigBK3->WinTop=0.083281;
	KeyConfigBK3->WinLeft=0.688828;
	KeyConfigBK3->WinWidth=0.232499;
	KeyConfigBK3->WinHeight=0.834063;
	UGUILabel* KeyConfigAliasLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	KeyConfigAliasLabel->Caption="Action";
	KeyConfigAliasLabel->TextAlign = ETextAlign::TXTA_Center;
	KeyConfigAliasLabel->TextColor=FColor(255, 255, 255, 255);
	KeyConfigAliasLabel->TextFont="UT2HeaderFont";
	KeyConfigAliasLabel->WinTop=0.004167;
	KeyConfigAliasLabel->WinLeft=0.124414;
	KeyConfigAliasLabel->WinWidth=0.25;
	KeyConfigAliasLabel->WinHeight=32;
	UGUILabel* KeyConfigAliasLabel2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	KeyConfigAliasLabel2->Caption="Key 1";
	KeyConfigAliasLabel2->TextAlign = ETextAlign::TXTA_Center;
	KeyConfigAliasLabel2->TextColor=FColor(255, 255, 255, 255);
	KeyConfigAliasLabel2->TextFont="UT2HeaderFont";
	KeyConfigAliasLabel2->WinTop=0.004167;
	KeyConfigAliasLabel2->WinLeft=0.449414;
	KeyConfigAliasLabel2->WinWidth=0.25;
	KeyConfigAliasLabel2->WinHeight=32;
	UGUILabel* KeyConfigAliasLabel3 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	KeyConfigAliasLabel3->Caption="Key 2";
	KeyConfigAliasLabel3->TextAlign = ETextAlign::TXTA_Center;
	KeyConfigAliasLabel3->TextColor=FColor(255, 255, 255, 255);
	KeyConfigAliasLabel3->TextFont="UT2HeaderFont";
	KeyConfigAliasLabel3->WinTop=0.004167;
	KeyConfigAliasLabel3->WinLeft=0.686914;
	KeyConfigAliasLabel3->WinWidth=0.25;
	KeyConfigAliasLabel3->WinHeight=32;

	BkColor = FColor(100, 24, 24, 200);
	Bindings = { FKeyBinding({true, "Movement", ""}),
	FKeyBinding({false, "Forward", "MoveForward"}),
	FKeyBinding({false, "Backward", "MoveBackward"}),
	FKeyBinding({false, "Strafe Left", "StrafeLeft"}),
	FKeyBinding({false, "Strafe Right", "StrafeRight"}),
	FKeyBinding({false, "Jump", "Jump"}),
	FKeyBinding({false, "Walk", "Walking"}),
	FKeyBinding({false, "Crouch", "Duck"}),
	FKeyBinding({false, "Strafe Toggle", "Strafe"}),
	FKeyBinding({true, "Looking", ""}),
	FKeyBinding({false, "Turn Left", "TurnLeft"}),
	FKeyBinding({false, "Turn Right", "TurnRight"}),
	FKeyBinding({false, "Look Up", "LookUp"}),
	FKeyBinding({false, "Look Down", "LookDown"}),
	FKeyBinding({false, "Center View", "CenterView"}),
	FKeyBinding({true, "Weapons", ""}),
	FKeyBinding({false, "Fire", "Fire"}),
	FKeyBinding({false, "Alt-Fire", "AltFire"}),
	FKeyBinding({false, "Throw Weapon", "ThrowWeapon"}),
	FKeyBinding({false, "Best Weapon", "SwitchToBestWeapon"}),
	FKeyBinding({false, "Next Weapon", "NextWeapon"}),
	FKeyBinding({false, "Prev Weapon", "PrevWeapon"}),
	FKeyBinding({false, "Last Weapon", "SwitchToLastWeapon"}),
	FKeyBinding({true, "Weapon Selection", ""}),
	FKeyBinding({false, "Super Weapon", "SwitchWeapon 0"}),
	FKeyBinding({false, "Shield Gun", "SwitchWeapon 1"}),
	FKeyBinding({false, "Assault Rifle", "SwitchWeapon 2"}),
	FKeyBinding({false, "Bio-Rifle", "SwitchWeapon 3"}),
	FKeyBinding({false, "Shock Rifle", "SwitchWeapon 4"}),
	FKeyBinding({false, "Link Gun", "SwitchWeapon 5"}),
	FKeyBinding({false, "Minigun", "SwitchWeapon 6"}),
	FKeyBinding({false, "Flak Cannon", "SwitchWeapon 7"}),
	FKeyBinding({false, "Rocket Launcher", "SwitchWeapon 8"}),
	FKeyBinding({false, "Lightning Rifle", "SwitchWeapon 9"}),
	FKeyBinding({false, "Translocator", "SwitchWeapon 10"}),
	FKeyBinding({true, "Communication", ""}),
	FKeyBinding({false, "Say", "Talk"}),
	FKeyBinding({false, "Team Say", "TeamTalk"}),
	FKeyBinding({false, "Speech Menu", "SpeechMenuToggle"}),
	FKeyBinding({true, "Taunts", ""}),
	FKeyBinding({false, "Pelvic Thrust", "taunt pthrust"}),
	FKeyBinding({false, "Ass Smack", "taunt asssmack"}),
	FKeyBinding({false, "Throat Cut", "taunt throatcut"}),
	FKeyBinding({true, "Hud", ""}),
	FKeyBinding({false, "Grow Hud", "GrowHud"}),
	FKeyBinding({false, "Shrink Hud", "ShrinkHud"}),
	FKeyBinding({true, "Miscellaneous", ""}),
	FKeyBinding({false, "Pause", "Pause"}),
	FKeyBinding({false, "Screenshot", "shot"}),
	FKeyBinding({false, "Menu", "ShowMenu"}),
	FKeyBinding({false, "ScoreBoard", "ShowScores"}),
	FKeyBinding({false, "ScoreBoard Toggle", "ScoreToggle"}),
	FKeyBinding({false, "In Game Chat", "InGameChat"}),
	FKeyBinding({false, "Server Info", "ServerInfo"}) };

	Labels = { "Movement","Forward","Backward","Strafe Left","Strafe Right","Jump","Walk","Crouch","Strafe Toggle","Looking","Turn Left","Turn Right","Look Up","Look Down","Center View","Weapons","Fire","Alt-Fire","Throw Weapon","Best Weapon","Next Weapon","Prev Weapon","Last Weapon","Weapon Selection","Super Weapon","Shield Gun","Assault Rifle","Bio-Rifle","Shock Rifle","Link Gun","Minigun","Flak Cannon","Rocket Launcher","Lightning Rifle","Translocator","Communication","Say","Team Say","Speech Menu","Taunts","Pelvic Thrust","Ass Smack","Throat Cut","Hud","Grow Hud","Shrink Hud","Miscellaneous","Pause","Screenshot","Menu","ScoreBoard","ScoreBoard Toggle","In Game Chat","Server Info" };
	Header = "[";
	Footer = "] Perform this action ";
	SectionLabelMargin = 10;
	Controls = { KeyConfigKeyList,KeyConfigBK1,KeyConfigBK2,KeyConfigBK3,KeyConfigAliasLabel,KeyConfigAliasLabel2,KeyConfigAliasLabel3,KeyResetButton };
	WinTop = 0.15;
	WinHeight = 0.74;
}


//const DefaultBindings = 54;

void UTab_ControlSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyListBox = GUIListBox(Controls[0]);
	MyListBox.List.__OnDrawItem__Delegate = DrawBinding;
	MyListBox.List.SelectedBKColor = BkColor;
	MyListBox.List.SelectedImage = None;
	MyListBox.List.__OnClick__Delegate = GetNewKey;
	MyListBox.List.__OnChange__Delegate = ListChange;
	MyListBox.List.__OnKeyEvent__Delegate = ListOnKeyEvent;
	MyListBox.List.bHotTrack = true;
	MyListBox.List.OnClickSound = 0;
	MyListBox.List.__OnAdjustTop__Delegate = MyOnAdjustTop;
	SelStyle = Controller.GetStyle("RoundButton", MyListBox.List.FontScale);
	*/
}

void UTab_ControlSettings::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		if (!bListInitialised)
		{
			InitBindings();
			MyListBox.List.Index = 1;
			HackIndex = 1;
			bListInitialised = true;
		}
	}
	*/
}

int32 UTab_ControlSettings::Weight(int32 i)
{
	/*
	if ((i == 1) || (i == 2))
	{
		return 100;
	}
	if ((i >= 48) && (i <= 90))
	{
		return 50;
	}
	if (i == 32)
	{
		return 45;
	}
	if (i == 4)
	{
		return 40;
	}
	if ((i == 236) || (i == 237))
	{
		return 35;
	}
	if ((i >= 33) && (i <= 40))
	{
		return 30;
	}
	if ((i >= 96) && (i <= 111))
	{
		return 30;
	}
	*/
	return 25;
}

void UTab_ControlSettings::Swap(int32 Index, int32 A, int32 B)
{
	/*
	int32 TempInt = 0;
	FString TempStrA = "";
	FString TempStrB = "";
	TempInt = Bindings[Index].Binds[A];
	TempStrA = Bindings[Index].BindKeyNames[A];
	TempStrB = Bindings[Index].BindLocalizedKeyNames[A];
	Bindings[Index].Binds[A] = Bindings[Index].Binds[B];
	Bindings[Index].BindKeyNames[A] = Bindings[Index].BindKeyNames[B];
	Bindings[Index].BindLocalizedKeyNames[A] = Bindings[Index].BindLocalizedKeyNames[B];
	Bindings[Index].Binds[B] = TempInt;
	Bindings[Index].BindKeyNames[B] = TempStrA;
	Bindings[Index].BindLocalizedKeyNames[B] = TempStrB;
	*/
}

void UTab_ControlSettings::AddToBindings(FString Alias, FString KeyLabel, bool bSectionLabel)
{
	/*
	int32 At = 0;
	At = Bindings.Length;
	Bindings.Length = (Bindings.Length + 1);
	Bindings[At].bIsSectionLabel = bSectionLabel;
	Bindings[At].KeyLabel = KeyLabel;
	Bindings[At].Alias = Alias;
	MyListBox.List.Add(Bindings[At].KeyLabel);
	*/
}

void UTab_ControlSettings::InitBindings()
{
	/*
	int32 i = 0;
	int32 j = 0;
	int32 k = 0;
	int32 Index = 0;
	FString KeyName = "";
	FString Alias = "";
	FString LocalizedKeyName = "";
	FString UserKeyClass = "";
	local class<GUIUserKeyBinding>  Key;
	for (i = 0; i < Bindings.Length; i++)
	{
		if (Bindings[i].Binds.Length > 0)
		{
			Bindings[i].Binds.remove(0, Bindings[i].Binds.Length);
		}
		if (Bindings[i].BindKeyNames.Length > 0)
		{
			Bindings[i].BindKeyNames.remove(0, Bindings[i].BindKeyNames.Length);
		}
		if (Bindings[i].BindLocalizedKeyNames.Length > 0)
		{
			Bindings[i].BindLocalizedKeyNames.remove(0, Bindings[i].BindLocalizedKeyNames.Length);
		}
		if (i < 54)
		{
			Bindings[i].KeyLabel = Labels[i];
		}
		MyListBox.List.Add(Bindings[i].KeyLabel);
	}
	j = 0;
	for (UserKeyClass = PlayerOwner().Level.GetNextInt("Xinterface.GUIUserKeyBinding", j++); UserKeyClass != ""; UserKeyClass = PlayerOwner().Level.GetNextInt("Xinterface.GUIUserKeyBinding", j++))
	{
		Key = class<GUIUserKeyBinding>(DynamicLoadObject(UserKeyClass, Class'Class'));
		if (Key != None)
		{
			for (i = 0; i < Key.Default.KeyData.Length; i++)
			{
				AddToBindings(Key.Default.KeyData[i].Alias, Key.Default.KeyData[i].KeyLabel, Key.Default.KeyData[i].bIsSection);
			}
		}
	}
	for (i = 0; i < 255; i++)
	{
		KeyName = PlayerOwner().ConsoleCommand("KEYNAME" @ string(i));
		LocalizedKeyName = PlayerOwner().ConsoleCommand("LOCALIZEDKEYNAME" @ string(i));
		if (KeyName != "")
		{
			Alias = PlayerOwner().ConsoleCommand("KEYBINDING" @ KeyName);
			if (Alias != "")
			{
				for (j = 0; j < Bindings.Length; j++)
				{
					if (Bindings[j].Alias ~= Alias)
					{
						Index = Bindings[j].Binds.Length;
						Bindings[j].Binds[Index] = i;
						Bindings[j].BindKeyNames[Index] = KeyName;
						Bindings[j].BindLocalizedKeyNames[Index] = LocalizedKeyName;
						k = 0;
						if (k < Index)
						{
							if (Weight(Bindings[j].Binds[k]) < Weight(Bindings[j].Binds[Index]))
							{
								Swap(j, k, Index);
							}
							else
							{
								k++;
							}
						}
					}
				}
			}
		}
	}
	*/
}

FString UTab_ControlSettings::GetCurrentKeyBind(int32 Index, int32 bind)
{
	/*
	if (Index >= Bindings.Length)
	{
		return "";
	}
	if (Bindings[Index].bIsSectionLabel)
	{
		return "";
	}
	if ((Index == NewIndex) && (bind == NewSubIndex))
	{
		return "???";
	}
	if (bind >= Bindings[Index].Binds.Length)
	{
		return "";
	}
	return Bindings[Index].BindLocalizedKeyNames[bind];
	*/

	return "FAKE";    //FAKE    /ELiZ
}

void UTab_ControlSettings::DrawBinding(UCanvas* Canvas, int32 Item, float X, float Y, float W, float H, bool bSelected, bool bPending)
{
	/*
	int32 X1 = 0;
	int32 w1 = 0;
	bool InBindArea = false;
	if (Item >= Bindings.Length)
	{
		return;
	}
	if ((Controller.MouseX >= Controls[2].Bounds[0]) && (Controller.MouseX <= Controls[3].Bounds[2]))
	{
		InBindArea = true;
	}
	if (Controller.HasMouseMoved() && (!bSetNextKeyPress))
	{
		if (InBindArea)
		{
			if ((Controller.MouseX >= Controls[2].Bounds[0]) && (Controller.MouseX <= Controls[2].Bounds[2]))
			{
				row = 0;
			}
			else
			{
				if ((Controller.MouseX >= Controls[3].Bounds[0]) && (Controller.MouseX <= Controls[3].Bounds[2]))
				{
					row = 1;
				}
			}
			InBindArea = true;
		}
		if (((InBindArea && (MyListBox.List.Index != HackIndex)) && (MyListBox.List.Index < Bindings.Length)) && Bindings[MyListBox.List.Index].bIsSectionLabel)
		{
			MyListBox.List.SetIndex(HackIndex);
		}
	}
	if (InBindArea)
	{
		if (bSetNextKeyPress && (MyListBox.List.Index != HackIndex))
		{
			MyListBox.List.SetIndex(HackIndex);
		}
		if (HackIndex != MyListBox.List.Index)
		{
			UpdateHint(MyListBox.List.Index);
		}
		HackIndex = MyListBox.List.Index;
	}
	if (Bindings[Item].bIsSectionLabel)
	{
		Canvas.CurX = (Controls[1].ClientBounds[0] + 3);
		Canvas.CurY = Y;
		Canvas.SetDrawColor(24, 24, 74, 200);
		Canvas.DrawTile(Controller.DefaultPens[0], ((Controls[1].ClientBounds[2] - Controls[1].ClientBounds[0]) - 6), H, 0, 0, 1, 1);
		MyListBox.Style.DrawText(Canvas, 3, (Controls[1].ClientBounds[0] + SectionLabelMargin), Y, (Controls[1].ClientBounds[2] - Controls[1].ClientBounds[0]), H, 0, Bindings[Item].KeyLabel, MyListBox.FontScale);
	}
	else
	{
		MyListBox.Style.DrawText(Canvas, MenuState, Controls[1].ActualLeft(), Y, Controls[1].ActualWidth(), H, 1, Bindings[Item].KeyLabel, MyListBox.FontScale);
	}
	MyListBox.Style.DrawText(Canvas, MenuState, Controls[2].ActualLeft(), Y, Controls[2].ActualWidth(), H, 1, GetCurrentKeyBind(Item, 0), MyListBox.FontScale);
	MyListBox.Style.DrawText(Canvas, MenuState, Controls[3].ActualLeft(), Y, Controls[3].ActualWidth(), H, 1, GetCurrentKeyBind(Item, 1), MyListBox.FontScale);
	if (bSelected && (!Bindings[Item].bIsSectionLabel))
	{
		if (row == 0)
		{
			X1 = int(Controls[2].ActualLeft());
			w1 = int(Controls[2].ActualWidth());
		}
		else
		{
			if (row == 1)
			{
				X1 = int(Controls[3].ActualLeft());
				w1 = int(Controls[3].ActualWidth());
			}
		}
		if (!bSetNextKeyPress)
		{
			SelStyle.Draw(Canvas, 1, float(X1), Y, float(w1), H);
		}
		else
		{
			SelStyle.Draw(Canvas, 3, float(X1), Y, float(w1), H);
		}
		UpdateHint(Item);
	}
	*/
}

bool UTab_ControlSettings::ListOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	bool Result = false;
	int32 oldIndex = 0;
	if ((Key == 13) && (State == 3))
	{
		GetNewKey(None);
		return true;
	}
	if ((Key == 8) && (State == 3))
	{
		if ((Controller.MouseX >= Controls[2].Bounds[0]) && (Controller.MouseX <= Controls[2].Bounds[2]))
		{
			RemoveExistingKey(MyListBox.List.Index, 0);
		}
		else
		{
			if ((Controller.MouseX >= Controls[3].Bounds[0]) && (Controller.MouseX <= Controls[3].Bounds[2]))
			{
				RemoveExistingKey(MyListBox.List.Index, 1);
			}
		}
		UpdateHint(MyListBox.List.Index);
		return true;
	}
	if ((State == 1) && ((((Key == 37) || (Key == 100)) || (Key == 39)) || (Key == 102)))
	{
		if (row == 0)
		{
			row = 1;
		}
		else
		{
			row = 0;
		}
		UpdateHint(MyListBox.List.Index);
		return true;
	}
	oldIndex = MyListBox.List.Index;
	Result = MyListBox.List.InternalOnKeyEvent(Key, State, Delta);
	if (MyListBox.List.Index != oldIndex)
	{
		if (Bindings[MyListBox.List.Index].bIsSectionLabel)
		{
			if (MyListBox.List.Index < oldIndex)
			{
				SearchUp(oldIndex);
			}
			else
			{
				SearchDown(oldIndex);
			}
		}
	}
	UpdateHint(MyListBox.List.Index);
	*/
	return false;   //FAKE   /ELiZ
}

void UTab_ControlSettings::SearchUp(int32 oldIndex)
{
	/*
	int32 cindex = 0;
	cindex = MyListBox.List.Index;
	if (cindex > 0)
	{
		if (!Bindings[cindex].bIsSectionLabel)
		{
			MyListBox.List.SetIndex(cindex);
			return;
		}
		(cindex);
	}
	MyListBox.List.SetIndex(oldIndex);
	*/
}

void UTab_ControlSettings::SearchDown(int32 oldIndex)
{
	/*
	int32 cindex = 0;
	cindex = MyListBox.List.Index;
	if (cindex < (MyListBox.List.ItemCount - 1))
	{
		if (!Bindings[cindex].bIsSectionLabel)
		{
			MyListBox.List.SetIndex(cindex);
			return;
		}
		cindex++;
	}
	MyListBox.List.SetIndex(oldIndex);
	*/
}

void UTab_ControlSettings::RemoveExistingKey(int32 Index, int32 SubIndex)
{
	/*
	if (((Index >= Bindings.Length) || (SubIndex >= Bindings[Index].Binds.Length)) || (Bindings[Index].Binds[SubIndex] < 0))
	{
		return;
	}
	PlayerOwner().ConsoleCommand("SET Input" @ Bindings[Index].BindKeyNames[SubIndex]);
	Bindings[Index].Binds.remove(SubIndex, 1);
	Bindings[Index].BindKeyNames.remove(SubIndex, 1);
	Bindings[Index].BindLocalizedKeyNames.remove(SubIndex, 1);
	*/
}

void UTab_ControlSettings::RemoveAllOccurance(uint8 NewKey)
{
	/*
	int32 i = 0;
	int32 j = 0;
	for (i = 0; i < Bindings.Length; i++)
	{
		j = (Bindings[i].Binds.Length - 1);
		if (j >= 0)
		{
			if (Bindings[i].Binds[j] == NewKey)
			{
				RemoveExistingKey(i, j);
			}
			j;
		}
	}
	*/
}

void UTab_ControlSettings::UpdateHint(int32 Index)
{
	/*
	int32 i = 0;
	FString t = "";
	if ((Index < 0) || (Index >= Bindings.Length))
	{
		MyListBox.List.Hint = "";
		Controller.ActivePage.SetHint(MyListBox.List.Hint);
		return;
	}
	else
	{
		t = "";
		for (i = 0; i < Bindings[Index].Binds.Length; i++)
		{
			if (t == "")
			{
				t = "" $ GetCurrentKeyBind(Index, i);
			}
			else
			{
				t = t $ ", " $ GetCurrentKeyBind(Index, i);
			}
		}
	}
	MyListBox.List.Hint = Header $ t $ Footer;
	Controller.ActivePage.SetHint(MyListBox.List.Hint);
	*/
}

void UTab_ControlSettings::AddNewKey(int32 Index, int32 SubIndex, uint8 NewKey)
{
	/*
	if (Index >= Bindings.Length)
	{
		return;
	}
	if ((SubIndex < Bindings[Index].Binds.Length) && (Bindings[Index].Binds[SubIndex] == NewKey))
	{
		return;
	}
	RemoveAllOccurance(NewKey);
	if (SubIndex >= Bindings[Index].Binds.Length)
	{
		Bindings[Index].Binds.Length = (Bindings[Index].Binds.Length + 1);
		Bindings[Index].BindKeyNames.Length = (Bindings[Index].BindKeyNames.Length + 1);
		Bindings[Index].BindLocalizedKeyNames.Length = (Bindings[Index].BindLocalizedKeyNames.Length + 1);
		SubIndex = (Bindings[Index].Binds.Length - 1);
	}
	Bindings[Index].Binds[SubIndex] = NewKey;
	Bindings[Index].BindKeyNames[SubIndex] = PlayerOwner().ConsoleCommand("KeyName" @ string(NewKey));
	Bindings[Index].BindLocalizedKeyNames[SubIndex] = PlayerOwner().ConsoleCommand("LOCALIZEDKEYNAME" @ string(NewKey));
	PlayerOwner().ConsoleCommand("SET Input" @ Bindings[Index].BindKeyNames[SubIndex] @ Bindings[Index].Alias);
	UpdateHint(Index);
	*/
}

bool UTab_ControlSettings::GetNewKey(UGUIComponent* Sender)
{
	/*
	int32 SubIndex = 0;
	if ((Controller.MouseX >= Controls[2].Bounds[0]) && (Controller.MouseX <= Controls[2].Bounds[2]))
	{
		SubIndex = 0;
	}
	else
	{
		if ((Controller.MouseX >= Controls[3].Bounds[0]) && (Controller.MouseX <= Controls[3].Bounds[2]))
		{
			SubIndex = 1;
		}
		else
		{
			return true;
		}
	}
	NewIndex = MyListBox.List.Index;
	NewSubIndex = SubIndex;
	bSetNextKeyPress = true;
	Controller.__OnNeedRawKeyPress__Delegate = RawKey;
	Controller.Master.bRequireRawJoystick = true;
	PlayerOwner().ClientPlaySound(Controller.EditSound);
	PlayerOwner().ConsoleCommand("toggleime 0");
	*/
	return true;
}

bool UTab_ControlSettings::RawKey(uint8 NewKey)
{
	/*
	if (NewKey != 27)
	{
		AddNewKey(NewIndex, NewSubIndex, NewKey);
	}
	NewIndex = -1;
	NewSubIndex = -1;
	bSetNextKeyPress = false;
	Controller.__OnNeedRawKeyPress__Delegate = None;
	Controller.Master.bRequireRawJoystick = false;
	PlayerOwner().ClientPlaySound(Controller.ClickSound);
	*/
	return true;
}

void UTab_ControlSettings::ListChange(UGUIComponent* Sender)
{
	//UpdateHint(MyListBox.List.Index);
}

void UTab_ControlSettings::MyOnAdjustTop(UGUIComponent* Sender)
{
	/*
	if (MyListBox.List.Index < MyListBox.List.Top)
	{
		MyListBox.List.SetIndex(MyListBox.List.Top);
	}
	else
	{
		if (MyListBox.List.Index >= (MyListBox.List.Top + MyListBox.List.ItemsPerPage))
		{
			MyListBox.List.SetIndex((MyListBox.List.Top + MyListBox.List.ItemsPerPage));
		}
	}
	*/
}

bool UTab_ControlSettings::ResetClicked(UGUIComponent* Sender)
{
	/*
	Controller.ResetKeyboard();
	InitBindings();
	*/
	return true;
}