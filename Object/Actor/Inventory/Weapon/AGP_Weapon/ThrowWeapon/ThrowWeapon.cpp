// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/BaseSmokeEmitter.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Projector/Projector.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/GrenadeHelper/GrenadeHelper.h"
#include "AA29/Object/DamageType/Burned/Burned.h"
#include "AA29/Object/Actor/Projector/BaseContactProjector/de_bt_grenimpact/de_bt_grenimpact.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_grenexplosion/em_bt_grenexplosion.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"

AThrowWeapon::AThrowWeapon()
{
	_fMinFuseTime      = 4;
	_fAddFuseTime      = 1.5;
	PullSound          = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Pull.WeaponsUS_Grenades_Pull"), NULL, LOAD_None, NULL);
	PullLowSound       = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Lowpull.WeaponsUS_Grenades_Lowpull"), NULL, LOAD_None, NULL);
	PopSpoonSound      = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Spoonpop.WeaponsUS_Grenades_Spoonpop"), NULL, LOAD_None, NULL);
	//cExplosionEmitter = Aem_bt_grenexplosion::StaticClass();
	//cExplosionDecal = Ade_bt_grenimpact::StaticClass();
	_fThrowSpeed       = 1145;
	_fThrowTime        = 0.2;
	_fTossSpeed        = 600;
	_fTossTime         = 0.2;
	InvGrenadeIndex    = 255;
	_bCanBeMiles       = false;
	SingleFire         = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Throw.WeaponsUS_Grenades_Throw"), NULL, LOAD_None, NULL);
	SelectChargeSound  = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_SelectNew.WeaponsUS_Grenades_SelectNew"), NULL, LOAD_None, NULL);
	SelectSound        = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_SelectNew.WeaponsUS_Grenades_SelectNew"), NULL, LOAD_None, NULL);
	DisplayFOV         = 50;
	_bLarge            = false;
	bVirtualInventory  = true;
	PlayerViewOffset   = FVector(3, 75, -3);
	InitialState       = FName("Idle");
}

/*
simulated State BusyRaisingWeapon
{
	simulated Function Tick(float DeltaTime)
	{
		Global.pnCurrentRoadPathNode(DeltaTime);
		if (Instigator.PressingFire())
		{
			bPressedFire=true;
		}
	}
}
*/

/*
simulated State Idle
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (bPressedFire)
		{
			Fire(0);
			bPressedFire=false;
		}
	}
}
*/

/*
simulated State PulledPin extends busy
{
	simulated Function ChangeFireMode()
	{
	}
	simulated Function bool PutDown()
	{
	}
	simulated Function Tick(float DeltaTime)
	{
		Global.pnCurrentRoadPathNode(DeltaTime);
		if (((GetNetMode() != ENetMode::NM_DedicatedServer) && _bPulledPin) && (Instigator != nullptr))
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
	simulated Function AltFire(float Value)
	{
		if (Level.debugGrenade)
		{
			Log("ThrowWeapon:PulledPin::AltFire");
		}
		if (Cast<AAGP_Pawn>(GetOwner()) != nullptr)
		{
			if (Cast<AAGP_Pawn>(GetOwner())->bIsSprinting)
			{
				DebugLog(DEBUG_Gren,"ThrowWeapon - user is sprinting, no pulling pin");
				return;
			}
		}
		if (_bUseAnimNotifyAltFire && (! IsAltFireNotified()))
		{
			return;
		}
		if (! _bLostSpoon)
		{
			_bLostSpoon=true;
			ServerAltFire();
		}
	}
	Function ServerAltFire()
	{
		if (Level.debugGrenade)
		{
			Log("ThrowWeapon:PulledPin::ServerAltFire");
		}
		DebugLog(DEBUG_Gren,"ThrowWeapon:PulledPin::ServerAltFire");
		if (Cast<AAGP_Pawn>(GetOwner()) != nullptr)
		{
			if (Cast<AAGP_Pawn>(GetOwner())->bIsSprinting)
			{
				DebugLog(DEBUG_Gren,"ThrowWeapon - user is sprinting, no pulling pin");
				return;
			}
		}
		_bLostSpoon=true;
		SetFuseTime((_fMinFuseTime + (_fAddFuseTime * FMath::FRand())));
		PlaySound(PopSpoonSound,1,0.5,,60,,true);
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (Level.debugGrenade)
		{
			Log("ThrowWeapon:PulledPin::AnimEnd Animation Complete");
		}
		DebugLog(DEBUG_Gren,"ThrowWeapon:PulledPin::AnimEnd Animation Complete");
		_bPulledPin=true;
		if ((GetNetMode() != ENetMode::NM_DedicatedServer) && ((Instigator == nullptr) || ((! Instigator.PressingFire()) && (! Instigator.bIsDead))))
		{
			Fire(0);
		}
	}
	simulated Function Fire(float Value)
	{
		DebugLog(DEBUG_Gren,"ThrowWeapon::PulledPin::Fire()");
		if (Cast<AAGP_Pawn>(GetOwner()) != nullptr)
		{
			if (Cast<AAGP_Pawn>(GetOwner())->bIsSprinting)
			{
				DebugLog(DEBUG_Gren,"ThrowWeapon - user is sprinting, no throwing");
				return;
			}
		}
		if ((_bPulledPin && (! _bBlewUp)) && (! Instigator.bIsDead))
		{
			DebugLog(DEBUG_Gren,"ThrowWeapon:PulledPin::Fire");
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
		DebugLog(DEBUG_Gren,string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		Super::BeginState();
		Instigator.GrenadeThrow3p(Instigator.9);
		if (! _bPulledPin)
		{
			if (_bTossNotThrow)
			{
				RunAnimation("LowPull",1);
				PlayOwnedSound(PullLowSound,1,0.5,false,60,,true,false);
			}
			else
			{
				RunAnimation("Pull",1);
				PlayOwnedSound(PullSound,1,0.5,false,60,,true,false);
			}
		}
		else
		{
			if (_bTossNotThrow)
			{
				RunAnimation("LiveLowPull",1);
			}
			else
			{
				RunAnimation("LivePull",1);
			}
		}
		InstigatorController=Instigator.Controller;
	}
Begin:
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
		AnimEnd(0);
	}
}
*/

/*
simulated State BusyFiring
{
	Function Pickup DropFrom(Vector StartLocation, bool bAttach)
	{
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		if (Level.debugGrenade)
		{
			Log(string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		DebugLog(DEBUG_Gren,string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		PlayFiring();
	}
	simulated Function Timer()
	{
		if (Level.debugGrenade)
		{
			Log(string(this) @ "ThrowWeapon:BusyFiring::Timer");
		}
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
	Function Pickup DropFrom(Vector StartLocation, bool bAttach)
	{
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		return false;
	}
	simulated Function bool PutDown()
	{
		return true;
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
		DebugLog(DEBUG_Gren,string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		if (GetNetMode() != ENetMode::NM_Client)
		{
			DebugLog(DEBUG_Gren,"Grenade thrown - pickup being spawned");
			SpawnPickup();
		}
		_bLostSpoon=true;
		_bTossNotThrow=false;
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (Level.debugGrenade)
		{
			Log("ThrowWeapon:Thrown::AnimEnd");
		}
		DebugLog(DEBUG_Gren,"ThrowWeapon:Thrown::AnimEnd");
		if ((Instigator != nullptr) && (Instigator.Weapon == this))
		{
			Instigator.DeleteInventory(this);
			Instigator.PendingWeapon=nullptr;
			Instigator.ChangedWeapon();
		}
	}
}
*/

/*
simulated State DestroyWeapon
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
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function bool PutDown()
	{
		return true;
	}
Begin:
	if ((Instigator != nullptr) && (Instigator.Weapon == this))
	{
		Instigator.DeleteInventory(this);
		Instigator.PendingWeapon=nullptr;
		Instigator.ChangedWeapon();
		Instigator.GrenadeThrow3p(Instigator.1);
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			ClientBlowUp();
		}
	}
	Destroy();
}
*/

/*
simulated State PickedUpLive extends Idle
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "ThrowWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		Super::BeginState();
		if (_PickupPtr != nullptr)
		{
			_PickupPtr.Destroy();
			_PickupPtr=nullptr;
		}
	}
	simulated Function bool PutDown()
	{
		return false;
	}
}
*/

void AThrowWeapon::Destroyed()
{
	Super::Destroyed();
	PullSound=NULL;
	PullLowSound= NULL;
	BoomSound= NULL;
	PopSpoonSound= NULL;
	InstigatorController= NULL;
	_PickupPtr= NULL;
}
EUpperBodyAnim AThrowWeapon::GetUpperBodyLowerAnim()
{
	return EUpperBodyAnim::UBANIM_GREN_LowerGn;
}
EUpperBodyAnim AThrowWeapon::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_GREN_RaiseGn;
}
EUpperBodyAnim AThrowWeapon::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_GREN_Ready;
}
void AThrowWeapon::Reload()
{
}
void AThrowWeapon::FixJam()
{
}
void AThrowWeapon::InitFor(AInventory* Inv)
{
}

AAmmunition* AThrowWeapon::SpawnAmmoFor(AAGP_Weapon* OldW, AAmmunition* oldA)
{
	return nullptr;     //FAKE   /ELiZ
}

void AThrowWeapon::SpawnAndAttachMILESGear()
{
}

void AThrowWeapon::TempLowerWeapon(bool bActive)
{
	/*
		if (! IsLostSpoon() && ! IsPinPulled())
		{
			TempLowerWeapon(bActive);
		}
	*/
}
bool AThrowWeapon::IsPinPulled()
{
	return _bPulledPin;
}
bool AThrowWeapon::isHandsOnly()
{
	return IsPinPulled();
}
bool AThrowWeapon::IsLostSpoon()
{
	return _bLostSpoon;
}
bool AThrowWeapon::IsTossNotThrow()
{
	return _bTossNotThrow;
}
void AThrowWeapon::SetFuseTime(float Time)
{
	_FuseTime=Time;
	_FuseCounter=0;
}
void AThrowWeapon::Tick(float DeltaTime)
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
void AThrowWeapon::RecountAmmo()
{
	AmmoMagCount=0;
}
bool AThrowWeapon::ShouldDrawCrosshair()
{
	return false;
}
void AThrowWeapon::HandleLive(APawn* NewInstigator)
{
	//Instigator=NewInstigator;
	_bPulledPin=true;
	_bLostSpoon=true;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		FString ObjectName = GetOwner()->GetName();
		UE_LOG(LogTemp, Log, TEXT("The %s is live!  Careful!"), *ObjectName);
	}
}
void AThrowWeapon::Finish()
{
	/*
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponState)
		{
			Log(Self @ "ThrowWeapon::Finish - Instigator" @ Instigator @ "Controller" @ Instigator.Controller);
		}
		if (Instigator == nullptr || Instigator.Controller == nullptr)
		{
			GotoState("None");
			return;
		}
		if (_bLostSpoon)
		{
			GotoState('PickedUpLive');
		}
		else
		{
			GotoState('Idle');
		}
	*/
}
void AThrowWeapon::ClientFinish()
{
	/*
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugWeaponState)
		{
			Log(Self @ "ThrowWeapon::ClientFinish - Instigator" @ Instigator @ "Controller" @ Instigator.Controller);
		}
		if (Instigator == nullptr || Instigator.Controller == nullptr)
		{
			GotoState("None");
			return;
		}
		if (_bLostSpoon)
		{
			GotoState('PickedUpLive');
		}
		else
		{
			GotoState('Idle');
		}
	*/
}
void AThrowWeapon::Fire(float Value)
{
	/*
		if (Instigator != nullptr)
		{
			if (Instigator.Controller != nullptr)
			{
				Log("----- " + Instigator.Controller + ".Location = " + Instigator.Controller.Location + " -----");
				if (Cast<APlayerController>(Instigator.Controller) != nullptr)
				{
					Log("----- " + Instigator.Controller + ".ViewTarget = " + PlayerController(Instigator.Controller).ViewTarget + " -----");
				}
			}
			Log("----- " + Instigator + ".Location = " + Instigator.Location + " -----");
		}
		*/
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			FString ObjectName = GetOwner()->GetName();
			UE_LOG(LogTemp, Log, TEXT("%s ThrowWeapon:Global::Fire"), *ObjectName);
		}
		/*
		if (Cast<AAGP_Pawn>(Instigator) != nullptr && Cast<AAGP_Pawn>(Instigator)._FireMonitor != nullptr)
		{
			Cast<AAGP_Pawn>(Instigator)._FireMonitor.Notify();
		}
		if (Instigator != nullptr && Instigator.bIsSprinting || Instigator.bWantsToSprint)
		{
			return;
		}
		ServerFire();
		if (GetNetMode() == ENetMode::NM_Client)
		{
			GotoState('PulledPin');
		}
	*/
}
void AThrowWeapon::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
		UE_LOG(LogTemp, Warning, TEXT("ThrowWeapon::ServerFire()"));
		/*
		if (Instigator != nullptr)
		{
			if (Instigator.Controller != nullptr)
			{
				Log("----- " + Instigator.Controller + ".Location = " + Instigator.Controller.Location + " -----");
				if (Cast<APlayerController>(Instigator.Controller) != nullptr)
				{
					Log("----- " + Instigator.Controller + ".ViewTarget = " + PlayerController(Instigator.Controller).ViewTarget + " -----");
				}
			}
			Log("----- " + Instigator + ".Location = " + Instigator.Location + " -----");
		}
		if (Instigator != nullptr && Instigator.bIsSprinting || Instigator.bWantsToSprint)
		{
			return;
		}
		GotoState('PulledPin');
	*/
}
void AThrowWeapon::ServerThrow()
{
	/*
		APlayerController* PC = nullptr;
		if (Instigator == nullptr || Instigator.isDead())
		{
			DebugLog(DEBUG_Gren,"ThrowWeapon::ServerThrow()	Instigator is dead. Dropping should handle this.");
			return;
		}
		_bPulledPin=true;
		GotoState('BusyFiring');
		PC=Cast<APlayerController>(Instigator.Controller);
		if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredGrenade();
		}
	*/
}
void AThrowWeapon::DoChangeFireMode()
{
	_bTossNotThrow=! _bTossNotThrow;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		UE_LOG(LogTemp, Log, TEXT("ThrowWeapon::DoChangeFireMode %s"), _bTossNotThrow ? TEXT("true") : TEXT("false"));
	}
}
void AThrowWeapon::PlayChangeFireMode()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		UE_LOG(LogTemp, Log, TEXT("ThrowWeapon::PlayChangeFireMode Live %s Toss %s"),_bLostSpoon ? TEXT("true") : TEXT("false"), _bTossNotThrow ? TEXT("true") : TEXT("false"));
	}
	if (_bLostSpoon)
	{
		if (! _bTossNotThrow)
		{
			//RunAnimation('LiveHighToLow',1);
		}
		else
		{
			//RunAnimation('LiveLowToHigh',1);
		}
	}
	else
	{
		if (! _bTossNotThrow)
		{
			//RunAnimation('HighToLow',1);
		}
		else
		{
			//RunAnimation('LowToHigh',1);
		}
	}
}

void AThrowWeapon::BlowUp()
{
	FVector HitLocation = FVector(0,0,0);
	AActor* HitActor = nullptr;
	AGrenadeHelper* GH = nullptr;
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
				DebugLog(DEBUG_Warn,"ThrowWeapon::BlowUp()	No Pickup/No Instigator. Don't know where to blow up!");
				GotoState('DestroyWeapon');
				return;
			}
		}
		GH=Level.GetGrenadeHelper();
		GH.GrenHurtRadius(HitActor,HitLocation,_fDamageRadius,_fKillRadius,_fDamage,MyDamageType,FragDamageType,_fMomentum,DamageClasses,InstigatorController);
		GH.GrenadeEffects(HitActor,HitLocation,_fDamageRadius,_fKillRadius,_fEffectDuration,_fMaxAudIntensity,_fMaxVisIntensity);
		if (_PickupPtr != nullptr)
		{
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
			PlaySound(BoomSound,3,1,True,1500,,true);
		}
		MakeNoise(_fHitNoise);
		_bBlewUp=true;
		_FuseTime=0;
		if (_PickupPtr == nullptr)
		{
			if (cSmokeEmitter != nullptr)
			{
				if (ThirdPersonActor != nullptr)
				{
					ThirdPersonActor.Destroy();
					ThirdPersonActor=nullptr;
				}
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
		GotoState('DestroyWeapon');
	*/
}

void AThrowWeapon::ClientBlowUp()
{
	_bBlewUp=true;
	//GetInstigator()->GrenadeThrow3p(Instigator.1);
}

FVector AThrowWeapon::GetFireStart(FVector X, FVector Y, FVector Z)
{
	//return Instigator.EyePosition();
	return FVector(0, 0, 0);
}

void AThrowWeapon::SpawnPickup(bool bDrop, AThrowWeaponPickup* SetPickupPtr)
{
	FVector StartLoc = FVector(0,0,0);
	FVector X = FVector(0,0,0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	float fpAdjustedThrowSpeed = 0;
	FRotator rotTemp = FRotator(0,0,0);
	/*
		if (Owner != nullptr && Cast<AAGP_Pawn>(GetOwner()) != nullptr && Cast<AAGP_Pawn>(GetOwner())->EventLab != nullptr && EventLab == nullptr)
		{
			EventLab=Cast<AAGP_Pawn>(GetOwner())->EventLab;
		}
		if (_PickupPtr != nullptr)
		{
			return;
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup bDrop" @ bDrop @ "SetPickupPtr" @ SetPickupPtr);
		if (Instigator.Controller != nullptr && Instigator.Controller->IsA(ANPCBaseSoldierController::StaticClass()))
		{
			rotTemp=Instigator.GetViewRotation();
			rotTemp.Pitch=NPCBaseSoldierController(Instigator.Controller).GetGrenadePitch();
			GetAxes(rotTemp,X,Y,Z);
			DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup for NPC rotation: (PRY): " + rotTemp.Pitch + "," + rotTemp.Roll + "," + rotTemp.Yaw);
		}
		else
		{
			DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup rotation: (PRY): " + Instigator.GetViewRotation().Pitch + "," + Instigator.GetViewRotation().Roll + "," + Instigator.GetViewRotation().Yaw);
			GetAxes(Instigator.GetViewRotation(),X,Y,Z);
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup Instigator is: " + Instigator);
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup Axes/rotation: " + X + "," + Y + "," + Z);
		if (Instigator.Controller != nullptr && Instigator.Controller->IsA(ANPCBaseController::StaticClass()))
		{
			StartLoc=FVector(Instigator.Location.X,Instigator.Location.Y,Instigator.Location.Z + 48);
			DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup StartLoc set to instigator (pawn) location");
		}
		else
		{
			StartLoc=GetFireStart(X,Y,Z);
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup PickupClass: " + PickupClass);
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon:Thrown::SpawnPickup Start location: " + StartLoc.X + "," + StartLoc.Y + "," + StartLoc.Z);
		if (SetPickupPtr == nullptr)
		{
			_PickupPtr=ThrowWeaponPickup(Spawn(PickupClass,Self,"None",StartLoc));
			_PickupPtr.bShowThreatenedNodes=bShowThreatenedNodes;
		}
		else
		{
			_PickupPtr=SetPickupPtr;
		}
		DebugLog(DEBUG_Gren,"ThrowWeapon::SpawnPickup() - Pickupptr is: " + _PickupPtr);
		if (_PickupPtr != nullptr)
		{
			_PickupPtr.InitDroppedPickupFor(this);
			_PickupPtr.bAlwaysRelevant=true;
		}
		fpAdjustedThrowSpeed=_fThrowSpeed;
		if (Instigator.Controller != nullptr && Instigator.Controller->IsA(ANPCBaseController::StaticClass()))
		{
			fpAdjustedThrowSpeed += FMath::FRand() * 100;
		}
		if (EventLab != nullptr)
		{
			_PickupPtr.SetEventLab(EventLab);
		}
		if (bDrop)
		{
			_PickupPtr.Velocity=VRand() * 200;
		}
		else
		{
			if (_bTossNotThrow)
			{
				_PickupPtr.Velocity=X * _fTossSpeed;
			}
			else
			{
				_PickupPtr.Velocity=X * fpAdjustedThrowSpeed;
			}
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon::SpawnPickup Ptr" @ _PickupPtr @ "Vel" @ _PickupPtr.Velocity);
		if (_PickupPtr != nullptr)
		{
			_PickupPtr.SetWeapon(this);
			_PickupPtr.RandSpin(100000);
			if (Instigator.bIsCrouched)
			{
				_PickupPtr.Velocity *= 0.95;
			}
			else
			{
				if (Instigator.bIsProne)
				{
					_PickupPtr.Velocity *= 0.85;
				}
			}
		}
		DebugLog(DEBUG_Gren,Self @ "ThrowWeapon::SpawnPickup PulledPin" @ _bPulledPin @ "BlewUp" @ _bBlewUp @ "LostSpoon" @ _bLostSpoon);
		if (_bPulledPin && ! _bBlewUp && ! _bLostSpoon)
		{
			SetFuseTime(_fMinFuseTime + _fAddFuseTime * FMath::FRand());
			PlayOwnedSound(PopSpoonSound,1,0.5,false,60,,True,false);
		}
		if (_bPulledPin && Instigator.isDead())
		{
			SetFuseTime(_fMinFuseTime + _fAddFuseTime * FMath::FRand());
			PlayOwnedSound(PopSpoonSound,1,0.5,false,60,,True,false);
		}
		SetOwner(nullptr);
	*/
}

void AThrowWeapon::TweenDown()
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
		if (_bPulledPin)
		{
			if (_bTossNotThrow)
			{
				RunAnimation('LiveLowDown',1,0.05);
			}
			else
			{
				RunAnimation('LiveDown',1,0.05);
			}
		}
		else
		{
			if (_bTossNotThrow)
			{
				RunAnimation('LowDown',1,0.05);
			}
			else
			{
				RunAnimation('Down',1,0.05);
			}
		}
	}
	*/
}

void AThrowWeapon::PlaySelect()
{
	int32 RandNum = 0;
	FName OutSeqName = "";
	float OutAnimFrame = 0;
	float OutAnimRate = 0;
	/*

		GetAnimParams(0,OutSeqName,OutAnimFrame,OutAnimRate);
		if (! IsAnimating() && ! AnimIsInGroup(0,'Select'))
		{
			if (_bPulledPin)
			{
				RunAnimation('LiveSelect',1);
			}
			else
			{
				if (_bTossNotThrow)
				{
					RunAnimation('LowSelect',1);
				}
				else
				{
					if (HasAnim('SelectB'))
					{
						RandNum=Rand(2);
						if (RandNum == 1)
						{
							RunAnimation('Select',1);
						}
						else
						{
							RunAnimation('SelectB',1);
						}
					}
					else
					{
						RunAnimation('Select',1);
					}
				}
			}
			PlayOwnedSound(SelectSound,1,0.5,false,60,,True,false);
		}
		else
		{
			if (IsAnimating() && OutSeqName == 'Still')
			{
				if (_bPulledPin)
				{
					RunAnimation('LiveSelect',1);
				}
				else
				{
					if (HasAnim('SelectB'))
					{
						RandNum=Rand(2);
						if (RandNum == 1)
						{
							RunAnimation('Select',1);
						}
						else
						{
							RunAnimation('SelectB',1);
						}
					}
					else
					{
						RunAnimation('Select',1);
					}
				}
				PlayOwnedSound(SelectSound,1,0.5,false,60,,True,false);
			}
		}
	*/
}

void AThrowWeapon::PlayIdleAnim()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
	{
		UE_LOG(LogTemp, Log, TEXT("ThrowWeapon::PlayIdleAnim Toss %s Live %s"), _bTossNotThrow ? TEXT("true") : TEXT("false"), _bPulledPin ? TEXT("true") : TEXT("false"));
	}
	if (_bTossNotThrow)
	{
		if (_bPulledPin)
		{
			//RunAnimation('LiveLowStill',1,0.05,true);
		}
		else
		{
			//RunAnimation('LowIdle',1,0.05,true);
		}
	}
	else
	{
		if (_bPulledPin)
		{
			//RunAnimation('LiveStill',1,0.05,true);
		}
		else
		{
			//RunAnimation('Idle',1,0.05,true);
		}
	}
}

void AThrowWeapon::PlayFiring()
{
	/*
	if (Cast<AAGP_Pawn>(Instigator) != nullptr)
	{
		Cast<AAGP_Pawn>(Instigator).NotifyThrow(this,"THROWN");
	}
	if (_bTossNotThrow)
	{
		PlayAnim('LowFire');
		SetTimer(_fTossTime,false);
	}
	else
	{
		PlayAnim('Fire');
		SetTimer(_fThrowTime,false);
	}
	PlayOwnedSound(SingleFire,1,0.5,false,60,,True,false);
	if (_bTossNotThrow)
	{
		Instigator.GrenadeThrow3p(Instigator.8);
	}
	else
	{
		Instigator.GrenadeThrow3p(Instigator.7);
	}
	*/
}
void AThrowWeapon::StartCrawling()
{
	if (IsPinPulled())
	{
		return;
	}
	Super::StartCrawling();
}
