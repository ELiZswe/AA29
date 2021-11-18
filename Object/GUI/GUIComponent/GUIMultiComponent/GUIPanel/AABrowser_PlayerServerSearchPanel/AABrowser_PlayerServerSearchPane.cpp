// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_PlayerServerSearchPanel/AABrowser_PlayerServerSearchPane.h"

UAABrowser_PlayerServerSearchPane::UAABrowser_PlayerServerSearchPane()
{
	//BackgroundBorder = GUIImage'AGP_Interface.AABrowser_PlayerServerSearchPanel.PanelBackground';
	//SearchBy = GUILabel'AGP_Interface.AABrowser_PlayerServerSearchPanel.SearchByLabel';
	//PlayerSearchType = moCheckBox'AGP_Interface.AABrowser_PlayerServerSearchPanel.PlayerSearchTypeOption';
	//ServerSearchType = moCheckBox'AGP_Interface.AABrowser_PlayerServerSearchPanel.ServerSearchTypeOption';
	//SearchText = GUIComboBox'AGP_Interface.AABrowser_PlayerServerSearchPanel.SearchTextComboBox';
	//Search = GUIButton'AGP_Interface.AABrowser_PlayerServerSearchPanel.SearchButton';
}

void UAABrowser_PlayerServerSearchPane::OnSearch(FFilterItem filter)
{
}

void UAABrowser_PlayerServerSearchPane::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	PlayerSearchType.Checked(True);
	CurrentSearchType = PlayerSearchType;
	SetSearchHistoryText();
	*/
}

void UAABrowser_PlayerServerSearchPane::SetSearchHistoryText()
{
	/*
	local int Index;
	SearchText.List.bNotify = False;
	SearchText.Clear();
	Switch(CurrentSearchType)
	{
			case PlayerSearchType:
				Index = 0;
				if (Index < 10)
				{
					SearchText.addItem(PlayerNameSearchHistory[Index]);
					++Index;
					break;
				}
				GOTO JL00D4;
			case ServerSearchType:
				for (Index = 0; Index < 10; Index++)
				{
					SearchText.addItem(ServerNameSearchHistory[Index]);
				}
				GOTO JL00D4;
			default:
				Log(Self @ "Unknown search type!");
			JL00D4:
				SearchText.List.bNotify = True;
	}
	*/
}

void UAABrowser_PlayerServerSearchPane::InternalOnSearchTypeChanged()
{
	/*
	SearchText.SetText("");
	SetSearchHistoryText();
	*/
}

void UAABrowser_PlayerServerSearchPane::MakeFilter()
{
	/*
	local ServerBrowserBase.FilterItem filter;
	Switch(CurrentSearchType)
	{
		case PlayerSearchType:
			filter.Key = "playerName";
			break;
		case ServerSearchType:
		default:
			filter.Key = "serverName";
			break;
	}
	filter.Value = SearchText.GetText();
	Return filter;
	*/
}

bool UAABrowser_PlayerServerSearchPane::InternalOnClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
		case Search:
			UpdateAndSaveSearchHistories();
			OnSearch(MakeFilter());
			Return True;
			break;
		default:
			Return False;
			break;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool UAABrowser_PlayerServerSearchPane::IsInSearchHistory(FString SearchString)
{
	/*
	local int Index;
	Switch(CurrentSearchType)
	{
		case PlayerSearchType:
			Index = 0;
			if (Index < 10)
			{
				if (SearchString == PlayerNameSearchHistory[Index])
				{
					Return True;
				}
				++Index;
				break;
			}
			GOTO JL0088;
		case ServerSearchType:
			for (Index = 0; Index < 10; Index++)
			{
				if (SearchString == ServerNameSearchHistory[Index])
				{
					Return True;
				}
			}
			GOTO JL0088;
		default:
		JL0088:
			Return False;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void UAABrowser_PlayerServerSearchPane::UpdateAndSaveSearchHistories()
{
	/*
	local int Index;
	local string SearchString;
	SearchString = SearchText.GetText();
	if (!IsInSearchHistory(SearchString))
	{
		Switch(CurrentSearchType)
		{
		case PlayerSearchType:
			Index = 9;
			if (Index > 0)
			{
				PlayerNameSearchHistory[Index] = PlayerNameSearchHistory[Index - 1];
				--Index;
				break;
			}
			PlayerNameSearchHistory[0] = SearchString;
		case ServerSearchType:
			for (Index = 9; Index > 0; Index--)
			{
				ServerNameSearchHistory[Index] = ServerNameSearchHistory[Index - 1];
			}
			ServerNameSearchHistory[0] = SearchString;
		default:
			SetSearchHistoryText();
			SaveConfig();
		}
	}
	*/
}

void UAABrowser_PlayerServerSearchPane::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
case PlayerSearchType:
	if (PlayerSearchType.IsChecked())
	{
		ServerSearchType.bValueReadOnly = False;
		ServerSearchType.SetComponentValue(False, True);
		PlayerSearchType.bValueReadOnly = True;
		CurrentSearchType = PlayerSearchType;
		InternalOnSearchTypeChanged();
	}
	break;
case ServerSearchType:
	if (ServerSearchType.IsChecked())
	{
		ServerSearchType.bValueReadOnly = True;
		PlayerSearchType.bValueReadOnly = False;
		PlayerSearchType.SetComponentValue(False, True);
		CurrentSearchType = ServerSearchType;
		InternalOnSearchTypeChanged();
	}
	break;
case SearchText:
	break;
default:
	}
	*/
}

void UAABrowser_PlayerServerSearchPane::testonly_GetPlayerSearchType()
{
	//Return PlayerSearchType;
}

void UAABrowser_PlayerServerSearchPane::testonly_GetServerSearchType()
{
	//Return ServerSearchType;
}

void UAABrowser_PlayerServerSearchPane::testonly_GetSearchText()
{
	//Return SearchText;
}

void UAABrowser_PlayerServerSearchPane::testonly_GetSearch()
{
	//Return Search;
}