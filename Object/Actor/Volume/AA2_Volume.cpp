// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/AA2_Volume.h"

AAA2_Volume::AAA2_Volume()
{
	LocationName = "unspecified";
	//bSkipActorPropertyReplication = true;
	//CollisionRadius = 0;
	//CollisionHeight = 0;
	//bCollideActors = true;
}

/*
State AssociatedTouch
{
	Event Touch(Actor Other)
	{
		AssociatedActor.Touch(Other);
	}
	Event UnTouch(Actor Other)
	{
		AssociatedActor.UnTouch(Other);
	}
	Function BeginState()
	{
		local Actor A;
		ForEach TouchingActors(Class'Actor', A)
		{
			Touch(A);
		}
	}
}
*/

//native Function bool Encompasses(Actor Other);
bool AAA2_Volume::Encompasses(AActor* Other)
{
	return false;    //FAKE /ELiZ
}

//native Function bool EncompassesPoint(Vector Point);
bool AAA2_Volume::EncompassesPoint(FVector Point)
{
	return false;    //FAKE /ELiZ
}


bool AAA2_Volume::BetterThan(AActor* Other)
{
	/*
	local Volume OV;
	if (Other == None)
	{
		return true;
	}
	else
	{
		if (Other.IsA('Volume'))
		{
			OV = Volume(Other);
			if (LocationPriority == OV.LocationPriority)
			{
				return (XY_Area < OV.XY_Area);
			}
			else
			{
				return (LocationPriority > OV.LocationPriority);
			}
		}
		else
		{
			if (Other.IsA('ZoneInfo'))
			{
				return (LocationPriority > ZoneInfo(Other).LocationPriority);
			}
			else
			{
				DebugLog(DEBUG_Warn, "Volume::BetterThan()	Received unknown Actor for comparison " $ string(Other));
				return true;
			}
		}
	}
	*/
	return false;   //FAKE   /ELiZ
}

AActor* AAA2_Volume::GetNearbyObjective(bool bDefender)
{
	/*
	if ((bDefender && bScoreDefender) || ((!bDefender) && bScoreHelper))
	{
		return Objective;
	}
	else
	{
		return None;
	}
	*/
	return nullptr;    //FAKE   /EliZ
}

void AAA2_Volume::BeginPlay()
{
	/*
	local Box BBox;
	Super::BeginPlay();
	if (LocationName != "")
	{
		BBox = GetBoundingBox();
		XY_Area = (Abs((BBox.Min.X - BBox.Max.X)) * Abs((BBox.Min.Y - BBox.Max.Y)));
	}
	else
	{
		LocationPriority = -1;
	}
	if ((!bScoreDefender) && (!bScoreHelper))
	{
		Objective = None;
	}
	*/
}

void AAA2_Volume::SetAssociatedActor(AActor* Other)
{
	/*
	AssociatedActor = Other;
	if (AssociatedActor != None)
	{
		GotoState('AssociatedTouch');
	}
	else
	{
		GotoState('None');
	}
	*/
}

void AAA2_Volume::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (AssociatedActorTag != 'None')
	{
		ForEach AllActors(Class'Actor', AssociatedActor, AssociatedActorTag)
		{
		}
	}
	if (AssociatedActor != None)
	{
		GotoState('AssociatedTouch');
		InitialState = GetStateName();
	}
	*/
}

//void AAA2_Volume::DisplayDebug(UCanvas* Canvas, float& YL, float& YPos)

void AAA2_Volume::DisplayDebug(UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	Super::DisplayDebug(Canvas, YL, YPos);
	Canvas.DrawText("AssociatedActor " $ string(AssociatedActor), false);
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	*/
}