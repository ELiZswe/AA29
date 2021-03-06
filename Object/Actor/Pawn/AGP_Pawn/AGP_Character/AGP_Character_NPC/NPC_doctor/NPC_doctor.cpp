// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_doctor/NPC_doctor.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

ANPC_doctor::ANPC_doctor()
{
	NPC_DamageOn			= true;
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	AnimRate				= 1;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Pilot.SoldierM_Pilot'"), NULL, LOAD_None, NULL);
	LoadMesh();
}

void ANPC_doctor::PostBeginPlay()
{
	AAGP_Objective* AO = nullptr;
	Super::PostBeginPlay();
	/*
	if ((DamageTag != "None") && (DamageTag != "None"))
	{
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
	}
	InitialKillHealth = KillHealth;
	vStartLocation = Location;
	vStartRotation = Rotation;
	*/
}

/*
void ANPC_doctor::TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	if (Health <= 0)
	{
		Log(string(this) + " TakeDamage entered on already dead pawn!");
		return;
	}
	if ((Controller != nullptr) && Controller->IsA(AaAIController::StaticClass()))
	{
		Log(string(this) + " Damage received for Pawn with AI Controller: " + FString::FromInt(Damage));
		Cast<AaAIController>(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, DamageType, Bone);
	}
	TriggerEvent(DamageEvent, this, instigatedBy);
	Super::TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType, Bone, KillerController, ResponsibleActor);
}
*/

void ANPC_doctor::UndoDeath()
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
	//Acceleration *= 0;
	//GotoState("None");
}

void ANPC_doctor::MatchStarting()
{
	UndoDeath();
	DoAnimLoop();
	/*
	SetDrawType(DT_Mesh);
	if ((ControllerClass != nullptr) && (Controller == nullptr))
	{
		Controller = Spawn(ControllerClass);
		if (Controller != nullptr)
		{
			Controller.Possess(this);
		}
	}
	*/
}

void ANPC_doctor::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	DoAnimLoop();
}

void ANPC_doctor::DoAnimLoop()
{
	if ((AnimSequence != "None") && (AnimSequence != "None"))
	{
		//LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
	}
}

bool ANPC_doctor::IsFriend(APawn* Other)
{
	return true;
}

bool ANPC_doctor::UsedBy(APawn* User)
{
	/*
	if ((Controller != nullptr) && Controller->IsA(ANPCBaseController::StaticClass()))
	{
		return Super::UsedBy(User);
	}
	bNPCused = true;
	nNPCusedtime = int((GetWorld()->GetTimeSeconds() + 1));
	LastUsedBy = User;
	if (DamageObjective != nullptr)
	{
		DamageObjective.NotifyLinkUsedBy(User);
	}
	return Controller.UsedBy(User);
	*/
	return false;   //FAKE   /ELiZ
}

void ANPC_doctor::Touch(AActor* Other)
{
	//Controller.Touch(Other);
}
