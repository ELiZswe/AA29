// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/AIController/ScriptedController/Bot/AGP_Bot/AGP_Bot.h"

AAGP_Bot::AAGP_Bot()
{

}
/*
State Idle
{
}

State Walking extends Idle
{
	Event BeginState()
	{
		if (DestinationNode == None)
		{
			GotoState('Idle');
		}
		DebugLog(DEBUG_AI,"AGP_BOT:Walking:BeginState():DestinationNode =" $ string(DestinationNode));
		GotoState(GetStateName(),'DestNode');
	}
	Function Arrived(Actor Destination)
	{
		Super::Arrived(Destination);
		DebugLog(DEBUG_AI,"AGP_BOT:Walking:Arrived():Destination=" $ string(Destination));
		ResumeState();
	}
Begin:
	if (DestinationNode != None)
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
	JL'DestNode'
;
}

State Patrolling extends Walking
{
	Event BeginState()
	{
		if ((DestinationNode == None) && (PatrolPath != None))
		{
			DestinationNode=PatrolPath.GetNode(Location,Pawn);
		}
		DebugLog(DEBUG_AI,"AGP_BOT:Patrolling:BeginState():DestinationNode =" $ string(DestinationNode));
		Super::BeginState();
	}
	Function Arrived(Actor Destination)
	{
		local NavigationPoint Dest;
		Super::Arrived(Destination);
		DebugLog(DEBUG_AI,"AGP_BOT:Patrolling:Arrived():Destination=" $ string(Destination));
		Dest=NavigationPoint(Destination);
		if ((Dest != None) && (PatrolPath != None))
		{
			PatrolPath.Arrived(Dest,Pawn);
			DestinationNode=PatrolPath.GetNextNode(Dest,Pawn);
			DebugLog(DEBUG_AI,"AGP_BOT:Patrolling:Arrived():NextDestination=" $ string(DestinationNode));
		}
	}
}
*/

void AAGP_Bot::Arrived(AActor* Destination)
{
	/*
	if (State Walking)
	{
		Arrived(Destination);
		UE_LOG(LogTemp, Warning, TEXT("AGP_BOT:Walking:Arrived():Destination=" $ Destination));
		ResumeState();
	}
	if (State Patrolling)
	{
		local NavigationPoint Dest;
		Arrived(Destination);
		UE_LOG(LogTemp, Warning, TEXT("AGP_BOT:Patrolling:Arrived():Destination=" $ Destination));
		Dest = NavigationPoint(Destination);
		if (Dest != None && PatrolPath != None)
		{
			PatrolPath.Arrived(Dest, Pawn);
			DestinationNode = PatrolPath.GetNextNode(Dest, Pawn);
			UE_LOG(LogTemp, Warning, TEXT("AGP_BOT:Patrolling:Arrived():NextDestination=" $ DestinationNode));
		}
	}
	*/
}

void AAGP_Bot::BeginState()
{
	/*
	if (State Walking)
	{
		if (DestinationNode == None)
		{
			GotoState('Idle');
		}
		UE_LOG(LogTemp, Warning, TEXT("AGP_BOT:Walking:BeginState():DestinationNode =" $ DestinationNode));
		GotoState(GetStateName(),'DestNode');
	}
	if (State Patrolling)
	{
		if (DestinationNode == None && PatrolPath != None)
		{
			DestinationNode = PatrolPath.GetNode(Location, Pawn);
		}
		UE_LOG(LogTemp, Warning, TEXT("AGP_BOT:Patrolling:BeginState():DestinationNode =" $ DestinationNode));
		Super::BeginState();
	}
	*/
}

void AAGP_Bot::PostBeginPlay()
{
}
void AAGP_Bot::Think()
{
	/*
	if (NextThought != None)
	{
		if (NextThought.Preformed(Self))
		{
			NextThought = NextThought.NextThought;
		}
	}
	*/
}
void AAGP_Bot::AddThought(UAI_Thought* Thought)
{
	/*
	local AI_Thought Next;
	Next = NextThought;
	if (Next != None)
	{
		Next = Next.NextThought;
	}
	Thought.NextThought = NextThought;
	Next.NextThought = Thought;
	*/
}

void AAGP_Bot::PauseState(float Time, FName NewState, FName aNextState)
{
	/*
	UE_LOG(LogTemp, Warning, TEXT("AGP_BOT:PauseState():State=" $ GetStateName()));
	GotoState(NewState);
	Self.NextState = NextState;
	UE_LOG(LogTemp, Warning, TEXT("AGP_BOT:PauseState():New State=""" $ GetStateName() $ """NodePause=" $ Time));
	if (Time > 0)
	{
		SetCustomTimer(Time, False, 'ResumeState');
	}
	*/
}

void AAGP_Bot::ResumeState()
{
	/*
	UE_LOG(LogTemp, Warning, TEXT("AGP_BOT:ResumeState():NextState=" $ NextState));
	if (NextState == 'None')
	{
		NextState = 'Idle';
	}
	GotoState(NextState);
	NextState = 'None';
	*/
}
void AAGP_Bot::NotifyJumpApex()
{
}
