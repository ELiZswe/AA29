// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/Security/AGPS/AGPS.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "Kismet/GameplayStatics.h"

AAGPS::AAGPS()
{

}

/*
auto State StartUp
{
	Function BeginState()
	{
		int32 iPackage = 0;
		int32 iMapsAndCodeToTest = 0;
		TArray<FString> asMapAndCodePackagesToTest = {};
		TArray<FString> asResult = {};
		if ((GetWorld()->GetNetMode() == NM_DedicatedServer) && Cast<AAGP_GameInfo>(GetGameMode()).IsRequireAuthorization())
		{
			Cast<AHumanController>(GetOwner())->ClientMessage("Validating your installation, please wait...");
			DebugLog(DEBUG_Security,"AGPS.StartUp.BeginState() entered - getting all server packages");
			LocalPerform(300,"","",asMapAndCodePackagesToTest);
			DebugLog(DEBUG_Security,"AGPS.StartUp.BeginState() server packages: " + FString::FromInt(asMapAndCodePackagesToTest.Num()));
			iMapsAndCodeToTest=0;
			for (iPackage=0; iPackage<asMapAndCodePackagesToTest.Num(); iPackage++)
			{
				if ((Len(asMapAndCodePackagesToTest[iPackage]) > 4) && (((Right(asMapAndCodePackagesToTest[iPackage],4) ~= ".aao") && Cast<AAGP_GameInfo>(GetGameMode()).bEnableMapTesting) || ((Right(asMapAndCodePackagesToTest[iPackage],2) ~= ".u") && Cast<AAGP_GameInfo>(GetGameMode()).bEnableCodeTesting)))
				{
					asPackagesToTest[iMapsAndCodeToTest]=asMapAndCodePackagesToTest[iPackage];
					LocalPerform(2,asPackagesToTest[iMapsAndCodeToTest],"",asResult);
					asLocalPackageMD5s[iMapsAndCodeToTest]=asResult[0];
					DebugLog(DEBUG_Security,"AGPS.StartUp.BeginState() Will test " + asPackagesToTest[iMapsAndCodeToTest] + " is " + asLocalPackageMD5s[iMapsAndCodeToTest]);
					iMapsAndCodeToTest ++;
				}
			}
			iEntryBeingTested=0;
			ClientPerform(2,asPackagesToTest[iEntryBeingTested],"");
			DebugLog(DEBUG_Security,"AGPS.StartUp.BeginState() exiting");
		}
	}
}
*/

/*
State TerminationWarning
{
	Function BeginState()
	{
		DebugLog(DEBUG_Security,"AGPS.TerminationWarning.BeginState() entered");
		SetTimer(1,true);
	}
	Function Timer()
	{
		DebugLog(DEBUG_Security,"AGPS.TerminationWarning.Timer() entered");
		if (Cast<AHumanController>(GetOwner())->PlayerReplicationInfo != nullptr)
		{
			DebugLog(DEBUG_Security,"AGPS.TerminationWarning.Timer() Good PRI for player, warning them");
			Cast<AHumanController>(GetOwner())->NotifyAdminMessage("Your installation appears to be damaged.|Please run Cleaner.exe to repair it.");
			GotoState("Terminating");
		}
	}
}
*/

/*
State Terminating
{
	Function BeginState()
	{
		DebugLog(DEBUG_Security,"AGPS.Terminating.BeginState() entered");
		SetTimer(20,false);
	}
	Function Timer()
	{
		if (Cast<AHumanController>(GetOwner())->PlayerReplicationInfo != nullptr)
		{
			DebugLog(DEBUG_Security,"AGPS.Terminating.Timer() entered, destroying client now.");
			Owner.Destroy();
			Destroy();
			GotoState("None");
		}
	}
}
*/

void AAGPS::PostBeginPlay()
{
	//Super::PostBeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AGPS.PostBeginPlay entered"));
	if (GetNetMode() == ENetMode::NM_DedicatedServer && Cast<AAGP_GameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->IsRequireAuthorization())
	{
		if (Cast<AAGP_GameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->bEnableMapTesting)
		{
			UE_LOG(LogTemp, Log, TEXT("Map Testing Enabled"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Map Testing Disabled"));
		}
		if (Cast<AAGP_GameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->bEnableCodeTesting)
		{
			UE_LOG(LogTemp, Log, TEXT("Code Testing Enabled"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Code Testing Disabled"));
		}
	}
}

void AAGPS::ServerCallback(int32 iSecType, FString sData)
{
	/*
	switch(iSecType)
	{
			case 2:
				DebugLog(DEBUG_Security, "Quick MD5 value package " + asPackagesToTest[iEntryBeingTested] + ": " + sData);
				DebugLog(DEBUG_Security, "Local MD5: " + asLocalPackageMD5s[iEntryBeingTested]);
				if (asLocalPackageMD5s[iEntryBeingTested] ~= sData)
				{
					DebugLog(DEBUG_Security, "Good file for " + asPackagesToTest[iEntryBeingTested]);
					break;
				}
				DebugLog(DEBUG_Security, "MD5's for file " + asPackagesToTest[iEntryBeingTested] + " do not match.");
				Log("File " + asPackagesToTest[iEntryBeingTested] + " is not valid.");
				ReportFailure();
				GOTO JL01B6;
	}
	if (iEntryBeingTested < asPackagesToTest.Num() - 1)
	{
		iEntryBeingTested++;
		ClientPerform(2, asPackagesToTest[iEntryBeingTested], "");
	}
	else
	{
		DebugLog(DEBUG_Security, "All packages processed");
		SetTimer(0, false);
		GotoState("None");
	}
	GOTO JL01B6;
		case 255:
			DebugLog(DEBUG_Security, "Bad package, signalling failure" + sData);
			ReportFailure();
			GOTO JL01B6;
		default:
			
		JL01B6:
	*/
}
void AAGPS::ReportFailure()
{
	//GotoState('TerminationWarning');
}
