// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HelpIcon.generated.h"

UCLASS()
class AA29_API AHelpIcon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHelpIcon();

	UPROPERTY()							float		RotationSpeed;			//var float RotationSpeed;
	UPROPERTY()							AActor*		Follower;				//var Actor Follower;
	UPROPERTY()							FVector		offset;					//var Vector offset;

	void PostBeginPlay();
	void SetHelpIcon(AActor* FollowMe, FVector _offset, float Scale, float RotSpeed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
