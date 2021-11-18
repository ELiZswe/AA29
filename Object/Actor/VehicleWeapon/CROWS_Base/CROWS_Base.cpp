// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/CROWS_Base/CROWS_Base.h"

ACROWS_Base::ACROWS_Base()
{
	Ammo = 200;
		ChargeTimerName = "ChargeTimer";
		//ChargeSound = Sound'S_AAO_Armory.M2.s_arm_m2_crows_charge_armed';
		ChargeTime = 3;
		CameraPitchBone = "B_Camera";
		MinSustain = 0.3;
		//ServoAtkLR = Sound'S_AAO_Armory.M2.s_arm_m2_servo_lr_attack';
		//ServoRelLR = Sound'S_AAO_Armory.M2.s_arm_m2_servo_lr_release';
		//ServoSusLR = Sound'S_AAO_Armory.M2.s_arm_m2_servo_lr_sustain';
		ServoVolumeLR = 0.05;
		//ServoDamagedSus = Sound'S_AAO_Armory.M2.s_arm_m2_crows_motor_damaged';
		//DryFireSound = Sound'S_AAO_Armory.M2.s_arm_m2_crows_dry_fire';
		//CameraFailureSound = Sound'S_AAO_Armory.M2.s_arm_m2_crows_optics_damaged';
		//GunFailureSound = Sound'S_AAO_Armory.M2.s_arm_m2_crows_weapon_damaged';
		//ServoAtkUD = Sound'S_AAO_Armory.M2.s_arm_m2_servo_ud_attack';
		//ServoRelUD = Sound'S_AAO_Armory.M2.s_arm_m2_servo_ud_release';
		//ServoSusUD = Sound'S_AAO_Armory.M2.s_arm_m2_servo_ud_sustain';
		ServoVolumeUD = 0.05;
		ServoSoundRadius = 128;
		//asBodyPanelClasses(0) = "AGP.CROWS_Main_BodyPanel";
		//asBodyPanelClasses(1) = "AGP.CROWS_Camera_BodyPanel";
		//asBodyPanelClasses(2) = "AGP.CROWS_WeaponMount_BodyPanel";
		//asBodyPanelClasses(3) = "AGP.CROWS_M2_BodyPanel";
		//StartBodyPanelMeshes(0) = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_main';
		//StartBodyPanelMeshes(1) = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_camera';
		//StartBodyPanelMeshes(2) = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_weaponmount';
		//StartBodyPanelMeshes(3) = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_m2';
		//StartBodyPanelBones(0) = B_Base;
		//StartBodyPanelBones(1) = B_Camera;
		//StartBodyPanelBones(2) = B_Weapon;
		//StartBodyPanelBones(3) = B_Weapon;
		WeaponFireBone = "B_Muzzle";
		WeaponFireBaseBone = "B_Weapon";
		CameraViewBone = "B_WeaponCamera";
		CameraBaseBone = "B_WeaponCamera_50cal_Vector";
		RootBone = "CROWS_Root";
		iCameraHealth = 1000;
		iCameraLensHealth = 150;
		iLaserHealth = 150;
		iYawServoHealth = 1000;
		iPitchServoHealth = 1000;
		iWeaponHealth = 1500;
		//DamageThreshholds(0) = 100;
		//DamageThreshholds(1) = 200;
		//DamageThreshholds(2) = 400;
		//DamagedTexture(0) = Texture'T_AAO_Skins.weapons.t_skin_weapons_crows_mount_1a';
		//DamagedTexture(1) = Texture'T_AAO_Skins.weapons.t_skin_weapons_crows_mount_1b';
		//DamagedTexture(2) = Texture'T_AAO_Skins.weapons.t_skin_weapons_crows_mount_1c';
		YawBone = "B_Base";
		PitchBone = "B_Weapon";
		PitchUpLimit = 6760;
		PitchDownLimit = -4500;
		WeaponFireAttachmentBone = "B_Muzzle";
		WeaponFireOffset = 76;
		RotationsPerSecond = 20;
		bDoOffsetTrace = true;
		bCorrectAim = false;
		//TracerClass = Class'AGP.BaseTracer';
		//FireSoundClass = Sound'S_AAO_Armory.M2.s_arm_m2_single_fire';
		FireSoundVolume = 512;
		FireSoundRadius = 256;
		//ProjectileClass = Class'AGP_Inventory.Proj_MK19Gren';
		ShakeRotMag = FVector(0, 0, 200);
		ShakeRotRate = FVector(0, 0, 500);
		ShakeRotTime = 1.25;
		ShakeOffsetMag = FVector(0, 0, 1);
		ShakeOffsetRate = FVector(0, 0, 200);
		ShakeOffsetTime = 1.25;
		//WeaponAimAnims(0) = "vehhmvcrwsidle";
		//WeaponAimAnims(1) = "vehhmvcrwsidle";
		numWeaponAimAnims = 1;
		//	\\AIInfo = ;
		//Mesh = SkeletalMesh'A_AAO_Vehicles.CROWS';
		//CollisionRadius = 1;
		//CollisionHeight = 1;
		//bUseCylinderCollision = true;
}
/*
State ProjectileFireMode
{
	Function Fire(Controller C)
	{
		if (iSystemStatus & 32 != 32)
		{
			if (GunFailureClicks == 0)
			{
				WeaponFailureSounds();
			}
			else
			{
				PlayOwnedSound(DryFireSound,0,FireSoundVolume / 255,,FireSoundRadius,,False);
			}
			Return;
		}
		if (Ammo > 0 && bCharged)
		{
			SpawnProjectile(ProjectileClass,False);
			Ammo--;
		}
		else
		{
			PlayOwnedSound(DryFireSound,0,FireSoundVolume / 255,,FireSoundRadius,,False);
		}
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,23,Instigator,"InstantFireMode");
		}
	}
}
*/


void ACROWS_Base::WeaponFailureSounds()
{
	/*
	if (GunFailureClicks < 3)
	{
		PlaySound(DryFireSound, 0, FireSoundVolume / 255, , FireSoundRadius);
		GunFailureClicks++;
		SetCustomTimer(GetSoundDuration(DryFireSound), False, 'WeaponFailureSounds');
	}
	else
	{
		PlaySound(GunFailureSound, 0, FireSoundVolume / 255, , FireSoundRadius);
	}
	*/
}

void ACROWS_Base::SpawnProjectile(AProjectile* ProjClass, bool bAltFire)
{
	/*
	local Projectile p;
	DebugLog(DEBUG_Vehicle, "Spawning Projectile" $ ProjClass);
	CalcWeaponFire();
	p = Spawn(ProjClass, , , WeaponFireLocation, WeaponFireRotation, True);
	DebugLog(DEBUG_Vehicle, "Spawned P:" $ p);
	if (p != None)
	{
		FlashMuzzleFlash();
		if (bAmbientFireSound)
		{
			AmbientSound = FireSoundClass;
		}
		else
		{
			PlayOwnedSound(FireSoundClass, 0, FireSoundVolume / 255, , FireSoundRadius, , False);
		}
		if (!bCasingQueued)
		{
			SetCustomTimer(CasingSoundMinDelay + FRand() * CasingDelayDeviation, False, 'PlayCasingRing');
			bCasingQueued = true;
		}
		if (HissCount == 0)
		{
			SetCustomTimer(HissDecrementDelay, False, 'DecrementHiss');
		}
		HissCount += 1;
		if (HissCount >= HissTriggerCount)
		{
			StopCustomTimer('PlayHiss');
			SetCustomTimer(FireInterval + 0.05, False, 'PlayHiss');
		}
	}
	Return p;
	*/
}
void ACROWS_Base::DecrementHiss()
{
	/*
	HissCount -= 3;
	if (HissCount < 0)
	{
		HissCount = 0;
	}
	if (HissCount != 0)
	{
		SetCustomTimer(HissDecrementDelay, False, 'DecrementHiss');
	}
	*/
}
void ACROWS_Base::PlayHiss()
{
	/*
	local float fSoundDuration;
	PlayOwnedSound(BarrelHiss, 0, FireSoundVolume / 512, , FireSoundRadius, , False);
	fSoundDuration = GetSoundDuration(BarrelHiss);
	StopCustomTimer('FinishHiss');
	SetCustomTimer(fSoundDuration * 3 / 4, False, 'FinishHiss');
	*/
}
void ACROWS_Base::FinishHiss()
{
	//StopCustomTimer('DecrementHiss');
	HissCount = 0;
}

void ACROWS_Base::OwnerEffects()
{
	/*
	if (iSystemStatus & 32 == 0)
	{
		Return;
	}
	if (Ammo > 0 && bCharged)
	{
		OwnerEffects();
	}
	*/
}

void ACROWS_Base::ShakeView()
{
	/*
	if (iSystemStatus & 32 == 0)
	{
		Return;
	}
	ShakeView();
	*/
}

void ACROWS_Base::ChargeWeapon()
{
	/*
	if (iSystemStatus & 32 == 0)
	{
		Return;
	}
	SetCustomTimer(ChargeTime, False, 'ChargeTimer');
	if (iSystemStatus & 32 != 32)
	{
		PlaySound(GunFailureSound, 0, FireSoundVolume / 255, , FireSoundRadius);
	}
	else
	{
		PlaySound(ChargeSound, , 1, , 10000);
	}
	bCharged = False;
	*/
}

void ACROWS_Base::SetLaseDistance(float inLaseDistance)
{
	LaseDistance = inLaseDistance;
}

void ACROWS_Base::HideGun(bool bHide)
{
	bHideGun = bHide;
	//bHidden = bHide;
}

void ACROWS_Base::ChargeTimer()
{
	bCharged = true;
}

void ACROWS_Base::Tick(float DeltaTime)
{
	/*
	local Object.Rotator TempRot;
	local int Inc;
	local int i;
	if (Instigator == None)
	{
		Tick(DeltaTime);
		Return;
	}
	if (DamageIndex != LastDamageIndex)
	{
		for (i = 0; i <= 3; i++)
		{
			BodyPanels[i].SwapTexture(DamagedTexture[DamageIndex]);
		}
		LastDamageIndex = DamageIndex;
	}
	if (Instigator.Controller != None && Instigator.Controller.bFire == 0)
	{
		GotoState('ProjectileFireMode');
	}
	if (RotateCamera.Yaw != 0 || RotateCamera.Pitch != 0)
	{
		TempRot = Instigator.Rotation;
		Inc = DeltaTime * 1000;
		if (RotateCamera.Yaw > 0)
		{
			if (Inc > RotateCamera.Yaw)
			{
				Inc = RotateCamera.Yaw;
			}
			TempRot.Yaw -= Inc;
			RotateCamera.Yaw -= Inc;
		}
		else
		{
			if (RotateCamera.Yaw < 0)
			{
				if (Inc > -RotateCamera.Yaw)
				{
					Inc = -RotateCamera.Yaw;
				}
				TempRot.Yaw += Inc;
				RotateCamera.Yaw += Inc;
			}
		}
		if (RotateCamera.Pitch > 0)
		{
			if (Inc > RotateCamera.Pitch)
			{
				Inc = RotateCamera.Pitch;
			}
			TempRot.Pitch -= Inc;
			RotateCamera.Pitch -= Inc;
		}
		else
		{
			if (RotateCamera.Pitch < 0)
			{
				if (Inc > -RotateCamera.Pitch)
				{
					Inc = -RotateCamera.Pitch;
				}
				TempRot.Pitch += Inc;
				RotateCamera.Pitch += Inc;
			}
		}
	}
	*/
	Super::Tick(DeltaTime);
}

void ACROWS_Base::SetLaseOffset(FRotator newOffset)
{
	LaseOffset = newOffset;
}

void ACROWS_Base::CalcWeaponFire()
{
	//WeaponFireLocation = GetBoneCoords(CameraViewBone).Origin;
	//WeaponFireRotation = GetBoneRotation(WeaponFireBone);
}

void ACROWS_Base::PlayCasingRing()
{
	//PlaySound(BulletCasingRing[Rand(3)], 0, FireSoundVolume / 255, , FireSoundRadius, , False);
	//bCasingQueued = False;
}

void ACROWS_Base::PostNetBeginPlay()
{
	/*
	PostNetBeginPlay();
	SetBoneRotation(WeaponFireAttachmentBone, rot(0 16384 0), 0, 1);
	if (Level.NetMode != 3)
	{
		AttachBodyPanels();
	}
	*/
}

void ACROWS_Base::PostBeginPlay()
{
	/*
	PostBeginPlay();
	BulletVelocity = ProjectileClass.Default.Speed;
	DebugLog(DEBUG_Vehicle, "CROWS_Base::PostBeginPlay");
	iSystemStatus = 255;
	*/
}

void ACROWS_Base::Destroyed()
{
	/*
	local int i;
	if (Role == 4)
	{
		for (i = 0; i < 4; i++)
		{
			BodyPanels[i].Destroy();
		}
	}
	*/
	Super::Destroyed();
}

void ACROWS_Base::AttachBodyPanels()
{
	/*
	local int i;
	DebugLog(DEBUG_Vehicle, Self $ ".AttachBodyPanels() entered ");
	for (i = 0; i < asBodyPanelClasses.Length; i++)
	{
		BodyPanels[i] = Spawn(Class'BodyPanel', Self);
		BodyPanels[i].PanelID = i;
		BodyPanels[i].SetStaticMesh(StartBodyPanelMeshes[i]);
		BodyPanels[i].RemoteRole = 1;
		BodyPanels[i].SetCollision(False, False, False);
		BodyPanels[i].bUseCollisionStaticMesh = False;
		BodyPanels[i].bAcceptsProjectors = False;
		BodyPanels[i].bBlockZeroExtentTraces = False;
		BodyPanels[i].bBlockNonZeroExtentTraces = False;
		AttachToBone(BodyPanels[i], StartBodyPanelBones[i]);
		BodyPanels[i].SetBase(Self);
		BodyPanels[i].RelRotation = rot(16384 0 32768);
		BodyPanels[i].SetRelativeRotation(BodyPanels[i].RelRotation);
		DebugLog(DEBUG_Vehicle, Self $ ".AttachBodyPanels() - Attaching: " $ BodyPanels[i] $ " To Bone " $ StartBodyPanelBones[i] $ " in " $ BodyPanels[i]);
	}
	*/
}

bool ACROWS_Base::IsPitchServoFunctional()
{
	/*
	if (iSystemStatus & 8 == 8)
	{
		Return True;
	}
	*/
	return false;
}

bool ACROWS_Base::IsYawServoFunctional()
{
	/*
	if (iSystemStatus & 16 == 16)
	{
		Return True;
	}
	*/
	return false;
}

void ACROWS_Base::GetFailedServoPitch()
{
	//Return rotRotationAtServoFailure.Pitch;
}

void ACROWS_Base::GetFailedServoYaw()
{
	//Return rotRotationAtServoFailure.Yaw;
}

void ACROWS_Base::TakeProjectileImpactDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector aMomentum, UaDamageType* InDamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	/*
	DebugLog(DEBUG_Vehicle, Self $ ".TakeProjectileImpactDamage() entered with damage: " $ Damage $ " on bone " $ Bone.Name);
	TakeProjectileImpactDamage(Damage, instigatedBy, HitLocation, aMomentum, InDamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
	*/
}
/*
void ACROWS_Base::TakeDamage(int Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	local int idx;
	DebugLog(DEBUG_Vehicle, "CROWS weapon system taking damage at location " $ HitLocation $ " Bone: " $ Bone.Name $ " Damage: " $ Damage);
	if (Damage == 0)
	{
		Damage = 30;
	}
	iTotalDamage += Damage;
	if (idx < DamageThreshholds.Length)
	{
		if (iTotalDamage <= DamageThreshholds[idx])
		{
		}
		idx++;
	}
	if (idx >= DamageThreshholds.Length)
	{
		idx = DamageThreshholds.Length - 1;
	}
	DamageIndex = idx;
	if (Bone.Name ~= "B_CAMERALENS")
	{
		if (FRand() > 0.5)
		{
			Bone.Name = "B_LASER";
		}
	}
	Switch(Bone.Name)
	{
			case "B_CAMERA":
				if (Damage <= iCameraHealth)
				{
					iCameraHealth -= Damage;
					break;
				}
				iCameraHealth = 0;
	}
	DebugLog(DEBUG_Vehicle, "CROWS camera health: " $ iCameraHealth);
	if (iCameraHealth == 0)
	{
		iSystemStatus = iSystemStatus & ~1 | 2 | 4;
		DebugLog(DEBUG_Vehicle, "Camera disabled: " $ iSystemStatus);
	}
	GOTO JL0595;
		case "B_CAMERALENS":
			if (Damage <= iCameraLensHealth)
			{
				iCameraLensHealth -= Damage;
			}
			else
			{
				iCameraLensHealth = 0;
			}
			DebugLog(DEBUG_Vehicle, "CROWS camera lens health: " $ iCameraLensHealth);
			if (iCameraLensHealth == 0)
			{
				PlaySound(CameraFailureSound, , 1, , 10000);
				iSystemStatus = iSystemStatus & ~2;
				DebugLog(DEBUG_Vehicle, "Camera lens disabled: " $ iSystemStatus);
			}
			GOTO JL0595;
		case "B_LASER":
			if (Damage <= iLaserHealth)
			{
				iLaserHealth -= Damage;
			}
			else
			{
				iLaserHealth = 0;
			}
			DebugLog(DEBUG_Vehicle, "CROWS laser health: " $ iLaserHealth);
			if (iLaserHealth == 0)
			{
				iSystemStatus = iSystemStatus & ~4;
				DebugLog(DEBUG_Vehicle, "Laser disabled: " $ iSystemStatus);
			}
			GOTO JL0595;
		case "B_MUZZLE":
			if (iWeaponHealth > 0)
			{
				if (Damage <= iWeaponHealth)
				{
					iWeaponHealth -= Damage;
				}
				else
				{
					iWeaponHealth = 0;
				}
				DebugLog(DEBUG_Vehicle, "CROWS weapon health: " $ iWeaponHealth);
				if (iWeaponHealth == 0)
				{
					iSystemStatus = iSystemStatus & ~32;
					DebugLog(DEBUG_Vehicle, "M2 disabled: " $ iSystemStatus);
				}
			}
			GOTO JL0595;
		case "CROWS_ROOT":
		case "B_WEAPON":
		case "B_BASE":
			if (FRand() > 0.5)
			{
				if (Damage <= iPitchServoHealth)
				{
					iPitchServoHealth -= Damage;
				}
				else
				{
					iPitchServoHealth = 0;
				}
				DebugLog(DEBUG_Vehicle, "CROWS pitch servo health: " $ iPitchServoHealth);
				if (iPitchServoHealth == 0)
				{
					rotRotationAtServoFailure.Pitch = PlayerController(Pawn(Owner).Controller).GetViewRotation().Pitch;
					iSystemStatus = iSystemStatus & ~8;
					DebugLog(DEBUG_Vehicle, "Pitch servo down: " $ iSystemStatus);
				}
			}
			else
			{
				if (Damage <= iYawServoHealth)
				{
					iYawServoHealth -= Damage;
				}
				else
				{
					iYawServoHealth = 0;
				}
				DebugLog(DEBUG_Vehicle, "CROWS yaw servo health: " $ iYawServoHealth);
				if (iYawServoHealth == 0)
				{
					rotRotationAtServoFailure.Yaw = PlayerController(Pawn(Owner).Controller).GetViewRotation().Yaw;
					iSystemStatus = iSystemStatus & ~16;
					DebugLog(DEBUG_Vehicle, "Yaw servo down: " $ iSystemStatus);
				}
			}
			GOTO JL0595;
		default:
		JL0595:
}
*/