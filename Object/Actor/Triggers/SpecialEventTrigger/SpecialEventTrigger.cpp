// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/SpecialEventTrigger/SpecialEventTrigger.h"

ASpecialEventTrigger::ASpecialEventTrigger()
{
	bPlayerJumpToInterpolation = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/GamePlay/S_SpecialEvent_Mat.S_SpecialEvent_Mat'"), NULL, LOAD_None, NULL);
	//bObsolete = true;
}

void ASpecialEventTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	local PlayerController p;
	local ScriptedSequence S;
	local Actor A;
	if (Len(Message) != 0)
	{
		if (bBroadcast)
		{
			Level.Game.Broadcast(EventInstigator, Message, "CriticalEvent");
		}
		else
		{
			if ((Len(Message) != 0) && (EventInstigator != None))
			{
				EventInstigator.ClientMessage(Message);
			}
		}
	}
	if (Sound != None)
	{
		if (bPlayersPlaySoundEffect)
		{
			ForEach DynamicActors(Class'PlayerController', p)
			{
				p.ClientPlaySound(Sound);
			}
		}
		else
		{
			PlaySound(Sound);
		}
	}
	if (Damage > 0)
	{
		Other.TakeDamage(Damage, EventInstigator, EventInstigator.Location, vect(0, 0, 0), DamageType);
	}
	if (EventInstigator == nullptr)
	{
		return;
	}
	if (AmbientSound != None)
	{
		EventInstigator.AmbientSound = AmbientSound;
	}
	if (bKillInstigator)
	{
		EventInstigator.Died(None, DamageType, EventInstigator.Location);
	}
	if (((Event != "None") && (Event != "None")) && (Level.NetMode == NM_Standalone))
	{
		if ((InterpolatedActorTag == "None") || (InterpolatedActorTag == "None"))
		{
			if (EventInstigator.IsPlayerPawn())
			{
				A = EventInstigator;
				if (A.bInterpolating)
				{
					return;
				}
			}
			else
			{
				return;
			}
		}
		else
		{
			ForEach DynamicActors(Class'Actor', A, InterpolatedActorTag)
			{
			}
			if ((A == nullptr) || A.bInterpolating)
			{
				return;
			}
			if (bViewTargetInterpolatedActor && EventInstigator.IsHumanControlled())
			{
				PlayerController(EventInstigator.Controller).SetViewTarget(A);
				PlayerController(EventInstigator.Controller).bBehindView = bThirdPersonViewTarget;
				if (PlayerScriptTag != "None")
				{
					ForEach DynamicActors(class'GamePlay.ScriptedSequence', S, PlayerScriptTag)
					{
					}
					if (S != None)
					{
						EventInstigator.Controller.Pawn = nullptr;
						PlayerController(EventInstigator.Controller).GotoState("Spectating");
						S.TakeOver(EventInstigator);
					}
				}
			}
		}
	}
	*/
}
