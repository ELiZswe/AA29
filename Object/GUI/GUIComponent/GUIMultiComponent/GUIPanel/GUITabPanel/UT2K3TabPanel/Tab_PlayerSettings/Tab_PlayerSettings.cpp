// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_PlayerSettings/Tab_PlayerSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICharacterList/GUICharacterListTeam/GUICharacterListTeam.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UTab_PlayerSettings::UTab_PlayerSettings()
{
	UGUICharacterListTeam* PlayerCharList = NewObject<UGUICharacterListTeam>(UGUICharacterListTeam::StaticClass());
	PlayerCharList->IniOption = "@Internal";
	PlayerCharList->StyleName = "CharButton";
	PlayerCharList->Hint = "Changes the character you play as.";
	PlayerCharList->WinTop = 0.813543;
	PlayerCharList->WinLeft = 0.036465;
	PlayerCharList->WinWidth = 0.453729;
	PlayerCharList->WinHeight = 0.189297;
	//PlayerCharList->OnClick=PlayerCharList.InternalOnClick;
	//PlayerCharList->OnRightClick=PlayerCharList.InternalOnRightClick;
	//PlayerCharList->OnMousePressed=PlayerCharList.InternalOnMousePressed;
	//PlayerCharList->OnMouseRelease=PlayerCharList.InternalOnMouseRelease;
	//PlayerCharList->OnKeyEvent=PlayerCharList.InternalOnKeyEvent;
	//PlayerCharList->OnLoadINI=Tab_PlayerSettings.InternalOnLoadINI;
	//PlayerCharList->OnBeginDrag=PlayerCharList.InternalOnBeginDrag;
	//PlayerCharList->OnEndDrag=PlayerCharList.InternalOnEndDrag;
	//PlayerCharList->OnDragDrop=PlayerCharList.InternalOnDragDrop;
	//PlayerCharList->OnDragEnter=PlayerCharList.InternalOnDragEnter;
	//PlayerCharList->OnDragLeave=PlayerCharList.InternalOnDragLeave;
	//PlayerCharList->OnDragOver=PlayerCharList.InternalOnDragOver;
	UGUIButton* PlayerOGG = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PlayerOGG->Caption = "Play List";
	PlayerOGG->Hint = "Configure your OGG Play List.";
	PlayerOGG->WinTop = 0.91875;
	PlayerOGG->WinLeft = 0.62;
	PlayerOGG->WinWidth = 0.25;
	PlayerOGG->WinHeight = 0.05;
	//PlayerOGG->OnClick=Tab_PlayerSettings.Playlist;
	//PlayerOGG->OnKeyEvent=PlayerOGG.InternalOnKeyEvent;
	UmoCheckBox* PlayerSmallWeap = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	PlayerSmallWeap->ComponentJustification = EeTextAlign::TXTA_Left;
	PlayerSmallWeap->CaptionWidth = 0.9;
	PlayerSmallWeap->Caption = "Small Weapons";
	//PlayerSmallWeap->OnCreateComponent=PlayerSmallWeap.InternalOnCreateComponent;
	PlayerSmallWeap->IniOption = "@Internal";
	PlayerSmallWeap->IniDefault = "False";
	PlayerSmallWeap->Hint = "Makes your first person weapon smaller.";
	PlayerSmallWeap->WinTop = 0.318333;
	PlayerSmallWeap->WinLeft = 0.521875;
	PlayerSmallWeap->WinWidth = 0.39375;
	PlayerSmallWeap->WinHeight = 0.04;
	UmoNumericEdit* PlayerFOV = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	PlayerFOV->MinValue = 80;
	PlayerFOV->MaxValue = 100;
	PlayerFOV->ComponentJustification = EeTextAlign::TXTA_Left;
	PlayerFOV->CaptionWidth = 0.65;
	PlayerFOV->Caption = "Default FOV";
	//PlayerFOV->OnCreateComponent=PlayerFOV.InternalOnCreateComponent;
	PlayerFOV->IniOption = "@INTERNAL";
	PlayerFOV->IniDefault = "85";
	PlayerFOV->Hint = "This value will change your field of view while playing.";
	PlayerFOV->WinTop = 0.228123;
	PlayerFOV->WinLeft = 0.524766;
	PlayerFOV->WinWidth = 0.39375;
	PlayerFOV->WinHeight = 0.06;
	//PlayerFOV->OnLoadINI=Tab_PlayerSettings.InternalOnLoadINI;
	UGUIButton* Player3DView = NewObject<UGUIButton>(UGUIButton::StaticClass());
	Player3DView->Caption = "3D View";
	Player3DView->Hint = "Toggle between 3D view and biography of character.";
	Player3DView->WinTop = 0.977868;
	Player3DView->WinLeft = 0.62;
	Player3DView->WinWidth = 0.25;
	Player3DView->WinHeight = 0.05;
	//Player3DView->OnClick=Tab_PlayerSettings.Toggle3DView;
	//Player3DView->OnKeyEvent=Player3DView.InternalOnKeyEvent;
	UGUIButton* PlayerRight = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PlayerRight->StyleName = "ArrowRight";
	PlayerRight->WinTop = 0.88646;
	PlayerRight->WinLeft = 0.479688;
	PlayerRight->WinWidth = 0.043555;
	PlayerRight->WinHeight = 0.084414;
	PlayerRight->bNeverFocus = true;
	PlayerRight->bRepeatClick = true;
	PlayerRight->OnClickSound = EClickSound::CS_Up;
	//PlayerRight->OnClick=Tab_PlayerSettings.InternalOnClick;
	//PlayerRight->OnKeyEvent=PlayerRight.InternalOnKeyEvent;
	UGUIButton* PlayerLeft = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PlayerLeft->StyleName = "ArrowLeft";
	PlayerLeft->WinTop = 0.88646;
	PlayerLeft->WinLeft = 0.000781;
	PlayerLeft->WinWidth = 0.043555;
	PlayerLeft->WinHeight = 0.084414;
	PlayerLeft->bNeverFocus = true;
	PlayerLeft->bRepeatClick = true;
	PlayerLeft->OnClickSound = EClickSound::CS_Down;
	//PlayerLeft->OnClick=Tab_PlayerSettings.InternalOnClick;
	//PlayerLeft->OnKeyEvent=PlayerLeft.InternalOnKeyEvent;
	UGUIScrollTextBox* PlayerScroll = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	PlayerScroll->CharDelay = 0.0025;
	PlayerScroll->EOLDelay = 0.5;
	//PlayerScroll->OnCreateComponent=PlayerScroll.InternalOnCreateComponent;
	PlayerScroll->WinTop = 0.406;
	PlayerScroll->WinLeft = 0.506132;
	PlayerScroll->WinWidth = 0.472071;
	PlayerScroll->WinHeight = 0.39707;
	PlayerScroll->bNeverFocus = true;
	UmoComboBox* PlayerHand = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	PlayerHand->ComponentJustification = EeTextAlign::TXTA_Left;
	PlayerHand->CaptionWidth = 0.65;
	PlayerHand->Caption = "Weapon";
	//PlayerHand->OnCreateComponent=PlayerHand.InternalOnCreateComponent;
	PlayerHand->IniOption = "@INTERNAL";
	PlayerHand->IniDefault = "High";
	PlayerHand->Hint = "Changes whether your weapon is visible.";
	PlayerHand->WinTop = 0.130729;
	PlayerHand->WinLeft = 0.524766;
	PlayerHand->WinWidth = 0.39375;
	PlayerHand->WinHeight = 0.06;
	//PlayerHand->OnLoadINI=Tab_PlayerSettings.InternalOnLoadINI;
	UmoComboBox* PlayerTeam = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	PlayerTeam->ComponentJustification = EeTextAlign::TXTA_Left;
	PlayerTeam->CaptionWidth = 0.65;
	PlayerTeam->Caption = "Preferred Team";
	//PlayerTeam->OnCreateComponent=PlayerTeam.InternalOnCreateComponent;
	PlayerTeam->IniOption = "@Internal";
	PlayerTeam->IniDefault = "Red";
	PlayerTeam->Hint = "Changes the team you will play on by default.";
	PlayerTeam->WinTop = 0.036979;
	PlayerTeam->WinLeft = 0.524766;
	PlayerTeam->WinWidth = 0.39375;
	PlayerTeam->WinHeight = 0.06;
	//PlayerTeam->OnLoadINI=Tab_PlayerSettings.InternalOnLoadINI;
	UmoEditBox* PlayerName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PlayerName->CaptionWidth = 0.25;
	PlayerName->Caption = "Name";
	//PlayerName->OnCreateComponent=PlayerName.InternalOnCreateComponent;
	PlayerName->IniOption = "@INTERNAL";
	PlayerName->IniDefault = "Player";
	PlayerName->Hint = "Changes the alias you play as.";
	PlayerName->WinTop = 0.714063;
	PlayerName->WinLeft = 0.121093;
	PlayerName->WinWidth = 0.3;
	PlayerName->WinHeight = 0.06;
	//PlayerName->OnLoadINI=Tab_PlayerSettings.InternalOnLoadINI;
	UGUIImage* PlayerBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//PlayerBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	PlayerBK1->ImageColor = FColor(255, 255, 255, 160);
	PlayerBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	PlayerBK1->WinTop = 0.008854;
	PlayerBK1->WinLeft = 0.506016;
	PlayerBK1->WinWidth = 0.434062;
	PlayerBK1->WinHeight = 0.377694;
	UGUIImage* PlayerPortrait = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//PlayerPortrait->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	PlayerPortrait->ImageStyle = EImgStyle::ISTY_Scaled;
	PlayerPortrait->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PlayerPortrait->WinTop = 0.024583;
	PlayerPortrait->WinLeft = 0.17225;
	PlayerPortrait->WinWidth = 0.183;
	PlayerPortrait->WinHeight = 0.637;
	UGUIImage* PlayerPortraitBorder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//PlayerPortraitBorder->Image=Texture'InterfaceContent.Menu.BorderBoxA1';
	PlayerPortraitBorder->ImageStyle = EImgStyle::ISTY_Stretched;
	PlayerPortraitBorder->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PlayerPortraitBorder->WinTop = 0.0185;
	PlayerPortraitBorder->WinLeft = 0.168687;
	PlayerPortraitBorder->WinWidth = 0.188563;
	PlayerPortraitBorder->WinHeight = 0.647875;
	UGUIImage* Player3DBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//Player3DBack->Image=Texture'InterfaceContent.Menu.BorderBoxA';
	Player3DBack->ImageColor = FColor(255, 255, 255, 160);
	Player3DBack->ImageStyle = EImgStyle::ISTY_Stretched;
	Player3DBack->WinTop = 0.156;
	Player3DBack->WinLeft = 0.506132;
	Player3DBack->WinWidth = 0.472071;
	Player3DBack->WinHeight = 0.742383;
	Player3DBack->bVisible = false;
	Player3DBack->bAcceptsInput = true;
	Player3DBack->OnClickSound = EClickSound::CS_Click;
	//Player3DBack->OnClick=Tab_PlayerSettings.NextAnim;

	HandNames = { "Right","Hidden","Left","Center" };
	TeamNames = { "Red","Blue" };
	SpinnyDudeOffset = FVector(150, 77, -22);
	bRenderDude = true;
	ShowBioCaption = "Bio";
	Show3DViewCaption = "3D View";
	Controls = { PlayerBK1,PlayerName,PlayerTeam,PlayerHand,PlayerCharList,PlayerScroll,PlayerLeft,PlayerRight,PlayerPortrait,Player3DView,PlayerPortraitBorder,Player3DBack,PlayerFOV,PlayerSmallWeap,PlayerOGG };
	WinTop = 0.15;
	WinHeight = 0.72;
	//OnDraw = Tab_PlayerSettings.InternalDraw;
}

void UTab_PlayerSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].__OnChange__Delegate = InternalOnChange;
	}
	moComboBox(Controls[3]).addItem(HandNames[0]);
	moComboBox(Controls[3]).addItem(HandNames[1]);
	moComboBox(Controls[3]).addItem(HandNames[2]);
	moComboBox(Controls[3]).addItem(HandNames[3]);
	moComboBox(Controls[3]).ReadOnly(true);
	moComboBox(Controls[2]).addItem(TeamNames[0]);
	moComboBox(Controls[2]).addItem(TeamNames[1]);
	moComboBox(Controls[2]).ReadOnly(true);
	moComboBox(Controls[2]).MyComboBox.__OnChange__Delegate = TeamChange;
	if (bUnlocked)
	{
		GUICharacterListTeam(Controls[4]).InitListExclusive("DUP");
	}
	else
	{
		GUICharacterListTeam(Controls[4]).InitListExclusive("DUP", "UNLOCK");
	}
	GUIImage(Controls[8]).Image = GUICharacterList(Controls[4]).GetPortrait();
	GUIScrollTextBox(Controls[5]).SetContent(Controller.LoadDecoText("", GUICharacterListTeam(Controls[4]).GetDecoText()));
	SpinnyDude = PlayerOwner().Spawn(class'XInterface.SpinnyWeap');
	SpinnyDude.SetRotation(PlayerOwner().Rotation);
	SpinnyDude.SetDrawType(DT_Mesh);
	SpinnyDude.bPlayRandomAnims = true;
	SpinnyDude.SetDrawScale(0.9);
	SpinnyDude.spinRate = 12000;
	bRenderDude = false;
	GUIButton(Controls[9]).Caption = Show3DViewCaption;
	moEditBox(Controls[1]).MyEditBox.bConvertSpaces = true;
	moEditBox(Controls[1]).MyEditBox.MaxWidth = 16;
	moNumericEdit(Controls[12]).MyNumericEdit.Step = 5;
	moCheckBox(Controls[13]).Checked(PlayerOwner().bSmallWeapons);
	if (ExtendedConsole(PlayerOwner().Player.Console).MusicManager == nullptr)
	{
		Controls[14].bVisible = false;
	}
	*/
}

void UTab_PlayerSettings::UpdateSpinnyDude()
{
}

bool UTab_PlayerSettings::InternalDraw(UCanvas* Canvas)
{
	/*
	FVector CamPos = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FRotator CamRot = FRotator(0, 0, 0);
	if (bRenderDude)
	{
		Canvas.GetCameraLocation(CamPos, CamRot);
		GetAxes(CamRot, X, Y, Z);
		SpinnyDude.SetLocation((((CamPos + (SpinnyDudeOffset.X * X)) + (SpinnyDudeOffset.Y * Y)) + (SpinnyDudeOffset.Z * Z)));
		Canvas.DrawActor(SpinnyDude, false, true, 90);
	}
	*/
	return false;
}

bool UTab_PlayerSettings::Playlist(UGUIComponent* Sender)
{
	//ExtendedConsole(PlayerOwner().Player.Console).MusicMenu();
	return true;
}

bool UTab_PlayerSettings::Toggle3DView(UGUIComponent* Sender)
{
	/*
	bRenderDude = (!bRenderDude);
	if (bRenderDude)
	{
		UpdateSpinnyDude();
		Controls[5].bVisible = false;
		GUIButton(Controls[9]).Caption = ShowBioCaption;
	}
	else
	{
		Controls[5].bVisible = true;
		Controls[11].bVisible = false;
		GUIButton(Controls[9]).Caption = Show3DViewCaption;
		SpinnyDude.LinkMesh(None);
	}
	*/
	return true;
}

bool UTab_PlayerSettings::NextAnim(UGUIComponent* Sender)
{
	/*
	if (bRenderDude)
	{
		SpinnyDude.PlayNextAnim();
	}
	*/
	return true;
}

void UTab_PlayerSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	FString CharName = "";
	FString TeamName = "";
	int32 i = 0;
	if (Sender == Controls[1])
	{
		moEditBox(Sender).SetText(PlayerOwner().GetUrlOption("Name"));
	}
	else
	{
		if (Sender == Controls[2])
		{
			if ((PlayerOwner().PlayerReplicationInfo == nullptr) || (PlayerOwner().PlayerReplicationInfo.Team == nullptr))
			{
				TeamName = PlayerOwner().GetUrlOption("Team");
			}
			else
			{
				TeamName = "" $ string(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex);
			}
			OriginalTeam = TeamName;
			if (TeamName ~= "1")
			{
				moComboBox(Controls[2]).SetText(TeamNames[1]);
			}
			else
			{
				moComboBox(Controls[2]).SetText(TeamNames[0]);
			}
		}
		else
		{
			if (Sender == Controls[3])
			{
				i = int(Class'PlayerController'.Default.Handedness);
				if (i == 2)
				{
					moComboBox(Controls[3]).SetText(HandNames[1]);
				}
				else
				{
					if (i == -1)
					{
						moComboBox(Controls[3]).SetText(HandNames[2]);
					}
					else
					{
						if (i == 0)
						{
							moComboBox(Controls[3]).SetText(HandNames[3]);
						}
						else
						{
							moComboBox(Controls[3]).SetText(HandNames[0]);
						}
					}
				}
			}
			else
			{
				if (Sender == Controls[4])
				{
					CharName = PlayerOwner().GetUrlOption("Character");
					GUICharacterList(Sender).Find(CharName);
					GUIImage(Controls[8]).Image = GUICharacterList(Controls[4]).GetPortrait();
					GUIScrollTextBox(Controls[5]).SetContent(Controller.LoadDecoText("", GUICharacterListTeam(Controls[4]).GetDecoText()));
				}
				else
				{
					if (Sender == Controls[12])
					{
						moNumericEdit(Controls[12]).SetValue(int(PlayerOwner().DefaultFOV));
					}
				}
			}
		}
	}
	*/
}

void UTab_PlayerSettings::TeamChange(UGUIComponent* Sender)
{
	bChanged = true;
}

void UTab_PlayerSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local GUICharacterList C;
	FString cname = "";
	local Sound NameSound;
	bool CharName = false;
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if ((((Sender == Controls[1]) || (Sender == Controls[2])) || (Sender == Controls[3])) || (Sender == Controls[12]))
	{
		bChanged = true;
	}
	else
	{
		if (Sender == Controls[4])
		{
			GUIImage(Controls[8]).Image = GUICharacterList(Controls[4]).GetPortrait();
			GUIScrollTextBox(Controls[5]).SetContent(Controller.LoadDecoText("", GUICharacterListTeam(Controls[4]).GetDecoText()));
			C = GUICharacterList(Controls[4]);
			cname = moEditBox(Controls[1]).GetText();
			CharName = false;
			if (((cname ~= "Nothing") || (cname ~= "")) || (cname ~= "Player"))
			{
				CharName = true;
			}
			if (CharName)
			{
				moEditBox(Controls[1]).SetText(GUICharacterList(Controls[4]).SelectedText());
			}
			NameSound = GUICharacterList(Controls[4]).GetSound();
			PlayerOwner().ClientPlaySound(NameSound, , , 6);
			if (bRenderDude)
			{
				UpdateSpinnyDude();
			}
			bChanged = true;
		}
		else
		{
			if (Sender == Controls[13])
			{
				PlayerOwner().bSmallWeapons = moCheckBox(Controls[13]).IsChecked();
				PlayerOwner().SaveConfig();
			}
		}
	}
	*/
}

bool UTab_PlayerSettings::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == Controls[6])
	{
		GUICharacterList(Controls[4]).PgUp();
	}
	else
	{
		if (Sender == Controls[7])
		{
			GUICharacterList(Controls[4]).PgDown();
		}
	}
	*/
	return true;
}

bool UTab_PlayerSettings::InternalApply(UGUIComponent* Sender)
{
	/*
	FString PName = "";
	FString PChar = "";
	FString PTeam = "";
	FString NewTeam = "";
	if (!bChanged)
	{
		return true;
	}
	PName = moEditBox(Controls[1]).GetText();
	PChar = GUICharacterList(Controls[4]).SelectedText();
	PTeam = moComboBox(Controls[2]).GetText();
	PlayerOwner().UpdateURL("Name", PName, true);
	PlayerOwner().UpdateURL("Character", PChar, true);
	if (PTeam ~= TeamNames[1])
	{
		NewTeam = "1";
	}
	else
	{
		NewTeam = "0";
	}
	if (NewTeam != OriginalTeam)
	{
		PlayerOwner().UpdateURL("Team", NewTeam, true);
		PlayerOwner().ChangeTeam(int(PlayerOwner().GetUrlOption("Team")));
	}
	PlayerOwner().ConsoleCommand("setname" @ PName);
	PlayerOwner().ConsoleCommand("changecharacter" @ PChar);
	if (moComboBox(Controls[3]).GetText() == HandNames[1])
	{
		PlayerOwner().SetHand(2);
	}
	else
	{
		if (moComboBox(Controls[3]).GetText() == HandNames[2])
		{
			PlayerOwner().SetHand(-1);
		}
		else
		{
			if (moComboBox(Controls[3]).GetText() == HandNames[3])
			{
				PlayerOwner().SetHand(0);
			}
			else
			{
				PlayerOwner().SetHand(1);
			}
		}
	}
	PlayerOwner().FOV(float(moNumericEdit(Controls[12]).GetValue()));
	bChanged = false;
	*/
	return true;
}

void UTab_PlayerSettings::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (!bShow)
	{
		InternalApply(None);
	}
	*/
}
