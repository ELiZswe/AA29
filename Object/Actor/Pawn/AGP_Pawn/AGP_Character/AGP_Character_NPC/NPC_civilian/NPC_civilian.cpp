// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_civilian/NPC_civilian.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"

ANPC_civilian::ANPC_civilian() 
{
	NPC_DamageOn			= true;
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	AnimRate				= 1;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/CivilianM_B.CivilianM_B'"), NULL, LOAD_None, NULL);
	bCollideActors			= false;
	LoadMesh();
}

/*
simulated State BusyProning
{
	simulated Function EndState()
	{
		FName IdleAnim = "";
		EndState();
		if (_AnimationMonitor == nullptr)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				IdleAnim="PrnLg";
				break;
				case 22:
				case 18:
				IdleAnim="PrnBinocsUp";
				break;
				case 21:
				case 19:
				IdleAnim="PrnBinocsDn";
				break;
				case 68:
				case 70:
				IdleAnim="PrnCLUIdleUp";
				break;
				case 67:
				case 71:
				IdleAnim="PrnCLUIdleDwn";
				break;
				case 75:
				IdleAnim="PrnTubeIdle";
				break;
				case 25:
				case 29:
				IdleAnim="PrnRPG";
				break;
				case 33:
				IdleAnim="PrnAT4";
				break;
				case 39:
				IdleAnim="PrnSMIdle";
				break;
				case 12:
				case 9:
				default:
				IdleAnim="PrnNo";
				break;
			}
			if ((Controller != nullptr) && Controller.IsInState("InjuredWaitingForHealing"))
			{
				IdleAnim=nmNPCIdleAnim;
			}
			LoopAnim(IdleAnim,1,0.05);
		}
	}
}
*/

/*
simulated State BusyCrouching
{
	simulated Function EndState()
	{
		FName IdleAnim = "";
		EndState();
		if (_AnimationMonitor == nullptr)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				IdleAnim="CrhLgFr";
				break;
				case 12:
				IdleAnim="CrhGnRdy";
				break;
				case 9:
				IdleAnim="CrhGnFr";
				break;
				case 68:
				case 70:
				IdleAnim="CrhCluIdleUp";
				break;
				case 67:
				case 71:
				IdleAnim="CrhCluIdleDwn";
				break;
				case 75:
				IdleAnim="CrhTubeIdle";
				break;
				case 22:
				case 18:
				IdleAnim="CrhBinocsUp";
				break;
				case 21:
				case 19:
				IdleAnim="CrhBinocsDn";
				break;
				case 25:
				case 29:
				IdleAnim="CrhRPG";
				break;
				case 33:
				IdleAnim="CrhAT4";
				break;
				case 39:
				IdleAnim="CrhSmIdle";
				break;
				default:
				IdleAnim="CrhNo";
				break;
			}
			if ((Controller != nullptr) && Controller.IsInState("InjuredWaitingForHealing"))
			{
				IdleAnim=nmNPCIdleAnim;
			}
			if (AnimLoopAction != "None")
			{
				LoopAnim(AnimLoopAction,1,0.25);
			}
			else
			{
				LoopAnim(IdleAnim,1,0.25);
			}
		}
		bInProneTransition=false;
	}
}
*/

void ANPC_civilian::BeginPlay()
{
	BeginPlay();
	/*
	if (GetNetMode() != ENetMode::NM_Client)
	{
		if (Cast<AAGP_GameInfo>(GetGameMode()).bNoInventory)
		{
			DebugLog(DEBUG_Warn, "AGP_Pawn::BeginPlay()	Not giving InvContainers!");
		}
		else
		{
			if (_InvHands == nullptr)
			{
				_InvHands = SpawnContainer("AGP_Inventory.InvHands");
				_InvHands.bStasis = true;
				_InvHands.SetPhysics(PHYS_None);
				_InvShoulder = SpawnContainer("AGP_Inventory.InvShoulder");
				_InvShoulder.bStasis = true;
				_InvShoulder.SetPhysics(PHYS_None);
			}
		}
	}
	*/
}

void ANPC_civilian::PostBeginPlay()
{
	Super::PostBeginPlay();
	vStartLocation = GetActorLocation();
	vStartRotation = GetActorRotation();
	LoadSkinsAndMeshes();
}

void ANPC_civilian::ConfigureLinkDamage()
{
	AAGP_Objective* AO = nullptr;
	/*
	InitialKillHealth = KillHealth;
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
	*/
}

/*
void ANPC_civilian::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	FVector MomentumDir = FVector(0, 0, 0);
	if (KillHealth > 0)
	{
		if ((Controller != nullptr) && Controller->IsA(AaAIController::StaticClass()))
		{
			Cast<AaAIController>(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, DamageType, Bone);
		}
		if (DamageEvent != "None")
		{
			TriggerEvent(DamageEvent, this, instigatedBy);
		}
		Controller.TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType, Bone, KillerController);
		Damage = FMath::Min(Damage, KillHealth);
		(KillHealth -= Damage);
		MomentumDir = Normal(Momentum);
		if (DamageObjective != nullptr)
		{
			DamageObjective.NotifyLinkDamage(instigatedBy, FMath::Min(Damage, KillHealth));
		}
		if (((instigatedBy != nullptr) && (instigatedBy.Controller != nullptr)) && (Cast<AHumanController>(instigatedBy.Controller) != nullptr))
		{
			Level.Game.Stats.PlayerStats[HumanController(instigatedBy.Controller).PlayerStatsIndex].StatEvent_ROECivilianHits();
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
		else
		{
			if (DamageObjective != nullptr)
			{
				if (((instigatedBy != nullptr) && (instigatedBy.Controller != nullptr)) && instigatedBy.Controller->IsA(AHumanController::StaticClass()))
				{
					Cast<AHumanController>(instigatedBy.Controller).NotifyAdminMessage("Cease Fire - You are hitting a non-combatant.");
				}
			}
		}
	}
}
*/

void ANPC_civilian::UndoDeath()
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

void ANPC_civilian::MatchStarting()
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

void ANPC_civilian::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	DoAnimLoop();
}

void ANPC_civilian::DoAnimLoop()
{
	if ((AnimSequence != "None") && (AnimSequence != "None"))
	{
		/*
		if (HasAnim(AnimSequence))
		{
			LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
		}
		*/
	}
}

bool ANPC_civilian::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_civilian::LoadSkinsAndMeshes()
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

void ANPC_civilian::SetSkinsAndMeshes()
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
			else
			{
			}
		}
		//LinkMesh(FriendlyMesh);
	}
	bUpdateSkinsAndMeshes = false;
}

/*
bool ANPC_civilian::UsedBy(APawn* User)
{
	bool bResult = false;
	bNPCused = true;
	nNPCusedtime = int((GetWorld()->GetTimeSeconds() + 1));
	LastUsedBy = User;
	if (DamageObjective != nullptr)
	{
		DamageObjective.NotifyLinkUsedBy(User);
	}
	bResult = Controller.UsedBy(User);
	if (bResult)
	{
		return bResult;
	}
	else
	{
		return Super::UsedBy(User);
	}
}
*/

void ANPC_civilian::Touch(AActor* Other)
{
	if (Controller != nullptr)
	{
		//Controller.Touch(Other);
	}
}

void ANPC_civilian::AnimateRunning()
{
	TurnLeftAnim = "StdRotLtNo";
	TurnRightAnim = "StdRotRtNo";
	MovementAnims[0] = "RunFwNo";
	MovementAnims[1] = "RunBkNo";
	MovementAnims[2] = "RunLtNo";
	MovementAnims[3] = "RunRtNo";
}

void ANPC_civilian::AnimateSprinting()
{
	TurnLeftAnim = "StdRotLtNo";
	TurnRightAnim = "StdRotRtNo";
	MovementAnims[0] = "SprintFwNo";
	MovementAnims[1] = "WlkBkNo";
	MovementAnims[2] = "SprintLtNo";
	MovementAnims[3] = "SprintRtNo";
}

void ANPC_civilian::AnimateCrouchWalking()
{
	TurnLeftAnim = "CrhRotLtNo";
	TurnRightAnim = "CrhRotRtNo";
	MovementAnims[0] = "CrhFwNo";
	MovementAnims[1] = "CrhBkNo";
	MovementAnims[2] = "CrhLtNo";
	MovementAnims[3] = "CrhRtNo";
}

void ANPC_civilian::AnimateWalking()
{
	TurnLeftAnim = "StdRotLtNo";
	TurnRightAnim = "StdRotRtNo";
	MovementAnims[0] = "WlkFwNo";
	MovementAnims[1] = "WlkBkNo";
	MovementAnims[2] = "WlkLtNo";
	MovementAnims[3] = "WlkRtNo";
}

