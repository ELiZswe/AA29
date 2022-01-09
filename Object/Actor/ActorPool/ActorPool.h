// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "ActorPool.generated.h"

UCLASS()
class AActorPool : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AActorPool();

	UPROPERTY()																			FPoolItem Pool;						//var PoolItem Pool;
	UPROPERTY()																			int32 cPoolClass;					//var class<Object> cPoolClass;

	void Init();
	void ReleaseActor(int32 Index);
	void ResetActor(int32 Index);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
