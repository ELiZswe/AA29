// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bass.generated.h"

class ABassLaserBeam;
class ABassLaserAttachment;

UCLASS()
class AA29_API ABass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()					bool WestquotesLeavenworth;					//var bool WestquotesLeavenworth;
	UPROPERTY()					bool IllTemperedWithLaserBeams;				//var bool IllTemperedWithLaserBeams;
	UPROPERTY()					bool SeaBassAwaken;							//var bool SeaBassAwaken;
	UPROPERTY()					bool AHaiku;								//var bool AHaiku;
	UPROPERTY()					int32 Health;								//var int Health;
	UPROPERTY()					ABassLaserBeam* MyBeam;						//var BassLaserBeam MyBeam;
	UPROPERTY()					ABassLaserAttachment* LaserAttachment;		//var BassLaserAttachment LaserAttachment;

	void PostBeginPlay();
	void Destroyed();
};
