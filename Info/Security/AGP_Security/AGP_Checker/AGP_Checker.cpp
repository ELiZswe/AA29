// All the original content belonged to the US Army


#include "AA29/Info/Security/AGP_Security/AGP_Checker/AGP_Checker.h"


AAGP_Checker::AAGP_Checker()
{
	TimeoutSeconds = 60;
	WaitSeconds = 60;
}


/*

State Secure
{
	Function BeginState()
	{
		Disable('Timer');
		BeginState();
	}
}
State CheckNext
{
	Function Timer()
	{
		Log("Player [" $ PlayerController(Owner).PlayerReplicationInfo.PlayerName $ "] timed out while being tested.");
	}
}
State StartUp
{
	Function Timer()
	{
		Index = 0;
		if (Checks.Length > 0)
		{
			Log("[Securing] " $ PlayerController(Owner).PlayerReplicationInfo.PlayerName);
			Log("Checking " $ Checks[Index]);
			ClientPerform(MD5Type[Index],Checks[Index],"");
			GotoState('CheckNext');
		}
		else
		{
			Log("[Nothing to Secure] " $ PlayerController(Owner).PlayerReplicationInfo.PlayerName);
		}
	}
}
*/

void AAGP_Checker::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
}
void AAGP_Checker::BadNews(FString S)
{
	/*
	local PlayerController PC;
	local string st;
	local int i;
	i = InStr(S, "\");
		if (i >= 0)
		{
			st = Right(S, Len(S) - i - 1);
			S = st;
			i = InStr(S, "\");
		}
	ForEach AllActors(Class'PlayerController', PC)
	{
		if (PC.Player != None)
		{
			GOTO JL007F;
		}
	JL007F:
	}
	*/
}
void AAGP_Checker::ServerCallback(int32 SecType, FString Data)
{
	/*
	Log("ServerCallback(" $ SecType $ ", " $ Data $ ")");
	if (SecType == MD5Type[Index])
	{
		if (SecType == 4)
		{
			sResult = sResult $ "3" $ Chr(255) $ Data $ Chr(255);
			CheckContinue();
		}
		else
		{
			if (SecType == 5)
			{
				sResult = sResult $ "2" $ Chr(255) $ Data $ Chr(255);
				CheckContinue();
			}
			else
			{
				if (SecType == 6)
				{
					sResult = sResult $ "4" $ Chr(255) $ Checks[Index] @ Data $ Chr(255);
					CheckContinue();
				}
				else
				{
					if (SecType == 2)
					{
						if (Data ~= MD5[Index])
						{
							CheckContinue();
						}
						else
						{
							Log("[INSECURE CLIENT]" @ PlayerController(Owner).PlayerReplicationInfo.PlayerName $ " has a modifed " $ Checks[Index]);
							sResult = sResult $ "1" $ Chr(255) $ Checks[Index] $ Chr(255);
							Disable('Timer');
						}
					}
				}
			}
		}
	}
	*/
}
void AAGP_Checker::CheckContinue()
{
	/*
	Index++;
	if (Index == Checks.Length)
	{
		Log("Player " $ PlayerController(Owner).PlayerReplicationInfo.PlayerName $ " has been secured");
		GotoState('Secure');
	}
	else
	{
		Log("Checking " $ Checks[Index]);
		ClientPerform(MD5Type[Index], Checks[Index], "");
		GotoState('CheckNext');
	}
	*/
}
