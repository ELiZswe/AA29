// All the original content belonged to the US Army


#include "AA29/AAGameplay/MarksmanTarget_Part/MarksmanTarget_Part.h"

AMarksmanTarget_Part::AMarksmanTarget_Part()
{
	DrawType = EDrawType::DT_StaticMesh;
		//StaticMesh = StaticMesh'M_AA2_FX.misc.fx_misc_sheet';
	if (StaticMesh)
	{
		StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Targets/eqp2_targets_gguy1a.eqp2_targets_gguy1a'")));
	}

			//bUseDynamicLights = false;
		//Skins(0) = Texture'T_AA2_MISC.misc.misc_cork_tile';
		//bUnlit = true;
		//bShadowCast = false;
		//bStaticLighting = true;
		//CollisionRadius = 10;
		//CollisionHeight = 10;
		//bCollideWorld = false;
		//bBlockActors = false;
		//bBlockPlayers = false;
		//bBlockNonZeroExtentTraces = false;
		//bUseCylinderCollision = false;
}

void AMarksmanTarget_Part::SetMarksmanTarget(AMarksmanTarget* t)
{
	Target = t;
}
void AMarksmanTarget_Part::SetZoneID(FString Id)
{
	ZoneID = Id;
}
/*
void AMarksmanTarget_Part::TakeDamage(int Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (Target != None)
	{
		Target.NotifyDamaged(Damage, EventInstigator, DamageType, ZoneID);
	}
}
*/