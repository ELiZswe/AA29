// All the original content belonged to the US Army


#include "AA29/AGP_Trigger/NoiseTrigger/NoiseTrigger.h"

ANoiseTrigger::ANoiseTrigger()
{
	NOTIFYDELAY = 1;
	Noises = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Outdoor/Brush1_Cue.Brush1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Outdoor/Brush2_Cue.Brush2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Outdoor/Brush3_Cue.Brush3_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Outdoor/Brush4_Cue.Brush4_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Outdoor/Brush5_Cue.Brush5_Cue'"), NULL, LOAD_None, NULL)
	};
	NoiseVolume = 1;
	NoiseRadius = 256;
	ScriptVolume = 1;
	MaxVelocity = 60;
	//bHidden = false;
	//bAcceptsProjectors = false;
	//bStaticLighting = true;
	//CollisionRadius = 32;
	//CollisionHeight = 32;
	//bUseCylinderCollision = true;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	//bDirectional = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}


/*
State Idle
{
	Function BeginState()
	{
	}
}
State PlayingSound
{
	Function UnTouch(Actor Other)
	{
	}
	Function Touch(Actor Other)
	{
	}
	Function Tick(float DeltaTime)
	{
		if (VSize(Instigator.Location - Location) > CollisionRadius * 2)
		{
			Instigator = None;
			GotoState('Idle');
			Return;
		}
	}
	Function BeginState()
	{
	}
}
*/

void ANoiseTrigger::Touch(AActor* Other)
{
	/*
	Instigator = AGP_Pawn(Other);
	if (Instigator != None && Instigator.Controller.IsA('HumanController'))
	{
		SetTimer(NOTIFYDELAY + 0.001, false);
		if (VSize(Instigator.Velocity) > MaxVelocity)
		{
			GotoState('PlayingSound');
		}
	}
	*/
}
void ANoiseTrigger::Timer()
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 4, Instigator, "EXTNOISE," $ ScriptVolume);
	}
	*/
}
void ANoiseTrigger::UnTouch(AActor* Other)
{
}
void ANoiseTrigger::Tick(float DeltaTime)
{
	/*
	Tick(DeltaTime);
	if (Instigator != None && VSize(Instigator.Velocity) > MaxVelocity)
	{
		GotoState('PlayingSound');
	}
	*/
}