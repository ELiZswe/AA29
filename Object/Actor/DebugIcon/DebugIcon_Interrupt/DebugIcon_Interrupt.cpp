// All the original content belonged to the US Army


#include "AA29/Object/Actor/DebugIcon/DebugIcon_Interrupt/DebugIcon_Interrupt.h"

ADebugIcon_Interrupt::ADebugIcon_Interrupt()
{
	Interrupt_Action_Complete_Tex	= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_actioncomp_Mat.interrupt_actioncomp_Mat"), NULL, LOAD_None, NULL);
	Interrupt_Ammo_Jam_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_ammojam_Mat.interrupt_ammojam_Mat"), NULL, LOAD_None, NULL);
	Interrupt_Bullet_Whip_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_bulletwhip_Mat.interrupt_bulletwhip_Mat"), NULL, LOAD_None, NULL);
	Interrupt_Enemy_Lost_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_enemylost_Mat.interrupt_enemylost_Mat"), NULL, LOAD_None, NULL);
	Interrupt_Friendly_Die_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_friendlydie_Mat.interrupt_friendlydie_Mat"), NULL, LOAD_None, NULL);
	Interrupt_Hear_Gunfire_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_heargunfire_Mat.interrupt_heargunfire_Mat"), NULL, LOAD_None, NULL);
	Interrupt_Hear_Movement_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_hearmove_Mat.interrupt_hearmove_Mat"), NULL, LOAD_None, NULL);
	Interrupt_Injured_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_injured_Mat.interrupt_injured_Mat"), NULL, LOAD_None, NULL);
	Interrupt_Kill_Enemy_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_killenemy_Mat.interrupt_killenemy_Mat"), NULL, LOAD_None, NULL);
	Interrupt_See_Grenade_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_seegrenade_Mat.interrupt_seegrenade_Mat"), NULL, LOAD_None, NULL);
	Interrupt_See_Enemy_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_seenemy_Mat.interrupt_seenemy_Mat"), NULL, LOAD_None, NULL);
	Interrupt_See_Vehicle_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/interrupt_seevehicle_Mat.interrupt_seevehicle_Mat"), NULL, LOAD_None, NULL);
	Texture							= Interrupt_Action_Complete_Tex;
		
}

void ADebugIcon_Interrupt::UpdateAction(FString NewAction)
{
	if (NewAction == "SeePlayer")		{		Texture = Interrupt_See_Enemy_Tex;			return; }
	if (NewAction == "SeeVehicle")		{		Texture = Interrupt_See_Vehicle_Tex;		return; }
	if (NewAction == "SeeGrenade")		{		Texture = Interrupt_See_Grenade_Tex;		return; }
	if (NewAction == "BulletWhip")		{		Texture = Interrupt_Bullet_Whip_Tex;		return; }
	if (NewAction == "AmmoJam")			{		Texture = Interrupt_Ammo_Jam_Tex;			return; }
	if (NewAction == "Injured")			{		Texture = Interrupt_Injured_Tex;			return; }
	if (NewAction == "EnemyKilled")		{		Texture = Interrupt_Kill_Enemy_Tex;			return; }
	if (NewAction == "FriendDied")		{		Texture = Interrupt_Friendly_Die_Tex;		return; }
	if (NewAction == "HearGunfire")		{		Texture = Interrupt_Hear_Gunfire_Tex;		return; }
	if (NewAction == "HeardPlayer")		{		Texture = Interrupt_Hear_Movement_Tex;		return; }
	if (NewAction == "LostEnemy")		{		Texture = Interrupt_Enemy_Lost_Tex;			return; }
	if (NewAction == "ActionComplete")	{		Texture = Interrupt_Action_Complete_Tex;	return; }
}