// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_Javelin/PickupW_Javelin.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_Javelin/ScopeW_Javelin.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_Javelin/AttachW_Javelin.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/BackBlastDamage/BackBlastDamage.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_Javelin.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Javelin/Ammo_Javelin.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_CLUpack/Attch_CLUpack.h"
#include "AA29/Object/Actor/Jav_Target/Jav_Target.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/BaseAmmoRound/BaseAmmoRound.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassJavelin/ClassJavelin.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
AWEAPON_Javelin::AWEAPON_Javelin()
{
	bTargetIsVisible					= true;
	ReloadTubeEmpty						= "UnloadEmpty";
	MinRangeDirect						= 3000;
	MinRangeTop							= 7500;
	acc_check							= 0.5;
	LockOn_Time							= 2;
	MisFireChance						= 0.01;
	NV_Sound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Thermal_On.S_Armo_Javelin_CLU_Thermal_On"), NULL, LOAD_None, NULL);
	ChangeViewMode						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/s_armo_Javelin_Thermal_Zoom.s_armo_Javelin_Thermal_Zoom"), NULL, LOAD_None, NULL);
	SeekOn								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Seeker_On.S_Armo_Javelin_CLU_Seeker_On"), NULL, LOAD_None, NULL);
	SeekOff								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Seeker_Off.S_Armo_Javelin_CLU_Seeker_Off"), NULL, LOAD_None, NULL);
	LockTone							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Aquire_Lock.S_Armo_Javelin_CLU_Aquire_Lock"), NULL, LOAD_None, NULL);
	LockedOnSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Locked_On.S_Armo_Javelin_CLU_Locked_On"), NULL, LOAD_None, NULL);
	MissileBitError						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Missile_Error.S_Armo_Javelin_CLU_Missile_Error"), NULL, LOAD_None, NULL);
	UnloadFull							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Unload.S_Armo_Javelin_CLU_Unload"), NULL, LOAD_None, NULL);
	UnloadEmpty							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Unload_Spent.S_Armo_Javelin_CLU_Unload_Spent"), NULL, LOAD_None, NULL);
	LockFail							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Unsucessfull_Lock.S_Armo_Javelin_CLU_Unsucessfull_Lock"), NULL, LOAD_None, NULL);
	ZoomSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Thermal_On.S_Armo_Javelin_CLU_Thermal_On"), NULL, LOAD_None, NULL);
	UnZoomSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Power_On.S_Armo_Javelin_CLU_Power_On"), NULL, LOAD_None, NULL);
	CLU_Fan								= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Ambient.S_Armo_Javelin_CLU_Ambient"), NULL, LOAD_None, NULL);
	DirectAttackSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/s_Armo_Javelin_CLU_Direct_Fire.s_Armo_Javelin_CLU_Direct_Fire"), NULL, LOAD_None, NULL);
	TopAttackSound						= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/s_Armo_Javelin_CLU_Top_Fire.s_Armo_Javelin_CLU_Top_Fire"), NULL, LOAD_None, NULL);
	bUseNV								= true;
	_RecoilDirInfo.MeanDirection		= FVector(0, 0, 0);
	_RecoilDirInfo.bPitch				= 1;
	_RecoilDirInfo.PitchMean			= 0;
	_RecoilDirInfo.PitchMaxDeviation	= 8;
	_RecoilDirInfo.PitchFalloff			= 1;
	_RecoilDirInfo.bYaw					= 1;
	_RecoilDirInfo.YawMean				= 0;
	_RecoilDirInfo.YawMaxDeviation		= 5;
	_RecoilDirInfo.YawFalloff			= 0.75;
	_RecoilDirInfo.bRoll				= 0;
	_RecoilDirInfo.RollMean				= 0;
	_RecoilDirInfo.RollMaxDeviation		= 0;
	_RecoilDirInfo.RollFalloff			= 0;
	_RecoilDirInfo.SpeedMean			= 0;
	_RecoilDirInfo.SpeedMaxDeviation	= 0;
	_RecoilDirInfo.SpeedFalloff			= 0;
	_RecoilDirInfo.Base					= FRotator(0, 0, 0);
	SingleFire							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Missile_Fire.S_Armo_Javelin_Missile_Fire"), NULL, LOAD_None, NULL);
	OutdoorSingleFire					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Missile_Fire.S_Armo_Javelin_Missile_Fire"), NULL, LOAD_None, NULL);
	ReloadSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Reload.S_Armo_Javelin_CLU_Reload"), NULL, LOAD_None, NULL);
	NV_Sound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Fix_Jam.S_Armo_Javelin_CLU_Fix_Jam"), NULL, LOAD_None, NULL);
	SelectChargeSound					= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Select.S_Armo_Javelin_CLU_Select"), NULL, LOAD_None, NULL);
	FireAnims							= { "Fire" , "Fire" , "Fire" };
	ReloadFullAnim						= "Unload";
	_cScopeClass						= AScopeW_Javelin::StaticClass();
	OwnerDamageType						= UProjectileDamageLargeArms::StaticClass();
	RadiusDamageType					= UBackBlastDamage::StaticClass();
	AmmoRoundClass						= AAmmoRound_Javelin::StaticClass();
	SingleFiringRate					= 0.68;
	CurrentElevation					= 3277;
	AmmoName							= AAmmo_Javelin::StaticClass();
	BackBlastRadius						= 650;
	BackBlastCone						= 0.85;
	BackBlastDamage						= 125;
	BackFireOffset						= FVector(-27, 0, 0);
	bHasBackBlast						= true;
	SelectSound							= LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_CLU_Select.S_Armo_Javelin_CLU_Select"), NULL, LOAD_None, NULL);
	DisplayFOV							= 58;
	_ZoomDirInfo.MeanDirection			= FVector(0, 0, 0);
	_ZoomDirInfo.bPitch					= 1;
	_ZoomDirInfo.PitchMean				= 0;
	_ZoomDirInfo.PitchMaxDeviation		= 1.5;
	_ZoomDirInfo.PitchFalloff			= 0.75;
	_ZoomDirInfo.bYaw					= 1;
	_ZoomDirInfo.YawMean				= 0;
	_ZoomDirInfo.YawMaxDeviation		= 3;
	_ZoomDirInfo.YawFalloff				= 0.75;
	_ZoomDirInfo.bRoll					= 0;
	_ZoomDirInfo.RollMean				= 0;
	_ZoomDirInfo.RollMaxDeviation		= 0;
	_ZoomDirInfo.RollFalloff			= 0;
	_ZoomDirInfo.SpeedMean				= 0;
	_ZoomDirInfo.SpeedMaxDeviation		= 0;
	_ZoomDirInfo.SpeedFalloff			= 0;
	_ZoomDirInfo.Base					= FRotator(0, 0, 0);
	WallTraceDist						= 45;
	weaponType							= EWeaponType::WEAPON_Javelin;
	bMisFire							= false;
	PickupClass							= APickupW_Javelin::StaticClass();
	fWeight								= 6.8;
	PlayerViewOffset					= FVector(0, 0, 0);
	AttachmentClass						= { AAttachW_Javelin::StaticClass() };
	IconMaterial						= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/jav_icon_Mat.jav_icon_Mat'"), NULL, LOAD_None, NULL);
	ItemName							= "Javelin";
	Mesh								= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AAO_Armory/1stPrsnCLU.1stPrsnCLU"), NULL, LOAD_None, NULL);
	//bFullVolume = true;
	//SoundVolume = 64;
	//SoundRadius = 1;
}

/*
simulated State BusyZooming
{
	simulated Function UnZoom()
	{
		Global.bTubeAttached();
		JavelinPlaySound(UnZoomSound);
	}
	simulated Function bool CanSprint()
	{
		return Global.ARClass();
	}
Begin:
	if (bZoomDir)
	{
		bInZoom=true;
		Instigator.WeaponAdjust3p(Instigator.70);
		RunAnimation("Zoom",1);
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			Sleep(AnimTimerDuration);
			AnimEnd(0);
		}
		else
		{
			FinishAnim();
		}
		Zoom();
		SetPreviousViewMode();
		AmbientSound=CLU_Fan;
	}
	else
	{
		UnZoom();
		Instigator.WeaponAdjust3p(Instigator.71);
		RunAnimation("UnZoom",1);
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			Sleep(AnimTimerDuration);
			AnimEnd(0);
		}
		else
		{
			FinishAnim();
		}
		bInZoom=false;
		CancelLock();
	}
	GotoState("Idle");
}
*/

/*
simulated State LockedOn extends Idle
{
	simulated Function NV()
	{
	}
	simulated Function AltFire(float Value)
	{
	}
	simulated Function FireMode()
	{
	}
	simulated Function UnZoom()
	{
		Global.bTubeAttached();
		JavelinPlaySound(UnZoomSound);
	}
	simulated Function Tick(float DeltaTime)
	{
		FVector TraceStart = FVector(0,0,0);
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		Super::Tick(DeltaTime);
		if (bLockedOn)
		{
			if (GetZoomMultiplier() == 4)
			{
				if (Acos(( Vector(Instigator.GetViewRotation()) Dot  Vector(rotator((J_Target.Location - Instigator.Location))))) > 0.055)
				{
					CancelLock(true);
				}
			}
			else
			{
				if (Acos(( Vector(Instigator.GetViewRotation()) Dot  Vector(rotator((J_Target.Location - Instigator.Location))))) > 0.025)
				{
					CancelLock(true);
				}
			}
			if ((! Level.IsServer()) && (! Instigator.PressingAltFire()))
			{
				CancelLock(true);
				return;
			}
			GetAxes(Instigator.GetViewRotation(),X,Y,Z);
			TraceStart.X=Instigator.Location.X;
			TraceStart.Y=Instigator.Location.Y;
			TraceStart.Z=(Instigator.Location.Z + Instigator.BaseEyeHeight);
			(TraceStart += (Instigator.CollisionRadius * X));
			if (! FastTrace(J_Target->GetActorLocation(),TraceStart))
			{
				if (bTargetIsVisible)
				{
					SetTimer(2,false);
					bTargetIsVisible=false;
				}
			}
			else
			{
				bTargetIsVisible=true;
				SetTimer(0,false);
			}
		}
	}
	simulated Function Timer()
	{
		CancelLock(true);
	}
	simulated Function EndState()
	{
		JavelinStopSound(LockedOnSound);
		Super::EndState();
	}
Begin:
	if (Level.IsServer())
	{
		ClientGotoState("LockedOn","None");
	}
	JavelinPlaySound(LockedOnSound);
}
*/

/*
simulated State Targeting extends Idle
{
	simulated Function NV()
	{
	}
	simulated Function FireMode()
	{
	}
	simulated Function AltFire(float Value)
	{
	}
	simulated Function ToggleZoom()
	{
		JavelinStopSound(LockTone);
		Global.AttachW_Javelin_Tube();
	}
	simulated Function UnZoom()
	{
		JavelinStopSound(LockTone);
		JavelinPlaySound(UnZoomSound);
		Global.bTubeAttached();
	}
	simulated Function EndState()
	{
		JavelinStopSound(LockTone);
		Super::EndState();
	}
	simulated Function Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);
		if ((! Instigator.PressingAltFire()) && (! Level.IsServer()))
		{
			CancelLock(true);
			JavelinStopSound(LockTone);
			if (GetNetMode() != ENetMode::NM_Client)
			{
				SetTimer(0,false);
			}
			return;
		}
		(total_count += DeltaTime);
		if (GetNetMode() != ENetMode::NM_Client)
		{
			if ((total_count - old_total_count) > 0.1)
			{
				if (CheckTarget())
				{
					(accuracy_count += (total_count - old_total_count));
				}
				old_total_count=total_count;
			}
		}
	}
	simulated Function bool CheckLastTarget()
	{
		AActor* NewTarget = nullptr;
		NewTarget=JavTrace();
		if ((GetNetMode() != ENetMode::NM_Client) && (HomingTarget == nullptr))
		{
			SetHomingTarget(NewTarget);
		}
		if ((! bDirectFire) && IsInState("TooClose"))
		{
			return false;
		}
		if (NewTarget == HomingTarget)
		{
			return true;
		}
		return false;
	}
	simulated Function Timer()
	{
		if (((HomingTarget == nullptr) || (! IsZoomed())) || ((accuracy_count / total_count) < acc_check))
		{
			JavelinPlaySound(LockFail);
			GotoState("Idle");
			if (Level.IsServer())
			{
				ClientGotoState("Idle","None");
			}
			return;
		}
		if (CheckLastTarget())
		{
			Toggle_bLockedOn();
			Spawn_J_Target();
			SetScopeVar();
			GotoState("LockedOn");
		}
		else
		{
			JavelinPlaySound(LockFail);
			GotoState("Idle");
			if (Level.IsServer())
			{
				ClientGotoState("Idle","None");
			}
		}
	}
Begin:
	total_count=0;
	accuracy_count=0;
	old_total_count=0;
	JavelinPlaySound(LockTone);
	if (Level.IsServer())
	{
		ClientGotoState("Targeting","Begin");
	}
	if (GetNetMode() != ENetMode::NM_Client)
	{
		if (total_count < LockOn_Time)
		{
			SetTimer((LockOn_Time - total_count),false);
		}
		else
		{
			Timer();
		}
	}
}
*/

/*
simulated State TooClose extends Targeting
{
Begin:
	total_count=0;
	accuracy_count=0;
	old_total_count=0;
	JavelinPlaySound(LockTone);
	if (Level.IsServer())
	{
		ClientGotoState("TooClose","Begin");
	}
	if (GetNetMode() != ENetMode::NM_Client)
	{
		if (total_count < LockOn_Time)
		{
			SetTimer((LockOn_Time - total_count),false);
		}
		else
		{
			Timer();
		}
	}
}
*/

/*
simulated State BusyLoweringWeapon
{
	simulated Function UnZoom()
	{
		Global.bTubeAttached();
		JavelinPlaySound(UnZoomSound);
	}
	simulated Function bool TweenDownImmediately()
	{
		return false;
	}
Begin:
	if (IsZoomed())
	{
		UnZoom();
		RunAnimation("UnZoom",1);
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			Sleep(AnimTimerDuration);
		}
		else
		{
			FinishAnim();
		}
		bInZoom=false;
	}
	TweenDown();
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
		AnimEnd(0);
	}
	else
	{
		FinishAnim();
	}
}
*/

/*
simulated State BusyReloading
{
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function BeginState()
	{
	}
	simulated Function UnZoom()
	{
		Global.bTubeAttached();
		JavelinPlaySound(UnZoomSound);
	}
	simulated Function EndState()
	{
		if (IsJammed())
		{
			DoFixJam();
		}
		Super::EndState();
		bCanMisFire=true;
		if (bWasZoomed)
		{
			bWasZoomed=false;
			Cast<AAGP_Pawn>(Instigator).SkipWeaponAdjustment(Instigator.71);
		}
		if (GetNetMode() != ENetMode::NM_Client)
		{
			if (CurrentJRA == 0)
			{
				if (Cast<ABaseWeaponAttachment>(ThirdPersonActor).AmmoRound3P == nullptr)
				{
					BaseWeaponAttachment(ThirdPersonActor).SpawnAndAttachAR3P();
				}
			}
			else
			{
				if (Cast<ABaseWeaponAttachment>(ThirdPersonActor).AmmoRound3P != nullptr)
				{
					BaseWeaponAttachment(ThirdPersonActor).DestroyAR3P();
				}
			}
			if (CurrentJRA != 0)
			{
				ClientAdjustAmmoRound(true);
			}
		}
		if (Cast<AHumanController>(Instigator.Controller).SwapType != 0)
		{
			SwapWeapons();
		}
	}
Begin:
	if (IsZoomed())
	{
		UnZoom();
		RunAnimation("ZoomOut",1,0.05);
		Sleep((AnimTimerDuration + 0.25));
		bInZoom=false;
		bWasZoomed=true;
	}
	if (Instigator != nullptr)
	{
		CurrentJRA=Instigator.JavelinReloadAnimation;
	}
	if ((GetNetMode() != ENetMode::NM_Client) && (CurrentJRA == 0))
	{
		ClientAdjustAmmoRound(false);
	}
	fpTimeReloadNextAllowed=(GetWorld()->GetTimeSeconds() + 2);
	PlayReloading();
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep((AnimTimerDuration + 0.25));
	}
	else
	{
		FinishAnim();
	}
	AnimEnd(0);
}
*/

/*
simulated State BusyFixingJam
{
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function BeginState()
	{
	}
	simulated Function UnZoom()
	{
		Global.bTubeAttached();
		JavelinPlaySound(UnZoomSound);
	}
	simulated Function EndState()
	{
		DoFixJam();
		Super::EndState();
	}
Begin:
	if (IsZoomed())
	{
		Instigator.WeaponAdjust3p(Instigator.71);
		UnZoom();
		RunAnimation("ZoomOut",1,0.05);
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			Sleep(AnimTimerDuration);
		}
		else
		{
			FinishAnim();
		}
		bInZoom=false;
	}
	PlayFixJam();
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
	}
	else
	{
		FinishAnim();
	}
	AnimEnd(0);
}
*/

/*
simulated State Jammed
{
	simulated Function Fire(float Value)
	{
	}
	simulated Function UnZoom()
	{
		Global.bTubeAttached();
		JavelinPlaySound(UnZoomSound);
	}
	simulated Function AltFire(float Value)
	{
		JavelinPlaySound(MissileBitError);
	}
Begin:
	JavelinPlaySound(MissileBitError);
}
*/

/*
simulated State BusyRaisingWeapon
{
	simulated Function BeginState()
	{
		if (Instigator != nullptr)
		{
			Instigator.ResetLean();
		}
		Super::BeginState();
	}
}
*/

void AWEAPON_Javelin::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	DisplayDebug(Canvas,YL,YPos);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	Canvas.SetDrawColor(0,255,0);
	Canvas.DrawText("Javelin Tube Attached: " + bTubeAttached + "    Attaching: " + bAttachingTube + "   Wants to swap: " + bWantsToSwap);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	*/
}

void AWEAPON_Javelin::SpawnTubePickup()
{
	AWeapon* W = nullptr;
	/*
	if (bTubeAttached)
	{
		if (AmmoType.AmmoAmount > 0)
		{
			W=Spawn('Javelin_Tube');
			W.Velocity=Velocity;
			W.DropFrom(Instigator.Location +  Vector(FRotator(0 16384 0) + Instigator.Controller.Rotation) * 30);
			AmmoType.AmmoAmount=0;
			RecountAmmo();
		}
		else
		{
			W=Spawn('Javelin_Empty_Tube');
			W.Velocity=Velocity;
			W.DropFrom(Instigator.Location +  Vector(FRotator(0 16384 0) + Instigator.Controller.Rotation) * 30);
		}
	}
	*/
}

APickup* AWEAPON_Javelin::DropFrom(FVector StartLocation, bool bAttach)
{
	APickup* p = nullptr;
	/*
	if (Instigator != nullptr)
	{
		Instigator.bCanProne=true;
		Cast<AAGP_Pawn>(Instigator).bHasCLU=false;
		Cast<AAGP_Pawn>(Instigator).bAllowSwap=false;
		Instigator.ChangeJavelinReloadAnimation(0);
		if (CLUpack != nullptr)
		{
			CLUpack.RemoveCLUPack();
		}
		ClientSetUpCLUPack(false);
	}
	SpawnTubePickup();
	p=DropFrom(StartLocation,bAttach);
	if (AmmoMagCount > 0)
	{
		SetClipCount(GetBestClip(),0);
		RecountAmmo();
	}
	*/
	return p;
}

bool AWEAPON_Javelin::CheckForNoReload()
{
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		//if (! Cast<AHumanController>(Instigator.Controller).QualifiedFor(AClassJavelin::StaticClass()))
		//{
		//	return true;
		//}
	}
	//if (! Instigator.IsBusy() && ! Instigator.bIsProne && bTubeAttached || HasAmmo())
	//{
	//	return false;
	//}
	//else
	//{
	//	return true;
	//}
	return false;  //FAKE   /ELiZ
}
void AWEAPON_Javelin::PlayReloading()
{
	/*
		if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
		}
		switch(Instigator.JavelinReloadAnimation)
		{
			case 0:
			RunAnimation(ReloadEmptyAnim,1);
			if (! bUseAnimNotifySounds)
			{
				PlayWeaponSound(ReloadSound,ReloadSound);
			}
			break;
			case 1:
			RunAnimation(ReloadFullAnim,1);
			if (! bUseAnimNotifySounds)
			{
				PlayWeaponSound(UnloadFull,UnloadFull);
			}
			break;
			case 2:
			RunAnimation(ReloadTubeEmpty,1);
			if (! bUseAnimNotifySounds)
			{
				PlayWeaponSound(UnloadEmpty,UnloadEmpty);
			}
			break;
			default:
			Log("Warning: JavelinReloadAnimation byte out of bounds.",'PICA');
			RunAnimation(ReloadEmptyAnim,1);
			if (! bUseAnimNotifySounds)
			{
				PlayWeaponSound(ReloadSound,ReloadSound);
			}
		}
	*/
}

bool AWEAPON_Javelin::ShouldDoDelayedEject()
{
	return false;
}

void AWEAPON_Javelin::SetbTubeAttached(bool Tube)
{
	/*
		AttachW_Javelin(ThirdPersonActor).SetbTubeAttached(Tube);
		bTubeAttached=Tube;
	*/
}
void AWEAPON_Javelin::Reload()
{
	/*
		if (Instigator != nullptr && Instigator.Controller != nullptr && Cast<AHumanController>(Instigator.Controller) != nullptr && Cast<AHumanController>(Instigator.Controller).IsInState("None"))
		{
			return;
		}
		Set_bAttachingTube();
		if (bTubeAttached)
		{
			SetbTubeAttached(false);
			Instigator.bCanProne=true;
			GotoState('BusyReloading');
		}
		else
		{
			if (! bTubeAttached && AmmoMagCount > 0)
			{
				SetbTubeAttached(true);
				Instigator.bCanProne=false;
				GotoState('BusyReloading');
			}
		}
	*/
}
void AWEAPON_Javelin::Set_bAttachingTube()
{
	//bAttachingTube=! bTubeAttached;
}
void AWEAPON_Javelin::ReloadClip(uint8 newclip)
{
	/*
		if (bAttachingTube)
		{
			Instigator.bCanProne=false;
			ReloadClip(newclip);
		}
		else
		{
			Instigator.bCanProne=true;
		}
	*/
}
void AWEAPON_Javelin::SpawnTube()
{
	AAGP_Weapon* Tube = nullptr;
	/*
	if (AmmoType.AmmoAmount > 0)
	{
		AmmoType.AmmoAmount=0;
		RecountAmmo();
		Tube=Spawn('Javelin_Tube');
		Tube.GiveTo(Instigator);
	}
	*/
}
void AWEAPON_Javelin::NPC_Fire(float Value, APawn* Enemy)
{
	/*
	SetHomingTarget(Enemy);
	if (FMath::FRand() < 0.5)
	{
		bDirectFire=true;
	}
	else
	{
		bDirectFire=false;
	}
	bSeekOn=true;
	bLockedOn=true;
	Spawn_J_Target();
	Super::NPC_Fire(Value,Enemy);
	*/
}

void AWEAPON_Javelin::NPC_ProjectileFire()
{
	FVector X = FVector(0,0,0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector SpawnLocation = FVector(0, 0, 0);;
	FVector AimVector = FVector(0, 0, 0);;
	FRotator SpawnRot = FRotator(0, 0, 0);;
	/*
	AimVector=J_Target.Location - Instigator.Location;
	SpawnLocation=GetBoneCoords('DummyJavTube').Origin;
	SpawnRot=AimVector;
	GetAxes(SpawnRot,X,Y,Z);
	X=Normal(X);
	SpawnLocation += FireOffset.X * X;
	AimVector=Normal(AimVector);
	AimVector.Z=0.3;
	_Projectile=GetCurrentAmmoType().SpawnProjectile(SpawnLocation,AimVector);
	*/
}

void AWEAPON_Javelin::ClientAdjustAmmoRound(bool bRemove)
{
	bool bFirstPerson = false;
	AHumanController* HC = nullptr;
	/*
		HC=Cast<AHumanController>(Instigator.Controller);
		if (HC != nullptr && Instigator != nullptr)
		{
			bFirstPerson=! HC.bBehindView && HC.ViewTarget == Instigator;
		}
		if (AmmoRoundList != nullptr && ! bFirstPerson)
		{
			if (bRemove)
			{
				AmmoRoundList.SetDrawType(0);
			}
			else
			{
				AmmoRoundList.SetDrawType(8);
			}
		}
	*/
}

void AWEAPON_Javelin::AdjustAmmoRound()
{
	/*
	if (AmmoRoundList != nullptr)
	{
		if (AmmoRoundList.DrawType == 8)
		{
			AmmoRoundList.SetDrawType(0);
		}
		else
		{
			AmmoRoundList.SetDrawType(8);
		}
	}
	*/
}

void AWEAPON_Javelin::StaticPrecache(ALevelInfo* L)
{
	/*
	L->AddPrecacheMaterial(Texture'fx_decal_explosion');
	L->AddPrecacheMaterial(Texture'fx_smk_ball03');
	L->AddPrecacheMaterial(Texture'fx_smk_ball04');
	L->AddPrecacheMaterial(Texture'fx_drt_cloud01');
	L->AddPrecacheMaterial(Texture'fx_part_explosion01');
	L->AddPrecacheMaterial(Texture'fx_smk_ball01');
	L.AddPrecacheStaticMesh(StaticMesh'fx_part_con_chunk1');
	L.AddPrecacheStaticMesh(StaticMesh'Tube3PSpent');
	L->AddPrecacheMaterial(Texture'missile');
	L->AddPrecacheMaterial(Texture'Backblast_jav');
	L->AddPrecacheMaterial(Texture'fx_smk_ball02');
	L.AddPrecacheStaticMesh(StaticMesh'missile');
	L.AddPrecacheStaticMesh(StaticMesh'Backblast');
	L.AddPrecacheStaticMesh(StaticMesh'Tube3PLoaded');
	StaticPrecache(L);
	*/
}

bool AWEAPON_Javelin::IsJavelin()
{
	return true;
}

void AWEAPON_Javelin::TweenDown()
{
	FName SeqName = "";
	float AnimFrame = 0;
	float AnimRate = 0;
	/*
	GetAnimParams(0,SeqName,AnimFrame,AnimRate);
	if (IsAnimating() && AnimIsInGroup(0,'Select') || AnimIsInGroup(0,'SelectNew'))
	{
		TweenAnim(SeqName,AnimFrame * 0.4);
	}
	else
	{
		if (_bActive)
		{
			if (HasAnim('Drop'))
			{
				RunAnimation('Drop',1);
			}
			else
			{
				if (Instigator != nullptr && Instigator.bIsProne)
				{
					RunAnimation('pronedown',1);
				}
				else
				{
					RunAnimation('Down',1);
				}
			}
		}
		else
		{
			PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
			if (SeqName == 'Drop' || SeqName == 'DropStill')
			{
				RunAnimation('LowDown',1);
			}
			else
			{
				if (Instigator != nullptr && Instigator.bIsProne)
				{
					RunAnimation('pronedown',1);
				}
				else
				{
					RunAnimation('Down',1);
				}
			}
		}
	}
	*/
}

void AWEAPON_Javelin::PlaySelect()
{
	int32 initradius = 0;
	/*
	if (Cast<ABaseWeaponAttachment>(ThirdPersonActor) != nullptr)
	{
		BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(this);
	}
	if (IsZoomed() && ShouldUse3dSights())
	{
		PlayIdleAnim();
	}
	else
	{
		if (! IsAnimating() || ! AnimIsInGroup(0,'Select') || ! AnimIsInGroup(0,'SelectNew'))
		{
			if (_bActive)
			{
				if (HasAnim('Raise'))
				{
					RunAnimation('Raise',1);
				}
				else
				{
					if (Instigator != nullptr && Instigator.bIsProne)
					{
						RunAnimation('proneselect',1);
					}
					else
					{
						RunAnimation('Select',1);
					}
				}
			}
			else
			{
				if (! _bCharged && HasAnim('SelectNew'))
				{
					if (Instigator != nullptr && Instigator.bIsSprinting)
					{
						Instigator.StopSprint();
					}
					_bCharged=true;
					if (Instigator != nullptr && Instigator.bIsProne)
					{
						RunAnimation('proneselect',1);
					}
					else
					{
						RunAnimation('SelectNew',1);
					}
					if (GetNetMode() == ENetMode::NM_Client)
					{
						initradius=1000000;
					}
					else
					{
						initradius=60;
					}
					PlayWeaponSound(SelectChargeSound,EnemyWeaponClass.Default.SelectChargeSound,,initradius);
				}
				else
				{
					if (Instigator != nullptr && Instigator.bIsProne)
					{
						RunAnimation('proneselect',1);
					}
					else
					{
						RunAnimation('Select',1);
					}
					PlayWeaponSound(SelectSound,EnemyWeaponClass.Default.SelectSound);
				}
			}
		}
	}
	*/
}

void AWEAPON_Javelin::JavelinPlaySound(USoundBase* SoundName)
{
	/*
	if (Instigator != nullptr && Instigator == Level.GetClientPawn())
	{
		GetSoundActor().PlaySound(SoundName,0,0.5,True,60,1,false,true);
	}
	*/
}

void AWEAPON_Javelin::JavelinStopSound(USoundBase* SoundName)
{
	/*
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		StopSound(SoundName);
	}
	*/
}
void AWEAPON_Javelin::PostBeginPlay()
{
	/*
	PostBeginPlay();
	MinRangeDirect=Max(Level.JavelinMinRangeDirect,0);
	MinRangeTop=Max(Level.JavelinMinRangeTop,0);
	*/
}

bool AWEAPON_Javelin::CanLean()
{
	return false;
}

void AWEAPON_Javelin::GiveTo(APawn* Other, APickup* Pickup)
{
	AInventory* weap = nullptr;
	/*
		GiveTo(Other,Pickup);
		weap=Cast<AAGP_Pawn>(Instigator).getAltShoulderInventory();
		if (weap == nullptr)
		{
			weap=Cast<AAGP_Pawn>(Instigator).getHandsInventory();
		}
		if (weap->IsA(AJavelin_Tube::StaticClass()))
		{
			AddClip(AmmoName);
			RecountAmmo();
		}
		MaybeSwapBinocs();
		Cast<AAGP_Pawn>(Other).bHasCLU=true;
		if (Other != nullptr)
		{
			CLUpack=Spawn('Attch_CLUpack');
			CLUpack.SetUpCLUPack(Other);
		}
		ClientSetUpCLUPack(true);
	*/
}
void AWEAPON_Javelin::MaybeSwapBinocs()
{
	/*
		if (Instigator != nullptr && Cast<AAGP_Pawn>(Instigator).Weapon != nullptr && Cast<AAGP_Pawn>(Instigator).Weapon->IsA(AItem_Binoculars::StaticClass()))
		{
			Cast<AHumanController>(Instigator.Controller).SwapType=3;
			SwapWeapons();
		}
	*/
}
void AWEAPON_Javelin::SwapWeapons()
{
	/*
		Cast<AAGP_Pawn>(Instigator).bAllowSwap=true;
		switch(Cast<AHumanController>(Instigator.Controller).SwapType)
		{
			case 1:
			Cast<AHumanController>(Instigator.Controller).SwapHands();
			break;
			case 2:
			Cast<AHumanController>(Instigator.Controller).SwapAltShoulder();
			break;
			case 3:
			Cast<AHumanController>(Instigator.Controller).SwapHip();
			break;
			case 4:
			Cast<AHumanController>(Instigator.Controller).Pistol();
			break;
			case 5:
			Cast<AHumanController>(Instigator.Controller).Grenade(1);
			break;
			case 6:
			Cast<AHumanController>(Instigator.Controller).Grenade(2);
			break;
			case 7:
			Cast<AHumanController>(Instigator.Controller).Grenade(3);
			break;
			case 8:
			Cast<AHumanController>(Instigator.Controller).Grenade(4);
			break;
			case 9:
			Cast<AHumanController>(Instigator.Controller).Grenade(5);
			break;
			case 10:
			Cast<AHumanController>(Instigator.Controller).Grenade(6);
			break;
			default:
			Cast<AAGP_Pawn>(Instigator).bAllowSwap=false;
			DebugLog(DEBUG_Warn,"Weapon_Javelin:SwapWeapons: Invalid SType:" @ Cast<AHumanController>(Instigator.Controller).SwapType);
		}
		Cast<AHumanController>(Instigator.Controller).SwapType=0;
	*/
}

AInvContainer* AWEAPON_Javelin::GetSwapContainer()
{
	return Cast<AAGP_Pawn>(GetInstigator())->getInvContainerHip();
}

void AWEAPON_Javelin::Destroyed()
{
	/*
		if (J_Target != nullptr)
		{
			J_Target.Destroy();
		}
		if (Instigator != nullptr)
		{
			Instigator.bCanProne=true;
			Cast<AAGP_Pawn>(Instigator).bAllowSwap=false;
			Cast<AAGP_Pawn>(Instigator).bHasCLU=false;
			Instigator.ChangeJavelinReloadAnimation(0);
			if (CLUpack != nullptr)
			{
				CLUpack.RemoveCLUPack();
			}
		}
		Destroyed();
	*/
}
void AWEAPON_Javelin::SpawnAndAttachScope()
{
	/*
		SpawnAndAttachScope();
		if (_Scope->IsA(AScopeW_Javelin::StaticClass()))
		{
			myscope=ScopeW_Javelin(_Scope);
		}
	*/
}
bool AWEAPON_Javelin::CanUseWeapon(int32 DesiredAction)
{
	switch(DesiredAction)
	{
		case 7:
			//return ! Instigator.IsInState('BusyReloading') && ! IsInState('BusyReloading');
		case 0:
			return ! bSafe;
		case 3:
			/*
			if (IsInState('BusyReloading'))
			{
				return false;
			}
			if (GetWorld()->GetTimeSeconds() < fpTimeReloadNextAllowed)
			{
				return false;
			}
			if (Instigator != nullptr && Instigator.Controller != nullptr && Cast<AHumanController>(Instigator.Controller) != nullptr && Cast<AHumanController>(Instigator.Controller).IsInState("None"))
			{
				return false;
			}
			*/
			return ! CheckForNoReload();
		case 6:
			//return CanZoom() && ! Instigator.IsBusy();
		case 5:
			return IsZoomed();
		case 2:
			return bTubeAttached;
		default:
			return false;
	}
}
void AWEAPON_Javelin::FixSynch()
{
	/*
		bTubeAttached=! bTubeAttached;
		SetbTubeAttached(bTubeAttached);
	*/
}

ABaseAmmoRound* AWEAPON_Javelin::SpawnSingleAmmoRound(bool bAux, int32 ammo_id, bool bSpecial)
{
	ABaseAmmoRound* Ar = nullptr;
	ABaseAmmoRound* ARClass = nullptr;
	/*
	if (bAux)
	{
		ARClass=AuxAmmoRoundClass;
	}
	else
	{
		if (bSpecial)
		{
			ARClass=SpecialAmmoRoundClass;
		}
		else
		{
			ARClass=AmmoRoundClass;
		}
	}
	Ar=Spawn(ARClass,Instigator);
	Ar.SetAmmoID(ammo_id);
	AttachToBone(Ar,'TubeRoot');
	Ar.SetDrawScale(DrawScale);
	*/
	return Ar;
}

float AWEAPON_Javelin::GetBreatheMultiplier()
{
	return 0.3;
}
bool AWEAPON_Javelin::CanSprint()
{
	if (CheckJavelinTube())
	{
		return false;
	}
	else
	{
		return Super::CanSprint();
	}
}

bool AWEAPON_Javelin::CheckJavelinTube()
{
	return bTubeAttached;
}

void AWEAPON_Javelin::FixJam()
{
	/*
		ServerFixJam();
		if (GetNetMode() == ENetMode::NM_Client)
		{
			GotoState('BusyFixingJam');
		}
	*/
}
void AWEAPON_Javelin::ClientSetUpCLUPack(bool bSetUp)
{
	/*
		if (Instigator != nullptr && GetNetMode() == ENetMode::NM_Client)
		{
			if (bSetUp)
			{
				CLUpack=Spawn('Attch_CLUpack');
				CLUpack.SetUpCLUPack(Instigator);
			}
			else
			{
				if (CLUpack != nullptr)
				{
					Instigator.bCanProne=true;
					Cast<AAGP_Pawn>(Instigator).bHasCLU=false;
					Cast<AAGP_Pawn>(Instigator).bAllowSwap=false;
					CLUpack.RemoveCLUPack();
				}
			}
		}
	*/
}
EUpperBodyAnim AWEAPON_Javelin::GetUpperBodyLowerAnim()
{
	return EUpperBodyAnim::UBANIM_Jav_LowerJav;
}
EUpperBodyAnim AWEAPON_Javelin::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_Jav_RaiseJav;
}
EUpperBodyAnim AWEAPON_Javelin::GetUpperBodyReadyAnim()
{
	if (IsZoomed())
	{
		return EUpperBodyAnim::UBANIM_Jav_ReadyZoom;
	}
	else
	{
		return EUpperBodyAnim::UBANIM_Jav_Ready;
	}
}
void AWEAPON_Javelin::Fire(float Value)
{
	/*
		if (bLockedOn == false)
		{
			return;
		}
		if (! bDirectFire && CheckDistance(HomingTarget))
		{
			CancelLock(true);
			return;
		}
		Toggle_bLockedOn();
		GotoState('Idle');
		Fire(Value);
		bDisableNV=false;
		CycleZoom();
		ToggleVision(false);
	*/
}
void AWEAPON_Javelin::ProjectileFire()
{
	APlayerController* PC = nullptr;
	FVector X = FVector(0,0,0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FRotator R = FRotator(0, 0, 0);
	/*
	if (Instigator != nullptr)
	{
		R=Instigator.GetViewRotation() + AdjustedAim;
		R.Pitch=R.Pitch - CurrentElevation;
	}
	Owner.MakeNoise(1);
	_Projectile=GetCurrentAmmoType().SpawnProjectile(ThirdPersonActor.GetBoneCoords('Backblast').Origin +  Vector(ThirdPersonActor.GetBoneRotation('TubeRoot')) * 32,ThirdPersonActor.GetBoneRotation('TubeRoot'));
	PC=Cast<APlayerController>(Instigator.Controller);
	if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
	{
		Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredRocket();
	}
	if (bHasBackBlast)
	{
		GetAxes(R,X,Y,Z);
		ProjectileBackBlast(X,Y,Z);
	}
	*/
}
void AWEAPON_Javelin::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	bTooClose=CheckDistance(HomingTarget);
	bSeekOn=false;
	//GetInstigator()->ChangeJavelinReloadAnimation(2);
	Super::ServerFire(bNoAdjustAim,bRapid,bBreatheBonus);
}

bool AWEAPON_Javelin::CheckTarget()
{
	AActor* NewTarget = nullptr;
	/*
	NewTarget=JavTrace();
	if (GetNetMode() != ENetMode::NM_Client)
	{
		if (HomingTarget != nullptr && IsInState('Targeting') && CheckDistance(NewTarget))
		{
			SetTimer(0,false);
			GotoState('TooClose','AlreadyTargeting');
			ClientGotoState('TooClose','AlreadyTargeting');
		}
		else
		{
			if (IsInState('TooClose') && ! CheckDistance(NewTarget))
			{
				SetTimer(0,false);
				GotoState('Targeting','AlreadyTargeting');
				ClientGotoState('Targeting','AlreadyTargeting');
			}
		}
		if (HomingTarget == nullptr)
		{
			SetHomingTarget(NewTarget);
		}
	}
	if (NewTarget == HomingTarget)
	{
		return true;
	}
	*/
	return false;
}

void AWEAPON_Javelin::FailedSupported()
{
	if (! bSafe)
	{
		FireMode();
	}
}

void AWEAPON_Javelin::FireMode()
{
	if (bDirectFire)
	{
		bDirectFire=false;
		JavelinPlaySound(DirectAttackSound);
	}
	else
	{
		bDirectFire=true;
		JavelinPlaySound(TopAttackSound);
	}
}

void AWEAPON_Javelin::Target_Lock()
{
	if (AmmoType->HasAmmo())
	{
		bSeekOn=true;
		//SetHomingTarget(JavTrace());
		if (HomingTarget == nullptr || ! CheckDistance(HomingTarget))
		{
			//GotoState('Targeting');
		}
		else
		{
			//GotoState('TooClose');
		}
	}
}
void AWEAPON_Javelin::CancelLock(bool KeepSeekOn)
{
	/*
		HomingTarget=nullptr;
		if (bLockedOn)
		{
			Toggle_bLockedOn();
		}
		if (IsInState('LockedOn') || IsInState('Targeting') || IsInState('TooClose'))
		{
			GotoState('Idle');
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
			{
				ClientGotoState('Idle',"None");
			}
		}
		if (! KeepSeekOn)
		{
			bSeekOn=false;
		}
		if (J_Target != nullptr)
		{
			J_Target.Destroy();
		}
	*/
}
void AWEAPON_Javelin::Spawn_J_Target()
{
	/*
	if (HomingTarget != nullptr)
	{
		if (Instigator.IsHumanControlled())
		{
			J_Target=Spawn('Jav_Target',Self,,HitLocation,HomingTarget.Rotation);
		}
		else
		{
			J_Target=Spawn('Jav_Target',Self,,HomingTarget->GetActorLocation(),HomingTarget.Rotation);
		}
		J_Target.SetBase(HomingTarget);
	}
	*/
}

bool AWEAPON_Javelin::CheckDistance(AActor* Target)
{
	if (Target != nullptr)
	{
		/*
		if (VSizeSquared(Target->GetActorLocation() - GetInstigator()->GetActorLocation()) < MinRangeDirect * *2)
		{
			return true;
		}
		if (VSizeSquared(Target->GetActorLocation() - GetInstigator()->GetActorLocation()) < MinRangeTop * *2 && !bDirectFire)
		{
			return true;
		}
		*/
	}
	else
	{
		return false;
	}
	return false;   //FAKE    /ELiZ
}

AActor* AWEAPON_Javelin::JavTrace()
{
	FVector StartTrace = FVector(0,0,0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	ABaseWeaponAttachment* BA = nullptr;
	AActor* HitActor = nullptr;
	AActor* TraceFrom = nullptr;
	//FPrecisionVector JavVector;
	FBoneInfo HitBone;
	UMaterialInstance* HitMaterial = nullptr;
	/*
	GetAxes(Instigator.GetViewRotation(),X,Y,Z);
	StartTrace.X=Instigator.Location.X;
	StartTrace.Y=Instigator.Location.Y;
	StartTrace.Z=Instigator.Location.Z + Instigator.BaseEyeHeight;
	StartTrace += Instigator.CollisionRadius * X;
	VtoPV(StartTrace,JavVector);
	EndTrace=StartTrace + 130000 * X;
	BA=BaseWeaponAttachment(ThirdPersonActor);
	TraceFrom=BA.GetSource();
	TraceFrom.bUseCollisionStaticMesh=true;
	HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,false);
	TraceFrom.bUseCollisionStaticMesh=false;
	*/
	return HitActor;
}

void AWEAPON_Javelin::SetSeekViewMode()
{
	if (GetZoomMultiplier() != 9)
	{
		CycleZoom();
	}
	ToggleVision(true);
}

void AWEAPON_Javelin::AltFire(float Value)
{
	/*
		if (IsZoomed() && AmmoType.AmmoAmount > 0)
		{
			bDisableNV=true;
			if (bCanMisFire || bForceMisfire)
			{
				bCanMisFire=false;
				if (FMath::FRand() < MisFireChance || bForceMisfire)
				{
					if (bForceMisfire)
					{
						ServerUnJamit();
					}
					HandleMisFire();
					bDisableNV=false;
					return;
				}
			}
			if (! bSeekOn)
			{
				JavelinPlaySound(SeekOn);
				RememberViewMode();
			}
			Target_Lock();
			SetSeekViewMode();
		}
	*/
}

void AWEAPON_Javelin::Toggle_bLockedOn()
{
	bLockedOn=! bLockedOn;
}

AJav_Target* AWEAPON_Javelin::GetJ_Target()
{
	return J_Target;
}

AActor* AWEAPON_Javelin::GetHomingTarget()
{
	return HomingTarget;
}

bool AWEAPON_Javelin::GetbTooClose()
{
	return bTooClose;
}

void AWEAPON_Javelin::SetHomingTarget(AActor* Target)
{
	/*
	if (Target != nullptr && Target->ValidJavelinTarget == 1 || Target->ValidJavelinTarget == 2)
	{
		HomingTarget=Target;
	}
	else
	{
		HomingTarget=nullptr;
	}
	*/
}

void AWEAPON_Javelin::RememberViewMode()
{
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		if (myscope != nullptr)
		{
			if (myscope->fZoomMultiplier == 9)
			{
				bWas9x=true;
			}
			else
			{
				bWas9x=false;
			}
		}
		bNVWasOn=GetbIsActive();
	}
}

void AWEAPON_Javelin::SetPreviousViewMode()
{
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		if (bNVWasOn && ! bIsActive)
		{
			ToggleVision(true);
		}
		else
		{
			if (! bNVWasOn && bIsActive)
			{
				ToggleVision(false);
			}
		}
		if (myscope->fZoomMultiplier == 4 && bWas9x)
		{
			CycleZoom();
		}
		else
		{
			if (myscope->fZoomMultiplier == 9 && ! bWas9x)
			{
				CycleZoom();
			}
		}
	}
}

void AWEAPON_Javelin::NV()
{
	if (IsZoomed())
	{
		if (bDisableNV)
		{
			CancelLock(false);
			JavelinPlaySound(SeekOff);
			SetPreviousViewMode();
			bDisableNV=false;
			return;
		}
		if (GetZoomMultiplier() == 9)
		{
			CycleZoom();
			ToggleVision(false);
		}
		else
		{
			if (! bIsActive)
			{
				ToggleVision(true);
				JavelinPlaySound(NV_Sound);
			}
			else
			{
				CycleZoom();
				JavelinPlaySound(ChangeViewMode);
			}
		}
	}
}

void AWEAPON_Javelin::ToggleZoom()
{
	Super::ToggleZoom();
}

void AWEAPON_Javelin::Zoom()
{
	Super::Zoom();
	JavelinPlaySound(ZoomSound);
}
void AWEAPON_Javelin::UnZoom()
{
	if (! bSeekOn)
	{
		RememberViewMode();
	}
	UnZoom();
	//AmbientSound=nullptr;
	CancelLock(false);
	bDisableNV=false;
	if (bIsActive)
	{
		Toggle_bIsActive(false);
	}
}
void AWEAPON_Javelin::ToggleVision(bool TurnOn)
{
	Toggle_bIsActive(TurnOn);
}
void AWEAPON_Javelin::CycleZoom()
{
	if (_Scope != nullptr)
	{
		myscope->CycleZoom(Cast<APlayerController>(GetInstigator()->Controller));
	}
}
bool AWEAPON_Javelin::GetbIsActive()
{
	return bIsActive;
}

bool AWEAPON_Javelin::GetbSeekOn()
{
	return bSeekOn;
}

bool AWEAPON_Javelin::GetbDirectFire()
{
	return bDirectFire;
}

bool AWEAPON_Javelin::GetbLockedOn()
{
	return bLockedOn;
}

void AWEAPON_Javelin::SetbIsActive(bool _bIsActive)
{
	bIsActive=_bIsActive;
}

void AWEAPON_Javelin::Toggle_bIsActive(bool TurnOn)
{
	if (! TurnOn)
	{
		SetbIsActive(false);
		if (bUseNV)
		{
			Set_NV();
		}
	}
	else
	{
		SetbIsActive(true);
		myscope->bNeedtoSetNightVision=true;
	}
}

void AWEAPON_Javelin::Set_NV()
{
	if (Cast<AHumanController>(GetInstigator()->Controller) != nullptr)
	{
		myscope->Jav_User->SetNightVision(false);
		myscope->Jav_User->HideSmoke(false);
	}
}
bool AWEAPON_Javelin::ShouldDrawCrosshair()
{
	if (! IsZoomed())
	{
		return Super::ShouldDrawCrosshair();
	}
	else
	{
		return false;
	}
}

int32 AWEAPON_Javelin::TrackLength(UCanvas* Canvas, int32 Direction, FVector TargetLocation)
{
	AJav_Target* TrackTarget = nullptr;
	int32 Iterations = 0;
	int32 EndLength = 0;
	int32 MissCount = 0;
	FVector ScreenLoc = FVector(0,0,0);
	FVector WorldLoc = FVector(0,0,0);
	float xStart = 0;
	float YStart = 0;
	float NextScreenLoc = 0;
	float NewSize = 0;
	AActor* NewHomingTarget = nullptr;
	int32 MaxEndlength = 0;
	/*
		ScreenLoc=Canvas.WorldToScreen(TargetLocation);
		xStart=ScreenLoc.X;
		YStart=ScreenLoc.Y;
		ScreenLoc.Z=0;
		if (Direction < 2)
		{
			NewSize=Canvas.SizeX * 0.15;
			MaxEndlength=Canvas.SizeX * 0.28;
		}
		else
		{
			NewSize=Canvas.SizeY * 0.15;
			MaxEndlength=Canvas.SizeY * 0.25;
		}
		NextScreenLoc=NewSize;
		TrackTarget=Spawn('Jav_Target',Self,,HomingTarget->GetActorLocation(),HomingTarget.Rotation);
		if (Iterations < 5)
		{
			NewSize=NewSize / 2;
			if (Direction == 0)
			{
				ScreenLoc.X=xStart - NextScreenLoc;
			}
			if (Direction == 1)
			{
				ScreenLoc.X=xStart + NextScreenLoc;
			}
			if (Direction == 2)
			{
				ScreenLoc.Y=YStart - NextScreenLoc;
			}
			if (Direction == 3)
			{
				ScreenLoc.Y=YStart + NextScreenLoc;
			}
			WorldLoc=Canvas.ScreenToWorld(ScreenLoc);
			NewHomingTarget=SimTrace(WorldLoc);
			if (NewHomingTarget == HomingTarget)
			{
				NextScreenLoc=NextScreenLoc + NewSize;
				TrackTarget.SetLocation(NewHomingLocation);
			}
			else
			{
				MissCount ++;
				NextScreenLoc=NextScreenLoc - NewSize;
			}
			Iterations ++;
		}
		if (Direction == 0)
		{
			EndLength=Canvas.WorldToScreen(J_Target.Location).X - Canvas.WorldToScreen(TrackTarget.Location).X;
		}
		if (Direction == 1)
		{
			EndLength=Canvas.WorldToScreen(TrackTarget.Location).X - Canvas.WorldToScreen(J_Target.Location).X;
		}
		if (Direction == 2)
		{
			EndLength=Canvas.WorldToScreen(J_Target.Location).Y - Canvas.WorldToScreen(TrackTarget.Location).Y;
		}
		if (Direction == 3)
		{
			EndLength=Canvas.WorldToScreen(TrackTarget.Location).Y - Canvas.WorldToScreen(J_Target.Location).Y;
		}
		if (MissCount == Iterations)
		{
			EndLength=1;
		}
		TrackTarget.Destroy();
		return FMath::Min(EndLength,MaxEndlength);
	*/
	return 0;    //FAKE   /EliZ
}

AActor* AWEAPON_Javelin::SimTrace(FVector TraceVec)
{
	FVector StartTrace = FVector(0,0,0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	ABaseWeaponAttachment* BA = nullptr;
	AActor* TraceFrom = nullptr;
	FBoneInfo HitBone;
	UMaterialInstance* HitMaterial = nullptr;
	AActor* NewHomingTarget = nullptr;
	/*
	FPrecisionVector StartVector;
	FPrecisionVector EndVector;
	GetAxes(Instigator.GetViewRotation(),X,Y,Z);
	StartTrace.X=Instigator.Location.X;
	StartTrace.Y=Instigator.Location.Y;
	StartTrace.Z=Instigator.Location.Z + Instigator.BaseEyeHeight;
	StartTrace += Instigator.CollisionRadius * X;
	VtoPV(StartTrace,StartVector);
	VtoPV(TraceVec,EndVector);
	EndTrace=StartTrace + 130000 * TraceVec;
	BA=BaseWeaponAttachment(ThirdPersonActor);
	TraceFrom=BA.GetSource();
	TraceFrom.bUseCollisionStaticMesh=true;
	NewHomingTarget=TraceFrom.BoneTrace(NewHomingLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,false);
	TraceFrom.bUseCollisionStaticMesh=false;
	*/
	return NewHomingTarget;
}

void AWEAPON_Javelin::SetScopeVar()
{
	myscope->SetbUpdateTrackGateSize();
}

void AWEAPON_Javelin::RunAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	/*
	if (! HasAnim(Sequence))
	{
		Log("Weapon_Javelin is missing 1st person anim:" @ Sequence,'PICA');
		Sequence='Idle';
	}
	RunAnimation(Sequence,Rate,TweenTime,bLoop);
	*/
}

void AWEAPON_Javelin::ServerJamit()
{
	bForceMisfire=true;
}

void AWEAPON_Javelin::ServerUnJamit()
{
	bForceMisfire=false;
}

bool AWEAPON_Javelin::ShowProjectileView()
{
	return false;
	/*
	if (_Projectile != nullptr && VSizeSquared(_Projectile.Velocity) > 1 && IsZoomed())
	{
		return true;
	}
	*/
}
void AWEAPON_Javelin::ProjectileCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation)
{
	/*
	ViewActor=_Projectile;
	CameraLocation=_Projectile.Location + Normal(_Projectile.Velocity) * 150;
	CameraRotation=Proj_Javelin(_Projectile).J_Target.Location - _Projectile.Location;
	*/
}
