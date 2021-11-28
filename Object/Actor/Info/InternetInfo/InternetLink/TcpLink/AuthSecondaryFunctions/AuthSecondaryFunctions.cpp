// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/AuthSecondaryFunctions/AuthSecondaryFunctions.h"

AAuthSecondaryFunctions::AAuthSecondaryFunctions()
{
	TimerResolution = 0.25;
}



void AAuthSecondaryFunctions::AddStringField(FString InString, FString FieldData)
{
	/*
	if (InString ~= "")
	{
		Return FieldData;
	}
	else
	{
		Return InString $ Chr(255) $ FieldData;
	}
	*/
}
void AAuthSecondaryFunctions::ParseField(FString InString, FString &OutString)
{
	/*
	local int iPos;
	local string Temp;
	OutString = "";
	iPos = InStr(InString, Chr(255));
	if (iPos == -1)
	{
		Return "";
	}
	else
	{
		Temp = Left(InString, iPos);
		OutString = Right(InString, Len(InString) - iPos - 1);
		Return Temp;
	}
	*/
}
void AAuthSecondaryFunctions::UnbuildAuthString(FString AuthString)
{
	/*
	local string sTemp1;
	local string sTemp2;
	local string sResult;
	sTemp1 = AuthString;
	sResult = ParseField(sTemp1, sTemp2);
	sResult = ParseField(sTemp2, sTemp1);
	sResult = ParseField(sTemp1, sTemp2);
	sResult = ParseField(sTemp2, sTemp1);
	sUserName = sResult;
	sResult = ParseField(sTemp1, sTemp2);
	sEncryptedPassword = sResult;
	sResult = ParseField(sTemp2, sTemp1);
	sIPAddress = sResult;
	*/
}
void AAuthSecondaryFunctions::Start(FString SendString, FString ReceiveString)
{
	/*
	local int iPos;
	local string sTemp;
	local string string0;
	local string string1;
	if (SecondaryFunctionServerAddress ~= "" || Level.IsUnofficialServer())
	{
		Return False;
	}
	Log(Self @ "AuthSecondaryFunctions::Start Parsing input string '" $ SendString $ "'");
	Log(Self @ "AuthSecondaryFunctions::Start Parsing output string '" $ ReceiveString $ "'");
	UnbuildAuthString(SendString);
	FinalAuthDataString = "";
	FinalAuthDataString = AddStringField(FinalAuthDataString, sUserName);
	FinalAuthDataString = AddStringField(FinalAuthDataString, sEncryptedPassword);
	FinalAuthDataString = AddStringField(FinalAuthDataString, sIPAddress);
	sTemp = ReceiveString;
	iPos = InStr(sTemp, ",");
	if (iPos != -1)
	{
		string0 = Left(sTemp, iPos);
		string1 = Right(sTemp, Len(sTemp) - iPos - 1);
		FinalAuthDataString = AddStringField(FinalAuthDataString, string0);
		sTemp = string1;
		iPos = InStr(sTemp, ",");
	}
	FinalAuthDataString = AddStringField(FinalAuthDataString, sTemp);
	Log("FinalAuthDataString = '" $ FinalAuthDataString $ "'");
	AuthPropStage = 0;
	TimeSinceAsyncXaction = 0;
	SetTimer(TimerResolution, true);
	Resolve(SecondaryFunctionServerAddress);
	Return True;
	*/
}
void AAuthSecondaryFunctions::Timer()
{
	/*
	local bool ShouldSelfDestruct;
	TimeSinceAsyncXaction += TimerResolution;
	ShouldSelfDestruct = False;
	Switch(AuthPropStage)
	{
			case 0:
				break;
			case 1:
				Log("Trying to bind " $ AuthBackupServerAddress.Port $ "...");
				if (BindPort(AuthBackupServerAddress.Port) != 0)
				{
					Log("Succeeded! Trying to open " $ AuthBackupServerAddress.Addr $ ":" $ AuthBackupServerAddress.Port);
					if (Open(AuthBackupServerAddress))
					{
						TimeSinceAsyncXaction = 0;
						AuthPropStage += 1;
					}
				}
				if (AuthPropStage == 1)
				{
					ShouldSelfDestruct = true;
				}
				break;
			case 2:
				break;
			case 3:
				SendText(FinalAuthDataString);
				Close();
				AuthPropStage += 1;
				TimeSinceAsyncXaction = 0;
				break;
			case 4:
				break;
			case 5:
				ShouldSelfDestruct = true;
				break;
			default:
	}
	if (ShouldSelfDestruct || TimeSinceAsyncXaction > TimerResolution * 10)
	{
		SetTimer(0, false);
		Destroy();
	}
	*/
}
void AAuthSecondaryFunctions::Opened()
{
	/*
	Log(Self @ "AuthSecondaryFunctions::Opened AuthPropStage=" $ AuthPropStage);
	AuthPropStage += 1;
	TimeSinceAsyncXaction = 0;
	*/
}
void AAuthSecondaryFunctions::Closed()
{
	/*
	Log(Self @ "AuthSecondaryFunctions::Closed AuthPropStage=" $ AuthPropStage);
	AuthPropStage += 1;
	TimeSinceAsyncXaction = 0;
	*/
}
void AAuthSecondaryFunctions::Resolved(FIpAddr Addr)
{
	/*
	Log(Self @ "AuthSecondaryFunctions::Resolved Addr.Addr=" $ Addr.Addr $ " and Addr.Port=" $ Addr.Port $ " and AuthPropStage=" $ AuthPropStage);
	if (Addr.Addr == 0)
	{
		SetTimer(0, false);
		Destroy();
		Return;
	}
	AuthBackupServerAddress.Port = 20046;
	AuthBackupServerAddress.Addr = Addr.Addr;
	AuthPropStage += 1;
	TimeSinceAsyncXaction = 0;
	*/
}
void AAuthSecondaryFunctions::ResolveFailed()
{
	/*
	Log(Self @ "AuthSecondaryFunctions::ResolveFailed ABORTING PROPAGATION!");
	SetTimer(0, false);
	Destroy();
	*/
}
void AAuthSecondaryFunctions::Destroyed()
{
	//if (IsConnected())
	//{
	//UE_LOG(LogTemp, Warning, TEXT("AuthSecondaryFunctions::Destroyed Performing HardClose() on currently open connection..."));
	//	HardClose();
	//}
	Super::Destroyed();
}
