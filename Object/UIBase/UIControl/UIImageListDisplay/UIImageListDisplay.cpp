// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIImageListDisplay/UIImageListDisplay.h"

UUIImageListDisplay::UUIImageListDisplay()
{
	_iCenterImage = -1;
}

void UUIImageListDisplay::Destroyed()
{
	Super::Destroyed();
	_AlphaShade = nullptr;
	_Completed = nullptr;
	_NotAvailable = nullptr;
	_Images.SetNum(0);
}

void UUIImageListDisplay::ProcessParams()
{
	if (_iParams == 1)
	{
		_bTour = true;
	}
	else
	{
		_bTour = false;
	}
}

void UUIImageListDisplay::Draw(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	float Xsize = 0;
	float Ysize = 0;
	int32 iLabelX = 0;
	int32 iLabelY = 0;
	if (_iCenterImage == -1)
	{
		return;
	}
	/*
	oldstyle = Canvas.Style;
	Canvas.Style = 6;
	Canvas.SetPos(_ScaledPos.X - 140, _ScaledPos.Y);
	if (_iCenterImage == 0)
	{
		GOTO JL014F;
	}
	Canvas.DrawTile(_Images[_iCenterImage - 1].Tex, _ScaledPos.W, _ScaledPos.H, 0, 0, 110, 82);
	CheckStatus(Canvas, _iCenterImage - 1, _ScaledPos.X - 140, _ScaledPos.Y);
	Canvas.SetPos(_ScaledPos.X - 140, _ScaledPos.Y);
	Canvas.DrawTile(_AlphaShade, _ScaledPos.W, _ScaledPos.H, 270, 60, 8, 8);
JL014F:
	Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
	Canvas.DrawTile(_Images[_iCenterImage].Tex, _ScaledPos.W, _ScaledPos.H, 0, 0, 110, 82);
	CheckStatus(Canvas, _iCenterImage, _ScaledPos.X, _ScaledPos.Y);
	Canvas.SetPos(_ScaledPos.X + 140, _ScaledPos.Y);
	if (_iCenterImage == _Images.Num() - 1)
	{
		GOTO JL0301;
	}
	Canvas.DrawTile(_Images[_iCenterImage + 1].Tex, _ScaledPos.W, _ScaledPos.H, 0, 0, 110, 82);
	CheckStatus(Canvas, _iCenterImage + 1, _ScaledPos.X + 140, _ScaledPos.Y);
	Canvas.SetPos(_ScaledPos.X + 140, _ScaledPos.Y);
	Canvas.DrawTile(_AlphaShade, _ScaledPos.W, _ScaledPos.H, 270, 60, 8, 8);
JL0301:
	Canvas.TextSize(_Images[_iCenterImage].Info, Xsize, Ysize);
	iLabelX = _ScaledPos.X - 68 + 256 - Xsize / 2;
	iLabelY = _ScaledPos.Y + 104 + 32 - Ysize / 2;
	Canvas.SetPos(iLabelX, iLabelY);
	Canvas.DrawText(_Images[_iCenterImage].Info);
	Canvas.Style = oldstyle;
	*/
}

void UUIImageListDisplay::CheckStatus(UCanvas* Canvas, int32 Index, int32 XPos, int32 YPos)
{
	/*
	if (_Images[Index].Status == -1)
	{
		Canvas.SetPos(XPos, YPos);
		Canvas.DrawTile(_NotAvailable, _ScaledPos.W, _ScaledPos.H, 0, 0, 110, 82);
	}
	else
	{
		if (_Images[Index].Status == 1)
		{
			Canvas.SetPos(XPos, YPos);
			Canvas.DrawTile(_Completed, _ScaledPos.W, _ScaledPos.H, 0, 0, 110, 82);
		}
	}
	*/
}
void UUIImageListDisplay::AddImage(FString sInfo, FString sTexture, FString sData0, FString sData1, FString sData2, FString sData3, int32 Status)
{
	int32 new_index = 0;
	FImageInfo iinfo = FImageInfo({});
	/*
	new_index = _Images.Num();
	_Images[new_index] = iinfo;
	_Images[new_index].Info = sInfo;
	if (sTexture != "" && sTexture != "None")
	{
		_Images[new_index].Tex = Texture(DynamicLoadObject(sTexture, Class'Texture'));
	}
	else
	{
		_Images[new_index].Tex = nullptr;
	}
	if (_Images[new_index].Tex == nullptr)
	{
		_Images[new_index].Tex = Texture(DynamicLoadObject("t_aao_ui.uniform.t_ui_uniform_pin_branch_infantry", Class'Texture'));
	}
	_Images[new_index].sData[0] = sData0;
	_Images[new_index].sData[1] = sData1;
	_Images[new_index].sData[2] = sData2;
	_Images[new_index].sData[3] = sData3;
	_Images[new_index].Status = Status;
	_iCenterImage = 0;
	*/
}

void UUIImageListDisplay::SetData(int32 Data)
{
	int32 iLines = 0;
	int32 iCurLine = 0;
	FString sInfo = "";
	FString sTexture = "";
	FString sData = "";
	int32 iStatus = 0;
	/*
	_iCenterImage = -1;
	_Images.RemoveAt(0, _Images.Num());
	if (_bTour)
	{
		iLines = cFrame->cHUD.Level.iNumTours;
		for (iCurLine = 0; iCurLine < iLines; iCurLine++)
		{
			sInfo = cFrame->cHUD.Level.GetTourName(iCurLine);
			sTexture = cFrame->cHUD.Level.GetTourImage(iCurLine);
			sData[0] = cFrame->cHUD.Level.GetTourText(iCurLine);
			sData[1] = cFrame->cHUD.Level.GetTourTextTitle(iCurLine);
			sData[2] = cFrame->cHUD.Level.GetTourHistoryText(iCurLine);
			sData[3] = cFrame->cHUD.Level.GetTourHistoryTextTitle(iCurLine);
			iStatus = cFrame->cHUD.Level.GetTourStatus(iCurLine);
			AddImage(sInfo, sTexture, sData[0], sData[1], sData[2], sData[3], iStatus);
		}
	}
	else
	{
		iLines = cFrame->cHUD.Level.GetTourMissions(Data);
		for (iCurLine = 0; iCurLine < iLines; iCurLine++)
		{
			sInfo = cFrame->cHUD.Level.GetTourMissionTitle(Data, iCurLine);
			sTexture = cFrame->cHUD.Level.GetTourMissionImage(Data, iCurLine);
			sData[0] = cFrame->cHUD.Level.GetTourMissionMapFilename(Data, iCurLine);
			sData[1] = cFrame->cHUD.Level.GetTourMissionTitle(Data, iCurLine);
			iStatus = cFrame->cHUD.Level.GetMissionStatus(Data, iCurLine);
			AddImage(sInfo, sTexture, sData[0], sData[1], sData[2], sData[3], iStatus);
		}
	}
	*/
}

void UUIImageListDisplay::NextImage()
{
	if (_iCenterImage == -1)
	{
		return;
	}
	if (_iCenterImage + 1 < _Images.Num())
	{
		_iCenterImage++;
	}
}

void UUIImageListDisplay::PrevImage()
{
	if (_iCenterImage == -1)
	{
		return;
	}
	if (_iCenterImage - 1 >= 0)
	{
		_iCenterImage--;
	}
}

FString UUIImageListDisplay::GetImageName()
{
	FString Name = "";
	if (_iCenterImage == -1)
	{
		return Name;
	}
	else
	{
		return _Images[_iCenterImage].Info;
	}
}

int32 UUIImageListDisplay::GetIndex()
{
	return _iCenterImage;
}

FString UUIImageListDisplay::GetData(int32 Index)
{
	return _Images[_iCenterImage].sData[Index];
}

bool UUIImageListDisplay::IsAvailable()
{
	if (_Images[_iCenterImage].Status == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
