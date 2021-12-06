// All the original content belonged to the US Army


#include "AA29/Object/Actor/AAGameplay/EESpotLight/EESpotLight.h"
#include "AA29/Object/Actor/AAGameplay/DynLight/DynLight.h"
#include "AA29/Object/Actor/AAGameplay/EESpotLightPart/EESpotLightPart.h"
#include "AA29/Object/Actor/AAGameplay/NPC_EEGuard/NPC_EEGuard.h"
#include "AA29/Object/Actor/AAGameplay/DebugSphere/DebugSphere.h"
#include "AA29/Keypoint/LookTarget/LookTarget.h"
#include "AA29/MultiTimer/MultiTimer.h"

#include "Kismet/GameplayStatics.h"

AEESpotLight::AEESpotLight()
{
	bLookAround = true;
	LookTargetIntervalMin = 5;
	LookTargetIntervalMax = 10;
	RotationSpeed = 4096;
	SpotScale = 256;
	BrightnessFactor = 1000;
	DetectionFactor = 20;
	MaxTraceDist = 8192;
	//DebugDetectSkin = FinalBlend'T_AA2_UI.Misc_Grid_GreenF';
	//PlayerBones(0) = (BodyPart = "head", BoneName = "Goggles1");
	//PlayerBones(1) = (BodyPart = "Chest", BoneName = "RuckSack");
	//PlayerBones(2) = (BodyPart = "ShoulderRight", BoneName = "RArmUp");
	//PlayerBones(3) = (BodyPart = "ShoulderLeft", BoneName = "LArmUp");
	//PlayerBones(4) = (BodyPart = "Abdomen", BoneName = "ButtPouch");
	//PlayerBones(5) = (BodyPart = "Pelvis", BoneName = "Pelvis");
	//PlayerBones(6) = (BodyPart = "KneeRight", BoneName = "RLegLow");
	//PlayerBones(7) = (BodyPart = "KneeLeft", BoneName = "LLegLow");
	DrawType = EDrawType::DT_StaticMesh;
	StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Lights/exterior/spot-light-bracket.spot-light-bracket'"), NULL, LOAD_None, NULL));

	StaticMesh->SetCastShadow(false);
	StaticMesh->SetReceivesDecals(false);

	//bUseDynamicLights = false;
	//Physics = 8;
	
	//bCanTeleport = false;
	//CollisionRadius = 16;
	//CollisionHeight = 1;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bBlockPlayers = false;
	
	//bBlockNonZeroExtentTraces = false;
	//bUseCylinderCollision = false;
	//bBlockBulletTraces = false;
}

void AEESpotLight::BeginPlay()
{
	Super::BeginPlay();

	Init();
	GetLookTargets();
	GetHost();
	InitDLight();
	InitVolumeLight();

	//	mT = Spawn(Class'MultiTimer');
	UWorld* const World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		mT = World->SpawnActor<AMultiTimer>(AMultiTimer::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	}


	//mT = Spawn(Class'MultiTimer');
	if (mT != nullptr)
	{
		mT->SetTimerHost(this);
	}
	SetNewLookTarget();
	
	if (bDebug)
	{
		DetectDistActor = CreateDebugSphere(DebugDetectSkin, 4096);
	}

}
void AEESpotLight::Init()
{
	//this is the LightHousing
	UWorld* const World = GetWorld();
	if (World)
	{
		FVector Location = FVector(0, 0, 80);
		FRotator Rotation = FRotator(0, 0, 0);;
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		Light = World->SpawnActor<AEESpotLightPart>(AEESpotLightPart::StaticClass(), Location, Rotation, SpawnParams);
		Light->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	}
	if (Light != nullptr)
	{
		//Light.SetBase(Self);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EESpotLight::Init(): Error: Couldn't spawn EESpotLightPart"));
	}
	
}
void AEESpotLight::InitVolumeLight()
{
	/*
	local FVector N;
	N = Normal(Vector(Light.Rotation));
	N *= 26 * DrawScale;
	SpotHaze = Spawn('SpotHaze', Light, 'SpotHaze', N + Light.Location + MakeVect(0, 0, 0), Light.Rotation);
	if (SpotHaze != None)
	{
		SpotHaze.SetBase(Light);
	}
	else
	{
		Log("EESpotLight::InitVolumeLight(): Error: Couldn't spawn SpotHaze");
	}
	*/
}
void AEESpotLight::InitDLight()
{
	//this is the Light
	UWorld* const World = GetWorld();
	if (World)
	{
		FVector Location = FVector(0, 0, 80);
		FRotator Rotation = FRotator(90, 0, 0);;

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		DLight = World->SpawnActor<ADynLight>(ADynLight::StaticClass(), Location, Rotation, SpawnParams);
		DLight->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	}
	if (DLight != nullptr)
	{
		//Below was commented out in 2.4.1 as well
		//DLight.SetBase( Self );
		//DLight.SetRelativeLocation( MakeVect(0,0,40) );
		//DLight.SetRelativeRotation( MakeRot(0,0,0) );
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EESpotLight::InitDLight(): Error: Couldn't spawn DynLight"));
	}
}
void AEESpotLight::GetLookTargets()
{
	
	ALookTarget* L = nullptr;
	ALookTarget* LTemp = nullptr;
	int32 i=0;
	int32 j=0;
	if (LookTargetTag == "None" || LookTargetTag == "")
	{
		return;
	}
	else
	{
		TArray<AActor*> TargetActor;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(LookTargetTag), TargetActor);
		for (AActor* Actor : TargetActor)
		{
			if (Actor->IsA(ALookTarget::StaticClass()))
			{
				LookTargets.Add(Cast<ALookTarget>(Actor));
			}
		}
	}
	
	//Sort array if we are supposed to sequence looktargets
	if (bSequenceLookTargets)
	{
		//Bubble sort
		for (i = 0; i < LookTargets.Num()-1; i++)
		{
			//Don't do loop for last array element (length-1)
			for (j = 0; j < LookTargets.Num() - 2; j++)
			{
				//If next element is less than current, swap 'em
				if (LookTargets[j + 1]->Sequence < LookTargets[j]->Sequence)
				{
					LTemp = LookTargets[j + 1];
					LookTargets[j + 1] = LookTargets[j];
					LookTargets[j] = LTemp;
				}
			}
		}
	}

}
void AEESpotLight::GetHost()
{
	if (GuardTag == "None")
	{
		return;
	}

	TArray<AActor*> TargetActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(GuardTag), TargetActor);
	for (AActor* Actor : TargetActor)
	{
		if (Actor->IsA(ANPC_EEGuard::StaticClass()))
		{
			MyGuard = Cast<ANPC_EEGuard>(Actor);
			return;
		}
	}
	//Log("EESpotLight::GetHost(): Error: Guard not found: " $ GuardTag $ " for SpotLight: " $ Self);
}
ADebugSphere* AEESpotLight::CreateDebugSphere(UMaterialInstance* aTexture, float YawRate)
{
	
	ADebugSphere* D = nullptr;

	UWorld* const World = GetWorld();
	if (World)
	{
		FVector Location = FVector(0, 0, 0);
		FRotator Rotation = FRotator(0, 0, 0);;
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		D = World->SpawnActor<ADebugSphere>(ADebugSphere::StaticClass(), Location, Rotation, SpawnParams);
		D->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	}
	//D = Spawn(Class'DebugSphere', , , , MakeRot(0, 0, 0));
	if (D != nullptr)
	{
		//D.bHidden = False;
		//D->SetDrawScale(1);
		//D->Skins[0] = aTexture;
		//D->RotationRate.Yaw = YawRate;
	}
	return D;
}
void AEESpotLight::Tick(float DeltaTime)
{
	/*
	if (!bInit)
	{
		bInit = true;
		Player = AGP_Pawn(Level.GetClientPawn());
	}
	PlayerDistance = VSize(SpotLocation - Player.Location);
	UpdateDLight();
	if (bSearchForPlayer)
	{
		CheckPlayerDetection();
	}
	if (bDebug)
	{
		UpdateDebugSpheres();
	}
	*/
}
void AEESpotLight::CheckPlayerDetection()
{
	/*
	if (PlayerIsVisible() && !bPlayerDetected)
	{
		bPlayerDetected = true;
		TurnToActor(Player);
		mT.StartTimer('PlayerSpotted', 2);
		mT.StartTimer('ResetPlayerDetected', 5);
		StopLookTargets();
	}
	*/
}
bool AEESpotLight::PlayerIsVisible()
{
	if (PlayerDistance <= GetDetectDistance())
	{
		return PlayerIsReallyVisible();
	}
	else
	{
		return false;
	}
}
bool AEESpotLight::PlayerIsReallyVisible()
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
		bVisible = FastTrace(BonePos, Light.Location);
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
	return false;     //  FAKE   /ELiZ
}
int32 AEESpotLight::GetReqVisBones()
{
	return 3;
}
void AEESpotLight::UpdateDebugSpheres()
{
	/*
	DetectDistActor.SetLocation(SpotLocation);
	DetectDistActor.SetDrawScale(GetDetectDistance() * 1 / 128);
	*/
}
float AEESpotLight::GetDetectDistance()
{
	//return DLight.LightRadius* DetectionFactor;

	return 100.0f;    //FAKE   /ELiZ
}

void AEESpotLight::TimerNotify(FName TimerName, AMultiTimer* Timer)
{
	/*
	Switch(TimerName)
	{
			case 'SetNewLookTarget':
				SetNewLookTarget();
				break;
			case 'PlayerSpotted':
				PlayerSpotted();
				break;
			case 'ResetPlayerDetected':
				ResetPlayerDetected();
				break;
			default:
				break;
	}
	*/
}

void AEESpotLight::SetNewLookTarget()
{
	/*
	if (LookTargets.Num() == 0 || !bLookAround)
	{
		return;
	}
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
		TurnToActor(LookTargets[Rand(LookTargets.Length)]);
	}
	mT.StartTimer('SetNewLookTarget', FRand() * LookTargetIntervalMax - LookTargetIntervalMin + LookTargetIntervalMin, false);
	*/
}
void AEESpotLight::StopLookTargets()
{
	//mT.StopTimer('SetNewLookTarget');
}
void AEESpotLight::TurnToActor(AActor* Actor, float Rate)
{
	/*
	local Object.Rotator TempRot;
	if (Rate == 0)
	{
		if (bMountedSideways)
		{
			RotationRate.Pitch = RotationSpeed;
			Light.RotationRate.Yaw = RotationSpeed;
		}
		else
		{
			RotationRate.Yaw = RotationSpeed;
			Light.RotationRate.Pitch = RotationSpeed;
		}
	}
	else
	{
		if (bMountedSideways)
		{
			RotationRate.Pitch = Rate;
			Light.RotationRate.Yaw = Rate;
		}
		else
		{
			RotationRate.Yaw = Rate;
			Light.RotationRate.Pitch = Rate;
		}
	}
	TempRot = Normalize(Actor.Location - Location);
	if (bMountedSideways)
	{
		DesiredRotation.Pitch = TempRot.Pitch;
		Light.DesiredRotation.Yaw = TempRot.Yaw;
	}
	else
	{
		DesiredRotation.Yaw = TempRot.Yaw;
		Light.DesiredRotation.Pitch = TempRot.Pitch;
	}
	bRotateToDesired = true;
	Light.bRotateToDesired = true;
	*/
}
void AEESpotLight::UpdateDLight()
{
	/*
	FVector X;
	FVector Y;
	FVector Z;
	FVector HitLocation;
	FVector HitNormal;
	FVector StartTrace;
	FVector EndTrace;
	AActor* HitActor;
	GetAxes(Light.Rotation, X, Y, Z);
	StartTrace = Light.Location + CollisionRadius * X;
	EndTrace = StartTrace + MaxTraceDist * X;
	HitActor = Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	DLight.LightBrightness = 1 - VSize(Location - HitLocation) / MaxTraceDist * BrightnessFactor;
	DLight.LightRadius = VSize(Location - HitLocation) / MaxTraceDist * SpotScale;
	SpotLocation = HitLocation;
	HitLocation += HitNormal * 64;
	DLight.SetLocation(HitLocation);
	*/
}
void AEESpotLight::UpdateVolumeLight()
{
	/*
	FVector N;
	N = Normal(Vector(Light.Rotation));
	N *= 32 * DrawScale;
	SpotHaze.SetLocation(N + Light.Location);
	*/
}
void AEESpotLight::PlayerSpotted()
{
	/*
	if (MyGuard != nullptr)
	{
		MyGuard.ExtAlertedByDevice(Self, Player, true);
	}
	*/
}
void AEESpotLight::ResetPlayerDetected()
{
	bPlayerDetected = false;
	SetNewLookTarget();
}
