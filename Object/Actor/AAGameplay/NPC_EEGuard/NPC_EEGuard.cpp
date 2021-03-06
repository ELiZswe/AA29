// All the original content belonged to the US Army

#include "AA29/Object/Actor/AAGameplay/NPC_EEGuard/NPC_EEGuard.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AAGameplay/DebugSphere/DebugSphere.h"
#include "AA29/Object/Actor/AAGameplay/EEAnimHelper/EEAnimHelper.h"
#include "AA29/Object/Actor/MultiTimer/MultiTimer.h"
#include "AA29/Object/Actor/Keypoint/LookTarget/LookTarget.h"

ANPC_EEGuard::ANPC_EEGuard()
{
	DetectDistanceVisual = 1536;
	DetectDistanceAudioMin = 256;
	DetectDistanceAudioMax = 2048;
	VisionCone = 0.5;
	NoiseThreshold = 0.5;
	NoiseMax = 3;
	InvestigateTime = 5;
	bNoGuard = true;
	bDebug = true;
	LookTargetIntervalMin = 5;
	LookTargetIntervalMax = 10;
	bLookAround = true;
	AlertLevel_Low = 1;
	AlertLevel_Medium = 1.2;
	AlertLevel_High = 1.5;
	MaxPlayerDistance = 4096;
	AlertFriendsRadius = 1024;
	bAlertFriends = true;
	bAlertRecieve = true;
	DetectionInterval = 1.5;
	PlayerBones = {
		FBoneProfile({ "head", "Goggles1" }),
		FBoneProfile({ "Chest", "RuckSack" }),
		FBoneProfile({ "ShoulderRight", "RArmUp" }),
		FBoneProfile({ "ShoulderLeft", "LArmUp" }),
		FBoneProfile({ "Abdomen", "ButtPouch" }),
		FBoneProfile({ "Pelvis", "Pelvis" }),
		FBoneProfile({ "KneeRight", "RLegLow" }),
		FBoneProfile({ "KneeLeft", "LLegLow" })
	};
	//DebugVisionSkin = FinalBlend'T_AA2_UI.Misc_Grid_GreenF';
	//DebugAudioSkin = FinalBlend'T_AA2_UI.Misc_Grid_BlueF';
	//Mesh = SkeletalMesh'A_AA2_CharactersOpfor.OpforM_USTraining';
	SkeletalMesh->SetSkeletalMesh(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_USTraining.OpforM_USTraining'"), NULL, LOAD_None, NULL));
	//DrawScale = 1.13;
	//PrePivot = (X = 0, Y = 0, Z = -39);
	/*
	Skins = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_PANTS_Forest_BDU_Clean_Mat.Soldier_PANTS_Forest_BDU_Clean_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_SHIRT_Forest_BDU_Clean_Mat.Soldier_SHIRT_Forest_BDU_Clean_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Cauc_Mat.Soldier_HAND_Inf_Cauc_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_CaucA_Mat.Soldier_FACE_CaucA_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Skn_m9_Spec_Mat.Skn_m9_Spec_Mat'"), NULL, LOAD_None, NULL)
	};
	*/
	//bCanTeleport = true;
	//CollisionHeight = 55;
}

/*
State Guarding
{
	Function BeginState()
	{
		SetNewLookTarget();
		SetTimer((45 + float(RandS(15))),false);
	}
	Function Tick(float DeltaTime)
	{
		Global.i(DeltaTime);
		if (bDisabled)
		{
			return;
		}
	}
	Function Timer()
	{
		HeardNoiseCount=0;
		AlertLevel=0;
	}
	Function CheckPlayerDetection()
	{
		if (PlayerIsAudible())
		{
			TurnToActor(Player);
			GotoState("HeardSomething");
		}
		else
		{
			if (PlayerIsVisible())
			{
				TurnToActor(Player);
				GotoState("SawSomething");
			}
		}
	}
	Function ExtNoiseHeard()
	{
		TurnToActor(Player);
		GotoState("HeardSomething");
	}
	Function ExtAlertedByFriend(AActor* Instigator)
	{
		TurnToActor(Instigator);
		GotoState("AlertedByFriend");
	}
	Function ExtAlertedByDevice(AActor* Device, AActor* Instigator, bool bPlayerSpotted)
	{
		if (bPlayerSpotted)
		{
			TurnToActor(Instigator);
			GotoState("PlayerSpotted");
		}
	}
}
*/

/*
State HeardSomething
{
	Function BeginState()
	{
		HeardNoiseCount ++;
		AlertLevel=2;
		SetTimer(DetectionInterval,true);
		if (bAlertFriends)
		{
			AlertFriends();
		}
		StopLookTargets();
	}
	Function Tick(float DeltaTime)
	{
		Global.i(DeltaTime);
	}
	Function Timer()
	{
		if (PlayerIsVisible())
		{
			TurnToActor(Player);
			GotoState("SawSomething");
		}
		if (PlayerIsAudible())
		{
			HeardNoiseCount ++;
			TurnToActor(Player);
			GotoState("HeardSomething");
		}
	}
	Function ExtNoiseHeard()
	{
		HeardNoiseCount ++;
		TurnToActor(Player);
		GotoState("HeardSomething");
	}
Begin:
	if (HeardNoiseCount >= NoiseMax)
	{
		GotoState("PlayerSpotted");
	}
	else
	{
		EVENT_HeardSomething();
	}
	Sleep((InvestigateTime + FRandS()));
	EVENT_FalseAlarm();
	AlertLevel=1;
	GotoState("Guarding");
}
*/

/*
State SawSomething
{
	Function BeginState()
	{
		AlertLevel=2;
		SetTimer(DetectionInterval,true);
		EVENT_SawSomething();
		if (bAlertFriends)
		{
			AlertFriends();
		}
		StopLookTargets();
	}
	Function Tick(float DeltaTime)
	{
		Global.i(DeltaTime);
		if (bNoGuard || bDisabled)
		{
			return;
		}
	}
	Function Timer()
	{
		if (PlayerIsVisible())
		{
			TurnToActor(Player);
			GotoState("PlayerSpotted");
		}
		if (PlayerIsAudible())
		{
			TurnToActor(Player);
			GotoState("PlayerSpotted");
		}
	}
	Function ExtNoiseHeard()
	{
		TurnToActor(Player);
		GotoState("PlayerSpotted");
	}
Begin:
	Sleep((InvestigateTime + FRandS()));
	AlertLevel=1;
	EVENT_FalseAlarm();
	GotoState("Guarding");
}
*/

/*
State AlertedByFriend
{
	Function BeginState()
	{
		AlertLevel=2;
		SetTimer(DetectionInterval,true);
		StopLookTargets();
	}
	Function Tick(float DeltaTime)
	{
		Global.i(DeltaTime);
	}
	Function Timer()
	{
		if (PlayerIsVisible())
		{
			TurnToActor(Player);
			GotoState("SawSomething");
		}
		if (PlayerIsAudible())
		{
			TurnToActor(Player);
			GotoState("SawSomething");
		}
	}
	Function ExtNoiseHeard()
	{
		TurnToActor(Player);
		GotoState("SawSomething");
	}
Begin:
	Sleep((InvestigateTime + FRandS()));
	AlertLevel=1;
	GotoState("Guarding");
}
*/

/*
State PlayerSpotted
{
	Function BeginState()
	{
		EVENT_PlayerSpotted();
	}
	Function Tick(float DeltaTime)
	{
		Global.i(DeltaTime);
		TurnToActor(Player);
	}
}
*/

void ANPC_EEGuard::PostBeginPlay()
{
/*
	Super::PostBeginPlay();
	DeathCamera=GetActorByTag(DeathCameraTag);
	SetPhysics(2);
	GetLookTargets();
	GetFriends();
	DesiredRotation=Rotation;
	MultiTimer=Spawn(AMultiTimer::StaticClass());
	MultiTimer.SetTimerHost(this);
	AnimHelper=Spawn('EEAnimHelper');
	AnimHelper.SetAnimHost(this);
	if (bDebug)
	{
		VisionDistActor=CreateDebugSphere(DebugVisionSkin,4096);
		AudioDistActor=CreateDebugSphere(DebugAudioSkin,-4096);
	}
*/
}

void ANPC_EEGuard::Destroyed()
{
	VisionDistActor->Destroy();
	VisionDistActor = nullptr;
	AudioDistActor->Destroy();
	AudioDistActor = nullptr;
}

FVector ANPC_EEGuard::GetEyePosition()
{
	FVector EyeLocation = FVector(0, 0, 0);
	EyeLocation = GetActorLocation();
	EyeLocation.Z += 48;
	return EyeLocation;
}

FRotator ANPC_EEGuard::GetEyeRotation()
{
	//return GetBoneRotation('Goggles1');
	return FRotator(0, 0, 0);
}

void ANPC_EEGuard::GetFriends()
{
	ANPC_EEGuard* F = nullptr;
	/*
	ForEach AllActors('NPC_EEGuard', F)
	{
		if (VSize(Location - F.Location) <= AlertFriendsRadius)
		{
			friends[friends.Num()] = F;
		}
	}
	*/
}

void ANPC_EEGuard::GetLookTargets()
{
	ALookTarget* L = nullptr;
	int32 i = 0;
	int32 j = 0;
	/*
	if (LookTargetTag == "None" || LookTargetTag == "None")
	{
		return;
	}
	else
	{
		ForEach AllActors(ALookTarget::StaticClass(), L)
		{
			if (L.Tag == LookTargetTag)
			{
				LookTargets[LookTargets.Num()] = L;
			}
		}
	}
	if (bSequenceLookTargets)
	{
		for (i = 0; i < LookTargets.Num(); i++)
		{
			j = 0;
			if (j < LookTargets.Num() - 1)
			{
				if (LookTargets[j + 1].Sequence < LookTargets[j].Sequence)
				{
					L = LookTargets[j + 1];
					LookTargets[j + 1] = LookTargets[j];
					LookTargets[j] = L;
				}
				j++;
			}
		}
	}
	*/
}

ADebugSphere* ANPC_EEGuard::CreateDebugSphere(UMaterialInstance* aTexture, float YawRate)
{
	ADebugSphere* D = nullptr;
	/*
	D = Spawn(ADebugSphere::StaticClass());
	if (D != nullptr)
	{
		D.bHidden = false;
		D.SetDrawScale(1);
		D.Skins[0] = aTexture;
		D.RotationRate.Yaw = YawRate;
	}
	*/
	return D;
}
void ANPC_EEGuard::SetNewLookTarget()
{
	if (LookTargets.Num() == 0)
	{
		return;
	}
	if (bDebug)
	{
		//Log("NPC_EEGuard::SetNewLookTarget(): Guard: " + this + " - Tag: " + Tag);
	}
	/*
	if (bSequenceLookTargets)
	{
		TurnToActor(LookTargets[NextLookTarget]);
		NextLookTarget++;
		if (NextLookTarget >= LookTargets.Num())
		{
			NextLookTarget = 0;
		}
	}
	else
	{
		TurnToActor(LookTargets[Rand(LookTargets.Num())]);
	}
	MultiTimer.StartTimer('SetNewLookTarget', FMath::FRand() * LookTargetIntervalMax - LookTargetIntervalMin + LookTargetIntervalMin, false);
	*/
}

void ANPC_EEGuard::StopLookTargets()
{
	MultiTimer->StopTimer("SetNewLookTarget");
}

void ANPC_EEGuard::TurnToActor(AActor* Actor, float Rate)
{
	FRotator TempRot = FRotator(0,0,0);
	/*
	if (Rate == 0)
	{
		RotationRate.Yaw = 16384;
	}
	else
	{
		RotationRate.Yaw = Rate;
	}
	TempRot = Normalize(Actor.Location - Location);
	DesiredRotation.Yaw = TempRot.Yaw;
	bRotateToDesired = true;
	*/
}
void ANPC_EEGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bInit)
	{
		FirstTickInit();
		return;
	}
	/*
	SetActorRotation(Normalize(Rotation));
	DesiredRotation = Normalize(DesiredRotation);
	CheckTurning();
	if (bNoGuard || bDisabled)
	{
		return;
	}
	PlayerDistance = GetPlayerDistance();
	if (PlayerDistance > MaxPlayerDistance)
	{
		ShrinkDebugSpheres();
		return;
	}
	VisualDetectDistance = GetVisualDetectDistance();
	AudioDetectDistance = GetAudioDetectDistance();
	PlayerNoise = GetPlayerNoise();
	CheckPlayerDetection();
	if (bDebug)
	{
		UpdateDebugSpheres();
	}
	*/
}
void ANPC_EEGuard::FirstTickInit()
{
	bInit = true;
	/*
	AnimHelper.BeginAnims();
	Player = Cast<AAGP_Pawn>(Level.GetClientPawn());
	GotoState('Guarding');
	*/
}
void ANPC_EEGuard::CheckPlayerDetection()
{
}
void ANPC_EEGuard::CheckTurning()
{
	/*
	if (!AnimHelper.IsTurning() && Abs(DesiredRotation.Yaw - Rotation.Yaw) > 1000)
	{
		AnimHelper.PlayTurning();
	}
	*/
}

void ANPC_EEGuard::UpdateDebugSpheres()
{
	float NoiseRadius = 0;
	/*
	VisionDistActor.SetLocation(Location);
	VisionDistActor.SetDrawScale(VisualDetectDistance * 1 / 128);
	AudioDistActor.SetLocation(Location);
	NoiseRadius = PlayerDistance * 1 / NoiseThreshold * PlayerNoise;
	AudioDistActor.SetDrawScale(FClamp(NoiseRadius, DetectDistanceAudioMin, 65535) * 1 / 128);
	*/
}
void ANPC_EEGuard::ShrinkDebugSpheres()
{
	if (VisionDistActor != nullptr)
	{
		//VisionDistActor->SetDrawScale(1);
	}
	if (AudioDistActor != nullptr)
	{
		//AudioDistActor->SetDrawScale(1);
	}
}

void ANPC_EEGuard::AlertFriends()
{
	MultiTimer->StartTimer("DoAlertFriends", 1, false);
}

void ANPC_EEGuard::DoAlertFriends()
{
	int32 i = 0;
	/*
	for (i = 0; i < friends.Num(); i++)
	{
		if (friends[i] == nullptr)
		{
		}
		if (friends[i].bAlertRecieve)
		{
			friends[i].ExtAlertedByFriend(Player);
		}
	}
	*/
}
void ANPC_EEGuard::ExtAlertedByFriend(AActor* aInstigator)
{
}

void ANPC_EEGuard::ExtAlertedByDevice(AActor* Device, AActor* aInstigator, bool bPlayerSpotted)
{
	if (bPlayerSpotted)
	{
		TurnToActor(aInstigator,0);
		//GotoState('PlayerSpotted');
	}
}

float ANPC_EEGuard::GetVisualDetectDistance()
{
	return DetectDistanceVisual* PlayerVisibility* GetAlertLevelValue();
}

float ANPC_EEGuard::GetAudioDetectDistance()
{
	return DetectDistanceAudioMax* GetAlertLevelValue();
}

float ANPC_EEGuard::GetPlayerDistance()
{
	//return VSize(Location - Player.Location);
	return 0;    //FAKE  /ELiZ
}

bool ANPC_EEGuard::PlayerIsVisible()
{
	/*
	if (PlayerDistance <= VisualDetectDistance && infront(Player.Location) > VisionCone)
	{
		return PlayerIsReallyVisible();
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool ANPC_EEGuard::PlayerIsReallyVisible()
{
	int32 i = 0;
	int32 NumVisible = 0;
	int32 ReqVisible = 0;
	bool bVisible = false;
	FVector BonePos = FVector(0,0,0);
	/*
	ReqVisible = GetReqVisBones();
	for (i = 0; i < PlayerBones.Num(); i++)
	{
		BonePos = Player.GetBoneCoords(PlayerBones[i].BoneName).Origin;
		bVisible = FastTrace(BonePos, GetEyePosition());
		if (bVisible)
		{
			NumVisible++;
		}
		if (NumVisible >= ReqVisible)
		{
		}
	}
	return NumVisible >= ReqVisible;
	*/
	return false;    //FAKE   /ELiZ
}
int32 ANPC_EEGuard::GetReqVisBones()
{
	
	switch(AlertLevel)
	{
		case EAlertLevel::AL_Low:
			return 4;
		case EAlertLevel::AL_Medium:
			return 4;
		case EAlertLevel::AL_High:
			return 3;
		default:
			return 3;
	}
}

bool ANPC_EEGuard::PlayerIsAudible()
{
	/*
	if (PlayerDistance <= AudioDetectDistance && PlayerNoise > NoiseThreshold || PlayerDistance <= DetectDistanceAudioMin)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

float ANPC_EEGuard::GetPlayerNoise()
{
	float NoiseLevel = 0;
	/*
	NoiseLevel = 1 - PlayerDistance / AudioDetectDistance;
	NoiseLevel *= PlayerAudibility;
	NoiseLevel =FMath::Clamp(NoiseLevel, 0, 65535);
	*/
	return NoiseLevel;
}

float ANPC_EEGuard::GetAlertLevelValue()
{
	switch(AlertLevel)
	{
		case EAlertLevel::AL_Low:
			return AlertLevel_Low;
		case EAlertLevel::AL_Medium:
			return AlertLevel_Medium;
		case EAlertLevel::AL_High:
			return AlertLevel_High;
		default:
			return 0;
	}
}

void ANPC_EEGuard::ExtMakeNoise(AActor* aInstigator, float Loudness)
{
	float NoiseLevel = 0;
	float Distance = 0;
	/*
	Distance = VSize(aInstigator.Location - Location);
	NoiseLevel = 1 - Distance / AudioDetectDistance;
	NoiseLevel *= Loudness;
	NoiseLevel =FMath::Clamp(NoiseLevel, 0, 65535);
	if (bDebug)
	{
		Log("NPC_EEGuard::ExtMakeNoise(): NoiseLevel: " + NoiseLevel);
	}
	if (NoiseLevel >= NoiseThreshold)
	{
		ExtNoiseHeard();
	}
	*/
}
void ANPC_EEGuard::ExtNoiseHeard()
{
}

float ANPC_EEGuard::infront(FVector vec)
{
	FVector LookDir = FVector(0,0,0);
	FVector AimDir = FVector(0, 0, 0);
	/*
	LookDir = Vector(Rotation);
	LookDir = Normal(LookDir);
	AimDir = vec - GetEyePosition();
	AimDir = Normal(AimDir);
	return LookDir Dot AimDir;
	*/
	return 0;    //FAKE  /ELiZ
}

float ANPC_EEGuard::FRandS()
{
	if (FMath::FRand() >= 0.5)
	{
		return FMath::FRand() * -1;
	}
	else
	{
		return FMath::FRand();
	}
}

int32 ANPC_EEGuard::RandS(int32 Num)
{
	/*
	if (Rand(2) == 0)
	{
		return Rand(Num) * -1;
	}
	else
	{
		return Rand(Num);
	}
	*/
	return 0;   //FAKE  /ELiZ

}
void ANPC_EEGuard::ResetMe()
{
	bDisabled = false;
	//GotoState('Guarding');
	AlertLevel = EAlertLevel::AL_Low;
	HeardNoiseCount = 0;
}
void ANPC_EEGuard::DisableMe()
{
	/*
	bDisabled = true;
	GotoState("None");
	*/
}

void ANPC_EEGuard::EVENT_HeardSomething()
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 31, None, "HEARSOMETHING");
	}
	*/
}

void ANPC_EEGuard::EVENT_SawSomething()
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 31, None, "SEESOMETHING");
	}
	*/
}

void ANPC_EEGuard::EVENT_PlayerSpotted()
{
	/*
	TriggerEvent(DeathEvent, this, Player);
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 31, None, "PLAYERSPOTTED");
	}
	*/
}

void ANPC_EEGuard::EVENT_FalseAlarm()
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 31, None, "FALSEALARM");
	}
	*/
}

void ANPC_EEGuard::EVENT_ExtNoiseHeard(AActor* aInstigator)
{
	//EVENT_HeardSomething();
}

void ANPC_EEGuard::TimerNotify(FName TimerName, AMultiTimer* Timer)
{
	if (TimerName == "DoAlertFriends")
	{
		DoAlertFriends();
	}
	if (TimerName == "SetNewLookTarget")
	{
		SetNewLookTarget();
	}
}

void ANPC_EEGuard::Landed(FVector HitNormal)
{
	//SetPhysics(5);
}

