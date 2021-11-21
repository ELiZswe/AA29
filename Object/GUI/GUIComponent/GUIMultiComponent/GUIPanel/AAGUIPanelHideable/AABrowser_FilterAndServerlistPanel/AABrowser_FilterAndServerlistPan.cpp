// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanelHideable/AABrowser_FilterAndServerlistPanel/AABrowser_FilterAndServerlistPan.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_ServersPlayersRulesPanel/AABrowser_ServersPlayersRulesPan.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AATreeAndExclusiveListPanel/AABrowser_FilterPanel/AABrowser_FilterPanel.h"

UAABrowser_FilterAndServerlistPan::UAABrowser_FilterAndServerlistPan()
{
	UAABrowser_ServersPlayersRulesPan* ServersPlayersRulesPanel = NewObject<UAABrowser_ServersPlayersRulesPan>(UAABrowser_ServersPlayersRulesPan::StaticClass());
	//ServersPlayersRulesPanel->OnUpdateServerList = AABrowser_FilterAndServerlistPanel.InternalOnUpdateServerList;
	ServersPlayersRulesPanel->WinLeft = 0.33;
	ServersPlayersRulesPanel->WinWidth = 0.666667;
	ServersPlayersRulesPanel->WinHeight = 1;
	//ServersPlayersRulesPanel->OnSaveINI=ServersPlayersRulesPanel.InternalOnSaveINI;
	UAABrowser_FilterPanel* FilterBox = NewObject<UAABrowser_FilterPanel>(UAABrowser_FilterPanel::StaticClass());
	//FilterBox->OnFiltersChanged = AABrowser_FilterAndServerlistPanel.InternalOnFiltersChanged;
	FilterBox->WinWidth = 0.333333;
	FilterBox->WinHeight = 1;
	leftside = FilterBox;
	rightside = ServersPlayersRulesPanel;
}

void UAABrowser_FilterAndServerlistPan::OnUpdateServerList()
{
}

void UAABrowser_FilterAndServerlistPan::OnFiltersChanged()
{
}

void UAABrowser_FilterAndServerlistPan::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//InitComponent(MyController, MyOwner);
	//__OnExpand__Delegate = AABrowser_ServersPlayersRulesPanel(rightside).InternalOnExpand;
	//__OnContract__Delegate = AABrowser_ServersPlayersRulesPanel(rightside).InternalOnContract;
}

void UAABrowser_FilterAndServerlistPan::SetFilterSet(int32 FilterSetIndex)
{
	//AABrowser_FilterPanel(leftside).SetFilterSet(FilterSetIndex);
}

void UAABrowser_FilterAndServerlistPan::ClearFilterSet()
{
	//AABrowser_FilterPanel(leftside).ClearFilterSet();
}

void UAABrowser_FilterAndServerlistPan::ClearLists()
{
	//AABrowser_ServersPlayersRulesPanel(rightside).Clear();
}

void UAABrowser_FilterAndServerlistPan::ShowFilterSummary()
{
	//AABrowser_FilterPanel(leftside).ShowFilterSummary();
}

void UAABrowser_FilterAndServerlistPan::ReceivedServer(int32 Data)
{
	//AABrowser_ServersPlayersRulesPanel(rightside).ReceivedServer(Data);
}

void UAABrowser_FilterAndServerlistPan::PutIntoDeploymentMode(FString sDeploymentModeMap)
{
	//AABrowser_FilterPanel(leftside).PutIntoDeploymentMode(sDeploymentModeMap);
}

void UAABrowser_FilterAndServerlistPan::GetGameSpyFilterString()
{
	//Return AABrowser_FilterPanel(leftside).GetGameSpyFilterString();
}

void UAABrowser_FilterAndServerlistPan::GetDBMBSFilterList()
{
	//Return AABrowser_FilterPanel(leftside).GetDBMBSFilterList();
}

void UAABrowser_FilterAndServerlistPan::JoinCurrentlySelectedServer()
{
	//AABrowser_ServersPlayersRulesPanel(rightside).JoinCurrentlySelectedServer();
}

void UAABrowser_FilterAndServerlistPan::InternalOnUpdateServerList()
{
	//OnUpdateServerList();
}

void UAABrowser_FilterAndServerlistPan::InternalOnFiltersChanged()
{
	//Log(Self $ ".InternalOnFiltersChanged() entered");
	//OnFiltersChanged();
}