// All the original content belonged to the US Army


#include "BlackHawkStatic.h"

// Sets default values
ABlackHawkStatic::ABlackHawkStatic()
{
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

/*
// Called when the game starts or when spawned
void ABlackHawkStatic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlackHawkStatic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/
void ABlackHawkStatic::BeginPlay()
{
		Super::BeginPlay();
		//AmbientSound=sndHover;
		//bFullVolume=True;
		//SoundRadius=2000;
		//SoundVolume=255;
		if(! bUseToStartRotor)
		{
			fpRotorSpeed=fpRotorActivatedSpeed;
			fpDesiredRotorSpeed=fpRotorActivatedSpeed;
		}
		else
		{
			//fpDesiredRotorSpeed = 250;
			//fpRotorSpeed = 250;
			fpDesiredRotorSpeed = 25;
			fpRotorSpeed = 25;
		}
		/*
			SetTimer(0.25,True);
		InitializeCrew();
		if(Role == 4)
		{
			ConfigureLinkDamage();
		}
		if(bIsCivilian)
		{
			Skins[0]=CivilianBHSkin;
		}
	*/
}
void ABlackHawkStatic::ConfigureLinkDamage()
{
	/*
		local AGP.AGP_Objective AO;
		InitialKillHealth=KillHealth;
		if(DamageTag != 'None' && DamageTag != 'None')
		{
			ForEach AllActors(Class'AGP_Objective',AO)
			{
				if(AO.DamageTag == DamageTag)
				{
					if(DamageObjective == None)
					{
						DamageObjective=AO;
					}
					else
					{
						DebugLog(DEBUG_Warn,"BlackhawkStatic::PostBeginPlay()	Already have a DamageObjective! " $ AO @ DamageObjective);
					}
				}
			}
			if(DamageObjective == None)
			{
				DebugLog(DEBUG_Warn,"BlackhawkStatic::PostBeginPlay()	Could not find DamageObjective for DamageTag " $ DamageTag);
			}
		}
	*/
}
/*
void ABlackHawkStatic::TakeDamage(int Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	local float DamageMultiplier;
	if(Bone.Name == nameMainRotorBone || Bone.Name == nameTailRotorBone)
	{
		DamageMultiplier=1;
	}
	else
	{
		DamageMultiplier=0.33;
	}
	if(DamageEvent != 'None')
	{
		TriggerEvent(DamageEvent,Self,instigatedBy);
	}
	if(DamageObjective != None)
	{
		DamageObjective.NotifyLinkDamage(instigatedBy,DamageMultiplier * Damage);
		if(instigatedBy != None && instigatedBy.Controller != None && instigatedBy.Controller.IsA('HumanController'))
		{
			HumanController(instigatedBy.Controller).NotifyAdminMessage("Cease Fire - You firing too close to a medevac chopper.");
		}
	}
}
*/
void ABlackHawkStatic::InitializeCrew()
{
	/*
		SetCollision(False,False);
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
		SetCollision(True,True);
	*/
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
	/*
		local FVector vNoVertVel;
		local float fpAltitude;
		local int iEmitter;
		local FVector vDustLocation;
		if(fpRotorSpeed > fpRotorDustSpeed)
		{
			for(iEmitter=0; iEmitter<16; iEmitter++)
			{
				if(emitDust[iEmitter] != None && emitDust[iEmitter].bAutoDestroyPrepped)
				{
					emitDust[iEmitter].Destroy();
					emitDust[iEmitter]=None;
				}
				if(emitDust[iEmitter] != None && VSize(emitDust[iEmitter].Location - Location) > 450)
				{
					emitDust[iEmitter].Destroy();
					emitDust[iEmitter]=None;
				}
				if(emitDust[iEmitter] == None)
				{
					vDustLocation=Location;
					vDustLocation +=  Vector(MakeRot(0,iEmitter * 4096,0)) * 200 + Rand(150);
					vDustLocation -= MakeVect(0,0,fpAltitude - 60);
					emitDust[iEmitter]=Spawn('HelicopterDustCloudEffect',Self,,vDustLocation,Rotation);
					emitDust[iEmitter].UpdateDust(GetBoneCoords('Pilot').Origin);
				}
			}
		}
		else
		{
			for(iEmitter=0; iEmitter<16; iEmitter++)
			{
				if(emitDust[iEmitter] != None)
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
void ABlackHawkStatic::UsedBy(APawn* User)
{
	/*
		AActor* actIterator;
		ForEach DynamicActors(Class'Actor',actIterator,namePlayerUsedEvent)
		{
		}
		actIterator.Trigger(Self,User);
		fpDesiredRotorSpeed=fpRotorActivatedSpeed;
		Return True;
	*/
}
void ABlackHawkStatic::AttachCrewChief()
{
	/*
		local Object.Coords SpawnCoords;
		SpawnCoords=GetBoneCoords('CrewChief');
		pCrewChief=Spawn(class<Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHCrewChief",Class'Class')),,,SpawnCoords.Origin + MakeVect(0,0,-32),Rotation,True,True);
		pCrewChief.HUDText="Crew Chief";
		pCrewChief.SetCollision(False,False,False);
		pCrewChief.PrePivot.Z=0;
		pCrewChief.SetPhysics(0);
		pCrewChief.AnimAction='BH_CrewIdle';
		pCrewChief.SetCollision(False,True,True);
		AttachHelmet(pCrewChief);
	*/
}
void ABlackHawkStatic::AttachCrewLoadMaster()
{
	/*
		local Object.Coords SpawnCoords;
		SpawnCoords=GetBoneCoords('Player');
		pCrewLoadMaster=Spawn(class<Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHCrewChief",Class'Class')),,,SpawnCoords.Origin,Rotation,True,True);
		pCrewLoadMaster.HUDText="Loadmaster";
		pCrewLoadMaster.SetCollision(False,False,False);
		pCrewLoadMaster.PrePivot.Z=0;
		pCrewLoadMaster.SetPhysics(0);
		pCrewLoadMaster.AnimAction='BH_CrewIdle';
		AttachToBone(pCrewLoadMaster,'Player');
		AttachHelmet(pCrewLoadMaster);
	*/
}
void ABlackHawkStatic::AttachCoPilot()
{
	/*
		local Object.Coords SpawnCoords;
		SpawnCoords=GetBoneCoords('CoPilot');
		pCoPilot=Spawn(class<Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHPilot",Class'Class')),,,SpawnCoords.Origin,Rotation,True,True);
		pCoPilot.HUDText="Co-Pilot";
		pCoPilot.SetCollision(False,False,False);
		pCoPilot.AnimAction='BH_Pilot';
		pCoPilot.bCollideWorld=False;
		pCoPilot.PrePivot.Z=0;
		pCoPilot.SetPhysics(0);
		AttachHelmet(pCoPilot);
		SetCustomTimer(1,False,'ResetCopilotAnim');
	*/
}
void ABlackHawkStatic::AttachPilot()
{
	/*
		local Object.Coords SpawnCoords;
		SpawnCoords=GetBoneCoords('Pilot');
		pPilot=Spawn(class<Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHPilot",Class'Class')),,,SpawnCoords.Origin,Rotation,True,True);
		pPilot.HUDText="Pilot";
		pPilot.SetCollision(False,False,False);
		pPilot.AnimAction='BH_Pilot';
		pPilot.bCollideWorld=False;
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
		aRearwardWounded.SetRelativeLocation(MakeVect(30,0,-10));
		aRearwardWounded.SetRelativeRotation(MakeRot(0,16384,0));
	*/
}
void ABlackHawkStatic::AttachForwardWounded()
{
	/*
		aForwardWounded.LinkMesh(Mesh(DynamicLoadObject("M_AA2_Character.Wounded.Char_Wounded_Civ_Afr01",Class'Mesh')));
		aForwardWounded.SetDrawType(8);
		AttachToBone(aForwardWounded,'CrewChief');
		aForwardWounded.SetRelativeLocation(MakeVect(30,0,-10));
		aForwardWounded.SetRelativeRotation(MakeRot(0,16384,0));
	*/
}
void ABlackHawkStatic::AttachHelmet(APawn* pawnCrewMember)
{
	/*
		local Actor actAttachment;
		actAttachment=Spawn(class<Actor>(DynamicLoadObject("AGP_Inventory.Attch_FlightCrewHelmetBH_RedCross",Class'Class')));
		actAttachment.SetDrawScale(1.13);
		pawnCrewMember.AttachToBone(actAttachment,'BN_HeadEnd');
		actAttachment.SetRelativeRotation(MakeRot(0,32768,16384));
	*/
}





