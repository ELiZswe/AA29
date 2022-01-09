// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CallForSupport.generated.h"

UCLASS()
class ACallForSupport : public AActor
{
	GENERATED_BODY()

public:
	
	ACallForSupport();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()										int32				InitialStrikesAvailable;			//var int InitialStrikesAvailable;
	UPROPERTY()										APlayerController*	Caller;								//var PlayerController Caller;
	UPROPERTY()										bool				bFiring;							//var bool bFiring;
	UPROPERTY()										bool				bReady;								//var bool bReady;
	UPROPERTY()										bool				bAvailable;							//var bool bAvailable;
	UPROPERTY(EditAnywhere)		USoundBase*			SquadLeaderEnemyEliminatedSound;	//var() Sound SquadLeaderEnemyEliminatedSound;
	UPROPERTY(EditAnywhere)		USoundBase*			SquadLeaderEnemyDownSound;			//var() Sound SquadLeaderEnemyDownSound;
	UPROPERTY(EditAnywhere)		USoundBase*			SquadLeaderEnemySpottedSound;		//var() Sound SquadLeaderEnemySpottedSound;
	UPROPERTY(EditAnywhere)		USoundBase*			SquadLeaderTakeCoverSound;			//var() Sound SquadLeaderTakeCoverSound;
	UPROPERTY(EditAnywhere)		USoundBase*			SquadLeaderCoverMeSound;			//var() Sound SquadLeaderCoverMeSound;
	UPROPERTY(EditAnywhere)		USoundBase*			SquadLeaderAreaSecureSound;			//var() Sound SquadLeaderAreaSecureSound;
	UPROPERTY(EditAnywhere)		USoundBase*			SquadLeaderRogerSound;				//var() Sound SquadLeaderRogerSound;
	UPROPERTY(EditAnywhere)		USoundBase*			SquadLeaderHooahSound;				//var() Sound SquadLeaderHooahSound;
	UPROPERTY(EditAnywhere)		USoundBase*			EnemyDownSound;						//var() Sound EnemyDownSound;
	UPROPERTY(EditAnywhere)		USoundBase*			EnemySpottedSound;					//var() Sound EnemySpottedSound;
	UPROPERTY(EditAnywhere)		USoundBase*			TakeCoverSound;						//var() Sound TakeCoverSound;
	UPROPERTY(EditAnywhere)		USoundBase*			CoverMeSound;						//var() Sound CoverMeSound;
	UPROPERTY(EditAnywhere)		USoundBase*			AreaSecureSound;					//var() Sound AreaSecureSound;
	UPROPERTY(EditAnywhere)		USoundBase*			RogerSound;							//var() Sound RogerSound;
	UPROPERTY(EditAnywhere)		USoundBase*			HooahSound;							//var() Sound HooahSound;
	UPROPERTY(EditAnywhere)		USoundBase*			ReadySound;							//var() Sound ReadySound;
	UPROPERTY(EditAnywhere)		USoundBase*			StrikeSound;						//var() Sound StrikeSound;
	UPROPERTY(EditAnywhere)		USoundBase*			RespondSound;						//var() Sound RespondSound;
	UPROPERTY(EditAnywhere)		USoundBase*			AcknowledgeSound;					//var() Sound AcknowledgeSound;
	UPROPERTY(EditAnywhere)		USoundBase*			AvailableSound;						//var() Sound AvailableSound;
	UPROPERTY(EditAnywhere)		USoundBase*			ConfirmSound;						//var() Sound ConfirmSound;
	UPROPERTY(EditAnywhere)		USoundBase*			RequestSound;						//var() Sound RequestSound;
	UPROPERTY(EditAnywhere)		USoundBase*			RadioSound;							//var() Sound RadioSound;
	UPROPERTY(EditAnywhere)		int32				StrikesAvailable;					//var() int StrikesAvailable;
	UPROPERTY(EditAnywhere)		float				ArrivalTime;						//var() float ArrivalTime;
	UPROPERTY(EditAnywhere)		uint8				TeamNumber;							//var() byte TeamNumber;

	void PostBeginPlay();
	void Reset();
	void GetInPosition();
	void Acknowledge();
	void Respond();
	void Strike();
	void CallForSupport(APlayerController* PC);
	bool CheckMark(APawn* Aimer, FVector TestMark, bool bFire);
	bool IsFiring();
	bool IsReady();
	bool IsAvailable();
	int32 GetNumStrikesAvailable();
	int32 GetTeamNumber();
};