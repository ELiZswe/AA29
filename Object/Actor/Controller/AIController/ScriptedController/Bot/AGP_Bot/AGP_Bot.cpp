// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/ScriptedController/Bot/AGP_Bot/AGP_Bot.h"
#include "AA29/Object/AI_Thought/AI_Thought.h"

AAGP_Bot::AAGP_Bot()
{

}

/*
State Idle
{
}
*/

/*
State Walking extends Idle
{
	Event BeginState()
	{
		if (DestinationNode == nullptr)
		{
			GotoState("Idle");
		}
		DebugLog(DEBUG_AI,"AGP_BOT:Walking:BeginState():DestinationNode =" $ string(DestinationNode));
		GotoState(GetStateName(),"DestNode");
	}
	Function Arrived(AActor* Destination)
	{
		Super::Arrived(Destination);
		DebugLog(DEBUG_AI,"AGP_BOT:Walking:Arrived():Destination=" $ string(Destination));
		ResumeState();
	}
Begin:
	if (DestinationNode != nullptr)
	{
		if (actorReachable(DestinationNode))
		{
			NextPath=DestinationNode;
		}
		else
		{
			NextPath=NavigationPoint(FindPathToward(DestinationNode));
		}
		MoveToward(NextPath);
		if (NextPath == DestinationNode)
		{
			Arrived(DestinationNode);
		}
	}
	Sleep(0);
	JL"DestNode"
;
}
*/

/*
State Patrolling extends Walking
{
	Event BeginState()
	{
		if ((DestinationNode == nullptr) && (PatrolPath != nullptr))
		{
			DestinationNode=PatrolPath.GetNode(Location,Pawn);
		}
		DebugLog(DEBUG_AI,"AGP_BOT:Patrolling:BeginState():DestinationNode =" $ string(DestinationNode));
		Super::BeginState();
	}
	Function Arrived(AActor* Destination)
	{
		ANavigationPoint* Dest = nullptr;
		Super::Arrived(Destination);
		DebugLog(DEBUG_AI,"AGP_BOT:Patrolling:Arrived():Destination=" $ string(Destination));
		Dest=NavigationPoint(Destination);
		if ((Dest != nullptr) && (PatrolPath != nullptr))
		{
			PatrolPath.Arrived(Dest,Pawn);
			DestinationNode=PatrolPath.GetNextNode(Dest,Pawn);
			DebugLog(DEBUG_AI,"AGP_BOT:Patrolling:Arrived():NextDestination=" $ string(DestinationNode));
		}
	}
}
*/

void PostBeginPlay()
{
}

void AAGP_Bot::Think()
{
	if (NextThought != nullptr)
	{
		if (NextThought->Preformed(this))
		{
			NextThought = NextThought->NextThought;
		}
	}
}

void AAGP_Bot::AddThought(UAI_Thought* Thought)
{
	UAI_Thought* Next = nullptr;
	for (Next = NextThought; Next != nullptr; Next = Next->NextThought)
	{
	}
	Thought->NextThought = NextThought;
	Next->NextThought = Thought;
}

void AAGP_Bot::PauseState(float Time, FName NewState, FName aNextState)
{
	//DebugLog(DEBUG_AI, "AGP_BOT:PauseState():State=" $ string(GetStateName()));
	//GotoState(NewState);
	this->NextState = aNextState;
	//DebugLog(DEBUG_AI, "AGP_BOT:PauseState():New State=\"" $ string(GetStateName()) $ "\"NodePause=" $ string(Time));
	if (Time > 0)
	{
		//SetCustomTimer(Time, false, "ResumeState");
	}
}

void AAGP_Bot::ResumeState()
{
	//DebugLog(DEBUG_AI, "AGP_BOT:ResumeState():NextState=" $ string(NextState));
	if (NextState == "None")
	{
		NextState = "Idle";
	}
	//GotoState(NextState);
	NextState = "None";
}

void AAGP_Bot::Arrived(AActor* aDestination)
{
}

void AAGP_Bot::NotifyJumpApex()
{
}