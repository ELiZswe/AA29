// All the original content belonged to the US Army

#include "AA29/Object/Actor/FSTS_HelpMarker/FSTS_HelpMarker.h"

// Sets default values
AFSTS_HelpMarker::AFSTS_HelpMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryDrawScale = 1.5;
	AltDrawScale = 6;
	PrimaryStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FX/star/m_fx_floating_star.m_fx_floating_star'"), NULL, LOAD_None, NULL);
	AltStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FX/star/m_fx_floating_star.m_fx_floating_star'"), NULL, LOAD_None, NULL);
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_FX/star/m_fx_floating_star.m_fx_floating_star'"), NULL, LOAD_None, NULL);
	//bUnlit = true;
	//CollisionRadius = 0;
	//CollisionHeight = 0;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	//RotationRate = FRotator(0, 200, 0);
}


void AFSTS_HelpMarker::BeginPlay()
{
	Super::BeginPlay();
}

void AFSTS_HelpMarker::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (CustomDisplayClass != nullptr)
	{
		CustomDisplay = Spawn(CustomDisplayClass, this, , Location, Rotation);
		CustomDisplay.SetBase(this);
		CustomDisplay.SetRelativeLocation(FVector(0, 0, 0));
		CustomDisplay.SetRelativeRotation(FRotator(0, 0, 0));
		CustomDisplay.bHidden = true;
	}
	*/
}

void AFSTS_HelpMarker::Tick(float dt)
{
	FVector newBounceLocation = FVector(0, 0, 0);
	FVector localX = FVector(0, 0, 0);
	FVector localY = FVector(0, 0, 0);
	FVector localZ = FVector(0, 0, 0);
	FRotator NewRotation = FRotator(0, 0, 0);
	float BounceMagnitude = 0;
	Super::Tick(dt);
	(BounceTime += dt);
	/*
	if (BounceTime > 1)
	{
		(BounceTime -= 1);
		SetActorLocation((OldMarkLocation + MarkOffset));
	}
	if ((!bNoFollowMarkingActor) && (Owner != nullptr))
	{
		newBounceLocation = (Location + (Owner.Location - OldMarkLocation));
		OldMarkLocation = Owner.Location;
	}
	else
	{
		newBounceLocation = Location;
	}
	localX = Vector(Rotation);
	localX = Normal(localX);
	localY = (localX Cross FVector(0, 0, 1));
	localY = Normal(localY);
	localZ = (localY Cross localX);
	localZ = Normal(localZ);
	BounceMagnitude = (0.5 * Sin(((BounceTime * 2) * 3.141593)));
	switch (BounceAxis)
	{
	case 1:
		(newBounceLocation.X += BounceMagnitude);
		break;
	case 2:
		(newBounceLocation.Y += BounceMagnitude);
		break;
	case 0:
		(newBounceLocation.Z += BounceMagnitude);
		break;
	case 4:
		(newBounceLocation += (localX * BounceMagnitude));
		break;
	case 5:
		(newBounceLocation += (localY * BounceMagnitude));
		break;
	case 3:
		(newBounceLocation += (localZ * BounceMagnitude));
		break;
	default:
	}
	NewRotation = Rotation;
	(NewRotation += RotationRate);
	if (CustomDisplay != nullptr)
	{
		CustomDisplay.SetLocation(newBounceLocation);
		CustomDisplay.SetRotation(NewRotation);
	}
	SetActorLocation(newBounceLocation);
	SetActorRotation(NewRotation);
	OldLocation = Location;
	*/
}

void AFSTS_HelpMarker::ChangedMarker(FVector MarkingActorLocation, FVector MarkerOffset, bool bNoFollowTarget)
{
	BounceTime = 0;
	bNoFollowMarkingActor = bNoFollowTarget;
	MarkOffset = MarkerOffset;
	OldMarkLocation = MarkingActorLocation;
	//OldLocation = Location;
}

bool AFSTS_HelpMarker::SetMarkingActor(AActor* Target, FVector MarkerOffset, bool bNoFollowTarget)
{
	FVector newMarkerLocation = FVector(0, 0, 0);
	if (Target == nullptr)
	{
		//Log("ERROR: Couldn't place help marker, No valid location given");
		return false;
	}
	/*
	newMarkerLocation = (Target.Location + MarkerOffset);
	SetActorLocation(newMarkerLocation);
	SetActorRotation(Target.Rotation);
	if (CustomDisplay != nullptr)
	{
		CustomDisplay.SetLocation(Location);
		CustomDisplay.SetRotation(Rotation);
	}
	SetOwner(Target);
	MarkActor = Target;
	ChangedMarker(Target->GetActorLocation(), MarkerOffset, bNoFollowTarget);
	*/
	return true;
}

bool AFSTS_HelpMarker::SetMarkingLocation(FVector NewLocation, FVector MarkerOffset)
{
	FVector newMarkerLocation = FVector(0, 0, 0);
	newMarkerLocation = (NewLocation + MarkerOffset);
	/*
	SetActorLocation(newMarkerLocation);
	if (CustomDisplay != nullptr)
	{
		CustomDisplay.SetLocation(Location);
	}
	SetOwner(nullptr);
	*/
	ChangedMarker(NewLocation, MarkerOffset, true);
	return true;
}

void AFSTS_HelpMarker::ActivateMarker()
{
	/*
	bHidden = false;
	if (CustomDisplay != nullptr)
	{
		CustomDisplay.bHidden = false;
	}
	*/
}

void AFSTS_HelpMarker::DeactivateMarker()
{
	/*
	bHidden = true;
	if (CustomDisplay != nullptr)
	{
		CustomDisplay.bHidden = true;
	}
	*/
}

bool AFSTS_HelpMarker::IsActive()
{
	//return bHidden;
	return false;    //FAKE  /ELiZ
}

void AFSTS_HelpMarker::SetDisplayMesh(bool bUsePrimaryMesh)
{
	if (bUsePrimaryMesh)
	{
		//SetStaticMesh(PrimaryStaticMesh);
		//SetDrawScale(PrimaryDrawScale);
	}
	else
	{
		//SetStaticMesh(AltStaticMesh);
		//SetDrawScale(AltDrawScale);
	}
}
