// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_BHPilot/NPC_BHPilot.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/DamageType/Crushed/Crushed.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

ANPC_BHPilot::ANPC_BHPilot()
{
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	bDummyPawn				= true;
	AnimSequence			= "BH_Pilot";
	AnimRate				= 1;
	bDontPossess			= true;
	bDisableShadow			= true;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Pilot.SoldierM_Pilot'"), NULL, LOAD_None, NULL);
	HUDText					= "Pilot";
	LoadMesh();
}

/*
simulated State BusyCrouching
{
	simulated Function EndState()
	{
		LoopAnim(AnimSequence,1,0.25);
	}
}
*/

/*
simulated State BusyStanding
{
	simulated Function EndState()
	{
		LoopAnim(AnimSequence,1,0.25);
	}
}
*/

void ANPC_BHPilot::SetAnimAction(FName NewAction)
{
}

void ANPC_BHPilot::SetLoopingAnimAction(FName NewAction)
{
}

void ANPC_BHPilot::PostBeginPlay()
{
	Super::PostBeginPlay();
	/*
	vStartLocation = Location;
	vStartRotation = Rotation;
	LoadSkinsAndMeshes();
	SetDrawScale((1 - (float(Rand(5)) * 0.01)));
	*/
}

void ANPC_BHPilot::ConfigureLinkDamage()
{
	AAGP_Objective* AO = nullptr;
	InitialKillHealth = KillHealth;
	if ((DamageTag != "None") && (DamageTag != "None"))
	{
		/*
		ForEach AllActors(AAGP_Objective::StaticClass(), AO)
		{
			if (AO.DamageTag == DamageTag)
			{
				if (DamageObjective == nullptr)
				{
					DamageObjective = AO;
				}
				else
				{
					DebugLog(DEBUG_Warn, "NPC_Ambient::PostBeginPlay()	Already have a DamageObjective! " + FString::FromInt(AO) @ FString::FromInt(DamageObjective));
				}
			}
		}
		if (DamageObjective == nullptr)
		{
			DebugLog(DEBUG_Warn, "NPC_Ambient::PostBeginPlay()	Could not find DamageObjective for DamageTag " + FString::FromInt(DamageTag));
		}
		*/
	}
}

/*
void ANPC_BHPilot::TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	FVector MomentumDir = FVector(0, 0, 0);
	if (Controller == nullptr)
	{
		return;
	}
	if (Controller.bGodMode)
	{
		return;
	}
	if (DamageType == ACrushed::StaticClass())
	{
		return;
	}
	if (instigatedBy == nullptr)
	{
		return;
	}
	if ((Controller != nullptr) && Controller->IsA(AaAIController::StaticClass()))
	{
		Cast<AaAIController>(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, DamageType, Bone);
	}
	if (((Base != nullptr) && Base->IsA(AVehicle::StaticClass())) && (Controller == nullptr))
	{
		Damage = FMath::Min(Damage, KillHealth);
		(KillHealth -= Damage);
		MomentumDir = Normal(Momentum);
		PlayHit(float(Damage), instigatedBy, HitLocation, DamageType, MomentumDir);
		if (DamageObjective != nullptr)
		{
			DamageObjective.NotifyLinkDamage(instigatedBy, Damage);
		}
		if (KillHealth <= 0)
		{
			if (bPhysicsAnimUpdate)
			{
				TearOffMomentum = Momentum;
			}
			TriggerEvent(KillEvent, this, instigatedBy);
			if (DamageObjective != nullptr)
			{
				DamageObjective.NotifyLinkKill(instigatedBy);
			}
			SetCollision(false, false, false);
			Died(instigatedBy.Controller, DamageType, HitLocation, MomentumDir, Bone);
		}
		return;
	}
	TriggerEvent(DamageEvent, this, instigatedBy);
	NotifyShotHit(instigatedBy, DamageType);
	if (KillHealth > 0)
	{
		Controller.TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType, Bone, KillerController);
		Damage = FMath::Min(Damage, KillHealth);
		(KillHealth -= Damage);
		MomentumDir = Normal(Momentum);
		PlayHit(float(Damage), instigatedBy, HitLocation, DamageType, MomentumDir);
		if (DamageObjective != nullptr)
		{
			DamageObjective.NotifyLinkDamage(instigatedBy, Damage);
		}
		if (KillHealth <= 0)
		{
			if (bPhysicsAnimUpdate)
			{
				TearOffMomentum = Momentum;
			}
			TriggerEvent(KillEvent, this, instigatedBy);
			if (DamageObjective != nullptr)
			{
				DamageObjective.NotifyLinkKill(instigatedBy);
			}
			SetCollision(false, false, false);
			Died(instigatedBy.Controller, DamageType, HitLocation, MomentumDir, Bone);
		}
	}
}
*/

void ANPC_BHPilot::UndoDeath()
{
	Health = 100;
	KillHealth = InitialKillHealth;
	//bPlayedDeath = false;
	bIsDead = false;
	//bInvulnerableBody = false;
	bNetAlreadyDead = false;
	bSimDeadFalling = false;
	//SetDrawType(DT_Mesh);
	//SetCollision(true, true, true);
	//SetPhysics(PHYS_None);
	//SetLocation(vStartLocation);
	//SetRotation(vStartRotation);
	//SetPhysics(PHYS_Walking);
	//(Acceleration *= 0);
	//GotoState("None");
}

void ANPC_BHPilot::MatchStarting()
{
	UndoDeath();
	DoAnimLoop();
	//SetDrawType(DT_Mesh);
}

void ANPC_BHPilot::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	DoAnimLoop();
}

void ANPC_BHPilot::DoAnimLoop()
{
	if ((AnimSequence != "None") && (AnimSequence != "None"))
	{
		//LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
	}
}

bool ANPC_BHPilot::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_BHPilot::Touch(AActor* Other)
{
	if (Controller != nullptr)
	{
		//Controller.Touch(Other);
	}
}

void ANPC_BHPilot::LoadSkinsAndMeshes()
{
	int32 i = 0;
	if (GetNetMode() != ENetMode::NM_Client)
	{
		for (i = 0; i < Skins.Num(); i++)
		{
			FriendlyMaterial[i] = Skins[i];
		}
		//FriendlyMesh = Mesh;
	}
}

void ANPC_BHPilot::SetSkinsAndMeshes()
{
	int32 i = 0;
	/*
	if (!bUpdateSkinsAndMeshes)
	{
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		Skins.Num() = 0;
		AlphaSkins.Num() = 0;
		BlackSkins.Num() = 0;
		for (i = 0; i < 5; i++)
		{
			if (FriendlyMaterial[i] != nullptr)
			{
				Skins.Num() = i;
				Skins[i] = FriendlyMaterial[i];
			}
			else
			{
			}
		}
		LinkMesh(FriendlyMesh);
	}
	bUpdateSkinsAndMeshes = false;
	*/
}

void ANPC_BHPilot::ActivateLinkedObjective(APawn* User)
{
	if (DamageObjective != nullptr)
	{
		//DamageObjective.NotifyLinkUsedBy(User);
	}
}

bool ANPC_BHPilot::UsedBy(APawn* User)
{
	//return Controller.UsedBy(User);
	return false;    //FAKE   /ELiZ
}

void ANPC_BHPilot::AnimateRunning()
{
}

void ANPC_BHPilot::AnimateWalking()
{
}
