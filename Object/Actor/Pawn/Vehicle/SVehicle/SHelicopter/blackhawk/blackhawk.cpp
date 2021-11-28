// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SHelicopter/blackhawk/blackhawk.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParamsRBFull/KarmaParamsRBFull.h"

Ablackhawk::Ablackhawk()
{
	UKarmaParamsRBFull* KParams0 = NewObject<UKarmaParamsRBFull>(UKarmaParamsRBFull::StaticClass());
	KParams0->KInertiaTensor.SetNum(6);
	KParams0->KInertiaTensor[0] = 1;
	KParams0->KInertiaTensor[3] = 3;
	KParams0->KInertiaTensor[5] = 3.5;
	KParams0->KLinearDamping = 0;
	KParams0->KAngularDamping = 0;
	KParams0->bKNonSphericalInertia = true;
	KParams0->bHighDetailOnly = false;
	KParams0->bClientOnly = false;
	KParams0->bKDoubleTickRate = true;
	KParams0->bKStayUpright = true;
	KParams0->bKAllowRotate = true;
	KParams0->bDoSafetime = true;
	KParams0->KFriction = 0.5;
	sndCruising = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Helicopter/blackhawk/BHRotorCruise_Que.BHRotorCruise_Que'"), NULL, LOAD_None, NULL);
	sndHover = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Helicopter/blackhawk/BHRotorHover_Que.BHRotorHover_Que'"), NULL, LOAD_None, NULL);
	KillHealth = 1000;
	fpOriginalMaxRotorSpeed = 250;
	SmokeGeneratorAttachmentBone = "MainRotor";
	//DestroyedModelClass = class'AGP_Vehicles.Blackhawk_DestroyedBody';
	DestroyedVehicleMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/blackhawk/veh_blackhawk_fullcrashed.veh_blackhawk_fullcrashed'"), NULL, LOAD_None, NULL);
	UprightStiffness = 100;
	UprightDamping = 90;
	LongDamping = 0.1;
	LatDamping = 0.1;
	UpDamping = 0.1;
	TurnTorqueFactor = 350;
	TurnTorqueMax = 150;
	TurnDamping = 45;
	MaxYawRate = 2;
	PitchTorqueMax = 10;
	PitchDamping = 40;
	RollTorqueMax = 10;
	RollDamping = 50;
	RotorSpeedAccelRateMax = 160;
	RotorSpeedForceFactor = 1;
	RotorSpeedIdle = 20;
	RotorSpeedMax = 250;
	TailRotorBoneName = "TailRotor";
	RotorBoneName = "MainRotor";
	RotorBoneAxis = EAA2_Axis::AXIS_Y;
	RotorBoneSpeedScale = 1000;
	RotorBoneSpeedMax = 1000000;
	VehicleMass = 4;
	bDrawDriverInTP = true;
	bFPNoZFromCameraPitch = true;
	DriverBone = "Pilot";
	DrivePos = FVector(0, 0, -15);
	bPlayDrivingAnimations = false;
	ExitPositions = { FVector(0, -165, 100),FVector(0, 165, 100) };
	EntryPosition = FVector(0, -165, -80);
	EntryRadius = 180;
	FPCamPos = FVector(160, 0, 120);
	FPCamViewOffset = FVector(90, 0, 0);
	TPCamDistance = 1400;
	TPCamLookat = FVector(-50, 0, 0);
	TPCamWorldOffset = FVector(0, 0, 250);
	bIsHelicopter = true;
	bSusceptibleToSmallArms = true;
	//SightRadius = 27000;
	//bIgnoresFog = true;
	//AmbientSoundScaling = 2;
	//bProp = true;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Helicopter/BlackHawkB.BlackHawkB'"), NULL, LOAD_None, NULL);
	//bShadowCast = true;
	//CollisionRadius = 400;
	//CollisionHeight = 250;
	//bCollideWorld = true;
	//bBlockProjectiles = true;
	KParams = KParams0;
}

/*
replication
{
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		bSmokeGeneratorOn;
}
*/
/*
State VehicleDestroyed
{
	Function CallDestroy()
	{
		Log("BlackHawk::CallDestroy() called: Destroy_Track");
	}
	Function Died(Controller Killer, class<DamageType>  DamageType, Vector HitLocation, Vector HitDir, Actor.BoneInfo Bone)
	{
	}
Begin:
	StopCustomTimer('DustCloudTimer');
	Log("BlackHawk state: vehicle_damage");
	DestroyAppearance();
	Sleep((FRand() * 10));
	SpawnDestructionEffects();
}

*/

void Ablackhawk::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	SetTimer(0.25, true);
	SetCustomTimer(0.5, true, 'DustCloudTimer');
	*/
}

void Ablackhawk::Destroyed()
{
	/*
	int32 iEmitter = 0;
	for (iEmitter = 0; iEmitter < 16; iEmitter++)
	{
		if (emitDust[iEmitter] != None)
		{
			emitDust[iEmitter].HideDirt();
		}
	}
	if (SmokeGenerator != None)
	{
		SmokeGenerator.Destroy();
	}
	if ((Controller == None) || (NPCBaseHelicopterController(Controller) == None))
	{
		Super::Destroyed();
		return;
	}
	NPCBaseHelicopterController(Controller).CleanupCrew();
	Controller.Destroy();
	Controller = None;
	Super::Destroyed();
	*/
}

void Ablackhawk::Timer()
{
	/*
	FVector vNoVertVel = FVector(0, 0, 0);
	float fpAltitude = 0;
	int32 iEmitter = 0;
	CheckSmokeGenerator();
	Super::Timer();
	if (bSmokeGeneratorOn)
	{
	}
	if (Driver == None)
	{
		return;
	}
	vNoVertVel = Velocity;
	vNoVertVel.Z = 0;
	if (VSize(vNoVertVel) < float(10))
	{
		if (Driver.AmbientSound != sndHover)
		{
			Driver.AmbientSound = sndHover;
			Driver.bFullVolume = true;
			Driver.SoundRadius = 2000;
			Driver.AmbientSoundScaling = 10;
		}
		Driver.SoundVolume = byte((float(192) + (float(64) * ((fpHelicopterCollective + 1) / 2))));
	}
	else
	{
		if (Driver.AmbientSound != sndCruising)
		{
			Driver.AmbientSound = sndCruising;
			Driver.bFullVolume = true;
			Driver.SoundRadius = 2500;
			Driver.AmbientSoundScaling = 10;
		}
		Driver.SoundVolume = byte((float(192) + (float(64) * ((fpHelicopterCollective + 1) / 2))));
	}
	*/
}

bool Ablackhawk::UsedBy(APawn* User)
{
	//return Controller.UsedBy(User);
	return false;    //FAKE   /EliZ
}

void Ablackhawk::DustCloudTimer()
{
	/*
	FVector vNoVertVel = FVector(0, 0, 0);
	float fpAltitude = 0;
	int32 iEmitter = 0;
	FVector vDustLocation = FVector(0, 0, 0);
	if (Controller == None)
	{
		return;
	}
	if (NPCBaseHelicopterController(Controller) == None)
	{
		return;
	}
	vNoVertVel = Velocity;
	vNoVertVel.Z = 0;
	if (VSize(vNoVertVel) < 5)
	{
		fpAltitude = NPCBaseHelicopterController(Controller).GetRealAltitude();
		if (fpAltitude < float(250))
		{
			for (iEmitter = 0; iEmitter < 16; iEmitter++)
			{
				if ((emitDust[iEmitter] != None) && emitDust[iEmitter].bAutoDestroyPrepped)
				{
					emitDust[iEmitter].Destroy();
					emitDust[iEmitter] = None;
				}
				if ((emitDust[iEmitter] != None) && (VSize((emitDust[iEmitter].Location - Location)) > float(450)))
				{
					emitDust[iEmitter].Destroy();
					emitDust[iEmitter] = None;
				}
				if (emitDust[iEmitter] == None)
				{
					vDustLocation = Location;
					vDustLocation += (Vector(MakeRot(0, (iEmitter * 4096), 0)) * float((200 + Rand(150))));
					vDustLocation -= MakeVect(0, 0, (fpAltitude - float(10)));
					emitDust[iEmitter] = Spawn(class'AGP_Vehicles.HelicopterDustCloudEffect', Self, , vDustLocation, Rotation);
					emitDust[iEmitter].UpdateDust(GetBoneCoords(DriverBone).Origin);
				}
			}
		}
		else
		{
			if ((fpAltitude > float(250)) && (Velocity.Z > 5))
			{
				for (iEmitter = 0; iEmitter < 16; iEmitter++)
				{
					if (emitDust[iEmitter] != None)
					{
						emitDust[iEmitter].HideDirt();
					}
				}
			}
		}
	}
	*/
}

bool Ablackhawk::TryToDrive(APawn* p)
{
	/*
	if (((((p.bIsCrouched || (p.Controller == None)) || (Driver != None)) || (p.DrivenVehicle != None)) || p.IsA('Vehicle')) || (Health <= 0))
	{
		Log(string(Self) $ ".TryToDrive() Rejecting attempt to drive");
		return false;
	}
	if (!Level.Game.CanEnterVehicle(Self, p))
	{
		Log("CanEnterVehicle() would normally block BH entry");
	}
	KDriverEnter(p);
	*/
	return true;
}

void Ablackhawk::KDriverEnter(APawn* p)
{
	/*
	local PlayerController PC;
	local Controller C;
	Driver = p;
	Driver.SetCollision(false, false);
	Driver.bCollideWorld = false;
	Driver.bPhysicsAnimUpdate = false;
	Driver.Velocity = vect(0, 0, 0);
	Driver.SetPhysics(PHYS_None);
	Driver.SetBase(Self);
	C = p.Controller;
	p.Controller.UnPossess();
	Driver.SetOwner(C);
	C.Possess(Self);
	*/
}

bool Ablackhawk::KDriverLeave(bool bForceLeave)
{
	/*
	local Controller C;
	local PlayerController PC;
	bool havePlaced = false;
	if (Controller == None)
	{
		return false;
	}
	if ((Driver != None) && ((!bRemoteControlled) || bHideRemoteDriver))
	{
		Driver.bHardAttach = false;
		Driver.bCollideWorld = true;
		Driver.SetCollisionSize(Driver.Default.CollisionRadius, Driver.Default.CollisionHeight);
		Driver.SetCollision(true, true);
		havePlaced = PlaceExitingDriver();
		if ((!havePlaced) && (!bForceLeave))
		{
			Driver.bHardAttach = true;
			Driver.bCollideWorld = false;
			Driver.SetCollision(false, false);
			return false;
		}
	}
	bDriving = false;
	C = Controller;
	if (C.RouteGoal == Self)
	{
		C.RouteGoal = None;
	}
	if (C.MoveTarget == Self)
	{
		C.MoveTarget = None;
	}
	C.bVehicleTransition = true;
	Controller.UnPossess();
	if ((Driver != None) && (Driver.Health > 0))
	{
		Driver.SetOwner(C);
		C.Possess(Driver);
		PC = PlayerController(C);
		if (PC != None)
		{
			PC.ClientSetViewTarget(Driver);
		}
		Driver.StopDriving(Self);
	}
	C.bVehicleTransition = false;
	if (C == Controller)
	{
		Controller = None;
	}
	bReservedOccupation = false;
	ClearDriverHiddenAttachments();
	Driver = None;
	DriverLeft();
	Throttle = 0;
	Steering = 0;
	Rise = 0;
	*/
	return true;
}
/*
void Ablackhawk::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  dtDamageType, Actor.BoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	FVector MomentumDir = FVector(0, 0, 0);
	if (Damage < 0)
	{
		switch (dtDamageType.Default.AmmoType)
		{
		case 0:
			return;
		case 1:
		case 2:
		case 4:
			Damage = 30;
			break;
		case 3:
			Damage = 5;
			break;
		case 6:
		case 18:
		case 12:
			Damage = 10;
			break;
		case 5:
		case 7:
		case 8:
		case 9:
		case 10:
		case 13:
			Damage = 5;
			break;
		case 16:
			Damage = 2;
			break;
		case 14:
			Damage = 250;
			break;
		default:
			Damage = 1;
			break;
		}
	}
	if (dtDamageType.Default.bBulletHit)
	{
		Spawn(Class'AGP_Effects.em_bt_metal', Self, , HitLocation);
	}
	if ((Controller != None) && Controller.IsA('AIController'))
	{
		AIController(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, dtDamageType, Bone);
	}
	TriggerEvent(DamageEvent, Self, instigatedBy);
	if (!(((Bone.Name ~= "MainRotor") || (Bone.Name ~= "Rotor")) || (Bone.Name ~= "Pilot")))
	{
		(Damage /= 2);
	}
	if (Controller.bGodMode && (Health <= Damage))
	{
		return;
	}
	if (KillHealth > 0)
	{
		Controller.TakeDamage(Damage, instigatedBy, HitLocation, Momentum, dtDamageType, Bone, KillerController);
		Damage = Min(Damage, KillHealth);
		(KillHealth -= Damage);
		Health = KillHealth;
		if (DamageObjective != None)
		{
			DamageObjective.NotifyLinkDamage(instigatedBy, Damage);
		}
		if (KillHealth <= 0)
		{
			TriggerEvent(KillEvent, Self, instigatedBy);
			if (DamageObjective != None)
			{
				DamageObjective.NotifyLinkKill(instigatedBy);
			}
			AmbientSound = None;
			Log("Helicopter shot down");
			if ((Controller != None) && Controller.IsA('AIController'))
			{
				AIController(Controller).NotifyTakeDamage(Damage, instigatedBy, HitLocation, dtDamageType, Bone);
			}
		}
	}
}
*/

void Ablackhawk::HelicopterEngineSmoke(bool bEnable)
{
	/*
	bSmokeGeneratorOn = bEnable;
	if ((fpSmokeEndTime != 0) && (fpSmokeEndTime < Level.TimeSeconds))
	{
		fpSmokeEndTime = (Level.TimeSeconds + float(30));
	}
	*/
}

void Ablackhawk::HelicopterRotorSmoke(bool bEnable)
{
}

void Ablackhawk::HelicopterCockpitSmoke(bool bEnable)
{
}

void Ablackhawk::CheckSmokeGenerator()
{
	/*
	if (((((Level.NetMode == NM_DedicatedServer) || (Level.NetMode == NM_Standalone)) && bSmokeGeneratorOn) && (Level.TimeSeconds > fpSmokeEndTime)) && (fpSmokeEndTime > 0))
	{
		bSmokeGeneratorOn = false;
		return;
	}
	if ((SmokeGenerator != None) && (!bSmokeGeneratorOn))
	{
		SmokeGenerator.Kill();
		SmokeGenerator = None;
		return;
	}
	if (bSmokeGeneratorOn && (SmokeGenerator == None))
	{
		SpawnSmokeGenerator(60);
	}
	*/
}

void Ablackhawk::SpawnSmokeGenerator(float fpSmokeLengthSeconds)
{
	/*
	SmokeGenerator = Spawn(Class'AGP_Effects.M83SmokeEmitter', Self, , Location, rot(16384, 0, 0));
	if (SmokeGenerator == None)
	{
		bSmokeGeneratorOn = false;
		return;
	}
	Log("Created smoke generator: " $ string(SmokeGenerator) $ ", attaching to " $ string(SmokeGeneratorAttachmentBone));
	SmokeGenerator.SetBase(Self);
	AttachToBone(SmokeGenerator, SmokeGeneratorAttachmentBone);
	SmokeGenerator._EffectDuration = fpSmokeLengthSeconds;
	fpSmokeEndTime = (Level.TimeSeconds + fpSmokeLengthSeconds);
	*/
}

void Ablackhawk::StartSmokeGenerator()
{
	//bSmokeGeneratorOn = true;
}

void Ablackhawk::SpawnDestructionEffects()
{
	/*
	local Actor NewBody;
	local Emitter DestructionEffect;
	DestructionEffect = Spawn(Class'AGP_Effects.VehicleHulkBurn', Self);
	DestructionEffect.SetBase(Self);
	DestructionEffect = Spawn(Class'AGP_Effects.em_bt_PG7Bexplosion', Self);
	DestructionEffect.SetBase(Self);
	*/
}

void Ablackhawk::Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone)
{
}

void Ablackhawk::Landed(FVector HitNormal)
{
	/*
	if (Controller != None)
	{
		Controller.Landed(HitNormal);
	}
	*/
}

void Ablackhawk::HelicopterForceRotorMaxToIdleSpeed()
{
	//RotorSpeedMax = RotorSpeedIdle;
}

void Ablackhawk::HelicopterRestoreRotorMaxSpeed()
{
	//RotorSpeedMax = fpOriginalMaxRotorSpeed;
}

void Ablackhawk::DestroyAppearance()
{
	/*
	int32 i = 0;
	local KarmaParams KP;
	Throttle = 0;
	Steering = 0;
	Rise = 0;
	SetDrawType(DT_StaticMesh);
	AmbientSound = None;
	SetPhysics(PHYS_Falling);
	SetStaticMesh(DestroyedVehicleMesh);
	SetCollisionSize(1, 1);
	SetRotation((Rotation + MakeRot(0, 16384, 0)));
	if (Level.NetMode != NM_DedicatedServer)
	{
		SpawnDestructionEffects();
	}
	KP = KarmaParams(KParams);
	if (KP != None)
	{
		KP.KStartLinVel = Velocity;
	}
	bWorldGeometry = false;
	bCollideWorld = false;
	Skins.Length = 0;
	*/
}
