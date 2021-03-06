// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/PlayerController/AGP_Player/AGP_Player.h"
#include "CinematicPlayer.generated.h"

UCLASS()
class ACinematicPlayer : public AAGP_Player
{
	GENERATED_BODY()
public:
	ACinematicPlayer();
	
	FString FindMenu();
	void Fire(float F);
	void AltFire(float F);
	void ShowMenu();
	void GotoMenu(FString MenuName);
};
