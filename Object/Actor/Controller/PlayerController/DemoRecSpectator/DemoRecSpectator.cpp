// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/DemoRecSpectator/DemoRecSpectator.h"

ADemoRecSpectator::ADemoRecSpectator()
{

}

/*
auto State Spectating
{
	exec Function Fire(float F)
	{
		bBehindView=false;
		DemoViewNextPlayer();
	}
	exec Function AltFire(float F)
	{
		bBehindView=(! bBehindView);
	}
	Event PlayerTick(float DeltaTime)
	{
		Super::PlayerTick(DeltaTime);
		if (((Role == 3) && ((RealViewTarget == None) || (RealViewTarget == Self))) && (! bFoundPlayer))
		{
			DemoViewNextPlayer();
			if ((RealViewTarget != None) && (RealViewTarget != Self))
			{
				bFoundPlayer=true;
			}
		}
		if ((RealViewTarget != None) && (RealViewTarget.Pawn == None))
		{
			if (! bBehindView)
			{
				if (! bTempBehindView)
				{
					bTempBehindView=true;
					bBehindView=true;
				}
			}
		}
		else
		{
			if (bTempBehindView)
			{
				bBehindView=false;
				bTempBehindView=false;
			}
		}
	}
}
*/
