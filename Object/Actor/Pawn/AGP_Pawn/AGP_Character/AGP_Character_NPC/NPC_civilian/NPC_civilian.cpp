// All the original content belonged to the US Army

#include "NPC_civilian.h"

ANPC_civilian::ANPC_civilian() 
{
	NPC_DamageOn			= true;
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	AnimRate				= 1;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/CivilianM_B.CivilianM_B"), NULL, LOAD_None, NULL);
	bCollideActors			= false;
	LoadMesh();
}

/*
simulated State BusyProning
{
	simulated Function EndState()
	{
		FName IdleAnim = "";
		EndState();
		if (_AnimationMonitor == None)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				IdleAnim="PrnLg";
				break;
				case 22:
				case 18:
				IdleAnim="PrnBinocsUp";
				break;
				case 21:
				case 19:
				IdleAnim="PrnBinocsDn";
				break;
				case 68:
				case 70:
				IdleAnim="PrnCLUIdleUp";
				break;
				case 67:
				case 71:
				IdleAnim="PrnCLUIdleDwn";
				break;
				case 75:
				IdleAnim="PrnTubeIdle";
				break;
				case 25:
				case 29:
				IdleAnim="PrnRPG";
				break;
				case 33:
				IdleAnim="PrnAT4";
				break;
				case 39:
				IdleAnim="PrnSMIdle";
				break;
				case 12:
				case 9:
				default:
				IdleAnim="PrnNo";
				break;
			}
			if ((Controller != None) && Controller.IsInState("InjuredWaitingForHealing"))
			{
				IdleAnim=nmNPCIdleAnim;
			}
			LoopAnim(IdleAnim,1,0.05);
		}
	}
}
*/

/*
simulated State BusyCrouching
{
	simulated Function EndState()
	{
		FName IdleAnim = "";
		EndState();
		if (_AnimationMonitor == None)
		{
			switch(UpperBodyAnim)
			{
				case 2:
				IdleAnim="CrhLgFr";
				break;
				case 12:
				IdleAnim="CrhGnRdy";
				break;
				case 9:
				IdleAnim="CrhGnFr";
				break;
				case 68:
				case 70:
				IdleAnim="CrhCluIdleUp";
				break;
				case 67:
				case 71:
				IdleAnim="CrhCluIdleDwn";
				break;
				case 75:
				IdleAnim="CrhTubeIdle";
				break;
				case 22:
				case 18:
				IdleAnim="CrhBinocsUp";
				break;
				case 21:
				case 19:
				IdleAnim="CrhBinocsDn";
				break;
				case 25:
				case 29:
				IdleAnim="CrhRPG";
				break;
				case 33:
				IdleAnim="CrhAT4";
				break;
				case 39:
				IdleAnim="CrhSmIdle";
				break;
				default:
				IdleAnim="CrhNo";
				break;
			}
			if ((Controller != None) && Controller.IsInState("InjuredWaitingForHealing"))
			{
				IdleAnim=nmNPCIdleAnim;
			}
			if (AnimLoopAction != "None")
			{
				LoopAnim(AnimLoopAction,1,0.25);
			}
			else
			{
				LoopAnim(IdleAnim,1,0.25);
			}
		}
		bInProneTransition=false;
	}
}
*/
