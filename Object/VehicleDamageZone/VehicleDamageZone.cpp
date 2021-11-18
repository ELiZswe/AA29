// All the original content belonged to the US Army


#include "AA29/Object/VehicleDamageZone/VehicleDamageZone.h"

UVehicleDamageZone::UVehicleDamageZone()
{
	DamageModifier = 1;
	MaxHitPoints = 100;
}

void UVehicleDamageZone::CopyDamageZones(UVehicleDamageZone* DefaultZone)
{
	/*
	local int i;
	ArmorThreshold = DefaultZone.ArmorThreshold;
	DamageModifier = DefaultZone.DamageModifier;
	MaxHitPoints = DefaultZone.MaxHitPoints;
	HitPoints = DefaultZone.HitPoints;
	bWheelZone = DefaultZone.bWheelZone;
	WheelNum = DefaultZone.WheelNum;
	bInitialSyncToVehicleHealth = DefaultZone.bInitialSyncToVehicleHealth;
	bNoPassDamageToVehicle = DefaultZone.bNoPassDamageToVehicle;
	bControlsExternalMesh = DefaultZone.bControlsExternalMesh;
	VehiclePositionOwnerIndex = DefaultZone.VehiclePositionOwnerIndex;
	MeshOwnerType = DefaultZone.MeshOwnerType;
	bAttachedToLeftTread = DefaultZone.bAttachedToLeftTread;
	bAttachedToRightTread = DefaultZone.bAttachedToRightTread;
	PenetrationPercent = DefaultZone.PenetrationPercent;
	ChildDamageZones.insert(0, DefaultZone.ChildDamageZones.Length);
	for (i = 0; i < DefaultZone.ChildDamageZones.Length; i++)
	{
		ChildDamageZones[i] = DefaultZone.ChildDamageZones[i];
	}
	WindowDamageZones.insert(0, DefaultZone.WindowDamageZones.Length);
	for (i = 0; i < DefaultZone.WindowDamageZones.Length; i++)
	{
		WindowDamageZones[i] = DefaultZone.WindowDamageZones[i];
	}
	if (DefaultZone.DamageStates.Length > 0)
	{
		DamageStates.insert(0, DefaultZone.DamageStates.Length);
		for (i = 0; i < DefaultZone.DamageStates.Length; i++)
		{
			DamageStates[i].DamageBones[0] = DefaultZone.DamageStates[i].DamageBones[0];
			DamageStates[i].DamageBones[1] = DefaultZone.DamageStates[i].DamageBones[1];
			DamageStates[i].DamageBones[2] = DefaultZone.DamageStates[i].DamageBones[2];
			DamageStates[i].DamageBones[3] = DefaultZone.DamageStates[i].DamageBones[3];
			DamageStates[i].DamageBones[4] = DefaultZone.DamageStates[i].DamageBones[4];
			DamageStates[i].DamageBones[5] = DefaultZone.DamageStates[i].DamageBones[5];
			DamageStates[i].DamageBones[6] = DefaultZone.DamageStates[i].DamageBones[6];
			DamageStates[i].DamageBones[7] = DefaultZone.DamageStates[i].DamageBones[7];
			DamageStates[i].BoneSlot[0] = DefaultZone.DamageStates[i].BoneSlot[0];
			DamageStates[i].BoneSlot[1] = DefaultZone.DamageStates[i].BoneSlot[1];
			DamageStates[i].BoneSlot[2] = DefaultZone.DamageStates[i].BoneSlot[2];
			DamageStates[i].BoneSlot[3] = DefaultZone.DamageStates[i].BoneSlot[3];
			DamageStates[i].BoneSlot[4] = DefaultZone.DamageStates[i].BoneSlot[4];
			DamageStates[i].BoneSlot[5] = DefaultZone.DamageStates[i].BoneSlot[5];
			DamageStates[i].BoneSlot[6] = DefaultZone.DamageStates[i].BoneSlot[6];
			DamageStates[i].BoneSlot[7] = DefaultZone.DamageStates[i].BoneSlot[7];
			DamageStates[i].DamagePct = DefaultZone.DamageStates[i].DamagePct;
			DamageStates[i].ChildDamagePct = DefaultZone.DamageStates[i].ChildDamagePct;
			DamageStates[i].VisualEffectClass = DefaultZone.DamageStates[i].VisualEffectClass;
			DamageStates[i].VisualEffect = DefaultZone.DamageStates[i].VisualEffect;
			DamageStates[i].PhysicalEffect = DefaultZone.DamageStates[i].PhysicalEffect;
		}
	}
	CurrentDamageState = DefaultZone.CurrentDamageState;
	*/
}
void UVehicleDamageZone::Destroyed()
{
	MeshOwner = nullptr;
	//ChildDamageZones.remove(0, ChildDamageZones.Length);
}
