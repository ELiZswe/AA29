// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Page.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"

UIRC_Page::UIRC_Page()
{
	UGUIScrollTextBox* DisplayBox = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	DisplayBox->bNoTeletype = true;
	DisplayBox->bStripColors = true;
	DisplayBox->CharDelay = 0.0015;
	DisplayBox->EOLDelay = 0.25;
	DisplayBox->bVisibleWhenEmpty = true;
	//DisplayBox->OnCreateComponent=DisplayBox.InternalOnCreateComponent;
	DisplayBox->StyleName = "ServerBrowserGrid";
	DisplayBox->WinHeight = 1;
	DisplayBox->bScaleToParent = true;
	UmoEditBox* entrybox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	entrybox->CaptionWidth = 0;
	//entrybox->OnCreateComponent=entrybox.InternalOnCreateComponent;
	entrybox->WinTop = 0.95;
	entrybox->WinLeft = 0;
	entrybox->WinWidth = 1;
	entrybox->WinHeight = 0.05;
	UGUIPanel* DisplayPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	DisplayPanel->Controls = { DisplayBox };
	UGUIPanel* UtilPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	UGUISplitter* MainSplitter = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	MainSplitter->SplitPosition = 0.8;
	MainSplitter->bFixedSplitter = true;
	MainSplitter->Controls = { DisplayPanel,UtilPanel };
	MainSplitter->WinHeight = 0.95;

	HasLeftText = "has left";
	HasJoinedText = "has joined";
	WasKickedByText = "was kicked by";
	NowKnownAsText = "is now known as";
	QuitText = "Quit";
	SetsModeText = "sets mode";
	NewTopicText = "Topic";
	MaxChatScrollback = 250;
	InputHistorySize = 16;
	IRCTextColor = FColor(160, 160, 160, 0);
	IRCNickColor = FColor(255, 150, 150, 0);
	IRCActionColor = FColor(0, 200, 230, 0);
	IRCInfoColor = FColor(160, 130, 130, 0);
	IRCLinkColor = FColor(150, 150, 255, 0);
	Controls = { entrybox,MainSplitter };
	WinTop = 0.15;
	WinHeight = 0.73;
}

void UIRC_Page::ProcessInput(FString Text)
{
}

bool UIRC_Page::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	FString Input = "";
	int32 Index = 0;
	if (State != 1)
	{
		return false;
	}
	if (Key == 13)
	{
		Input = TextEntry.GetText();
		if (Input != "")
		{
			Index = InputHistory.Length;
			InputHistory.insert(Index, 1);
			InputHistory[Index] = Input;
			if (InputHistory.Length > InputHistorySize)
			{
				InputHistory.remove(0, (InputHistory.Length - InputHistorySize));
			}
			InputHistoryPos = (InputHistory.Length - 1);
			bDoneInputScroll = false;
			ProcessInput(Input);
			TextEntry.SetText("");
		}
		return true;
	}
	else
	{
		if (Key == 38)
		{
			if (InputHistory.Length > 0)
			{
				TextEntry.SetText(InputHistory[InputHistoryPos]);
				(InputHistoryPos);
				if (InputHistoryPos < 0)
				{
					InputHistoryPos = (InputHistory.Length - 1);
				}
				bDoneInputScroll = true;
			}
			return true;
		}
		else
		{
			if (Key == 40)
			{
				if (InputHistory.Length > 0)
				{
					if (!bDoneInputScroll)
					{
						InputHistoryPos = 0;
					}
					TextEntry.SetText(InputHistory[InputHistoryPos]);
					InputHistoryPos++;
					if (InputHistoryPos > (InputHistory.Length - 1))
					{
						InputHistoryPos = 0;
					}
					bDoneInputScroll = true;
				}
				return true;
			}
		}
	}
	*/
	return false;
}

FString UIRC_Page::ColorizeLinks(FString InString)
{
	int32 i = 0;
	FString OutString = "";
	FString Character = "";
	FString Word = "";
	FString ColourlessWord = "";
	bool InWord = false;
	bool HaveWord = false;
	/*
	i = 0;
	if (true)
	{
		if ((i < Len(InString)) && (!HaveWord))
		{
			Character = Mid(InString, i, 1);
			if (InWord)
			{
				if (Character == " ")
				{
					HaveWord = true;
				}
				else
				{
					Word = Word $ Character;
					i++;
				}
			}
			else
			{
				if (Character == " ")
				{
					OutString = OutString $ Character;
					i++;
				}
				else
				{
					InWord = true;
					Word = Word $ Character;
					i++;
				}
			}
		}
		if (Word == "")
		{
			return OutString;
		}
		ColourlessWord = StripColorCodes(Word);
		if (((Left(ColourlessWord, 7) == "http://") || (Left(ColourlessWord, 9) == "unreal://")) || (Left(ColourlessWord, (Len(PlayerOwner().GetURLProtocol()) + 3)) == PlayerOwner().GetURLProtocol() $ "://"))
		{
			OutString = OutString $ MakeColorCode(IRCLinkColor) $ ColourlessWord $ MakeColorCode(IRCTextColor);
		}
		else
		{
			OutString = OutString $ Word;
		}
		Word = "";
		HaveWord = false;
		InWord = false;
	}
	*/
	return OutString;
}

bool UIRC_Page::IRCTextDblClick(UGUIComponent* Sender)
{
	/*
	FString ClickString = "";
	ClickString = StripColorCodes(TextDisplay.MyScrollText.ClickedString);
	if (Left(ClickString, 7) == "http://")
	{
		PlayerOwner().ConsoleCommand("start" @ ClickString);
	}
	else
	{
		if ((Left(ClickString, 9) == "unreal://") || (Left(ClickString, (Len(PlayerOwner().GetURLProtocol()) + 3)) == PlayerOwner().GetURLProtocol() $ "://"))
		{
			Controller.CloseAll(false);
			PlayerOwner().ClientTravel(ClickString, 0, false);
		}
	}
	*/
	return true;
}

void UIRC_Page::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	TextEntry = moEditBox(Controls[0]);
	TextEntry.__OnKeyEvent__Delegate = InternalOnKeyEvent;
	TextEntry.MyEditBox.Style = Controller.GetStyle("IRCEntry", TextEntry.MyEditBox.FontScale);
	TextDisplay = GUIScrollTextBox(GUIPanel(GUISplitter(Controls[1]).Controls[0]).Controls[0]);
	TextDisplay.MyScrollText.Separator = Chr(13);
	TextDisplay.MyScrollText.MaxHistory = MaxChatScrollback;
	TextDisplay.MyScrollText.Style = Controller.GetStyle("IRCText", TextDisplay.MyScrollText.FontScale);
	TextDisplay.MyScrollText.bClickText = true;
	TextDisplay.MyScrollText.__OnDblClick__Delegate = IRCTextDblClick;
	*/
}