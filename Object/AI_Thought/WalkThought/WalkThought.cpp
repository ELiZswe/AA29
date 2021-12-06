// All the original content belonged to the US Army

#include "AA29/Object/AI_Thought/WalkThought/WalkThought.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/Bot/AGP_Bot/AGP_Bot.h"

UWalkThought::UWalkThought()
{

}

bool UWalkThought::Preformed(AAGP_Bot* Bot)
{
	Bot->DestinationNode = Destination;
	//Bot->GotoState('Walking');
	return true;
}
