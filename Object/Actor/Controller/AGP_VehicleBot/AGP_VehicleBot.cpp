// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AGP_VehicleBot/AGP_VehicleBot.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/NPCRoadPathNode/AGP_VehicleNode/AGP_VehicleNode.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"

AAGP_VehicleBot::AAGP_VehicleBot()
{
	bAdvancedTactics = false;

}

/*
State Driving
{
	Event Touch(AActor* Other)
	{
		Super::Touch(Other);
		if (Other == CurDestination)
		{
			CurIntermediate=nullptr;
			if (Cast<ACROWS_HMMWV>(Pawn) != nullptr)
			{
				Cast<ACROWS_HMMWV>(Pawn).Throttle=0;
				Cast<ACROWS_HMMWV>(Pawn).Steering=0;
				Cast<ACROWS_HMMWV>(Pawn).Shifter=0;
			}
			MoveTimer=-1;
			EventLab.ActorNotify(Pawn,27,Self,string(CurDestination.Tag));
		}
		else
		{
			if (Other == CurIntermediate)
			{
				EventLab.ActorNotify(Pawn,27,Self,string(CurIntermediate.Tag));
				CurIntermediate=CurIntermediate.NextNode;
				MoveTimer=-1;
			}
		}
	}
	Function NotifyTakeHit(APawn* instigatedBy, Vector HitLocation, int32 Damage, class<DamageType>  DamageType, Vector Momentum)
	{
	}
	Event Bump(AActor* Other)
	{
	}
Begin:
	if (Pawn == nullptr)
	{
		GotoState("None");
	}
	if (Cast<ACROWS_HMMWV>(Pawn) != nullptr)
	{
		Cast<ACROWS_HMMWV>(Pawn).Shifter=1;
	}
	if (CurIntermediate != nullptr)
	{
		Pawn.DesiredSpeed=CurIntermediate.fpDesiredSpeed;
		Pawn.MaxDesiredSpeed=CurIntermediate.fpMaxDesiredSpeed;
		Focus=CurIntermediate;
		Cast<ACROWS_HMMWV>(Pawn).Shifter=1;
		MoveToward(CurIntermediate);
		JL"Drive";
	}
}
*/

void AAGP_VehicleBot::SetCurrentNode(AAGP_VehicleNode* newNode)
{
	CurIntermediate = newNode;
}

void AAGP_VehicleBot::SetDestination(AAGP_VehicleNode* newNode)
{
	CurDestination = newNode;
}

void AAGP_VehicleBot::Trigger(AActor* Other, APawn* EventInstigator)
{
	ChangeState("Driving");
}
