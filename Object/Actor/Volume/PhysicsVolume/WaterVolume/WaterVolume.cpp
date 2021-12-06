// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/PhysicsVolume/WaterVolume/WaterVolume.h"

AWaterVolume::AWaterVolume()
{
	EntrySoundName = "PlayerSounds.FootstepWater1";
	ExitSoundName = "GeneralImpacts.ImpactSplash2";
	EntryActorName = "xGame.WaterSplash";
	PawnEntryActorName = "xGame.WaterRing";
	FluidFriction = 2.4;
	bWaterVolume = true;
	bDistanceFog = true;
	DistanceFogColor = FColor(128, 64, 32, 64);
	DistanceFogStart = 8;
	DistanceFogEnd = 2000;
	KExtraLinearDamping = 2.5;
	KExtraAngularDamping = 0.4;
	NV_DistanceFogColor = FColor(128, 64, 32, 64);
	NV_DistanceFogStart = 8;
	NV_DistanceFogEnd = 2000;
	//LocationName = "under water";
}

void AWaterVolume::PostBeginPlay()
{
	//Super::PostBeginPlay();
	if ((EntrySound == nullptr) && (EntrySoundName != ""))
	{
		//EntrySound = Sound(DynamicLoadObject(EntrySoundName, Class'Sound'));
	}
	if ((ExitSound == nullptr) && (ExitSoundName != ""))
	{
		//ExitSound = Sound(DynamicLoadObject(ExitSoundName, Class'Sound'));
	}
	if ((EntryActor == nullptr) && (EntryActorName != ""))
	{
		//EntryActor = class<Actor>(DynamicLoadObject(EntryActorName, Class'Class'));
	}
	if ((PawnEntryActor == nullptr) && (PawnEntryActorName != ""))
	{
		//PawnEntryActor = class<Actor>(DynamicLoadObject(PawnEntryActorName, Class'Class'));
	}
}
