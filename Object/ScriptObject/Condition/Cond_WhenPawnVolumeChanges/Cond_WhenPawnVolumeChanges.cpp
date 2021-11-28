// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenPawnVolumeChanges/Cond_WhenPawnVolumeChanges.h"

UCond_WhenPawnVolumeChanges::UCond_WhenPawnVolumeChanges()
{
	_nNumParamsDefined = 3;
}

void UCond_WhenPawnVolumeChanges::Destroyed()
{
	Super::Destroyed();
	_Actor = nullptr;
	_Pawn = nullptr;
}

void UCond_WhenPawnVolumeChanges::ConditionStart()
{
	/*
	if (_Pawn == None)
	{
		if (_Actor != None)
		{
			if (_Actor.IsA('HumanController'))
			{
				_Pawn = AGP_Pawn(HumanController(_Actor).Pawn);
			}
			if (_Actor.IsA('AGP_Pawn'))
			{
				_Pawn = AGP_Pawn(_Actor);
			}
		}
	}
	if (_bDebug)
	{
		Log("Cond_WhenPawnVolumeChanges::ConditionStart()");
	}
	_Pawn.SetCurrentVolumeMonitor(Self);
	*/
}

void UCond_WhenPawnVolumeChanges::ConditionFinish()
{
	/*
	local ScriptObject soBlank;
	if (_bDebug)
	{
		Log("Cond_WhenPawnVolumeChanges::ConditionFinish()");
	}
	_Pawn.SetCurrentVolumeMonitor(soBlank);
	*/
}

bool UCond_WhenPawnVolumeChanges::ProcessParams()
{
	/*
	_VolumeTag = string(GetParam(0));
	_Actor = _ParentScreenplay.GetActorByTag(string(GetParam(1)));
	_bEntry = bool(GetParam(2));
	*/
	return true;
}

void UCond_WhenPawnVolumeChanges::SetActor(AActor* Actor)
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPawnVolumeChanges::SetActor(" $ string(Actor.Tag) $ ")");
	}
	_Actor = Actor;
	*/
}

void UCond_WhenPawnVolumeChanges::SetVolumeTag(FName voltag)
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPawnVolumeChanges::SetVolumeTag(" $ string(voltag) $ ")");
	}
	_VolumeTag = voltag;
	*/
}

void UCond_WhenPawnVolumeChanges::SetVolumeNotifyOnEntry(bool Entry)
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPawnVolumeChanges::SetVolumeNotifyOnEntry(" $ string(Entry) $ ")");
	}
	_bEntry = Entry;
	*/
}

void UCond_WhenPawnVolumeChanges::update()
{
	/*
	local Volume vol;
	if (_bDebug)
	{
		Log("Cond_WhenPawnVolumeChanges::Update()");
	}
	if (_Pawn != None)
	{
		vol = _Pawn.GetCurrentVolume();
		if (_bEntry)
		{
			if (_bDebug)
			{
				Log("Cond_WhenPawnVolumeChanges::Update() - checking if we enter");
			}
			if (vol != None)
			{
				if (vol.Tag == _VolumeTag)
				{
					_bTrue = true;
					Notify();
				}
				else
				{
					_bTrue = false;
				}
			}
		}
		else
		{
			if (_bDebug)
			{
				Log("Cond_WhenPawnVolumeChanges::Update() - checking if we exit");
			}
			if (vol == None)
			{
				if (bWasInVolume)
				{
					_bTrue = true;
					Notify();
				}
			}
			else
			{
				_bTrue = false;
				if (vol.Tag == _VolumeTag)
				{
					bWasInVolume = true;
				}
				else
				{
					bWasInVolume = false;
				}
			}
		}
	}
	*/
}

