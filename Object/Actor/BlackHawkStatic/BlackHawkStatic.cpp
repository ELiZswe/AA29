// All the original content belonged to the US Army

#include "AA29/Object/Actor/BlackHawkStatic/BlackHawkStatic.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Emitter/HelicopterDustCloudEffect/HelicopterDustCloudEffect.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

// Sets default values
ABlackHawkStatic::ABlackHawkStatic()
{
	emitDust.SetNum(16);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseToStartRotor = true;
	fpRotorActivatedSpeed = 750;
	fpRotorAcceleration = 1.5;
	fpRotorDustSpeed = 500;
	bIsCivilian = true;
	CivilianBHSkin = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Vehicles/blackhawk/skin_veh_MedBlackHawkMain.skin_veh_MedBlackHawkMain'"), NULL, LOAD_None, NULL);
	bIncludePilot = true;
	bProp = true;

	nameMainRotorBone = "MainRotor";
	nameTailRotorBone = "TailRotor";

	PoseableMesh = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("PoseableMesh"));
	PoseableMesh->SetSkeletalMesh(LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_Helicopter/BlackHawkB.BlackHawkB"), NULL, LOAD_None, NULL));
}

void ABlackHawkStatic::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	AmbientSound = sndHover;
	bFullVolume = true;
	SoundRadius = 2000;
	SoundVolume = 255;
	*/
	if (!bUseToStartRotor)
	{
		fpRotorSpeed = fpRotorActivatedSpeed;
		fpDesiredRotorSpeed = fpRotorActivatedSpeed;
	}
	else
	{
		fpDesiredRotorSpeed = 250;
		fpRotorSpeed = 250;
	}
	//SetTimer(0.25, true);
	InitializeCrew();
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		ConfigureLinkDamage();
	}
	if (bIsCivilian)
	{
		Skins[0] = CivilianBHSkin;
	}
	*/
}

void ABlackHawkStatic::ConfigureLinkDamage()
{
	AAGP_Objective* AO = nullptr;
	InitialKillHealth = KillHealth;
	/*
	if(DamageTag != "None" && DamageTag != "None")
	{
		ForEach AllActors(AAGP_Objective::StaticClass(),AO)
		{
			if(AO.DamageTag == DamageTag)
			{
				if(DamageObjective == nullptr)
				{
					DamageObjective=AO;
				}
				else
				{
					DebugLog(DEBUG_Warn,"BlackhawkStatic::PostBeginPlay()	Already have a DamageObjective! " + AO @ DamageObjective);
				}
			}
		}
		if(DamageObjective == nullptr)
		{
			DebugLog(DEBUG_Warn,"BlackhawkStatic::PostBeginPlay()	Could not find DamageObjective for DamageTag " + DamageTag);
		}
	}
	*/
}

/*
void ABlackHawkStatic::TakeDamage(int32 Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	float DamageMultiplier = 0;
	if(Bone.Name == nameMainRotorBone || Bone.Name == nameTailRotorBone)
	{
		DamageMultiplier=1;
	}
	else
	{
		DamageMultiplier=0.33;
	}
	if(DamageEvent != "None")
	{
		TriggerEvent(DamageEvent,Self,instigatedBy);
	}
	if(DamageObjective != nullptr)
	{
		DamageObjective.NotifyLinkDamage(instigatedBy,DamageMultiplier * Damage);
		if(instigatedBy != nullptr && instigatedBy.Controller != nullptr && instigatedBy.Controller->IsA(AHumanController::StaticClass()))
		{
			Cast<AHumanController>(instigatedBy.Controller).NotifyAdminMessage("Cease Fire - You firing too close to a medevac chopper.");
		}
	}
}
*/

void ABlackHawkStatic::InitializeCrew()
{
	//SetCollision(false,false);
	if(bIncludePilot)
	{
		AttachPilot();
	}
	if(bIncludeCoPilot)
	{
		AttachCoPilot();
	}
	if(bIncludeLoadMaster)
	{
		AttachCrewLoadMaster();
	}
	else
	{
		if(bIncludeRearwardWounded)
		{
			AttachRearwardWounded();
		}
	}
	if(bIncludeCrewchief)
	{
		AttachCrewChief();
	}
	else
	{
		if(bIncludeForwardWounded)
		{
			AttachForwardWounded();
		}
	}
	//SetCollision(true,true);
}

void ABlackHawkStatic::Timer()
{
	//Super::Timer();
	//SoundVolume=192 + 63 * fpMainRotorRotation / 750;
}

void ABlackHawkStatic::Tick(float DeltaTime)
{
	FRotator rotTailRotor;
	FRotator rotMainRotor;
	Super::Tick(DeltaTime);
	if(fpDesiredRotorSpeed > 0 && fpRotorSpeed < fpDesiredRotorSpeed)
	{
		fpRotorSpeed += fpRotorAcceleration;
	}
	fpMainRotorRotation += fpRotorSpeed;
	//rotMainRotor=FRotator(0, fpMainRotorRotation,0);
	rotMainRotor = FRotator(0, fpMainRotorRotation, -90);
	rotTailRotor= FRotator(0,90,fpMainRotorRotation);

	//Tail(Pitch = 0.000007, Yaw = 9.188171, Roll = 0.000001)
	if(PoseableMesh != nullptr)
	{
		
		PoseableMesh->SetBoneRotationByName(nameMainRotorBone, rotMainRotor, EBoneSpaces::ComponentSpace);
		PoseableMesh->SetBoneRotationByName(nameTailRotorBone, rotTailRotor, EBoneSpaces::ComponentSpace);
		//SetBoneRotation(nameMainRotorBone, rotMainRotor, , 1);
		//SetBoneRotation(nameTailRotorBone, rotTailRotor, , 1);
	}
}

void ABlackHawkStatic::DustCloudTimer()
{
	FVector vNoVertVel = FVector(0,0,0);
	float fpAltitude = 0;
	int32 iEmitter = 0;
	FVector vDustLocation = FVector(0,0,0);
	/*
		if(fpRotorSpeed > fpRotorDustSpeed)
		{
			for(iEmitter=0; iEmitter<16; iEmitter++)
			{
				if(emitDust[iEmitter] != nullptr && emitDust[iEmitter].bAutoDestroyPrepped)
				{
					emitDust[iEmitter].Destroy();
					emitDust[iEmitter]=nullptr;
				}
				if(emitDust[iEmitter] != nullptr && VSize(emitDust[iEmitter].Location - Location) > 450)
				{
					emitDust[iEmitter].Destroy();
					emitDust[iEmitter]=nullptr;
				}
				if(emitDust[iEmitter] == nullptr)
				{
					vDustLocation=Location;
					vDustLocation +=  Vector(FRotator(0,iEmitter * 4096,0)) * 200 + Rand(150);
					vDustLocation -= FVector(0,0,fpAltitude - 60);
					emitDust[iEmitter]=Spawn('HelicopterDustCloudEffect',Self,,vDustLocation,Rotation);
					emitDust[iEmitter].UpdateDust(GetBoneCoords('Pilot').Origin);
				}
			}
		}
		else
		{
			for(iEmitter=0; iEmitter<16; iEmitter++)
			{
				if(emitDust[iEmitter] != nullptr)
				{
					emitDust[iEmitter].HideDirt();
				}
			}
		}
	*/
}

void ABlackHawkStatic::Trigger(AActor* Other, APawn* EventInstigator)
{
	UsedBy(EventInstigator);
}

bool ABlackHawkStatic::UsedBy(APawn* User)
{
	AActor* actIterator = nullptr;
	/*
	ForEach DynamicActors(Class'Actor',actIterator,namePlayerUsedEvent)
	{
	}
	actIterator.Trigger(this,User);
	*/
	fpDesiredRotorSpeed=fpRotorActivatedSpeed;
	return true;
}

void ABlackHawkStatic::AttachCrewChief()
{
	FCoords SpawnCoords = FCoords({});
	/*
	SpawnCoords=GetBoneCoords('CrewChief');
	pCrewChief=Spawn(class<Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHCrewChief",Class'Class')),,,SpawnCoords.Origin + FVector(0,0,-32),Rotation,True,true);
	pCrewChief.HUDText="Crew Chief";
	pCrewChief.SetCollision(false,false,false);
	pCrewChief.PrePivot.Z=0;
	pCrewChief.SetPhysics(0);
	pCrewChief.AnimAction='BH_CrewIdle';
	pCrewChief.SetCollision(false,True,true);
	AttachHelmet(pCrewChief);
	*/
}

void ABlackHawkStatic::AttachCrewLoadMaster()
{
	FCoords SpawnCoords = FCoords({});
	/*
	SpawnCoords=GetBoneCoords('Player');
	pCrewLoadMaster=Spawn(class<Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHCrewChief",Class'Class')),,,SpawnCoords.Origin,Rotation,True,true);
	pCrewLoadMaster.HUDText="Loadmaster";
	pCrewLoadMaster.SetCollision(false,false,false);
	pCrewLoadMaster.PrePivot.Z=0;
	pCrewLoadMaster.SetPhysics(0);
	pCrewLoadMaster.AnimAction='BH_CrewIdle';
	AttachToBone(pCrewLoadMaster,'Player');
	AttachHelmet(pCrewLoadMaster);
	*/
}

void ABlackHawkStatic::AttachCoPilot()
{
	FCoords SpawnCoords = FCoords({});
	/*
	SpawnCoords=GetBoneCoords('CoPilot');
	pCoPilot=Spawn(class<Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHPilot",Class'Class')),,,SpawnCoords.Origin,Rotation,True,true);
	pCoPilot.HUDText="Co-Pilot";
	pCoPilot.SetCollision(false,false,false);
	pCoPilot.AnimAction='BH_Pilot';
	pCoPilot.bCollideWorld=false;
	pCoPilot.PrePivot.Z=0;
	pCoPilot.SetPhysics(0);
	AttachHelmet(pCoPilot);
	SetCustomTimer(1,false,'ResetCopilotAnim');
	*/
}

void ABlackHawkStatic::AttachPilot()
{
	FCoords SpawnCoords = FCoords({});
	/*
	SpawnCoords=GetBoneCoords('Pilot');
	pPilot=Spawn(class<Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHPilot",Class'Class')),,,SpawnCoords.Origin,Rotation,True,true);
	pPilot.HUDText="Pilot";
	pPilot.SetCollision(false,false,false);
	pPilot.AnimAction='BH_Pilot';
	pPilot.bCollideWorld=false;
	pPilot.PrePivot.Z=0;
	pPilot.SetPhysics(0);
	AttachHelmet(pPilot);
	*/
}

void ABlackHawkStatic::AttachRearwardWounded()
{
	/*
	aRearwardWounded.LinkMesh(Mesh(DynamicLoadObject("M_AA2_Character.Wounded.Char_Wounded_Civ_Afr01",Class'Mesh')));
	aRearwardWounded.SetDrawType(8);
	AttachToBone(aRearwardWounded,'Player');
	aRearwardWounded.SetRelativeLocation(FVector(30,0,-10));
	aRearwardWounded.SetRelativeRotation(FRotator(0,16384,0));
	*/
}

void ABlackHawkStatic::AttachForwardWounded()
{
	/*
	aForwardWounded.LinkMesh(Mesh(DynamicLoadObject("M_AA2_Character.Wounded.Char_Wounded_Civ_Afr01",Class'Mesh')));
	aForwardWounded.SetDrawType(8);
	AttachToBone(aForwardWounded,'CrewChief');
	aForwardWounded.SetRelativeLocation(FVector(30,0,-10));
	aForwardWounded.SetRelativeRotation(FRotator(0,16384,0));
	*/
}

void ABlackHawkStatic::AttachHelmet(APawn* pawnCrewMember)
{
	AActor* actAttachment = nullptr;
	/*
	actAttachment=Spawn(class<Actor>(DynamicLoadObject("AGP_Inventory.Attch_FlightCrewHelmetBH_RedCross",Class'Class')));
	actAttachment.SetDrawScale(1.13);
	pawnCrewMember.AttachToBone(actAttachment,'BN_HeadEnd');
	actAttachment.SetRelativeRotation(FRotator(0,32768,16384));
	*/
}

