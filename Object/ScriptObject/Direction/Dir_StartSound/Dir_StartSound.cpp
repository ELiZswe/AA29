// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_StartSound/Dir_StartSound.h"

UDir_StartSound::UDir_StartSound()
{
	_nNumParamsDefined = 3;
}

void UDir_StartSound::Destroyed()
{
	/*
	Super::Destroyed();
	_Sound = None;
	*/
}

void UDir_StartSound::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StartSound::DirectionStart()");
	}
	if (_Sound != None)
	{
		if (_Sound._TargetPawn == None)
		{
			_Sound._TargetPawn = _ParentScreenplay.GetHumanController().Pawn;
		}
		_Sound.Start();
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_StartSound::DirectionStart() - _Sound == None");
		}
	}
	*/
}

void UDir_StartSound::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StartSound::DirectionFinish()");
	}
	if (_Sound != None)
	{
		_Sound.Finish();
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_StartSound::DirectionFinish() - _Sound == None");
		}
	}
	*/
}

bool UDir_StartSound::ProcessParams()
{
	/*
	FString SlotName = "";
	FString TargetName = "";
	_Sound = AGP_Sound(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_Sound == None)
	{
		if (_bDebug)
		{
			Log("Dir_StartSound::ProcessParams() - could not find AGP_Sound with tag " $ GetParam(0));
		}
		return false;
	}
	TargetName = GetParam(1);
	_Sound._TargetPawn = None;
	if (TargetName != "")
	{
		_Sound._TargetPawn = Pawn(_ParentScreenplay.GetActorByTag(string(TargetName)));
	}
	SlotName = GetParam(2);
	if (SlotName == "")
	{
		return true;
	}
	else
	{
		if (SlotName == "SLOT_None")
		{
			_Sound.SoundSlot = 0;
		}
		else
		{
			if (SlotName == "SLOT_Misc")
			{
				_Sound.SoundSlot = 1;
			}
			else
			{
				if (SlotName == "SLOT_Pain")
				{
					_Sound.SoundSlot = 2;
				}
				else
				{
					if (SlotName == "SLOT_Interact")
					{
						_Sound.SoundSlot = 3;
					}
					else
					{
						if (SlotName == "SLOT_Ambient")
						{
							_Sound.SoundSlot = 4;
						}
						else
						{
							if (SlotName == "SLOT_Talk")
							{
								_Sound.SoundSlot = 5;
							}
							else
							{
								if (SlotName == "SLOT_Interface")
								{
									_Sound.SoundSlot = 6;
								}
							}
						}
					}
				}
			}
		}
	}
	*/
	return true;
}

void UDir_StartSound::SetSound(AAGP_Sound* Sound)
{
	/*
	if (_bDebug)
	{
		Log("Dir_StartSound::SetSound()");
	}
	_Sound = Sound;
	*/
}
