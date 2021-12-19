// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "GameFramework/Actor.h"
#include "BaseAmmoRound.generated.h"

UCLASS()
class ABaseAmmoRound : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseAmmoRound();

	UPROPERTY()		ABaseAmmoRound* NextAmmoRound;		//var BaseAmmoRound NextAmmoRound;
	UPROPERTY()		int32 ammo_id;						//var int32 ammo_id;
	UPROPERTY()		UStaticMesh* ExpendedSM;			//var StaticMesh ExpendedSM;
	UPROPERTY()		bool bHasBreechRound;				//var bool bHasBreechRound;
	UPROPERTY()		bool bRoundInBreech;				//var bool bRoundInBreech;
	
	//From Actor
	UPROPERTY()		UStaticMesh* StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Destroyed();
	void AdjustAmmoRound(int32 total_ammo);
	void AdjustSpecialAmmoRounds(bool bRender);
	void SetAmmoID(int32 new_id);
	FName GetBoneNameForAmmoAttach(bool bAux, bool bSpecial);
};
