// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"
#include "AA29/Object/Actor/Triggers/DamageTrigger/DamageTrigger.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/DamageType/Impact/Impact.h"
#include "AA29/Object/Actor/Controller/AIController/AgentController/AgentController.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/BaseSmokeEmitter.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "Particles/Emitter.h"

AThrowWeaponPickup::AThrowWeaponPickup()
{

	sWood = {
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood1.WeaponsUS_Grenades_GrenadeBounceWood1"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood2.WeaponsUS_Grenades_GrenadeBounceWood2"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood3.WeaponsUS_Grenades_GrenadeBounceWood3"), NULL, LOAD_None, NULL)
	};

	sDirt = {
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceDirt1.WeaponsUS_Grenades_GrenadeBounceDirt1"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceDirt2.WeaponsUS_Grenades_GrenadeBounceDirt2"), NULL, LOAD_None, NULL),
	LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceDirt3.WeaponsUS_Grenades_GrenadeBounceDirt3"), NULL, LOAD_None, NULL)
	};

	sMetal = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceMetal1.WeaponsUS_Grenades_GrenadeBounceMetal1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceMetal2.WeaponsUS_Grenades_GrenadeBounceMetal2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceMetal3.WeaponsUS_Grenades_GrenadeBounceMetal3"), NULL, LOAD_None, NULL)
	};

	sMuffled = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadebounceMuffled1.WeaponsUS_Grenades_GrenadebounceMuffled1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadebounceMuffled2.WeaponsUS_Grenades_GrenadebounceMuffled2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadebounceMuffled3.WeaponsUS_Grenades_GrenadebounceMuffled3"), NULL, LOAD_None, NULL)
	};

	_fBounceDamp = 0.4;
	_fBounceSpin = 40000;
	_sImpactSounds = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Grenadebounce1.WeaponsUS_Grenades_Grenadebounce1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Grenadebounce2.WeaponsUS_Grenades_Grenadebounce2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Grenadebounce3.WeaponsUS_Grenades_Grenadebounce3"), NULL, LOAD_None, NULL)
	};
	bAttachMILESBox      = false;
	bOnlyReplicateHidden = false;
	PickupMessage        = FString("You found a thrown weapon.");
	PickupSound          = LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_SelectNew.WeaponsUS_Grenades_SelectNew"), NULL, LOAD_None, NULL);
	DrawType             = EDrawType::DT_StaticMesh;
	//bAlwaysTestCollision = false;
	//RemoteRole = 2
	//NetUpdateFrequency = 16
	LandedRotationOffset = FRotator(0, 0, 0);
		//CollisionRadius = 3;
		//CollisionHeight = 2;
		//bBounce = true;
		//bRotateToDesired = true;
}

/*
auto State Pickup
{
	Function bool ValidTouch(AActor* Other)
	{
		if (_bIsLive && (Other->IsA(APawn::StaticClass()) && Pawn(Other).IsHumanControlled()))
		{
			return false;
		}
		else
		{
			return Super::ValidTouch(Other);
		}
	}
	Function bool ForceRealInventory(APawn* p)
	{
		return Cast<AAGP_Pawn>(p).AreHandsEmpty();
	}
}
*/

void AThrowWeaponPickup::SetDoorBreacherEmitter(AEmitter* EM)
{
}

void AThrowWeaponPickup::StaticPrecache(ALevelInfo* L)
{
	/*
	if (Default.liveStaticMesh != nullptr)
	{
		L.AddPrecacheStaticMesh(Default.liveStaticMesh);
	}
	Super::StaticPrecache(L);
	*/
}

void AThrowWeaponPickup::RandSpin(float spinRate)
{
	/*
	DesiredRotation=RotRand();
	RotationRate.Yaw=spinRate * 2 * FMath::FRand() - spinRate;
	RotationRate.Pitch=spinRate * 2 * FMath::FRand() - spinRate;
	RotationRate.Roll=spinRate * 2 * FMath::FRand() - spinRate;
	*/
}
void AThrowWeaponPickup::Destroyed()
{
	Super::Destroyed();
	if (DamageArea != nullptr)
	{
		DamageArea->Destroy();
		DamageArea=nullptr;
	}
}
bool AThrowWeaponPickup::IsLive()
{
	return _bIsLive;
}
void AThrowWeaponPickup::PostBeginPlay()
{
	AThrowWeapon* W = nullptr;
	/*
	PostBeginPlay();
	W=class<ThrowWeapon>(InventoryType);
	if (W != nullptr && W.Default.cSmokeEmitter != nullptr)
	{
		_EffectDuration=RandRange(W.Default.cSmokeEmitter.Default.Duration.Min,W.Default.cSmokeEmitter.Default.Duration.Max);
	}
	else
	{
		_EffectDuration=0;
	}
	*/
}
void AThrowWeaponPickup::SetWeapon(AThrowWeapon* W)
{
	/*
	Inventory=W;
	_bIsLive=true;
	SetStaticMesh(liveStaticMesh);
	if (LiveMesh != nullptr)
	{
		LinkMesh(LiveMesh);
	}
	*/
}

void AThrowWeaponPickup::InitDroppedPickupFor(AInventory* Inv, bool bFreeze)
{
	AThrowWeapon* W = nullptr;
	W=Cast<AThrowWeapon>(Inv);
	if (W != nullptr && W->IsPinPulled())
	{
		W->SpawnPickup(true,this);
	}
	Super::InitDroppedPickupFor(Inv,bFreeze);
}

void AThrowWeaponPickup::AgentControllerFearMe()
{
	AAgentController* AC = nullptr;
	float fGrenadeAwareDistance = 0;
	FVector vVec = FVector(0,0,0);
	float fLen = 0;
	fGrenadeAwareDistance = 1024;
	/*
	ForEach DynamicActors('AgentController',AC)
	{
		vVec=Location - AC.Location;
		fLen=VSize(vVec);
		if (fLen < fGrenadeAwareDistance)
		{
			AC.FearGrenade=Self;
		}
	}
	*/
}

void AThrowWeaponPickup::AgentControllerRemoveFearMe()
{
	for (TActorIterator<AAgentController> Itr(GetWorld()); Itr; ++Itr)
	{
		Cast<AAgentController>(*Itr)->FearGrenade = nullptr;
	}
}

void AThrowWeaponPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (_bBlewUp && ! _bBlewUpProcessed)
	{
		_bBlewUpProcessed=true;
		ProcessBlewUp();
	}
	else
	{
		if (! _bBlewUpProcessed)
		{
			AgentControllerFearMe();
		}
	}
}
void AThrowWeaponPickup::DeleteProjectile()
{
	/*
	if (Owner != nullptr)
	{
		Owner.GotoState('DestroyWeapon');
	}
	LifeSpan=1;
	SetDrawType(0);
	SetPhysics(0);
	Velocity=FVector(0,0,0);
	SetCollision(false,false,false);
	Disable('Tick');
	*/
}

void AThrowWeaponPickup::ProcessBlewUp()
{
	AThrowWeapon* W = nullptr;
	ANPCPathNode* npcpn = nullptr;
	float fpThreatenedNodeDistance = 0;
	/*
	W=class<ThrowWeapon>(InventoryType);
	if (W != nullptr)
	{
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			if (W.Default.cExplosionEmitter != nullptr)
			{
				Spawn(W.Default.cExplosionEmitter,,,Location,FRotator(16384 0 0));
			}
			if (W.Default.cExplosionDecal != nullptr)
			{
				Spawn(W.Default.cExplosionDecal,,,Location,FVector(0 0 -1));
			}
			SpawnSmokeEmitter(W);
			PlayOwnedSound(W.Default.BoomSound,3,1,True,1500,,true);
		}
		if (GetNetMode() != ENetMode::NM_Client)
		{
			SpawnDamageArea(W);
		}
	}
	if (_EffectDuration > 0)
	{
		LifeSpan=_EffectDuration + 1;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			LifeSpan /= 2;
		}
	}
	else
	{
		LifeSpan=1;
		bHidden=true;
	}
	if (! IsA('PickupT_M83_Smoke'))
	{
		fpThreatenedNodeDistance=W.Default._fKillRadius + W.Default._fDamageRadius;
		ForEach RadiusActors('NPCPathNode',npcpn,fpThreatenedNodeDistance,Location)
		{
			if (bShowThreatenedNodes)
			{
				npcpn.DebugNavMarker(false,false);
			}
			npcpn.FearCost=0;
		}
	}
	*/
}

void AThrowWeaponPickup::SpawnSmokeEmitter(AThrowWeapon*  W)
{
	ABaseSmokeEmitter* SmokeGenerator = nullptr;
	/*
	if (W.Default.cSmokeEmitter != nullptr)
	{
		SmokeGenerator=Spawn(W.Default.cSmokeEmitter,Self,,Location,FRotator(16384 0 0));
		SmokeGenerator.SetBase(this);
		SmokeGenerator.PickupPtr=Self;
		SmokeGenerator._EffectDuration=_EffectDuration;
	}
	*/
}

void AThrowWeaponPickup::SpawnDamageArea(AThrowWeapon*  W)
{
	/*
	if (W.Default.SmokeDamageType != nullptr && Role == 4)
	{
		DamageArea=Spawn('DamageTrigger',Self);
		DamageArea.InitializeFor(this);
	}
	*/
}

void AThrowWeaponPickup::Landed(FVector HitNormal)
{
	AController* ctrlIterator = nullptr;
	ANPCPathNode* npcpn = nullptr;
	AThrowWeapon*  W = nullptr;
	float fpThreatenedNodeDistance = 0;
	if (DamageArea != nullptr)
	{
		DamageArea->NotifyLanded(this);
	}
	/*
	W = class<ThrowWeapon>(InventoryType);
	Super::Landed(HitNormal);
	if (VSize(Velocity) < float(20))
	{
		SetPhysics(PHYS_None);
	}
	else
	{
		HitWall(HitNormal, nullptr);
	}
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (ctrlIterator->IsA(ANPCBaseController::StaticClass()))
		{
			NPCBaseController(ctrlIterator).NotifyGrenadeLanded(this);
		}
	}
	if (!IsA("PickupT_M83_Smoke"))
	{
		if ((_bIsLive && (W != nullptr)) && (W.Default._fDamage > float(50)))
		{
			fpThreatenedNodeDistance = (W.Default._fKillRadius + W.Default._fDamageRadius);
			ForEach RadiusActors(ANPCPathNode::StaticClass(), npcpn, fpThreatenedNodeDistance, Location)
			{
				npcpn.FearCost = int((float(5000) * (1 - (VSize((npcpn.Location - Location)) / fpThreatenedNodeDistance))));
				if (bShowThreatenedNodes)
				{
					npcpn.DebugNavMarker(true, false);
				}
			}
		}
	}
	*/
}

void AThrowWeaponPickup::HitWall(FVector HitNormal, AActor* Wall)
{
	ADecoMesh* DM = nullptr;
	FVector HitLoc = FVector(0,0,0);
	FVector HitNorm = FVector(0, 0, 0);
	UMaterialInstance* HitMaterial = nullptr;
	int32 PolyFlags = 0;
	/*
	if (! bBounce)
	{
		return;
	}
	if (Wall != nullptr && Wall->IsA(ADecoMesh::StaticClass()))
	{
		DM=DecoMesh(Wall);
		if (DM.bInstantGrenBreak && DM.DamageHealth > 0)
		{
			DM.TakeDamage(DM.InitialDamageHealth * 1000,Instigator,DM->GetActorLocation(),FVector(0,0,0),AImpact::StaticClass(),,,Self);
			return;
		}
	}
	if (! bPlacedPickup)
	{
		Trace(HitLoc,HitNorm,Location + Velocity * 1000,Location,True,FVector(0,0,0),HitMaterial,PolyFlags);
		if (PFlag_DeleteProjectiles(PolyFlags))
		{
			DeleteProjectile();
			return;
		}
		else
		{
			if (GetNetMode() != ENetMode::NM_DedicatedServer)
			{
				if (HitMaterial != nullptr)
				{
					PlayLandedSound(HitMaterial);
				}
				else
				{
					PlaySound(_sImpactSounds[Rand(_sImpactSounds.Num())],1,1.5,,150,,true);
				}
			}
		}
	}
	Velocity=MirrorVectorByNormal(Velocity,HitNormal) * GetMaterialBounceDamp(HitMaterial);
	RandSpin(_fBounceSpin);
	if (VSize(Velocity) < 20)
	{
		bBounce=false;
	}
	*/
}
void AThrowWeaponPickup::Touch(AActor* Other)
{
	FVector HitNormal = FVector(0,0,0);
	FVector HitLocation = FVector(0, 0, 0);
	UMaterialInstance* HitMaterial = nullptr;
	AActor* HitActor = nullptr;
	/*
	if (Other == nullptr)
	{
		return;
	}
	if (VSize(Velocity) == 0)
	{
		return;
	}
	if (Other.bBlockActors && Other.bProjTarget || Other.bBlockActors && Other.bBlockPlayers)
	{
		if (Instigator != nullptr && Other != Instigator && Other != Instigator.FrontAuxCyl && Other != Instigator.BackAuxCyl)
		{
			HitActor=Trace(HitLocation,HitNormal,Location + Velocity,Location,True,FVector(0,0,0),HitMaterial);
			if (HitActor == nullptr)
			{
				HitActor=Trace(HitLocation,HitNormal,Location + Velocity,Location,True,FVector(CollisionRadius,CollisionRadius,CollisionHeight),HitMaterial);
			}
			HitWall(HitNormal,Other);
		}
	}
	*/
}
void AThrowWeaponPickup::PlayLandedSound(UTexture2D* HitMaterial)
{
	USoundBase* S = nullptr;
	/*
	switch(HitMaterial.GetMaterialType())
	{
		case 0:
			return;
		case 18:
		case 19:
		case 20:
		case 1:
			S=sWood[Rand(sWood.Num())];
			break;
		case 2:
			S=sDirt[Rand(sDirt.Num())];
			break;
		case 3:
			S=sDirt[Rand(sDirt.Num())];
		break;
		case 21:
		case 22:
		case 23:
		case 4:
			S=sMetal[Rand(sMetal.Num())];
			break;
		case 5:
			S=sMetal[Rand(sMetal.Num())];
			break;
		case 6:
			S=_sImpactSounds[Rand(_sImpactSounds.Num())];
			break;
		case 7:
			S=sMuffled[Rand(sMuffled.Num())];
			break;
		case 8:
			break;
		case 9:
			S=sDirt[Rand(sDirt.Num())];
			break;
		case 10:
			S=sMetal[Rand(sMetal.Num())];
			break;
		case 11:
			S=sWood[Rand(sWood.Num())];
			break;
		case 12:
			S=sMuffled[Rand(sMuffled.Num())];
			break;
		case 13:
			S=sMuffled[Rand(sMuffled.Num())];
			break;
		case 14:
			S=sDirt[Rand(sDirt.Num())];
			break;
		case 15:
			S=sDirt[Rand(sDirt.Num())];
			break;
		case 16:
			S=sDirt[Rand(sDirt.Num())];
			break;
		case 17:
			S=sMetal[Rand(sMetal.Num())];
			break;
		default:
			break;
	}
	PlayOwnedSound(S,1,0.4,,300,,true);
	*/
}

float AThrowWeaponPickup::GetMaterialBounceDamp(UTexture2D* HitMaterial)
{
	float Damp = 0;
	Damp = _fBounceDamp;
	/*
	if (HitMaterial == nullptr)
	{
		return Damp;
	}
	switch(HitMaterial.GetMaterialType())
	{
		case 10:
		case 21:
		case 22:
		case 23:
		case 4:
			Damp *= 1.25;
			break;
		case 6:
			Damp *= 1.125;
			break;
		case 17:
		case 11:
		case 18:
		case 19:
		case 20:
		case 1:
			break;
		case 12:
		case 9:
		case 5:
			Damp *= 0.75;
			break;
		case 14:
		case 3:
			Damp *= 0.625;
			break;
		case 15:
		case 13:
		case 2:
		case 7:
			Damp*= 0.5;
			break;
		case 16:
			Damp *= 0.375;
			break;
		default:
			break;
	}
	*/
	return Damp;
}
void AThrowWeaponPickup::MaybeAdjustCollisionSize()
{
}

