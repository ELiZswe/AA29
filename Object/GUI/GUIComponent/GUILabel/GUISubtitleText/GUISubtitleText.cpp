// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUILabel/GUISubtitleText/GUISubtitleText.h"


UGUISubtitleText::UGUISubtitleText()
{
	DelayTime = 2;
	GuessCharTime = 0.06;
	Separator = "|";
	TextAlign = ETextAlign::TXTA_Center;
	bMultiLine = true;
	StyleName = "TextLabel";
}

void UGUISubtitleText::OnStopped()
{
}
void UGUISubtitleText::Restart()
{
	/*
	CurLine = 0;
	Caption = "";
	DisplayState = 0;
	if (InitialDelay <= 0)
	{
		SetTimer(0.001, true);
	}
	else
	{
		SetTimer(InitialDelay, true);
	}
	*/
}
void UGUISubtitleText::Stop()
{
	Caption = "";
	TimerInterval = 0;
	DisplayState = EDisplayState::DS_Stopped;
	OnStopped();
}
void UGUISubtitleText::SetSubtitles(FString alldata, FString sep, bool bDontGuess, FString lengthdata)
{
	/*
	local array<String> newdata;
	local array<String> datalength;
	local int i;
	if (sep == "")
	{
		sep = Separator;
	}
	Split(alldata, sep, newdata);
	if (bDontGuess)
	{
		Split(lengthdata, sep, datalength);
		datalength.Length = newdata.Length;
	}
	ClearSubtitles();
	for (i = 0; i < newdata.Length; i++)
	{
		if (bDontGuess)
		{
			AddSubtitle(newdata[i], datalength[i]);
		}
		else
		{
			AddSubtitle(newdata[i], GuessCharTime * Len(newdata[i]));
		}
	}
	Restart();
	Return i;
	*/
}
void UGUISubtitleText::AddSubtitle(FString NewTitle, float Delay, float Visible)
{
	/*
	Return InsertSubtitle(SubTitles.Length, NewTitle, Delay, Visible);
	*/
}
void UGUISubtitleText::InsertSubtitle(int32 Position, FString NewTitle, float Delay, float Visible)
{
	/*
	if (Position > SubTitles.Length)
	{
		Return - 1;
	}
	if (Position < 0)
	{
		Return - 1;
	}
	SubTitles.insert(Position, 1);
	SubTitleTiming.insert(Position, 1);
	SubTitles[Position] = NewTitle;
	if (Delay == 0)
	{
		Delay = DelayTime;
	}
	SubTitleTiming[Position].Delay = Max(Delay, 0);
	if (Visible == 0)
	{
		Visible = VisibleTime;
	}
	if (Visible >= Delay)
	{
		Visible = 0;
	}
	SubTitleTiming[Position].Visible = Max(Visible, 0);
	Return Position;
	*/
}
void UGUISubtitleText::ClearSubtitles()
{
	/*
	SubTitles.Length = 0;
	SubTitleTiming.Length = 0;
	*/
}
void UGUISubtitleText::Timer()
{
	/*
	if (CurLine >= SubTitles.Length)
	{
		Caption = "";
		TimerInterval = 0;
		DisplayState = 2;
		OnStopped();
		Return;
	}
	if (DisplayState == 0)
	{
		Caption = SubTitles[CurLine];
		if (SubTitleTiming[CurLine].Visible > 0)
		{
			DisplayState = 1;
			TimerInterval = SubTitleTiming[CurLine].Visible;
		}
		else
		{
			TimerInterval = SubTitleTiming[CurLine].Delay;
			CurLine++;
		}
	}
	else
	{
		if (DisplayState == 1)
		{
			Caption = "";
			DisplayState = 0;
			TimerInterval = SubTitleTiming[CurLine].Delay - SubTitleTiming[CurLine].Visible;
			CurLine++;
		}
	}
	*/
}
