// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC.h"

AFSTS_NPC::AFSTS_NPC()
{
	bStaticSkinsAndMeshes  = true;
	bCleanUp               = false;
	//ActionIcon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_HUD_USE_ICON_S_Mat.T_UI_HUD_USE_ICON_S_Mat'"), NULL, LOAD_None, NULL);
}

void AFSTS_NPC::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	//DoAnimLoop();
}

/*
void AFSTS_NPC::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	if (!bNoTakeDamage)
	{
		Super::TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
	}
	else
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this, ET_Destroyed, instigatedBy);
		}
	}
}
*/
