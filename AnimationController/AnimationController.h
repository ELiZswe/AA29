// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnimationController.generated.h"

//class AAnimInstruction;

UCLASS()
class AA29_API AAnimationController : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AAnimationController();

	UPROPERTY()										bool bDebug;								//var bool bDebug;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName AnimatedActorTag;						//var() name AnimatedActorTag;
	UPROPERTY()										int32 LoopCount;							//var int LoopCount;
	UPROPERTY()										int32 QueueBack;							//var int QueueBack;
	UPROPERTY()										int32 QueueFront;							//var int QueueFront;
	//UPROPERTY()										AAnimInstruction* AnimationQueue;			//var AAnimInstruction* AnimationQueue;
	UPROPERTY()										AActor* AnimatedActor;						//var Actor AnimatedActor;

	void QueueClear();
	bool QueueIsEmpty();
	void QueueIsFull();
	//bool Enqueue(AAnimInstruction* Inst);
	void Dequeue();
	void BeginPlay();
	void PlayNextInstruction();
	//void AddInstruction(AAnimInstruction* Inst);
	void FlushInstructions();
	void Timer();
	void AnimEnd(int32 Channel);
	//void GetDebugString(AAnimInstruction* Inst);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
