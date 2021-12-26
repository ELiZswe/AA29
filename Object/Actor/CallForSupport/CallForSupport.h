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
	// Sets default values for this actor's properties
	ACallForSupport();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()										int32				InitialStrikesAvailable;			//var int InitialStrikesAvailable;
	UPROPERTY()										APlayerController*	Caller;								//var PlayerController Caller;
	UPROPERTY()										bool				bFiring;							//var bool bFiring;
	UPROPERTY()										bool				bReady;								//var bool bReady;
	UPROPERTY()										bool				bAvailable;							//var bool bAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			SquadLeaderEnemyEliminatedSound;	//var() Sound SquadLeaderEnemyEliminatedSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			SquadLeaderEnemyDownSound;			//var() Sound SquadLeaderEnemyDownSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			SquadLeaderEnemySpottedSound;		//var() Sound SquadLeaderEnemySpottedSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			SquadLeaderTakeCoverSound;			//var() Sound SquadLeaderTakeCoverSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			SquadLeaderCoverMeSound;			//var() Sound SquadLeaderCoverMeSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			SquadLeaderAreaSecureSound;			//var() Sound SquadLeaderAreaSecureSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			SquadLeaderRogerSound;				//var() Sound SquadLeaderRogerSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			SquadLeaderHooahSound;				//var() Sound SquadLeaderHooahSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			EnemyDownSound;						//var() Sound EnemyDownSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			EnemySpottedSound;					//var() Sound EnemySpottedSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			TakeCoverSound;						//var() Sound TakeCoverSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			CoverMeSound;						//var() Sound CoverMeSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			AreaSecureSound;					//var() Sound AreaSecureSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			RogerSound;							//var() Sound RogerSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			HooahSound;							//var() Sound HooahSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			ReadySound;							//var() Sound ReadySound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			StrikeSound;						//var() Sound StrikeSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			RespondSound;						//var() Sound RespondSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			AcknowledgeSound;					//var() Sound AcknowledgeSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			AvailableSound;						//var() Sound AvailableSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			ConfirmSound;						//var() Sound ConfirmSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			RequestSound;						//var() Sound RequestSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase*			RadioSound;							//var() Sound RadioSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32				StrikesAvailable;					//var() int StrikesAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float				ArrivalTime;						//var() float ArrivalTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		uint8				TeamNumber;							//var() byte TeamNumber;

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