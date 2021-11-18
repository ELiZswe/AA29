// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIFooter/ButtonFooter/AABrowser_Footer/AABrowser_Footer.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UAABrowser_Footer::UAABrowser_Footer()
{
	UmoCheckBox* PunkBusterCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	PunkBusterCheckBox->CaptionWidth = 0.9;
	PunkBusterCheckBox->Caption = "Enable PunkBuster";
	//PunkBusterCheckBox->OnCreateComponent=PunkBusterCheckBox.InternalOnCreateComponent;
	PunkBusterCheckBox->FontScale = EFontScale::FNS_Small;
	PunkBusterCheckBox->Hint = "Check this box to enable PunkBuster.";
	PunkBusterCheckBox->WinTop = 0.1;
	PunkBusterCheckBox->WinLeft = 0.02;
	PunkBusterCheckBox->WinWidth = 0.2;
	PunkBusterCheckBox->WinHeight = 0.053476;
	PunkBusterCheckBox->TabOrder = 6;
	PunkBusterCheckBox->bBoundToParent = true;
	PunkBusterCheckBox->bScaleToParent = true;
	PunkBusterCheckBox->bStandardized = false;
	UGUIButton* BrowserIconKey = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserIconKey->Caption = "ICON KEY";
	BrowserIconKey->MenuState = EMenuState::MSAT_Disabled;
	BrowserIconKey->StyleName = "SquareMenuButton";
	BrowserIconKey->WinTop = 0.1;
	BrowserIconKey->WinLeft = 0.771094;
	BrowserIconKey->WinWidth = 0.02;
	BrowserIconKey->WinHeight = 0.053476;
	BrowserIconKey->RenderWeight = 2;
	BrowserIconKey->TabOrder = 4;
	BrowserIconKey->bBoundToParent = true;
	//BrowserIconKey->OnClick=AABrowser_Footer.InternalOnClick;
	//BrowserIconKey->OnKeyEvent=BrowserIconKey.InternalOnKeyEvent;
	UGUIButton* BrowserJoin = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserJoin->Caption = "JOIN";
	BrowserJoin->MenuState = EMenuState::MSAT_Disabled;
	BrowserJoin->StyleName = "SquareMenuButton";
	BrowserJoin->WinTop = 0.1;
	BrowserJoin->WinLeft = 611;
	BrowserJoin->WinWidth = 0.02;
	BrowserJoin->WinHeight = 0.053476;
	BrowserJoin->RenderWeight = 2;
	BrowserJoin->TabOrder = 2;
	BrowserJoin->bBoundToParent = true;
	//BrowserJoin->OnClick=AABrowser_Footer.InternalOnClick;
	//BrowserJoin->OnKeyEvent=BrowserJoin.InternalOnKeyEvent;
	UGUIButton* BrowserSpec = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserSpec->Caption = "SPECTATE";
	BrowserSpec->MenuState = EMenuState::MSAT_Disabled;
	BrowserSpec->StyleName = "SquareMenuButton";
	BrowserSpec->WinTop = 0.1;
	BrowserSpec->WinLeft = 0.771094;
	BrowserSpec->WinWidth = 0.02;
	BrowserSpec->WinHeight = 0.053476;
	BrowserSpec->RenderWeight = 2;
	BrowserSpec->TabOrder = 1;
	BrowserSpec->bBoundToParent = true;
	//BrowserSpec->OnClick=AABrowser_Footer.InternalOnClick;
	//BrowserSpec->OnKeyEvent=BrowserSpec.InternalOnKeyEvent;
	UGUIButton* BrowserRefresh = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserRefresh->Caption = "REFRESH";
	BrowserRefresh->MenuState = EMenuState::MSAT_Disabled;
	BrowserRefresh->StyleName = "SquareMenuButton";
	BrowserRefresh->WinTop = 0.1;
	BrowserRefresh->WinLeft = 0.885352;
	BrowserRefresh->WinWidth = 0.02;
	BrowserRefresh->WinHeight = 0.053476;
	BrowserRefresh->RenderWeight = 2;
	BrowserRefresh->TabOrder = 0;
	BrowserRefresh->bBoundToParent = true;
	//BrowserRefresh->OnClick=AABrowser_Footer.InternalOnClick;
	//BrowserRefresh->OnKeyEvent=BrowserRefresh.InternalOnKeyEvent;
	UGUIButton* BrowserFilter = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserFilter->Caption = "FILTERS";
	BrowserFilter->bAutoSize = true;
	BrowserFilter->StyleName = "SquareMenuButton";
	BrowserFilter->Hint = "Filters allow more control over which servers will appear in the server browser lists.";
	BrowserFilter->WinTop = 0.17;
	BrowserFilter->WinWidth = 0.02;
	BrowserFilter->WinHeight = 0.053476;
	BrowserFilter->RenderWeight = 2;
	BrowserFilter->TabOrder = 5;
	BrowserFilter->bBoundToParent = true;
	//BrowserFilter->OnClick=AABrowser_Footer.InternalOnClick;
	//BrowserFilter->OnKeyEvent=BrowserFilter.InternalOnKeyEvent;
	UGUITitleBar* BrowserStatus = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	BrowserStatus->bUseTextHeight = false;
	BrowserStatus->Justification = EeTextAlign::TXTA_Right;
	BrowserStatus->FontScale = EFontScale::FNS_Small;
	BrowserStatus->WinTop = 0.030495;
	BrowserStatus->WinLeft = 0.238945;
	BrowserStatus->WinWidth = 0.761055;
	BrowserStatus->WinHeight = 0.053476;
	BrowserStatus->bBoundToParent = true;
	BrowserStatus->bScaleToParent = true;
	t_StatusBar = BrowserStatus;
	b_Join = BrowserJoin;
	b_Spectate = BrowserSpec;
	b_Refresh = BrowserRefresh;
	b_Filter = BrowserFilter;
	b_IconKey = BrowserIconKey;
	ch_PunkBuster = PunkBusterCheckBox;
	ButtonHeight = 0.04;
	bFullHeight = false;
	Justification = EeTextAlign::TXTA_Left;
	WinTop = 0.936927;
	WinHeight = 0.14;

	ButtonHeight = 0.04;
	bFullHeight = false;
	Justification = EeTextAlign::TXTA_Left;
	WinTop = 0.936927;
	WinHeight = 0.14;
}

bool UAABrowser_Footer::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (GUIButton(Sender) == None)
	{
		return false;
	}
	if (Sender == b_Back)
	{
		Controller.CloseMenu(False);
		return true;
	}
	if (Sender == b_Join)
	{
		p_Anchor.JoinClicked();
		return true;
	}
	if (Sender == b_Spectate)
	{
		p_Anchor.SpectateClicked();
		return true;
	}
	if (Sender == b_Refresh)
	{
		p_Anchor.RefreshClicked();
		return true;
	}
	if (Sender == b_Filter)
	{
		p_Anchor.FilterClicked();
		return true;
	}
	if (Sender == b_IconKey)
	{
		p_Anchor.IconKeyClicked();
		return true;
	}
	*/
	return false;
}

void UAABrowser_Footer::UpdateActiveButtons(UAABrowser_Page* CurrentPanel)
{
	/*
	if (CurrentPanel == None)
	{
		Return;
	}
	UpdateButtonState(b_Join, CurrentPanel.IsJoinAvailable(b_Join.Caption));
	UpdateButtonState(b_Refresh, CurrentPanel.IsRefreshAvailable(b_Refresh.Caption));
	UpdateButtonState(b_Spectate, CurrentPanel.IsSpectateAvailable(b_Spectate.Caption));
	UpdateButtonState(b_Filter, CurrentPanel.IsFilterAvailable(b_Filter.Caption));
	UpdateButtonState(b_IconKey, CurrentPanel.IsFilterAvailable(b_IconKey.Caption));
	*/
}

void UAABrowser_Footer::UpdateButtonState(UGUIButton* But, bool Active)
{
	/*
	if (Active)
	{
		EnableComponent(But);
	}
	else
	{
		DisableComponent(But);
	}
	*/
}

void UAABrowser_Footer::PositionButtons(UCanvas* C)
{
	/*
	local bool B;
	B = b_Filter.bVisible;
	b_Filter.bVisible = False;
	PositionButtons(C);
	b_Filter.bVisible = B;
	b_Filter.WinLeft = GetMargin();
	*/
}

float UAABrowser_Footer::GetButtonLeft()
{
	float Result=0;
	/*
	local bool bWasVisible;
	
	bWasVisible = b_Filter.bVisible;
	b_Filter.bVisible = False;
	Result = GetButtonLeft();
	b_Filter.bVisible = bWasVisible;
	*/
	return Result;
}