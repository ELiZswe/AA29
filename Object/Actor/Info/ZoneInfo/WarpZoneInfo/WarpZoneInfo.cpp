// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ZoneInfo/WarpZoneInfo/WarpZoneInfo.h"

AWarpZoneInfo::AWarpZoneInfo()
{

}

/*
State DelayedWarp
{
	Function Tick(float DeltaTime)
	{
		local Controller p;
		bool bFound = false;
		p=Level.ControllerList;
		if (p != None)
		{
			if (p.Pawn.bWarping && (p.Pawn.Region.Zone == Self))
			{
				bFound=true;
				ActorEntered(p);
			}
			p=p.nextController;
		}
		if (! bFound)
		{
			GotoState("None");
		}
	}
}
*/

/*
replication
{
	reliable if ((Role == ROLE_Authority))
		OtherSideURL, ThisTag, OtherSideActor;
}
*/

//native(314) final Function Warp(Vector& loc, Vector& Vel, Rotator& R);
void AWarpZoneInfo::Warp(FVector& loc, FVector& Vel, FRotator& R)
{

}

//native(315) final Function UnWarp(Vector& loc, Vector& Vel, Rotator& R);
void AWarpZoneInfo::UnWarp(FVector& loc, FVector& Vel, FRotator& R)
{

}

void AWarpZoneInfo::PreBeginPlay()
{
	/*
	Super::PreBeginPlay();
	Generate();
	numDestinations = 0;
	if (numDestinations < 8)
	{
		if (Destinations[numDestinations] != "")
		{
			numDestinations++;
		}
		else
		{
			numDestinations = 8;
		}
	}
	if ((numDestinations > 0) && (OtherSideURL == ""))
	{
		OtherSideURL = Destinations[0];
	}
	*/
}

void AWarpZoneInfo::Trigger(AActor* Other, APawn* EventInstigator)
{
	int32 nextPick = 0;
	/*
	if (numDestinations == 0)
	{
		return;
	}
	nextPick = 0;
	if ((nextPick < 8) && (Destinations[nextPick] != OtherSideURL))
	{
		nextPick++;
	}
	nextPick++;
	if ((nextPick > 7) || (Destinations[nextPick] == ""))
	{
		nextPick = 0;
	}
	OtherSideURL = Destinations[nextPick];
	ForceGenerate();
	*/
}

void AWarpZoneInfo::Generate()
{
	if (OtherSideLevel != nullptr)
	{
		return;
	}
	ForceGenerate();
}

void AWarpZoneInfo::ForceGenerate()
{
	/*
	if (InStr(OtherSideURL, "/") >= 0)
	{
		OtherSideLevel = nullptr;
		OtherSideActor = nullptr;
	}
	else
	{
		OtherSideLevel = XLevel;
		ForEach AllActors(Class'WarpZoneInfo', OtherSideActor)
		{
			if ((string(OtherSideActor.ThisTag) ~= OtherSideURL) && (OtherSideActor != Self))
			{
			}
		}
	}
	*/
}

void AWarpZoneInfo::ActorEntered(AActor* Other)
{
	FVector L = FVector(0, 0, 0);
	FRotator R = FRotator(0, 0, 0);
	/*
	local Controller p;
	if (!Other.bJustTeleported)
	{
		Generate();
		if (OtherSideActor != None)
		{
			Other.Disable("Touch");
			Other.Disable("UnTouch");
			L = Other.Location;
			if (Pawn(Other) != None)
			{
				R = Pawn(Other).GetViewRotation();
			}
			UnWarp(L, Other.Velocity, R);
			OtherSideActor.Warp(L, Other.Velocity, R);
			if (Other.IsA("Pawn"))
			{
				Pawn(Other).bWarping = bNoTeleFrag;
				if (Other.SetLocation(L))
				{
					if (Role == 4)
					{
						p = Level.ControllerList;
						if (p != None)
						{
							if (p.Enemy == Other)
							{
								p.LineOfSightTo(Other);
							}
							p = p.nextController;
						}
					}
					R.Roll = 0;
					Pawn(Other).SetViewRotation(R);
					Pawn(Other).ClientSetLocation(L, R);
					if (Pawn(Other).Controller != None)
					{
						Pawn(Other).Controller.MoveTimer = -1;
					}
				}
				else
				{
					GotoState("DelayedWarp");
				}
			}
			else
			{
				Other.SetLocation(L);
				Other.SetRotation(R);
			}
			Other.Enable("Touch");
			Other.Enable("UnTouch");
		}
	}
	*/
}

void AWarpZoneInfo::ActorLeaving(AActor* Other)
{
	/*
	if (Other.IsA("Pawn"))
	{
		Pawn(Other).bWarping = false;
	}
	*/
}