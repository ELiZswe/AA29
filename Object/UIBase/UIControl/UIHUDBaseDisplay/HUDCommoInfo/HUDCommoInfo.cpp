// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDCommoInfo/HUDCommoInfo.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoHandSignal/CommoHandSignal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoRadio/CommoRadio.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoShout/CommoShout.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoSquad/CommoSquad.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoTestAnswers/CommoTestAnswers.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoWhisper/CommoWhisper.h"
#include "Engine/Canvas.h"

UHUDCommoInfo::UHUDCommoInfo()
{
	_CommoTexture.SetNum(6);
	_CommoTexture = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_hand_Mat.hud_com_hand_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_whisper_Mat.hud_com_whisper_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_shout_Mat.hud_com_shout_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_radio_Mat.hud_com_radio_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_ssg_Mat.hud_rank_ssg_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_com_global_Mat.hud_com_global_Mat'"), NULL, LOAD_None, NULL)
	};
	_iMessageSet = 1;
	_iMaxMessageSet = 3;
}

static const float MessageDisplayTime = 4.0;
static const float MessageFadeTime = 1.5;
static const float MessagesShown = 9;
static const float kMessagePosX = 8;
static const float kMessagePosY = 48;

void UHUDCommoInfo::Destroyed()
{
	int32 i=0;
	Super::Destroyed();
	_Level = nullptr;
	for (i = 0; i < 6; i++)
	{
		_CommoTexture[i] = nullptr;
	}
}

bool UHUDCommoInfo::ShowingMessages()
{
	return _bDrawMessages;
}

void UHUDCommoInfo::ShowMessages(bool Show)
{
	if (Show)
	{
		_fStartTime = GetWorld()->GetTimeSeconds();
		_iMessageSet = GetDefault<UHUDCommoInfo>()->_iMessageSet;
	}
	_bDrawMessages = Show;
}

void UHUDCommoInfo::ShowNextMessageSet()
{
	_iMessageSet++;
	_fStartTime = GetWorld()->GetTimeSeconds();
	if (_iMessageSet > _iMaxMessageSet)
	{
		_iMessageSet = GetDefault<UHUDCommoInfo>()->_iMessageSet;
	}
}

int32 UHUDCommoInfo::IndexToMessage(int32 Index)
{
	return _iMessageSet - 1 * 9 + Index;
}

void UHUDCommoInfo::DrawCommoAnswers(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	int32 Index = 0;
	int32 baseindex = 0;
	uint8 bytealpha = 0;
	FColor OldColor = FColor(0, 0, 0, 0);
	FString toprint = "";
	ACommoLocalMessage* CommoType = nullptr;
	int32 XPos = 0;
	int32 YPos = 0;
	float Xsize = 0;
	float Ysize = 0;
	bool bGlobal = false;
	float Alpha = 0;
	int32 theType = 0;
	Alpha = 1;
	bGlobal = false;
	/*
	XPos = int((8 * cFrame->fScaleX));
	YPos = int((float(48) * cFrame->fScaleY));
	if (Alpha < 0)
	{
		return;
	}
	if (Alpha > 1)
	{
		Alpha = 1;
	}
	bytealpha = uint8((255 * Alpha));
	if (cFrame->cActor != nullptr)
	{
		oldstyle = Canvas.Style;
		OldColor = Canvas.DrawColor;
		Canvas.Style = ERenderStyle.STY_Alpha;
		Canvas.SetPos(float(XPos), float(YPos));
		if ((cFrame != nullptr) && cFrame->cHUD->IsA(AAGP_HUD::StaticClass()))
		{
			Canvas.DrawColor = Cast<AAGP_HUD>(cFrame->cHUD).HUDColor;
		}
		else
		{
			Canvas.DrawColor.A = bytealpha;
		}
		CommoType = ACommoTestAnswers::StaticClass();
		toprint = CommoType.Default._messagename;
		if (toprint == "Answers")
		{
			theType = 0;
		}
		else
		{
			if (toprint == "Practice")
			{
				theType = 1;
			}
			else
			{
				if (toprint == "Question")
				{
					theType = 2;
				}
			}
		}
		Canvas.DrawText(toprint, false);
		Canvas.TextSize(toprint, Xsize, Ysize);
		YPos += int(Ysize);
		Canvas.SetPos(float(XPos), float(YPos));
		if (!bGlobal)
		{
			if (CommoType.Default._iNumMessages < ((_iMessageSet - 1) * 9))
			{
				_iMessageSet = Default._iMessageSet;
			}
			baseindex = ((_iMessageSet - 1) * 9);
			for (Index = 0; Index < 9; Index++)
			{
				if ((Index + baseindex) >= CommoType.Default._iNumMessages)
				{
				}
				if (CommoType.Default._Messages[Index] == "")
				{
				}
				if (theType == 2)
				{
					if (Index < 6)
					{
						toprint = "  " @ CommoType.Default._Messages[(baseindex + Index)];
					}
					else
					{
						toprint = FString::FromInt((Index + 1)) + ": " @ CommoType.Default._Messages[(baseindex + Index)];
					}
				}
				else
				{
					toprint = FString::FromInt((Index + 1)) + ": " @ CommoType.Default._Messages[(baseindex + Index)];
				}
				Canvas.DrawText(toprint, false);
				Canvas.TextSize(toprint, Xsize, Ysize);
				YPos += int((Ysize + 5));
				Canvas.SetPos(float(XPos), float(YPos));
			}
			if (theType == 1)
			{
				if ((_iMessageSet != Default._iMessageSet) || ((Index + baseindex) < CommoType.Default._iNumMessages))
				{
					YPos += int((Ysize + 5));
					Canvas.SetPos(float(XPos), float(YPos));
					toprint = "9:  repeat word....";
					Canvas.DrawText(toprint, false);
					Canvas.TextSize(toprint, Xsize, Ysize);
					YPos += int((Ysize + 5));
					Canvas.SetPos(float(XPos), float(YPos));
					toprint = "0: Exit Practice....";
					Canvas.DrawText(toprint, false);
					Canvas.TextSize(toprint, Xsize, Ysize);
				}
			}
			else
			{
				if (theType == 2)
				{
					if ((_iMessageSet != Default._iMessageSet) || ((Index + baseindex) < CommoType.Default._iNumMessages))
					{
						YPos += int((Ysize + 5));
						Canvas.SetPos(float(XPos), float(YPos));
						toprint = "7:  Previous word....";
						Canvas.DrawText(toprint, false);
						Canvas.TextSize(toprint, Xsize, Ysize);
						YPos += int((Ysize + 5));
						Canvas.SetPos(float(XPos), float(YPos));
						toprint = "8:  Next word....";
						Canvas.DrawText(toprint, false);
						Canvas.TextSize(toprint, Xsize, Ysize);
						YPos += int((Ysize + 5));
						Canvas.SetPos(float(XPos), float(YPos));
						toprint = "9:  Repeat word....";
						Canvas.DrawText(toprint, false);
						Canvas.TextSize(toprint, Xsize, Ysize);
						YPos += int((Ysize + 5));
						Canvas.SetPos(float(XPos), float(YPos));
						toprint = "0: Exit Test and Grade ....";
						Canvas.DrawText(toprint, false);
						Canvas.TextSize(toprint, Xsize, Ysize);
					}
				}
			}
		}
		Canvas.Style = uint8(oldstyle);
		Canvas.DrawColor = OldColor;
	}
	*/
}

void UHUDCommoInfo::Draw(UCanvas* Canvas)
{
	float elapsed = 0;
	FColor OldColor = FColor(0, 0, 0, 0);
	float ratio = 0;
	/*
	if ((((((Canvas == nullptr) || (cFrame == nullptr)) || (cFrame->cActor == nullptr)) || (cFrame->cActor.Level == nullptr)) || cFrame->cActor.bDeleteMe) || cFrame->cActor.Level.bDeleteMe)
	{
		return;
	}
	if (_Level == nullptr)
	{
		_Level = cFrame->cActor.Level;
	}
	if (_GetWorld()->GetNetMode() == NM_Standalone)
	{
		if (_Level.bEnableCommo)
		{
			DrawCommoAnswers(Canvas);
		}
		return;
	}
	elapsed = (_GetWorld()->GetTimeSeconds() - _fStartTime);
	DrawIcon(Canvas);
	if (_bDrawMessages)
	{
		if (Cast<AHumanController>(Cast<APawn>(cFrame->cActor).Controller).Player.Console.IsInState("Typing"))
		{
			_bDrawMessages = false;
			return;
		}
		if (elapsed > (4 + 1.5))
		{
			_bDrawMessages = false;
			return;
		}
		OldColor = Canvas.DrawColor;
		Canvas.SetDrawColor(255, 255, 255);
		if (elapsed < 4)
		{
			DrawMessages(Canvas, 1);
		}
		else
		{
			ratio = (elapsed - 4);
			ratio = ((1.5 - ratio) / 1.5);
			DrawMessages(Canvas, ratio);
		}
		Canvas.DrawColor = OldColor;
	}
	*/
}

void UHUDCommoInfo::DrawIcon(UCanvas* Canvas)
{
	FColor OldColor = FColor(0, 0, 0, 0);
	int32 oldstyle = 0;
	int32 Index = 0;
	/*
	if (Cast<AAGP_Pawn>(cFrame->cActor) == nullptr)
	{
		return;
	}
	if (cFrame->cActor != nullptr)
	{
		OldColor = Canvas.DrawColor;
		oldstyle = Canvas.Style;
		Canvas.Style = ERenderStyle.STY_Alpha;
		Canvas.DrawColor = Cast<AAGP_HUD>(cFrame->cHUD).HUDColor;
		Canvas.SetPos(float(_ScaledPos.X), float(_ScaledPos.Y));
		switch (Cast<AAGP_Pawn>(cFrame->cActor).CommoState)
		{
		case 0:
			Index = 0;
			break;
		case 1:
			Index = 1;
			break;
		case 2:
			Index = 2;
			break;
		case 3:
			Index = 3;
			break;
		case 4:
			Index = 4;
			break;
		case 5:
			Index = 5;
			break;
		default:
			Index = 2;
		}
		Canvas.DrawTile(_CommoTexture[Index], float(_ScaledPos.W), float(_ScaledPos.H), 0, 0, float(_CommoTexture[Index].USize), float(_CommoTexture[Index].VSize));
		Canvas.Style = uint8(oldstyle);
		Canvas.DrawColor = OldColor;
	}
	*/
}

void UHUDCommoInfo::DrawMessages(UCanvas* Canvas, float Alpha)
{
	int32 oldstyle = 0;
	int32 Index = 0;
	int32 baseindex = 0;
	uint8 bytealpha = 0;
	FColor OldColor = FColor(0, 0, 0, 0);
	FString toprint = "";
	ACommoLocalMessage* CommoType = nullptr;
	int32 XPos = 0;
	int32 YPos = 0;
	float Xsize = 0;
	float Ysize = 0;
	bool bGlobal = false;
	bGlobal = false;
	/*
	XPos = int((8 * cFrame->fScaleX));
	YPos = int((float(48) * cFrame->fScaleY));
	if (Alpha < 0)
	{
		return;
	}
	if (Alpha > 1)
	{
		Alpha = 1;
	}
	bytealpha = uint8((255 * Alpha));
	if ((cFrame != nullptr) && (cFrame->cActor != nullptr))
	{
		oldstyle = Canvas.Style;
		OldColor = Canvas.DrawColor;
		Canvas.Style = ERenderStyle.STY_Alpha;
		Canvas.SetPos(float(XPos), float(YPos));
		if ((cFrame != nullptr) && cFrame->cHUD->IsA(AAGP_HUD::StaticClass()))
		{
			Canvas.DrawColor = Cast<AAGP_HUD>(cFrame->cHUD).HUDColor;
		}
		else
		{
			Canvas.DrawColor.A = bytealpha;
		}
		CommoType = nullptr;
		switch (Cast<AAGP_Pawn>(cFrame->cActor).CommoState)
		{
		case 0:
			CommoType = ACommoHandSignal::StaticClass();
			break;
		case 1:
			CommoType = ACommoWhisper::StaticClass();
			break;
		case 2:
			CommoType = ACommoShout::StaticClass();
			break;
		case 3:
			CommoType = ACommoRadio::StaticClass();
			break;
		case 4:
			CommoType = ACommoSquad::StaticClass();
			break;
		case 5:
			bGlobal = true;
			break;
		default:
			break;
		}
		if (!bGlobal)
		{
			toprint = CommoType.GetMessageTypeName();
		}
		else
		{
			toprint = "Global Message";
		}
		Canvas.DrawText(toprint, false);
		Canvas.TextSize(toprint, Xsize, Ysize);
		YPos += int(Ysize);
		Canvas.SetPos(float(XPos), float(YPos));
		Canvas.DrawText("T:  Talk / Chat", false);
		Canvas.TextSize(toprint, Xsize, Ysize);
		YPos += int((Ysize + 5));
		Canvas.SetPos(float(XPos), float(YPos));
		if (!bGlobal)
		{
			if (CommoType.Default._iNumMessages < ((_iMessageSet - 1) * 9))
			{
				_iMessageSet = Default._iMessageSet;
			}
			baseindex = ((_iMessageSet - 1) * 9);
			for (Index = 0; Index < 9; Index++)
			{
				if ((Index + baseindex) >= CommoType.Default._iNumMessages)
				{
				}
				if (CommoType.Default._Messages[Index] == "")
				{
				}
				toprint = FString::FromInt((Index + 1)) + ": " @ CommoType.Default._Messages[(baseindex + Index)];
				Canvas.DrawText(toprint, false);
				Canvas.TextSize(toprint, Xsize, Ysize);
				YPos += int((Ysize + 5));
				Canvas.SetPos(float(XPos), float(YPos));
			}
			if ((_iMessageSet != Default._iMessageSet) || ((Index + baseindex) < CommoType.Default._iNumMessages))
			{
				YPos += int((Ysize + 5));
				Canvas.SetPos(float(XPos), float(YPos));
				toprint = "0:  other messages....";
				Canvas.DrawText(toprint, false);
				Canvas.TextSize(toprint, Xsize, Ysize);
			}
		}
		Canvas.Style = uint8(oldstyle);
		Canvas.DrawColor = OldColor;
	}
	*/
}
