// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/AA2_Volume.h"
#include "AA29/Object/Actor/Keypoint/DecorationList/DecorationList.h"
#include "AA29/Object/Actor/Info/ZoneInfo/ZoneInfo.h"
#include "Engine/Canvas.h"

AAA2_Volume::AAA2_Volume()
{
	LocationName = "unspecified";
	//bSkipActorPropertyReplication = true;
	//CollisionRadius = 0;
	//CollisionHeight = 0;
	//bCollideActors = true;
}

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
	AAA2_Volume* OV = nullptr;
	if (Other == nullptr)
	{
		return true;
	}
	else
	{
		if (Other->IsA(AAA2_Volume::StaticClass()))
		{
			OV = Cast<AAA2_Volume>(Other);
			if (LocationPriority == OV->LocationPriority)
			{
				return (XY_Area < OV->XY_Area);
			}
			else
			{
				return (LocationPriority > OV->LocationPriority);
			}
		}
		else
		{
			if (Other->IsA(AZoneInfo::StaticClass()))
			{
				return (LocationPriority > Cast<AZoneInfo>(Other)->LocationPriority);
			}
			else
			{
				//DebugLog(DEBUG_Warn, "Volume::BetterThan()	Received unknown Actor for comparison " + FString::FromInt(Other));
				return true;
			}
		}
	}
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
		return nullptr;
	}
	*/
	return nullptr;    //FAKE   /EliZ
}

void AAA2_Volume::BeginPlay()
{
	FBox BBox;
	Super::BeginPlay();
	if (LocationName != "")
	{
		//BBox = GetBoundingBox();
		//XY_Area = (FMath::Abs((BBox.Min.X - BBox.Max.X)) * Abs((BBox.Min.Y - BBox.Max.Y)));
	}
	else
	{
		LocationPriority = -1;
	}
	if ((!bScoreDefender) && (!bScoreHelper))
	{
		Objective = nullptr;
	}
}

void AAA2_Volume::SetAssociatedActor(AActor* Other)
{
	AssociatedActor = Other;
	if (AssociatedActor != nullptr)
	{
		//GotoState('AssociatedTouch');
	}
	else
	{
		//GotoState("None");
	}
}

void AAA2_Volume::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (AssociatedActorTag != "None")
	{
		ForEach AllActors(Class'Actor', AssociatedActor, AssociatedActorTag)
		{
		}
	}
	if (AssociatedActor != nullptr)
	{
		GotoState('AssociatedTouch');
		InitialState = GetStateName();
	}
	*/
}

void AAA2_Volume::DisplayDebug(UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	Super::DisplayDebug(Canvas, YL, YPos);
	Canvas.DrawText("AssociatedActor " + FString::FromInt(AssociatedActor), false);
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	*/
}
