// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/AuthSecondaryFunctions/AuthSecondaryFunctions.h"

AAuthSecondaryFunctions::AAuthSecondaryFunctions()
{
	TimerResolution = 0.25;
}

FString AAuthSecondaryFunctions::AddStringField(FString InString, FString FieldData)
{
	/*
	if (InString ~= "")
	{
		return FieldData;
	}
	else
	{
		return InString + Chr(255) + FieldData;
	}
	*/
	return "FAKE";    //FAKE  /EliZ
}

FString AAuthSecondaryFunctions::ParseField(FString InString, FString &OutString)
{
	int32 iPos = 0;
	FString Temp = "";
	OutString = "";
	/*
	iPos = InStr(InString, Chr(255));
	if (iPos == -1)
	{
		return "";
	}
	else
	{
		Temp = Left(InString, iPos);
		OutString = Right(InString, Len(InString) - iPos - 1);
		return Temp;
	}
	*/
	return "FAKE";    //FAKE  /EliZ
}

void AAuthSecondaryFunctions::UnbuildAuthString(FString AuthString)
{
	FString sTemp1 = "";
	FString sTemp2 = "";
	FString sResult = "";
	sTemp1 = AuthString;
	/*
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

bool AAuthSecondaryFunctions::Start(FString SendString, FString ReceiveString)
{
	int32 iPos = 0;
	FString sTemp = "";
	FString string0 = "";
	FString string1 = "";
	/*
	if (SecondaryFunctionServerAddress ~= "" || Level.IsUnofficialServer())
	{
		return false;
	}
	Log(Self @ "AuthSecondaryFunctions::Start Parsing input string '" + SendString + "'");
	Log(Self @ "AuthSecondaryFunctions::Start Parsing output string '" + ReceiveString + "'");
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
	Log("FinalAuthDataString = '" + FinalAuthDataString + "'");
	AuthPropStage = 0;
	TimeSinceAsyncXaction = 0;
	SetTimer(TimerResolution, true);
	Resolve(SecondaryFunctionServerAddress);
	*/
	return true;
}

void AAuthSecondaryFunctions::Timer()
{
	bool ShouldSelfDestruct = false;
	TimeSinceAsyncXaction += TimerResolution;
	ShouldSelfDestruct = false;
	/*
	switch(AuthPropStage)
	{
			case 0:
				break;
			case 1:
				Log("Trying to bind " + AuthBackupServerAddress.Port + "...");
				if (BindPort(AuthBackupServerAddress.Port) != 0)
				{
					Log("Succeeded! Trying to open " + AuthBackupServerAddress.Addr + ":" + AuthBackupServerAddress.Port);
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
	//Log(Self @ "AuthSecondaryFunctions::Opened AuthPropStage=" + AuthPropStage);
	AuthPropStage += 1;
	TimeSinceAsyncXaction = 0;
}
void AAuthSecondaryFunctions::Closed()
{
	//Log(Self @ "AuthSecondaryFunctions::Closed AuthPropStage=" + AuthPropStage);
	AuthPropStage += 1;
	TimeSinceAsyncXaction = 0;
}
void AAuthSecondaryFunctions::Resolved(FIpAddr Addr)
{
	/*
	Log(Self @ "AuthSecondaryFunctions::Resolved Addr.Addr=" + Addr.Addr + " and Addr.Port=" + Addr.Port + " and AuthPropStage=" + AuthPropStage);
	if (Addr.Addr == 0)
	{
		SetTimer(0, false);
		Destroy();
		return;
	}
	AuthBackupServerAddress.Port = 20046;
	AuthBackupServerAddress.Addr = Addr.Addr;
	AuthPropStage += 1;
	TimeSinceAsyncXaction = 0;
	*/
}
void AAuthSecondaryFunctions::ResolveFailed()
{
	//Log(Self @ "AuthSecondaryFunctions::ResolveFailed ABORTING PROPAGATION!");
	//SetTimer(0, false);
	Destroy();
}
void AAuthSecondaryFunctions::Destroyed()
{
	if (IsConnected())
	{
		UE_LOG(LogTemp, Warning, TEXT("AuthSecondaryFunctions::Destroyed Performing HardClose() on currently open connection..."));
		HardClose(false);
	}
	Super::Destroyed();
}
