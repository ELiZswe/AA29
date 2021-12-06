// All the original content belonged to the US Army


#include "AA29/Object/Actor/AAGameplay/EEBlackHawk/EEBlackHawk.h"
#include "AA29/Object/Actor/Emitter/aux_light_signal/aux_light_signal.h"
#include "AA29/Object/Actor/AAGameplay/BHCrew/BHCrew.h"
#include "AA29/Object/Actor/Light/VolumeLight/BHLandingLight/BHLandingLight.h"
#include "AA29/Object/Actor/AAGameplay/BHM134A/BHM134A.h"
#include "AA29/Object/Actor/AAGameplay/EEBlackHawk_Collision/EEBlackHawk_Collision.h"
#include "Kismet/GameplayStatics.h"

AEEBlackHawk::AEEBlackHawk()
{
	SignalLights = { nullptr,nullptr,nullptr,nullptr };
	LandingLights = { nullptr,nullptr,nullptr,nullptr };
	ChopperSounds = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Misc/Vehicles/Helo1_Interior_Cue.Helo1_Interior_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Aircraft/blackhawk/Blackhawk_Loop1_Cue.Blackhawk_Loop1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Aircraft/blackhawk/Blackhawk_Loop5_Cue.Blackhawk_Loop5_Cue'"), NULL, LOAD_None,NULL)
		};

	bDoDLight = true;

	if (PilotMesh)
	{
		PilotMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		PilotMesh->SetSkeletalMesh(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryBasicACU.InfantryBasicACU'"), NULL, LOAD_None, NULL));
	}
	
	//bUseDynamicLights = false;
	//bNoDelete = true;
	
	PMC = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("PMC"));
	if (PMC)
	{
		PMC->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}

	PMC->SetSkeletalMesh(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Objects/BlackHawkB.BlackHawkB'"), NULL, LOAD_None, NULL));
	PMC->SetMaterial(0, LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Vehicles/blackhawk/skin_veh_blackhawkmain1b_Mat.skin_veh_blackhawkmain1b_Mat'"), NULL, LOAD_None, NULL));
	PMC->SetMaterial(1, LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Vehicles/blackhawk/skin_veh_blackhawkinside1b_Mat.skin_veh_blackhawkinside1b_Mat'"), NULL, LOAD_None, NULL));
	PMC->SetMaterial(2, LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Vehicles/blackhawk/skin_veh_blackhawkwindows1b_Mat.skin_veh_blackhawkwindows1b_Mat'"), NULL, LOAD_None, NULL));
	PMC->SetWorldScale3D(FVector(1.13, 1.13, 1.13));
	//PMC->SetReceivesDecals(false);


	//AmbientGlow = 32;
	//bStaticLighting = true;
	//bCanTeleport = true;
	//bCollideActors = false;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bBlockPlayers = false;
	
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bUseCylinderCollision = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;


	Crew.SetNum(5);
	Guns.SetNum(2);
}


void AEEBlackHawk::BeginPlay()
{
	Super::BeginPlay();

	InitChopper();
	InitCrew();
	InitGuns();
	InitLights();
	ResetAnims();    //Mine
	if (bLandingLightsStartOn)
	{
		TurnOnLandingLights();
	}
	else
	{
		TurnOffLandingLights();
	}
}
void AEEBlackHawk::ResetAnims()
{
	int32 i;
	//StopAnimating();
	for (i = 0; i < 5; i++)
	{
		Crew[i]->SkeletalMesh->PlayAnimation(nullptr,false);
	}
	
	for (i = 0; i < 2; i++)
	{
		Guns[i]->SkeletalMesh->PlayAnimation(nullptr,false);
	}

	Crew[0]->SkeletalMesh->PlayAnimation(LoadObject<UAnimSequence>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Pilot/BH_Pilot.BH_Pilot'"), NULL, LOAD_None, NULL), true);
	Crew[1]->SkeletalMesh->PlayAnimation(LoadObject<UAnimSequence>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Pilot/BH_CoPilot.BH_CoPilot'"), NULL, LOAD_None, NULL), true);
	Crew[2]->SkeletalMesh->PlayAnimation(LoadObject<UAnimSequence>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Pilot/BH_CrewIdle.BH_CrewIdle'"), NULL, LOAD_None, NULL), true);
	Crew[3]->SkeletalMesh->PlayAnimation(LoadObject<UAnimSequence>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Pilot/BH_Gunner.BH_Gunner'"), NULL, LOAD_None, NULL), true);
	Crew[4]->SkeletalMesh->PlayAnimation(LoadObject<UAnimSequence>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Pilot/BH_Gunner2.BH_Gunner2'"), NULL, LOAD_None, NULL), true);

	Guns[0]->SkeletalMesh->PlayAnimation(LoadObject<UAnimSequence>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_Weapons3P/m134_3P/BH_GunIdle.BH_GunIdle'"), NULL, LOAD_None, NULL), true);
	Guns[1]->SkeletalMesh->PlayAnimation(LoadObject<UAnimSequence>(NULL, TEXT("AnimSequence'/Game/AmericasArmy/Animations/A_AA2_Weapons3P/m134_3P/BH_GunIdle2.BH_GunIdle2'"), NULL, LOAD_None, NULL), true);

}
void AEEBlackHawk::TurnOnLandingLights()
{
	/*
	int32 i;
	for (i = 0; i < LandingLights.Num(); i++)
	{
		LandingLights[i]->TurnOn();
	}
	bDoDLight = true;
	*/
}
void AEEBlackHawk::TurnOffLandingLights()
{
	/*
	int32 i;
	for (i = 0; i < LandingLights.Num(); i++)
	{
		LandingLights[i]->TurnOff();
	}
	bDoDLight = false;
	*/
}
void AEEBlackHawk::InitChopper()
{
	//SetActorRotation(FRotator(0, 0, 0));
	UWorld* const World = GetWorld();
	if (World)
	{
		FVector Location = FVector(0, 0, 0);
		FRotator Rotation = FRotator(0, 180, 0);

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		CollisionActor = World->SpawnActor<AEEBlackHawk_Collision>(AEEBlackHawk_Collision::StaticClass(), Location, Rotation, SpawnParams);
		CollisionActor->AttachToComponent(StaticMesh, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	}


	if (CollisionActor != nullptr)
	{
		//CollisionActor->SetActorLocation(GetBoneCoords('Collision').Origin);
		//CollisionActor->SetActorRotation(GetBoneRotation('Collision'));
		CollisionActor->SetActorLocation(GetActorLocation());
		CollisionActor->SetActorRotation(GetActorRotation());
		CollisionActor->SetActorHiddenInGame(true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EEBlackHawk::InitChopper(): Unable to spawn CollisionActor"));
	}
	/*
	PlayerView = Spawn(Class'PlayerView');
	ViewMarker = Spawn(Class'Marker');
	if (PlayerView != None && ViewMarker != None)
	{
		PlayerView.SetLocation(Location + MakeVect(-32, -56, -72));
		PlayerView.SetRotation(Rotation);
		PlayerView.SetBase(Self);
		ViewMarker.SetLocation(PlayerView.Location);
		ViewMarker.SetRotation(PlayerView.Rotation);
		ViewMarker.SetBase(PlayerView);
	}
	else
	{
		Log("EEBlackHawk::InitChopper(): Couldn't spawn PlayerView or ViewMarker");
	}
	ChaseCamA = Spawn(Class'Marker');
	ChaseCamB = Spawn(Class'Marker');
	if (ChaseCamA != None && ChaseCamB != None)
	{
		ChaseCamA.bHidden = False;
		ChaseCamB.bHidden = False;
		ChaseCamA.Texture = None;
		ChaseCamB.Texture = None;
		ChaseCamA.SetBase(Self);
		ChaseCamB.SetBase(Self);
	}
	else
	{
		Log("EEBlackHawk::InitChopper(): Couldn't spawn ChaseCamA or ChaseCamB");
	}
	LightPoint = Spawn(Class'PlayerView');
	if (LightPoint != None)
	{
		LightPoint.bHidden = true;
		LightPoint.Texture = Texture'S_Actor';
		LightPoint.SetLocation(Location + MakeVect(220, 0, -162));
		LightPoint.SetRotation(MakeRot(0, 0, 0) + MakeRot(-14000, 0, 0));
		LightPoint.SetBase(Self);
	}
	else
	{
		Log("EEBlackHawk::InitChopper(): Couldn't spawn LightPoint");
	}
	DLight = Spawn('DynLight');
	if (DLight != None)
	{
		DLight.bHidden = true;
		DLight.LightBrightness = 0;
		DLight.LightRadius = 1;
	}
	else
	{
		Log("EEBlackHawk::InitDLight(): Error: Couldn't spawn DynLight");
	}
	*/
}
void AEEBlackHawk::InitLights()
{
	int32 i = 0;

	UWorld* const World = GetWorld();
	if (World)
	{
		for (i = 0; i < SignalLights.Num(); i++)
		{

			FVector Location = FVector(0, 0, 0);
			FRotator Rotation = FRotator(0, 180, 0);

			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SignalLights[i] = World->SpawnActor<Aaux_light_signal>(Aaux_light_signal::StaticClass(), Location, Rotation, SpawnParams);
			SignalLights[i]->SetSignalSize(16);
			switch (i)
			{
			case 0:
				SignalLights[i]->SetSignalColor(FColor(255, 0, 0, 255));
				//AttachToBone(SignalLights[i], 'NavLightTail');
				SignalLights[i]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "NavLightTail");
				break;
			case 1:
				SignalLights[i]->SetSignalColor(FColor(255, 0, 0, 255));
				//AttachToBone(SignalLights[i], 'NavLightBelly');
				SignalLights[i]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "NavLightBelly");
				break;
			case 2:
				SignalLights[i]->SetSignalColor(FColor(255, 0, 0, 255));
				//AttachToBone(SignalLights[i], 'NavLightPort');

				SignalLights[i]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "NavLightPort");
				break;
			case 3:
				SignalLights[i]->SetSignalColor(FColor(0, 255, 0, 255));
				//AttachToBone(SignalLights[i], 'NavLightStbd');
				SignalLights[i]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "NavLightStbd");
				break;
			default:
				break;
			}
		}
	}


	for (i = 0; i < LandingLights.Num(); i++)
	{
		FVector Location = FVector(0, 0, 0);
		FRotator Rotation = FRotator(0, 180, 0);

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		LandingLights[i] = World->SpawnActor<ABHLandingLight>(ABHLandingLight::StaticClass(), Location, Rotation, SpawnParams);
		//LandingLights[i] = Spawn('BHLandingLight');

		switch (i)
		{
		case 0:
			SignalLights[i]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "LandingLightFwStbd");
			//LandingLights[i].SetRelativeLocation(Normal(Vector(Rotation)) * 12);
			break;
		case 1:
			SignalLights[i]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "LandingLightBkStbd");
			//LandingLights[i].SetRelativeLocation(Normal(Vector(Rotation)) * 12);
			break;
		case 2:
			SignalLights[i]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "LandingLightFwPort");
			//LandingLights[i].SetRelativeLocation(Normal(Vector(Rotation)) * 12);
			break;
		case 3:
			SignalLights[i]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "LandingLightBkPort");
			//LandingLights[i].SetRelativeLocation(Normal(Vector(Rotation)) * 12);
			break;
		default:
			break;
		}
	}
}

void AEEBlackHawk::InitCrew()
{
	TArray<AActor*> TargetActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Pilot"), TargetActor);
	for (AActor* Actor : TargetActor)
	{
		if (Actor->IsA(ABHCrew::StaticClass()))
		{
			Crew[0] = Cast<ABHCrew>(TargetActor[0]);
		}
	}
	if (Crew[0] != nullptr)
	{
		Crew[0]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "CoPilot");
		Crew[0]->SetActorEnableCollision(false);
		Crew[0]->SetActorRelativeRotation(FRotator(0, 180, 0));
		Crew[0]->SetActorRelativeLocation(FVector(-3, 0, -12));
	}

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("CoPilot"), TargetActor);
	for (AActor* Actor : TargetActor)
	{
		if (Actor->IsA(ABHCrew::StaticClass()))
		{
			Crew[1] = Cast<ABHCrew>(TargetActor[0]);
		}
	}
	if (Crew[1] != nullptr)
	{
		Crew[1]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale , "Pilot");
		Crew[1]->SetActorEnableCollision(false);
		Crew[1]->SetActorRelativeRotation(FRotator(0, 180, 0));
		Crew[1]->SetActorRelativeLocation(FVector(-3, 0, -12));
	}

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("CrewChief"), TargetActor);
	for (AActor* Actor : TargetActor)
	{
		if (Actor->IsA(ABHCrew::StaticClass()))
		{
			Crew[2] = Cast<ABHCrew>(TargetActor[0]);
		}
	}
	if (Crew[2] != nullptr)
	{
		Crew[2]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "CrewChief");
		Crew[2]->SetActorEnableCollision(false);
		Crew[2]->SetActorRelativeRotation(FRotator(0, 180, 0));
		Crew[2]->SetActorRelativeLocation(FVector(-3, 0, -12));
	}

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("GunnerPort"), TargetActor);
	for (AActor* Actor : TargetActor)
	{
		if (Actor->IsA(ABHCrew::StaticClass()))
		{
			Crew[3] = Cast<ABHCrew>(TargetActor[0]);
		}
	}
	if (Crew[3] != nullptr)
	{
		Crew[3]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GunnerPort");
		Crew[3]->SetActorEnableCollision(false);
		Crew[3]->SetActorRelativeRotation(FRotator(0, 180, 0));
		Crew[3]->SetActorRelativeLocation(FVector(-3, 0, -12));
	}


	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("GunnerStbd"), TargetActor);
	for (AActor* Actor : TargetActor)
	{
		if (Actor->IsA(ABHCrew::StaticClass()))
		{
			Crew[4] = Cast<ABHCrew>(TargetActor[0]);
		}
	}
	if (Crew[4] != nullptr)
	{
		Crew[4]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GunnerStbd");
		Crew[4]->SetActorEnableCollision(false);
		Crew[4]->SetActorRelativeRotation(FRotator(0, 180, 0));
		Crew[4]->SetActorRelativeLocation(FVector(-3, 0, -12));
	}
	
}
void AEEBlackHawk::InitGuns()
{
	TArray<AActor*> TargetActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("M134Port"), TargetActor);
	for (AActor* Actor : TargetActor)
	{
		if (Actor->IsA(ABHM134A::StaticClass()))
		{
			Guns[0] = Cast<ABHM134A>(TargetActor[0]);
		}
	}
	if (Guns[0] != nullptr)
	{
		Guns[0]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GunnerPort");
		Guns[0]->SetActorEnableCollision(false);
		Guns[0]->SetActorRelativeRotation(FRotator(0, 180, 0));
		Guns[0]->SetActorRelativeLocation(FVector(-3, 0, -3));
	}

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("M134Stbd"), TargetActor);
	for (AActor* Actor : TargetActor)
	{
		if (Actor->IsA(ABHM134A::StaticClass()))
		{
			Guns[1] = Cast<ABHM134A>(TargetActor[0]);
		}
	}
	if (Guns[1] != nullptr)
	{
		Guns[1]->AttachToComponent(PMC, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "GunnerStbd");
		Guns[1]->SetActorEnableCollision(false);
		Guns[1]->SetActorRelativeRotation(FRotator(0, 180, 0));
		Guns[1]->SetActorRelativeLocation(FVector(-3, 0, -3));
	}
}

void AEEBlackHawk::Tick(float DeltaTime)
{
	UpdateCollision();
	SpinRotors();
	/*
	ChaseCamA.SetRelativeLocation(MakeVect(-1024, 0, 64));
	ChaseCamA.SetRelativeRotation(MakeRot(0, 0, 0));
	ChaseCamB.SetRelativeLocation(MakeVect(512, -150, -128));
	ChaseCamB.SetRelativeRotation(MakeRot(800, 29000, 0));
	if (bDoDLight)
	{
		UpdateDLight();
	}
	else
	{
		DLight.LightBrightness = 0;
		DLight.LightRadius = 1;
	}
	*/
}

void AEEBlackHawk::UpdateCollision()
{
	/*
	CollisionActor.SetLocation(GetBoneCoords('Collision').Origin);
	CollisionActor.SetRotation(GetBoneRotation('Collision'));
	*/
}
void AEEBlackHawk::UpdateDLight()
{
	/*
	local FVector N;
	local FVector HitLocation;
	local FVector HitNormal;
	local FVector StartTrace;
	local FVector EndTrace;
	local Actor HitActor;
	N = Normal(Vector(LightPoint.Rotation));
	StartTrace = LightPoint.Location;
	EndTrace = StartTrace + 3096 * N;
	HitActor = Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
	DLight.LightBrightness = 128;
	DLight.LightRadius = 40;
	HitLocation += HitNormal * 64;
	DLight.SetLocation(HitLocation);
	*/
}
void AEEBlackHawk::SpinRotors()
{
	FRotator CurrentRotation;
	CurrentRotation = PMC->GetBoneRotationByName(FName("MainRotor"), EBoneSpaces::ComponentSpace);
	CurrentRotation.Yaw = MainRotorRotation.Yaw;
	PMC->SetBoneRotationByName(FName("MainRotor"), CurrentRotation, EBoneSpaces::ComponentSpace);
	CurrentRotation = PMC->GetBoneRotationByName(FName("TailRotor"), EBoneSpaces::ComponentSpace);
	CurrentRotation.Roll = TailRotorRotation.Roll;
	PMC->SetBoneRotationByName(FName("TailRotor"), CurrentRotation, EBoneSpaces::ComponentSpace);
	MainRotorRotation.Yaw += 10;
	TailRotorRotation.Roll += 10;
}
void AEEBlackHawk::SetChopperSound(FName SoundType)
{
	AmbientSound = nullptr;
	if (SoundType == "Interior") { AmbientSound = ChopperSounds[0]; };
	if (SoundType == "exterior") { AmbientSound = ChopperSounds[1]; };
	if (SoundType == "Exterior2") { AmbientSound = ChopperSounds[2]; };
}
void AEEBlackHawk::Destroyed()
{
	/*
	int32 i;
	for (i = 0; i < SignalLights.Num()-1; i++)
	{
		SignalLights[i]->Destroy();
		SignalLights[i] = nullptr;
	}
	for (i = 0; i < LandingLights.Num()-1; i++)
	{
		LandingLights[i]->Destroy();
		LandingLights[i] = nullptr;
	}

	PlayerView->Destroy();
	PlayerView = nullptr;
	ViewMarker->Destroy();
	ViewMarker = nullptr;
	ChaseCamA->Destroy();
	ChaseCamA = nullptr;
	ChaseCamB->Destroy();
	ChaseCamB = nullptr;
	LightPoint->Destroy();
	LightPoint = nullptr;
	DLight->Destroy();
	DLight = nullptr;
	CollisionActor->Destroy();
	CollisionActor = nullptr;
	*/
}
