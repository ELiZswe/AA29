// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "AnimationController.generated.h"

UCLASS()
class AAnimationController : public AActor
{
	GENERATED_BODY()

public:	
	
	AAnimationController();

	UPROPERTY()										bool bDebug;								//var bool bDebug;
	UPROPERTY(EditAnywhere)		FName AnimatedActorTag;						//var() name AnimatedActorTag;
	UPROPERTY()										int32 LoopCount;							//var int LoopCount;
	UPROPERTY()										int32 QueueBack;							//var int QueueBack;
	UPROPERTY()										int32 QueueFront;							//var int QueueFront;
	UPROPERTY()										FAnimInstruction AnimationQueue;			//var FAnimInstruction AnimationQueue;
	UPROPERTY()										AActor* AnimatedActor;						//var Actor AnimatedActor;

	void QueueClear();
	bool QueueIsEmpty();
	bool QueueIsFull();
	bool Enqueue(FAnimInstruction Inst);
	bool Dequeue();
	void BeginPlay();
	void PlayNextInstruction();
	void AddInstruction(FAnimInstruction Inst);
	void FlushInstructions();
	void Timer();
	void AnimEnd(int32 Channel);
	FString GetDebugString(FAnimInstruction Inst);

public:	
	
	virtual void Tick(float DeltaTime) override;
};
