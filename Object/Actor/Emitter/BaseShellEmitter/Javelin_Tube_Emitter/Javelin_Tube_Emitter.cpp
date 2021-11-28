// All the original content belonged to the US Army

#include "Javelin_Tube_Emitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

AJavelin_Tube_Emitter::AJavelin_Tube_Emitter()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->UseCollision = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->Acceleration = FVector(0, 0, -750);
	MeshEmitter0->ExtentMultiplier = FVector(0.2, 0.2, 0.2);
	MeshEmitter0->DampingFactorRange = FRangeVector({ {0.1, 0.3}, {0.1, 0.3}, {0.1, 0.3} });
	MeshEmitter0->MaxParticles = 1;
	MeshEmitter0->SpinsPerSecondRange = FRangeVector({ {-0.08, 0.08}, {-0.08, 0.08}, {-0.08, 0.08} });
	MeshEmitter0->SecondsBeforeInactive = 0;
	MeshEmitter0->LifetimeRange = FRange({ 20, 20 });
	MeshEmitter0->StartVelocityRange = FRangeVector({ {0, 0}, {100, 100}, {0, 0} });
	MeshEmitter0->bPlayCollisionSoundFromOwner = true;
	MeshEmitter0->LandedMinSquaredVelocity = 10000;
	MeshEmitter0->bRestOnLand = true;
	MeshEmitter0->RestReset = FVector(0, 0, 0.25);
	MeshEmitter0->bRestReset_YPitch = true;
	MeshEmitter0->bRestReset_ZRoll = true;
	MeshEmitter0->bWeirdSpinOnCollide = true;
	MeshEmitter0->WeirdBounce = 0.1;

	sWood = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL)
	};
	sConcrete = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL)
	};
	sMetal = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL)
	};
	sWater = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Watersplash.S_Armo_Javelin_Watersplash"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Watersplash.S_Armo_Javelin_Watersplash"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Watersplash.S_Armo_Javelin_Watersplash"), NULL, LOAD_None, NULL)
	};
	sDirt = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL)
	};

	ShellDrawScale = FVector(1.13, 1.13, 1.13);
	ShellStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3PLoaded.Tube3PLoaded"), NULL, LOAD_None, NULL),
	bUseAnimNotifyEject = true;
};

FRangeVector AJavelin_Tube_Emitter::GetStartVelocity()
{
	FVector V = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	/*
	GetAxes(Instigator.Rotation, X, Y, Z);
	if (Instigator != None)
	{
		V = Instigator.Velocity;
	}
	V = ((V + (Y * float(100))) + (float(15) * X));
	*/
	return GetRVFromV(V);
}

FRangeVector AJavelin_Tube_Emitter::GetStartRotation()
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
		R.Roll = (R.Roll + 32768);
	}
	V.X = float(R.Yaw);
	V.Y = float(R.Pitch);
	V.Z = float(R.Roll);
	(V /= float(65535));
	*/
	return GetRVFromV(V);
}