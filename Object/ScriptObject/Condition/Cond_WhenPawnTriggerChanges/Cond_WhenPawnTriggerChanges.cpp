// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenPawnTriggerChanges/Cond_WhenPawnTriggerChanges.h"

UCond_WhenPawnTriggerChanges::UCond_WhenPawnTriggerChanges()
{
	_nNumParamsDefined = 3;
}

void UCond_WhenPawnTriggerChanges::Destroyed()
{
	Super::Destroyed();
	_Actor = nullptr;
	_Pawn = nullptr;
}

void UCond_WhenPawnTriggerChanges::ConditionStart()
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
		Log("Cond_WhenPawnTriggerChanges::ConditionStart()");
	}
	_Pawn.SetCurrentTriggerMonitor(Self);
	*/
}

void UCond_WhenPawnTriggerChanges::ConditionFinish()
{
	/*
	local ScriptObject soBlank;
	if (_bDebug)
	{
		Log("Cond_WhenPawnTriggerChanges::ConditionFinish()");
	}
	_Pawn.SetCurrentTriggerMonitor(soBlank);
	*/
}

bool UCond_WhenPawnTriggerChanges::ProcessParams()
{
	/*
	_TriggerTag = string(GetParam(0));
	_Actor = _ParentScreenplay.GetActorByTag(string(GetParam(1)));
	_bEntry = bool(GetParam(2));
	*/
	return true;
}

void UCond_WhenPawnTriggerChanges::SetActor(AActor* Actor)
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPawnTriggerChanges::SetActor(" $ string(Actor.Tag) $ ")");
	}
	_Actor = Actor;
	*/
}

void UCond_WhenPawnTriggerChanges::SetTriggerTag(FName trigtag)
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPawnTriggerChanges::SetVolumeTag(" $ string(trigtag) $ ")");
	}
	_TriggerTag = trigtag;
	*/
}

void UCond_WhenPawnTriggerChanges::SetTriggerNotifyOnEntry(bool Entry)
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPawnTriggerChanges::SetTriggerNotifyOnEntry(" $ string(Entry) $ ")");
	}
	_bEntry = Entry;
	*/
}

void UCond_WhenPawnTriggerChanges::update()
{
	/*
	local AGP_Gameplay.AGP_Trigger trig;
	if (_bDebug)
	{
		Log("Cond_WhenPawnTriggerChanges::Update()");
	}
	if (_Pawn != None)
	{
		trig = AGP_Trigger(_Pawn.GetCurrentTrigger());
		if (_bEntry)
		{
			if (trig != None)
			{
				if (trig.Tag == _TriggerTag)
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
			if (trig == None)
			{
				Notify();
			}
			else
			{
				_bTrue = false;
				if (trig.Tag == _TriggerTag)
				{
					bWasInTrigger = true;
				}
				else
				{
					bWasInTrigger = false;
				}
			}
		}
	}
	*/
}
