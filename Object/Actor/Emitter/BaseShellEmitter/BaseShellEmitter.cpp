// All the original content belonged to the US Army

#include "BaseShellEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

ABaseShellEmitter::ABaseShellEmitter()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->UseCollision = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->Acceleration = FVector(0, 0, -750);
	MeshEmitter0->DampingFactorRange = FRangeVector({ {0.3, 0.6}, {0.3, 0.6}, {0.3, 0.6} });
	MeshEmitter0->MaxParticles = 200;
	MeshEmitter0->SpinsPerSecondRange = FRangeVector({ {-1, 1}, {-1, 1}, {-1, 1} });
	MeshEmitter0->SecondsBeforeInactive = 0;
	MeshEmitter0->LifetimeRange = FRange({ 10, 10 });
	MeshEmitter0->bPlayCollisionSoundFromOwner = true;
	MeshEmitter0->LandedMinSquaredVelocity = 10000;
	MeshEmitter0->bRestOnLand = true;
	MeshEmitter0->RestReset = FVector(0, 0.75, 0);
	MeshEmitter0->bRestReset_XYaw = true;
	MeshEmitter0->bRestReset_YPitch = true;
	MeshEmitter0->bWeirdSpinOnCollide = true;
	MeshEmitter0->WeirdBounce = 0.4;
	Emitters = { MeshEmitter0 };

	sWood = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWood1.WeaponFX_Shells_CasingWood1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWood2.WeaponFX_Shells_CasingWood2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWood3.WeaponFX_Shells_CasingWood3"), NULL, LOAD_None, NULL)
	};
	sConcrete = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingConcrete1.WeaponFX_Shells_CasingConcrete1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingConcrete2.WeaponFX_Shells_CasingConcrete2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingConcrete3.WeaponFX_Shells_CasingConcrete3"), NULL, LOAD_None, NULL)
	};
	sMetal = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMetal1.WeaponFX_Shells_CasingMetal1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMetal2.WeaponFX_Shells_CasingMetal2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMetal3.WeaponFX_Shells_CasingMetal3"), NULL, LOAD_None, NULL)
	};
	sWater = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWater1.WeaponFX_Shells_CasingWater1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWater2.WeaponFX_Shells_CasingWater2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingWater3.WeaponFX_Shells_CasingWater3"), NULL, LOAD_None, NULL)
	};
	sDirt = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMuffled1.WeaponFX_Shells_CasingMuffled1"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMuffled2.WeaponFX_Shells_CasingMuffled2"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/Shells/WeaponFX_Shells_CasingMuffled3.WeaponFX_Shells_CasingMuffled3"), NULL, LOAD_None, NULL)
	};

	fPitchModifier = 1;
	
	//	bNoDelete = false;
	//bTrailerSameRotation = true;
	//Physics = 10;
	//RemoteRole = 0;
	//Mass = 4;
	//bRenderAttachmentSeperately = true;
}

void ABaseShellEmitter::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	MeshEmitter(Emitters[0]).StaticMesh = ShellStaticMesh;
	Emitters[0].StartSizeRange = GetRVFromV(ShellDrawScale);
	*/
}

void ABaseShellEmitter::Initialize(FRotationRandomizer newShellDirInfo, FBoneOffset newOffset1P, FBoneOffset newOffset3P, AActor* newAttachTo3P)
{
	/*
	local PlayerController cc;
	bool bFirstPerson = false;
	ShellDirInfo = newShellDirInfo;
	Offset1P = newOffset1P;
	Offset3P = newOffset3P;
	AttachTo3P = newAttachTo3P;
	if (AttachTo3P == None)
	{
		AttachTo3P = Instigator;
	}
	cc = Level.GetClientController();
	if (cc != None)
	{
		bFirstPerson = ((!cc.bBehindView) && (cc.ViewTarget == Instigator));
	}
	SetFirstPerson(bFirstPerson);
	*/
}

void ABaseShellEmitter::GetCollisionSound(UParticleEmitter* E, int32 PIndex, UMaterialInstance* HitMat, USoundBase*& HitSound, float& Volume, float& Radius, float& Pitch, float& Fade, float& Priority)
{
	/*
	float sizesq = 0;
	if (HitMat == None)
	{
		HitSound = sConcrete[Rand(sConcrete.Length)];
	}
	else
	{
		switch (HitMat.GetMaterialType())
		{
		case 0:
			HitSound = sConcrete[Rand(sConcrete.Length)];
			break;
		case 18:
		case 19:
		case 20:
		case 1:
			HitSound = sWood[Rand(sWood.Length)];
			break;
		case 2:
			HitSound = sConcrete[Rand(sConcrete.Length)];
			break;
		case 3:
			HitSound = sDirt[Rand(sDirt.Length)];
			break;
		case 21:
		case 22:
		case 23:
		case 4:
			HitSound = sMetal[Rand(sConcrete.Length)];
			break;
		case 5:
			HitSound = sConcrete[Rand(sConcrete.Length)];
			break;
		case 6:
			HitSound = sConcrete[Rand(sConcrete.Length)];
			break;
		case 7:
			HitSound = sDirt[Rand(sDirt.Length)];
			break;
		case 8:
			HitSound = sWater[Rand(sWater.Length)];
			break;
		case 9:
			HitSound = sDirt[Rand(sDirt.Length)];
			break;
		case 10:
			HitSound = sMetal[Rand(sConcrete.Length)];
			break;
		case 11:
			HitSound = sWood[Rand(sWood.Length)];
			break;
		case 12:
			HitSound = sDirt[Rand(sDirt.Length)];
			break;
		case 13:
			HitSound = None;
			break;
		case 14:
			HitSound = sDirt[Rand(sDirt.Length)];
			break;
		case 15:
			HitSound = sDirt[Rand(sDirt.Length)];
			break;
		case 16:
			HitSound = sDirt[Rand(sDirt.Length)];
			break;
		case 17:
			HitSound = sConcrete[Rand(sConcrete.Length)];
			break;
		default:
			HitSound = None;
			break;
		}
	}
	if (HitSound != None)
	{
		Radius = 15;
		Pitch = fPitchModifier;
		Fade = 0;
		Priority = 0;
		Volume = 0.4;
		sizesq = VSizeSquared(E.Particles[PIndex].Velocity);
		if (sizesq < float(100000))
		{
			(Volume *= (sizesq / float(100000)));
		}
	}
	*/
}

FRangeVector ABaseShellEmitter::GetRVFromV(FVector V)
{
	FRangeVector RV;
	/*
	RV.X.Min = V.X;
	RV.X.Max = V.X;
	RV.Y.Min = V.Y;
	RV.Y.Max = V.Y;
	RV.Z.Min = V.Z;
	RV.Z.Max = V.Z;
	*/
	return RV;
}

FRangeVector ABaseShellEmitter::GetStartRotation()
{
	FRotator R = FRotator(0, 0, 0);
	FVector V = FVector(0, 0, 0);
	/*
	if (bInFirstPerson && (Instigator != None))
	{
		R = (Instigator.GetViewRotation() + Offset1P.ROffset);
	}
	else
	{
		R = Rotation;
	}
	V.X = float(R.Yaw);
	V.Y = float(R.Pitch);
	V.Z = float(R.Roll);
	(V /= float(65535));
	*/
	return GetRVFromV(V);
}

FRangeVector ABaseShellEmitter::GetStartVelocity()
{
	FVector V = FVector(0, 0, 0);
	FRotator R = FRotator(0, 0, 0);
	/*
	if (Instigator != None)
	{
		R = Instigator.Rotation;
		V = Instigator.Velocity;
	}
	else
	{
		R = Rotation;
	}
	(V += CalcDirection(ShellDirInfo, MakeRot(0, R.Yaw, 0)));
	*/
	return GetRVFromV(V);
}

FVector ABaseShellEmitter::GetStartLocationOffset()
{
	/*
	local Coords C;
	FVector loc = FVector(0, 0, 0);
	local Actor A;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	if (bInFirstPerson)
	{
		C = Instigator.Weapon.GetBoneCoords(Offset1P.nBone);
		loc = (((C.Origin + (Offset1P.VOffset.X * C.XAxis)) + (Offset1P.VOffset.Y * C.YAxis)) + (Offset1P.VOffset.Z * C.ZAxis));
		A = Instigator.Trace(HitLocation, HitNormal, loc, Instigator.Location);
		if (A != None)
		{
			loc = HitLocation;
		}
		return (loc - Location);
	}
	else
	{
		return vect(0, 0, 0);
	}
	*/
	return  FVector(0, 0, 0);
}

void ABaseShellEmitter::SetFirstPerson(bool bFirstPerson, bool bImmediate)
{
	/*
	bInFirstPerson = bFirstPerson;
	if (AttachTo3P == None)
	{
		return;
	}
	if (bInFirstPerson)
	{
		AttachTo3P.DetachFromBone(Self);
		if (bImmediate)
		{
			ImmedateUpdate1P();
		}
	}
	else
	{
		if (bImmediate)
		{
			ImmediateUpdate3P();
		}
		AttachTo3P.AttachToBoneOffset(Self, Offset3P);
	}
	*/
}

void ABaseShellEmitter::ImmedateUpdate1P()
{
	/*
	SetLocation(Instigator.Location);
	SetRotation(Instigator.Rotation);
	*/
}

void ABaseShellEmitter::ImmediateUpdate3P()
{
	/*
	SetLocation((Offset3P.VOffset + AttachTo3P.GetBoneCoords(Offset3P.nBone).Origin));
	SetRotation((Offset3P.ROffset + AttachTo3P.GetBoneRotation(Offset3P.nBone)));
	*/
}

void ABaseShellEmitter::Eject(bool bFirstPerson)
{
	/*
	if (bFirstPerson != bInFirstPerson)
	{
		SetFirstPerson(bFirstPerson, true);
	}
	if (bFirstPerson && bUseAnimNotifyEject)
	{
		return;
	}
	Emitters[0].StartLocationOffset = GetStartLocationOffset();
	Emitters[0].StartSpinRange = GetStartRotation();
	Emitters[0].StartVelocityRange = GetStartVelocity();
	Emitters[0].SpawnParticle(1);
	*/
}

void ABaseShellEmitter::AnimControlledEject()
{
	/*
	if ((!bInFirstPerson) || (Level.NetMode == NM_DedicatedServer))
	{
		return;
	}
	Emitters[0].StartLocationOffset = GetStartLocationOffset();
	Emitters[0].StartSpinRange = GetStartRotation();
	Emitters[0].StartVelocityRange = GetStartVelocity();
	Emitters[0].SpawnParticle(1);
	*/
}


