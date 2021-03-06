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
	CurLine = 0;
	Caption = "";
	DisplayState = EDisplayState::DS_Delay;
	if (InitialDelay <= 0)
	{
		SetTimer(0.001, true);
	}
	else
	{
		SetTimer(InitialDelay, true);
	}
}

void UGUISubtitleText::Stop()
{
	Caption = "";
	TimerInterval = 0;
	DisplayState = EDisplayState::DS_Stopped;
	OnStopped();
}

int32 UGUISubtitleText::SetSubtitles(FString alldata, FString sep, bool bDontGuess, FString lengthdata)
{
	int32 i = 0;
	TArray<FString> newdata = {};
	TArray<int32> datalength = {};
	if (sep == "")
	{
		sep = Separator;
	}
	//Split(alldata, sep, newdata);
	if (bDontGuess)
	{
		//Split(lengthdata, sep, datalength);
		//datalength.Num() = newdata.Num();
	}
	ClearSubtitles();
	for (i = 0; i < newdata.Num(); i++)
	{
		if (bDontGuess)
		{
			AddSubtitle(newdata[i], datalength[i],0);
		}
		else
		{
			AddSubtitle(newdata[i], GuessCharTime * newdata[i].Len(),0);
		}
	}
	Restart();
	return i;
}

int32 UGUISubtitleText::AddSubtitle(FString NewTitle, float Delay, float Visible)
{
	return InsertSubtitle(SubTitles.Num(), NewTitle, Delay, Visible);
}

int32 UGUISubtitleText::InsertSubtitle(int32 Position, FString NewTitle, float Delay, float Visible)
{
	if (Position > SubTitles.Num())
	{
		return - 1;
	}
	if (Position < 0)
	{
		return - 1;
	}
	//SubTitles.insert(Position, 1);
	//SubTitleTiming.insert(Position, 1);
	SubTitles[Position] = NewTitle;
	if (Delay == 0)
	{
		Delay = DelayTime;
	}
	//SubTitleTiming[Position].Delay = FMath::Max(Delay, 0);
	if (Visible == 0)
	{
		Visible = VisibleTime;
	}
	if (Visible >= Delay)
	{
		Visible = 0;
	}
	//SubTitleTiming[Position].Visible = FMath::Max(Visible, 0);
	return Position;
}

void UGUISubtitleText::ClearSubtitles()
{
	SubTitles.Empty();
	SubTitleTiming.Empty();
}

void UGUISubtitleText::Timer()
{
	if (CurLine >= SubTitles.Num())
	{
		Caption = "";
		TimerInterval = 0;
		DisplayState = EDisplayState::DS_Stopped;
		OnStopped();
		return;
	}
	if (DisplayState == EDisplayState::DS_Delay)
	{
		Caption = SubTitles[CurLine];
		if (SubTitleTiming[CurLine].Visible > 0)
		{
			DisplayState = EDisplayState::DS_Visibility;
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
		if (DisplayState == EDisplayState::DS_Visibility)
		{
			Caption = "";
			DisplayState = EDisplayState::DS_Delay;
			TimerInterval = SubTitleTiming[CurLine].Delay - SubTitleTiming[CurLine].Visible;
			CurLine++;
		}
	}
}
