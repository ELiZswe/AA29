// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "CinematicGame.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API ACinematicGame : public AGameInfo
{
	GENERATED_BODY()
public:
	ACinematicGame();

	UPROPERTY(config)		bool bPreviouslyViewed;			//var config bool bPreviouslyViewed;


	void PostBeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void AddDefaultInventory(APawn* PlayerPawn);
	void SetGameSpeed(float t);
	void PostLogin(APlayerController* NewPlayer);
	void Logout(AController* Exiting);

};
