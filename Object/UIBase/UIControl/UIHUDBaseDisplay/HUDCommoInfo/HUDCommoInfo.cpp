// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDCommoInfo/HUDCommoInfo.h"

UHUDCommoInfo::UHUDCommoInfo()
{
	//_CommoTexture(0) = Texture'T_AA2_UI.HUD.hud_com_hand';
	//_CommoTexture(1) = Texture'T_AA2_UI.HUD.hud_com_whisper'
	//_CommoTexture(2) = Texture'T_AA2_UI.HUD.hud_com_shout'
	//_CommoTexture(3) = Texture'T_AA2_UI.HUD.hud_com_radio'
	//_CommoTexture(4) = Texture'T_AA2_UI.HUD.hud_rank_ssg'
	//_CommoTexture(5) = Texture'T_AA2_UI.HUD.hud_com_global'
	_iMessageSet = 1;
	_iMaxMessageSet = 3;
}

//const MessageDisplayTime = 4.0;
//const MessageFadeTime = 1.5;
//const MessagesShown = 9;
//const kMessagePosX = 8;
//const kMessagePosY = 48;


void UHUDCommoInfo::Destroyed()
{
	int32 i=0;
	Super::Destroyed();
	_Level = nullptr;
	/*
	for (i = 0; i < 6; i++)
	{
		_CommoTexture[i] = nullptr;
	}
	*/
}
bool UHUDCommoInfo::ShowingMessages()
{
	return _bDrawMessages;
}
void UHUDCommoInfo::ShowMessages(bool Show)
{
	/*
	if (Show)
	{
		_fStartTime = _Level.TimeSeconds;
		_iMessageSet = Default._iMessageSet;
	}
	_bDrawMessages = Show;
	*/
}
void UHUDCommoInfo::ShowNextMessageSet()
{
	/*
	_iMessageSet++;
	_fStartTime = _Level.TimeSeconds;
	if (_iMessageSet > _iMaxMessageSet)
	{
		_iMessageSet = Default._iMessageSet;
	}
	*/
}
int32 UHUDCommoInfo::IndexToMessage(int32 Index)
{
	return _iMessageSet - 1 * 9 + Index;
}
void UHUDCommoInfo::DrawCommoAnswers(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local int Index;
	local int baseindex;
	local byte bytealpha;
	local Object.Color OldColor;
	local string toprint;
	local class<CommoLocalMessage>  CommoType;
	local int XPos;
	local int YPos;
	local float Xsize;
	local float Ysize;
	local bool bGlobal;
	local float Alpha;
	local int theType;
	Alpha = 1;
	bGlobal = False;
	XPos = 8 * cFrame.fScaleX;
	YPos = 48 * cFrame.fScaleY;
	if (Alpha < 0)
	{
		Return;
	}
	if (Alpha > 1)
	{
		Alpha = 1;
	}
	bytealpha = 255 * Alpha;
	if (cFrame.cActor != None)
	{
		oldstyle = Canvas.Style;
		OldColor = Canvas.DrawColor;
		Canvas.Style = 6;
		Canvas.SetPos(XPos, YPos);
		if (cFrame != None && cFrame.cHUD.IsA('AGP_HUD'))
		{
			Canvas.DrawColor = AGP_HUD(cFrame.cHUD).HUDColor;
		}
		else
		{
			Canvas.DrawColor.A = bytealpha;
		}
		CommoType = 'CommoTestAnswers';
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
		Canvas.DrawText(toprint, False);
		Canvas.TextSize(toprint, Xsize, Ysize);
		YPos += Ysize;
		Canvas.SetPos(XPos, YPos);
		if (!bGlobal)
		{
			if (CommoType.Default._iNumMessages < _iMessageSet - 1 * 9)
			{
				_iMessageSet = Default._iMessageSet;
			}
			baseindex = _iMessageSet - 1 * 9;
			for (Index = 0; Index < 9; Index++)
			{
				if (Index + baseindex >= CommoType.Default._iNumMessages)
				{
				}
				if (CommoType.Default._Messages[Index] == "")
				{
				}
				if (theType == 2)
				{
					if (Index < 6)
					{
						toprint = "  " @ CommoType.Default._Messages[baseindex + Index];
					}
					else
					{
						toprint = Index + 1 $ ": " @ CommoType.Default._Messages[baseindex + Index];
					}
				}
				else
				{
					toprint = Index + 1 $ ": " @ CommoType.Default._Messages[baseindex + Index];
				}
				Canvas.DrawText(toprint, False);
				Canvas.TextSize(toprint, Xsize, Ysize);
				YPos += Ysize + 5;
				Canvas.SetPos(XPos, YPos);
			}
			if (theType == 1)
			{
				if (_iMessageSet != Default._iMessageSet || Index + baseindex < CommoType.Default._iNumMessages)
				{
					YPos += Ysize + 5;
					Canvas.SetPos(XPos, YPos);
					toprint = "9:  repeat word....";
					Canvas.DrawText(toprint, False);
					Canvas.TextSize(toprint, Xsize, Ysize);
					YPos += Ysize + 5;
					Canvas.SetPos(XPos, YPos);
					toprint = "0: Exit Practice....";
					Canvas.DrawText(toprint, False);
					Canvas.TextSize(toprint, Xsize, Ysize);
				}
			}
			else
			{
				if (theType == 2)
				{
					if (_iMessageSet != Default._iMessageSet || Index + baseindex < CommoType.Default._iNumMessages)
					{
						YPos += Ysize + 5;
						Canvas.SetPos(XPos, YPos);
						toprint = "7:  Previous word....";
						Canvas.DrawText(toprint, False);
						Canvas.TextSize(toprint, Xsize, Ysize);
						YPos += Ysize + 5;
						Canvas.SetPos(XPos, YPos);
						toprint = "8:  Next word....";
						Canvas.DrawText(toprint, False);
						Canvas.TextSize(toprint, Xsize, Ysize);
						YPos += Ysize + 5;
						Canvas.SetPos(XPos, YPos);
						toprint = "9:  Repeat word....";
						Canvas.DrawText(toprint, False);
						Canvas.TextSize(toprint, Xsize, Ysize);
						YPos += Ysize + 5;
						Canvas.SetPos(XPos, YPos);
						toprint = "0: Exit Test and Grade ....";
						Canvas.DrawText(toprint, False);
						Canvas.TextSize(toprint, Xsize, Ysize);
					}
				}
			}
		}
		Canvas.Style = oldstyle;
		Canvas.DrawColor = OldColor;
	}
	*/
}
void UHUDCommoInfo::Draw(UCanvas* Canvas)
{
	/*
	local float elapsed;
	local Object.Color OldColor;
	local float ratio;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	if (_Level == None)
	{
		_Level = cFrame.cActor.Level;
	}
	if (_Level.NetMode == 0)
	{
		if (_Level.bEnableCommo)
		{
			DrawCommoAnswers(Canvas);
		}
		Return;
	}
	elapsed = _Level.TimeSeconds - _fStartTime;
	DrawIcon(Canvas);
	if (_bDrawMessages)
	{
		if (HumanController(Pawn(cFrame.cActor).Controller).Player.Console.IsInState('Typing'))
		{
			_bDrawMessages = False;
			Return;
		}
		if (elapsed > 4 + 1.5)
		{
			_bDrawMessages = False;
			Return;
		}
		OldColor = Canvas.DrawColor;
		Canvas.SetDrawColor(255, 255, 255);
		if (elapsed < 4)
		{
			DrawMessages(Canvas, 1);
		}
		else
		{
			ratio = elapsed - 4;
			ratio = 1.5 - ratio / 1.5;
			DrawMessages(Canvas, ratio);
		}
		Canvas.DrawColor = OldColor;
	}
	*/
}
void UHUDCommoInfo::DrawIcon(UCanvas* Canvas)
{
	/*
	local Object.Color OldColor;
	local int oldstyle;
	local int Index;
	if (AGP_Pawn(cFrame.cActor) == None)
	{
		Return;
	}
	if (cFrame.cActor != None)
	{
		OldColor = Canvas.DrawColor;
		oldstyle = Canvas.Style;
		Canvas.Style = 6;
		Canvas.DrawColor = AGP_HUD(cFrame.cHUD).HUDColor;
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Switch(AGP_Pawn(cFrame.cActor).CommoState)
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
		Canvas.DrawTile(_CommoTexture[Index], _ScaledPos.W, _ScaledPos.H, 0, 0, _CommoTexture[Index].USize, _CommoTexture[Index].VSize);
		Canvas.Style = oldstyle;
		Canvas.DrawColor = OldColor;
	}
	*/
}
void UHUDCommoInfo::DrawMessages(UCanvas* Canvas, float Alpha)
{
	/*
	local int oldstyle;
	local int Index;
	local int baseindex;
	local byte bytealpha;
	local Object.Color OldColor;
	local string toprint;
	local class<CommoLocalMessage>  CommoType;
	local int XPos;
	local int YPos;
	local float Xsize;
	local float Ysize;
	local bool bGlobal;
	bGlobal = False;
	XPos = 8 * cFrame.fScaleX;
	YPos = 48 * cFrame.fScaleY;
	if (Alpha < 0)
	{
		Return;
	}
	if (Alpha > 1)
	{
		Alpha = 1;
	}
	bytealpha = 255 * Alpha;
	if (cFrame != None && cFrame.cActor != None)
	{
		oldstyle = Canvas.Style;
		OldColor = Canvas.DrawColor;
		Canvas.Style = 6;
		Canvas.SetPos(XPos, YPos);
		if (cFrame != None && cFrame.cHUD.IsA('AGP_HUD'))
		{
			Canvas.DrawColor = AGP_HUD(cFrame.cHUD).HUDColor;
		}
		else
		{
			Canvas.DrawColor.A = bytealpha;
		}
		CommoType = None;
		Switch(AGP_Pawn(cFrame.cActor).CommoState)
		{
				case 0:
					CommoType = 'CommoHandSignal';
					break;
				case 1:
					CommoType = 'CommoWhisper';
					break;
				case 2:
					CommoType = 'CommoShout';
					break;
				case 3:
					CommoType = 'CommoRadio';
					break;
				case 4:
					CommoType = 'CommoSquad';
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
		Canvas.DrawText(toprint, False);
		Canvas.TextSize(toprint, Xsize, Ysize);
		YPos += Ysize;
		Canvas.SetPos(XPos, YPos);
		Canvas.DrawText("T:  Talk / Chat", False);
		Canvas.TextSize(toprint, Xsize, Ysize);
		YPos += Ysize + 5;
		Canvas.SetPos(XPos, YPos);
		if (!bGlobal)
		{
			if (CommoType.Default._iNumMessages < _iMessageSet - 1 * 9)
			{
				_iMessageSet = Default._iMessageSet;
			}
			baseindex = _iMessageSet - 1 * 9;
			for (Index = 0; Index < 9; Index++)
			{
				if (Index + baseindex >= CommoType.Default._iNumMessages)
				{
				}
				if (CommoType.Default._Messages[Index] == "")
				{
				}
				toprint = Index + 1 $ ": " @ CommoType.Default._Messages[baseindex + Index];
				Canvas.DrawText(toprint, False);
				Canvas.TextSize(toprint, Xsize, Ysize);
				YPos += Ysize + 5;
				Canvas.SetPos(XPos, YPos);
			}
			if (_iMessageSet != Default._iMessageSet || Index + baseindex < CommoType.Default._iNumMessages)
			{
				YPos += Ysize + 5;
				Canvas.SetPos(XPos, YPos);
				toprint = "0:  other messages....";
				Canvas.DrawText(toprint, False);
				Canvas.TextSize(toprint, Xsize, Ysize);
			}
		}
		Canvas.Style = oldstyle;
		Canvas.DrawColor = OldColor;
	}
	*/
}
