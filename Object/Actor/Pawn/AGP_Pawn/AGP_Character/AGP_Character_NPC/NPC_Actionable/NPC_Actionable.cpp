// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_Actionable/NPC_Actionable.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"

ANPC_Actionable::ANPC_Actionable()
{
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	bDummyPawn				= true;
	bCanBeCarried			= true;
	AnimRate				= 1;
	bDontPossess			= true;
	MovementAnims			= {
		"None",
		"None",
		"None",
		"None"
	};
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/CivilianM_B.CivilianM_B'"), NULL, LOAD_None, NULL);
	LoadMesh();
}

void ANPC_Actionable::PostBeginPlay()
{
	Super::PostBeginPlay();
	LoadSkinsAndMeshes();
}

void ANPC_Actionable::ConfigureLinkDamage()
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
void ANPC_Actionable::TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, Actor.BoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	FVector MomentumDir = FVector(0, 0, 0);
	TriggerEvent(DamageEvent, this, instigatedBy);
	if (DamageObjective != nullptr)
	{
		if (KillHealth > 0)
		{
			Controller.TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType, Bone, KillerController);
			Damage = FMath::Min(Damage, KillHealth);
			(KillHealth -= Damage);
			MomentumDir = Normal(Momentum);
			if (DamageObjective != nullptr)
			{
				DamageObjective.NotifyLinkDamage(instigatedBy, Damage);
			}
			if (KillHealth <= 0)
			{
				TearOffMomentum = Momentum;
				TriggerEvent(KillEvent, this, instigatedBy);
				if (DamageObjective != nullptr)
				{
					DamageObjective.NotifyLinkKill(instigatedBy);
				}
				Died(instigatedBy.Controller, DamageType, HitLocation, MomentumDir, Bone);
			}
		}
	}
}
*/

void ANPC_Actionable::UndoDeath()
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
	//GotoState("None");
}

void ANPC_Actionable::MatchStarting()
{
	UndoDeath();
	DoAnimLoop();
	//SetDrawType(DT_Mesh);
}

void ANPC_Actionable::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	DoAnimLoop();
}

void ANPC_Actionable::DoAnimLoop()
{
	if ((AnimSequence != "None") && (AnimSequence != "None"))
	{
		//LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
	}
}

bool ANPC_Actionable::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_Actionable::LoadSkinsAndMeshes()
{
	int32 i = 0;
	/*
	if (GetNetMode() != ENetMode::NM_Client)
	{
		for (i = 0; i < Skins.Num(); i++)
		{
			FriendlyMaterial[i] = Skins[i];
		}
		FriendlyMesh = Mesh;
	}
	*/
}

void ANPC_Actionable::SetSkinsAndMeshes()
{
	int32 i = 0;
	if (!bUpdateSkinsAndMeshes)
	{
		return;
	}
	/*
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
		}
		LinkMesh(FriendlyMesh);
	}
	*/
	bUpdateSkinsAndMeshes = false;
}

bool ANPC_Actionable::UsedBy(APawn* User)
{
	bNPCused = true;
	/*
	nNPCusedtime = int((GetWorld()->GetTimeSeconds() + 1));
	if (DamageObjective != nullptr)
	{
		DamageObjective.NotifyLinkUsedBy(User);
	}
	return Controller.UsedBy(User);
	*/
	return false;    //FAKE  /ELiZ
}

void ANPC_Actionable::Touch(AActor* Other)
{
	//Controller.Touch(Other);
}
