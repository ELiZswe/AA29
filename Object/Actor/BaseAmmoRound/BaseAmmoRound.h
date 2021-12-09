// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "GameFramework/Actor.h"
#include "BaseAmmoRound.generated.h"

UCLASS()
class AA29_API ABaseAmmoRound : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseAmmoRound();

	UPROPERTY()		ABaseAmmoRound* NextAmmoRound;		//var BaseAmmoRound NextAmmoRound;
	UPROPERTY()		int32 ammo_id;						//var int ammo_id;
	UPROPERTY()		UStaticMesh* ExpendedSM;			//var StaticMesh ExpendedSM;
	UPROPERTY()		bool bHasBreechRound;				//var bool bHasBreechRound;
	UPROPERTY()		bool bRoundInBreech;				//var bool bRoundInBreech;

	//From Actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		EDrawType DrawType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UStaticMesh* StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void AdjustAmmoRound() ;
	virtual void AdjustSpecialAmmoRounds() ;
	virtual void SetAmmoID() ;
	virtual void GetBoneName() ;
};
