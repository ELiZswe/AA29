// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bass.generated.h"

class ABassLaserBeam;
class ABassLaserAttachment;

UCLASS()
class ABass : public AActor
{
	GENERATED_BODY()
	
public:	
	ABass();

	UPROPERTY()					bool WestquotesLeavenworth;					//var bool WestquotesLeavenworth;
	UPROPERTY()					bool IllTemperedWithLaserBeams;				//var bool IllTemperedWithLaserBeams;
	UPROPERTY()					bool SeaBassAwaken;							//var bool SeaBassAwaken;
	UPROPERTY()					bool AHaiku;								//var bool AHaiku;
	UPROPERTY()					int32 Health;								//var int Health;
	UPROPERTY()					ABassLaserBeam* MyBeam;						//var BassLaserBeam MyBeam;
	UPROPERTY()					ABassLaserAttachment* LaserAttachment;		//var BassLaserAttachment LaserAttachment;

	//Mine
	UPROPERTY()					USkeletalMeshComponent* VisibleSkeletalMesh;
	UPROPERTY()					USceneComponent* Root;
	UPROPERTY(EditAnywhere)		USkeletalMesh* Mesh;

	virtual void Tick(float DeltaTime) override;
	void PostBeginPlay();
	void Destroyed();
protected:

	virtual void BeginPlay() override;
};
