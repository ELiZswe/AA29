// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AA29/AA29.h"
#include "AA2_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAA2_GameMode : public AGameModeBase
{
	GENERATED_BODY()
		

public:
	//AAA2_GameMode(const FObjectInitializer& ObjectInitializer);
	AAA2_GameMode();


	UPROPERTY()				EGameState	CurrentGameState;

	virtual AActor* ChoosePlayerStart_Implementation(AController* Player);
	virtual void BeginPlay() override;
	virtual void StartPlay() override;
	virtual void StartRound();
	virtual void StartMatch();
	virtual void PostLogin(APlayerController* NewPlayer) override;


	virtual bool IsRequireAuthorization();
	virtual FString StripColor(FString S);


	//From GameInfo
	virtual bool CheatsDisabled();

protected:



private:

};
