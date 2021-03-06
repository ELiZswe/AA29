// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_FilterSetPanel/AABrowser_FilterSetPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAABrowser_FilterSetPanel::UAABrowser_FilterSetPanel()
{
	UGUIButton* ShowFiltersButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ShowFiltersButton->Caption = "List Filters";
	ShowFiltersButton->FontScale = EeFontScale::FNS_Small;
	ShowFiltersButton->WinTop = 0.463732;
	ShowFiltersButton->WinLeft = 0.5;
	ShowFiltersButton->WinWidth = 0.455923;
	ShowFiltersButton->WinHeight = 0.296775;
	//ShowFiltersButton->OnClick=AABrowser_FilterSetPanel.InternalOnClick;
	//ShowFiltersButton->OnKeyEvent=ShowFiltersButton.InternalOnKeyEvent;
	UGUIButton* ClearFiltersButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ClearFiltersButton->Caption = "Clear Filters";
	ClearFiltersButton->FontScale = EeFontScale::FNS_Small;
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
	PanelBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfill_Mat.backgroundfill_Mat'"), NULL, LOAD_None, NULL);
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
	int32 Index = 0;
	Super::InitComponent(MyController, MyOwner);
	for (Index = 0; Index < 5; Index++)
	{
		FilterSet->addItem("Set" + FString::FromInt(Index + 1),nullptr, "");
	}
}

void UAABrowser_FilterSetPanel::InternalOnChange(UGUIComponent* Sender)
{
	if (Sender == FilterSet)
	{
		//OnFilterSetChanged(Cast<UmoComboBox>(Sender).GetIndex());
	}
}

bool UAABrowser_FilterSetPanel::InternalOnClick(UGUIComponent* Sender)
{
	if (Sender == ClearFilters)
	{
		OnClearFilters();
		return true;
	}
	if (Sender == ShowFilters)
	{
		OnShowFilters();
		return true;
	}
	return false;
}

void UAABrowser_FilterSetPanel::testonly_SetFilterSetIndex(int32 NewIndex)
{
	FilterSet->SetIndex(NewIndex);
}

void UAABrowser_FilterSetPanel::testonly_ClearFiltersPress()
{
	ClearFilters->OnClick(ClearFilters);
}

void UAABrowser_FilterSetPanel::testonly_ShowFiltersPress()
{
	ShowFilters->OnClick(ShowFilters);
}
