// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/Security/AGP_Security/AGP_Checker/AGP_Checker.h"

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
		Disable("Timer");
		Super::BeginState();
	}
}
*/

/*
State CheckNext
{
	Function Timer()
	{
		Log("Player [" + PlayerController(GetOwner())->PlayerReplicationInfo.PlayerName + "] timed out while being tested.");
	}
Begin:
	SetTimer(float(TimeoutSeconds),false);
}
*/

/*
auto State StartUp
{
	Function Timer()
	{
		Index=0;
		if (Checks.Num() > 0)
		{
			Log("[Securing] " + PlayerController(GetOwner())->PlayerReplicationInfo.PlayerName);
			Log("Checking " + Checks[Index]);
			ClientPerform(MD5Type[Index],Checks[Index],"");
			GotoState("CheckNext");
		}
		else
		{
			Log("[Nothing to Secure] " + PlayerController(GetOwner())->PlayerReplicationInfo.PlayerName);
		}
	}
Begin:
	SetTimer(float(WaitSeconds),false);
}
*/

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
		Log("Player [" + PlayerController(GetOwner())->PlayerReplicationInfo.PlayerName + "] timed out while being tested.");
	}
}
State StartUp
{
	Function Timer()
	{
		Index = 0;
		if (Checks.Num() > 0)
		{
			Log("[Securing] " + PlayerController(GetOwner())->PlayerReplicationInfo.PlayerName);
			Log("Checking " + Checks[Index]);
			ClientPerform(MD5Type[Index],Checks[Index],"");
			GotoState('CheckNext');
		}
		else
		{
			Log("[Nothing to Secure] " + PlayerController(GetOwner())->PlayerReplicationInfo.PlayerName);
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
	APlayerController* PC = nullptr;
	FString st;
	int32 i = 0;
	i = InStr(S, "\");
		if (i >= 0)
		{
			st = Right(S, Len(S) - i - 1);
			S = st;
			i = InStr(S, "\");
		}
	ForEach AllActors(Class'PlayerController', PC)
	{
		if (PC.Player != nullptr)
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
	Log("ServerCallback(" + SecType + ", " + Data + ")");
	if (SecType == MD5Type[Index])
	{
		if (SecType == 4)
		{
			sResult = sResult + "3" + Chr(255) + Data + Chr(255);
			CheckContinue();
		}
		else
		{
			if (SecType == 5)
			{
				sResult = sResult + "2" + Chr(255) + Data + Chr(255);
				CheckContinue();
			}
			else
			{
				if (SecType == 6)
				{
					sResult = sResult + "4" + Chr(255) + Checks[Index] @ Data + Chr(255);
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
							Log("[INSECURE CLIENT]" @ PlayerController(GetOwner())->PlayerReplicationInfo.PlayerName + " has a modifed " + Checks[Index]);
							sResult = sResult + "1" + Chr(255) + Checks[Index] + Chr(255);
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
	if (Index == Checks.Num())
	{
		Log("Player " + PlayerController(GetOwner())->PlayerReplicationInfo.PlayerName + " has been secured");
		GotoState('Secure');
	}
	else
	{
		Log("Checking " + Checks[Index]);
		ClientPerform(MD5Type[Index], Checks[Index], "");
		GotoState('CheckNext');
	}
	*/
}
