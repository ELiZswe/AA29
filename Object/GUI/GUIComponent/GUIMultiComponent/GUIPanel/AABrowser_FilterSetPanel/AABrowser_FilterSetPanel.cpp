// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_FilterSetPanel/AABrowser_FilterSetPanel.h"

UAABrowser_FilterSetPanel::UAABrowser_FilterSetPanel()
{
	//BackgroundBorder = GUIImage'AGP_Interface.AABrowser_FilterSetPanel.PanelBackground';
	//FilterSet = moComboBox'AGP_Interface.AABrowser_FilterSetPanel.FilterSetComboBox';
	//ClearFilters = GUIButton'AGP_Interface.AABrowser_FilterSetPanel.ClearFiltersButton';
	//ShowFilters = GUIButton'AGP_Interface.AABrowser_FilterSetPanel.ShowFiltersButton';
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
