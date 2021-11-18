// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_GameSettings/Tab_GameSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUISlider/GUISlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UTab_GameSettings::UTab_GameSettings()
{
	UGUISlider* GameHudCrossHairA = NewObject<UGUISlider>(UGUISlider::StaticClass());
	GameHudCrossHairA->MaxValue=255;
	GameHudCrossHairA->bIntSlider=true;
	GameHudCrossHairA->IniOption="@Internal";
	GameHudCrossHairA->Hint="Changes the color of your crosshair.";
	GameHudCrossHairA->WinTop=0.645729;
	GameHudCrossHairA->WinLeft=0.678126;
	GameHudCrossHairA->WinWidth=0.214062;
	//GameHudCrossHairA->OnClick=GameHudCrossHairA.InternalOnClick;
	//GameHudCrossHairA->OnMousePressed=GameHudCrossHairA.InternalOnMousePressed;
	//GameHudCrossHairA->OnMouseRelease=GameHudCrossHairA.InternalOnMouseRelease;
	//GameHudCrossHairA->OnKeyEvent=GameHudCrossHairA.InternalOnKeyEvent;
	//GameHudCrossHairA->OnCapturedMouseMove=GameHudCrossHairA.InternalCapturedMouseMove;
	//GameHudCrossHairA->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UGUISlider* GameHudCrossHairB = NewObject<UGUISlider>(UGUISlider::StaticClass());
	GameHudCrossHairB->MaxValue=255;
	GameHudCrossHairB->bIntSlider=true;
	GameHudCrossHairB->IniOption="@Internal";
	GameHudCrossHairB->Hint="Changes the color of your crosshair.";
	GameHudCrossHairB->WinTop=0.541562;
	GameHudCrossHairB->WinLeft=0.678126;
	GameHudCrossHairB->WinWidth=0.214062;
	//GameHudCrossHairB->OnClick=GameHudCrossHairB.InternalOnClick;
	//GameHudCrossHairB->OnMousePressed=GameHudCrossHairB.InternalOnMousePressed;
	//GameHudCrossHairB->OnMouseRelease=GameHudCrossHairB.InternalOnMouseRelease;
	//GameHudCrossHairB->OnKeyEvent=GameHudCrossHairB.InternalOnKeyEvent;
	//GameHudCrossHairB->OnCapturedMouseMove=GameHudCrossHairB.InternalCapturedMouseMove;
	//GameHudCrossHairB->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UGUISlider* GameHudCrossHairG = NewObject<UGUISlider>(UGUISlider::StaticClass());
	GameHudCrossHairG->MaxValue=255;
	GameHudCrossHairG->bIntSlider=true;
	GameHudCrossHairG->IniOption="@Internal";
	GameHudCrossHairG->Hint="Changes the color of your crosshair.";
	GameHudCrossHairG->WinTop=0.437395;
	GameHudCrossHairG->WinLeft=0.678126;
	GameHudCrossHairG->WinWidth=0.214062;
	//GameHudCrossHairG->OnClick=GameHudCrossHairG.InternalOnClick;
	//GameHudCrossHairG->OnMousePressed=GameHudCrossHairG.InternalOnMousePressed;
	//GameHudCrossHairG->OnMouseRelease=GameHudCrossHairG.InternalOnMouseRelease;
	//GameHudCrossHairG->OnKeyEvent=GameHudCrossHairG.InternalOnKeyEvent;
	//GameHudCrossHairG->OnCapturedMouseMove=GameHudCrossHairG.InternalCapturedMouseMove;
	//GameHudCrossHairG->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UGUISlider* GameHudCrossHairR = NewObject<UGUISlider>(UGUISlider::StaticClass());
	GameHudCrossHairR->MaxValue=255;
	GameHudCrossHairR->bIntSlider=true;
	GameHudCrossHairR->IniOption="@Internal";
	GameHudCrossHairR->Hint="Changes the color of your crosshair.";
	GameHudCrossHairR->WinTop=0.333228;
	GameHudCrossHairR->WinLeft=0.678126;
	GameHudCrossHairR->WinWidth=0.214062;
	//GameHudCrossHairR->OnClick=GameHudCrossHairR.InternalOnClick;
	//GameHudCrossHairR->OnMousePressed=GameHudCrossHairR.InternalOnMousePressed;
	//GameHudCrossHairR->OnMouseRelease=GameHudCrossHairR.InternalOnMouseRelease;
	//GameHudCrossHairR->OnKeyEvent=GameHudCrossHairR.InternalOnKeyEvent;
	//GameHudCrossHairR->OnCapturedMouseMove=GameHudCrossHairR.InternalCapturedMouseMove;
	//GameHudCrossHairR->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UmoComboBox* GameCrossHair = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	GameCrossHair->ComponentJustification = EeTextAlign::TXTA_Left;
	GameCrossHair->CaptionWidth=0.3;
	GameCrossHair->Caption="Crosshair";
	//GameCrossHair->OnCreateComponent=GameCrossHair.InternalOnCreateComponent;
	GameCrossHair->IniOption="@Internal";
	GameCrossHair->Hint="Please select your crosshair!";
	GameCrossHair->WinTop=0.186719;
	GameCrossHair->WinLeft=0.552148;
	GameCrossHair->WinWidth=0.383398;
	GameCrossHair->WinHeight=0.06;
	//GameCrossHair->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* GameDeathMsgs = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameDeathMsgs->ComponentJustification = EeTextAlign::TXTA_Left;
	GameDeathMsgs->CaptionWidth=0.9;
	GameDeathMsgs->Caption="No Console Death Messages";
	//GameDeathMsgs->OnCreateComponent=GameDeathMsgs.InternalOnCreateComponent;
	GameDeathMsgs->IniOption="ini:Engine.XGame.xDeathMessage bNoConsoleDeathMessages";
	GameDeathMsgs->IniDefault="False";
	GameDeathMsgs->Hint="Turn off reporting of death messages in console";
	GameDeathMsgs->WinTop=0.832553;
	GameDeathMsgs->WinLeft=0.04746;
	GameDeathMsgs->WinWidth=0.403711;
	GameDeathMsgs->WinHeight=0.04;
	//GameDeathMsgs->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* GameAutoAim = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameAutoAim->ComponentJustification = EeTextAlign::TXTA_Left;
	GameAutoAim->CaptionWidth=0.9;
	GameAutoAim->Caption="Auto Aim";
	//GameAutoAim->OnCreateComponent=GameAutoAim.InternalOnCreateComponent;
	GameAutoAim->IniOption="ini:Engine.Engine.AudioDevice ReverseStereo";
	GameAutoAim->Hint="Turn this option on to have UT2004 help you aim (not available in Multiplayer).";
	GameAutoAim->WinTop=0.692344;
	GameAutoAim->WinLeft=0.05;
	GameAutoAim->WinWidth=0.4;
	GameAutoAim->WinHeight=0.04;
	//GameAutoAim->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* GameDodging = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameDodging->ComponentJustification = EeTextAlign::TXTA_Left;
	GameDodging->CaptionWidth=0.9;
	GameDodging->Caption="Dodging";
	//GameDodging->OnCreateComponent=GameDodging.InternalOnCreateComponent;
	GameDodging->IniOption="ini:Engine.Engine.AudioDevice ReverseStereo";
	GameDodging->Hint="Turn this option off to disable special dodge moves.";
	GameDodging->WinTop=0.541563;
	GameDodging->WinLeft=0.05;
	GameDodging->WinWidth=0.4;
	GameDodging->WinHeight=0.04;
	//GameDodging->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* GameReduceGore = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameReduceGore->ComponentJustification = EeTextAlign::TXTA_Left;
	GameReduceGore->CaptionWidth=0.9;
	GameReduceGore->Caption="Reduce Gore";
	//GameReduceGore->OnCreateComponent=GameReduceGore.InternalOnCreateComponent;
	GameReduceGore->IniOption="ini:Engine.Engine.AudioDevice ReverseStereo";
	GameReduceGore->Hint="Turn this option On to reduce the amount of blood and guts you see.";
	GameReduceGore->WinTop=0.415521;
	GameReduceGore->WinLeft=0.05;
	GameReduceGore->WinWidth=0.4;
	GameReduceGore->WinHeight=0.04;
	//GameReduceGore->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* GameWeaponBob = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameWeaponBob->ComponentJustification = EeTextAlign::TXTA_Left;
	GameWeaponBob->CaptionWidth=0.9;
	GameWeaponBob->Caption="Weapon Bob";
	//GameWeaponBob->OnCreateComponent=GameWeaponBob.InternalOnCreateComponent;
	GameWeaponBob->IniOption="@Internal";
	GameWeaponBob->Hint="Prevent your weapon from bobbing up and down while moving.";
	GameWeaponBob->WinTop=0.29078;
	GameWeaponBob->WinLeft=0.05;
	GameWeaponBob->WinWidth=0.4;
	GameWeaponBob->WinHeight=0.04;
	//GameWeaponBob->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UmoCheckBox* GameScreenFlashes = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameScreenFlashes->ComponentJustification = EeTextAlign::TXTA_Left;
	GameScreenFlashes->CaptionWidth=0.9;
	GameScreenFlashes->Caption="Screen Flashes";
	//GameScreenFlashes->OnCreateComponent=GameScreenFlashes.InternalOnCreateComponent;
	GameScreenFlashes->IniOption="ini:Engine.Engine.ViewportManager ScreenFlashes";
	GameScreenFlashes->Hint="Turn this option off to disable screen flashes when you take damage.";
	GameScreenFlashes->WinTop=0.168385;
	GameScreenFlashes->WinLeft=0.05;
	GameScreenFlashes->WinWidth=0.4;
	GameScreenFlashes->WinHeight=0.04;
	//GameScreenFlashes->OnLoadINI=Tab_GameSettings.InternalOnLoadINI;
	UGUIImage* GameBK = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//GameBK->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	GameBK->ImageColor=FColor(255, 255, 255, 160);
	GameBK->ImageStyle = EImgStyle::ISTY_Stretched;
	GameBK->WinTop=0.130208;
	GameBK->WinLeft=0.029297;
	GameBK->WinWidth=0.427148;
	GameBK->WinHeight=0.803125;
	UGUIImage* GameBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//GameBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	GameBK1->ImageColor=FColor(255, 255, 255, 160);
	GameBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	GameBK1->WinTop=0.130208;
	GameBK1->WinLeft=0.517578;
	GameBK1->WinWidth=0.448633;
	GameBK1->WinHeight=0.803125;
	UGUIImage* GameCrossHairImage = NewObject<UGUIImage>(UGUIImage::StaticClass());
	GameCrossHairImage->ImageAlign = EImgAlign::IMGA_Center;
	GameCrossHairImage->X1=0;
	GameCrossHairImage->Y1=0;
	GameCrossHairImage->X2=64;
	GameCrossHairImage->Y2=64;
	GameCrossHairImage->WinTop=0.817969;
	GameCrossHairImage->WinLeft=0.744334;
	GameCrossHairImage->WinWidth=0.055273;
	GameCrossHairImage->WinHeight=0.06;
	UGUIImage* CrosshairBK = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//CrosshairBK->Image=Texture'InterfaceContent.Menu.BorderBoxA';
	CrosshairBK->ImageColor=FColor(255, 255, 255, 160);
	CrosshairBK->ImageStyle = EImgStyle::ISTY_Stretched;
	CrosshairBK->WinTop=0.741667;
	CrosshairBK->WinLeft=0.699062;
	CrosshairBK->WinWidth=0.09;
	CrosshairBK->WinHeight=0.15;
	UGUILabel* GameHudCrossHairRLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GameHudCrossHairRLabel->Caption="Red:";
	GameHudCrossHairRLabel->TextAlign = ETextAlign::TXTA_Center;
	GameHudCrossHairRLabel->TextColor=FColor(255, 255, 255, 255);
	GameHudCrossHairRLabel->WinTop=0.30625;
	GameHudCrossHairRLabel->WinLeft=0.610353;
	GameHudCrossHairRLabel->WinWidth=0.081251;
	GameHudCrossHairRLabel->WinHeight=32;
	UGUILabel* GameHudCrossHairGLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GameHudCrossHairGLabel->Caption="Green:";
	GameHudCrossHairGLabel->TextAlign = ETextAlign::TXTA_Center;
	GameHudCrossHairGLabel->TextColor=FColor(255, 255, 255, 255);
	GameHudCrossHairGLabel->WinTop=0.408333;
	GameHudCrossHairGLabel->WinLeft=0.580664;
	GameHudCrossHairGLabel->WinWidth=0.120313;
	GameHudCrossHairGLabel->WinHeight=32;
	UGUILabel* GameHudCrossHairBLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GameHudCrossHairBLabel->Caption="Blue:";
	GameHudCrossHairBLabel->TextAlign = ETextAlign::TXTA_Center;
	GameHudCrossHairBLabel->TextColor=FColor(255, 255, 255, 255);
	GameHudCrossHairBLabel->WinTop=0.514583;
	GameHudCrossHairBLabel->WinLeft=0.599414;
	GameHudCrossHairBLabel->WinWidth=0.096876;
	GameHudCrossHairBLabel->WinHeight=32;
	UGUILabel* GameHudCrossHairALabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GameHudCrossHairALabel->Caption="Opacity:";
	GameHudCrossHairALabel->TextAlign = ETextAlign::TXTA_Center;
	GameHudCrossHairALabel->TextColor=FColor(255, 255, 255, 255);
	GameHudCrossHairALabel->WinTop=0.616667;
	GameHudCrossHairALabel->WinLeft=0.571289;
	GameHudCrossHairALabel->WinWidth=0.120313;
	GameHudCrossHairALabel->WinHeight=32;

	CrosshairNames = { "Hidden","Cross (1)","Cross (2)","Cross (3)","Cross (4)","Cross (5)","Dot","Pointer","Triad (1)","Triad (2)","Triad (3)","Bracket (1)","Bracket (2)","Circle (1)","Circle (2)" };
	Controls = { GameBK,GameBK1,GameScreenFlashes,GameWeaponBob,GameReduceGore,GameDodging,GameAutoAim,GameDeathMsgs,GameCrossHair,GameCrossHairImage,CrosshairBK,GameHudCrossHairRLabel,GameHudCrossHairR,GameHudCrossHairGLabel,GameHudCrossHairG,GameHudCrossHairBLabel,GameHudCrossHairB,GameHudCrossHairALabel,GameHudCrossHairA };
	WinTop = 0.15;
	WinHeight = 0.74;
}

void UTab_GameSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].__OnChange__Delegate = InternalOnChange;
	}
	for (i = 0; i < 15; i++)
	{
		moComboBox(Controls[8]).addItem(CrosshairNames[i]);
	}
	moComboBox(Controls[8]).ReadOnly(true);
	if (Class'GameInfo'.Default.bAlternateMode)
	{
		Controls[4].bVisible = false;
	}
	*/
}

void UTab_GameSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	int32 i = 0;
	if (Sender == Controls[2])
	{
		moCheckBox(Sender).Checked(bool(S));
	}
	else
	{
		if (Sender == Controls[3])
		{
			moCheckBox(Sender).Checked(Class'Pawn'.Default.bWeaponBob);
		}
		else
		{
			if (Sender == Controls[4])
			{
				moCheckBox(Sender).Checked(Class'GameInfo'.UseLowGore());
			}
			else
			{
				if (Sender == Controls[5])
				{
					moCheckBox(Sender).Checked(PlayerOwner().DodgingIsEnabled());
				}
				else
				{
					if (Sender == Controls[6])
					{
						moCheckBox(Sender).Checked((Class'GameInfo'.Default.AutoAim > 0));
					}
					else
					{
						if (Sender == Controls[8])
						{
							if (!Class'HUD'.Default.bCrosshairShow)
							{
								i = 0;
							}
							else
							{
								i = (Class'HUD'.Default.CrosshairStyle + 1);
							}
							moComboBox(Sender).SetText(CrosshairNames[i]);
							SetCrossHairGraphic(i);
						}
						else
						{
							if (Sender == Controls[12])
							{
								GUISlider(Sender).Value = float(Class'HUD'.Default.CrossHairColor.R);
							}
							else
							{
								if (Sender == Controls[14])
								{
									GUISlider(Sender).Value = float(Class'HUD'.Default.CrossHairColor.G);
								}
								else
								{
									if (Sender == Controls[16])
									{
										GUISlider(Sender).Value = float(Class'HUD'.Default.CrossHairColor.B);
									}
									else
									{
										if (Sender == Controls[18])
										{
											GUISlider(Sender).Value = float(Class'HUD'.Default.CrossHairColor.A);
											GUIImage(Controls[9]).ImageColor = PlayerOwner().myHUD.CrossHairColor;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	*/
}

FString UTab_GameSettings::InternalOnSaveINI(UGUIComponent* Sender)
{
	return "FAKE";    //FAKE   /ELiZ
}

void UTab_GameSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if (Sender == Controls[2])
	{
		PlayerOwner().ConsoleCommand("set" @ Sender.IniOption @ string(moCheckBox(Sender).IsChecked()));
	}
	else
	{
		if (Sender == Controls[3])
		{
			PlayerOwner().ConsoleCommand("set Pawn bWeaponBob " $ string(moCheckBox(Sender).IsChecked()));
			Class'Pawn'.Default.bWeaponBob = moCheckBox(Sender).IsChecked();
			Class'Pawn'.StaticSaveConfig();
		}
		else
		{
			if (Sender == Controls[4])
			{
				Class'GameInfo'.Default.bLowGore = moCheckBox(Sender).IsChecked();
				Class'GameInfo'.StaticSaveConfig();
			}
			else
			{
				if (Sender == Controls[5])
				{
					if (!moCheckBox(Sender).IsChecked())
					{
						PlayerOwner().SetDodging(false);
					}
					else
					{
						PlayerOwner().SetDodging(true);
					}
				}
				else
				{
					if (Sender == Controls[6])
					{
						if (moCheckBox(Sender).IsChecked())
						{
							Class'GameInfo'.Default.AutoAim = 0.5;
						}
						else
						{
							Class'GameInfo'.Default.AutoAim = 0;
						}
						Class'GameInfo'.StaticSaveConfig();
					}
					else
					{
						if (Sender == Controls[8])
						{
							SetCrossHairGraphic(moComboBox(Sender).GetIndex());
							if (moComboBox(Sender).GetText() == "Hidden")
							{
								PlayerOwner().myHUD.bCrosshairShow = false;
								PlayerOwner().myHUD.SaveConfig();
								return;
							}
							PlayerOwner().myHUD.bCrosshairShow = true;
							PlayerOwner().myHUD.CrosshairStyle = (moComboBox(Sender).GetIndex() - 1);
							PlayerOwner().myHUD.SaveConfig();
						}
						else
						{
							if (Sender == Controls[12])
							{
								PlayerOwner().myHUD.CrossHairColor.R = byte(GUISlider(Sender).Value);
								PlayerOwner().myHUD.SaveConfig();
								GUIImage(Controls[9]).ImageColor = PlayerOwner().myHUD.CrossHairColor;
							}
							else
							{
								if (Sender == Controls[14])
								{
									PlayerOwner().myHUD.CrossHairColor.G = byte(GUISlider(Sender).Value);
									PlayerOwner().myHUD.SaveConfig();
									GUIImage(Controls[9]).ImageColor = PlayerOwner().myHUD.CrossHairColor;
								}
								else
								{
									if (Sender == Controls[16])
									{
										PlayerOwner().myHUD.CrossHairColor.B = byte(GUISlider(Sender).Value);
										PlayerOwner().myHUD.SaveConfig();
										GUIImage(Controls[9]).ImageColor = PlayerOwner().myHUD.CrossHairColor;
									}
									else
									{
										if (Sender == Controls[18])
										{
											PlayerOwner().myHUD.CrossHairColor.A = byte(GUISlider(Sender).Value);
											PlayerOwner().myHUD.SaveConfig();
											GUIImage(Controls[9]).ImageColor = PlayerOwner().myHUD.CrossHairColor;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	*/
}

void UTab_GameSettings::SetCrossHairGraphic(int32 Index)
{
	/*
	local GUIImage img;
	img = GUIImage(Controls[9]);
	img.Image = class'XInterface.HudBDeathMatch'.Default.Crosshairs[(Index - 1)].WidgetTexture;
	img.bVisible = (Index != 0);
	*/
}