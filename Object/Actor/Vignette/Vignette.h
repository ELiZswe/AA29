// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vignette.generated.h"

class AGameInfo;


UCLASS()
class AVignette : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AVignette();

	UPROPERTY()		FString MapName;				//var() FString MapName;
	UPROPERTY()		AGameInfo* GameClass;			//var() class<GameInfo> GameClass;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	void Init();
	void DrawVignette(UCanvas* C, float Progress);

};
