// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Demo_DoorBreacher/Demo_DoorBreacher.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_DoorBreacher_Demo/PickupT_DoorBreacher_Demo.h"
#include "AA29/Object/Actor/Inventory/Weapon\AGP_Weapon\ThrowWeapon\Throw_M67_Frag\Throw_MILES_Grenade\Throw_MILES_Grenade.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/AttachT_Demo_DoorBreacher/AttachT_Demo_DoorBreacher.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/BreacherExplosionDamage/BreacherExplosionDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/FragDamage/BreacherFragDamage.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/GrenadeHelper/GrenadeHelper.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/DamageType/Burned/Burned.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_door_breach_explosion/em_bt_door_breach_explosion.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_MILES_Grenade/Throw_MILES_Grenade.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"

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

	DamageClasses = {
		//AMover::StaticClass(),
		//Class'Engine.Pawn',
		//ABaseProjectile::StaticClass(),
		//AThrowWeaponPickup::StaticClass(),
		//ATriggers::StaticClass(),
		//ABodyPanel::StaticClass()
	};

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
	IconMaterial			= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_db_Mat.hud_wpn_db_Mat'"), NULL, LOAD_None, NULL);
	ItemName                = "Demolition Door Breacher";
	Mesh                    = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/DoorBreacher_1p.DoorBreacher_1p"), NULL, LOAD_None, NULL);
	DrawScale               = 1;
}

/*
simulated State PulledPin
{
	simulated Function ChangeFireMode()
	{
	}
	simulated Function bool PutDown()
	{
	}
	simulated Function Tick(float DeltaTime)
	{
		Global.H(DeltaTime);
		if (_bLostSpoon)
		{
			Cast<APlayerController>(Instigator.Controller).LockPlayer(false,false);
			PlayFiring();
			if (! _bBlewUp)
			{
				GotoState("Thrown");
			}
		}
		else
		{
			if ((GetNetMode() != ENetMode::NM_DedicatedServer) && _bPulledPin)
			{
				if ((! Instigator.PressingFire()) && (! Instigator.bIsDead))
				{
					Fire(0);
				}
				else
				{
					if (Instigator.PressingAltFire() && (! _bLostSpoon))
					{
						AltFire(0);
					}
				}
			}
		}
	}
	simulated Function AltFire(float Value)
	{
		Super::AltFire(Value);
	}
	Function ServerAltFire()
	{
		if (Level.debugGrenade)
		{
			Log("ThrowWeapon:PulledPin::ServerAltFire");
		}
		_bLostSpoon=true;
		SetFuseTime((_fMinFuseTime + (_fAddFuseTime * FMath::FRand())));
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (Level.debugGrenade)
		{
			Log("ThrowWeapon:PulledPin::AnimEnd Animation Complete");
		}
		_bPulledPin=true;
		if ((GetNetMode() != ENetMode::NM_DedicatedServer) && (! Instigator.bIsDead))
		{
			Fire(0);
		}
		Cast<APlayerController>(Instigator.Controller).LockPlayer(false,false);
	}
	Function ServerThrow()
	{
		Super::ServerThrow();
		BlastDir=Normal((Instigator.Location - SavedHitactor.Location));
		if (SavedHitactor->IsA(AMover::StaticClass()) && Cast<AMover>(SavedHitactor).bBreachable)
		{
			Mover(SavedHitactor).HandleBreachInfo(this);
		}
	}
	simulated Function Fire(float Value)
	{
		DebugLog(DEBUG_Gren,"ThrowWeapon::PulledPin::Fire()");
		if ((_bPulledPin && (! _bBlewUp)) && (! Instigator.bIsDead))
		{
			if ((Cast<AAGP_Pawn>(Instigator) != nullptr) && (Cast<AAGP_Pawn>(Instigator)._FireMonitor != nullptr))
			{
				Cast<AAGP_Pawn>(Instigator)._FireMonitor.Notify();
			}
			ServerThrow();
			if (GetWorld()->GetNetMode() == NM_Client)
			{
				GotoState("BusyFiring");
			}
		}
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Cast<APlayerController>(Instigator.Controller).LockPlayer(true,true);
		iPendingShots=0;
		_bActive=false;
		Enable("AnimEnd");
		Instigator.GrenadeThrow3p(Instigator.13);
		RunAnimation("Pull",1);
		PlayOwnedSound(PullSound,1,0.5,false,60,,true,false);
		InstigatorController=Instigator.Controller;
	}
}
*/

/*
simulated State BusyFiring
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		if (Level.debugGrenade)
		{
			Log("ThrowWeapon:Thrown::BeginState");
		}
		PlayFiring();
		if (! _bBlewUp)
		{
			GotoState("Thrown");
		}
	}
}
*/

/*
simulated State Thrown
{
	Function Fire(float Value)
	{
	}
	Function AltFire(float Value)
	{
	}
	Function Reload()
	{
	}
	Function ChangeFireMode()
	{
	}
	Function FixJam()
	{
	}
	simulated Function bool PutDown()
	{
		return true;
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (Instigator.Weapon == this)
		{
			Instigator.GrenadeThrow3p(Instigator.1);
			Instigator.DeleteInventory(this);
			Instigator.PendingWeapon=nullptr;
			Instigator.ChangedWeapon();
		}
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		if (Level.debugGrenade)
		{
			Log("ThrowWeapon:Thrown::BeginState");
		}
		if (GetNetMode() != ENetMode::NM_Client)
		{
			SpawnPickup();
		}
		Enable("AnimEnd");
		_bLostSpoon=true;
		_bTossNotThrow=false;
	}
}
*/

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
			if (Cast<AAGP_Pawn>(Instigator) != nullptr && Cast<AAGP_Pawn>(Instigator)._FireMonitor != nullptr)
			{
				Cast<AAGP_Pawn>(Instigator)._FireMonitor.Notify();
			}
			ServerFire();
		}
		else
		{
			return;
		}
	*/
}
void ADemo_DoorBreacher::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	UE_LOG(LogTemp, Warning, TEXT("Demo_DoorBreacher::ServerFire()"));
	/*
	if (CanPlaceDemolition())
	{
		ClientGotoState('PulledPin',"None");
		GotoState('PulledPin');
	}
	*/
}

bool ADemo_DoorBreacher::CanPlaceDemolition()
{
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector StartTrace = FVector(0, 0, 0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	AActor* HitActor = nullptr;
	//GetAxes(Instigator.GetViewRotation(), X, Y, Z);
	StartTrace = GetFireStart(X, Y, Z);
	EndTrace = (StartTrace + (X * fPlacementTraceDistance));
	//HitActor = Instigator.Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	if (GetNetMode() != ENetMode::NM_Client)
	{
		SavedHitactor = HitActor;
		SavedHitLocation = HitLocation;
		SavedPlacementNormal = HitNormal;
	}
	if ((HitActor != nullptr) && HitActor->IsA(ADecoMesh::StaticClass()))
	{
		return Cast<ADecoMesh>(HitActor)->bBreachable;
	}
	else
	{
		return false;
	}
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
	if (_bPulledPin)
	{
		//RunAnimation('Still',1,0.05,true);
	}
	else
	{
		//RunAnimation('Idle',1,0.05,true);
	}
}
void ADemo_DoorBreacher::PlaySelect()
{
	FName OutSeqName ="";
	float OutAnimFrame = 0;
	float OutAnimRate = 0;
	/*
	GetAnimParams(0,OutSeqName,OutAnimFrame,OutAnimRate);
	if (! IsAnimating() && ! AnimIsInGroup(0,'Select'))
	{
		RunAnimation('Select',1);
		PlayOwnedSound(SelectSound,1,0.5,false,60,,True,false);
	}
	else
	{
		if (IsAnimating() && OutSeqName == 'Still')
		{
			RunAnimation('Select',1);
			PlayOwnedSound(SelectSound,1,0.5,false,60,,True,false);
		}
	}
	*/
}
void ADemo_DoorBreacher::TweenDown()
{
	FName Anim = "";
	float frame = 0;
	float Rate = 0;
	/*
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
	FVector StartTrace = FVector(0,0,0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	int32 SpawnOffset = 0;
	/*
	GetAxes(Instigator.GetViewRotation(),X,Y,Z);
	StartTrace=GetFireStart(X,Y,Z);
	EndTrace=StartTrace + X * fPlacementTraceDistance;
	if (SetPickupPtr == nullptr)
	{
		_PickupPtr=ThrowWeaponPickup(Spawn(PickupClass,Self,"None",SavedHitLocation,SavedPlacementNormal * -1 + FRotator(0 -49152 16384)));
		_PickupPtr.InitDroppedPickupFor(this);
		if (_PickupPtr == nullptr && SpawnOffset < 20)
		{
			SpawnOffset += 2;
			_PickupPtr=ThrowWeaponPickup(Spawn(PickupClass,Self,"None",SavedHitLocation + SavedPlacementNormal * SpawnOffset,SavedPlacementNormal * -1 + FRotator(0 -49152 16384)));
			_PickupPtr.InitDroppedPickupFor(this);
		}
		if (_PickupPtr == nullptr)
		{
			GotoState('Idle');
		}
		else
		{
			_PickupPtr.bAlwaysRelevant=true;
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
	if (_PickupPtr != nullptr)
	{
		_PickupPtr.SetWeapon(this);
		_PickupPtr.SetDoorBreacherEmitter(Cast<ADecoMesh>(SavedHitactor).BreachedEmitter);
	}
	if (_bPulledPin && ! _bBlewUp && ! _bLostSpoon)
	{
		SetFuseTime(_fMinFuseTime + _fAddFuseTime * FMath::FRand());
		MakeNoise(1);
	}
	SetOwner(nullptr);
	*/
}
void ADemo_DoorBreacher::BlowUp()
{
	FVector HitLocation = FVector(0,0,0);
	AActor* HitActor = nullptr;
	AGrenadeHelper* GH = nullptr;
	ANPCAICombatController* npcaiccIterator = nullptr;
	/*
	if (Level.Game.bGameEnded)
	{
		return;
	}
	if (_PickupPtr != nullptr)
	{
		HitActor=_PickupPtr;
		HitLocation=_PickupPtr.Location;
	}
	else
	{
		if (Instigator != nullptr)
		{
			HitActor=Instigator;
			if (Instigator.bIsProne && Instigator.FrontAuxCyl != nullptr)
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
			return;
		}
	}
	GH=Level.GetGrenadeHelper();
	GH.GrenHurtRadius(HitActor,HitLocation,_fDamageRadius,_fKillRadius,_fDamage,MyDamageType,FragDamageType,_fMomentum,DamageClasses,InstigatorController);
	GH.GrenadeEffects(HitActor,HitLocation,_fDamageRadius,_fKillRadius,_fEffectDuration,_fMaxAudIntensity,_fMaxVisIntensity);
	if (_PickupPtr != nullptr)
	{
		DirectionalBlast(BlastDir);
		_PickupPtr._bBlewUp=true;
	}
	else
	{
		if (cExplosionEmitter != nullptr)
		{
			Spawn(cExplosionEmitter,,,HitLocation,FRotator(16384 0 0));
		}
		if (cExplosionDecal != nullptr)
		{
			Spawn(cExplosionDecal,,,HitLocation,FVector(0 0 -1));
		}
		SoundOcclusion=1;
		PlaySound(BoomSound,3,1,True,1500,,true);
	}
	MakeNoise(_fHitNoise);
	_bBlewUp=true;
	_FuseTime=0;
	if (_PickupPtr == nullptr)
	{
		if (cSmokeEmitter != nullptr)
		{
			ThirdPersonActor.Destroy();
			ThirdPersonActor=nullptr;
			SpawnPickup(true);
			_PickupPtr._bBlewUp=true;
			Instigator.TakeDamage(10,Instigator,Instigator->GetActorLocation(),FVector(0,0,0),ABurned::StaticClass(),,,Self);
		}
		if (Instigator.Weapon == this)
		{
			Instigator.GrenadeThrow3p(Instigator.1);
			Instigator.DeleteInventory(this);
			Instigator.PendingWeapon=nullptr;
			Instigator.ChangedWeapon();
			if (GetNetMode() == ENetMode::NM_DedicatedServer)
			{
				ClientBlowUp();
			}
		}
	}
	ForEach AllActors(ANPCAICombatController::StaticClass(),npcaiccIterator)
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
	FVector StartOffset = FVector(0,0,0);
	float Scale = 0;
	FVector vVec = FVector(0, 0, 0);
	FVector vMomentum = FVector(0, 0, 0);
	FVector vDir = FVector(0, 0, 0);
	AActor* A = nullptr;
	APawn* p = nullptr;
	float fLen = 0;
	int32 Index = 0;
	/*
	BlastDirection=Normal(BlastDirection);
	StartOffset=_PickupPtr.Location;
	for (Index=0; Index<DamageClasses.Num(); Index++)
	{
		if (DamageClasses[Index] == nullptr)
		{
		}
		ForEach VisibleCollidingActors(Class'Actor',A,DirectionalBlastRadius,StartOffset,True)
		{
			if (ClassIsChildOf(A.Class,DamageClasses[Index]))
			{
				p=Pawn(A);
				if (p != nullptr)
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
							Cast<APlayerController>(p.Controller).GrenadeExploded(2,Scale);
						}
						p.TakeDamage(DirectionalBlastDamage * Scale,Instigator,FVector(0,0,0),vMomentum,RadiusDamageType,,,Self);
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
						A.TakeDamage(DirectionalBlastDamage * Scale,Instigator,FVector(0,0,0),FVector(0,0,0),RadiusDamageType,,,Self);
					}
				}
			}
		}
	}
	*/
}
