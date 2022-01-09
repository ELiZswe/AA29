// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HelpIcon.generated.h"

UCLASS()
class AHelpIcon : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AHelpIcon();

	UPROPERTY()							float		RotationSpeed;			//var float RotationSpeed;
	UPROPERTY()							AActor*		Follower;				//var Actor Follower;
	UPROPERTY()							FVector		offset;					//var Vector offset;

	void PostBeginPlay();
	void SetHelpIcon(AActor* FollowMe, FVector _offset, float Scale, float RotSpeed);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
