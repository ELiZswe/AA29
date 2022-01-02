// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_PlayerServerSearchPanel/AABrowser_PlayerServerSearchPane.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAABrowser_PlayerServerSearchPane::UAABrowser_PlayerServerSearchPane()
{
	UGUIButton* SearchButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SearchButton->Caption = "Search";
	SearchButton->FontScale = EFontScale::FNS_Small;
	SearchButton->WinTop = 0.218968;
	SearchButton->WinLeft = 0.837044;
	SearchButton->WinWidth = 0.153078;
	SearchButton->WinHeight = 0.625229;
	SearchButton->bBoundToParent = true;
	//SearchButton->OnClick=AABrowser_PlayerServerSearchPanel.InternalOnClick;
	//SearchButton->OnKeyEvent=SearchButton.InternalOnKeyEvent;
	UGUIComboBox* SearchTextComboBox = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	SearchTextComboBox->bIgnoreChangeWhenTyping = true;
	SearchTextComboBox->Hint = "Search history is kept for the last 10 queries.";
	SearchTextComboBox->WinTop = 0.277536;
	SearchTextComboBox->WinLeft = 0.519757;
	SearchTextComboBox->WinWidth = 0.3;
	SearchTextComboBox->WinHeight = 0.485681;
	SearchTextComboBox->bBoundToParent = true;
	//SearchTextComboBox->OnChange=AABrowser_PlayerServerSearchPanel.InternalOnChange;
	//SearchTextComboBox->OnKeyEvent=SearchTextComboBox.InternalOnKeyEvent;
	UmoCheckBox* ServerSearchTypeOption = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	ServerSearchTypeOption->bAutoSizeCaption = false;
	ServerSearchTypeOption->ComponentJustification = EeTextAlign::TXTA_Left;
	ServerSearchTypeOption->CaptionWidth = 0.6;
	ServerSearchTypeOption->Caption = "Server";
	ServerSearchTypeOption->LabelStyleName = "SmallText";
	//ServerSearchTypeOption->OnCreateComponent=ServerSearchTypeOption.InternalOnCreateComponent;
	ServerSearchTypeOption->WinTop = 0.195422;
	ServerSearchTypeOption->WinLeft = 0.349695;
	ServerSearchTypeOption->WinWidth = 0.175;
	ServerSearchTypeOption->WinHeight = 0.687776;
	ServerSearchTypeOption->bBoundToParent = true;
	ServerSearchTypeOption->bStandardized = false;
	//ServerSearchTypeOption->OnChange=AABrowser_PlayerServerSearchPanel.InternalOnChange;
	UmoCheckBox* PlayerSearchTypeOption = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	PlayerSearchTypeOption->bAutoSizeCaption = false;
	PlayerSearchTypeOption->ComponentJustification = EeTextAlign::TXTA_Left;
	PlayerSearchTypeOption->CaptionWidth = 0.55;
	PlayerSearchTypeOption->Caption = "Player";
	PlayerSearchTypeOption->LabelStyleName = "SmallText";
	//PlayerSearchTypeOption->OnCreateComponent=PlayerSearchTypeOption.InternalOnCreateComponent;
	PlayerSearchTypeOption->WinTop = 0.195422;
	PlayerSearchTypeOption->WinLeft = 0.189513;
	PlayerSearchTypeOption->WinWidth = 0.175;
	PlayerSearchTypeOption->WinHeight = 0.687776;
	PlayerSearchTypeOption->bBoundToParent = true;
	PlayerSearchTypeOption->bStandardized = false;
	//PlayerSearchTypeOption->OnChange=AABrowser_PlayerServerSearchPanel.InternalOnChange;
	UGUIImage* PanelBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	PanelBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfill_Mat.backgroundfill_Mat'"), NULL, LOAD_None, NULL);
	PanelBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	PanelBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PanelBackground->WinHeight = 1;
	PanelBackground->RenderWeight = 0;
	PanelBackground->bBoundToParent = true;
	PanelBackground->bScaleToParent = true;
	UGUILabel* SearchByLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SearchByLabel->Caption = "Search By:";
	SearchByLabel->TextColor = FColor(255, 255, 255, 255);
	SearchByLabel->StyleName = "SmallText";
	SearchByLabel->WinTop = 0.279449;
	SearchByLabel->WinLeft = 0.014817;
	SearchByLabel->WinWidth = 0.174696;
	SearchByLabel->WinHeight = 0.485681;
	SearchByLabel->bBoundToParent = true;
	BackgroundBorder = PanelBackground;
	SearchBy = SearchByLabel;
	PlayerSearchType = PlayerSearchTypeOption;
	ServerSearchType = ServerSearchTypeOption;
	SearchText = SearchTextComboBox;
	Search = SearchButton;
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
	return filter;
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
			return true;
			break;
		default:
			return false;
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
					return true;
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
					return true;
				}
			}
			GOTO JL0088;
		default:
		JL0088:
			return false;
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