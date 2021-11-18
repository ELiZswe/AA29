// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vignette.generated.h"

class AGameInfo;


UCLASS()
class AA29_API AVignette : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVignette();

	UPROPERTY()		FString MapName;				//var() FString MapName;
	UPROPERTY()		AGameInfo* GameClass;			//var() class<GameInfo> GameClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Init();
	void DrawVignette(UCanvas* C, float Progress);

};
