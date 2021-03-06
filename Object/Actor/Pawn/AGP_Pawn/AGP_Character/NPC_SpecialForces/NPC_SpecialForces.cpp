// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_SpecialForces/NPC_SpecialForces.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"

ANPC_SpecialForces::ANPC_SpecialForces()
{
	FSoundTimes.SetNum(5);
	SSound.SetNum(5);
	VSound.SetNum(5);
	IntelligenceSound.SetNum(4);
	CommunicationSound.SetNum(4);
	MedicalSound.SetNum(4);
	EngineerSound.SetNum(4);
	WeaponsSound.SetNum(4);
	SergeantSound.SetNum(4);
	CommanderSound.SetNum(4);
	LeaderSound.SetNum(4);
	SargGetInTruckLipsinc.SetNum(3);
	SargGoToClassLipsinc.SetNum(3);
	StudentVendingMachineLipsinc.SetNum(3);
	IntelligenceLipsinc.SetNum(4);
	CommunicationLipsinc.SetNum(4);
	MedicalLipsinc.SetNum(4);
	EngineerLipsinc.SetNum(4);
	WeaponsLipsinc.SetNum(4);
	SergeantLipsinc.SetNum(4);
	CommanderLipsinc.SetNum(4);
	LeaderLipsinc.SetNum(4);
	NPC_DamageOn           = true;
	bStaticSkinsAndMeshes  = true;
	KillHealth             = 100;
	AnimRate               = 1;
	bCleanUp               = false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB"), NULL, LOAD_None, NULL);
	LoadMesh();
}

static const int32 SARG_GET_IN_TRUCK_IDLE_SAY = 3;
static const int32 SARG_GO_TO_CLASS_IDLE_SAY = 3;
static const int32 STUDENT_VENDING_MACHINE_IDLE_SAY = 3;
static const int32 INTELLIGENCE_IDLE_SAY = 4;
static const int32 COMMUNICATION_IDLE_SAY = 4;
static const int32 MEDICAL_IDLE_SAY = 4;
static const int32 ENGINEER_IDLE_SAY = 4;
static const int32 WEAPONS_IDLE_SAY = 4;
static const int32 SERGEANT_IDLE_SAY = 4;
static const int32 COMMANDER_IDLE_SAY = 4;
static const int32 LEADER_IDLE_SAY = 4;
static const int32 MAXSAY = 5;
static const int32 ENTIRE_TEAM_SPOKE = 8;

/*
State DrillIdle
{
Begin:
	LoopAnim("DrillIdle",1,0);
	Sleep(0.05);
	EyeTrack();
	JL"Loop"
;
}
*/

/*
State DrillTalk
{
Begin:
	Sleep(0.05);
	EyeTrack();
	if (fLastUsedTime > GetWorld()->GetTimeSeconds())
	{
		LoopAnim("DrillTalk");
		JL"Loop"
;
	}
	GotoState("DrillIdle","Begin");
}
*/

/*
State DrillTalkHands
{
Begin:
	PlayAnim("DrillHandsTransition",1,1);
	Sleep(0.05);
	EyeTrack();
	if (fLastUsedTime > GetWorld()->GetTimeSeconds())
	{
		LoopAnim("DrillTalkHands");
		JL"Loop"
;
	}
	PlayAnim("DrillHandsTransitionBack",1,1);
	Sleep(0.5);
	GotoState("DrillIdle","Begin");
}
*/

/*
State DrillTalkHandsRandom
{
Begin:
	Sleep(0.1);
	if (fTalkHandsRandomTimer > GetWorld()->GetTimeSeconds())
	{
		LoopAnim("DrillTalkHands",1,0.1);
		JL"HANDS"
;
	}
	fTalkHandsRandomTimer=((GetWorld()->GetTimeSeconds() + 3) + (FMath::FRand() * 3));
	PlayAnim("DrillHandsTransitionBack",1,0.3);
	Sleep(0.5);
	Sleep(0.05);
	EyeTrack();
	if (fLastUsedTime > GetWorld()->GetTimeSeconds())
	{
		if (((FMath::FRand() > 0.8) && (fTalkHandsRandomTimer < GetWorld()->GetTimeSeconds())) && (fLastUsedTime > (GetWorld()->GetTimeSeconds() + 6)))
		{
			fTalkHandsRandomTimer=((GetWorld()->GetTimeSeconds() + 4) + (FMath::FRand() * 3));
			PlayAnim("DrillHandsTransition",1,0.3);
			Sleep(0.5);
			JL"HANDS"
;
		}
		else
		{
			LoopAnim("DrillTalk",1,0.3);
		}
		JL"Loop"
;
	}
	Sleep(0.1);
	GotoState("DrillIdle","Begin");
}
*/


float ANPC_SpecialForces::infront2(FVector vec)
{
	FVector LookDir = FVector(0, 0, 0);
	FVector AimDir = FVector(0, 0, 0);
	//LookDir = Vector(Rotation);
	//LookDir = Normal(LookDir);
	//AimDir = (vec - Location);
	//AimDir = Normal(AimDir);

	return FVector::DotProduct(LookDir, AimDir);
}

void ANPC_SpecialForces::EnableEyeTrack()
{
	bEyeTrack = true;
}

void ANPC_SpecialForces::DisableEyeTrack()
{
	bEyeTrack = false;
}

void ANPC_SpecialForces::BeginPlay()
{
	SetVoiceType(VoiceType);
}

void ANPC_SpecialForces::PostBeginPlay()
{
	Super::PostBeginPlay();
	vStartLocation = GetActorLocation();
	vStartRotation = GetActorRotation();
	SetAttachments();
	//rLEyeBall = GetBoneRotation("BN_LEyeBall");
	//rREyeBall = GetBoneRotation("BN_REyeBall");
	//rNeck = GetBoneRotation("Neck");
}

void ANPC_SpecialForces::ConfigureLinkDamage()
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
void ANPC_SpecialForces::TakeDamage(int32 Damage, APawn* instigatedBy, Fector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
	FVector MomentumDir = FVector(0, 0, 0);
	TriggerEvent(DamageEvent, this, instigatedBy);
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, ET_Destroyed, instigatedBy);
	}
	if ((DamageObjective != nullptr) || NPC_DamageOn)
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

void ANPC_SpecialForces::UndoDeath()
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
	if (AnimateType != EAnimateType::ANIMATE_None)
	{
		//GotoState("DrillIdle", "Init");
	}
	else
	{
		//GotoState("None");
	}
}

void ANPC_SpecialForces::MatchStarting()
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

void ANPC_SpecialForces::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	DoAnimLoop();
}

void ANPC_SpecialForces::DoAnimLoop()
{
	if ((AnimSequence != "None") && (AnimSequence != "None"))
	{
		//LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
	}
}

bool ANPC_SpecialForces::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_SpecialForces::SetVoiceType(EVoiceType aVoiceType)
{
	int32 i = 0;
	switch (aVoiceType)
	{
	case EVoiceType::VT_Leader:
		i = 0;
		if (i < 5)
		{
			if (LeaderLipsinc[i] != "None")
			{
				VSound[i] = LeaderLipsinc[i];
				SSound[i] = LeaderSound[i];
				UsedCountMax++;
			}
			i++;
			break;
		}
		break;
	case EVoiceType::VT_Commander:
		for (i = 0; i < 5; i++)
		{
			if (CommanderLipsinc[i] != "None")
			{
				VSound[i] = CommanderLipsinc[i];
				SSound[i] = CommanderSound[i];
				UsedCountMax++;
			}
		}
		break;
	case EVoiceType::VT_Sergeant:
		for (i = 0; i < 5; i++)
		{
			if (SergeantLipsinc[i] != "None")
			{
				VSound[i] = SergeantLipsinc[i];
				SSound[i] = SergeantSound[i];
				UsedCountMax++;
			}
		}
		break;
	case EVoiceType::VT_Weapons:
		for (i = 0; i < 5; i++)
		{
			if (WeaponsLipsinc[i] != "None")
			{
				VSound[i] = WeaponsLipsinc[i];
				SSound[i] = WeaponsSound[i];
				UsedCountMax++;
			}
		}
		break;
	case EVoiceType::VT_Engineer:
		for (i = 0; i < 5; i++)
		{
			if (EngineerLipsinc[i] != "None")
			{
				VSound[i] = EngineerLipsinc[i];
				SSound[i] = EngineerSound[i];
				UsedCountMax++;
			}
		}
		break;
	case EVoiceType::VT_Medical:
		for (i = 0; i < 5; i++)
		{
			if (MedicalLipsinc[i] != "None")
			{
				VSound[i] = MedicalLipsinc[i];
				SSound[i] = MedicalSound[i];
				UsedCountMax++;
			}
		}
		break;
	case EVoiceType::VT_Communication:
		for (i = 0; i < 5; i++)
		{
			if (CommunicationLipsinc[i] != "None")
			{
				VSound[i] = CommunicationLipsinc[i];
				SSound[i] = CommunicationSound[i];
				UsedCountMax++;
			}
		}
		break;
	case EVoiceType::VT_Intelligence:
		for (i = 0; i < 5; i++)
		{
			if (IntelligenceLipsinc[i] != "None")
			{
				VSound[i] = IntelligenceLipsinc[i];
				SSound[i] = IntelligenceSound[i];
				UsedCountMax++;
			}
		}
		break;
	case EVoiceType::VT_StudentVendingMachine:
		for (i = 0; i < 5; i++)
		{
			if (StudentVendingMachineLipsinc[i] != "None")
			{
				VSound[i] = StudentVendingMachineLipsinc[i];
				UsedCountMax++;
			}
		}
		break;
	case EVoiceType::VT_Sarg:
		for (i = 0; i < 5; i++)
		{
			if (SargGoToClassLipsinc[i] != "None")
			{
				VSound[i] = SargGoToClassLipsinc[i];
				UsedCountMax++;
			}
		}
		for (i = 0; i < 5; i++)
		{
			if (SargGetInTruckLipsinc[i] != "None")
			{
				VSound[i] = SargGetInTruckLipsinc[i];
				UsedCountMax++;
			}
		}
		break;
	default:
		break;
	}
}

void ANPC_SpecialForces::SelectHandState()
{
	switch (AnimateType)
	{
	case EAnimateType::ANIMATE_None:
		//GotoState("None");
		break;
	case EAnimateType::ANIMATE_Talk:
		//GotoState("DrillTalk", "Begin");
		break;
	case EAnimateType::ANIMATE_TalkHands:
		//GotoState("DrillTalkHands", "Begin");
		break;
	case EAnimateType::ANIMATE_TalkHandsRandom:
		//GotoState("DrillTalkHandsRandom", "Begin");
		break;
	case EAnimateType::ANIMATE_DrillIdle:
		//GotoState("DrillIdle", "Begin");
		break;
	default:
		//GotoState("None");
		break;
	}
}

bool ANPC_SpecialForces::UsedBy(APawn* User)
{
	ANPC_SpecialForces* p = nullptr;
	bool bSomeOneIsTalkingAlready = false;
	int32 iGabrielDemoCounter = 0;
	float fsoundDurration = 0;
	USoundBase* _Sound = nullptr;
	FVector vVec = FVector(0, 0, 0);
	float fLen = 0;
	if (bUseDisabled)
	{
		return false;
	}
	/*
	vVec = (Location - User.Location);
	fLen = VSize(vVec);
	if (bNPCused == false)
	{
		return false;
	}
	bNPCused = false;
	if (fLen > 192)
	{
		return false;
	}
	if (float(nNPCusedtime) > GetWorld()->GetTimeSeconds())
	{
		return false;
	}
	bSomeOneIsTalkingAlready = false;
	if ((infront2(User.Location) > 0) && (fLastUsedTime < GetWorld()->GetTimeSeconds()))
	{
		ForEach AllActors(ANPC_SpecialForces::StaticClass(), p)
		{
			if (p.fLastUsedTime > GetWorld()->GetTimeSeconds())
			{
				bSomeOneIsTalkingAlready = true;
			}
			if (p.bGaveGabrielDemoTalk == true)
			{
				iGabrielDemoCounter++;
			}
		}
	}
	else
	{
		bSomeOneIsTalkingAlready = true;
	}
	if (bSomeOneIsTalkingAlready == false)
	{
		if (SSound[UsedCount] != nullptr)
		{
			_Sound = SSound[UsedCount];
			fsoundDurration = GetSoundDuration(_Sound);
			fLastUsedTime = (GetWorld()->GetTimeSeconds() + fsoundDurration);
		}
		else
		{
			fLastUsedTime = (GetWorld()->GetTimeSeconds() + 3);
		}
		if ((bGaveGabrielDemoTalk == false) || (iGabrielDemoCounter == 8))
		{
			if (AnimateType != 0)
			{
				SelectHandState();
			}
			PlayLIPSincAnim(VSound[UsedCount], 1, 512);
			bGaveGabrielDemoTalk = true;
			UsedCount++;
			if (UsedCount >= UsedCountMax)
			{
				UsedCount = 1;
			}
		}
	}
	nNPCusedtime = int((GetWorld()->GetTimeSeconds() + 1));
	return Controller.UsedBy(User);
	*/
	return false;     //FAKE   /ELiZ
}

void ANPC_SpecialForces::Touch(AActor* Other)
{
	//Controller.Touch(Other);
}

void ANPC_SpecialForces::SetAttachments()
{
	int32 i = 0;
	AActor* Item = nullptr;
	for (i = 0; i < Attachments.Num(); i++)
	{
		/*
		Item = Spawn(Attachments[i].Attachment);
		if (Item != nullptr)
		{
			AttachToBone(Item, Attachments[i].Bone);
		}
		else
		{
			Log("AGP_NPC::SetAttachments(): ERROR: Item is NONE");
			return;
		}
		Item.SetRelativeLocation(Attachments[i].LocationOffset);
		Item.SetRelativeRotation(Attachments[i].RotationOffset);
		if (Attachments[i].bUseParentScale)
		{
			Item.SetDrawScale(Self.DrawScale);
		}
		else
		{
			if (Attachments[i].Scale == 0)
			{
				Item.SetDrawScale(1);
			}
			else
			{
				Item.SetDrawScale(Attachments[i].Scale);
			}
		}
		*/
	}
}

void ANPC_SpecialForces::Tick(float DeltaTime)
{
	if (bEyeTrack)
	{
		EyeTrack();
	}
}
