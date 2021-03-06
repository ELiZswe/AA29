// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_Ambient/NPC_Ambient.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"

ANPC_Ambient::ANPC_Ambient()
{
	bStaticSkinsAndMeshes  = true;
	KillHealth             = 100;
	bDummyPawn             = true;
	AnimRate               = 1;
	bDontPossess           = true;
	MovementAnims          = {
		"None",
		"None",
		"None",
		"None"
	};
	bCleanUp               = false;
	bAlwaysRelevant        = true;
	//RemoteRole = 1
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/CivilianM_B.CivilianM_B'"), NULL, LOAD_None, NULL);
	bCollideWorld          = false;
	LoadMesh();
}

/*
State PlayAmbientNPCDyingAnimation
{
Begin:
	if (bIsCrouched)
	{
		PlayAnim("CrhKillChstSpin",1,0.05,13);
		Sleep((GetAnimDuration("CrhKillChstSpin",1) - 0.1));
	}
	else
	{
		PlayAnim("StdKillChst",1,0.05,13);
		Sleep((GetAnimDuration("StdKillChst",1) - 0.1));
	}
	StopAnimating(true);
}
*/

void ANPC_Ambient::PossessedBy(AController* C)
{

}
void ANPC_Ambient::BeginPlay()
{

}

void ANPC_Ambient::PostBeginPlay()
{
	Super::PostBeginPlay();
	ConfigureLinkDamage();
	AddDefaultInventory();
	InitialKillHealth = KillHealth;
	LoadSkinsAndMeshes();
	if ((Controller == nullptr) || (!Controller->IsA(ANPCBaseController::StaticClass())))
	{
		bPlayDyingAnimation = true;
		//SetCollision(true, true, true);
	}
}

void ANPC_Ambient::ConfigureLinkDamage()
{
	AAGP_Objective* AO = nullptr;
	//DebugLog(DEBUG_AI, FString::FromInt(this) + ".ConfigureLinkDamage() with damage tag set to " + FString::FromInt(DamageTag));
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
					DebugLog(DEBUG_AI, FString::FromInt(this) + " Found linked damage objective: " + FString::FromInt(AO));
					DamageObjective = AO;
				}
				else
				{
					DebugLog(DEBUG_AI, "NPC_Ambient::PostBeginPlay()	Already have a DamageObjective! " + FString::FromInt(AO) @ FString::FromInt(DamageObjective));
				}
			}
		}
		if (DamageObjective == nullptr)
		{
			//DebugLog(DEBUG_AI, "NPC_Ambient::PostBeginPlay()	Could not find DamageObjective for DamageTag " + FString::FromInt(DamageTag));
		}
		*/
	}
}
/*
void ANPC_Ambient::TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	FVector MomentumDir = FVector(0, 0, 0);
	if (bHidden)
	{
		return;
	}
	DebugLog(DEBUG_AI, FString::FromInt(this) + "TakeDamage Damage: " + FString::FromInt(Damage) + " type: " + FString::FromInt(DamageType));
	TriggerEvent(DamageEvent, this, instigatedBy);
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, ET_Destroyed, instigatedBy);
	}
	if (KillHealth > 0)
	{
		if (Controller != nullptr)
		{
			Controller.TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType, Bone, KillerController);
		}
		Damage = FMath::Min(Damage, KillHealth);
		(KillHealth -= Damage);
		MomentumDir = Normal(Momentum);
		if (DamageObjective != nullptr)
		{
			DamageObjective.NotifyLinkDamage(instigatedBy, Damage);
		}
		if (KillHealth <= 0)
		{
			TriggerEvent(KillEvent, this, instigatedBy);
			if (bPlayDyingAnimation)
			{
				DebugLog(DEBUG_AI, "NPC died! playing animation");
				GotoState("PlayAmbientNPCDyingAnimation");
			}
			if (DamageObjective != nullptr)
			{
				DamageObjective.NotifyLinkKill(instigatedBy);
			}
			if (bUseKarmaDeathAnimation)
			{
				Died(instigatedBy.Controller, DamageType, HitLocation, MomentumDir, Bone);
			}
		}
	}
}
*/

void ANPC_Ambient::UndoDeath()
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
	//BoneAuxCyl.SetCollision(true, true, true);
	//GotoState("None");
}

void ANPC_Ambient::MatchStarting()
{
	UndoDeath();
	DoAnimLoop();
	//SetDrawType(DT_Mesh);
}

void ANPC_Ambient::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	DoAnimLoop();
	//SetDrawType(DT_Mesh);
}

void ANPC_Ambient::DoAnimLoop()
{
	if ((AnimSequence != "None") && (AnimSequence != "None"))
	{
		//LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
	}
}

bool ANPC_Ambient::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_Ambient::LoadSkinsAndMeshes()
{
	int32 i = 0;

	if (GetNetMode() != ENetMode::NM_Client)
	{
		for (i = 0; i < Skins.Num(); i++)
		{
			//FriendlyMaterial[i] = Skins[i];
		}
		//FriendlyMesh = Mesh;
	}
}

void ANPC_Ambient::SetSkinsAndMeshes()
{
	int32 i = 0;
	if (!bUpdateSkinsAndMeshes)
	{
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		Skins.Empty();
		//AlphaSkins.Empty();
		//BlackSkins.Empty();
		for (i = 0; i < 5; i++)
		{
			if (FriendlyMaterial[i] != nullptr)
			{
				Skins.Add(FriendlyMaterial[i]);
			}
		}
		//LinkMesh(FriendlyMesh);
	}
	bUpdateSkinsAndMeshes = false;
}

bool ANPC_Ambient::UsedBy(APawn* User)
{
	/*
	if ((Controller != nullptr) && Controller->IsA(ANPCBaseController::StaticClass()))
	{
		return Super::UsedBy(User);
	}
	bNPCused = true;
	nNPCusedtime = int((GetWorld()->GetTimeSeconds() + 1));
	if (DamageObjective != nullptr)
	{
		DamageObjective.NotifyLinkUsedBy(User);
	}
	if (Controller != nullptr)
	{
		return Controller.UsedBy(User);
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE  /ELiZ
}

void ANPC_Ambient::Touch(AActor* Other)
{
	if (Controller != nullptr)
	{
		//Controller->Touch(Other);
	}
}

void ANPC_Ambient::MatchEnding()
{
}
