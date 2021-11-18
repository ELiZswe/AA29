// All the original content belonged to the US Army


#include "AA29/AAGameplay/NPC_EEGuard/NPC_EEGuard.h"

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
		//PlayerBones(0) = (BodyPart = "head", BoneName = "Goggles1");
		//PlayerBones(1) = (BodyPart = "Chest", BoneName = "RuckSack");
		//PlayerBones(2) = (BodyPart = "ShoulderRight", BoneName = "RArmUp");
		//PlayerBones(3) = (BodyPart = "ShoulderLeft", BoneName = "LArmUp");
		//PlayerBones(4) = (BodyPart = "Abdomen", BoneName = "ButtPouch");
		//PlayerBones(5) = (BodyPart = "Pelvis", BoneName = "Pelvis");
		//PlayerBones(6) = (BodyPart = "KneeRight", BoneName = "RLegLow");
		//PlayerBones(7) = (BodyPart = "KneeLeft", BoneName = "LLegLow");
		//DebugVisionSkin = FinalBlend'T_AA2_UI.Misc_Grid_GreenF';
		//DebugAudioSkin = FinalBlend'T_AA2_UI.Misc_Grid_BlueF';
		//Mesh = SkeletalMesh'A_AA2_CharactersOpfor.OpforM_USTraining';
		SkeletalMesh->SetSkeletalMesh(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_USTraining.OpforM_USTraining'"), NULL, LOAD_None, NULL));
		//DrawScale = 1.13;
		//PrePivot = (X = 0, Y = 0, Z = -39);
		//Skins(0) = Texture'T_AA2_Characters.Inf.Soldier_PANTS_Forest_BDU_Clean';
		//Skins(1) = Texture'T_AA2_Characters.Inf.Soldier_SHIRT_Forest_BDU_Clean';
		//Skins(2) = Texture'T_AA2_Characters.Inf.Soldier_HAND_Inf_Cauc';
		//Skins(3) = Texture'T_AA2_Characters.Inf.Soldier_FACE_CaucA';
		//Skins(4) = Texture'T_AA2_Characters.SF.Skn_m9_Spec';
		//bCanTeleport = true;
		//CollisionHeight = 55;
}


/*
State Guarding
{
	Function ExtAlertedByDevice (Actor Device, Actor Instigator, bool bPlayerSpotted)
	{
		if (bPlayerSpotted)
		{
			TurnToActor(Instigator);
			GotoState('PlayerSpotted');
		}
	}
	Function ExtAlertedByFriend (Actor Instigator)
	{
		TurnToActor(Instigator);
		GotoState('AlertedByFriend');
	}
	Function ExtNoiseHeard ()
	{
		TurnToActor(Player);
		GotoState('HeardSomething');
	}
	Function CheckPlayerDetection ()
	{
		if (PlayerIsAudible())
		{
			TurnToActor(Player);
			GotoState('HeardSomething');
		}
		else
		{
			if (PlayerIsVisible())
			{
				TurnToActor(Player);
				GotoState('SawSomething');
			}
		}
	}
	Function Timer ()
	{
		HeardNoiseCount=0;
		AlertLevel=0;
	}
	Function Tick (float DeltaTime)
	{
		Global.i(DeltaTime);
		if (bDisabled)
		{
			Return;
		}
	}
	Function BeginState ()
	{
		SetNewLookTarget();
		SetTimer(45 + RandS(15),False);
	}
}
State HeardSomething
{
	Function ExtNoiseHeard ()
	{
		HeardNoiseCount ++;
		TurnToActor(Player);
		GotoState('HeardSomething');
	}
	Function Timer ()
	{
		if (PlayerIsVisible())
		{
			TurnToActor(Player);
			GotoState('SawSomething');
		}
		if (PlayerIsAudible())
		{
			HeardNoiseCount ++;
			TurnToActor(Player);
			GotoState('HeardSomething');
		}
	}
	Function Tick (float DeltaTime)
	{
		Global.i(DeltaTime);
	}
	Function BeginState ()
	{
		HeardNoiseCount ++;
		AlertLevel=2;
		SetTimer(DetectionInterval,True);
		if (bAlertFriends)
		{
			AlertFriends();
		}
		StopLookTargets();
	}
}
State SawSomething
{
	Function ExtNoiseHeard ()
	{
		TurnToActor(Player);
		GotoState('PlayerSpotted');
	}
	Function Timer ()
	{
		if (PlayerIsVisible())
		{
			TurnToActor(Player);
			GotoState('PlayerSpotted');
		}
		if (PlayerIsAudible())
		{
			TurnToActor(Player);
			GotoState('PlayerSpotted');
		}
	}
	Function Tick (float DeltaTime)
	{
		Global.i(DeltaTime);
		if (bNoGuard || bDisabled)
		{
			Return;
		}
	}
	Function BeginState ()
	{
		AlertLevel=2;
		SetTimer(DetectionInterval,True);
		EVENT_SawSomething();
		if (bAlertFriends)
		{
			AlertFriends();
		}
		StopLookTargets();
	}
}
State AlertedByFriend
{
	Function ExtNoiseHeard ()
	{
		TurnToActor(Player);
		GotoState('SawSomething');
	}
	Function Timer ()
	{
		if (PlayerIsVisible())
		{
			TurnToActor(Player);
			GotoState('SawSomething');
		}
		if (PlayerIsAudible())
		{
			TurnToActor(Player);
			GotoState('SawSomething');
		}
	}
	Function Tick (float DeltaTime)
	{
		Global.i(DeltaTime);
	}
	Function BeginState ()
	{
		AlertLevel=2;
		SetTimer(DetectionInterval,True);
		StopLookTargets();
	}
}
State PlayerSpotted
{
	Function Tick (float DeltaTime)
	{
		Global.i(DeltaTime);
		TurnToActor(Player);
	}
	Function BeginState ()
	{
		EVENT_PlayerSpotted();
	}
}
*/

void ANPC_EEGuard::PostBeginPlay ()
{
/*
	Super::PostBeginPlay();
	DeathCamera=GetActorByTag(DeathCameraTag);
	SetPhysics(2);
	GetLookTargets();
	GetFriends();
	DesiredRotation=Rotation;
	MultiTimer=Spawn(Class'MultiTimer');
	MultiTimer.SetTimerHost(Self);
	AnimHelper=Spawn('EEAnimHelper');
	AnimHelper.SetAnimHost(Self);
	if (bDebug)
	{
		VisionDistActor=CreateDebugSphere(DebugVisionSkin,4096);
		AudioDistActor=CreateDebugSphere(DebugAudioSkin,-4096);
	}
*/
}

void ANPC_EEGuard::Destroyed()
{
	/*
	VisionDistActor.Destroy();
	VisionDistActor = None;
	AudioDistActor.Destroy();
	AudioDistActor = None;
	*/
}
void ANPC_EEGuard::GetEyePosition()
{
	//Return MakeVect(Location.X, Location.Y, Location.Z + 48);
}
void ANPC_EEGuard::GetEyeRotation()
{
	//Return GetBoneRotation('Goggles1');
}
void ANPC_EEGuard::GetFriends()
{
	/*
	local NPC_EEGuard F;
	ForEach AllActors('NPC_EEGuard', F)
	{
		if (VSize(Location - F.Location) <= AlertFriendsRadius)
		{
			friends[friends.Length] = F;
		}
	}
	*/
}
void ANPC_EEGuard::GetLookTargets()
{
	/*
	local LookTarget L;
	local int i;
	local int j;
	if (LookTargetTag == 'None' || LookTargetTag == 'None')
	{
		Return;
	}
	else
	{
		ForEach AllActors(Class'LookTarget', L)
		{
			if (L.Tag == LookTargetTag)
			{
				LookTargets[LookTargets.Length] = L;
			}
		}
	}
	if (bSequenceLookTargets)
	{
		for (i = 0; i < LookTargets.Length; i++)
		{
			j = 0;
			if (j < LookTargets.Length - 1)
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
void ANPC_EEGuard::CreateDebugSphere(UMaterialInstance* aTexture, float YawRate)
{
	/*
	local AGP.DebugSphere D;
	D = Spawn(Class'DebugSphere');
	if (D != None)
	{
		D.bHidden = False;
		D.SetDrawScale(1);
		D.Skins[0] = aTexture;
		D.RotationRate.Yaw = YawRate;
	}
	Return D;
	*/
}
void ANPC_EEGuard::SetNewLookTarget()
{
	/*
	if (LookTargets.Length == 0)
	{
		Return;
	}
	if (bDebug)
	{
		Log("NPC_EEGuard::SetNewLookTarget(): Guard: " $ Self $ " - Tag: " $ Tag);
	}
	if (bSequenceLookTargets)
	{
		TurnToActor(LookTargets[NextLookTarget]);
		NextLookTarget++;
		if (NextLookTarget >= LookTargets.Length)
		{
			NextLookTarget = 0;
		}
	}
	else
	{
		TurnToActor(LookTargets[Rand(LookTargets.Length)]);
	}
	MultiTimer.StartTimer('SetNewLookTarget', FRand() * LookTargetIntervalMax - LookTargetIntervalMin + LookTargetIntervalMin, false);
	*/
}
void ANPC_EEGuard::StopLookTargets()
{
	//MultiTimer.StopTimer('SetNewLookTarget');
}
void ANPC_EEGuard::TurnToActor(AActor* Actor, float Rate)
{
	/*
	local Object.Rotator TempRot;
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
	/*
	if (!bInit)
	{
		FirstTickInit();
		Return;
	}
	SetRotation(Normalize(Rotation));
	DesiredRotation = Normalize(DesiredRotation);
	CheckTurning();
	if (bNoGuard || bDisabled)
	{
		Return;
	}
	PlayerDistance = GetPlayerDistance();
	if (PlayerDistance > MaxPlayerDistance)
	{
		ShrinkDebugSpheres();
		Return;
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
	/*
	bInit = true;
	AnimHelper.BeginAnims();
	Player = AGP_Pawn(Level.GetClientPawn());
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
	/*
	local float NoiseRadius;
	VisionDistActor.SetLocation(Location);
	VisionDistActor.SetDrawScale(VisualDetectDistance * 1 / 128);
	AudioDistActor.SetLocation(Location);
	NoiseRadius = PlayerDistance * 1 / NoiseThreshold * PlayerNoise;
	AudioDistActor.SetDrawScale(FClamp(NoiseRadius, DetectDistanceAudioMin, 65535) * 1 / 128);
	*/
}
void ANPC_EEGuard::ShrinkDebugSpheres()
{
	/*
	if (VisionDistActor != None)
	{
		VisionDistActor.SetDrawScale(1);
	}
	if (AudioDistActor != None)
	{
		AudioDistActor.SetDrawScale(1);
	}
	*/
}
void ANPC_EEGuard::AlertFriends()
{
	//MultiTimer.StartTimer('DoAlertFriends', 1, false);
}
void ANPC_EEGuard::DoAlertFriends()
{
	/*
	local int i;
	for (i = 0; i < friends.Length; i++)
	{
		if (friends[i] == None)
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
	/*
	if (bPlayerSpotted)
	{
		TurnToActor(aInstigator);
		GotoState('PlayerSpotted');
	}
	*/
}
void ANPC_EEGuard::GetVisualDetectDistance()
{
	//Return DetectDistanceVisual* PlayerVisibility* GetAlertLevelValue();
}
void ANPC_EEGuard::GetAudioDetectDistance()
{
	//Return DetectDistanceAudioMax* GetAlertLevelValue();
}
void ANPC_EEGuard::GetPlayerDistance()
{
	//Return VSize(Location - Player.Location);
}
void ANPC_EEGuard::PlayerIsVisible()
{
	/*
	if (PlayerDistance <= VisualDetectDistance && infront(Player.Location) > VisionCone)
	{
		Return PlayerIsReallyVisible();
	}
	else
	{
		Return False;
	}
	*/
}
void ANPC_EEGuard::PlayerIsReallyVisible()
{
	/*
	local int i;
	local int NumVisible;
	local int ReqVisible;
	local bool bVisible;
	local FVector BonePos;
	ReqVisible = GetReqVisBones();
	for (i = 0; i < PlayerBones.Length; i++)
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
	Return NumVisible >= ReqVisible;
	*/
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
void ANPC_EEGuard::PlayerIsAudible()
{
	/*
	if (PlayerDistance <= AudioDetectDistance && PlayerNoise > NoiseThreshold || PlayerDistance <= DetectDistanceAudioMin)
	{
		Return True;
	}
	else
	{
		Return False;
	}
	*/
}
void ANPC_EEGuard::GetPlayerNoise()
{
	/*
	local float NoiseLevel;
	NoiseLevel = 1 - PlayerDistance / AudioDetectDistance;
	NoiseLevel *= PlayerAudibility;
	NoiseLevel = FClamp(NoiseLevel, 0, 65535);
	Return NoiseLevel;
	*/
}
void ANPC_EEGuard::GetAlertLevelValue()
{
	/*
	Switch(AlertLevel)
	{
		case 0:
			Return AlertLevel_Low;
		case 1:
			Return AlertLevel_Medium;
		case 2:
			Return AlertLevel_High;
		default:
	}
	*/
}
void ANPC_EEGuard::ExtMakeNoise(AActor* aInstigator, float Loudness)
{
	/*
	local float NoiseLevel;
	local float Distance;
	Distance = VSize(aInstigator.Location - Location);
	NoiseLevel = 1 - Distance / AudioDetectDistance;
	NoiseLevel *= Loudness;
	NoiseLevel = FClamp(NoiseLevel, 0, 65535);
	if (bDebug)
	{
		Log("NPC_EEGuard::ExtMakeNoise(): NoiseLevel: " $ NoiseLevel);
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
void ANPC_EEGuard::infront(FVector vec)
{
	/*
	local FVector LookDir;
	local FVector AimDir;
	LookDir = Vector(Rotation);
	LookDir = Normal(LookDir);
	AimDir = vec - GetEyePosition();
	AimDir = Normal(AimDir);
	Return LookDir Dot AimDir;
	*/
}
void ANPC_EEGuard::FRandS()
{
	/*
	if (FRand() >= 0.5)
	{
		Return FRand() * -1;
	}
	else
	{
		Return FRand();
	}
	*/
}
void ANPC_EEGuard::RandS(int32 Num)
{
	/*
	if (Rand(2) == 0)
	{
		Return Rand(Num) * -1;
	}
	else
	{
		Return Rand(Num);
	}
	*/
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
	GotoState('None');
	*/
}
void ANPC_EEGuard::EVENT_HeardSomething()
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 31, None, "HEARSOMETHING");
	}
	*/
}
void ANPC_EEGuard::EVENT_SawSomething()
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 31, None, "SEESOMETHING");
	}
	*/
}
void ANPC_EEGuard::EVENT_PlayerSpotted()
{
	/*
	TriggerEvent(DeathEvent, Self, Player);
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 31, None, "PLAYERSPOTTED");
	}
	*/
}
void ANPC_EEGuard::EVENT_FalseAlarm()
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 31, None, "FALSEALARM");
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


