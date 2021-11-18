// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyStructs.h"
#include "AA29/AA29.h"
#include "DBMBS.generated.h"

class AMBSUpdateServerStateRequestAdapt;

UCLASS()
class AA29_API ADBMBS : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY()						bool bLoggedIn;										//var transient bool bLoggedIn;
	UPROPERTY()						int32 PingTimeToMBSServer;							//var int PingTimeToMBSServer;
	UPROPERTY()						bool InitialPingComplete;							//var bool InitialPingComplete;
	UPROPERTY()						int32 TimesTimerOccured;							//var int TimesTimerOccured;
	UPROPERTY()						Fpointer ServerDescription;							//var const transient pointer ServerDescription;
	UPROPERTY()						Fpointer MBSSDK;									//var const transient pointer MBSSDK;
	UPROPERTY()						FString ServerIP;									//var string ServerIP;
	UPROPERTY(Config)				int32 QueryPort;									//var config int QueryPort;

public:	
	// Sets default values for this actor's properties
	ADBMBS();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	void InitMBS();
	void DeinitMBS();
	void UpdateServerDescription();
	void UpdateMBSGameLoopTickCalculator();
	void GetOperatingSystem();
	void GetServerPort();
	void GetMaxPlayers();
	void GetNumPlayers();
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

};
