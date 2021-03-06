// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/CROWS_Base/CROWS_Base.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseTracer/BaseTracer.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_MK19Gren/Proj_MK19Gren.h"

ACROWS_Base::ACROWS_Base()
{
	BodyPanels.SetNum(4);
	BulletCasingRing.SetNum(4);
	Ammo = 200;
	Ammo = 200;
	ChargeTimerName = "ChargeTimer";
	ChargeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_crows_charge_armed_Cue.s_arm_m2_crows_charge_armed_Cue'"), NULL, LOAD_None, NULL);
	ChargeTime = 3;
	CameraPitchBone = "B_Camera";
	MinSustain = 0.3;
	ServoAtkLR = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_servo_lr_attack_Cue.s_arm_m2_servo_lr_attack_Cue'"), NULL, LOAD_None, NULL);
	ServoRelLR = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_servo_lr_release_Cue.s_arm_m2_servo_lr_release_Cue'"), NULL, LOAD_None, NULL);
	ServoSusLR = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_servo_lr_sustain_Cue.s_arm_m2_servo_lr_sustain_Cue'"), NULL, LOAD_None, NULL);
	ServoVolumeLR = 0.05;
	ServoDamagedSus = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_crows_motor_damaged_Cue.s_arm_m2_crows_motor_damaged_Cue'"), NULL, LOAD_None, NULL);
	DryFireSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_crows_dry_fire_Cue.s_arm_m2_crows_dry_fire_Cue'"), NULL, LOAD_None, NULL);
	CameraFailureSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_crows_optics_damaged_Cue.s_arm_m2_crows_optics_damaged_Cue'"), NULL, LOAD_None, NULL);
	GunFailureSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_crows_weapon_damaged_Cue.s_arm_m2_crows_weapon_damaged_Cue'"), NULL, LOAD_None, NULL);
	ServoAtkUD = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_servo_ud_attack_Cue.s_arm_m2_servo_ud_attack_Cue'"), NULL, LOAD_None, NULL);
	ServoRelUD = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_servo_ud_release_Cue.s_arm_m2_servo_ud_release_Cue'"), NULL, LOAD_None, NULL);
	ServoSusUD = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_servo_ud_sustain_Cue.s_arm_m2_servo_ud_sustain_Cue'"), NULL, LOAD_None, NULL);
	ServoVolumeUD = 0.05;
	ServoSoundRadius = 128;
	asBodyPanelClasses = {
		"AGP.CROWS_Main_BodyPanel",
		"AGP.CROWS_Camera_BodyPanel",
		"AGP.CROWS_WeaponMount_BodyPanel",
		"AGP.CROWS_M2_BodyPanel"
	};
	StartBodyPanelMeshes = {
		LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Weapons/weapons_3p/m_weap_weapons3p_CROWS_main.m_weap_weapons3p_CROWS_main'"), NULL, LOAD_None, NULL),
		LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Weapons/weapons_3p/m_weap_weapons3p_CROWS_camera.m_weap_weapons3p_CROWS_camera'"), NULL, LOAD_None, NULL),
		LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Weapons/weapons_3p/m_weap_weapons3p_CROWS_weaponmount.m_weap_weapons3p_CROWS_weaponmount'"), NULL, LOAD_None, NULL),
		LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Weapons/weapons_3p/m_weap_weapons3p_CROWS_m2.m_weap_weapons3p_CROWS_m2'"), NULL, LOAD_None, NULL)
	};
	StartBodyPanelBones = {
		"B_Base",
		"B_Camera",
		"B_Weapon",
		"B_Weapon"
	};
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
	DamageThreshholds = {
		100,
		200,
		400
	};
	DamagedTexture = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Skins/weapons/t_skin_weapons_crows_mount_1a_Mat.t_skin_weapons_crows_mount_1a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Skins/weapons/t_skin_weapons_crows_mount_1b_Mat.t_skin_weapons_crows_mount_1b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Skins/weapons/t_skin_weapons_crows_mount_1c_Mat.t_skin_weapons_crows_mount_1c_Mat'"), NULL, LOAD_None, NULL)
	};
	YawBone = "B_Base";
	PitchBone = "B_Weapon";
	PitchUpLimit = 6760;
	PitchDownLimit = -4500;
	WeaponFireAttachmentBone = "B_Muzzle";
	WeaponFireOffset = 76;
	RotationsPerSecond = 20;
	bDoOffsetTrace = true;
	bCorrectAim = false;
	//TracerClass = ABaseTracer::StaticClass();
	FireSoundClass = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/M2/s_arm_m2_single_fire_Cue.s_arm_m2_single_fire_Cue'"), NULL, LOAD_None, NULL);
	FireSoundVolume = 512;
	FireSoundRadius = 256;
	//ProjectileClass = AProj_MK19Gren::StaticClass();
	ShakeRotMag = FVector(0, 0, 200);
	ShakeRotRate = FVector(0, 0, 500);
	ShakeRotTime = 1.25;
	ShakeOffsetMag = FVector(0, 0, 1);
	ShakeOffsetRate = FVector(0, 0, 200);
	ShakeOffsetTime = 1.25;
	WeaponAimAnims = {
		"vehhmvcrwsidle",
		"vehhmvcrwsidle"
	};
	numWeaponAimAnims = 1;
	//ZeroSizeSize;
	//Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AAO_Vehicles/CROWS.CROWS'"), NULL, LOAD_None, NULL);
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bUseCylinderCollision = true;
}

static const float RadianToURot = 10430.3783505;
static const int32 CROWS_SYSSTATUS_CAMERA = 1;
static const int32 CROWS_SYSSTATUS_CAMERALENS = 2;
static const int32 CROWS_SYSSTATUS_LASER = 4;
static const int32 CROWS_SYSSTATUS_PITCHSERVO = 8;
static const int32 CROWS_SYSSTATUS_YAWSERVO = 0x10;
static const int32 CROWS_SYSSTATUS_M2WEAPON = 0x20;
static const int32 CROWS_SYSSTATUS_MK19WEAPON = 0x40;

/*
State ProjectileFireMode
{
	Function Fire(AController* C)
	{
		if ((iSystemStatus & 32) != 32)
		{
			if (GunFailureClicks == 0)
			{
				WeaponFailureSounds();
			}
			else
			{
				PlayOwnedSound(DryFireSound,0,(FireSoundVolume / 255),,FireSoundRadius,,false);
			}
			return;
		}
		if ((Ammo > 0) && bCharged)
		{
			SpawnProjectile(ProjectileClass,false);
			Ammo --;
		}
		else
		{
			PlayOwnedSound(DryFireSound,0,(FireSoundVolume / 255),,FireSoundRadius,,false);
		}
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,23,Instigator,"InstantFireMode");
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
		SetCustomTimer(GetSoundDuration(DryFireSound), false, 'WeaponFailureSounds');
	}
	else
	{
		PlaySound(GunFailureSound, 0, FireSoundVolume / 255, , FireSoundRadius);
	}
	*/
}

AProjectile* ACROWS_Base::SpawnProjectile(AProjectile* ProjClass, bool bAltFire)
{
	AProjectile* p = nullptr;
	//DebugLog(DEBUG_Vehicle, "Spawning Projectile" + FString::FromInt(ProjClass));
	CalcWeaponFire();
	//p = Spawn(ProjClass, , , WeaponFireLocation, WeaponFireRotation, true);
	//DebugLog(DEBUG_Vehicle, "Spawned P:" + FString::FromInt(p));
	if (p != nullptr)
	{
		FlashMuzzleFlash();
		if (bAmbientFireSound)
		{
			//AmbientSound = FireSoundClass;
		}
		else
		{
			//PlayOwnedSound(FireSoundClass, 0, (FireSoundVolume / 255), , FireSoundRadius, , false);
		}
		if (!bCasingQueued)
		{
			//SetCustomTimer((CasingSoundMinDelay + (FRand() * CasingDelayDeviation)), false, "PlayCasingRing");
			bCasingQueued = true;
		}
		if (HissCount == 0)
		{
			//SetCustomTimer(HissDecrementDelay, false, "DecrementHiss");
		}
		(HissCount += 1);
		if (HissCount >= HissTriggerCount)
		{
			//StopCustomTimer("PlayHiss");
			//SetCustomTimer((FireInterval + 0.05), false, "PlayHiss");
		}
	}
	return p;
}

void ACROWS_Base::DecrementHiss()
{
	HissCount -= 3;
	if (HissCount < 0)
	{
		HissCount = 0;
	}
	if (HissCount != 0)
	{
		//SetCustomTimer(HissDecrementDelay, false, 'DecrementHiss');
	}
}

void ACROWS_Base::PlayHiss()
{
	float fSoundDuration = 0;
	/*
	PlayOwnedSound(BarrelHiss, 0, FireSoundVolume / 512, , FireSoundRadius, , false);
	fSoundDuration = GetSoundDuration(BarrelHiss);
	StopCustomTimer('FinishHiss');
	SetCustomTimer(fSoundDuration * 3 / 4, false, 'FinishHiss');
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
		return;
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
		return;
	}
	ShakeView();
	*/
}

void ACROWS_Base::ChargeWeapon()
{
	/*
	if (iSystemStatus & 32 == 0)
	{
		return;
	}
	SetCustomTimer(ChargeTime, false, 'ChargeTimer');
	if (iSystemStatus & 32 != 32)
	{
		PlaySound(GunFailureSound, 0, FireSoundVolume / 255, , FireSoundRadius);
	}
	else
	{
		PlaySound(ChargeSound, , 1, , 10000);
	}
	bCharged = false;
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
	FRotator TempRot = FRotator(0,0,0);
	int32 Inc = 0;
	int32 i = 0;
	/*
	if (Instigator == nullptr)
	{
		Tick(DeltaTime);
		return;
	}
	if (DamageIndex != LastDamageIndex)
	{
		for (i = 0; i <= 3; i++)
		{
			BodyPanels[i].SwapTexture(DamagedTexture[DamageIndex]);
		}
		LastDamageIndex = DamageIndex;
	}
	if (Instigator.Controller != nullptr && Instigator.Controller.bFire == 0)
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
	//PlaySound(BulletCasingRing[Rand(3)], 0, FireSoundVolume / 255, , FireSoundRadius, , false);
	//bCasingQueued = false;
}

void ACROWS_Base::PostNetBeginPlay()
{
	Super::PostNetBeginPlay();
	/*
	SetBoneRotation(WeaponFireAttachmentBone, FRotator(0 16384 0), 0, 1);
	if (GetNetMode() != ENetMode::NM_Client)
	{
		AttachBodyPanels();
	}
	*/
}

void ACROWS_Base::PostBeginPlay()
{
	Super::PostBeginPlay();
	/*
	BulletVelocity = ProjectileClass.Default.Speed;
	DebugLog(DEBUG_Vehicle, "CROWS_Base::PostBeginPlay");
	iSystemStatus = 255;
	*/
}

void ACROWS_Base::Destroyed()
{
	int32 i = 0;
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
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
	int32 i = 0;
	/*
	DebugLog(DEBUG_Vehicle, this + ".AttachBodyPanels() entered ");
	for (i = 0; i < asBodyPanelClasses.Num(); i++)
	{
		BodyPanels[i] = Spawn(ABodyPanel::StaticClass(), this);
		BodyPanels[i].PanelID = i;
		BodyPanels[i].SetStaticMesh(StartBodyPanelMeshes[i]);
		BodyPanels[i].RemoteRole = 1;
		BodyPanels[i].SetCollision(false, false, false);
		BodyPanels[i].bUseCollisionStaticMesh = false;
		BodyPanels[i].bAcceptsProjectors = false;
		BodyPanels[i].bBlockZeroExtentTraces = false;
		BodyPanels[i].bBlockNonZeroExtentTraces = false;
		AttachToBone(BodyPanels[i], StartBodyPanelBones[i]);
		BodyPanels[i].SetBase(this);
		BodyPanels[i].RelRotation = FRotator(16384 0 32768);
		BodyPanels[i].SetRelativeRotation(BodyPanels[i].RelRotation);
		DebugLog(DEBUG_Vehicle, this + ".AttachBodyPanels() - Attaching: " + BodyPanels[i] + " To Bone " + StartBodyPanelBones[i] + " in " + BodyPanels[i]);
	}
	*/
}

bool ACROWS_Base::IsPitchServoFunctional()
{
	/*
	if (iSystemStatus & 8 == 8)
	{
		return true;
	}
	*/
	return false;
}

bool ACROWS_Base::IsYawServoFunctional()
{
	/*
	if (iSystemStatus & 16 == 16)
	{
		return true;
	}
	*/
	return false;
}

float ACROWS_Base::GetFailedServoPitch()
{
	return float(rotRotationAtServoFailure.Pitch);
}

float ACROWS_Base::GetFailedServoYaw()
{
	return float(rotRotationAtServoFailure.Yaw);
}

void ACROWS_Base::TakeProjectileImpactDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector aMomentum, UaDamageType* InDamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	/*
	DebugLog(DEBUG_Vehicle, this + ".TakeProjectileImpactDamage() entered with damage: " + Damage + " on bone " + Bone.Name);
	TakeProjectileImpactDamage(Damage, instigatedBy, HitLocation, aMomentum, InDamageType, Bone, KillerController, ResponsibleActor, HitMaterial);
	*/
}
/*
void ACROWS_Base::TakeDamage(int32 Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	int32 idx;
	DebugLog(DEBUG_Vehicle, "CROWS weapon system taking damage at location " + HitLocation + " Bone: " + Bone.Name + " Damage: " + Damage);
	if (Damage == 0)
	{
		Damage = 30;
	}
	iTotalDamage += Damage;
	if (idx < DamageThreshholds.Num())
	{
		if (iTotalDamage <= DamageThreshholds[idx])
		{
		}
		idx++;
	}
	if (idx >= DamageThreshholds.Num())
	{
		idx = DamageThreshholds.Num() - 1;
	}
	DamageIndex = idx;
	if (Bone.Name ~= "B_CAMERALENS")
	{
		if (FMath::FRand() > 0.5)
		{
			Bone.Name = "B_LASER";
		}
	}
	switch(Bone.Name)
	{
			case "B_CAMERA":
				if (Damage <= iCameraHealth)
				{
					iCameraHealth -= Damage;
					break;
				}
				iCameraHealth = 0;
	}
	DebugLog(DEBUG_Vehicle, "CROWS camera health: " + iCameraHealth);
	if (iCameraHealth == 0)
	{
		iSystemStatus = iSystemStatus & ~1 | 2 | 4;
		DebugLog(DEBUG_Vehicle, "Camera disabled: " + iSystemStatus);
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
			DebugLog(DEBUG_Vehicle, "CROWS camera lens health: " + iCameraLensHealth);
			if (iCameraLensHealth == 0)
			{
				PlaySound(CameraFailureSound, , 1, , 10000);
				iSystemStatus = iSystemStatus & ~2;
				DebugLog(DEBUG_Vehicle, "Camera lens disabled: " + iSystemStatus);
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
			DebugLog(DEBUG_Vehicle, "CROWS laser health: " + iLaserHealth);
			if (iLaserHealth == 0)
			{
				iSystemStatus = iSystemStatus & ~4;
				DebugLog(DEBUG_Vehicle, "Laser disabled: " + iSystemStatus);
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
				DebugLog(DEBUG_Vehicle, "CROWS weapon health: " + iWeaponHealth);
				if (iWeaponHealth == 0)
				{
					iSystemStatus = iSystemStatus & ~32;
					DebugLog(DEBUG_Vehicle, "M2 disabled: " + iSystemStatus);
				}
			}
			GOTO JL0595;
		case "CROWS_ROOT":
		case "B_WEAPON":
		case "B_BASE":
			if (FMath::FRand() > 0.5)
			{
				if (Damage <= iPitchServoHealth)
				{
					iPitchServoHealth -= Damage;
				}
				else
				{
					iPitchServoHealth = 0;
				}
				DebugLog(DEBUG_Vehicle, "CROWS pitch servo health: " + iPitchServoHealth);
				if (iPitchServoHealth == 0)
				{
					rotRotationAtServoFailure.Pitch = Cast<APlayerController>(Cast<APawn>(GetOwner())->Controller).GetViewRotation().Pitch;
					iSystemStatus = iSystemStatus & ~8;
					DebugLog(DEBUG_Vehicle, "Pitch servo down: " + iSystemStatus);
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
				DebugLog(DEBUG_Vehicle, "CROWS yaw servo health: " + iYawServoHealth);
				if (iYawServoHealth == 0)
				{
					rotRotationAtServoFailure.Yaw = Cast<APlayerController>(Cast<APawn>(GetOwner())->Controller).GetViewRotation().Yaw;
					iSystemStatus = iSystemStatus & ~16;
					DebugLog(DEBUG_Vehicle, "Yaw servo down: " + iSystemStatus);
				}
			}
			GOTO JL0595;
		default:
		JL0595:
}
*/
