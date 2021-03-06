// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/SpecialEventTrigger/SpecialEventTrigger.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"

ASpecialEventTrigger::ASpecialEventTrigger()
{
	bPlayerJumpToInterpolation = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/GamePlay/S_SpecialEvent_Mat.S_SpecialEvent_Mat'"), NULL, LOAD_None, NULL);
	//bObsolete = true;
}

void ASpecialEventTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	APlayerController* p = nullptr;
	AScriptedSequence* S = nullptr;
	AActor* A = nullptr;
	/*
	if (Len(Message) != 0)
	{
		if (bBroadcast)
		{
			Level.Game.Broadcast(EventInstigator, Message, "CriticalEvent");
		}
		else
		{
			if ((Len(Message) != 0) && (EventInstigator != nullptr))
			{
				EventInstigator.ClientMessage(Message);
			}
		}
	}
	if (Sound != nullptr)
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
		Other.TakeDamage(Damage, EventInstigator, EventInstigator->GetActorLocation(), FVector(0, 0, 0), DamageType);
	}
	if (EventInstigator == nullptr)
	{
		return;
	}
	if (AmbientSound != nullptr)
	{
		EventInstigator.AmbientSound = AmbientSound;
	}
	if (bKillInstigator)
	{
		EventInstigator.Died(None, DamageType, EventInstigator.Location);
	}
	if (((Event != "None") && (Event != "None")) && (GetWorld()->GetNetMode() == NM_Standalone))
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
				Cast<APlayerController>(EventInstigator.Controller).SetViewTarget(A);
				Cast<APlayerController>(EventInstigator.Controller).bBehindView = bThirdPersonViewTarget;
				if (PlayerScriptTag != "None")
				{
					ForEach DynamicActors(AScriptedSequence::StaticClass(), S, PlayerScriptTag)
					{
					}
					if (S != nullptr)
					{
						EventInstigator.Controller.Pawn = nullptr;
						Cast<APlayerController>(EventInstigator.Controller).GotoState("Spectating");
						S.TakeOver(EventInstigator);
					}
				}
			}
		}
	}
	*/
}
