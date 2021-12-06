// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/AGP_VehicleBot/AGP_VehicleBot.h"

AAGP_VehicleBot::AAGP_VehicleBot()
{
	bAdvancedTactics = false;

}

/*
State Driving
{
	Event Bump (Actor Other)
	{
	}
	Function NotifyTakeHit (Pawn instigatedBy, Object.Vector HitLocation, int Damage, class<DamageType>  DamageType, Object.Vector Momentum)
	{
	}
	Event Touch (Actor Other)
	{
		Touch(Other);
		if (Other == CurDestination)
		{
			CurIntermediate=None;
			if (CROWS_HMMWV(Pawn) != None)
			{
				CROWS_HMMWV(Pawn).Throttle=0;
				CROWS_HMMWV(Pawn).Steering=0;
				CROWS_HMMWV(Pawn).Shifter=0;
			}
			MoveTimer=-1;
			EventLab.ActorNotify(Pawn,27,Self,CurDestination.Tag);
		}
		else
		{
			if (Other == CurIntermediate)
			{
				EventLab.ActorNotify(Pawn,27,Self,CurIntermediate.Tag);
				CurIntermediate=CurIntermediate.NextNode;
				MoveTimer=-1;
			}
		}
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
