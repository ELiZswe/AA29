// All the original content belonged to the US Army


#include "AA29/Object/Actor/Patrol/CircularPatrol/LinearPatrol/LinearPatrol.h"

ALinearPatrol::ALinearPatrol()
{

}

ANavigationPoint* ALinearPatrol::GetNextNode(ANavigationPoint* CurrentNode, APawn* Bot)
{
	/*
	int32 i = 0;
	Log("Patrol:GetNextNode()");
	if (PatrolNodes.Length == 0)
	{
		return None;
	}
	for (i = 0; i < PatrolNodes.Length; i++)
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
			if (i == (PatrolNodes.Length - 1))
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
