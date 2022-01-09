// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGP_USMortarTeam.generated.h"

UCLASS()
class AAGP_USMortarTeam : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_USMortarTeam();

	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		UMaterialInstance* matSpotterMap;			//var(USMortarTeam) Material matSpotterMap;
	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		float fpSkillLevel;							//var(USMortarTeam) float fpSkillLevel;
	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		int32 iNumberOfTubes;						//var(USMortarTeam) int iNumberOfTubes;
	UPROPERTY()																	int32 iCurrentVehicleRoundsAvailable;		//var int iCurrentVehicleRoundsAvailable;
	UPROPERTY()																	int32 iCurrentSmokeRoundsAvailable;			//var int iCurrentSmokeRoundsAvailable;
	UPROPERTY()																	int32 iCurrentHERoundsAvailable;			//var int iCurrentHERoundsAvailable;
	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		int32 iMaxSmokeRoundsAvailable;				//var(USMortarTeam) int iMaxSmokeRoundsAvailable;
	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		int32 iMaxHERoundsAvailable;				//var(USMortarTeam) int iMaxHERoundsAvailable;
	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		int32 iMaxVehicleRoundsAvailable;			//var(USMortarTeam) int iMaxVehicleRoundsAvailable;
	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		int32 iMaxSmokeRoundsPerMission;			//var(USMortarTeam) int iMaxSmokeRoundsPerMission;
	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		int32 iMaxHERoundsPerMission;				//var(USMortarTeam) int iMaxHERoundsPerMission;
	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		int32 iMaxVehicleRoundsPerMission;			//var(USMortarTeam) int iMaxVehicleRoundsPerMission;
	UPROPERTY(EditAnywhere, Category = "USMortarTeam")		int32 iTeamID;								//var(USMortarTeam) int iTeamID;


	void Reset();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
