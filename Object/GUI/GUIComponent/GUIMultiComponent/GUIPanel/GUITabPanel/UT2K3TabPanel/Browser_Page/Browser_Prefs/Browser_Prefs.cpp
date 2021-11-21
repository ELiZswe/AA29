// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_Prefs/Browser_Prefs.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UBrowser_Prefs::UBrowser_Prefs()
{
	UGUIButton* MyBackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyBackButton->Caption="BACK";
	MyBackButton->StyleName="SquareMenuButton";
	MyBackButton->WinWidth=0.2;
	MyBackButton->WinHeight=0.5;
	//MyBackButton->OnKeyEvent=MyBackButton.InternalOnKeyEvent;
	UGUIButton* MyKeyButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyKeyButton->Caption="ICON KEY";
	MyKeyButton->StyleName="SquareMenuButton";
	MyKeyButton->WinLeft=0.2;
	MyKeyButton->WinWidth=0.2;
	MyKeyButton->WinHeight=0.5;
	//MyKeyButton->OnKeyEvent=MyKeyButton.InternalOnKeyEvent;
	UmoCheckBox* NoPasswdCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NoPasswdCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	NoPasswdCheckBox->CaptionWidth=0.9;
	NoPasswdCheckBox->Caption="No Passworded Servers";
	//NoPasswdCheckBox->OnCreateComponent=NoPasswdCheckBox.InternalOnCreateComponent;
	NoPasswdCheckBox->IniOption="@Internal";
	NoPasswdCheckBox->WinTop=0.21;
	NoPasswdCheckBox->WinLeft=0.05;
	NoPasswdCheckBox->WinWidth=0.34;
	NoPasswdCheckBox->WinHeight=0.04;
	UmoCheckBox* NoFullCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NoFullCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	NoFullCheckBox->CaptionWidth=0.9;
	NoFullCheckBox->Caption="No Full Servers";
	//NoFullCheckBox->OnCreateComponent=NoFullCheckBox.InternalOnCreateComponent;
	NoFullCheckBox->IniOption="@Internal";
	NoFullCheckBox->WinTop=0.27;
	NoFullCheckBox->WinLeft=0.05;
	NoFullCheckBox->WinWidth=0.34;
	NoFullCheckBox->WinHeight=0.04;
	UmoCheckBox* NoEmptyCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NoEmptyCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	NoEmptyCheckBox->CaptionWidth=0.9;
	NoEmptyCheckBox->Caption="No Empty Servers";
	//NoEmptyCheckBox->OnCreateComponent=NoEmptyCheckBox.InternalOnCreateComponent;
	NoEmptyCheckBox->IniOption="@Internal";
	NoEmptyCheckBox->WinTop=0.33;
	NoEmptyCheckBox->WinLeft=0.05;
	NoEmptyCheckBox->WinWidth=0.34;
	NoEmptyCheckBox->WinHeight=0.04;
	UmoComboBox* StatsViewCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	StatsViewCombo->ComponentJustification = EeTextAlign::TXTA_Left;
	StatsViewCombo->CaptionWidth=0.4;
	StatsViewCombo->Caption="Stats Servers";
	//StatsViewCombo->OnCreateComponent=StatsViewCombo.InternalOnCreateComponent;
	StatsViewCombo->IniOption="@INTERNAL";
	StatsViewCombo->WinTop=0.39;
	StatsViewCombo->WinLeft=0.05;
	StatsViewCombo->WinWidth=0.76;
	StatsViewCombo->WinHeight=0.04;
	UmoComboBox* MutatorCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MutatorCombo->ComponentJustification = EeTextAlign::TXTA_Left;
	MutatorCombo->CaptionWidth=0;
	//MutatorCombo->OnCreateComponent=MutatorCombo.InternalOnCreateComponent;
	MutatorCombo->IniOption="@INTERNAL";
	MutatorCombo->WinTop=0.45;
	MutatorCombo->WinLeft=0.675004;
	MutatorCombo->WinWidth=0.30875;
	MutatorCombo->WinHeight=0.06;
	UmoEditBox* CustomQuery = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	CustomQuery->CaptionWidth=0.4;
	CustomQuery->Caption="Custom Query";
	//CustomQuery->OnCreateComponent=CustomQuery.InternalOnCreateComponent;
	CustomQuery->IniOption="@INTERNAL";
	CustomQuery->WinTop=0.75;
	CustomQuery->WinLeft=0.05;
	CustomQuery->WinWidth=0.76;
	CustomQuery->WinHeight=0.04;
	UmoCheckBox* OnlyStandardCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	OnlyStandardCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	OnlyStandardCheckBox->CaptionWidth=0.9;
	OnlyStandardCheckBox->Caption="Only Standard Servers";
	//OnlyStandardCheckBox->OnCreateComponent=OnlyStandardCheckBox.InternalOnCreateComponent;
	OnlyStandardCheckBox->IniOption="@Internal";
	OnlyStandardCheckBox->WinTop=0.15;
	OnlyStandardCheckBox->WinLeft=0.05;
	OnlyStandardCheckBox->WinWidth=0.34;
	OnlyStandardCheckBox->WinHeight=0.04;
	UmoComboBox* MutatorModeCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MutatorModeCombo->ComponentJustification = EeTextAlign::TXTA_Left;
	MutatorModeCombo->Caption="Mutators";
	//MutatorModeCombo->OnCreateComponent=MutatorModeCombo.InternalOnCreateComponent;
	MutatorModeCombo->IniOption="@INTERNAL";
	MutatorModeCombo->WinTop=0.45;
	MutatorModeCombo->WinLeft=0.05;
	MutatorModeCombo->WinWidth=0.61;
	MutatorModeCombo->WinHeight=0.04;
	UmoCheckBox* NoBotServersCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NoBotServersCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	NoBotServersCheckBox->CaptionWidth=0.9;
	NoBotServersCheckBox->Caption="No Servers With Bots";
	//NoBotServersCheckBox->OnCreateComponent=NoBotServersCheckBox.InternalOnCreateComponent;
	NoBotServersCheckBox->IniOption="@Internal";
	NoBotServersCheckBox->WinTop=0.39;
	NoBotServersCheckBox->WinLeft=0.05;
	NoBotServersCheckBox->WinWidth=0.34;
	NoBotServersCheckBox->WinHeight=0.04;
	NoBotServersCheckBox->bVisible=false;
	UmoComboBox* WeaponStayCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	WeaponStayCombo->ComponentJustification = EeTextAlign::TXTA_Left;
	WeaponStayCombo->CaptionWidth=0.4;
	WeaponStayCombo->Caption="WeaponStay";
	//WeaponStayCombo->OnCreateComponent=WeaponStayCombo.InternalOnCreateComponent;
	WeaponStayCombo->IniOption="@INTERNAL";
	WeaponStayCombo->WinTop=0.57;
	WeaponStayCombo->WinLeft=0.05;
	WeaponStayCombo->WinWidth=0.76;
	WeaponStayCombo->WinHeight=0.04;
	UmoComboBox* TranslocatorCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	TranslocatorCombo->ComponentJustification = EeTextAlign::TXTA_Left;
	TranslocatorCombo->CaptionWidth=0.4;
	TranslocatorCombo->Caption="Translocator";
	//TranslocatorCombo->OnCreateComponent=TranslocatorCombo.InternalOnCreateComponent;
	TranslocatorCombo->IniOption="@INTERNAL";
	TranslocatorCombo->WinTop=0.63;
	TranslocatorCombo->WinLeft=0.05;
	TranslocatorCombo->WinWidth=0.76;
	TranslocatorCombo->WinHeight=0.04;
	UmoComboBox* MutatorModeCombo2 = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MutatorModeCombo2->ComponentJustification = EeTextAlign::TXTA_Left;
	//MutatorModeCombo2->OnCreateComponent=MutatorModeCombo2.InternalOnCreateComponent;
	MutatorModeCombo2->IniOption="@INTERNAL";
	MutatorModeCombo2->WinTop=0.51;
	MutatorModeCombo2->WinLeft=0.05;
	MutatorModeCombo2->WinWidth=0.61;
	MutatorModeCombo2->WinHeight=0.04;
	UmoComboBox* MutatorCombo2 = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MutatorCombo2->ComponentJustification = EeTextAlign::TXTA_Left;
	MutatorCombo2->CaptionWidth=0;
	//MutatorCombo2->OnCreateComponent=MutatorCombo2.InternalOnCreateComponent;
	MutatorCombo2->IniOption="@INTERNAL";
	MutatorCombo2->WinTop=0.51;
	MutatorCombo2->WinLeft=0.675004;
	MutatorCombo2->WinWidth=0.30875;
	MutatorCombo2->WinHeight=0.06;
	UmoNumericEdit* MinGamespeed = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MinGamespeed->MinValue=0;
	MinGamespeed->MaxValue=200;
	MinGamespeed->ComponentJustification = EeTextAlign::TXTA_Left;
	MinGamespeed->CaptionWidth=0.7;
	MinGamespeed->Caption="Game Speed Min";
	//MinGamespeed->OnCreateComponent=MinGamespeed.InternalOnCreateComponent;
	MinGamespeed->IniOption="@INTERNAL";
	MinGamespeed->WinTop=0.69;
	MinGamespeed->WinLeft=0.05;
	MinGamespeed->WinWidth=0.43375;
	MinGamespeed->WinHeight=0.06;
	UmoNumericEdit* MaxGamespeed = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MaxGamespeed->MinValue=0;
	MaxGamespeed->MaxValue=200;
	MaxGamespeed->ComponentJustification = EeTextAlign::TXTA_Left;
	MaxGamespeed->CaptionWidth=0.4;
	MaxGamespeed->Caption="Max";
	//MaxGamespeed->OnCreateComponent=MaxGamespeed.InternalOnCreateComponent;
	MaxGamespeed->IniOption="@INTERNAL";
	MaxGamespeed->WinTop=0.69;
	MaxGamespeed->WinLeft=0.557501;
	MaxGamespeed->WinWidth=0.235;
	MaxGamespeed->WinHeight=0.06;
	UGUITitleBar* MyStatus = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	MyStatus->bUseTextHeight=false;
	MyStatus->Justification = EeTextAlign::TXTA_Left;
	MyStatus->StyleName="SquareBar";
	MyStatus->WinTop=0.5;
	MyStatus->WinHeight=0.5;
	UGUIPanel* FooterPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	FooterPanel->Controls = { MyBackButton,MyStatus,MyKeyButton };
	FooterPanel->WinTop=0.9;
	FooterPanel->WinHeight=0.1;
	UGUILabel* FilterTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	FilterTitle->Caption="Server Filtering Options:";
	FilterTitle->TextColor=FColor(0, 200, 230, 255);
	FilterTitle->TextFont="UT2HeaderFont";
	FilterTitle->WinTop=0.05;
	FilterTitle->WinLeft=0.15;
	FilterTitle->WinWidth=0.720003;
	FilterTitle->WinHeight=0.05625;

	ViewStatsStrings = { "Any Servers", "Only Stats Servers", "No Stats Servers" };
	MutatorModeStrings = { "Any Mutators", "No Mutators", "This Mutator", "Not This Mutator" };
	WeaponStayStrings = { "Any Servers", "Only Weapon Stay Servers", "No Weapon Stay Servers" };
	TranslocatorStrings = { "Any Servers", "Only Translocator Servers", "No Translocator Servers" };
	Controls = { FooterPanel,FilterTitle,NoPasswdCheckBox,NoFullCheckBox,NoEmptyCheckBox,StatsViewCombo,MutatorCombo,CustomQuery,OnlyStandardCheckBox,MutatorModeCombo,NoBotServersCheckBox,WeaponStayCombo,TranslocatorCombo,MutatorModeCombo2,MutatorCombo2,MinGamespeed,MaxGamespeed };
}

void UBrowser_Prefs::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	if (bIsInitialised)
	{
		return;
	}
	GUIButton(GUIPanel(Controls[0]).Controls[0]).__OnClick__Delegate = BackClick;
	moComboBox(Controls[5]).addItem(ViewStatsStrings[0]);
	moComboBox(Controls[5]).addItem(ViewStatsStrings[1]);
	moComboBox(Controls[5]).addItem(ViewStatsStrings[2]);
	moComboBox(Controls[5]).ReadOnly(true);
	moComboBox(Controls[9]).addItem(MutatorModeStrings[0]);
	moComboBox(Controls[9]).addItem(MutatorModeStrings[1]);
	moComboBox(Controls[9]).addItem(MutatorModeStrings[2]);
	moComboBox(Controls[9]).addItem(MutatorModeStrings[3]);
	moComboBox(Controls[9]).ReadOnly(true);
	moComboBox(Controls[13]).addItem(MutatorModeStrings[0]);
	moComboBox(Controls[13]).addItem(MutatorModeStrings[2]);
	moComboBox(Controls[13]).addItem(MutatorModeStrings[3]);
	moComboBox(Controls[13]).ReadOnly(true);
	moComboBox(Controls[6]).ReadOnly(true);
	moComboBox(Controls[11]).addItem(WeaponStayStrings[0]);
	moComboBox(Controls[11]).addItem(WeaponStayStrings[1]);
	moComboBox(Controls[11]).addItem(WeaponStayStrings[2]);
	moComboBox(Controls[11]).ReadOnly(true);
	moComboBox(Controls[12]).addItem(TranslocatorStrings[0]);
	moComboBox(Controls[12]).addItem(TranslocatorStrings[1]);
	moComboBox(Controls[12]).addItem(TranslocatorStrings[2]);
	moComboBox(Controls[12]).ReadOnly(true);
	moNumericEdit(Controls[15]).MyNumericEdit.Step = 10;
	moNumericEdit(Controls[16]).MyNumericEdit.Step = 10;
	for (i = 2; i < 17; i++)
	{
		Controls[i].__OnLoadINI__Delegate = MyOnLoadINI;
		Controls[i].__OnChange__Delegate = MyOnChange;
	}
	StatusBar = GUITitleBar(GUIPanel(Controls[0]).Controls[1]);
	GUIButton(GUIPanel(Controls[0]).Controls[2]).__OnClick__Delegate = InternalShowIconKey;
	bIsInitialised = true;
	*/
}

bool UBrowser_Prefs::BackClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}

void UBrowser_Prefs::UpdateMutatorVisibility()
{
	/*
	if ((Browser.ViewMutatorMode == 0) || (Browser.ViewMutatorMode == 1))
	{
		Controls[6].bVisible = false;
		Controls[13].bVisible = false;
		Controls[14].bVisible = false;
	}
	else
	{
		Controls[6].bVisible = true;
		Controls[13].bVisible = true;
		if (Browser.ViewMutator2Mode == 0)
		{
			Controls[14].bVisible = false;
		}
		else
		{
			Controls[14].bVisible = true;
		}
	}
	*/
}

bool UBrowser_Prefs::InternalShowIconKey(UGUIComponent* Sender)
{
	//Controller.OpenMenu("XInterface.Browser_IconKey");
	return true;
}

void UBrowser_Prefs::MyOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	if (Sender == Controls[8])
	{
		moCheckBox(Controls[8]).Checked(Browser.bOnlyShowStandard);
	}
	else
	{
		if (Sender == Controls[2])
		{
			moCheckBox(Controls[2]).Checked(Browser.bOnlyShowNonPassword);
		}
		else
		{
			if (Sender == Controls[3])
			{
				moCheckBox(Controls[3]).Checked(Browser.bDontShowFull);
			}
			else
			{
				if (Sender == Controls[4])
				{
					moCheckBox(Controls[4]).Checked(Browser.bDontShowEmpty);
				}
				else
				{
					if (Sender == Controls[5])
					{
						moComboBox(Controls[5]).SetText(ViewStatsStrings[Browser.StatsServerView]);
					}
					else
					{
						if (Sender == Controls[6])
						{
						}
						if (Sender == Controls[7])
						{
							moEditBox(Controls[7]).SetText(Browser.CustomQuery);
						}
						else
						{
							if (Sender == Controls[9])
							{
								moComboBox(Controls[9]).SetText(MutatorModeStrings[Browser.ViewMutatorMode]);
								UpdateMutatorVisibility();
							}
							else
							{
								if (Sender == Controls[10])
								{
									moCheckBox(Controls[10]).Checked(Browser.bDontShowWithBots);
								}
								else
								{
									if (Sender == Controls[11])
									{
										moComboBox(Controls[11]).SetText(WeaponStayStrings[Browser.WeaponStayServerView]);
									}
									else
									{
										if (Sender == Controls[12])
										{
											moComboBox(Controls[12]).SetText(TranslocatorStrings[Browser.TranslocServerView]);
										}
										else
										{
											if (Sender == Controls[13])
											{
												moComboBox(Controls[13]).SetText(MutatorModeStrings[Browser.ViewMutator2Mode]);
												UpdateMutatorVisibility();
											}
											else
											{
												if (Sender == Controls[14])
												{
												}
												if (Sender == Controls[15])
												{
													moNumericEdit(Controls[15]).SetValue(Browser.MinGamespeed);
												}
												else
												{
													if (Sender == Controls[16])
													{
														moNumericEdit(Controls[16]).SetValue(Browser.MaxGamespeed);
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
	}
	*/
}

void UBrowser_Prefs::MyOnChange(UGUIComponent* Sender)
{
	/*
	FString t = "";
	if (Sender == Controls[8])
	{
		Browser.bOnlyShowStandard = moCheckBox(Controls[8]).IsChecked();
	}
	else
	{
		if (Sender == Controls[2])
		{
			Browser.bOnlyShowNonPassword = moCheckBox(Controls[2]).IsChecked();
		}
		else
		{
			if (Sender == Controls[3])
			{
				Browser.bDontShowFull = moCheckBox(Controls[3]).IsChecked();
			}
			else
			{
				if (Sender == Controls[4])
				{
					Browser.bDontShowEmpty = moCheckBox(Controls[4]).IsChecked();
				}
				else
				{
					if (Sender == Controls[5])
					{
						t = moComboBox(Controls[5]).GetText();
						if (t == ViewStatsStrings[0])
						{
							Browser.StatsServerView = 0;
						}
						else
						{
							if (t == ViewStatsStrings[1])
							{
								Browser.StatsServerView = 1;
							}
							else
							{
								if (t == ViewStatsStrings[2])
								{
									Browser.StatsServerView = 2;
								}
							}
						}
					}
					else
					{
						if (Sender == Controls[6])
						{
							Browser.DesiredMutator = moComboBox(Controls[6]).GetExtra();
						}
						else
						{
							if (Sender == Controls[7])
							{
								Browser.CustomQuery = moEditBox(Controls[7]).GetText();
							}
							else
							{
								if (Sender == Controls[9])
								{
									t = moComboBox(Controls[9]).GetText();
									if (t == MutatorModeStrings[0])
									{
										Browser.ViewMutatorMode = 0;
									}
									else
									{
										if (t == MutatorModeStrings[1])
										{
											Browser.ViewMutatorMode = 1;
										}
										else
										{
											if (t == MutatorModeStrings[2])
											{
												Browser.ViewMutatorMode = 2;
											}
											else
											{
												if (t == MutatorModeStrings[3])
												{
													Browser.ViewMutatorMode = 3;
												}
											}
										}
									}
									UpdateMutatorVisibility();
								}
								else
								{
									if (Sender == Controls[10])
									{
										Browser.bDontShowWithBots = moCheckBox(Controls[10]).IsChecked();
									}
									else
									{
										if (Sender == Controls[11])
										{
											t = moComboBox(Controls[11]).GetText();
											if (t == WeaponStayStrings[0])
											{
												Browser.WeaponStayServerView = 0;
											}
											else
											{
												if (t == WeaponStayStrings[1])
												{
													Browser.WeaponStayServerView = 1;
												}
												else
												{
													if (t == WeaponStayStrings[2])
													{
														Browser.WeaponStayServerView = 2;
													}
												}
											}
										}
										else
										{
											if (Sender == Controls[12])
											{
												t = moComboBox(Controls[12]).GetText();
												if (t == TranslocatorStrings[0])
												{
													Browser.TranslocServerView = 0;
												}
												else
												{
													if (t == TranslocatorStrings[1])
													{
														Browser.TranslocServerView = 1;
													}
													else
													{
														if (t == TranslocatorStrings[2])
														{
															Browser.TranslocServerView = 2;
														}
													}
												}
											}
											else
											{
												if (Sender == Controls[13])
												{
													t = moComboBox(Controls[13]).GetText();
													if (t == MutatorModeStrings[0])
													{
														Browser.ViewMutator2Mode = 0;
													}
													else
													{
														if (t == MutatorModeStrings[2])
														{
															Browser.ViewMutator2Mode = 2;
														}
														else
														{
															if (t == MutatorModeStrings[3])
															{
																Browser.ViewMutator2Mode = 3;
															}
														}
													}
													UpdateMutatorVisibility();
												}
												else
												{
													if (Sender == Controls[14])
													{
														Browser.DesiredMutator2 = moComboBox(Controls[14]).GetExtra();
													}
													else
													{
														if (Sender == Controls[15])
														{
															if (moNumericEdit(Controls[15]).GetValue() < 0)
															{
																moNumericEdit(Controls[15]).SetValue(0);
															}
															Browser.MinGamespeed = moNumericEdit(Controls[15]).GetValue();
														}
														else
														{
															if (Sender == Controls[16])
															{
																if (moNumericEdit(Controls[16]).GetValue() > 200)
																{
																	moNumericEdit(Controls[16]).SetValue(200);
																}
																Browser.MaxGamespeed = moNumericEdit(Controls[16]).GetValue();
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
			}
		}
	}
	Browser.SaveConfig();
	*/
}
