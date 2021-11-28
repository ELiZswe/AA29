// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/Mutator/AGP_Secure/AGP_Secure.h"

AAGP_Secure::AAGP_Secure()
{

}


/*
auto State Working
{
	Function BeginState()
	{
		Disable('Tick');
		Super::BeginState();
	}
}
*/

void AAGP_Secure::PostBeginPlay()
{
	/*
	Log("============================================");
	Log(" AGP_Secure ");
	Log("============================================");
	Disable('Tick');
	Super::PostBeginPlay();
	*/
}

void AAGP_Secure::Tick(float Delta)
{
	/*
	local Controller C;
	local PlayerController PC;
	Super::Tick(Delta);
	C = Level.ControllerList;
	if (C != None)
	{
		PC = PlayerController(C);
		if (((PC != None) && (PC.PlayerSecurity != None)) && (AGP_Checker(PC.PlayerSecurity) == None))
		{
			FixSecurity(PC);
			(LoginCnt);
		}
		C = C.nextController;
	}
	if (LoginCnt <= 0)
	{
		Disable('Tick');
	}
	*/
}

void AAGP_Secure::ModifyLogin(FString& Portal, FString& Options)
{
	/*
	LoginCnt++;
	Enable('Tick');
	Super::ModifyLogin(Portal, Options);
	*/
}

void AAGP_Secure::FixSecurity(APlayerController* PC)
{
	/*
	if (PC != None)
	{
		if ((PC.PlayerSecurity == None) || (AGP_Checker(PC.PlayerSecurity) == None))
		{
			if (PC.PlayerSecurity != None)
			{
				PC.PlayerSecurity.Destroy();
				PC.PlayerSecurity = None;
			}
			PC.PlayerSecurity = Spawn(Class'AGP.AGP_Checker', PC);
			if (PC.PlayerSecurity == None)
			{
				Log("Could not secure " $ PC.PlayerReplicationInfo.PlayerName);
			}
		}
	}
	*/
}