// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_FilterSetPanel/AABrowser_FilterSetPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAABrowser_FilterSetPanel::UAABrowser_FilterSetPanel()
{
	UGUIButton* ShowFiltersButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ShowFiltersButton->Caption = "List Filters";
	ShowFiltersButton->FontScale = EFontScale::FNS_Small;
	ShowFiltersButton->WinTop = 0.463732;
	ShowFiltersButton->WinLeft = 0.5;
	ShowFiltersButton->WinWidth = 0.455923;
	ShowFiltersButton->WinHeight = 0.296775;
	//ShowFiltersButton->OnClick=AABrowser_FilterSetPanel.InternalOnClick;
	//ShowFiltersButton->OnKeyEvent=ShowFiltersButton.InternalOnKeyEvent;
	UGUIButton* ClearFiltersButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ClearFiltersButton->Caption = "Clear Filters";
	ClearFiltersButton->FontScale = EFontScale::FNS_Small;
	ClearFiltersButton->WinTop = 0.463732;
	ClearFiltersButton->WinLeft = 0.019757;
	ClearFiltersButton->WinWidth = 0.455923;
	ClearFiltersButton->WinHeight = 0.296775;
	//ClearFiltersButton->OnClick=AABrowser_FilterSetPanel.InternalOnClick;
	//ClearFiltersButton->OnKeyEvent=ClearFiltersButton.InternalOnKeyEvent;
	UmoComboBox* FilterSetComboBox = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	FilterSetComboBox->bReadOnly = true;
	FilterSetComboBox->Caption = "Filter Sets:";
	FilterSetComboBox->LabelStyleName = "SmallText";
	//FilterSetComboBox->OnCreateComponent=FilterSetComboBox.InternalOnCreateComponent;
	FilterSetComboBox->WinTop = 0.12317;
	FilterSetComboBox->WinLeft = 0.034574;
	FilterSetComboBox->WinWidth = 0.935791;
	FilterSetComboBox->WinHeight = 0.246339;
	FilterSetComboBox->bBoundToParent = true;
	//FilterSetComboBox->OnChange=AABrowser_FilterSetPanel.InternalOnChange;
	UGUIImage* PanelBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	PanelBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	PanelBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	PanelBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PanelBackground->WinHeight = 1;
	PanelBackground->RenderWeight = 0;
	PanelBackground->bBoundToParent = true;
	PanelBackground->bScaleToParent = true;
	BackgroundBorder = PanelBackground;
	FilterSet = FilterSetComboBox;
	ClearFilters = ClearFiltersButton;
	ShowFilters = ShowFiltersButton;
}

void UAABrowser_FilterSetPanel::OnFilterSetChanged(int32 NewFilterSet)
{
}

void UAABrowser_FilterSetPanel::OnClearFilters()
{
}

void UAABrowser_FilterSetPanel::OnShowFilters()
{
}

void UAABrowser_FilterSetPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int Index;
	InitComponent(MyController, MyOwner);
	for (Index = 0; Index < 5; Index++)
	{
		FilterSet.addItem("Set" @ Index + 1);
	}
	*/
}

void UAABrowser_FilterSetPanel::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Sender == FilterSet)
	{
		OnFilterSetChanged(moComboBox(Sender).GetIndex());
	}
	*/
}

void UAABrowser_FilterSetPanel::InternalOnClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case ClearFilters:
				OnClearFilters();
				Return True;
				break;
			case ShowFilters:
				OnShowFilters();
				Return True;
				break;
			default:
				Return False;
				break;
	}
	*/
}

void UAABrowser_FilterSetPanel::testonly_SetFilterSetIndex(int32 NewIndex)
{
	//FilterSet.SetIndex(NewIndex);
}

void UAABrowser_FilterSetPanel::testonly_ClearFiltersPress()
{
	//ClearFilters.OnClick(ClearFilters);
}

void UAABrowser_FilterSetPanel::testonly_ShowFiltersPress()
{
	//ShowFilters.OnClick(ShowFilters);
}
