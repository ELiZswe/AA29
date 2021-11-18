// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageMSCustom.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"

UBrowser_ServerListPageMSCustom::UBrowser_ServerListPageMSCustom()
{
	UGUIComboBox* MyGameTypeCombo = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	MyGameTypeCombo->WinTop=0.25;
	MyGameTypeCombo->WinLeft=0.61574;
	MyGameTypeCombo->WinWidth=0.365;
	MyGameTypeCombo->WinHeight=24;
	//MyGameTypeCombo->OnKeyEvent=MyGameTypeCombo.InternalOnKeyEvent;
	UGUILabel* MyGameTypeLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyGameTypeLabel->Caption="Game Type";
	MyGameTypeLabel->TextColor=FColor(255, 255, 255, 255);
	MyGameTypeLabel->WinTop=0.283333;
	MyGameTypeLabel->WinLeft=0.405117;
	MyGameTypeLabel->WinWidth=0.4;
	MyGameTypeLabel->WinHeight=24;
	UGUIPanel* GameTypePanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	GameTypePanel->Controls = { MyGameTypeCombo };
	GameTypePanel->Controls = { MyGameTypeLabel };
	UGUISplitter* MyGameTypeSplitter = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	MyGameTypeSplitter->SplitPosition=0.08;
	MyGameTypeSplitter->bFixedSplitter=true;
	MyGameTypeSplitter->bDrawSplitter=false;
	//MyGameTypeSplitter->Background=Texture'Engine.DefaultTexture';
	MyGameTypeSplitter->Controls = { GameTypePanel };
	MyGameTypeSplitter->WinHeight=0.9;
	MyGameTypeSplitter->bBoundToParent=true;
	MyGameTypeSplitter->bScaleToParent=true;
	
	GameTypeSplit = MyGameTypeSplitter;
}

void UBrowser_ServerListPageMSCustom::ChangeGameType(UGUIComponent* Sender)
{
	/*
	Log("New Game Type:" $ GameTypeCombo.GetText() $ " (" $ GameTypeCombo.GetExtra() $ ")");
	GameType = GameTypeCombo.GetExtra();
	LastGameType = GameType;
	SaveConfig();
	RefreshList();
	*/
}

FString UBrowser_ServerListPageMSCustom::MyParseDescStr(FString DescStr, int32 Index)
{
	/*
	FString Temp = "";
	int32 p = 0;
	int32 i = 0;
	i = 0;
	if (DescStr != "")
	{
		p = InStr(DescStr, "|");
		if (p < 0)
		{
			Temp = DescStr;
			DescStr = "";
		}
		else
		{
			Temp = Left(DescStr, p);
			DescStr = Right(DescStr, ((Len(DescStr) - p) - 1));
		}
		if (i == Index)
		{
			return Temp;
		}
		i++;
	}
	*/
	return "FAKE";     //FAKE    /ELiZ    
}

bool UBrowser_ServerListPageMSCustom::IsStandardGameType(FString Desc)
{
	/*
	if (InStr(Desc, "xDeathMatch") >= 0)
	{
		return true;
	}
	if (InStr(Desc, "xTeamGame") >= 0)
	{
		return true;
	}
	if (InStr(Desc, "xCTFGame") >= 0)
	{
		return true;
	}
	if (InStr(Desc, "xBombingRun") >= 0)
	{
		return true;
	}
	if (InStr(Desc, "xDoubleDom") >= 0)
	{
		return true;
	}
	if (InStr(Desc, "xMutantGame") >= 0)
	{
		return true;
	}
	if (InStr(Desc, "xLastManStanding") >= 0)
	{
		return true;
	}
	if (InStr(Desc, "Invasion") >= 0)
	{
		return true;
	}
	*/
	return false;
}

FString UBrowser_ServerListPageMSCustom::FindGameTypeName(FString aGameType)
{
	/*
	int32 i = 0;
	for (i = 0; i < GameTypeCombo.List.ItemCount; i++)
	{
		if (aGameType == GameTypeCombo.List.GetExtraAtIndex(i))
		{
			return GameTypeCombo.List.getItemAtIndex(i);
		}
	}
	Log("CustomTab: Could Not Find Game Type '" $ aGameType $ "' In Combo");
	*/
	return "";
}

void UBrowser_ServerListPageMSCustom::PopulateGameTypes()
{
	/*
	FString Entry = "";
	FString Desc = "";
	FString MyGameType = "";
	FString TypeName = "";
	int32 Index = 0;
	int32 PeriodPos = 0;
	Index = 0;
	PlayerOwner().GetNextIntDesc("GameInfo", Index, Entry, Desc);
	if (Entry != "")
	{
		Desc = Entry $ "|" $ Desc;
		if (!IsStandardGameType(Desc))
		{
			MyGameType = MyParseDescStr(Desc, 0);
			PeriodPos = InStr(MyGameType, ".");
			if (PeriodPos != -1)
			{
				MyGameType = Mid(MyGameType, (PeriodPos + 1));
			}
			TypeName = MyParseDescStr(Desc, 2);
			GameTypeCombo.addItem(TypeName, None, MyGameType);
		}
		Index++;
		PlayerOwner().GetNextIntDesc("GameInfo", Index, Entry, Desc);
	}
	GameType = LastGameType;
	GameTypeCombo.SetText(FindGameTypeName(LastGameType));
	*/
}

void UBrowser_ServerListPageMSCustom::InitComponent(UGUIController* C, UGUIComponent* O)
{
	/*
	Super::InitComponent(C, O);
	if (!CustomInitialized)
	{
		MainSplit = GUISplitter(Controls[0]);
		MainSplit.WinHeight = 1;
		GameTypeSplit.Controls[1] = MainSplit;
		Controls[0] = GameTypeSplit;
		GameTypeSplit.InitComponent(C, Self);
		GameTypeCombo = GUIComboBox(GUIPanel(GameTypeSplit.Controls[0]).Controls[0]);
		PopulateGameTypes();
		GameTypeCombo.__OnChange__Delegate = ChangeGameType;
		CustomInitialized = true;
	}
	GameTypeCombo.ReadOnly(true);
	*/
}