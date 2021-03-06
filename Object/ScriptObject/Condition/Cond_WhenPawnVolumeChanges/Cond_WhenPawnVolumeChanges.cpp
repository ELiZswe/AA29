// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenPawnVolumeChanges/Cond_WhenPawnVolumeChanges.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"

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
		Log("Cond_WhenPawnVolumeChanges::ConditionStart()");
	}
	_Pawn.SetCurrentVolumeMonitor(this);
	*/
}

void UCond_WhenPawnVolumeChanges::ConditionFinish()
{
	UScriptObject* soBlank = nullptr;
	if (_bDebug)
	{
		//Log("Cond_WhenPawnVolumeChanges::ConditionFinish()");
	}
	//_Pawn.SetCurrentVolumeMonitor(soBlank);
}

bool UCond_WhenPawnVolumeChanges::ProcessParams()
{
	//_VolumeTag = FString::FromInt(GetParam(0));
	//_Actor = _ParentScreenplay.GetActorByTag(string(GetParam(1)));
	//_bEntry = bool(GetParam(2));
	return true;
}

void UCond_WhenPawnVolumeChanges::SetActor(AActor* Actor)
{
	if (_bDebug)
	{
		//Log("Cond_WhenPawnVolumeChanges::SetActor(" + FString::FromInt(Actor.Tag) + ")");
	}
	_Actor = Actor;
}

void UCond_WhenPawnVolumeChanges::SetVolumeTag(FName voltag)
{
	if (_bDebug)
	{
		//Log("Cond_WhenPawnVolumeChanges::SetVolumeTag(" + FString::FromInt(voltag) + ")");
	}
	_VolumeTag = voltag;
}

void UCond_WhenPawnVolumeChanges::SetVolumeNotifyOnEntry(bool Entry)
{
	if (_bDebug)
	{
		//Log("Cond_WhenPawnVolumeChanges::SetVolumeNotifyOnEntry(" + FString::FromInt(Entry) + ")");
	}
	_bEntry = Entry;
}

void UCond_WhenPawnVolumeChanges::update()
{
	AVolume* vol = nullptr;
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPawnVolumeChanges::Update()");
	}
	if (_Pawn != nullptr)
	{
		vol = _Pawn.GetCurrentVolume();
		if (_bEntry)
		{
			if (_bDebug)
			{
				Log("Cond_WhenPawnVolumeChanges::Update() - checking if we enter");
			}
			if (vol != nullptr)
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
			if (vol == nullptr)
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

