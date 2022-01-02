// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "DBMBS.generated.h"

class AMBSUpdateServerStateRequestAdapt;

UCLASS(Config = Game)
class ADBMBS : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADBMBS();

	UPROPERTY()						bool		bLoggedIn;						//var transient bool bLoggedIn;
	UPROPERTY()						int32		PingTimeToMBSServer;			//var int PingTimeToMBSServer;
	UPROPERTY()						bool		InitialPingComplete;			//var bool InitialPingComplete;
	UPROPERTY()						int32		TimesTimerOccured;				//var int TimesTimerOccured;
	UPROPERTY()						Fpointer	ServerDescription;				//var const transient pointer ServerDescription;
	UPROPERTY()						Fpointer	MBSSDK;							//var const transient pointer MBSSDK;
	UPROPERTY()						FString		ServerIP;						//var string ServerIP;
	UPROPERTY(Config)				int32		QueryPort;						//var config int QueryPort;

	bool InitMBS();
	void DeinitMBS();
	void UpdateServerDescription();
	void UpdateMBSGameLoopTickCalculator();
	FString GetOperatingSystem();
	int32 GetServerPort();
	int32 GetMaxPlayers();
	int32 GetNumPlayers();
	void Tick(float DeltaTime);
	void HandleLegacyQueryPort();
	void PostBeginPlay();
	void Login();
	void Destroyed();
	void Timer();
	void GetPlayerAttributes(TArray<FKeyValuePair>& Attributes, APlayerController* C);
	void AddPlayers(AMBSUpdateServerStateRequestAdapt* Adapter);
	void AddAttribute(TArray<FKeyValuePair>& Attributes, FString Key, FString Value);
	FString EscapeColorCodes(FString S);
	FString UnescapeColorCodes(FString S);
	void GetServerAttributes(TArray<FKeyValuePair>& ServerAttributes);
	FString BoolToIntString(bool Value);
	void SendStateToMBS();
	void PingMBSServer();
	int32 CalculateAveragePlayerPing();
	int32 GetPingTimeToReport();
	void SetPingTime(int32 Ping);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
