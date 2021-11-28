// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_PlayTip/Dir_PlayTip.h"

UDir_PlayTip::UDir_PlayTip()
{
	_nNumParamsDefined = 7;
	_sTip.SetNum(3);
	_sCmd.SetNum(5);
}

void UDir_PlayTip::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_PlayTip::DirectionStart()
{
	/*
	FString sDisplay[2] = "";
	if (_bDebug)
	{
		Log("Dir_PlayTip::DirectionStart()");
	}
	if (_HumanController != None)
	{
		sDisplay[0] = SubstituteNames(_sTip[0]);
		sDisplay[1] = SubstituteNames(_sTip[1]);
		_HumanController.SetPlayTips(sDisplay[0], sDisplay[1], _fFadeTime);
		if (_bDebug)
		{
			Log("SCRIPT PLAYTIP:  " $ sDisplay[0]);
			Log("SCRIPT PLAYTIP:  " $ sDisplay[1]);
		}
	}
	*/
}

FString UDir_PlayTip::SubstituteNames(FString startstring)
{
	int32 Position = 0;
	FString retval = "";
	int32 cmdnum = 0;
	int32 StrLen = 0;
	FString tmp = "";
	retval = "";
	Position = 0;
	/*
	StrLen = Len(startstring);
	if (Position < StrLen)
	{
		tmp = Mid(startstring, Position, 1);
		if (tmp == "<")
		{
			Position++;
			cmdnum = int(Mid(startstring, Position, 1));
			if (_sCmd[cmdnum] == "")
			{
				retval = retval $ "ERROR";
			}
			else
			{
				retval = retval $ GetCommandKey(_sCmd[cmdnum]);
			}
			Position++;
		}
		else
		{
			retval = retval $ tmp;
		}
		Position++;
	}
	*/
	return retval;
}

FString UDir_PlayTip::GetCommandKey(FString cmdname)
{
	/*
	local Console Console;
	FString cmdkeyname = "";
	local Interactions.EInputKey cmdkey;
	int32 Count = 0;
	FString retval = "";
	Console = _HumanController.Player.Console;
	retval = "<";
	cmdkeyname = "";
	Count = 0;
	if (Console.GetCommandKey(cmdname, cmdkey, cmdkeyname, Count))
	{
		if (Count > 0)
		{
			retval = retval $ " or ";
		}
		retval = retval $ Caps(cmdkeyname);
		Count++;
	}
	if (retval == "")
	{
		return "ERROR!";
	}
	return retval $ ">";
	*/
	return "FAKE";    //FAKE   /ELiZ
}

bool UDir_PlayTip::ProcessParams()
{
	/*
	_sTip[0] = GetParam(0);
	_sTip[1] = GetParam(1);
	_fFadeTime = float(GetParam(2));
	if (_fFadeTime < 0.1)
	{
		_fFadeTime = 3;
	}
	_sCmd[0] = GetParam(3);
	_sCmd[1] = GetParam(4);
	_sCmd[2] = GetParam(5);
	_sCmd[3] = GetParam(6);
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
