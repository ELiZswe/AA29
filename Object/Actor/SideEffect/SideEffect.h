// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "GameFramework/Actor.h"
#include "SideEffect.generated.h"

UCLASS()
class ASideEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASideEffect();
	
	UPROPERTY()		bool	bReplaceExtantEffects;		//var bool bReplaceExtantEffects;
	UPROPERTY()		bool	bThereCanBeOnlyOne;			//var bool bThereCanBeOnlyOne;
	UPROPERTY()		bool	bServerEffect;				//var bool bServerEffect;
	UPROPERTY()		float	EffectDuration;				//var float EffectDuration;

	void ScaleByDamage(int32 Damage);
	bool OverrideEffects();
	void Start();
	void update(float DeltaTime);
	void End();

	//From Actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		EDrawType DrawType;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
