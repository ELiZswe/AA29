// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UITextPageDisplay/UITextPageDisplay.h"

UUITextPageDisplay::UUITextPageDisplay()
{

}

void UUITextPageDisplay::Destroyed()
{
	Super::Destroyed();
	_sStringList.Empty();
}

void UUITextPageDisplay::Draw(UCanvas* Canvas)
{
	UFont* oldfont = nullptr;
	int32 oldstyle = 0;
	int32 TopLine = 0;
	int32 linepos = 0;
	float XL = 0;
	float YL = 0;
	//oldstyle = Canvas.Style;
	//Canvas.Style = 6;
	//oldfont = Canvas.Font;
	if (_sTitle != "")
	{
		//Canvas.Font = cFrame->Fonts[3];
		//Canvas.TextSize(_sTitle, XL, YL);
		//Canvas.SetPos(_ScaledPos.X + _ScaledPos.W - XL / 2, _ScaledPos.Y - 30);
		//Canvas.DrawText(_sTitle);
	}
	//Canvas.Font = cFrame->Fonts[0];
	TopLine = _iLinesPerPage * _iCurrPage;
	for (linepos = 0; linepos < _iLinesPerPage; linepos++)
	{
		if (_sStringList.Num() > TopLine + linepos)
		{
			//Canvas->SetPos(_ScaledPos.X, _ScaledPos.Y + linepos * 12);
			//Canvas->DrawText(_sStringList[TopLine + linepos]);
		}
	}
	if (_bPageDisplay)
	{
		if (_iLastPage > 0)
		{
			//Canvas.Font = cFrame->Fonts[1];
			//Canvas.SetPos(436 + cFrame->offset.X, 513 + cFrame->offset.Y);
			//Canvas.DrawText("Page " + _iCurrPage + 1 + " of " + _iLastPage + 1);
		}
	}
	//Canvas.Style = oldstyle;
	//Canvas.Font = oldfont;
}

int32 UUITextPageDisplay::SetTextFile(FString Filename)
{
	FString Line = "";
	int32 i = 0;
	_iCurrPage = 0;
	_sStringList.Empty();
	/*
	if (!FOpen(Filename))
	{
		_iLastPage = 0;
		return _iLastPage + 1;
	}
	i = 0;
	if (FReadLine(Line))
	{
		AddLine(Line);
		i++;
	}
	FClose();
	_iLastPage = _sStringList.Num() / _iLinesPerPage;
	*/
	return _iLastPage + 1;
}

int32 UUITextPageDisplay::SetStringList(TArray<FString> sStringList)
{
	_sStringList = sStringList;
	_iLastPage = _sStringList.Num() / _iLinesPerPage;
	return _iLastPage + 1;
}

TArray<FString> UUITextPageDisplay::GetStringList()
{
	return _sStringList;
}

void UUITextPageDisplay::AddLine(FString Line)
{
	_sStringList.Add(Line);
}

void UUITextPageDisplay::NextPage()
{
	if (_iCurrPage < _iLastPage)
	{
		_iCurrPage++;
	}
}

void UUITextPageDisplay::PrevPage()
{
	if (_iCurrPage - 1 >= 0)
	{
		_iCurrPage--;
	}
}

void UUITextPageDisplay::SetTitle(FString Title)
{
	_sTitle = Title;
}

void UUITextPageDisplay::SetLinesPerPage(int32 Lines)
{
	_iLinesPerPage = Lines;
}

void UUITextPageDisplay::SetPageDisplay(bool bState)
{
	_bPageDisplay = bState;
}
