// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/Mutator/AGP_Secure/AGP_Secure.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/Actor/Info/Security/AGP_Security/AGP_Checker/AGP_Checker.h"

AAGP_Secure::AAGP_Secure()
{

}

/*
auto State Working
{
	Function BeginState()
	{
		Disable("Tick");
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
	AController* C = nullptr;
	APlayerController* PC = nullptr;
	Super::Tick(Delta);

	/*
	for (C = Cast<AAA2_WorldSettings>(GetWorldSettings())->ControllerList; C != nullptr; C = C->nextController)
	{
		PC = Cast<APlayerController>(C);
		if (((PC != nullptr) && (PC.PlayerSecurity != nullptr)) && (Cast<AAGP_Checker>(PC.PlayerSecurity) == nullptr))
		{
			FixSecurity(PC);
			LoginCnt--;
		}
	}
	*/
	if (LoginCnt <= 0)
	{
		//Disable("Tick");
	}
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
	if (PC != nullptr)
	{
		if ((PC.PlayerSecurity == nullptr) || (Cast<AAGP_Checker>(PC.PlayerSecurity) == nullptr))
		{
			if (PC.PlayerSecurity != nullptr)
			{
				PC.PlayerSecurity.Destroy();
				PC.PlayerSecurity = nullptr;
			}
			PC.PlayerSecurity = Spawn(AAGP_Checker::StaticClass(), PC);
			if (PC.PlayerSecurity == nullptr)
			{
				Log("Could not secure " + PC.PlayerReplicationInfo.PlayerName);
			}
		}
	}
	*/
}
