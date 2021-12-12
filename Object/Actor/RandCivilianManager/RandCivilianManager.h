// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandCivilianManager.generated.h"

UCLASS()
class AA29_API ARandCivilianManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandCivilianManager();

	UPROPERTY()													AController* C;						//var Controller C;
	UPROPERTY()													TArray<APawn*> CivilianList;		//var TArray<Pawn> CivilianList;
	UPROPERTY(EditAnywhere, Category = "Civillian_Manager")		int32 MinCivilians;					//var(Civillian_Manager) int32 MinCivilians;
	UPROPERTY(EditAnywhere, Category = "Civillian_Manager")		int32 MaxCivilians;					//var(Civillian_Manager) int32 MaxCivilians;
	UPROPERTY(EditAnywhere, Category = "Civillian_Manager")		FName GroupTag;						//var(Civillian_Manager) FName GroupTag;

	void PreBeginPlay();
	void MatchStarting();
	bool IsLegalForThisManager(APawn* p);
	void HideOrShow();
	int32 FindRand(int32 Minimum, int32 Maximum);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
