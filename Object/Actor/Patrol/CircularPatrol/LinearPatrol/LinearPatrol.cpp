// All the original content belonged to the US Army

#include "AA29/Object/Actor/Patrol/CircularPatrol/LinearPatrol/LinearPatrol.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"

ALinearPatrol::ALinearPatrol()
{

}

ANavigationPoint* ALinearPatrol::GetNextNode(ANavigationPoint* CurrentNode, APawn* Bot)
{
	/*
	int32 i = 0;
	Log("Patrol:GetNextNode()");
	if (PatrolNodes.Num() == 0)
	{
		return nullptr;
	}
	for (i = 0; i < PatrolNodes.Num(); i++)
	{
		if (PatrolNodes[i] == CurrentNode)
		{
			if (bBackNodes)
			{
				i--;
			}
			else
			{
				i++;
			}
			if (i == (PatrolNodes.Num() - 1))
			{
				bBackNodes = true;
			}
			else
			{
				if (i == 0)
				{
					bBackNodes = false;
				}
			}
			return PatrolNodes[i];
		}
	}
	*/

	return nullptr;    //FAKE   /ELiZ
}
