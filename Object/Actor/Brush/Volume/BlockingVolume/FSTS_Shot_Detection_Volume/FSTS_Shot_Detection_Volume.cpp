// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/FSTS_Shot_Detection_Volume/FSTS_Shot_Detection_Volume.h"

AFSTS_Shot_Detection_Volume::AFSTS_Shot_Detection_Volume()
{
	//bBlockActors = false;
	//bProjTarget = true;
	//bBlockZeroExtentTraces = true;
	//bBlockKarma = false;
}

/*
void AFSTS_Shot_Detection_Volume::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, Actor.BoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	Log("Takedamage called");
	if (Ambush_Lab != None)
	{
		Ambush_Lab.Register_Volume_Hit(Self);
	}
	if (Event != "None")
	{
		TriggerEvent(Event, Self, None);
	}
}
*/