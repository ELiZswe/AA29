// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/FilterPageBase/FilterPage/AAFilterPage/AAFilterPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAFilterPage::UAAFilterPage()
{
	UmoCheckBox* FilterByOptions = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterByOptions->bAutoSizeCaption = false;
	FilterByOptions->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterByOptions->CaptionWidth = 0;
	//FilterByOptions->OnCreateComponent=FilterByOptions.InternalOnCreateComponent;
	FilterByOptions->IniOption = "@Internal";
	FilterByOptions->Hint = "Select to filter servers by the various options.";
	FilterByOptions->WinTop = 0.07;
	FilterByOptions->WinLeft = 0.015;
	FilterByOptions->WinWidth = 0.05;
	FilterByOptions->WinHeight = 0.048476;
	FilterByOptions->bBoundToParent = true;
	FilterByOptions->bStandardized = false;
	//FilterByOptions->OnChange=AAFilterPage.InternalOnChange;
	//FilterByOptions->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterByServerName = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterByServerName->bAutoSizeCaption = false;
	FilterByServerName->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterByServerName->CaptionWidth = 0;
	//FilterByServerName->OnCreateComponent=FilterByServerName.InternalOnCreateComponent;
	FilterByServerName->IniOption = "@Internal";
	FilterByServerName->Hint = "Select to filter servers by the server name.";
	FilterByServerName->WinTop = 0.836666;
	FilterByServerName->WinLeft = 0.015;
	FilterByServerName->WinWidth = 0.05;
	FilterByServerName->WinHeight = 0.048476;
	FilterByServerName->bBoundToParent = true;
	FilterByServerName->bStandardized = false;
	//FilterByServerName->OnChange=AAFilterPage.InternalOnChange;
	//FilterByServerName->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterByPlayerName = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterByPlayerName->bAutoSizeCaption = false;
	FilterByPlayerName->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterByPlayerName->CaptionWidth = 0;
	//FilterByPlayerName->OnCreateComponent=FilterByPlayerName.InternalOnCreateComponent;
	FilterByPlayerName->IniOption = "@Internal";
	FilterByPlayerName->Hint = "Select to filter servers by the players on them.";
	FilterByPlayerName->WinTop = 0.89;
	FilterByPlayerName->WinLeft = 0.0135;
	FilterByPlayerName->WinWidth = 0.05;
	FilterByPlayerName->WinHeight = 0.048476;
	FilterByPlayerName->bBoundToParent = true;
	FilterByPlayerName->bStandardized = false;
	//FilterByPlayerName->OnChange=AAFilterPage.InternalOnChange;
	//FilterByPlayerName->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterFull = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterFull->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterFull->CaptionWidth = 0.9;
	FilterFull->Caption = "Hide Full Servers";
	//FilterFull->OnCreateComponent=FilterFull.InternalOnCreateComponent;
	FilterFull->IniOption = "@Internal";
	FilterFull->Hint = "Select whether full servers should appear in the Server Browser";
	FilterFull->WinTop = 0.086667;
	FilterFull->WinLeft = 0.09375;
	FilterFull->WinWidth = 0.55;
	FilterFull->WinHeight = 0.048476;
	FilterFull->TabOrder = 0;
	FilterFull->bBoundToParent = true;
	FilterFull->bStandardized = false;
	//FilterFull->OnChange=AAFilterPage.InternalOnChange;
	//FilterFull->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterEmpty = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterEmpty->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterEmpty->CaptionWidth = 0.9;
	FilterEmpty->Caption = "Hide Empty Servers";
	//FilterEmpty->OnCreateComponent=FilterEmpty.InternalOnCreateComponent;
	FilterEmpty->IniOption = "@Internal";
	FilterEmpty->Hint = "Select whether to hide empty servers in the Server Browser";
	FilterEmpty->WinTop = 0.131667;
	FilterEmpty->WinLeft = 0.09375;
	FilterEmpty->WinWidth = 0.55;
	FilterEmpty->WinHeight = 0.048476;
	FilterEmpty->TabOrder = 1;
	FilterEmpty->bBoundToParent = true;
	FilterEmpty->bStandardized = false;
	//FilterEmpty->OnChange=AAFilterPage.InternalOnChange;
	//FilterEmpty->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterOfficial = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterOfficial->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterOfficial->CaptionWidth = 0.9;
	FilterOfficial->Caption = "Show Honor Gaining Servers Only";
	//FilterOfficial->OnCreateComponent=FilterOfficial.InternalOnCreateComponent;
	FilterOfficial->IniOption = "@Internal";
	FilterOfficial->Hint = "Select whether official servers should appear in the Server Browser";
	FilterOfficial->WinTop = 0.175;
	FilterOfficial->WinLeft = 0.09375;
	FilterOfficial->WinWidth = 0.55;
	FilterOfficial->WinHeight = 0.048476;
	FilterOfficial->TabOrder = 2;
	FilterOfficial->bBoundToParent = true;
	FilterOfficial->bStandardized = false;
	//FilterOfficial->OnChange=AAFilterPage.InternalOnChange;
	//FilterOfficial->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterLeased = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterLeased->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterLeased->CaptionWidth = 0.9;
	FilterLeased->Caption = "Show Leased Servers Only";
	//FilterLeased->OnCreateComponent=FilterLeased.InternalOnCreateComponent;
	FilterLeased->IniOption = "@Internal";
	FilterLeased->Hint = "Select whether leased servers (honor gaining or not depending on \"Show Honor Gaining Servers Only\" option) should appear in the Server Browser";
	FilterLeased->WinTop = 0.216667;
	FilterLeased->WinLeft = 0.09375;
	FilterLeased->WinWidth = 0.55;
	FilterLeased->WinHeight = 0.048476;
	FilterLeased->TabOrder = 3;
	FilterLeased->bBoundToParent = true;
	FilterLeased->bStandardized = false;
	//FilterLeased->OnChange=AAFilterPage.InternalOnChange;
	//FilterLeased->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterPassword = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterPassword->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterPassword->CaptionWidth = 0.9;
	FilterPassword->Caption = "Hide Servers Requiring A Password";
	//FilterPassword->OnCreateComponent=FilterPassword.InternalOnCreateComponent;
	FilterPassword->IniOption = "@Internal";
	FilterPassword->Hint = "Select whether password-protected servers should appear in the Server Browser";
	FilterPassword->WinTop = 0.26;
	FilterPassword->WinLeft = 0.09375;
	FilterPassword->WinWidth = 0.55;
	FilterPassword->WinHeight = 0.048476;
	FilterPassword->TabOrder = 4;
	FilterPassword->bBoundToParent = true;
	FilterPassword->bStandardized = false;
	//FilterPassword->OnChange=AAFilterPage.InternalOnChange;
	//FilterPassword->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterMILES = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterMILES->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterMILES->CaptionWidth = 0.9;
	FilterMILES->Caption = "Show Training Servers (MILES) Only";
	//FilterMILES->OnCreateComponent=FilterMILES.InternalOnCreateComponent;
	FilterMILES->IniOption = "@Internal";
	FilterMILES->Hint = "Select whether only MILES training servers should appear in the Server Browser.  Uncheck to show all live-fire and MILES.";
	FilterMILES->WinTop = 0.3;
	FilterMILES->WinLeft = 0.09375;
	FilterMILES->WinWidth = 0.55;
	FilterMILES->WinHeight = 0.048476;
	FilterMILES->TabOrder = 5;
	FilterMILES->bBoundToParent = true;
	FilterMILES->bStandardized = false;
	//FilterMILES->OnChange=AAFilterPage.InternalOnChange;
	//FilterMILES->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterCheats = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterCheats->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterCheats->CaptionWidth = 0.9;
	FilterCheats->Caption = "Show Cheat Mode Servers Only";
	//FilterCheats->OnCreateComponent=FilterCheats.InternalOnCreateComponent;
	FilterCheats->IniOption = "@Internal";
	FilterCheats->Hint = "Select whether cheats servers should appear in the Server Browser";
	FilterCheats->WinTop = 0.341667;
	FilterCheats->WinLeft = 0.09375;
	FilterCheats->WinWidth = 0.55;
	FilterCheats->WinHeight = 0.048476;
	FilterCheats->TabOrder = 6;
	FilterCheats->bBoundToParent = true;
	FilterCheats->bStandardized = false;
	//FilterCheats->OnChange=AAFilterPage.InternalOnChange;
	//FilterCheats->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterPunkBuster = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterPunkBuster->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterPunkBuster->CaptionWidth = 0.9;
	FilterPunkBuster->Caption = "Show PunkBuster Protected Servers Only";
	//FilterPunkBuster->OnCreateComponent=FilterPunkBuster.InternalOnCreateComponent;
	FilterPunkBuster->IniOption = "@Internal";
	FilterPunkBuster->Hint = "Select whether PunkBuster-enabled servers should appear in the Server Browser";
	FilterPunkBuster->WinTop = 0.39;
	FilterPunkBuster->WinLeft = 0.09375;
	FilterPunkBuster->WinWidth = 0.55;
	FilterPunkBuster->WinHeight = 0.048476;
	FilterPunkBuster->TabOrder = 7;
	FilterPunkBuster->bBoundToParent = true;
	FilterPunkBuster->bStandardized = false;
	//FilterPunkBuster->OnChange=AAFilterPage.InternalOnChange;
	//FilterPunkBuster->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterTournament = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterTournament->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterTournament->CaptionWidth = 0.9;
	FilterTournament->Caption = "Show Tournament Servers Only";
	//FilterTournament->OnCreateComponent=FilterTournament.InternalOnCreateComponent;
	FilterTournament->IniOption = "@Internal";
	FilterTournament->Hint = "Select whether tournament servers should appear in the Server Browser";
	FilterTournament->WinTop = 0.438333;
	FilterTournament->WinLeft = 0.09375;
	FilterTournament->WinWidth = 0.55;
	FilterTournament->WinHeight = 0.048476;
	FilterTournament->TabOrder = 8;
	FilterTournament->bBoundToParent = true;
	FilterTournament->bStandardized = false;
	//FilterTournament->OnChange=AAFilterPage.InternalOnChange;
	//FilterTournament->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterHonorByMinMax = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterHonorByMinMax->bAutoSizeCaption = false;
	FilterHonorByMinMax->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterHonorByMinMax->CaptionWidth = 0;
	//FilterHonorByMinMax->OnCreateComponent=FilterHonorByMinMax.InternalOnCreateComponent;
	FilterHonorByMinMax->IniOption = "@Internal";
	FilterHonorByMinMax->Hint = "Select to filter servers by their minimum and maximum honor settings.";
	FilterHonorByMinMax->WinTop = 0.506667;
	FilterHonorByMinMax->WinLeft = 0.03375;
	FilterHonorByMinMax->WinWidth = 0.05;
	FilterHonorByMinMax->WinHeight = 0.048476;
	FilterHonorByMinMax->bBoundToParent = true;
	FilterHonorByMinMax->bStandardized = false;
	//FilterHonorByMinMax->OnChange=AAFilterPage.InternalOnChange;
	//FilterHonorByMinMax->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoCheckBox* FilterHonorByAverage = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	FilterHonorByAverage->bAutoSizeCaption = false;
	FilterHonorByAverage->ComponentJustification = EeTextAlign::TXTA_Left;
	FilterHonorByAverage->CaptionWidth = 0;
	//FilterHonorByAverage->OnCreateComponent=FilterHonorByAverage.InternalOnCreateComponent;
	FilterHonorByAverage->IniOption = "@Internal";
	FilterHonorByAverage->Hint = "Select to filter servers by the average honor of the players.";
	FilterHonorByAverage->WinTop = 0.585;
	FilterHonorByAverage->WinLeft = 0.03375;
	FilterHonorByAverage->WinWidth = 0.05;
	FilterHonorByAverage->WinHeight = 0.048476;
	FilterHonorByAverage->bBoundToParent = true;
	FilterHonorByAverage->bStandardized = false;
	//FilterHonorByAverage->OnChange=AAFilterPage.InternalOnChange;
	//FilterHonorByAverage->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoNumericEdit* FilterMinHonor = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	FilterMinHonor->MinValue = 0;
	FilterMinHonor->MaxValue = 100;
	FilterMinHonor->bAutoSizeCaption = false;
	FilterMinHonor->CaptionWidth = 0.4;
	FilterMinHonor->Caption = "Min Honor";
	//FilterMinHonor->OnCreateComponent=FilterMinHonor.InternalOnCreateComponent;
	FilterMinHonor->IniOption = "@Internal";
	FilterMinHonor->Hint = "Minimum Honor Level Servers that should appear in the Server Browser";
	FilterMinHonor->WinTop = 0.498333;
	FilterMinHonor->WinLeft = 0.09375;
	FilterMinHonor->WinWidth = 0.525;
	FilterMinHonor->TabOrder = 9;
	FilterMinHonor->bBoundToParent = true;
	//FilterMinHonor->OnDeActivate=AAFilterPage.InternalOnMinMaxDeactivate;
	//FilterMinHonor->OnChange=AAFilterPage.InternalOnChange;
	//FilterMinHonor->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoNumericEdit* FilterMaxHonor = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	FilterMaxHonor->MinValue = 0;
	FilterMaxHonor->MaxValue = 100;
	FilterMaxHonor->bAutoSizeCaption = false;
	FilterMaxHonor->CaptionWidth = 0.4;
	FilterMaxHonor->Caption = "Max Honor";
	//FilterMaxHonor->OnCreateComponent=FilterMaxHonor.InternalOnCreateComponent;
	FilterMaxHonor->IniOption = "@Internal";
	FilterMaxHonor->Hint = "Maximum Honor Level Servers that should appear in the Server Browser";
	FilterMaxHonor->WinTop = 0.54;
	FilterMaxHonor->WinLeft = 0.09375;
	FilterMaxHonor->WinWidth = 0.525;
	FilterMaxHonor->TabOrder = 10;
	FilterMaxHonor->bBoundToParent = true;
	//FilterMaxHonor->OnDeActivate=AAFilterPage.InternalOnMinMaxDeactivate;
	//FilterMaxHonor->OnChange=AAFilterPage.InternalOnChange;
	//FilterMaxHonor->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoNumericEdit* FilterAverageHonor = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	FilterAverageHonor->MinValue = 1;
	FilterAverageHonor->MaxValue = 100;
	FilterAverageHonor->bAutoSizeCaption = false;
	FilterAverageHonor->CaptionWidth = 0.6;
	FilterAverageHonor->Caption = "Average Player Honor";
	//FilterAverageHonor->OnCreateComponent=FilterAverageHonor.InternalOnCreateComponent;
	FilterAverageHonor->IniOption = "@Internal";
	FilterAverageHonor->Hint = "Average Honor of players playing on servers that should appear in the Server Browser";
	FilterAverageHonor->WinTop = 0.595;
	FilterAverageHonor->WinLeft = 0.09375;
	FilterAverageHonor->WinWidth = 0.525;
	FilterAverageHonor->TabOrder = 11;
	FilterAverageHonor->bBoundToParent = true;
	//FilterAverageHonor->OnChange=AAFilterPage.InternalOnChange;
	//FilterAverageHonor->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoComboBox* CountryFilter = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	CountryFilter->bReadOnly = true;
	CountryFilter->ComponentJustification = EeTextAlign::TXTA_Left;
	CountryFilter->CaptionWidth = 0.4;
	CountryFilter->Caption = "Limit To Servers In Country:";
	//CountryFilter->OnCreateComponent=CountryFilter.InternalOnCreateComponent;
	CountryFilter->IniOption = "@Internal";
	CountryFilter->Hint = "Select the country where servers that should appear in the Server Browser are located";
	CountryFilter->WinTop = 0.693333;
	CountryFilter->WinLeft = 0.09375;
	CountryFilter->WinWidth = 0.525;
	CountryFilter->TabOrder = 12;
	CountryFilter->bBoundToParent = true;
	//CountryFilter->OnChange=AAFilterPage.InternalOnChange;
	//CountryFilter->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoComboBox* MapFilter = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MapFilter->bReadOnly = true;
	MapFilter->ComponentJustification = EeTextAlign::TXTA_Left;
	MapFilter->CaptionWidth = 0.4;
	MapFilter->Caption = "Show Selected Map Only:";
	//MapFilter->OnCreateComponent=MapFilter.InternalOnCreateComponent;
	MapFilter->IniOption = "@Internal";
	MapFilter->Hint = "Select the mission that should appear in the Server Browser";
	MapFilter->WinTop = 0.738333;
	MapFilter->WinLeft = 0.09375;
	MapFilter->WinWidth = 0.525;
	MapFilter->TabOrder = 13;
	MapFilter->bBoundToParent = true;
	//MapFilter->OnChange=AAFilterPage.InternalOnChange;
	//MapFilter->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoComboBox* TourFilter = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	TourFilter->bReadOnly = true;
	TourFilter->ComponentJustification = EeTextAlign::TXTA_Left;
	TourFilter->CaptionWidth = 0.4;
	TourFilter->Caption = "Show Selected Tour Only:";
	//TourFilter->OnCreateComponent=TourFilter.InternalOnCreateComponent;
	TourFilter->IniOption = "@Internal";
	TourFilter->Hint = "Select the tour that should appear in the Server Browser";
	TourFilter->WinTop = 0.785;
	TourFilter->WinLeft = 0.09375;
	TourFilter->WinWidth = 0.525;
	TourFilter->TabOrder = 14;
	TourFilter->bBoundToParent = true;
	//TourFilter->OnChange=AAFilterPage.InternalOnChange;
	//TourFilter->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoEditBox* ServerNameFilter = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	ServerNameFilter->ComponentJustification = EeTextAlign::TXTA_Left;
	ServerNameFilter->CaptionWidth = 0.4;
	ServerNameFilter->Caption = "Server Name";
	//ServerNameFilter->OnCreateComponent=ServerNameFilter.InternalOnCreateComponent;
	ServerNameFilter->IniOption = "@Internal";
	ServerNameFilter->Hint = "Enter a server name to search for. If unsure of the spelling add a \"*\" to the front or back to search for partial matches.";
	ServerNameFilter->WinTop = 0.848333;
	ServerNameFilter->WinLeft = 0.09375;
	ServerNameFilter->WinWidth = 0.525;
	ServerNameFilter->TabOrder = 15;
	ServerNameFilter->bBoundToParent = true;
	//ServerNameFilter->OnChange=AAFilterPage.InternalOnChange;
	//ServerNameFilter->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UmoEditBox* PlayerNameFilter = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PlayerNameFilter->ComponentJustification = EeTextAlign::TXTA_Left;
	PlayerNameFilter->CaptionWidth = 0.4;
	PlayerNameFilter->Caption = "Player Name";
	//PlayerNameFilter->OnCreateComponent=PlayerNameFilter.InternalOnCreateComponent;
	PlayerNameFilter->IniOption = "@Internal";
	PlayerNameFilter->Hint = "Enter a player name to search for. If unsure of the spelling add a \"*\" to the front or back to search for partial matches.";
	PlayerNameFilter->WinTop = 0.898333;
	PlayerNameFilter->WinLeft = 0.09375;
	PlayerNameFilter->WinWidth = 0.525;
	PlayerNameFilter->TabOrder = 16;
	PlayerNameFilter->bBoundToParent = true;
	//PlayerNameFilter->OnChange=AAFilterPage.InternalOnChange;
	//PlayerNameFilter->OnLoadINI=AAFilterPage.InternalOnLoadINI;
	UGUIButton* SaveFilterButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SaveFilterButton->Caption = "Save Filter";
	SaveFilterButton->StyleName = "SquareMenuButton";
	SaveFilterButton->Hint = "Save and apply the currently selected server browser filtering options.";
	SaveFilterButton->WinTop = 0.95;
	SaveFilterButton->WinLeft = 0.12;
	SaveFilterButton->WinWidth = 0.22;
	SaveFilterButton->RenderWeight = 2;
	SaveFilterButton->TabOrder = 17;
	SaveFilterButton->bBoundToParent = true;
	//SaveFilterButton->OnClick=AAFilterPage.InternalOnClick;
	//SaveFilterButton->OnKeyEvent=SaveFilterButton.InternalOnKeyEvent;
	UGUIButton* CancelChanges = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CancelChanges->Caption = "Discard Changes";
	CancelChanges->StyleName = "SquareMenuButton";
	CancelChanges->Hint = "Discard server browser filter changes and return to server list.";
	CancelChanges->WinTop = 0.95;
	CancelChanges->WinLeft = 0.55;
	CancelChanges->WinWidth = 0.22;
	CancelChanges->RenderWeight = 2;
	CancelChanges->TabOrder = 18;
	CancelChanges->bBoundToParent = true;
	//CancelChanges->OnClick=AAFilterPage.InternalOnClick;
	//CancelChanges->OnKeyEvent=CancelChanges.InternalOnKeyEvent;
	UGUIImage* OptionsFiltersBorder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	OptionsFiltersBorder->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	OptionsFiltersBorder->ImageStyle = EImgStyle::ISTY_Stretched;
	OptionsFiltersBorder->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	OptionsFiltersBorder->WinTop = 0.07;
	OptionsFiltersBorder->WinLeft = 0.015;
	OptionsFiltersBorder->WinWidth = 0.63;
	OptionsFiltersBorder->WinHeight = 0.724997;
	OptionsFiltersBorder->RenderWeight = 0.01;
	OptionsFiltersBorder->bBoundToParent = true;
	UGUIImage* ServerNameFiltersBorder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ServerNameFiltersBorder->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	ServerNameFiltersBorder->ImageStyle = EImgStyle::ISTY_Stretched;
	ServerNameFiltersBorder->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	ServerNameFiltersBorder->WinTop = 0.836666;
	ServerNameFiltersBorder->WinLeft = 0.015;
	ServerNameFiltersBorder->WinWidth = 0.63;
	ServerNameFiltersBorder->WinHeight = 0.0475;
	ServerNameFiltersBorder->RenderWeight = 0.01;
	ServerNameFiltersBorder->bBoundToParent = true;
	UGUIImage* PlayerNameFiltersBorder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	PlayerNameFiltersBorder->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	PlayerNameFiltersBorder->ImageStyle = EImgStyle::ISTY_Stretched;
	PlayerNameFiltersBorder->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PlayerNameFiltersBorder->WinTop = 0.891667;
	PlayerNameFiltersBorder->WinLeft = 0.015;
	PlayerNameFiltersBorder->WinWidth = 0.63;
	PlayerNameFiltersBorder->WinHeight = 0.0475;
	PlayerNameFiltersBorder->RenderWeight = 0.01;
	PlayerNameFiltersBorder->bBoundToParent = true;
	i_OptionsFiltersBorder = OptionsFiltersBorder;
	i_ServerNameFiltersBorder = ServerNameFiltersBorder;
	i_PlayerNameFiltersBorder = PlayerNameFiltersBorder;
	bSaveFilter = SaveFilterButton;
	bCancel = CancelChanges;
	ch_FilterByOptions = FilterByOptions;
	ch_FilterByServerName = FilterByServerName;
	ch_FilterByPlayerName = FilterByPlayerName;
	ch_Full = FilterFull;
	ch_Empty = FilterEmpty;
	ch_Official = FilterOfficial;
	ch_Leased = FilterLeased;
	ch_Password = FilterPassword;
	ch_MILES = FilterMILES;
	ch_Cheats = FilterCheats;
	ch_PunkBuster = FilterPunkBuster;
	ch_Tournament = FilterTournament;
	ch_FilterHonorByMinMax = FilterHonorByMinMax;
	ch_FilterHonorByAverage = FilterHonorByAverage;
	nu_MinHonor = FilterMinHonor;
	nu_MaxHonor = FilterMaxHonor;
	co_Map = MapFilter;
	co_Country = CountryFilter;
	nu_AverageHonor = FilterAverageHonor;
	co_Tour = TourFilter;
	ed_ServerName = ServerNameFilter;
	ed_PlayerName = PlayerNameFilter;

	Countries.SetNum(229);
	Countries[0] = "United States";
	Countries[1] = "Afghanistan";
	Countries[2] = "Albania";
	Countries[3] = "Algeria";
	Countries[4] = "American Samoa";
	Countries[5] = "Andorra";
	Countries[6] = "Angola";
	Countries[7] = "Anguilla";
	Countries[8] = "Anonymous Proxy";
	Countries[9] = "Antarctica";
	Countries[10] = "Antigua and Barbuda";
	Countries[11] = "Argentina";
	Countries[12] = "Armenia";
	Countries[13] = "Aruba";
	Countries[14] = "Asia/Pacific Region";
	Countries[15] = "Australia";
	Countries[16] = "Austria";
	Countries[17] = "Azerbaijan";
	Countries[18] = "Bahamas";
	Countries[19] = "Bahrain";
	Countries[20] = "Bangladesh";
	Countries[21] = "Barbados";
	Countries[22] = "Belarus";
	Countries[23] = "Belgium";
	Countries[24] = "Belize";
	Countries[25] = "Benin";
	Countries[26] = "Bermuda";
	Countries[27] = "Bhutan";
	Countries[28] = "Bolivia";
	Countries[29] = "Bosnia and Herzegovina";
	Countries[30] = "Botswana";
	Countries[31] = "Bouvet Island";
	Countries[32] = "Brazil";
	Countries[33] = "British Indian Ocean Territory";
	Countries[34] = "Brunei Darussalam";
	Countries[35] = "Bulgaria";
	Countries[36] = "Burkina Faso";
	Countries[37] = "Burundi";
	Countries[38] = "Cambodia";
	Countries[39] = "Cameroon";
	Countries[40] = "Canada";
	Countries[41] = "Cape Verde";
	Countries[42] = "Cayman Islands";
	Countries[43] = "Central African Republic";
	Countries[44] = "Chad";
	Countries[45] = "Chile";
	Countries[46] = "China";
	Countries[47] = "Colombia";
	Countries[48] = "Comoros";
	Countries[49] = "Congo";
	Countries[50] = "Congo, The Democratic Republic of the";
	Countries[51] = "Cook Islands";
	Countries[52] = "Costa Rica";
	Countries[53] = "Cote D'Ivoire";
	Countries[54] = "Croatia";
	Countries[55] = "Cyprus";
	Countries[56] = "Czech Republic";
	Countries[57] = "Denmark";
	Countries[58] = "Djibouti";
	Countries[59] = "Dominica";
	Countries[60] = "Dominican Republic";
	Countries[61] = "Ecuador";
	Countries[62] = "Egypt";
	Countries[63] = "El Salvador";
	Countries[64] = "Equatorial Guinea";
	Countries[65] = "Eritrea";
	Countries[66] = "Estonia";
	Countries[67] = "Ethiopia";
	Countries[68] = "Europe (other)";
	Countries[69] = "Falkland Islands (Malvinas)";
	Countries[70] = "Faroe Islands";
	Countries[71] = "Fiji";
	Countries[72] = "Finland";
	Countries[73] = "France";
	Countries[74] = "French Guiana";
	Countries[75] = "French Polynesia";
	Countries[76] = "French Southern Territories";
	Countries[77] = "Gabon";
	Countries[78] = "Gambia";
	Countries[79] = "Georgia";
	Countries[80] = "Germany";
	Countries[81] = "Ghana";
	Countries[82] = "Gibraltar";
	Countries[83] = "Greece";
	Countries[84] = "Greenland";
	Countries[85] = "Grenada";
	Countries[86] = "Guadeloupe";
	Countries[87] = "Guam";
	Countries[88] = "Guatemala";
	Countries[89] = "Guinea";
	Countries[90] = "Guinea-Bissau";
	Countries[91] = "Guyana";
	Countries[92] = "Haiti";
	Countries[93] = "Heard Island and McDonald Islands";
	Countries[94] = "Holy See (Vatican City State)";
	Countries[95] = "Honduras";
	Countries[96] = "Hong Kong";
	Countries[97] = "Hungary";
	Countries[98] = "Iceland";
	Countries[99] = "India";
	Countries[100] = "Indonesia";
	Countries[101] = "Iraq";
	Countries[102] = "Ireland";
	Countries[103] = "Israel";
	Countries[104] = "Italy";
	Countries[105] = "Jamaica";
	Countries[106] = "Japan";
	Countries[107] = "Jordan";
	Countries[108] = "Kazakstan";
	Countries[109] = "Kenya";
	Countries[110] = "Kiribati";
	Countries[111] = "Korea, Republic of";
	Countries[112] = "Kuwait";
	Countries[113] = "Kyrgyzstan";
	Countries[114] = "Lao People's Democratic Republic";
	Countries[115] = "Latvia";
	Countries[116] = "Lebanon";
	Countries[117] = "Lesotho";
	Countries[118] = "Liberia";
	Countries[119] = "Liechtenstein";
	Countries[120] = "Lithuania";
	Countries[121] = "Luxembourg";
	Countries[122] = "Macau";
	Countries[123] = "Macedonia";
	Countries[124] = "Madagascar";
	Countries[125] = "Malawi";
	Countries[126] = "Malaysia";
	Countries[127] = "Maldives";
	Countries[128] = "Mali";
	Countries[129] = "Malta";
	Countries[130] = "Marshall Islands";
	Countries[131] = "Martinique";
	Countries[132] = "Mauritania";
	Countries[133] = "Mauritius";
	Countries[134] = "Mayotte";
	Countries[135] = "Mexico";
	Countries[136] = "Micronesia, Federated States of";
	Countries[137] = "Moldova, Republic of";
	Countries[138] = "Monaco";
	Countries[139] = "Mongolia";
	Countries[140] = "Montserrat";
	Countries[141] = "Morocco";
	Countries[142] = "Mozambique";
	Countries[143] = "Myanmar";
	Countries[144] = "Namibia";
	Countries[145] = "Nauru";
	Countries[146] = "Nepal";
	Countries[147] = "Netherlands";
	Countries[148] = "Netherlands Antilles";
	Countries[149] = "New Caledonia";
	Countries[150] = "New Zealand";
	Countries[151] = "Nicaragua";
	Countries[152] = "Niger";
	Countries[153] = "Nigeria";
	Countries[154] = "Niue";
	Countries[155] = "Norfolk Island";
	Countries[156] = "Northern Mariana Islands";
	Countries[157] = "Norway";
	Countries[158] = "Oman";
	Countries[159] = "Pakistan";
	Countries[160] = "Palau";
	Countries[161] = "Palestinian Territory, Occupied";
	Countries[162] = "Panama";
	Countries[163] = "Papua New Guinea";
	Countries[164] = "Paraguay";
	Countries[165] = "Peru";
	Countries[166] = "Philippines";
	Countries[167] = "Poland";
	Countries[168] = "Portugal";
	Countries[169] = "Puerto Rico";
	Countries[170] = "Qatar";
	Countries[171] = "Reunion";
	Countries[172] = "Romania";
	Countries[173] = "Russian Federation";
	Countries[174] = "Rwanda";
	Countries[175] = "Saint Kitts and Nevis";
	Countries[176] = "Saint Lucia";
	Countries[177] = "Saint Vincent and the Grenadines";
	Countries[178] = "Samoa";
	Countries[179] = "San Marino";
	Countries[180] = "Sao Tome and Principe";
	Countries[181] = "Satellite Provider";
	Countries[182] = "Saudi Arabia";
	Countries[183] = "Senegal";
	Countries[184] = "Seychelles";
	Countries[185] = "Sierra Leone";
	Countries[186] = "Singapore";
	Countries[187] = "Slovakia";
	Countries[188] = "Slovenia";
	Countries[189] = "Solomon Islands";
	Countries[190] = "Somalia";
	Countries[191] = "South Africa";
	Countries[192] = "Spain";
	Countries[193] = "Sri Lanka";
	Countries[194] = "Suriname";
	Countries[195] = "Swaziland";
	Countries[196] = "Sweden";
	Countries[197] = "Switzerland";
	Countries[198] = "Taiwan";
	Countries[199] = "Tajikistan";
	Countries[200] = "Tanzania, United Republic of";
	Countries[201] = "Thailand";
	Countries[202] = "Togo";
	Countries[203] = "Tokelau";
	Countries[204] = "Tonga";
	Countries[205] = "Trinidad and Tobago";
	Countries[206] = "Tunisia";
	Countries[207] = "Turkey";
	Countries[208] = "Turkmenistan";
	Countries[209] = "Turks and Caicos Islands";
	Countries[210] = "Tuvalu";
	Countries[211] = "Uganda";
	Countries[212] = "Ukraine";
	Countries[213] = "United Arab Emirates";
	Countries[214] = "United Kingdom";
	Countries[215] = "United States";
	Countries[216] = "United States Minor Outlying Islands";
	Countries[217] = "Uruguay";
	Countries[218] = "Uzbekistan";
	Countries[219] = "Vanuatu";
	Countries[220] = "Venezuela";
	Countries[221] = "Vietnam";
	Countries[222] = "Virgin Islands, British";
	Countries[223] = "Virgin Islands, U.S.";
	Countries[224] = "Wallis and Futuna";
	Countries[225] = "Yemen";
	Countries[226] = "Yugoslavia";
	Countries[227] = "Zambia";
	Countries[228] = "Zimbabwe";

	sFilterBy = "Options";
	bFilterHideFull = true;
	bFilterShowOfficial = true;
	bFilterShowPB = true;
	sFilterHonorBy = "MinMax";
	nFilterMinHonor = 1;
	nFilterMaxHonor = 100;
	nFilterAverageHonor = 15;
	sFilterMap = "ALL";
	sFilterCountry = "ALL";
	sFilterTour = "ALL";
	WindowName = "Internet Server Browser Filters";
	WinTop = 0.05;
	WinLeft = 0.18;
	WinWidth = 0.66;
	WinHeight = 0.95;
}


//const AVERAGE_HONOR_RANGE = 5;
//const ALL_TOURS = -1;

void UAAFilterPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	t_WindowTitle.SetCaption("Server Browser Filters");
	Super::InitComponent(MyController, MyOwner);
	*/
}

void UAAFilterPage::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	switch (Sender)
	{
	case ch_FilterByOptions:
		if ((!(sFilterBy ~= "ServerName")) && (!(sFilterBy ~= "PlayerName")))
		{
			ch_FilterByOptions.SetComponentValue(string(true), true);
			ActivateFilterByOptions();
		}
		break;
	case ch_FilterByServerName:
		if (sFilterBy ~= "ServerName")
		{
			ch_FilterByServerName.SetComponentValue(string(true), true);
			ActivateFilterByServerName();
		}
		break;
	case ch_FilterByPlayerName:
		if (sFilterBy ~= "PlayerName")
		{
			ch_FilterByPlayerName.SetComponentValue(string(true), true);
			ActivateFilterByPlayerName();
		}
		break;
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
	case ch_FilterHonorByMinMax:
		if (!(sFilterHonorBy ~= "Average"))
		{
			ch_FilterHonorByMinMax.SetComponentValue(string(true), true);
			if ((!(sFilterBy ~= "ServerName")) && (!(sFilterBy ~= "PlayerName")))
			{
				ActivateFilterHonorByMinMax();
			}
		}
		break;
	case ch_FilterHonorByAverage:
		if (sFilterHonorBy ~= "Average")
		{
			ch_FilterHonorByAverage.SetComponentValue(string(true), true);
			if ((!(sFilterBy ~= "ServerName")) && (!(sFilterBy ~= "PlayerName")))
			{
				ActivateFilterHonorByAverage();
			}
		}
		break;
	case nu_MinHonor:
		nu_MinHonor.SetComponentValue(string(nFilterMinHonor), true);
		break;
	case nu_MaxHonor:
		nu_MaxHonor.SetComponentValue(string(nFilterMaxHonor), true);
		break;
	case nu_AverageHonor:
		nu_AverageHonor.SetComponentValue(string(nFilterAverageHonor), true);
		break;
	case co_Map:
		LoadMapFilter(co_Map, "");
		co_Map.SetText(sFilterMap);
		break;
	case co_Country:
		LoadCountryFilter();
		co_Country.SetText(sFilterCountry);
		break;
	case co_Tour:
		LoadTourFilter();
		co_Tour.SetText(sFilterTour);
		break;
	case ed_ServerName:
		ed_ServerName.SetText(sFilterServerName);
		break;
	case ed_PlayerName:
		ed_PlayerName.SetText(sFilterPlayerName);
		break;
	default:
		Log(string(Name) @ "Unknown component calling LoadINI:" $ GUIMenuOption(Sender).Caption);
		GUIMenuOption(Sender).SetComponentValue(S, true);
	}
	*/
}

void UAAFilterPage::LoadMapFilter(UGUIComponent* Sender, FString S)
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

void UAAFilterPage::LoadTourFilter()
{
	/*
	int32 Index = 0;
	co_Tour.addItem("ALL");
	for (Index = 0; Index < PlayerOwner().Level.iNumTours; Index++)
	{
		if (!PlayerOwner().Level.GetTourIsTraining(Index))
		{
			co_Tour.addItem(PlayerOwner().Level.GetTourName(Index));
		}
	}
	*/
}

void UAAFilterPage::LoadCountryFilter()
{
	/*
	int32 Index = 0;
	co_Country.addItem("ALL");
	for (Index = 0; Index < Countries.Length; Index++)
	{
		co_Country.addItem(Countries[Index]);
	}
	*/
}

void UAAFilterPage::ActivateFilterHonorByMinMax()
{
	/*
	sFilterHonorBy = "MinMax";
	ch_FilterHonorByMinMax.bValueReadOnly = true;
	ch_FilterHonorByAverage.bValueReadOnly = false;
	ch_FilterHonorByAverage.SetComponentValue(string(false), true);
	nu_MinHonor.EnableMe();
	nu_MaxHonor.EnableMe();
	nu_AverageHonor.DisableMe();
	*/
}

void UAAFilterPage::ActivateFilterHonorByAverage()
{
	/*
	sFilterHonorBy = "Average";
	ch_FilterHonorByAverage.bValueReadOnly = true;
	ch_FilterHonorByMinMax.bValueReadOnly = false;
	ch_FilterHonorByMinMax.SetComponentValue(string(false), true);
	nu_MinHonor.DisableMe();
	nu_MaxHonor.DisableMe();
	nu_AverageHonor.EnableMe();
	*/
}

void UAAFilterPage::ActivateFilterByOptions()
{
	/*
	sFilterBy = "Options";
	ch_FilterByOptions.bValueReadOnly = true;
	ch_FilterByServerName.bValueReadOnly = false;
	ch_FilterByServerName.SetComponentValue(string(false), true);
	ch_FilterByPlayerName.bValueReadOnly = false;
	ch_FilterByPlayerName.SetComponentValue(string(false), true);
	ch_Full.EnableMe();
	ch_Empty.EnableMe();
	ch_Official.EnableMe();
	ch_Leased.EnableMe();
	ch_Password.EnableMe();
	ch_MILES.EnableMe();
	ch_Cheats.EnableMe();
	ch_PunkBuster.EnableMe();
	ch_Tournament.EnableMe();
	ch_FilterHonorByMinMax.EnableMe();
	ch_FilterHonorByAverage.EnableMe();
	if (!(sFilterHonorBy ~= "Average"))
	{
		ActivateFilterHonorByMinMax();
	}
	else
	{
		ActivateFilterHonorByAverage();
	}
	co_Map.EnableMe();
	co_Country.EnableMe();
	co_Tour.EnableMe();
	ed_ServerName.DisableMe();
	ed_PlayerName.DisableMe();
	*/
}

void UAAFilterPage::DisableOptionsFilters()
{
	/*
	ch_Full.DisableMe();
	ch_Empty.DisableMe();
	ch_Official.DisableMe();
	ch_Leased.DisableMe();
	ch_Password.DisableMe();
	ch_MILES.DisableMe();
	ch_Cheats.DisableMe();
	ch_PunkBuster.DisableMe();
	ch_Tournament.DisableMe();
	ch_FilterHonorByMinMax.DisableMe();
	ch_FilterHonorByAverage.DisableMe();
	nu_MinHonor.DisableMe();
	nu_MaxHonor.DisableMe();
	co_Map.DisableMe();
	co_Country.DisableMe();
	nu_AverageHonor.DisableMe();
	co_Tour.DisableMe();
	*/
}

void UAAFilterPage::ActivateFilterByServerName()
{
	/*
	sFilterBy = "ServerName";
	ch_FilterByOptions.bValueReadOnly = false;
	ch_FilterByOptions.SetComponentValue(string(false), true);
	ch_FilterByServerName.bValueReadOnly = true;
	ch_FilterByPlayerName.bValueReadOnly = false;
	ch_FilterByPlayerName.SetComponentValue(string(false), true);
	DisableOptionsFilters();
	ed_ServerName.EnableMe();
	ed_PlayerName.DisableMe();
	*/
}

void UAAFilterPage::ActivateFilterByPlayerName()
{
	/*
	sFilterBy = "PlayerName";
	ch_FilterByOptions.bValueReadOnly = false;
	ch_FilterByOptions.SetComponentValue(string(false), true);
	ch_FilterByServerName.bValueReadOnly = false;
	ch_FilterByServerName.SetComponentValue(string(false), true);
	ch_FilterByPlayerName.bValueReadOnly = true;
	DisableOptionsFilters();
	ed_ServerName.DisableMe();
	ed_PlayerName.EnableMe();
	*/
}

void UAAFilterPage::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case ch_FilterByOptions:
		if (ch_FilterByOptions.IsChecked())
		{
			ActivateFilterByOptions();
		}
		break;
	case ch_FilterByServerName:
		if (ch_FilterByServerName.IsChecked())
		{
			ActivateFilterByServerName();
		}
		break;
	case ch_FilterByPlayerName:
		if (ch_FilterByPlayerName.IsChecked())
		{
			ActivateFilterByPlayerName();
		}
		break;
	case ch_FilterHonorByMinMax:
		if (ch_FilterHonorByMinMax.IsChecked())
		{
			ActivateFilterHonorByMinMax();
		}
		break;
	case ch_FilterHonorByAverage:
		if (ch_FilterHonorByAverage.IsChecked())
		{
			ActivateFilterHonorByAverage();
		}
		break;
	default:
	}
	*/
}

void UAAFilterPage::SwapMinMaxHonorValues()
{
	/*
	int32 MinHonor = 0;
	MinHonor = nu_MinHonor.GetValue();
	nu_MinHonor.SetComponentValue(string(nu_MaxHonor.GetValue()), true);
	nu_MaxHonor.SetComponentValue(string(MinHonor), true);
	*/
}

void UAAFilterPage::InternalOnMinMaxDeactivate()
{
	/*
	if (nu_MinHonor.GetValue() > nu_MaxHonor.GetValue())
	{
		SwapMinMaxHonorValues();
	}
	*/
}

void UAAFilterPage::SaveUserSelections()
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
	nFilterAverageHonor = nu_AverageHonor.GetValue();
	sFilterMap = co_Map.GetText();
	sFilterCountry = co_Country.GetText();
	sFilterTour = co_Tour.GetText();
	sFilterServerName = ed_ServerName.GetText();
	sFilterPlayerName = ed_PlayerName.GetText();
	*/
}

bool UAAFilterPage::InternalOnClick(UGUIComponent* guicSender)
{
	/*
	if (guicSender == bSaveFilter)
	{
		BuildFilterList();
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

void UAAFilterPage::Closed(UGUIComponent* Sender, bool bCancelled)
{
	//Super::Closed(Sender, bCancelled);
}

int32 UAAFilterPage::GetTourIndexByName(FString TourName)
{
	/*
	int32 Index = 0;
	for (Index = 0; Index < PlayerOwner().Level.iNumTours; Index++)
	{
		if (TourName ~= PlayerOwner().Level.GetTourName(Index))
		{
			return Index;
		}
	}
	*/
	return -1;
}

void UAAFilterPage::BuildFilterList()
{
	/*
	local TArray<ServerBrowserBase.FilterItem> FilterList;
	local ServerBrowserBase.FilterItem filter;
	int32 Tour = 0;
	if (sFilterBy ~= "ServerName")
	{
		if (Len(sFilterServerName) != 0)
		{
			filter.Key = "serverName";
			filter.Value = sFilterServerName;
			FilterList[FilterList.Length] = filter;
		}
	}
	else
	{
		if (sFilterBy ~= "PlayerName")
		{
			if (Len(sFilterPlayerName) != 0)
			{
				filter.Key = "playerName";
				filter.Value = sFilterPlayerName;
				FilterList[FilterList.Length] = filter;
			}
		}
		else
		{
			if (!(sFilterMap ~= "ALL"))
			{
				filter.Key = "mapName";
				filter.Value = sFilterMap;
				FilterList[FilterList.Length] = filter;
			}
			if (bFilterHideFull)
			{
				filter.Key = "playerCount";
				filter.Value = "<maxPlayers";
				FilterList[FilterList.Length] = filter;
			}
			if (bFilterHideEmpty)
			{
				filter.Key = "playerCount";
				filter.Value = ">0";
				FilterList[FilterList.Length] = filter;
			}
			if (bFilterShowOfficial)
			{
				filter.Key = "official";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (bFilterShowLeased)
			{
				filter.Key = "leased";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (bFilterHidePassword)
			{
				filter.Key = "requiresPassword";
				filter.Value = "0";
				FilterList[FilterList.Length] = filter;
			}
			if (bFilterShowMiles)
			{
				filter.Key = "miles";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (bFilterShowCheat)
			{
				filter.Key = "cheats";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (bFilterShowTournament)
			{
				filter.Key = "tournament";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (bFilterShowPB)
			{
				filter.Key = "punkbuster";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (!(sFilterHonorBy ~= "Average"))
			{
				if (nFilterMinHonor > 1)
				{
					filter.Key = "minHonor";
					filter.Value = ">=" $ string(nFilterMinHonor);
					FilterList[FilterList.Length] = filter;
				}
				if (nFilterMaxHonor < 100)
				{
					filter.Key = "maxHonor";
					filter.Value = "<=" $ string(nFilterMaxHonor);
					FilterList[FilterList.Length] = filter;
				}
			}
			else
			{
				filter.Key = "averageHonor";
				filter.Value = ">=" $ string(Clamp((nFilterAverageHonor - 5), 1, 100));
				FilterList[FilterList.Length] = filter;
				filter.Key = "averageHonor";
				filter.Value = "<=" $ string(Clamp((nFilterAverageHonor + 5), 1, 100));
				FilterList[FilterList.Length] = filter;
			}
			if (!(sFilterCountry ~= "ALL"))
			{
				filter.Key = "locale";
				filter.Value = sFilterCountry;
				FilterList[FilterList.Length] = filter;
			}
			Tour = GetTourIndexByName(sFilterTour);
			if (Tour != -1)
			{
				filter.Key = "tour";
				filter.Value = string(Tour);
				FilterList[FilterList.Length] = filter;
			}
		}
	}
	if (AABrowser_ServerListPageInternet(BrowserPage) != None)
	{
		AABrowser_ServerListPageInternet(BrowserPage).SetServerBrowserFilterList(FilterList);
	}
	*/
}

void UAAFilterPage::SaveSettings()
{
	/*
	SaveUserSelections();
	BuildFilterList();
	SaveConfig();
	*/
}

void UAAFilterPage::ResetClicked()
{
}

void UAAFilterPage::ResetFilterToShowStandardServers()
{
	/*
	Default.sFilterBy = "Options";
	Default.bFilterHideFull = true;
	Default.bFilterHideEmpty = false;
	Default.bFilterShowOfficial = true;
	Default.bFilterShowLeased = false;
	Default.bFilterHidePassword = false;
	Default.bFilterShowMiles = false;
	Default.bFilterShowCheat = false;
	Default.bFilterShowTournament = false;
	Default.bFilterShowPB = true;
	Default.sFilterHonorBy = "MinMax";
	Default.nFilterMinHonor = 1;
	Default.nFilterMaxHonor = 100;
	Default.nFilterAverageHonor = 15;
	Default.sFilterMap = "ALL";
	Default.sFilterCountry = "ALL";
	Default.sFilterTour = "ALL";
	Default.sFilterServerName = "";
	Default.sFilterPlayerName = "";
	*/
}