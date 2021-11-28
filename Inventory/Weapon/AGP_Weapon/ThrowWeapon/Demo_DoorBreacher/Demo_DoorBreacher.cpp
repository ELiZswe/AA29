// All the original content belonged to the US Army


#include "Demo_DoorBreacher.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_DoorBreacher_Demo/PickupT_DoorBreacher_Demo.h"
#include "AA29/Inventory/Weapon\AGP_Weapon\ThrowWeapon\Throw_M67_Frag\Throw_MILES_Grenade\Throw_MILES_Grenade.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_Demo_DoorBreacher/AttachT_Demo_DoorBreacher.h"
#include "AA29/DamageType/AGP_DamageType/ExplosionDamage/BreacherExplosionDamage/BreacherExplosionDamage.h"
#include "AA29/DamageType/AGP_DamageType/FragDamage/BreacherFragDamage.h"

ADemo_DoorBreacher::ADemo_DoorBreacher()
{
	fPlacementTraceDistance = 70;
	DirectionalBlastRadius  = 600;
	DirectionalBlastCone    = 0.45;
	DirectionalBlastDamage  = 4;
	_fMinFuseTime           = 5;
	_fDamage                = 150;
	_fDamageRadius          = 262.467194;
	_fKillRadius            = 104.95999; 
	_fMomentum              = 20000;
	FragDamageType          = UBreacherFragDamage::StaticClass();
	MyDamageType            = UBreacherExplosionDamage::StaticClass();
	//	\\DamageClasses =
	//System = 1;
	_fMaxVisIntensity       = 0.99;
	_fEffectDuration        = 10;
	_bUseAnimNotifyAltFire  = true;
	PullSound               = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Demolitions/WeaponsUS_Demo_DoorBreacherPull.WeaponsUS_Demo_DoorBreacherPull"), NULL, LOAD_None, NULL);
	BoomSound               = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Demolitions/WeaponsUS_Demo_DoorBreacherPull.WeaponsUS_Demo_DoorBreacherPull"), NULL, LOAD_None, NULL);
	//cExplosionEmitter = Aem_bt_door_breach_explosion::StaticClass();
	InvGrenadeIndex         = 5;
	_cMILESAltClass         = AThrow_MILES_Grenade::StaticClass();
	OwnerDamageType         = UBreacherExplosionDamage::StaticClass();
	RadiusDamageType        = UBreacherExplosionDamage::StaticClass();
	special_tag             = "_new";
	DisplayFOV              = 55;
	PickupClass             = APickupT_DoorBreacher_Demo::StaticClass();
	PlayerViewOffset        = FVector(0, 0, 0);
	AttachmentClass         = { AAttachT_Demo_DoorBreacher::StaticClass() };
	IconMaterial            = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_db.hud_wpn_db"), NULL, LOAD_None, NULL);
	ItemName                = "Demolition Door Breacher";
	Mesh                    = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/DoorBreacher_1p.DoorBreacher_1p"), NULL, LOAD_None, NULL);
	DrawScale               = 1;
}


void ADemo_DoorBreacher::Tick(float DeltaTime)
{
	if (_FuseTime > 0)
	{
		_FuseCounter += DeltaTime;
		if (_FuseCounter > _FuseTime)
		{
			BlowUp();
		}
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			UE_LOG(LogTemp, Log, TEXT("FUSECOUNTER %d TIME %d"), _FuseCounter, _FuseTime);
		}
	}
}
void ADemo_DoorBreacher::PipeBombAnim()
{
}
void ADemo_DoorBreacher::Fire(float Value)
{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			FString ObjectName = GetOwner()->GetName();
			UE_LOG(LogTemp, Log, TEXT("%s Demo_DoorBreacher::Global::Fire"), *ObjectName);
		}
		/*
		if (CanPlaceDemolition())
		{
			if (AGP_Pawn(Instigator) != None && AGP_Pawn(Instigator)._FireMonitor != None)
			{
				AGP_Pawn(Instigator)._FireMonitor.Notify();
			}
			ServerFire();
		}
		else
		{
			Return;
		}
	*/
}
void ADemo_DoorBreacher::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	UE_LOG(LogTemp, Warning, TEXT("Demo_DoorBreacher::ServerFire()"));
	/*
	if (CanPlaceDemolition())
	{
		ClientGotoState('PulledPin','None');
		GotoState('PulledPin');
	}
	*/
}
void ADemo_DoorBreacher::CanPlaceDemolition()
{
	/*
		local FVector HitLocation;
		local FVector HitNormal;
		local FVector StartTrace;
		local FVector EndTrace;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local Actor HitActor;
		GetAxes(Instigator.GetViewRotation(),X,Y,Z);
		StartTrace=GetFireStart(X,Y,Z);
		EndTrace=StartTrace + X * fPlacementTraceDistance;
		HitActor=Instigator.Trace(HitLocation,HitNormal,EndTrace,StartTrace,True);
		if (GetNetMode() != ENetMode::NM_Client)
		{
			SavedHitactor=HitActor;
			SavedHitLocation=HitLocation;
			SavedPlacementNormal=HitNormal;
		}
		if (HitActor != None && HitActor.IsA('DecoMesh'))
		{
			Return DecoMesh(HitActor).bBreachable;
		}
		else
		{
			Return False;
		}
	*/
}

bool ADemo_DoorBreacher::IsTossNotThrow()
{
	return false;
}

void ADemo_DoorBreacher::SetAltFireNotified(bool bNotify)
{
	_bAltFireNotified=bNotify;
}

bool ADemo_DoorBreacher::IsAltFireNotified()
{
	return _bAltFireNotified;
}

void ADemo_DoorBreacher::PlayFiring()
{
	//PlayAnim('Fire');
}
void ADemo_DoorBreacher::PlayIdleAnim()
{
	/*
		if (_bPulledPin)
		{
			RunAnimation('Still',1,0.05,True);
		}
		else
		{
			RunAnimation('Idle',1,0.05,True);
		}
	*/
}
void ADemo_DoorBreacher::PlaySelect()
{
	/*
		local name OutSeqName;
		local float OutAnimFrame;
		local float OutAnimRate;
		GetAnimParams(0,OutSeqName,OutAnimFrame,OutAnimRate);
		if (! IsAnimating() && ! AnimIsInGroup(0,'Select'))
		{
			RunAnimation('Select',1);
			PlayOwnedSound(SelectSound,1,0.5,False,60,,True,False);
		}
		else
		{
			if (IsAnimating() && OutSeqName == 'Still')
			{
				RunAnimation('Select',1);
				PlayOwnedSound(SelectSound,1,0.5,False,60,,True,False);
			}
		}
	*/
}
void ADemo_DoorBreacher::TweenDown()
{
	/*
		local name Anim;
		local float frame;
		local float Rate;
		if (IsAnimating() && AnimIsInGroup(0,'Select'))
		{
			GetAnimParams(0,Anim,frame,Rate);
			TweenAnim(Anim,frame * 0.4);
		}
		else
		{
			RunAnimation('Down',1,0.05);
		}
	*/
}
void ADemo_DoorBreacher::SpawnPickup(bool bDrop, AThrowWeaponPickup* SetPickupPtr)
{
	/*
		local FVector StartTrace;
		local FVector EndTrace;
		local FVector X;
		local FVector Y;
		local FVector Z;
		local int SpawnOffset;
		GetAxes(Instigator.GetViewRotation(),X,Y,Z);
		StartTrace=GetFireStart(X,Y,Z);
		EndTrace=StartTrace + X * fPlacementTraceDistance;
		if (SetPickupPtr == None)
		{
			_PickupPtr=ThrowWeaponPickup(Spawn(PickupClass,Self,'None',SavedHitLocation,SavedPlacementNormal * -1 + rot(0 -49152 16384)));
			_PickupPtr.InitDroppedPickupFor(Self);
			if (_PickupPtr == None && SpawnOffset < 20)
			{
				SpawnOffset += 2;
				_PickupPtr=ThrowWeaponPickup(Spawn(PickupClass,Self,'None',SavedHitLocation + SavedPlacementNormal * SpawnOffset,SavedPlacementNormal * -1 + rot(0 -49152 16384)));
				_PickupPtr.InitDroppedPickupFor(Self);
			}
			if (_PickupPtr == None)
			{
				GotoState('Idle');
			}
			else
			{
				_PickupPtr.bAlwaysRelevant=True;
			}
		}
		else
		{
			_PickupPtr=SetPickupPtr;
		}
		if (SavedHitactor != Instigator)
		{
			_PickupPtr.SetBase(SavedHitactor,SavedHitLocation);
			_PickupPtr.SetPhysics(0);
		}
		else
		{
			DebugLog(DEBUG_Inv,"Demo_DoorBreacher::SpawnPickup() - Error, SavedHitactor was instigator");
		}
		if (_PickupPtr != None)
		{
			_PickupPtr.SetWeapon(Self);
			_PickupPtr.SetDoorBreacherEmitter(DecoMesh(SavedHitactor).BreachedEmitter);
		}
		if (_bPulledPin && ! _bBlewUp && ! _bLostSpoon)
		{
			SetFuseTime(_fMinFuseTime + _fAddFuseTime * FRand());
			MakeNoise(1);
		}
		SetOwner(None);
	*/
}
void ADemo_DoorBreacher::BlowUp()
{
	/*
		local FVector HitLocation;
		local Actor HitActor;
		local GrenadeHelper GH;
		local AGP.NPCAICombatController npcaiccIterator;
		if (Level.Game.bGameEnded)
		{
			Return;
		}
		if (_PickupPtr != None)
		{
			HitActor=_PickupPtr;
			HitLocation=_PickupPtr.Location;
		}
		else
		{
			if (Instigator != None)
			{
				HitActor=Instigator;
				if (Instigator.bIsProne && Instigator.FrontAuxCyl != None)
				{
					HitLocation=Instigator.FrontAuxCyl.Location;
				}
				else
				{
					HitLocation=Instigator.GetBoneCoords('WeaponBone').Origin;
				}
			}
			else
			{
				DebugLog(DEBUG_Warn,"ThrowWeapon::Bone()	No Pickup/No Instigator. Don't know where to blow up!");
				GotoState('DestroyWeapon');
				Return;
			}
		}
		GH=Level.GetGrenadeHelper();
		GH.GrenHurtRadius(HitActor,HitLocation,_fDamageRadius,_fKillRadius,_fDamage,MyDamageType,FragDamageType,_fMomentum,DamageClasses,InstigatorController);
		GH.GrenadeEffects(HitActor,HitLocation,_fDamageRadius,_fKillRadius,_fEffectDuration,_fMaxAudIntensity,_fMaxVisIntensity);
		if (_PickupPtr != None)
		{
			DirectionalBlast(BlastDir);
			_PickupPtr._bBlewUp=True;
		}
		else
		{
			if (cExplosionEmitter != None)
			{
				Spawn(cExplosionEmitter,,,HitLocation,rot(16384 0 0));
			}
			if (cExplosionDecal != None)
			{
				Spawn(cExplosionDecal,,,HitLocation,vect(0 0 -1));
			}
			SoundOcclusion=1;
			PlaySound(BoomSound,3,1,True,1500,,True);
		}
		MakeNoise(_fHitNoise);
		_bBlewUp=True;
		_FuseTime=0;
		if (_PickupPtr == None)
		{
			if (cSmokeEmitter != None)
			{
				ThirdPersonActor.Destroy();
				ThirdPersonActor=None;
				SpawnPickup(True);
				_PickupPtr._bBlewUp=True;
				Instigator.TakeDamage(10,Instigator,Instigator.Location,vect(0 0 0),Class'Burned',,,Self);
			}
			if (Instigator.Weapon == Self)
			{
				Instigator.GrenadeThrow3p(Instigator.1);
				Instigator.DeleteInventory(Self);
				Instigator.PendingWeapon=None;
				Instigator.ChangedWeapon();
				if (GetNetMode() == ENetMode::NM_DedicatedServer)
				{
					ClientBlowUp();
				}
			}
		}
		ForEach AllActors(Class'NPCAICombatController',npcaiccIterator)
		{
			if (! npcaiccIterator.bDisableCombatController)
			{
				npcaiccIterator.NotifyDoorBreached(Location);
			}
			else
			{
			}
		}
		GotoState('DestroyWeapon');
	*/
}
void ADemo_DoorBreacher::DirectionalBlast(FVector BlastDirection)
{
	/*
		local FVector StartOffset;
		local float Scale;
		local FVector vVec;
		local FVector vMomentum;
		local FVector vDir;
		local Actor A;
		local Pawn p;
		local float fLen;
		local int Index;
		BlastDirection=Normal(BlastDirection);
		StartOffset=_PickupPtr.Location;
		for (Index=0; Index<DamageClasses.Length; Index++)
		{
			if (DamageClasses[Index] == None)
			{
			}
			ForEach VisibleCollidingActors(Class'Actor',A,DirectionalBlastRadius,StartOffset,True)
			{
				if (ClassIsChildOf(A.Class,DamageClasses[Index]))
				{
					p=Pawn(A);
					if (p != None)
					{
						vVec=p.Location - StartOffset;
						vDir=vVec;
						fLen=VSizeSquared(vVec);
						vVec=Normal(vVec);
						if (BlastDirection Dot vVec > DirectionalBlastCone && fLen < DirectionalBlastRadius * DirectionalBlastRadius)
						{
							Scale=1 - fLen / DirectionalBlastRadius * DirectionalBlastRadius;
							vMomentum += Scale * _fMomentum * vDir;
							if (p.IsHumanControlled())
							{
								if (fLen < DirectionalBlastRadius * DirectionalBlastRadius / 2)
								{
									p.CombatEffectivenessEvent(3);
								}
								PlayerController(p.Controller).GrenadeExploded(2,Scale);
							}
							p.TakeDamage(DirectionalBlastDamage * Scale,Instigator,vect(0 0 0),vMomentum,RadiusDamageType,,,Self);
						}
					}
					else
					{
						vVec=A.Location - StartOffset;
						fLen=VSizeSquared(vVec);
						vVec=Normal(vVec);
						if (BlastDirection Dot vVec > DirectionalBlastCone && fLen < DirectionalBlastRadius * DirectionalBlastRadius)
						{
							Scale=1 - fLen / DirectionalBlastRadius * DirectionalBlastRadius;
							A.TakeDamage(DirectionalBlastDamage * Scale,Instigator,vect(0 0 0),vect(0 0 0),RadiusDamageType,,,Self);
						}
					}
				}
			}
		}
	*/
}
