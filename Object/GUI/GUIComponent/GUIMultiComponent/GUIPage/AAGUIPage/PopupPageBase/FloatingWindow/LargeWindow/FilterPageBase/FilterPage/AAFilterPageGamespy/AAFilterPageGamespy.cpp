// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/FilterPageBase/FilterPage/AAFilterPageGamespy/AAFilterPageGamespy.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UAAFilterPageGamespy::UAAFilterPageGamespy()
{
	UmoCheckBox* FilterFull = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterFull->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterFull->CaptionWidth = 0.9;
	FilterFull->Caption = "Hide Full Servers";
	//FilterFull->OnCreateComponent=FilterFull.InternalOnCreateComponent;
	FilterFull->IniOption = "@Internal";
	FilterFull->Hint = "Select whether full servers should appear in the Server Browser";
	FilterFull->WinTop = 0.24;
	FilterFull->WinLeft = 0.25;
	FilterFull->WinWidth = 0.55;
	FilterFull->WinHeight = 0.048476;
	FilterFull->TabOrder = 0;
	FilterFull->bStandardized = false;
	//FilterFull->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterFull->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoCheckBox* FilterEmpty = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterEmpty->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterEmpty->CaptionWidth = 0.9;
	FilterEmpty->Caption = "Hide Empty Servers";
	//FilterEmpty->OnCreateComponent=FilterEmpty.InternalOnCreateComponent;
	FilterEmpty->IniOption = "@Internal";
	FilterEmpty->Hint = "Select whether to hide empty servers in the Server Browser";
	FilterEmpty->WinTop = 0.285;
	FilterEmpty->WinLeft = 0.25;
	FilterEmpty->WinWidth = 0.55;
	FilterEmpty->WinHeight = 0.048476;
	FilterEmpty->TabOrder = 1;
	FilterEmpty->bStandardized = false;
	//FilterEmpty->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterEmpty->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoCheckBox* FilterOfficial = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterOfficial->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterOfficial->CaptionWidth = 0.9;
	FilterOfficial->Caption = "Show Honor Gaining Servers Only";
	//FilterOfficial->OnCreateComponent=FilterOfficial.InternalOnCreateComponent;
	FilterOfficial->IniOption = "@Internal";
	FilterOfficial->Hint = "Select whether official servers should appear in the Server Browser";
	FilterOfficial->WinTop = 0.33;
	FilterOfficial->WinLeft = 0.25;
	FilterOfficial->WinWidth = 0.55;
	FilterOfficial->WinHeight = 0.048476;
	FilterOfficial->TabOrder = 2;
	FilterOfficial->bStandardized = false;
	//FilterOfficial->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterOfficial->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoCheckBox* FilterLeased = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterLeased->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterLeased->CaptionWidth = 0.9;
	FilterLeased->Caption = "Show Leased Servers Only";
	//FilterLeased->OnCreateComponent=FilterLeased.InternalOnCreateComponent;
	FilterLeased->IniOption = "@Internal";
	FilterLeased->Hint = "Select whether leased servers (honor gaining or not depending on \"Show Honor Gaining Servers Only\" option) should appear in the Server Browser";
	FilterLeased->WinTop = 0.375;
	FilterLeased->WinLeft = 0.25;
	FilterLeased->WinWidth = 0.55;
	FilterLeased->WinHeight = 0.048476;
	FilterLeased->TabOrder = 3;
	FilterLeased->bStandardized = false;
	//FilterLeased->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterLeased->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoCheckBox* FilterPassword = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterPassword->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterPassword->CaptionWidth = 0.9;
	FilterPassword->Caption = "Hide Servers Requiring A Password";
	//FilterPassword->OnCreateComponent=FilterPassword.InternalOnCreateComponent;
	FilterPassword->IniOption = "@Internal";
	FilterPassword->Hint = "Select whether password-protected servers should appear in the Server Browser";
	FilterPassword->WinTop = 0.42;
	FilterPassword->WinLeft = 0.25;
	FilterPassword->WinWidth = 0.55;
	FilterPassword->WinHeight = 0.048476;
	FilterPassword->TabOrder = 4;
	FilterPassword->bStandardized = false;
	//FilterPassword->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterPassword->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoCheckBox* FilterMILES = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterMILES->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterMILES->CaptionWidth = 0.9;
	FilterMILES->Caption = "Show Training Servers (MILES) Only";
	//FilterMILES->OnCreateComponent=FilterMILES.InternalOnCreateComponent;
	FilterMILES->IniOption = "@Internal";
	FilterMILES->Hint = "Select whether only MILES training servers should appear in the Server Browser.  Uncheck to show all live-fire and MILES.";
	FilterMILES->WinTop = 0.465;
	FilterMILES->WinLeft = 0.25;
	FilterMILES->WinWidth = 0.55;
	FilterMILES->WinHeight = 0.048476;
	FilterMILES->TabOrder = 5;
	FilterMILES->bStandardized = false;
	//FilterMILES->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterMILES->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoCheckBox* FilterCheats = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterCheats->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterCheats->CaptionWidth = 0.9;
	FilterCheats->Caption = "Show Cheat Mode Servers Only";
	//FilterCheats->OnCreateComponent=FilterCheats.InternalOnCreateComponent;
	FilterCheats->IniOption = "@Internal";
	FilterCheats->Hint = "Select whether cheats servers should appear in the Server Browser";
	FilterCheats->WinTop = 0.51;
	FilterCheats->WinLeft = 0.25;
	FilterCheats->WinWidth = 0.55;
	FilterCheats->WinHeight = 0.048476;
	FilterCheats->TabOrder = 6;
	FilterCheats->bStandardized = false;
	//FilterCheats->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterCheats->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoCheckBox* FilterPunkBuster = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterPunkBuster->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterPunkBuster->CaptionWidth = 0.9;
	FilterPunkBuster->Caption = "Show PunkBuster Protected Servers Only";
	//FilterPunkBuster->OnCreateComponent=FilterPunkBuster.InternalOnCreateComponent;
	FilterPunkBuster->IniOption = "@Internal";
	FilterPunkBuster->Hint = "Select whether PunkBuster-enabled servers should appear in the Server Browser";
	FilterPunkBuster->WinTop = 0.555;
	FilterPunkBuster->WinLeft = 0.25;
	FilterPunkBuster->WinWidth = 0.55;
	FilterPunkBuster->WinHeight = 0.048476;
	FilterPunkBuster->TabOrder = 7;
	FilterPunkBuster->bStandardized = false;
	//FilterPunkBuster->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterPunkBuster->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoCheckBox* FilterTournament = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterTournament->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterTournament->CaptionWidth = 0.9;
	FilterTournament->Caption = "Show Tournament Servers Only";
	//FilterTournament->OnCreateComponent=FilterTournament.InternalOnCreateComponent;
	FilterTournament->IniOption = "@Internal";
	FilterTournament->Hint = "Select whether tournament servers should appear in the Server Browser";
	FilterTournament->WinTop = 0.6;
	FilterTournament->WinLeft = 0.25;
	FilterTournament->WinWidth = 0.55;
	FilterTournament->WinHeight = 0.048476;
	FilterTournament->TabOrder = 8;
	FilterTournament->bStandardized = false;
	//FilterTournament->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterTournament->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoNumericEdit* FilterMinHonor = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	FilterMinHonor->MinValue = 0;
	FilterMinHonor->MaxValue = 100;
	FilterMinHonor->bAutoSizeCaption = false;
	FilterMinHonor->CaptionWidth = 0.4;
	FilterMinHonor->Caption = "Min Honor";
	//FilterMinHonor->OnCreateComponent=FilterMinHonor.InternalOnCreateComponent;
	FilterMinHonor->IniOption = "@Internal";
	FilterMinHonor->Hint = "Minimum Honor Level Servers that should appear in the Server Browser";
	FilterMinHonor->WinTop = 0.65;
	FilterMinHonor->WinLeft = 0.25;
	FilterMinHonor->WinWidth = 0.525;
	FilterMinHonor->TabOrder = 9;
	//FilterMinHonor->OnDeActivate=AAFilterPageGamespy.InternalOnMinMaxDeactivate;
	//FilterMinHonor->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterMinHonor->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoNumericEdit* FilterMaxHonor = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	FilterMaxHonor->MinValue = 0;
	FilterMaxHonor->MaxValue = 100;
	FilterMaxHonor->bAutoSizeCaption = false;
	FilterMaxHonor->CaptionWidth = 0.4;
	FilterMaxHonor->Caption = "Max Honor";
	//FilterMaxHonor->OnCreateComponent=FilterMaxHonor.InternalOnCreateComponent;
	FilterMaxHonor->IniOption = "@Internal";
	FilterMaxHonor->Hint = "Maximum Honor Level Servers that should appear in the Server Browser";
	FilterMaxHonor->WinTop = 0.7;
	FilterMaxHonor->WinLeft = 0.25;
	FilterMaxHonor->WinWidth = 0.525;
	FilterMaxHonor->TabOrder = 10;
	//FilterMaxHonor->OnDeActivate=AAFilterPageGamespy.InternalOnMinMaxDeactivate;
	//FilterMaxHonor->OnChange=AAFilterPageGamespy.InternalOnChange;
	//FilterMaxHonor->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UmoComboBox* MapFilter = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MapFilter->bReadOnly = true;
	MapFilter->ComponentJustification = EeTextAlign::TXTA_Left;
	MapFilter->CaptionWidth = 0.4;
	MapFilter->Caption = "Show Selected Map Only:";
	//MapFilter->OnCreateComponent=MapFilter.InternalOnCreateComponent;
	MapFilter->IniOption = "@Internal";
	MapFilter->Hint = "Select the mission that should appear in the Server Browser";
	MapFilter->WinTop = 0.75;
	MapFilter->WinLeft = 0.25;
	MapFilter->WinWidth = 0.525;
	MapFilter->TabOrder = 11;
	//MapFilter->OnChange=AAFilterPageGamespy.InternalOnChange;
	//MapFilter->OnLoadINI=AAFilterPageGamespy.InternalOnLoadINI;
	UGUIButton* SaveFilterButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SaveFilterButton->Caption = "Save Filter";
	SaveFilterButton->StyleName = "SquareMenuButton";
	SaveFilterButton->Hint = "Save and apply the currently selected server browser filtering options.";
	SaveFilterButton->WinTop = 0.91;
	SaveFilterButton->WinLeft = 0.12;
	SaveFilterButton->WinWidth = 0.22;
	SaveFilterButton->RenderWeight = 2;
	SaveFilterButton->TabOrder = 12;
	SaveFilterButton->bBoundToParent = true;
	//SaveFilterButton->OnClick=AAFilterPageGamespy.InternalOnClick;
	//SaveFilterButton->OnKeyEvent=SaveFilterButton.InternalOnKeyEvent;
	UGUIButton* CancelChanges = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelChanges->Caption = "Discard Changes";
	CancelChanges->StyleName = "SquareMenuButton";
	CancelChanges->Hint = "Discard server browser filter changes and return to server list.";
	CancelChanges->WinTop = 0.91;
	CancelChanges->WinLeft = 0.55;
	CancelChanges->WinWidth = 0.22;
	CancelChanges->RenderWeight = 2;
	CancelChanges->TabOrder = 13;
	CancelChanges->bBoundToParent = true;
	//CancelChanges->OnClick=AAFilterPageGamespy.InternalOnClick;
	//CancelChanges->OnKeyEvent=CancelChanges.InternalOnKeyEvent;
	bSaveFilter = SaveFilterButton;
	bCancel = CancelChanges;
	ch_Full = FilterFull;
	ch_Empty = FilterEmpty;
	ch_Official = FilterOfficial;
	ch_Leased = FilterLeased;
	ch_Password = FilterPassword;
	ch_MILES = FilterMILES;
	ch_Cheats = FilterCheats;
	ch_PunkBuster = FilterPunkBuster;
	ch_Tournament = FilterTournament;
	nu_MinHonor = FilterMinHonor;
	nu_MaxHonor = FilterMaxHonor;
	co_Map = MapFilter;
	bFilterHideFull = true;
	bFilterShowOfficial = true;
	bFilterShowPB = true;
	nFilterMinHonor = 1;
	nFilterMaxHonor = 100;
	sFilterMap = "ALL";
	WindowName = "Internet Server Browser Filters";
	WinLeft = 0.18;
	WinWidth = 0.66;
	WinHeight = 0.7;
}

void UAAFilterPageGamespy::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	t_WindowTitle.SetCaption("Server Browser Filters");
	Super::InitComponent(MyController, MyOwner);
	*/
}

void UAAFilterPageGamespy::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	switch (Sender)
	{
	case ch_Full:
		ch_Full.SetComponentValue(string(bFilterHideFull), true);
		break;
	case ch_Empty:
		ch_Empty.SetComponentValue(string(bFilterHideEmpty), false);
		break;
	case ch_Official:
		ch_Official.SetComponentValue(string(bFilterShowOfficial), true);
		break;
	case ch_Leased:
		ch_Leased.SetComponentValue(string(bFilterShowLeased), true);
		break;
	case ch_Password:
		ch_Password.SetComponentValue(string(bFilterHidePassword), false);
		break;
	case ch_MILES:
		ch_MILES.SetComponentValue(string(bFilterShowMiles), true);
		break;
	case ch_Cheats:
		ch_Cheats.SetComponentValue(string(bFilterShowCheat), true);
		break;
	case ch_PunkBuster:
		ch_PunkBuster.SetComponentValue(string(bFilterShowPB), true);
		break;
	case ch_Tournament:
		ch_Tournament.SetComponentValue(string(bFilterShowTournament), true);
		break;
	case nu_MinHonor:
		nu_MinHonor.SetComponentValue(string(nFilterMinHonor), true);
		break;
	case nu_MaxHonor:
		nu_MaxHonor.SetComponentValue(string(nFilterMaxHonor), true);
		break;
	case co_Map:
		LoadMapFilter(co_Map, "");
		co_Map.SetText(sFilterMap);
		break;
	default:
		Log(string(Name) @ "Unknown component calling LoadINI:" $ GUIMenuOption(Sender).Caption);
		GUIMenuOption(Sender).SetComponentValue(S, true);
	}
	*/
}

void UAAFilterPageGamespy::LoadMapFilter(UGUIComponent* Sender, FString S)
{
	/*
	int32 i = 0;
	int32 j = 0;
	int32 num_tours = 0;
	int32 num_missions = 0;
	FString File = "";
	FString TourName = "";
	FString MissionName = "";
	local TArray<FString> tourNames;
	int32 Index = 0;
	switch (Sender)
	{
	case co_Map:
		co_Map.addItem("ALL");
		File = GetBaseDir() $ "Tours.ini";
		num_tours = GetPrivateProfileInt(File, "Tours", "NumTours");
		i = 0;
		if (i < num_tours)
		{
			if (!PlayerOwner().Level.GetTourIsTraining(i))
			{
				TourName = PlayerOwner().Level.GetTourName(i);
				num_missions = PlayerOwner().Level.GetTourMissions(i);
				j = 0;
				if (j < num_missions)
				{
					MissionName = PlayerOwner().Level.GetTourMissionMBSTitle(i, j);
					Index = 0;
					if (Index < tourNames.Length)
					{
						if (MissionName <= tourNames[Index])
						{
							break;
						}
						else
						{
							if (((Index + 1) < tourNames.Length) && (MissionName <= tourNames[(Index + 1)]))
							{
								Index++;
							}
						}
					else
					{
						Index++;
					}
					}
				}
				if (Index < tourNames.Length)
				{
					tourNames.insert(Index, 1);
				}
				tourNames[Index] = MissionName;
				j++;
			}
		}
		i++;
	}
	for (Index = 0; Index < tourNames.Length; Index++)
	{
		co_Map.addItem(tourNames[Index]);
	}
	GOTO JL0207;
	default:
	JL0207:
	*/
}

void UAAFilterPageGamespy::SwapMinMaxHonorValues()
{
	/*
	int32 MinHonor = 0;
	MinHonor = nu_MinHonor.GetValue();
	nu_MinHonor.SetComponentValue(string(nu_MaxHonor.GetValue()), true);
	nu_MaxHonor.SetComponentValue(string(MinHonor), true);
	*/
}

void UAAFilterPageGamespy::InternalOnChange(UGUIComponent* Sender)
{
}

void UAAFilterPageGamespy::InternalOnMinMaxDeactivate()
{
	/*
	if (nu_MinHonor.GetValue() > nu_MaxHonor.GetValue())
	{
		SwapMinMaxHonorValues();
	}
	*/
}

void UAAFilterPageGamespy::SaveUserSelections()
{
	/*
	bFilterHideFull = ch_Full.IsChecked();
	bFilterHideEmpty = ch_Empty.IsChecked();
	bFilterShowOfficial = ch_Official.IsChecked();
	bFilterShowLeased = ch_Leased.IsChecked();
	bFilterHidePassword = ch_Password.IsChecked();
	bFilterShowMiles = ch_MILES.IsChecked();
	bFilterShowCheat = ch_Cheats.IsChecked();
	bFilterShowPB = ch_PunkBuster.IsChecked();
	bFilterShowTournament = ch_Tournament.IsChecked();
	nFilterMinHonor = nu_MinHonor.GetValue();
	nFilterMaxHonor = nu_MaxHonor.GetValue();
	sFilterMap = co_Map.GetText();
	*/
}

bool UAAFilterPageGamespy::InternalOnClick(UGUIComponent* guicSender)
{
	/*
	if (guicSender == bSaveFilter)
	{
		BuildFilterString();
		SaveSettings();
		Controller.CloseMenu(false);
		return true;
	}
	if (guicSender == bCancel)
	{
		Controller.CloseMenu(false);
		return true;
	}
	*/
	return false;
}

void UAAFilterPageGamespy::Closed(UGUIComponent* Sender, bool bCancelled)
{
	//Super::Closed(Sender, bCancelled);
}

void UAAFilterPageGamespy::BuildFilterString()
{
	/*
	FString sFilterString = "";
	if (sFilterMap == "ALL")
	{
		sFilterString = "";
	}
	else
	{
		sFilterString = "(mapname = '" $ sFilterMap $ "')";
	}
	if (bFilterHideFull)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(numplayers != maxplayers)");
	}
	if (bFilterHideEmpty)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(numplayers != 0)");
	}
	if (bFilterShowOfficial)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(official = 1)");
	}
	if (bFilterShowLeased)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(leased = 1)");
	}
	if (bFilterHidePassword)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(password = 0)");
	}
	if (bFilterShowMiles)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(miles = 1)");
	}
	if (bFilterShowCheat)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(cheats = 1)");
	}
	if (bFilterShowTournament)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(tournament = 1)");
	}
	if (bFilterShowPB)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(sv_punkbuster = 1)");
	}
	(sFilterString $ = NeedAnd(sFilterString) $ "(minhonor >= " $ string(nFilterMinHonor) $ ") AND (maxhonor <= " $ string(nFilterMaxHonor) $ ")");
	if (AABrowser_ServerListPageInternet(BrowserPage) != None)
	{
		AABrowser_ServerListPageInternet(BrowserPage).SetSBFilter(sFilterString);
	}
	*/
}

FString UAAFilterPageGamespy::NeedAnd(FString sFilter)
{
	FString MyString = "";
	/*
	if (sFilter != "")
	{
		MyString = " AND ";
	}
	*/
	return MyString;
}

void UAAFilterPageGamespy::SaveSettings()
{
	/*
	SaveUserSelections();
	BuildFilterString();
	SaveConfig();
	*/
}

void UAAFilterPageGamespy::ResetClicked()
{
}

void UAAFilterPageGamespy::ResetFilterToShowStandardServers()
{
	/*
	Default.bFilterHideFull = true;
	Default.bFilterHideEmpty = false;
	Default.bFilterShowOfficial = true;
	Default.bFilterShowLeased = false;
	Default.bFilterHidePassword = false;
	Default.bFilterShowMiles = false;
	Default.bFilterShowCheat = false;
	Default.bFilterShowTournament = false;
	Default.bFilterShowPB = true;
	Default.nFilterMinHonor = 1;
	Default.nFilterMaxHonor = 100;
	Default.sFilterMap = "ALL";
	*/
}
