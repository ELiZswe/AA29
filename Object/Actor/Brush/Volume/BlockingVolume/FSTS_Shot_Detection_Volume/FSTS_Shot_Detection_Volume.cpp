// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/FSTS_Shot_Detection_Volume/FSTS_Shot_Detection_Volume.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_Ambush/FA_EL_Ambush.h"

AFSTS_Shot_Detection_Volume::AFSTS_Shot_Detection_Volume()
{
	//bBlockActors = false;
	//bProjTarget = true;
	//bBlockZeroExtentTraces = true;
	//bBlockKarma = false;
}

/*
void AFSTS_Shot_Detection_Volume::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	Log("Takedamage called");
	if (Ambush_Lab != nullptr)
	{
		Ambush_Lab.Register_Volume_Hit(this);
	}
	if (Event != "None")
	{
		TriggerEvent(Event, this, None);
	}
}
*/
