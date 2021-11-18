// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyStructs.h"
#include "GameFramework/Actor.h"
#include "Base3pAmmoRound.generated.h"

class USkeletalMesh;

UCLASS()
class AA29_API ABase3pAmmoRound : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABase3pAmmoRound();

	//From Actor:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float DrawScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* Texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USkeletalMesh* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		EDrawType DrawType;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//virtual void IsRoundVisible() ;
	
	virtual void ShowRound(bool bShouldShowRound);


};
