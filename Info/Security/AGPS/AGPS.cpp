// All the original content belonged to the US Army


#include "AA29/Info/Security/AGPS/AGPS.h"

AAGPS::AAGPS()
{

}




/*
State StartUp
{
	Function BeginState()
	{
		local int iPackage;
		local int iMapsAndCodeToTest;
		local array<String> asMapAndCodePackagesToTest;
		local array<String> asResult;
		if (Level.NetMode == 1 && AGP_GameInfo(Level.Game).IsRequireAuthorization())
		{
			HumanController(Owner).ClientMessage("Validating your installation, please wait...");
			DebugLog(DEBUG_Security,"AGPS.StartUp.BeginState() entered - getting all server packages");
			LocalPerform(300,"","",asMapAndCodePackagesToTest);
			DebugLog(DEBUG_Security,"AGPS.StartUp.BeginState() server packages: " $ asMapAndCodePackagesToTest.Length);
			iMapsAndCodeToTest = 0;
			for (iPackage = 0; iPackage < asMapAndCodePackagesToTest.Length; iPackage++)
			{
				if (Len(asMapAndCodePackagesToTest[iPackage]) > 4 && Right(asMapAndCodePackagesToTest[iPackage],4) ~= ".aao" && AGP_GameInfo(Level.Game).bEnableMapTesting || Right(asMapAndCodePackagesToTest[iPackage],2) ~= ".u" && AGP_GameInfo(Level.Game).bEnableCodeTesting)
				{
					asPackagesToTest[iMapsAndCodeToTest] = asMapAndCodePackagesToTest[iPackage];
					LocalPerform(2,asPackagesToTest[iMapsAndCodeToTest],"",asResult);
					asLocalPackageMD5s[iMapsAndCodeToTest] = asResult[0];
					DebugLog(DEBUG_Security,"AGPS.StartUp.BeginState() Will test " $ asPackagesToTest[iMapsAndCodeToTest] $ " is " $ asLocalPackageMD5s[iMapsAndCodeToTest]);
					iMapsAndCodeToTest++;
				}
			}
			iEntryBeingTested = 0;
			ClientPerform(2,asPackagesToTest[iEntryBeingTested],"");
			DebugLog(DEBUG_Security,"AGPS.StartUp.BeginState() exiting");
		}
	}
}
State TerminationWarning
{
	Function Timer()
	{
		DebugLog(DEBUG_Security,"AGPS.TerminationWarning.Timer() entered");
		if (HumanController(Owner).PlayerReplicationInfo != None)
		{
			DebugLog(DEBUG_Security,"AGPS.TerminationWarning.Timer() Good PRI for player, warning them");
			HumanController(Owner).NotifyAdminMessage("Your installation appears to be damaged.|Please run Cleaner.exe to repair it.");
			GotoState('Terminating');
		}
	}
	Function BeginState()
	{
		DebugLog(DEBUG_Security,"AGPS.TerminationWarning.BeginState() entered");
		SetTimer(1,True);
	}
}

State Terminating
{
	Function Timer()
	{
		if (HumanController(Owner).PlayerReplicationInfo != None)
		{
			DebugLog(DEBUG_Security,"AGPS.Terminating.Timer() entered, destroying client now.");
			Owner.Destroy();
			Destroy();
			GotoState('None');
		}
	}
	Function BeginState()
	{
		DebugLog(DEBUG_Security,"AGPS.Terminating.BeginState() entered");
		SetTimer(20,False);
	}
}
*/
void AAGPS::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	DebugLog(DEBUG_Security, "AGPS.PostBeginPlay entered");
	if (Level.NetMode == 1 && AGP_GameInfo(Level.Game).IsRequireAuthorization())
	{
		if (AGP_GameInfo(Level.Game).bEnableMapTesting)
		{
			Log("Map Testing Enabled");
		}
		else
		{
			Log("Map Testing Disabled");
		}
		if (AGP_GameInfo(Level.Game).bEnableCodeTesting)
		{
			Log("Code Testing Enabled");
		}
		else
		{
			Log("Code Testing Disabled");
		}
	}
	*/
}

void AAGPS::ServerCallback(int32 iSecType, FString sData)
{
	/*
	Switch(iSecType)
	{
			case 2:
				DebugLog(DEBUG_Security, "Quick MD5 value package " $ asPackagesToTest[iEntryBeingTested] $ ": " $ sData);
				DebugLog(DEBUG_Security, "Local MD5: " $ asLocalPackageMD5s[iEntryBeingTested]);
				if (asLocalPackageMD5s[iEntryBeingTested] ~= sData)
				{
					DebugLog(DEBUG_Security, "Good file for " $ asPackagesToTest[iEntryBeingTested]);
					break;
				}
				DebugLog(DEBUG_Security, "MD5's for file " $ asPackagesToTest[iEntryBeingTested] $ " do not match.");
				Log("File " $ asPackagesToTest[iEntryBeingTested] $ " is not valid.");
				ReportFailure();
				GOTO JL01B6;
	}
	if (iEntryBeingTested < asPackagesToTest.Length - 1)
	{
		iEntryBeingTested++;
		ClientPerform(2, asPackagesToTest[iEntryBeingTested], "");
	}
	else
	{
		DebugLog(DEBUG_Security, "All packages processed");
		SetTimer(0, False);
		GotoState('None');
	}
	GOTO JL01B6;
		case 255:
			DebugLog(DEBUG_Security, "Bad package, signalling failure" $ sData);
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
