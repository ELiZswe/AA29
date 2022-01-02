// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AGP_VehicleBot/AGP_VehicleBot.h"

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
			if (CROWS_HMMWV(Pawn) != nullptr)
			{
				CROWS_HMMWV(Pawn).Throttle=0;
				CROWS_HMMWV(Pawn).Steering=0;
				CROWS_HMMWV(Pawn).Shifter=0;
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
	if (CROWS_HMMWV(Pawn) != nullptr)
	{
		CROWS_HMMWV(Pawn).Shifter=1;
	}
	if (CurIntermediate != nullptr)
	{
		Pawn.DesiredSpeed=CurIntermediate.fpDesiredSpeed;
		Pawn.MaxDesiredSpeed=CurIntermediate.fpMaxDesiredSpeed;
		Focus=CurIntermediate;
		CROWS_HMMWV(Pawn).Shifter=1;
		MoveToward(CurIntermediate);
		JL"Drive"
;
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
	//GotoState('Driving');
}
