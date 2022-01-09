// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandCivilianManager.generated.h"

UCLASS()
class ARandCivilianManager : public AActor
{
	GENERATED_BODY()
	
public:	
	
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
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
