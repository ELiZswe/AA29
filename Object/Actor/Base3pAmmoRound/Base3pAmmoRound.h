// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "GameFramework/Actor.h"
#include "Base3pAmmoRound.generated.h"

class USkeletalMesh;

UCLASS()
class ABase3pAmmoRound : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABase3pAmmoRound();

	//From Actor:
	UPROPERTY(EditAnywhere)		UStaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere)		float DrawScale;
	UPROPERTY(EditAnywhere)		UTexture2D* Texture;
	UPROPERTY(EditAnywhere)		USkeletalMesh* Mesh;
	UPROPERTY(EditAnywhere)		EDrawType DrawType;


protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	//virtual void IsRoundVisible() ;
	
	virtual void ShowRound(bool bShouldShowRound);


};
