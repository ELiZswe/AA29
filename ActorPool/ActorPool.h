// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "ActorPool.generated.h"

UCLASS()
class AA29_API AActorPool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorPool();


	UPROPERTY()																			FPoolItem Pool;						//var PoolItem Pool;
	UPROPERTY()																			int32 cPoolClass;					//var class<Object> cPoolClass;

	void Init();
	void ReleaseActor(int32 Index);
	void ResetActor(int32 Index);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
