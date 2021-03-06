// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/Teleporter/Teleporter.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/ReachSpec/ReachSpec.h"

ATeleporter::ATeleporter()
{
	bChangesYaw = true;
	bEnabled = true;
	bSpecialForced = true;
	//RemoteRole = 2;
	//SoundVolume = 128;
	//bCollideActors = true;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Teleport.S_Teleport'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

/*
replication
{
	reliable if ((Role == ROLE_Authority))
		URL, bEnabled;
	reliable if ((bNetInitial && (Role == ROLE_Authority)))
		bChangesVelocity, bChangesYaw, bReversesX, bReversesY, bReversesZ, TargetVelocity;
}
*/

void ATeleporter::PostBeginPlay()
{
	int32 i = 0;
	/*
	if (URL ~= "")
	{
		SetCollision(false, false, false);
	}
	if (!bEnabled)
	{
		FindTriggerActor();
	}
	for (i = 0; i < PathList.Num(); i++)
	{
		if (Cast<ATeleporter>(PathList[i].End) != nullptr)
		{
			PathList[i].bForced = true;
			PathList[i].reachFlags = (PathList[i].reachFlags | 256);
		}
	}
	Super::PostBeginPlay();
	*/
}

void ATeleporter::FindTriggerActor()
{
	AActor* A = nullptr;
	TriggerActor = nullptr;
	TriggerActor2 = nullptr;
	/*
	ForEach DynamicActors(Class'Actor', A)
	{
		if (A.Event == Tag)
		{
			if (TriggerActor == nullptr)
			{
				TriggerActor = A;
			}
			else
			{
				TriggerActor2 = A;
				return;
			}
		}
	}
	*/
}

bool ATeleporter::Accept(AActor* Incoming, AActor* Source)
{
	FRotator newRot = FRotator(0, 0, 0);
	FRotator OldRot = FRotator(0, 0, 0);
	float mag = 0;
	FVector oldDir = FVector(0, 0, 0);
	AController* p = nullptr;
	if (Incoming == nullptr)
	{
		return false;
	}
	/*
	Disable("Touch");
	newRot = Incoming.Rotation;
	if (bChangesYaw)
	{
		OldRot = Incoming.Rotation;
		newRot.Yaw = Rotation.Yaw;
		if (Source != nullptr)
		{
			newRot.Yaw += ((32768 + Incoming.Rotation.Yaw) - Source.Rotation.Yaw);
		}
	}
	if (Cast<APawn>(Incoming) != nullptr)
	{
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			for (p = Level.ControllerList; p != nullptr; p = p.nextController)
			{
				if (p.Enemy == Incoming)
				{
					p.LineOfSightTo(Incoming);
				}
			}
		}
		if (!Pawn(Incoming).SetLocation(Location))
		{
			Log(string(this) + " Teleport failed for " + FString::FromInt(Incoming));
			return false;
		}
		if ((GetRemoteRole() == ENetRole::ROLE_MAX) || ((GetWorld()->GetTimeSeconds() - LastFired) > 0.5))
		{
			newRot.Roll = 0;
			Cast<APawn>(Incoming).SetRotation(newRot);
			Cast<APawn>(Incoming).SetViewRotation(newRot);
			Cast<APawn>(Incoming).ClientSetRotation(newRot);
			LastFired = GetWorld()->GetTimeSeconds();
		}
		if (Cast<APawn>(Incoming).Controller != nullptr)
		{
			Cast<APawn>(Incoming).Controller.MoveTimer = -1;
			Cast<APawn>(Incoming).Anchor = this;
			Cast<APawn>(Incoming).SetMoveTarget(this);
		}
		Incoming.PlayTeleportEffect(false, true);
	}
	else
	{
		if (!Incoming.SetLocation(Location))
		{
			Enable("Touch");
			return false;
		}
		if (bChangesYaw)
		{
			Incoming.SetRotation(newRot);
		}
	}
	Enable("Touch");
	if (bChangesVelocity)
	{
		Incoming.Velocity = TargetVelocity;
	}
	else
	{
		if (bChangesYaw)
		{
			if (Incoming.Physics == 1)
			{
				OldRot.Pitch = 0;
			}
			oldDir = Vector(OldRot);
			mag = (Incoming.Velocity Dot oldDir);
			Incoming.Velocity = ((Incoming.Velocity - (mag * oldDir)) + (mag * Vector(Incoming.Rotation)));
		}
		if (bReversesX)
		{
			Incoming.Velocity.X *= -1;
		}
		if (bReversesY)
		{
			Incoming.Velocity.Y *= -1;
		}
		if (bReversesZ)
		{
			Incoming.Velocity.Z *= -1;
		}
	}
	*/
	return true;

}

void ATeleporter::Trigger(AActor* Other, APawn* EventInstigator)
{
	AActor* A = nullptr;
	bEnabled = !bEnabled;
	if (bEnabled)
	{
		/*
		ForEach TouchingActors(Class'Actor', A)
		{
			PostTouch(A);
		}
		*/
	}
}

void ATeleporter::Touch(AActor* Other)
{
	if ((!bEnabled) || (Other == nullptr))
	{
		return;
	}
	/*
	if (Other.bCanTeleport && (Other.PreTeleport(this) == false))
	{
		PendingTouch = Other.PendingTouch;
		Other.PendingTouch = this;
	}
	*/
}

void ATeleporter::PostTouch(AActor* Other)
{
	ATeleporter* D = nullptr;
	TArray<ATeleporter*> Dest;
	Dest.SetNum(16);
	int32 i = 0;
	/*
	if ((InStr(URL, "/") >= 0) || (InStr(URL, "#") >= 0))
	{
		if (((GetRemoteRole() == ENetRole::ROLE_MAX) && (Cast<APawn>(Other) != nullptr)) && Pawn(Other).IsHumanControlled())
		{
			Level.Game.SendPlayer(Cast<APlayerController>(Cast<APawn>(Other).Controller), URL);
		}
	}
	else
	{
		ForEach AllActors(ATeleporter::StaticClass(), D)
		{
			if ((string(D.Tag) ~= URL) && (D != Self))
			{
				Dest[i] = D;
				i++;
				if (i > 16)
				{
				}
			}
			else
			{
			}
		}
		i = Rand(i);
		if (Dest[i] != nullptr)
		{
			if (Other->IsA(APawn::StaticClass()))
			{
				Other.PlayTeleportEffect(false, true);
			}
			Dest[i].Accept(Other, this);
			if (Cast<APawn>(Other) != nullptr)
			{
				TriggerEvent(Event, this, Pawn(Other));
			}
		}
	}
	*/
}

AActor* ATeleporter::SpecialHandling(APawn* Other)
{
	FVector Dist2D = FVector(0, 0, 0);
	/*
	if ((bEnabled && (Cast<ATeleporter>(Other.Controller.RouteCache[1]) != nullptr)) && (string(Other.Controller.RouteCache[1].Tag) ~= URL))
	{
		if (FMath::Abs((Location.Z - Other.Location.Z)) < (CollisionHeight + Other.CollisionHeight))
		{
			Dist2D = (Location - Other.Location);
			Dist2D.Z = 0;
			if (VSize(Dist2D) < (CollisionRadius + Other.CollisionRadius))
			{
				PostTouch(Other);
			}
		}
		return this;
	}
	if (TriggerActor == nullptr)
	{
		FindTriggerActor();
		if (TriggerActor == nullptr)
		{
			return nullptr;
		}
	}
	if ((TriggerActor2 != nullptr) && (VSize((TriggerActor2.Location - Other.Location)) < VSize((TriggerActor.Location - Other.Location))))
	{
		return TriggerActor2;
	}
	*/
	return TriggerActor;
}

int32 ATeleporter::SpecialCost(APawn* Other, UReachSpec* Path)
{
	/*
	if ((Cast<ATeleporter>(Path.Start) == nullptr) || ((Path.reachFlags & 32) == 0))
	{
		return 0;
	}
	*/

	if (Cast<AVehicle>(Other) != nullptr)
	{
		return 10000000;
	}
	return 0;
}
