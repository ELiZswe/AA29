// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenPawnTriggerChanges/Cond_WhenPawnTriggerChanges.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"

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
	if (_Pawn == nullptr)
	{
		if (_Actor != nullptr)
		{
			if (_Actor->IsA(AHumanController::StaticClass()))
			{
				_Pawn = Cast<AAGP_Pawn>(Cast<AHumanController>(_Actor).Pawn);
			}
			if (_Actor->IsA(AAGP_Pawn::StaticClass()))
			{
				_Pawn = Cast<AAGP_Pawn>(_Actor);
			}
		}
	}
	if (_bDebug)
	{
		Log("Cond_WhenPawnTriggerChanges::ConditionStart()");
	}
	_Pawn.SetCurrentTriggerMonitor(this);
	*/
}

void UCond_WhenPawnTriggerChanges::ConditionFinish()
{
	UScriptObject* soBlank = nullptr;
	/*
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
	_TriggerTag = FString::FromInt(GetParam(0));
	_Actor = _ParentScreenplay.GetActorByTag(string(GetParam(1)));
	_bEntry = bool(GetParam(2));
	*/
	return true;
}

void UCond_WhenPawnTriggerChanges::SetActor(AActor* Actor)
{
	if (_bDebug)
	{
		//Log("Cond_WhenPawnTriggerChanges::SetActor(" + FString::FromInt(Actor.Tag) + ")");
	}
	_Actor = Actor;
}

void UCond_WhenPawnTriggerChanges::SetTriggerTag(FName trigtag)
{
	if (_bDebug)
	{
		//Log("Cond_WhenPawnTriggerChanges::SetVolumeTag(" + FString::FromInt(trigtag) + ")");
	}
	_TriggerTag = trigtag;
}

void UCond_WhenPawnTriggerChanges::SetTriggerNotifyOnEntry(bool Entry)
{
	if (_bDebug)
	{
		//Log("Cond_WhenPawnTriggerChanges::SetTriggerNotifyOnEntry(" + FString::FromInt(Entry) + ")");
	}
	_bEntry = Entry;
}

void UCond_WhenPawnTriggerChanges::update()
{
	AAGP_Trigger* trig = nullptr;
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPawnTriggerChanges::Update()");
	}
	if (_Pawn != nullptr)
	{
		trig = Cast<AAGP_Trigger>(_Pawn.GetCurrentTrigger());
		if (_bEntry)
		{
			if (trig != nullptr)
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
			if (trig == nullptr)
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
