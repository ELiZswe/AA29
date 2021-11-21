// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Page.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"

UAAIRC_Page::UAAIRC_Page()
{
	UmoEditBox* entrybox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	entrybox->CaptionWidth = 0;
	//entrybox->OnCreateComponent=entrybox.InternalOnCreateComponent;
	entrybox->StyleName = "IRCEntry";
	entrybox->WinTop = 0.885;
	entrybox->WinLeft = 0;
	entrybox->WinWidth = 1;
	entrybox->WinHeight = 0.053476;
	entrybox->TabOrder = 0;
	entrybox->bBoundToParent = true;
	entrybox->bScaleToParent = true;
	entrybox->bStandardized = false;
	//entrybox->OnKeyEvent=AAIRC_Page.InternalOnKeyEvent;
	ed_TextEntry = entrybox;

	HasLeftText = "%Name% has left %Chan%.";
	HasJoinedText = "%Name% has joined %Chan%.";
	WasKickedByText = "%Kicked% was kicked by %Kicker% ( %Reason% ).";
	NowKnownAsText = "%OldName% is now known as %NewName%.";
	QuitText = "*** %Name% Quit ( %Reason% )";
	SetsModeText = "*** %Name% sets mode: %mode%.";
	NewTopicText = "Topic";
	MaxChatScrollback = 250;
	InputHistorySize = 16;
	IRCTextColor = FColor(229, 248, 251, 0);
	IRCNickColor = FColor(156, 201, 168, 0);
	IRCActionColor = FColor(50, 30, 150, 0);
	IRCInfoColor = FColor(52, 180, 217, 0);
	IRCLinkColor = FColor(159, 82, 82, 0);
	WinHeight = 1;
}

void UAAIRC_Page::ProcessInput(FString Text)
{
}

void UAAIRC_Page::Free()
{
}

bool UAAIRC_Page::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	local FString Input;
	local int32 Index;
	if ((Key == 236) && (State == 3))
	{
		lb_TextDisplay.MyScrollText.WheelUp();
		return true;
	}
	if ((Key == 237) && (State == 3))
	{
		lb_TextDisplay.MyScrollText.WheelDown();
		return true;
	}
	if (State != 1)
	{
		return false;
	}
	if (Key == 13)
	{
		Input = ed_TextEntry.GetText();
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
			ed_TextEntry.SetText("");
		}
		return true;
	}
	else
	{
		if (Key == 38)
		{
			if (InputHistory.Length > 0)
			{
				ed_TextEntry.SetText(InputHistory[InputHistoryPos]);
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
					ed_TextEntry.SetText(InputHistory[InputHistoryPos]);
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

FString UAAIRC_Page::ColorizeLinks(FString InString)
{
	FString OutString = "";
	/*
	local int32 i;
	local FString Character;
	local FString Word;
	local FString ColourlessWord;
	local bool InWord;
	local bool HaveWord;
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
					(Word $ = Character);
					i++;
				}
			}
			else
			{
				if (Character == " ")
				{
					(OutString $ = Character);
					i++;
				}
				else
				{
					InWord = true;
					(Word $ = Character);
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

bool UAAIRC_Page::IRCTextDblClick(UGUIComponent* Sender)
{
	/*
	local FString ClickString;
	ClickString = StripColorCodes(lb_TextDisplay.MyScrollText.ClickedString);
	if ((Left(ClickString, 7) ~= "http://") || (Left(ClickString, 9) ~= "unreal://"))
	{
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", ClickString, ClickString);
	}
	*/
	return true;
}

void UAAIRC_Page::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super.InitComponent(MyController, MyOwner);
	lb_TextDisplay.MyScrollText.MaxHistory = MaxChatScrollback;
	lb_TextDisplay.MyScrollText.bClickText = true;
	lb_TextDisplay.MyScrollText.__OnDblClick__Delegate = IRCTextDblClick;
	lb_TextDisplay.MyScrollText.FocusInstead = ed_TextEntry;
	lb_TextDisplay.MyScrollText.bNeverFocus = true;
	*/
}

void UAAIRC_Page::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (GUIScrollTextBox(NewComp) != None)
	{
		lb_TextDisplay = GUIScrollTextBox(NewComp);
		lb_TextDisplay.bVisibleWhenEmpty = true;
		lb_TextDisplay.WinWidth = 1;
		lb_TextDisplay.WinHeight = 1;
		lb_TextDisplay.CharDelay = 0.0015;
		lb_TextDisplay.EOLDelay = 0.25;
		lb_TextDisplay.Separator = Chr(13);
		lb_TextDisplay.bVisibleWhenEmpty = true;
		lb_TextDisplay.bNoTeletype = true;
		lb_TextDisplay.StyleName = "IRCText";
	}
	*/
}

void UAAIRC_Page::InterpretColorCodes(FString& Text)
{
	/*
	local int32 pos;
	local FString Code;
	pos = InStr(Text, Chr(3));
	if (pos != -1)
	{
		pos++;
		Code = "";
		if (IsDigit(Mid(Text, pos, 1)))
		{
			(Code $ = Mid(Text, pos, 1));
			pos++;
		}
		if ((Code != "") && (Mid(Text, pos, 1) == ","))
		{
			Text = Left(Text, pos) $ Mid(Text, (pos + 1));
			if (IsDigit(Mid(Text, pos, 1)))
			{
				Text = Left(Text, pos) $ Mid(Text, (pos + 1));
			}
		}
		Text = Repl(Text, Chr(3) $ Code, MakeColorCode(DecodeColor(int(Code))));
		pos = InStr(Text, Chr(3));
	}
	*/
}

FColor UAAIRC_Page::DecodeColor(int32 ColorCode)
{
	FColor C = FColor(0,0,0,0);
	/*
	switch (ColorCode)
	{
	case 2:
		C = Class'Canvas'.MakeColor(0, 0, 127);
		break;
	case 3:
		C = Class'Canvas'.MakeColor(0, 147, 0);
		break;
	case 4:
		C = Class'Canvas'.MakeColor(255, 0, 0);
		break;
	case 5:
		C = Class'Canvas'.MakeColor(127, 0, 0);
		break;
	case 6:
		C = Class'Canvas'.MakeColor(156, 0, 156);
		break;
	case 7:
		C = Class'Canvas'.MakeColor(252, 127, 0);
		break;
	case 8:
		C = Class'Canvas'.MakeColor(255, 255, 0);
		break;
	case 9:
		C = Class'Canvas'.MakeColor(0, 255, 0);
		break;
	case 10:
		C = Class'Canvas'.MakeColor(0, 147, 147);
		break;
	case 11:
		C = Class'Canvas'.MakeColor(0, 255, 255);
		break;
	case 12:
		C = Class'Canvas'.MakeColor(0, 0, 252);
		break;
	case 13:
		C = Class'Canvas'.MakeColor(255, 0, 255);
		break;
	case 14:
		C = Class'Canvas'.MakeColor(127, 127, 127);
		break;
	case 15:
		C = Class'Canvas'.MakeColor(210, 210, 210);
		break;
	default:
		C = Class'Canvas'.MakeColor(255, 255, 255);
	}
	*/
	return C;
}
