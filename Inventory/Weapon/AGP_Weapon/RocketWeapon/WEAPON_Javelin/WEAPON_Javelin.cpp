// All the original content belonged to the US Army


#include "WEAPON_Javelin.h"
#include "AA29/Pickup/AGP_WeaponPickup/PickupW_Javelin/PickupW_Javelin.h"
#include "AA29/BaseScope/ScopeW_Javelin.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_Javelin/AttachW_Javelin.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/BackBlastDamage/BackBlastDamage.h"
#include "AA29/BaseAmmoRound/AmmoRound_Javelin.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_Javelin/Ammo_Javelin.h"

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
	IconMaterial						= LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/jav_icon.jav_icon"), NULL, LOAD_None, NULL);
	ItemName							= "Javelin";
	Mesh								= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AAO_Armory/1stPrsnCLU.1stPrsnCLU"), NULL, LOAD_None, NULL);
	//bFullVolume = true;
	//SoundVolume = 64;
	//SoundRadius = 1;
}

/*
void AWEAPON_Javelin::DisplayDebug(UCanvas* Canvas, out float YL, out float YPos)
{
	
		DisplayDebug(Canvas,YL,YPos);
		YPos += YL;
		Canvas.SetPos(4,YPos);
		Canvas.SetDrawColor(0,255,0);
		Canvas.DrawText("Javelin Tube Attached: " $ bTubeAttached $ "    Attaching: " $ bAttachingTube $ "   Wants to swap: " $ bWantsToSwap);
		YPos += YL;
		Canvas.SetPos(4,YPos);
	
}
*/
void AWEAPON_Javelin::SpawnTubePickup()
{
	/*
		local Weapon W;
		if (bTubeAttached)
		{
			if (AmmoType.AmmoAmount > 0)
			{
				W=Spawn('Javelin_Tube');
				W.Velocity=Velocity;
				W.DropFrom(Instigator.Location +  Vector(rot(0 16384 0) + Instigator.Controller.Rotation) * 30);
				AmmoType.AmmoAmount=0;
				RecountAmmo();
			}
			else
			{
				W=Spawn('Javelin_Empty_Tube');
				W.Velocity=Velocity;
				W.DropFrom(Instigator.Location +  Vector(rot(0 16384 0) + Instigator.Controller.Rotation) * 30);
			}
		}
	*/
}
void AWEAPON_Javelin::DropFrom(FVector StartLocation, bool bAttach)
{
	/*
		local Pickup p;
		if (Instigator != None)
		{
			Instigator.bCanProne=True;
			AGP_Pawn(Instigator).bHasCLU=False;
			AGP_Pawn(Instigator).bAllowSwap=False;
			Instigator.ChangeJavelinReloadAnimation(0);
			if (CLUpack != None)
			{
				CLUpack.RemoveCLUPack();
			}
			ClientSetUpCLUPack(False);
		}
		SpawnTubePickup();
		p=DropFrom(StartLocation,bAttach);
		if (AmmoMagCount > 0)
		{
			SetClipCount(GetBestClip(),0);
			RecountAmmo();
		}
		Return p;
	*/
}
bool AWEAPON_Javelin::CheckForNoReload()
{
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		//if (! HumanController(Instigator.Controller).QualifiedFor(Class'ClassJavelin'))
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
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
		}
		Switch(Instigator.JavelinReloadAnimation)
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
void AWEAPON_Javelin::ShouldDoDelayedEject()
{
	//Return False;
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
		if (Instigator != None && Instigator.Controller != None && HumanController(Instigator.Controller) != None && HumanController(Instigator.Controller).IsInState('None'))
		{
			Return;
		}
		Set_bAttachingTube();
		if (bTubeAttached)
		{
			SetbTubeAttached(False);
			Instigator.bCanProne=True;
			GotoState('BusyReloading');
		}
		else
		{
			if (! bTubeAttached && AmmoMagCount > 0)
			{
				SetbTubeAttached(True);
				Instigator.bCanProne=False;
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
			Instigator.bCanProne=False;
			ReloadClip(newclip);
		}
		else
		{
			Instigator.bCanProne=True;
		}
	*/
}
void AWEAPON_Javelin::SpawnTube()
{
	/*
		local AGP.AGP_Weapon Tube;
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
		if (FRand() < 0.5)
		{
			bDirectFire=True;
		}
		else
		{
			bDirectFire=False;
		}
		bSeekOn=True;
		bLockedOn=True;
		Spawn_J_Target();
		NPC_Fire(Value,Enemy);
	*/
}
void AWEAPON_Javelin::NPC_ProjectileFire()
{
	/*
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector SpawnLocation;
		local FVector AimVector;
		local FRotator SpawnRot;
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
	/*
		local bool bFirstPerson;
		local AGP.HumanController HC;
		HC=HumanController(Instigator.Controller);
		if (HC != None && Instigator != None)
		{
			bFirstPerson=! HC.bBehindView && HC.ViewTarget == Instigator;
		}
		if (AmmoRoundList != None && ! bFirstPerson)
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
		if (AmmoRoundList != None)
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
/*
void AWEAPON_Javelin::StaticPrecache (LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'fx_decal_explosion');
	L.AddPrecacheMaterial(Texture'fx_smk_ball03');
	L.AddPrecacheMaterial(Texture'fx_smk_ball04');
	L.AddPrecacheMaterial(Texture'fx_drt_cloud01');
	L.AddPrecacheMaterial(Texture'fx_part_explosion01');
	L.AddPrecacheMaterial(Texture'fx_smk_ball01');
	L.AddPrecacheStaticMesh(StaticMesh'fx_part_con_chunk1');
	L.AddPrecacheStaticMesh(StaticMesh'Tube3PSpent');
	L.AddPrecacheMaterial(Texture'missile');
	L.AddPrecacheMaterial(Texture'Backblast_jav');
	L.AddPrecacheMaterial(Texture'fx_smk_ball02');
	L.AddPrecacheStaticMesh(StaticMesh'missile');
	L.AddPrecacheStaticMesh(StaticMesh'Backblast');
	L.AddPrecacheStaticMesh(StaticMesh'Tube3PLoaded');
	StaticPrecache(L);
}
*/
void AWEAPON_Javelin::IsJavelin()
{
	//Return True;
}
void AWEAPON_Javelin::TweenDown()
{
	/*
		local name SeqName;
		local float AnimFrame;
		local float AnimRate;
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
					if (Instigator != None && Instigator.bIsProne)
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
					if (Instigator != None && Instigator.bIsProne)
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
	/*
		local int initradius;
		if (BaseWeaponAttachment(ThirdPersonActor) != None)
		{
			BaseWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
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
						if (Instigator != None && Instigator.bIsProne)
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
						if (Instigator != None && Instigator.bIsSprinting)
						{
							Instigator.StopSprint();
						}
						_bCharged=True;
						if (Instigator != None && Instigator.bIsProne)
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
						if (Instigator != None && Instigator.bIsProne)
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
		if (Instigator != None && Instigator == Level.GetClientPawn())
		{
			GetSoundActor().PlaySound(SoundName,0,0.5,True,60,1,False,True);
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
void AWEAPON_Javelin::CanLean()
{
	//Return False;
}
void AWEAPON_Javelin::GiveTo(APawn* Other, APickup* Pickup)
{
	/*
		local Inventory weap;
		GiveTo(Other,Pickup);
		weap=AGP_Pawn(Instigator).getAltShoulderInventory();
		if (weap == None)
		{
			weap=AGP_Pawn(Instigator).getHandsInventory();
		}
		if (weap.IsA('Javelin_Tube'))
		{
			AddClip(AmmoName);
			RecountAmmo();
		}
		MaybeSwapBinocs();
		AGP_Pawn(Other).bHasCLU=True;
		if (Other != None)
		{
			CLUpack=Spawn('Attch_CLUpack');
			CLUpack.SetUpCLUPack(Other);
		}
		ClientSetUpCLUPack(True);
	*/
}
void AWEAPON_Javelin::MaybeSwapBinocs()
{
	/*
		if (Instigator != None && AGP_Pawn(Instigator).Weapon != None && AGP_Pawn(Instigator).Weapon.IsA('Item_Binoculars'))
		{
			HumanController(Instigator.Controller).SwapType=3;
			SwapWeapons();
		}
	*/
}
void AWEAPON_Javelin::SwapWeapons()
{
	/*
		AGP_Pawn(Instigator).bAllowSwap=True;
		Switch(HumanController(Instigator.Controller).SwapType)
		{
			case 1:
			HumanController(Instigator.Controller).SwapHands();
			break;
			case 2:
			HumanController(Instigator.Controller).SwapAltShoulder();
			break;
			case 3:
			HumanController(Instigator.Controller).SwapHip();
			break;
			case 4:
			HumanController(Instigator.Controller).Pistol();
			break;
			case 5:
			HumanController(Instigator.Controller).Grenade(1);
			break;
			case 6:
			HumanController(Instigator.Controller).Grenade(2);
			break;
			case 7:
			HumanController(Instigator.Controller).Grenade(3);
			break;
			case 8:
			HumanController(Instigator.Controller).Grenade(4);
			break;
			case 9:
			HumanController(Instigator.Controller).Grenade(5);
			break;
			case 10:
			HumanController(Instigator.Controller).Grenade(6);
			break;
			default:
			AGP_Pawn(Instigator).bAllowSwap=False;
			DebugLog(DEBUG_Warn,"Weapon_Javelin:SwapWeapons: Invalid SType:" @ HumanController(Instigator.Controller).SwapType);
		}
		HumanController(Instigator.Controller).SwapType=0;
	*/
}
void AWEAPON_Javelin::GetSwapContainer()
{
	//Return AGP_Pawn(Instigator).getInvContainerHip();
}
void AWEAPON_Javelin::Destroyed()
{
	/*
		if (J_Target != None)
		{
			J_Target.Destroy();
		}
		if (Instigator != None)
		{
			Instigator.bCanProne=True;
			AGP_Pawn(Instigator).bAllowSwap=False;
			AGP_Pawn(Instigator).bHasCLU=False;
			Instigator.ChangeJavelinReloadAnimation(0);
			if (CLUpack != None)
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
		if (_Scope.IsA('ScopeW_Javelin'))
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
			if (Instigator != None && Instigator.Controller != None && HumanController(Instigator.Controller) != None && HumanController(Instigator.Controller).IsInState('None'))
			{
				return False;
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
void AWEAPON_Javelin::SpawnSingleAmmoRound(bool bAux, int32 ammo_id, bool bSpecial)
{
	/*
		local AGP.BaseAmmoRound Ar;
		local class<AGP.BaseAmmoRound>  ARClass;
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
		Return Ar;
	*/
}
void AWEAPON_Javelin::GetBreatheMultiplier()
{
	//Return 0.3;
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
		if (Instigator != None && GetNetMode() == ENetMode::NM_Client)
		{
			if (bSetUp)
			{
				CLUpack=Spawn('Attch_CLUpack');
				CLUpack.SetUpCLUPack(Instigator);
			}
			else
			{
				if (CLUpack != None)
				{
					Instigator.bCanProne=True;
					AGP_Pawn(Instigator).bHasCLU=False;
					AGP_Pawn(Instigator).bAllowSwap=False;
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
			Return;
		}
		if (! bDirectFire && CheckDistance(HomingTarget))
		{
			CancelLock(True);
			Return;
		}
		Toggle_bLockedOn();
		GotoState('Idle');
		Fire(Value);
		bDisableNV=False;
		CycleZoom();
		ToggleVision(False);
	*/
}
void AWEAPON_Javelin::ProjectileFire()
{
	/*
		local PlayerController PC;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FRotator R;
		if (Instigator != None)
		{
			R=Instigator.GetViewRotation() + AdjustedAim;
			R.Pitch=R.Pitch - CurrentElevation;
		}
		Owner.MakeNoise(1);
		_Projectile=GetCurrentAmmoType().SpawnProjectile(ThirdPersonActor.GetBoneCoords('Backblast').Origin +  Vector(ThirdPersonActor.GetBoneRotation('TubeRoot')) * 32,ThirdPersonActor.GetBoneRotation('TubeRoot'));
		PC=PlayerController(Instigator.Controller);
		if (Level.Game.Stats != None && PC != None && PC.PlayerStatsIndex >= 0)
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
	/*
		bTooClose=CheckDistance(HomingTarget);
		bSeekOn=False;
		Instigator.ChangeJavelinReloadAnimation(2);
		ServerFire(bNoAdjustAim,bRapid,bBreatheBonus);
	*/
}
void AWEAPON_Javelin::CheckTarget()
{
	/*
		local Actor NewTarget;
		NewTarget=JavTrace();
		if (GetNetMode() != ENetMode::NM_Client)
		{
			if (HomingTarget != None && IsInState('Targeting') && CheckDistance(NewTarget))
			{
				SetTimer(0,False);
				GotoState('TooClose','AlreadyTargeting');
				ClientGotoState('TooClose','AlreadyTargeting');
			}
			else
			{
				if (IsInState('TooClose') && ! CheckDistance(NewTarget))
				{
					SetTimer(0,False);
					GotoState('Targeting','AlreadyTargeting');
					ClientGotoState('Targeting','AlreadyTargeting');
				}
			}
			if (HomingTarget == None)
			{
				SetHomingTarget(NewTarget);
			}
		}
		if (NewTarget == HomingTarget)
		{
			Return True;
		}
		Return False;
	*/
}
void AWEAPON_Javelin::FailedSupported()
{
	/*
		if (! bSafe)
		{
			FireMode();
		}
	*/
}
void AWEAPON_Javelin::FireMode()
{
	/*
		if (bDirectFire)
		{
			bDirectFire=False;
			JavelinPlaySound(DirectAttackSound);
		}
		else
		{
			bDirectFire=True;
			JavelinPlaySound(TopAttackSound);
		}
	*/
}
void AWEAPON_Javelin::Target_Lock()
{
	/*
		if (AmmoType.HasAmmo())
		{
			bSeekOn=True;
			SetHomingTarget(JavTrace());
			if (HomingTarget == None || ! CheckDistance(HomingTarget))
			{
				GotoState('Targeting');
			}
			else
			{
				GotoState('TooClose');
			}
		}
	*/
}
void AWEAPON_Javelin::CancelLock(bool KeepSeekOn)
{
	/*
		HomingTarget=None;
		if (bLockedOn)
		{
			Toggle_bLockedOn();
		}
		if (IsInState('LockedOn') || IsInState('Targeting') || IsInState('TooClose'))
		{
			GotoState('Idle');
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
			{
				ClientGotoState('Idle','None');
			}
		}
		if (! KeepSeekOn)
		{
			bSeekOn=False;
		}
		if (J_Target != None)
		{
			J_Target.Destroy();
		}
	*/
}
void AWEAPON_Javelin::Spawn_J_Target()
{
	/*
		if (HomingTarget != None)
		{
			if (Instigator.IsHumanControlled())
			{
				J_Target=Spawn('Jav_Target',Self,,HitLocation,HomingTarget.Rotation);
			}
			else
			{
				J_Target=Spawn('Jav_Target',Self,,HomingTarget.Location,HomingTarget.Rotation);
			}
			J_Target.SetBase(HomingTarget);
		}
	*/
}
void AWEAPON_Javelin::CheckDistance(AActor* Target)
{
	/*
		if (Target != None)
		{
			if (VSizeSquared(Target.Location - Instigator.Location) < MinRangeDirect ** 2)
			{
				Return True;
			}
			if (VSizeSquared(Target.Location - Instigator.Location) < MinRangeTop ** 2 && ! bDirectFire)
			{
				Return True;
			}
		}
		else
		{
			Return False;
		}
	*/
}
void AWEAPON_Javelin::JavTrace()
{
	/*
		local FVector StartTrace;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local FVector EndTrace;
		local FVector HitNormal;
		local AGP.BaseWeaponAttachment BA;
		local Actor HitActor;
		local Actor TraceFrom;
		local Object.PrecisionVector JavVector;
		local Actor.BoneInfo HitBone;
		local Material HitMaterial;
		GetAxes(Instigator.GetViewRotation(),X,Y,Z);
		StartTrace.X=Instigator.Location.X;
		StartTrace.Y=Instigator.Location.Y;
		StartTrace.Z=Instigator.Location.Z + Instigator.BaseEyeHeight;
		StartTrace += Instigator.CollisionRadius * X;
		VtoPV(StartTrace,JavVector);
		EndTrace=StartTrace + 130000 * X;
		BA=BaseWeaponAttachment(ThirdPersonActor);
		TraceFrom=BA.GetSource();
		TraceFrom.bUseCollisionStaticMesh=True;
		HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,False);
		TraceFrom.bUseCollisionStaticMesh=False;
		Return HitActor;
	*/
}
void AWEAPON_Javelin::SetSeekViewMode()
{
	/*
		if (GetZoomMultiplier() != 9)
		{
			CycleZoom();
		}
		ToggleVision(True);
	*/
}
void AWEAPON_Javelin::AltFire(float Value)
{
	/*
		if (IsZoomed() && AmmoType.AmmoAmount > 0)
		{
			bDisableNV=True;
			if (bCanMisFire || bForceMisfire)
			{
				bCanMisFire=False;
				if (FRand() < MisFireChance || bForceMisfire)
				{
					if (bForceMisfire)
					{
						ServerUnJamit();
					}
					HandleMisFire();
					bDisableNV=False;
					Return;
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
void AWEAPON_Javelin::GetJ_Target()
{
	//Return J_Target;
}
void AWEAPON_Javelin::GetHomingTarget()
{
	//Return HomingTarget;
}
bool AWEAPON_Javelin::GetbTooClose()
{
	return bTooClose;
}
void AWEAPON_Javelin::SetHomingTarget(AActor* Target)
{
	/*
	if (Target != None && Target.ValidJavelinTarget == 1 || Target.ValidJavelinTarget == 2)
		{
			HomingTarget=Target;
		}
		else
		{
			HomingTarget=None;
		}
	*/
}
void AWEAPON_Javelin::RememberViewMode()
{
	/*
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			if (myscope != None)
			{
				if (myscope.fZoomMultiplier == 9)
				{
					bWas9x=True;
				}
				else
				{
					bWas9x=False;
				}
			}
			bNVWasOn=GetbIsActive();
		}
	*/
}
void AWEAPON_Javelin::SetPreviousViewMode()
{
	/*
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			if (bNVWasOn && ! bIsActive)
			{
				ToggleVision(True);
			}
			else
			{
				if (! bNVWasOn && bIsActive)
				{
					ToggleVision(False);
				}
			}
			if (myscope.fZoomMultiplier == 4 && bWas9x)
			{
				CycleZoom();
			}
			else
			{
				if (myscope.fZoomMultiplier == 9 && ! bWas9x)
				{
					CycleZoom();
				}
			}
		}
	*/
}
void AWEAPON_Javelin::NV()
{
	/*
		if (IsZoomed())
		{
			if (bDisableNV)
			{
				CancelLock();
				JavelinPlaySound(SeekOff);
				SetPreviousViewMode();
				bDisableNV=False;
				Return;
			}
			if (GetZoomMultiplier() == 9)
			{
				CycleZoom();
				ToggleVision(False);
			}
			else
			{
				if (! bIsActive)
				{
					ToggleVision(True);
					JavelinPlaySound(NV_Sound);
				}
				else
				{
					CycleZoom();
					JavelinPlaySound(ChangeViewMode);
				}
			}
		}
	*/
}
void AWEAPON_Javelin::ToggleZoom()
{
	//ToggleZoom();
}
void AWEAPON_Javelin::Zoom()
{
	/*
		Zoom();
		JavelinPlaySound(ZoomSound);
	*/
}
void AWEAPON_Javelin::UnZoom()
{
	/*
		if (! bSeekOn)
		{
			RememberViewMode();
		}
		UnZoom();
		AmbientSound=None;
		CancelLock();
		bDisableNV=False;
		if (bIsActive)
		{
			Toggle_bIsActive(False);
		}
	*/
}
void AWEAPON_Javelin::ToggleVision(bool TurnOn)
{
	Toggle_bIsActive(TurnOn);
}
void AWEAPON_Javelin::CycleZoom()
{
	/*
		if (_Scope != None)
		{
			myscope.CycleZoom(PlayerController(Instigator.Controller));
		}
	*/
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
	/*
		if (! TurnOn)
		{
			SetbIsActive(False);
			if (bUseNV)
			{
				Set_NV();
			}
		}
		else
		{
			SetbIsActive(True);
			myscope.bNeedtoSetNightVision=True;
		}
	*/
}
void AWEAPON_Javelin::Set_NV()
{
	/*
		if (HumanController(Instigator.Controller) != None)
		{
			myscope.Jav_User.SetNightVision(False);
			myscope.Jav_User.HideSmoke(False);
		}
	*/
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
void AWEAPON_Javelin::TrackLength(UCanvas* Canvas, int32 Direction, FVector TargetLocation)
{
	/*
		local Jav_Target TrackTarget;
		local int Iterations;
		local int EndLength;
		local int MissCount;
		local FVector ScreenLoc;
		local FVector WorldLoc;
		local float xStart;
		local float YStart;
		local float NextScreenLoc;
		local float NewSize;
		local Actor NewHomingTarget;
		local int MaxEndlength;
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
		TrackTarget=Spawn('Jav_Target',Self,,HomingTarget.Location,HomingTarget.Rotation);
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
		Return Min(EndLength,MaxEndlength);
	*/
}
void AWEAPON_Javelin::SimTrace(FVector TraceVec)
{
	/*
		local FVector StartTrace;
		local FVector EndTrace;
		local FVector HitNormal;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local AGP.BaseWeaponAttachment BA;
		local Actor TraceFrom;
		local Object.PrecisionVector StartVector;
		local Object.PrecisionVector EndVector;
		local Actor.BoneInfo HitBone;
		local Material HitMaterial;
		local Actor NewHomingTarget;
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
		TraceFrom.bUseCollisionStaticMesh=True;
		NewHomingTarget=TraceFrom.BoneTrace(NewHomingLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,False);
		TraceFrom.bUseCollisionStaticMesh=False;
		Return NewHomingTarget;
	*/
}
void AWEAPON_Javelin::SetScopeVar()
{
	//myscope.SetbUpdateTrackGateSize();
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
void AWEAPON_Javelin::ShowProjectileView()
{
	/*
		Return False;
		if (_Projectile != None && VSizeSquared(_Projectile.Velocity) > 1 && IsZoomed())
		{
			Return True;
		}
	*/
}
void AWEAPON_Javelin::ProjectileCalcView(AActor* ViewActor, FVector CameraLocation, FRotator CameraRotation)
{
	/*
		ViewActor=_Projectile;
		CameraLocation=_Projectile.Location + Normal(_Projectile.Velocity) * 150;
		CameraRotation=Proj_Javelin(_Projectile).J_Target.Location - _Projectile.Location;
	*/
}
