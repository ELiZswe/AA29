// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/PotentialClimbWatcher/PotentialClimbWatcher.h"
#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/LadderVolume/LadderVolume.h"

APotentialClimbWatcher::APotentialClimbWatcher()
{

}

void APotentialClimbWatcher::Tick(float DeltaTime)
{
	FRotator PawnRot = FRotator(0, 0, 0);
	ALadderVolume* L = nullptr;
	bool bFound = false;
	APawn* p = nullptr;
	FVector TraceDir = FVector(0, 0, 0);
	/*
	p = Pawn(GetOwner());
	if (((p == nullptr) || p.bDeleteMe) || (!p.CanGrabLadder()))
	{
		Destroy();
		return;
	}
	PawnRot = p.Rotation;
	PawnRot.Pitch = 0;
	ForEach p.TouchingActors(ALadderVolume::StaticClass(), L)
	{
		if (L.Encompasses(p))
		{
			TraceDir = L.ClimbDir;
			if ((Vector(p.GetViewRotation()) Dot L.ClimbDir) < 0)
			{
				(TraceDir *= -1);
			}
			if ((((((((p.Acceleration Dot L.LookDir) > 0.7) || IsZero(p.Acceleration)) || (p.Physics == 2)) && ((Vector(PawnRot) Dot L.LookDir) > 0.9)) && (!p.bIsProne)) && ((!p.IsBusy()) || p.IsInState("BusyJumping"))) && (((p.Weapon == nullptr) || (!p.Weapon.IsBusy())) || p.Weapon.IsTempBusy()))
			{
				p.ClimbLadder(L);
				Destroy();
				return;
			}
			else
			{
				bFound = true;
			}
		}
	}
	if (!bFound)
	{
		Destroy();
	}
	*/
}
