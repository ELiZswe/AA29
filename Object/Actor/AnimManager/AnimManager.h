// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnimManager.generated.h"

UCLASS()
class AAnimManager : public AActor
{
	GENERATED_BODY()
	
public:	
	
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
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
