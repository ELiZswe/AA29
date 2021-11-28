// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"
#include "AuthSecondaryFunctions.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAuthSecondaryFunctions : public ATcpLink
{
	GENERATED_BODY()
public:
	AAuthSecondaryFunctions();

	UPROPERTY()					FIpAddr AuthBackupServerAddress;				//var InternetLink.IpAddr AuthBackupServerAddress;
	UPROPERTY(globalconfig)		FString SecondaryFunctionServerAddress;			//var globalconfig string SecondaryFunctionServerAddress;
	UPROPERTY()					float TimerResolution;							//var float TimerResolution;
	UPROPERTY()					float TimeSinceAsyncXaction;					//var float TimeSinceAsyncXaction;
	UPROPERTY()					FString FinalAuthDataString;					//var string FinalAuthDataString;
	UPROPERTY()					FString sIPAddress;								//var string sIPAddress;
	UPROPERTY()					FString sEncryptedPassword;						//var string sEncryptedPassword;
	UPROPERTY()					FString sUserName;								//var string sUserName;
	UPROPERTY()					int32 AuthPropStage;							//var int AuthPropStage;



	void AddStringField(FString InString, FString FieldData);
	void ParseField(FString InString, FString& OutString);
	void UnbuildAuthString(FString AuthString);
	void Start(FString SendString, FString ReceiveString);
	void Timer();
	void Opened();
	void Closed();
	void Resolved(FIpAddr Addr);
	void ResolveFailed();
	void Destroyed();

};
