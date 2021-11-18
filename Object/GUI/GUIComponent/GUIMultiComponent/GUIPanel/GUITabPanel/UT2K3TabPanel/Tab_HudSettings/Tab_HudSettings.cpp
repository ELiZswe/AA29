// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_HudSettings/Tab_HudSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUISlider/GUISlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_HudSettings::UTab_HudSettings()
{
	UGUISlider* GameHudOpacity = NewObject<UGUISlider>(UGUISlider::StaticClass());
	GameHudOpacity->IniOption = "@Internal";
	GameHudOpacity->Hint = "Changes the opacity level of the HUD.";
	GameHudOpacity->WinTop = 0.80823;
	GameHudOpacity->WinLeft = 0.592189;
	GameHudOpacity->WinWidth = 0.290625;
	//GameHudOpacity->OnClick=GameHudOpacity.InternalOnClick;
	//GameHudOpacity->OnMousePressed=GameHudOpacity.InternalOnMousePressed;
	//GameHudOpacity->OnMouseRelease=GameHudOpacity.InternalOnMouseRelease;
	//GameHudOpacity->OnKeyEvent=GameHudOpacity.InternalOnKeyEvent;
	//GameHudOpacity->OnCapturedMouseMove=GameHudOpacity.InternalCapturedMouseMove;
	//GameHudOpacity->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UGUISlider* GameHudScale = NewObject<UGUISlider>(UGUISlider::StaticClass());
	GameHudScale->MinValue = 50;
	GameHudScale->IniOption = "@Internal";
	GameHudScale->Hint = "Changes the opacity level of the HUD.";
	GameHudScale->WinTop = 0.635312;
	GameHudScale->WinLeft = 0.590626;
	GameHudScale->WinWidth = 0.292187;
	//GameHudScale->OnClick=GameHudScale.InternalOnClick;
	//GameHudScale->OnMousePressed=GameHudScale.InternalOnMousePressed;
	//GameHudScale->OnMouseRelease=GameHudScale.InternalOnMouseRelease;
	//GameHudScale->OnKeyEvent=GameHudScale.InternalOnKeyEvent;
	//GameHudScale->OnCapturedMouseMove=GameHudScale.InternalCapturedMouseMove;
	//GameHudScale->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowWeaponInfo = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowWeaponInfo->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowWeaponInfo->CaptionWidth = 0.9;
	GameHudShowWeaponInfo->Caption = "Show Weapon Info";
	//GameHudShowWeaponInfo->OnCreateComponent=GameHudShowWeaponInfo.InternalOnCreateComponent;
	GameHudShowWeaponInfo->IniOption = "@Internal";
	GameHudShowWeaponInfo->WinTop = 0.181927;
	GameHudShowWeaponInfo->WinLeft = 0.05;
	GameHudShowWeaponInfo->WinWidth = 0.378125;
	GameHudShowWeaponInfo->WinHeight = 0.04;
	//GameHudShowWeaponInfo->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudVisible = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudVisible->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudVisible->CaptionWidth = 0.9;
	GameHudVisible->Caption = "Hide HUD";
	//GameHudVisible->OnCreateComponent=GameHudVisible.InternalOnCreateComponent;
	GameHudVisible->IniOption = "@Internal";
	GameHudVisible->Hint = "This option will toggle drawing of the HUD.";
	GameHudVisible->WinTop = 0.043906;
	GameHudVisible->WinLeft = 0.379297;
	GameHudVisible->WinWidth = 0.196875;
	GameHudVisible->WinHeight = 0.04;
	//GameHudVisible->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowPersonalInfo = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowPersonalInfo->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowPersonalInfo->CaptionWidth = 0.9;
	GameHudShowPersonalInfo->Caption = "Show Personal Info";
	//GameHudShowPersonalInfo->OnCreateComponent=GameHudShowPersonalInfo.InternalOnCreateComponent;
	GameHudShowPersonalInfo->IniOption = "@Internal";
	GameHudShowPersonalInfo->WinTop = 0.317343;
	GameHudShowPersonalInfo->WinLeft = 0.05;
	GameHudShowPersonalInfo->WinWidth = 0.378125;
	GameHudShowPersonalInfo->WinHeight = 0.04;
	//GameHudShowPersonalInfo->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowScore = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowScore->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowScore->CaptionWidth = 0.9;
	GameHudShowScore->Caption = "Show Score";
	//GameHudShowScore->OnCreateComponent=GameHudShowScore.InternalOnCreateComponent;
	GameHudShowScore->IniOption = "@Internal";
	GameHudShowScore->WinTop = 0.45276;
	GameHudShowScore->WinLeft = 0.05;
	GameHudShowScore->WinWidth = 0.378125;
	GameHudShowScore->WinHeight = 0.04;
	//GameHudShowScore->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowWeaponBar = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowWeaponBar->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowWeaponBar->CaptionWidth = 0.9;
	GameHudShowWeaponBar->Caption = "Show Weapon Bar";
	//GameHudShowWeaponBar->OnCreateComponent=GameHudShowWeaponBar.InternalOnCreateComponent;
	GameHudShowWeaponBar->IniOption = "@Internal";
	GameHudShowWeaponBar->WinTop = 0.598593;
	GameHudShowWeaponBar->WinLeft = 0.05;
	GameHudShowWeaponBar->WinWidth = 0.378125;
	GameHudShowWeaponBar->WinHeight = 0.04;
	//GameHudShowWeaponBar->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowPortraits = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowPortraits->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowPortraits->CaptionWidth = 0.9;
	GameHudShowPortraits->Caption = "Show Portraits";
	//GameHudShowPortraits->OnCreateComponent=GameHudShowPortraits.InternalOnCreateComponent;
	GameHudShowPortraits->IniOption = "@Internal";
	GameHudShowPortraits->WinTop = 0.723594;
	GameHudShowPortraits->WinLeft = 0.05;
	GameHudShowPortraits->WinWidth = 0.378125;
	GameHudShowPortraits->WinHeight = 0.04;
	//GameHudShowPortraits->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoNumericEdit* GameHudMessageCount = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	GameHudMessageCount->MinValue = 0;
	GameHudMessageCount->MaxValue = 8;
	GameHudMessageCount->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudMessageCount->CaptionWidth = 0.7;
	GameHudMessageCount->Caption = "Max. Chat Count";
	//GameHudMessageCount->OnCreateComponent=GameHudMessageCount.InternalOnCreateComponent;
	GameHudMessageCount->IniOption = "@Internal";
	GameHudMessageCount->WinTop = 0.196875;
	GameHudMessageCount->WinLeft = 0.550781;
	GameHudMessageCount->WinWidth = 0.38125;
	GameHudMessageCount->WinHeight = 0.06;
	//GameHudMessageCount->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoNumericEdit* GameHudMessageScale = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	GameHudMessageScale->MinValue = 0;
	GameHudMessageScale->MaxValue = 8;
	GameHudMessageScale->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudMessageScale->CaptionWidth = 0.7;
	GameHudMessageScale->Caption = "Chat Font Size";
	//GameHudMessageScale->OnCreateComponent=GameHudMessageScale.InternalOnCreateComponent;
	GameHudMessageScale->IniOption = "@Internal";
	GameHudMessageScale->WinTop = 0.321874;
	GameHudMessageScale->WinLeft = 0.550781;
	GameHudMessageScale->WinWidth = 0.38125;
	GameHudMessageScale->WinHeight = 0.06;
	//GameHudMessageScale->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoNumericEdit* GameHudMessageOffset = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	GameHudMessageOffset->MinValue = 0;
	GameHudMessageOffset->MaxValue = 4;
	GameHudMessageOffset->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudMessageOffset->CaptionWidth = 0.7;
	GameHudMessageOffset->Caption = "Message Font Size";
	//GameHudMessageOffset->OnCreateComponent=GameHudMessageOffset.InternalOnCreateComponent;
	GameHudMessageOffset->IniOption = "@Internal";
	GameHudMessageOffset->WinTop = 0.436457;
	GameHudMessageOffset->WinLeft = 0.550781;
	GameHudMessageOffset->WinWidth = 0.38125;
	GameHudMessageOffset->WinHeight = 0.06;
	//GameHudMessageOffset->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UmoCheckBox* GameHudShowEnemyNames = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	GameHudShowEnemyNames->ComponentJustification = EeTextAlign::TXTA_Left;
	GameHudShowEnemyNames->CaptionWidth = 0.9;
	GameHudShowEnemyNames->Caption = "Show Enemy Names";
	//GameHudShowEnemyNames->OnCreateComponent=GameHudShowEnemyNames.InternalOnCreateComponent;
	GameHudShowEnemyNames->IniOption = "@Internal";
	GameHudShowEnemyNames->WinTop = 0.848594;
	GameHudShowEnemyNames->WinLeft = 0.05;
	GameHudShowEnemyNames->WinWidth = 0.378125;
	GameHudShowEnemyNames->WinHeight = 0.04;
	//GameHudShowEnemyNames->OnLoadINI=Tab_HudSettings.InternalOnLoadINI;
	UGUIImage* GameBK = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//GameBK->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	GameBK->ImageColor = FColor(255, 255, 255, 160);
	GameBK->ImageStyle = EImgStyle::ISTY_Stretched;
	GameBK->WinTop = 0.130208;
	GameBK->WinLeft = 0.029297;
	GameBK->WinWidth = 0.427148;
	GameBK->WinHeight = 0.803125;
	UGUIImage* GameBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//GameBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	GameBK1->ImageColor = FColor(255, 255, 255, 160);
	GameBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	GameBK1->WinTop = 0.130208;
	GameBK1->WinLeft = 0.517578;
	GameBK1->WinWidth = 0.448633;
	GameBK1->WinHeight = 0.803125;
	UGUILabel* GameHudScaleLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GameHudScaleLabel->Caption = "HUD Scaling";
	GameHudScaleLabel->TextAlign = ETextAlign::TXTA_Center;
	GameHudScaleLabel->TextColor = FColor(255, 255, 255, 255);
	GameHudScaleLabel->WinTop = 0.560417;
	GameHudScaleLabel->WinLeft = 0.516602;
	GameHudScaleLabel->WinWidth = 0.448438;
	GameHudScaleLabel->WinHeight = 32;
	UGUILabel* GameHudOpacityLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GameHudOpacityLabel->Caption = "HUD Opacity";
	GameHudOpacityLabel->TextAlign = ETextAlign::TXTA_Center;
	GameHudOpacityLabel->TextColor = FColor(255, 255, 255, 255);
	GameHudOpacityLabel->WinTop = 0.7375;
	GameHudOpacityLabel->WinLeft = 0.516602;
	GameHudOpacityLabel->WinWidth = 0.448438;
	GameHudOpacityLabel->WinHeight = 32;

	CrosshairNames = { "Hidden","Cross (1)","Cross (2)","Cross (3)","Cross (4)","Cross (5)","Dot","Pointer","Triad (1)","Triad (2)","Triad (3)","Bracket (1)","Bracket (2)","Circle (1)","Circle (2)" };
	Controls = { GameBK,GameBK1,GameHudVisible,GameHudShowWeaponInfo,GameHudShowPersonalInfo,GameHudShowScore,GameHudShowWeaponBar,GameHudShowPortraits,GameHudMessageCount,GameHudMessageScale,GameHudMessageOffset,GameHudScaleLabel,GameHudScale,GameHudOpacityLabel,GameHudOpacity,GameHudShowEnemyNames };
	WinTop = 0.15;
	WinHeight = 0.74;
}

void UTab_HudSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].__OnChange__Delegate = InternalOnChange;
	}
	*/
}

void UTab_HudSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	if (Sender == Controls[2])
	{
		moCheckBox(Sender).Checked(Class'HUD'.Default.bHideHUD);
	}
	else
	{
		if (Sender == Controls[3])
		{
			moCheckBox(Sender).Checked(Class'HUD'.Default.bShowWeaponInfo);
		}
		else
		{
			if (Sender == Controls[4])
			{
				moCheckBox(Sender).Checked(Class'HUD'.Default.bShowPersonalInfo);
			}
			else
			{
				if (Sender == Controls[5])
				{
					moCheckBox(Sender).Checked(Class'HUD'.Default.bShowPoints);
				}
				else
				{
					if (Sender == Controls[6])
					{
						moCheckBox(Sender).Checked(Class'HUD'.Default.bShowWeaponBar);
					}
					else
					{
						if (Sender == Controls[7])
						{
							moCheckBox(Sender).Checked(Class'HUD'.Default.bShowPortrait);
						}
						else
						{
							if (Sender == Controls[15])
							{
								moCheckBox(Sender).Checked((!Class'HUD'.Default.bNoEnemyNames));
							}
							else
							{
								if (Sender == Controls[8])
								{
									moNumericEdit(Sender).SetValue(Class'HUD'.Default.ConsoleMessageCount);
								}
								else
								{
									if (Sender == Controls[9])
									{
										moNumericEdit(Sender).SetValue((8 - Class'HUD'.Default.ConsoleFontSize));
									}
									else
									{
										if (Sender == Controls[10])
										{
											moNumericEdit(Sender).SetValue((Class'HUD'.Default.MessageFontOffset + 4));
										}
										else
										{
											if (Sender == Controls[12])
											{
												GUISlider(Sender).Value = (Class'HUD'.Default.HudScale * float(100));
											}
											else
											{
												if (Sender == Controls[14])
												{
													GUISlider(Sender).Value = ((Class'HUD'.Default.HudOpacity / float(255)) * float(100));
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
		}
	}
	*/
}

FString UTab_HudSettings::InternalOnSaveINI(UGUIComponent* Sender)
{
	return "FAKE";   //FAKE   /ELiZ
}

void UTab_HudSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if (Sender == Controls[2])
	{
		PlayerOwner().myHUD.bHideHUD = moCheckBox(Sender).IsChecked();
	}
	else
	{
		if (Sender == Controls[3])
		{
			PlayerOwner().myHUD.bShowWeaponInfo = moCheckBox(Sender).IsChecked();
		}
		else
		{
			if (Sender == Controls[4])
			{
				PlayerOwner().myHUD.bShowPersonalInfo = moCheckBox(Sender).IsChecked();
			}
			else
			{
				if (Sender == Controls[5])
				{
					PlayerOwner().myHUD.bShowPoints = moCheckBox(Sender).IsChecked();
				}
				else
				{
					if (Sender == Controls[6])
					{
						PlayerOwner().myHUD.bShowWeaponBar = moCheckBox(Sender).IsChecked();
					}
					else
					{
						if (Sender == Controls[7])
						{
							PlayerOwner().myHUD.bShowPortrait = moCheckBox(Sender).IsChecked();
						}
						else
						{
							if (Sender == Controls[15])
							{
								PlayerOwner().myHUD.bNoEnemyNames = (!moCheckBox(Sender).IsChecked());
							}
							else
							{
								if (Sender == Controls[8])
								{
									PlayerOwner().myHUD.ConsoleMessageCount = moNumericEdit(Sender).GetValue();
								}
								else
								{
									if (Sender == Controls[9])
									{
										PlayerOwner().myHUD.ConsoleFontSize = int(Abs(float((moNumericEdit(Sender).GetValue() - 8))));
									}
									else
									{
										if (Sender == Controls[10])
										{
											PlayerOwner().myHUD.MessageFontOffset = (moNumericEdit(Sender).GetValue() - 4);
										}
										else
										{
											if (Sender == Controls[12])
											{
												PlayerOwner().myHUD.HudScale = (GUISlider(Sender).Value / float(100));
											}
											else
											{
												if (Sender == Controls[14])
												{
													PlayerOwner().myHUD.HudOpacity = ((GUISlider(Sender).Value / float(100)) * float(255));
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
		}
	}
	PlayerOwner().myHUD.SaveConfig();
	*/
}