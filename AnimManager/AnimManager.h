// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnimManager.generated.h"

UCLASS()
class AA29_API AAnimManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnimManager();

	UPROPERTY()										bool bDelayStateChange;						//var bool bDelayStateChange;
	UPROPERTY()										FName NewState;								//var name NewState;
	UPROPERTY()										APawn* Pawn;								//var Pawn Pawn;

	void PostNetBeginPlay();
	void PostNetReceive();
	void NetChangeState(FName State);
	void BindToPawn(APawn* p);
	void ReleasePawn();
	bool CanPlayDeathAnim();
	void PlayDeathAnim();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
