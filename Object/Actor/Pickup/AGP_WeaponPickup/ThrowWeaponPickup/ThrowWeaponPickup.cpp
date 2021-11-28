// All the original content belonged to the US Army


#include "ThrowWeaponPickup.h"

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


void AThrowWeaponPickup::SetDoorBreacherEmitter(AEmitter* EM)
{
}
/*
static void StaticPrecache (LevelInfo L)
{
	if (Default.liveStaticMesh != None)
	{
		L.AddPrecacheStaticMesh(Default.liveStaticMesh);
	}
	StaticPrecache(L);
}
*/

void AThrowWeaponPickup::RandSpin(float spinRate)
{
	/*
		DesiredRotation=RotRand();
		RotationRate.Yaw=spinRate * 2 * FRand() - spinRate;
		RotationRate.Pitch=spinRate * 2 * FRand() - spinRate;
		RotationRate.Roll=spinRate * 2 * FRand() - spinRate;
	*/
}
void AThrowWeaponPickup::Destroyed()
{
	
		Super::Destroyed();
		//if (DamageArea != NULL)
		//{
		//	DamageArea.Destroy();
		//	DamageArea=NULL;
		//}
	
}
bool AThrowWeaponPickup::IsLive()
{
	return _bIsLive;
}
void AThrowWeaponPickup::PostBeginPlay()
{
	/*
		local class<ThrowWeapon>  W;
		PostBeginPlay();
		W=class<ThrowWeapon>(InventoryType);
		if (W != None && W.Default.cSmokeEmitter != None)
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
		_bIsLive=True;
		SetStaticMesh(liveStaticMesh);
		if (LiveMesh != None)
		{
			LinkMesh(LiveMesh);
		}
	*/
}
void AThrowWeaponPickup::InitDroppedPickupFor(AInventory* Inv, bool bFreeze)
{
	/*
		local ThrowWeapon W;
		W=ThrowWeapon(Inv);
		if (W != None && W.IsPinPulled())
		{
			W.SpawnPickup(True,Self);
		}
		InitDroppedPickupFor(Inv,bFreeze);
	*/
}
void AThrowWeaponPickup::AgentControllerFearMe()
{
	/*
		local AgentController AC;
		local float fGrenadeAwareDistance;
		local FVector vVec;
		local float fLen;
		fGrenadeAwareDistance=1024;
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
	/*
		local AgentController AC;
		ForEach DynamicActors('AgentController',AC)
		{
			AC.FearGrenade=None;
		}
	*/
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
		if (Owner != None)
		{
			Owner.GotoState('DestroyWeapon');
		}
		LifeSpan=1;
		SetDrawType(0);
		SetPhysics(0);
		Velocity=vect(0 0 0);
		SetCollision(False,False,False);
		Disable('Tick');
	*/
}
void AThrowWeaponPickup::ProcessBlewUp()
{
	/*
		local class<ThrowWeapon>  W;
		local NPCPathNode npcpn;
		local float fpThreatenedNodeDistance;
		W=class<ThrowWeapon>(InventoryType);
		if (W != None)
		{
			if (GetNetMode() != ENetMode::NM_DedicatedServer)
			{
				if (W.Default.cExplosionEmitter != None)
				{
					Spawn(W.Default.cExplosionEmitter,,,Location,rot(16384 0 0));
				}
				if (W.Default.cExplosionDecal != None)
				{
					Spawn(W.Default.cExplosionDecal,,,Location,vect(0 0 -1));
				}
				SpawnSmokeEmitter(W);
				PlayOwnedSound(W.Default.BoomSound,3,1,True,1500,,True);
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
			bHidden=True;
		}
		if (! IsA('PickupT_M83_Smoke'))
		{
			fpThreatenedNodeDistance=W.Default._fKillRadius + W.Default._fDamageRadius;
			ForEach RadiusActors('NPCPathNode',npcpn,fpThreatenedNodeDistance,Location)
			{
				if (bShowThreatenedNodes)
				{
					npcpn.DebugNavMarker(False,False);
				}
				npcpn.FearCost=0;
			}
		}
	*/
}
void AThrowWeaponPickup::SpawnSmokeEmitter(AThrowWeapon*  W)
{
	/*
		local AGP_Effects.BaseSmokeEmitter SmokeGenerator;
		if (W.Default.cSmokeEmitter != None)
		{
			SmokeGenerator=Spawn(W.Default.cSmokeEmitter,Self,,Location,rot(16384 0 0));
			SmokeGenerator.SetBase(Self);
			SmokeGenerator.PickupPtr=Self;
			SmokeGenerator._EffectDuration=_EffectDuration;
		}
	*/
}
void AThrowWeaponPickup::SpawnDamageArea(AThrowWeapon*  W)
{
	/*
		if (W.Default.SmokeDamageType != None && Role == 4)
		{
			DamageArea=Spawn('DamageTrigger',Self);
			DamageArea.InitializeFor(Self);
		}
	*/
}
void AThrowWeaponPickup::Landed(FVector HitNormal)
{
	/*
		local Controller ctrlIterator;
		local NPCPathNode npcpn;
		local class<ThrowWeapon>  W;
		local float fpThreatenedNodeDistance;
		if (DamageArea != None)
		{
			DamageArea.NotifyLanded(Self);
		}
		W=class<ThrowWeapon>(InventoryType);
		Landed(HitNormal);
		if (VSize(Velocity) < 20)
		{
			SetPhysics(0);
		}
		else
		{
			HitWall(HitNormal,None);
		}
		ctrlIterator=Level.ControllerList;
		if (ctrlIterator != None)
		{
			if (ctrlIterator.IsA('NPCBaseController'))
			{
				NPCBaseController(ctrlIterator).NotifyGrenadeLanded(Self);
			}
			ctrlIterator=ctrlIterator.nextController;
		}
		if (! IsA('PickupT_M83_Smoke'))
		{
			if (_bIsLive && W != None && W.Default._fDamage > 50)
			{
				fpThreatenedNodeDistance=W.Default._fKillRadius + W.Default._fDamageRadius;
				ForEach RadiusActors('NPCPathNode',npcpn,fpThreatenedNodeDistance,Location)
				{
					npcpn.FearCost=5000 * 1 - VSize(npcpn.Location - Location) / fpThreatenedNodeDistance;
					if (bShowThreatenedNodes)
					{
						npcpn.DebugNavMarker(True,False);
					}
				}
			}
		}
	*/
}
void AThrowWeaponPickup::HitWall(FVector HitNormal, AActor* Wall)
{
	/*
		local DecoMesh DM;
		local FVector HitLoc;
		local FVector HitNorm;
		local Material HitMaterial;
		local int PolyFlags;
		if (! bBounce)
		{
			Return;
		}
		if (Wall != None && Wall.IsA('DecoMesh'))
		{
			DM=DecoMesh(Wall);
			if (DM.bInstantGrenBreak && DM.DamageHealth > 0)
			{
				DM.TakeDamage(DM.InitialDamageHealth * 1000,Instigator,DM.Location,vect(0 0 0),Class'Impact',,,Self);
				Return;
			}
		}
		if (! bPlacedPickup)
		{
			Trace(HitLoc,HitNorm,Location + Velocity * 1000,Location,True,vect(0 0 0),HitMaterial,PolyFlags);
			if (PFlag_DeleteProjectiles(PolyFlags))
			{
				DeleteProjectile();
				Return;
			}
			else
			{
				if (GetNetMode() != ENetMode::NM_DedicatedServer)
				{
					if (HitMaterial != None)
					{
						PlayLandedSound(HitMaterial);
					}
					else
					{
						PlaySound(_sImpactSounds[Rand(_sImpactSounds.Length)],1,1.5,,150,,True);
					}
				}
			}
		}
		Velocity=MirrorVectorByNormal(Velocity,HitNormal) * GetMaterialBounceDamp(HitMaterial);
		RandSpin(_fBounceSpin);
		if (VSize(Velocity) < 20)
		{
			bBounce=False;
		}
	*/
}
void AThrowWeaponPickup::Touch(AActor* Other)
{
	/*
		local FVector HitNormal;
		local FVector HitLocation;
		local Material HitMaterial;
		local Actor HitActor;
		if (Other == None)
		{
			Return;
		}
		if (VSize(Velocity) == 0)
		{
			Return;
		}
		if (Other.bBlockActors && Other.bProjTarget || Other.bBlockActors && Other.bBlockPlayers)
		{
			if (Instigator != None && Other != Instigator && Other != Instigator.FrontAuxCyl && Other != Instigator.BackAuxCyl)
			{
				HitActor=Trace(HitLocation,HitNormal,Location + Velocity,Location,True,vect(0 0 0),HitMaterial);
				if (HitActor == None)
				{
					HitActor=Trace(HitLocation,HitNormal,Location + Velocity,Location,True,MakeVect(CollisionRadius,CollisionRadius,CollisionHeight),HitMaterial);
				}
				HitWall(HitNormal,Other);
			}
		}
	*/
}
void AThrowWeaponPickup::PlayLandedSound(UTexture2D* HitMaterial)
{
	/*
		USoundBase* S;
		switch(HitMaterial.GetMaterialType())
		{
			case 0:
				return;
			case 18:
			case 19:
			case 20:
			case 1:
				S=sWood[Rand(sWood.Length)];
				break;
			case 2:
				S=sDirt[Rand(sDirt.Length)];
				break;
			case 3:
				S=sDirt[Rand(sDirt.Length)];
			break;
			case 21:
			case 22:
			case 23:
			case 4:
				S=sMetal[Rand(sMetal.Length)];
				break;
			case 5:
				S=sMetal[Rand(sMetal.Length)];
				break;
			case 6:
				S=_sImpactSounds[Rand(_sImpactSounds.Length)];
				break;
			case 7:
				S=sMuffled[Rand(sMuffled.Length)];
				break;
			case 8:
				break;
			case 9:
				S=sDirt[Rand(sDirt.Length)];
				break;
			case 10:
				S=sMetal[Rand(sMetal.Length)];
				break;
			case 11:
				S=sWood[Rand(sWood.Length)];
				break;
			case 12:
				S=sMuffled[Rand(sMuffled.Length)];
				break;
			case 13:
				S=sMuffled[Rand(sMuffled.Length)];
				break;
			case 14:
				S=sDirt[Rand(sDirt.Length)];
				break;
			case 15:
				S=sDirt[Rand(sDirt.Length)];
				break;
			case 16:
				S=sDirt[Rand(sDirt.Length)];
				break;
			case 17:
				S=sMetal[Rand(sMetal.Length)];
				break;
			default:
				break;
		}
		PlayOwnedSound(S,1,0.4,,300,,true);
	*/
}
void AThrowWeaponPickup::GetMaterialBounceDamp(UTexture2D* HitMaterial)
{
	/*
		local float Damp;
		Damp=_fBounceDamp;
		if (HitMaterial == None)
		{
			Return Damp;
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
		}
		return Damp;
	*/
}
void AThrowWeaponPickup::MaybeAdjustCollisionSize()
{
}


