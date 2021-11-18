// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIScrollText/GUIScrollText.h"

UGUIScrollText::UGUIScrollText()
{
	Separator = "|";
	VisibleLines = -1;
	CharDelay = 0.25;
	EOLDelay = 0.75;
	RepeatDelay = 3;
	TextAlign = EeTextAlign::TXTA_Left;

	//__OnClick__Delegate = "GUIScrollText.InternalOnClick"
	//__OnKeyType__Delegate = "GUIScrollText.InternalOnKeyType"
	//__OnKeyEvent__Delegate = "GUIScrollText.InternalOnKeyEvent"
}


//native final Function GetWordUnderCursor();
void UGUIScrollText::GetWordUnderCursor()
{

}

void UGUIScrollText::OnEndOfLine()
{
}

void UGUIScrollText::Dump()
{
	/*
	local int i;
	for (i = 0; i < StringElements.Length; i++)
	{
		Log(Name @ "ScrollText Elements[" $ i $ "]:" $ StringElements[i]);
	}
	*/
}

void UGUIScrollText::InitComponent(AGUIController* MyController, AGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	if (bNoTeletype)
	{
		EndScrolling();
	}
	*/
}

void UGUIScrollText::SetContent(FString NewContent, FString sep)
{
	/*
	if (sep == "")
	{
		Separator = Default.Separator;
	}
	else
	{
		Separator = sep;
	}
	Content = NewContent;
	bNewContent = True;
	if (bNoTeletype)
	{
		EndScrolling();
	}
	else
	{
		Restart();
	}
	*/
}

void UGUIScrollText::Stop()
{
	/*
	bStopped = True;
	ScrollState = 0;
	TimerInterval = 0;
	*/
}

void UGUIScrollText::Restart()
{
	/*
	VisibleLines = 0;
	VisibleChars = 0;
	if (InitialDelay <= 0)
	{
		ScrollState = 0;
		SetTimer(0.001, True);
	}
	else
	{
		ScrollState = 1;
		SetTimer(InitialDelay, True);
	}
	bStopped = False;
	*/
}

bool UGUIScrollText::SkipChar()
{
	/*
	if (ItemCount > 0 && !bStopped && VisibleLines >= 0 && VisibleLines < ItemCount)
	{
		if (VisibleChars == Len(StringElements[VisibleLines]))
		{
			if (VisibleLines + 1 < ItemCount)
			{
				VisibleLines++;
				VisibleChars = 0;
				TimerInterval = EOLDelay;
				ScrollState = 3;
				OnEndOfLine();
				Return True;
			}
		}
		else
		{
			VisibleChars++;
			TimerInterval = CharDelay;
			ScrollState = 2;
			Return True;
		}
	}
	*/
	return false;
}

void UGUIScrollText::Timer()
{
	/*
	if (ItemCount == 0)
	{
		if (!bNewContent)
		{
			TimerInterval = 0;
		}
		Return;
	}
	if (ScrollState == 4)
	{
		Restart();
	}
	else
	{
		if (ScrollState == 3)
		{
			if (!SkipChar())
			{
				if (bRepeat)
				{
					if (RepeatDelay > 0)
					{
						TimerInterval = RepeatDelay;
						ScrollState = 4;
					}
					else
					{
						Restart();
					}
				}
				else
				{
					bStopped = True;
					ScrollState = 0;
					TimerInterval = 0;
				}
			}
		}
		else
		{
			if (ScrollState == 0)
			{
				ScrollState = 1;
				SetTimer(CharDelay, True);
			}
			else
			{
				if (!SkipChar())
				{
					ScrollState = 3;
					TimerInterval = EOLDelay;
					OnEndOfLine();
				}
			}
		}
	}
	*/
}

bool UGUIScrollText::InternalOnClick(AGUIComponent* Sender)
{
	bool retval=false;
	/*
	if (bClickText)
	{
		ClickedString = GetWordUnderCursor();
		Return True;
	}
	retval = InternalOnClick(Sender);
	if (retval)
	{
		EndScrolling();
	}
	*/
	return retval;
}

bool UGUIScrollText::InternalOnKeyType(uint8 &Key, FString Unicode)
{
	EndScrolling();
	return false;
}

bool UGUIScrollText::InternalOnKeyEvent(uint8 &Key, uint8 &State, float Delta)
{
	bool retval=false;
	/*
	retval = InternalOnKeyEvent(Key, State, Delta);
	if (retval)
	{
		EndScrolling();
	}
	*/
	return retval;
}

void UGUIScrollText::EndScrolling()
{
	/*
	bStopped = True;
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	KillTimer();
	*/
}

bool UGUIScrollText::IsValid()
{
	return true;
}