// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ZoneInfo/WarpZoneInfo/WarpZoneInfo.h"

AWarpZoneInfo::AWarpZoneInfo()
{

}

/*
State DelayedWarp
{
	Function Tick(float DeltaTime)
	{
		local Controller p;
		bool bFound = false;
		p=Level.ControllerList;
		if (p != None)
		{
			if (p.Pawn.bWarping && (p.Pawn.Region.Zone == Self))
			{
				bFound=true;
				ActorEntered(p);
			}
			p=p.nextController;
		}
		if (! bFound)
		{
			GotoState("None");
		}
	}
}
*/
