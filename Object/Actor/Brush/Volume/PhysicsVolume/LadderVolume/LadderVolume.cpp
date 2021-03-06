// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/Ladder/Ladder.h"
#include "AA29/Object/Actor/Info/PotentialClimbWatcher/PotentialClimbWatcher.h"
#include "AA29/Object/Sound/Sound.h"

ALadderVolume::ALadderVolume()
{
	ClimbDir = FVector(0, 0, 1);
	bAutoPath = true;
	bStartOn = true;
	bDoTriggerLadder = true;
	//RemoteRole = 2;
}

void ALadderVolume::PostBeginPlay()
{
	ALadder* L = nullptr;
	ALadder* M = nullptr;
	FVector Dir = FVector(0, 0, 0);
	//Super::PostBeginPlay();
	if (bDoTriggerLadder)
	{
		SetLadderState(bStartOn);
	}
	//LookDir = Vector(WallDir);
	if ((!bAutoPath) && (LookDir.Z != 0))
	{
		//ClimbDir = FVector(0, 0, 1);
		for (L = LadderList; L != nullptr; L = L->LadderList)
		{
			for (M = LadderList; M != nullptr; M = M->LadderList)
			{
				if (M != L)
				{
					/*
					Dir = Normal((M.Location - L.Location));
					if ((Dir Dot ClimbDir) < 0)
					{
						Dir *= float(-1);
					}
					*/
					ClimbDir += Dir;
				}
			}
		}
		/*
		ClimbDir = Normal(ClimbDir);
		if ((ClimbDir Dot FVector(0, 0, 1)) < 0)
		{
			ClimbDir *= float(-1);
		}
		*/
	}

}

bool ALadderVolume::InUse(APawn* Ignored)
{
	APawn* StillClimbing = nullptr;
	/*
	ForEach TouchingActors(Class'Pawn', StillClimbing)
	{
		if (((StillClimbing != Ignored) && StillClimbing.bCollideActors) && StillClimbing.bBlockActors)
		{
			return true;
		}
	}
	if (PendingClimber != nullptr)
	{
		if (((((PendingClimber.Controller == nullptr) || (!PendingClimber.bCollideActors)) || (!PendingClimber.bBlockActors)) || (Cast<ALadder>(PendingClimber.Controller.MoveTarget) == nullptr)) || (Cast<ALadder>(PendingClimber.Controller.MoveTarget).MyLadder != Self))
		{
			PendingClimber = nullptr;
		}
	}
	return ((PendingClimber != nullptr) && (PendingClimber != Ignored));
	*/
	return false;    //FAKE   /ELiZ
}

void ALadderVolume::PawnEnteredVolume(APawn* p)
{
	FRotator PawnRot = FRotator(0, 0, 0);
	FVector TraceDir = FVector(0, 0, 0);
	/*
	Super::PawnEnteredVolume(p);
	if (!p.CanGrabLadder())
	{
		return;
	}
	TraceDir = ClimbDir;
	if ((Vector(p.GetViewRotation()) Dot ClimbDir) < 0)
	{
		(TraceDir *= -1);
	}
	if (p.Role == 2)
	{
		p.ClimbLadder(this);
		PawnRot = p.Rotation;
		PawnRot.Pitch = 0;
		return;
	}
	if (!p.CanGrabLadder())
	{
		return;
	}
	PawnRot = p.Rotation;
	PawnRot.Pitch = 0;
	if (((((((p.Weapon == nullptr) || (!p.Weapon.IsBusy())) || p.Weapon.IsTempBusy()) && ((!p.IsBusy()) || p.IsInState('BusyJumping'))) && (!p.bIsProne)) && ((((p.Acceleration Dot LookDir) > 0.7) || IsZero(p.Acceleration)) || (p.Physics == 2))) && (((Vector(PawnRot) Dot LookDir) > 0.9) || ((Cast<AAIController>(p.Controller) != nullptr) && (Cast<ALadder>(p.Controller.MoveTarget) != nullptr))))
	{
		p.ClimbLadder(this);
	}
	else
	{
		if ((!p.bDeleteMe) && (p.Controller != nullptr))
		{
			Spawn(APotentialClimbWatcher::StaticClass(), p);
		}
	}
	*/
}

void ALadderVolume::PawnLeavingVolume(APawn* p)
{
	/*
	if (p.Role == 2)
	{
		Super::PawnLeavingVolume(p);
		p.OnLadder = nullptr;
		p.EndClimbLadder(this);
		return;
	}
	if (p.OnLadder != Self)
	{
		return;
	}
	Super::PawnLeavingVolume(p);
	p.OnLadder = nullptr;
	p.EndClimbLadder(this);
	*/
}

void ALadderVolume::PhysicsChangedFor(AActor* Other)
{
	/*
	if (((((Other.Physics == 2) || (Other.Physics == 11)) || Other.bDeleteMe) || (Cast<APawn>(Other) == nullptr)) || (Cast<APawn>(Other).Controller == nullptr))
	{
		return;
	}
	Spawn(APotentialClimbWatcher::StaticClass(), Other);
	*/
}

void ALadderVolume::MatchStarting()
{
	/*
	Super::MatchStarting();
	if (bDoTriggerLadder)
	{
		SetLadderState(bStartOn);
	}
	*/
}

void ALadderVolume::SetLadderState(bool bOn)
{
	/*
	if (bOn)
	{
		SetCollision(true, false, false);
		bLadderIsOn = true;
	}
	else
	{
		SetCollision(false, false, false);
		bLadderIsOn = false;
	}
	*/
}

void ALadderVolume::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	Super::Trigger(Other, EventInstigator);
	if (!bDoTriggerLadder)
	{
		return;
	}
	if (bLadderIsOn)
	{
		SetLadderState(false);
	}
	else
	{
		SetLadderState(true);
	}
	*/
}

USoundBase* ALadderVolume::GetLadderClimbSound()
{
	FString sound_name = "";
	FString mat_name = "";
	int32 Max = 0;
	int32 Index = 0;
	USoundBase* S = nullptr;
	/*
	sound_name = "S_AA2_Material.Ladder.";
	switch (ClimbSound)
	{
	case 1:
		mat_name = "Wood";
		Max = 3;
		break;
	case 0:
		mat_name = "Metal";
		Max = 3;
		break;
	default:
	}
	Index = (Rand(Max) + 1);
	sound_name = "S_AA2_Material.Ladder." + mat_name + "LadderDefault" + FString::FromInt(Index);
	S = Sound(DynamicLoadObject(sound_name, USound::StaticClass()));
	*/
	return S;
}
