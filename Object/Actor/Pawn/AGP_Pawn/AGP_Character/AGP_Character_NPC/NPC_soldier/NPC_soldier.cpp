// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_soldier/NPC_soldier.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"

ANPC_soldier::ANPC_soldier()
{
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	AnimRate				= 1;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_InfantryB.OpforM_InfantryB'"), NULL, LOAD_None, NULL);
	LoadMesh();
}

/*
simulated State BusyCrouching
{
	simulated Function EndState()
	{
		FName IdleAnim = "";
		Super::EndState();
		if (_AnimationMonitor == nullptr)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				if (bIsFiringBlindlyOverHead)
				{
					IdleAnim="CrhFwUpBlndFrLoop";
					break;
				}
				if (bIsFiringBlindlyLeft)
				{
					IdleAnim="CrhFwLtBlndFrLoop";
					break;
				}
				IdleAnim="CrhLgFr";
			}
			case 12:
			IdleAnim="CrhGnRdy";
			case 9:
			IdleAnim="CrhGnFr";
			case 68:
			case 70:
			IdleAnim="CrhCluIdleUp";
			case 67:
			case 71:
			IdleAnim="CrhCluIdleDwn";
			case 75:
			IdleAnim="CrhTubeIdle";
			case 22:
			case 18:
			IdleAnim="CrhBinocsUp";
			case 21:
			case 19:
			IdleAnim="CrhBinocsDn";
			case 25:
			case 29:
			IdleAnim="CrhRPG";
			case 33:
			IdleAnim="CrhAT4";
			case 39:
			IdleAnim="CrhSmIdle";
			default:
			if (bIsFiringBlindlyOverHead)
			{
				IdleAnim="CrhFwUpBlndFrLoop";
			}
			else
			{
				if (bIsFiringBlindlyLeft)
				{
					IdleAnim="CrhFwLtBlndFrLoop";
				}
				else
				{
					if (bIsFiringBlindlyRight)
					{
						IdleAnim="CrhFwRtBlndFrLoop";
					}
					else
					{
						IdleAnim="CrhNo";
					}
				}
			}
			LoopAnim(IdleAnim,1,0.25);
		}
	}
}
*/

/*
simulated State BusyStanding
{
	simulated Function EndState()
	{
		FName IdleAnim = "";
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(this) @ "AGP_Pawn::EndState - in state" @ FString::FromInt(GetStateName()));
		}
		Super::EndState();
		if (_AnimationMonitor == nullptr)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				if (bIsFiringBlindlyLeft)
				{
					IdleAnim="StndLtBlndFr";
					break;
				}
				if (bIsFiringBlindlyRight)
				{
					IdleAnim="StndRtBlndFr";
					break;
				}
				if (bIsHipShooting)
				{
					IdleAnim="HipStdLgFr";
					break;
				}
				IdleAnim="StdLgFr";
			}
			case 12:
			IdleAnim="StdGnRdy";
			case 9:
			IdleAnim="StdGnFr";
			case 68:
			case 70:
			IdleAnim="StdCluUp";
			case 67:
			case 71:
			IdleAnim="StdCluDn";
			case 22:
			case 18:
			IdleAnim="StdBinocsUp";
			case 21:
			case 19:
			IdleAnim="StdBinocsDn";
			case 33:
			IdleAnim="StdAT4";
			case 25:
			case 29:
			IdleAnim="StdRPG";
			case 39:
			IdleAnim="StdSmIdle";
			default:
			if (bIsFiringBlindlyLeft)
			{
				IdleAnim="StndLtBlndFr";
			}
			else
			{
				if (bIsFiringBlindlyRight)
				{
					IdleAnim="StndRtBlndFr";
				}
				else
				{
					if (bIsHipShooting)
					{
						IdleAnim="HipStdLgFr";
					}
					else
					{
						IdleAnim="StdNo";
					}
				}
			}
			LoopAnim(IdleAnim,1,0.25);
		}
	}
}
*/

/*
replication
{
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		bWalkingPatrol;
}
*/


void ANPC_soldier::PostBeginPlay()
{
	Super::PostBeginPlay();
	vStartLocation = GetActorLocation();
	vStartRotation = GetActorRotation();
	LoadSkinsAndMeshes();
}

void ANPC_soldier::ConfigureLinkDamage()
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
void ANPC_soldier::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	FVector MomentumDir = FVector(0, 0, 0);
	if ((Controller != nullptr) && Controller->IsA(AaAIController::StaticClass()))
	{
		Cast<AaAIController>(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, DamageType, Bone);
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

void ANPC_soldier::UndoDeath()
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

void ANPC_soldier::MatchStarting()
{
	UndoDeath();
	DoAnimLoop();
	//SetDrawType(DT_Mesh);
}

void ANPC_soldier::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	DoAnimLoop();
}

void ANPC_soldier::DoAnimLoop()
{
	if ((AnimSequence != "None") && (AnimSequence != "None"))
	{
		//LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
	}
}

bool ANPC_soldier::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_soldier::Touch(AActor* Other)
{
	if (Controller != nullptr)
	{
		//Controller->Touch(Other);
	}
}

void ANPC_soldier::LoadSkinsAndMeshes()
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

void ANPC_soldier::SetSkinsAndMeshes()
{
	int32 i = 0;
	/*
	if (!bUpdateSkinsAndMeshes)
	{
		return;
	}
	*/
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		/*
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
		*/
	}
	//bUpdateSkinsAndMeshes = false;
}

void ANPC_soldier::ActivateLinkedObjective(APawn* User)
{
	if (DamageObjective != nullptr)
	{
		//DamageObjective->NotifyLinkUsedBy(User);
	}
}

bool ANPC_soldier::UsedBy(APawn* User)
{
	//return Controller->UsedBy(User);
	return false;    //FAKE   /ELiZ
}

void ANPC_soldier::AnimateRunning()
{
	if ((UpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large) || (UpperBodyAnim == EUpperBodyAnim::UBANIM_WEAP_Reload))
	{
		/*
		if (bIsHipShooting)
		{
			TurnLeftAnim = "HipStdRotLtLgFr";
			TurnRightAnim = "HipStdRotRtLgFr";
			MovementAnims[0] = "HipRunFwLgFr";
			MovementAnims[1] = "HipWlkBkLgFr";
			MovementAnims[2] = "HipRunLtLgFr";
			MovementAnims[3] = "HipRunRtLgFr";
		}
		else
		{
			TurnLeftAnim = "StdRotLtLgFr";
			TurnRightAnim = "StdRotRtLgFr";
			MovementAnims[0] = "RunFwLgFr";
			MovementAnims[1] = "WlkBkLgFr";
			MovementAnims[2] = "RunLtLgFr";
			MovementAnims[3] = "RunRtLgFr";
		}
		*/
	}
	else
	{
		TurnLeftAnim = "StdRotLtNo";
		TurnRightAnim = "StdRotRtNo";
		MovementAnims[0] = "RunFwNo";
		MovementAnims[1] = "RunBkNo";
		MovementAnims[2] = "RunLtNo";
		MovementAnims[3] = "RunRtNo";
	}
}

void ANPC_soldier::AnimateWalking()
{
	if ((UpperBodyAnim == EUpperBodyAnim::UBANIM_NONE_Large) || (UpperBodyAnim == EUpperBodyAnim::UBANIM_WEAP_Reload))
	{
		/*
		if (bIsHipShooting)
		{
			TurnLeftAnim = "HipStdRotLtLgFr";
			TurnRightAnim = "HipStdRotRtLgFr";
			MovementAnims[0] = "HipWlkFwLgFr";
			MovementAnims[1] = "HipWlkBkLgFr";
			MovementAnims[2] = "HipWlkLtLgFr";
			MovementAnims[3] = "HipWlkRtLgFr";
		}
		else
		{
			TurnLeftAnim = "StdRotLtLgFr";
			TurnRightAnim = "StdRotRtLgFr";
			MovementAnims[0] = "WlkFwLgFr";
			MovementAnims[1] = "WlkBkLgFr";
			MovementAnims[2] = "WlkLtLgFr";
			MovementAnims[3] = "WlkRtLgFr";
		}
		*/
	}
	else
	{
		TurnLeftAnim = "StdRotLtNo";
		TurnRightAnim = "StdRotRtNo";
		MovementAnims[0] = "WlkFwNo";
		MovementAnims[1] = "WlkBkNo";
		MovementAnims[2] = "WlkLtNo";
		MovementAnims[3] = "WlkRtNo";
	}
}
