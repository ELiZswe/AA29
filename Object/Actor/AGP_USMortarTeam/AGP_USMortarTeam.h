// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_USMortarTeam.generated.h"

UCLASS()
class AA29_API AAGP_USMortarTeam : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGP_USMortarTeam();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		UMaterialInstance* matSpotterMap;			//var(USMortarTeam) Material matSpotterMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		float fpSkillLevel;							//var(USMortarTeam) float fpSkillLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		int32 iNumberOfTubes;						//var(USMortarTeam) int iNumberOfTubes;
	UPROPERTY()																	int32 iCurrentVehicleRoundsAvailable;		//var int iCurrentVehicleRoundsAvailable;
	UPROPERTY()																	int32 iCurrentSmokeRoundsAvailable;			//var int iCurrentSmokeRoundsAvailable;
	UPROPERTY()																	int32 iCurrentHERoundsAvailable;			//var int iCurrentHERoundsAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		int32 iMaxSmokeRoundsAvailable;				//var(USMortarTeam) int iMaxSmokeRoundsAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		int32 iMaxHERoundsAvailable;				//var(USMortarTeam) int iMaxHERoundsAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		int32 iMaxVehicleRoundsAvailable;			//var(USMortarTeam) int iMaxVehicleRoundsAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		int32 iMaxSmokeRoundsPerMission;			//var(USMortarTeam) int iMaxSmokeRoundsPerMission;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		int32 iMaxHERoundsPerMission;				//var(USMortarTeam) int iMaxHERoundsPerMission;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		int32 iMaxVehicleRoundsPerMission;			//var(USMortarTeam) int iMaxVehicleRoundsPerMission;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "USMortarTeam")		int32 iTeamID;								//var(USMortarTeam) int iTeamID;


	void Reset();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
