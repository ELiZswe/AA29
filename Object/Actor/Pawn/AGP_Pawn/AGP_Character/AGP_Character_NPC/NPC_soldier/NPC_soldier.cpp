// All the original content belonged to the US Army

#include "NPC_soldier.h"

ANPC_soldier::ANPC_soldier()
{
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	AnimRate				= 1;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/OpforM_InfantryB.OpforM_InfantryB"), NULL, LOAD_None, NULL);
	LoadMesh();
}

/*
simulated State BusyCrouching
{
	simulated Function EndState()
	{
		FName IdleAnim = "";
		Super::EndState();
		if (_AnimationMonitor == None)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				if (bIsFiringBlindlyOverHead)
				{
					IdleAnim="CrhFwUpBlndFrLoop";
					break;
				}
				if (bIsFiringBlindlyLeft)
				{
					IdleAnim="CrhFwLtBlndFrLoop";
					break;
				}
				IdleAnim="CrhLgFr";
			}
			case 12:
			IdleAnim="CrhGnRdy";
			case 9:
			IdleAnim="CrhGnFr";
			case 68:
			case 70:
			IdleAnim="CrhCluIdleUp";
			case 67:
			case 71:
			IdleAnim="CrhCluIdleDwn";
			case 75:
			IdleAnim="CrhTubeIdle";
			case 22:
			case 18:
			IdleAnim="CrhBinocsUp";
			case 21:
			case 19:
			IdleAnim="CrhBinocsDn";
			case 25:
			case 29:
			IdleAnim="CrhRPG";
			case 33:
			IdleAnim="CrhAT4";
			case 39:
			IdleAnim="CrhSmIdle";
			default:
			if (bIsFiringBlindlyOverHead)
			{
				IdleAnim="CrhFwUpBlndFrLoop";
			}
			else
			{
				if (bIsFiringBlindlyLeft)
				{
					IdleAnim="CrhFwLtBlndFrLoop";
				}
				else
				{
					if (bIsFiringBlindlyRight)
					{
						IdleAnim="CrhFwRtBlndFrLoop";
					}
					else
					{
						IdleAnim="CrhNo";
					}
				}
			}
			LoopAnim(IdleAnim,1,0.25);
		}
	}
}
*/

/*
simulated State BusyStanding
{
	simulated Function EndState()
	{
		FName IdleAnim = "";
		if (Level.debugPawnState)
		{
			DebugLog(DEBUG_Anim,string(Self) @ "AGP_Pawn::EndState - in state" @ string(GetStateName()));
		}
		Super::EndState();
		if (_AnimationMonitor == None)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				if (bIsFiringBlindlyLeft)
				{
					IdleAnim="StndLtBlndFr";
					break;
				}
				if (bIsFiringBlindlyRight)
				{
					IdleAnim="StndRtBlndFr";
					break;
				}
				if (bIsHipShooting)
				{
					IdleAnim="HipStdLgFr";
					break;
				}
				IdleAnim="StdLgFr";
			}
			case 12:
			IdleAnim="StdGnRdy";
			case 9:
			IdleAnim="StdGnFr";
			case 68:
			case 70:
			IdleAnim="StdCluUp";
			case 67:
			case 71:
			IdleAnim="StdCluDn";
			case 22:
			case 18:
			IdleAnim="StdBinocsUp";
			case 21:
			case 19:
			IdleAnim="StdBinocsDn";
			case 33:
			IdleAnim="StdAT4";
			case 25:
			case 29:
			IdleAnim="StdRPG";
			case 39:
			IdleAnim="StdSmIdle";
			default:
			if (bIsFiringBlindlyLeft)
			{
				IdleAnim="StndLtBlndFr";
			}
			else
			{
				if (bIsFiringBlindlyRight)
				{
					IdleAnim="StndRtBlndFr";
				}
				else
				{
					if (bIsHipShooting)
					{
						IdleAnim="HipStdLgFr";
					}
					else
					{
						IdleAnim="StdNo";
					}
				}
			}
			LoopAnim(IdleAnim,1,0.25);
		}
	}
}
*/
