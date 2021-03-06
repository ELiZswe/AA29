// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
#include "AA29/AA29.h"
#include "AI_Stats.generated.h"

UCLASS()
class AAI_Stats : public AAI_Primitive
{
	GENERATED_BODY()
public:
	AAI_Stats();

	UPROPERTY()			ETeam		Team;				//var Pawn.ETeam Team;
	UPROPERTY()			AActor*		Source;				//var Actor Source;
	UPROPERTY()			bool		bAutoDiscoverMe;	//var bool bAutoDiscoverMe;
	UPROPERTY()			bool		bInvisible;			//var bool bInvisible;
	UPROPERTY()			bool		alive;				//var bool alive;
	UPROPERTY()			int32		enumStatIdx;		//var int enumStatIdx;
	UPROPERTY()			int32		floatStatIdx;		//var int floatStatIdx;
	UPROPERTY()			int32		vecStatIdx;			//var int vecStatIdx;
	UPROPERTY()			TArray<FEnumStat>	_enumStats;			//var EnumStat _enumStats;
	UPROPERTY()			TArray<FFloatStat>	_floatStats;		//var FloatStat _floatStats;
	UPROPERTY()			TArray<FVectorStat>	_vecStats;			//var VectorStat _vecStats;

	void SetTeam(ETeam new_team);
	ETeam GetTeam();
	void BeginPlay();
	bool setSource(AActor* informationSource);
	bool createNewEnumStat(FString itsCalled, uint8 Value, uint8 spoof, float chance, float obsc, bool staticp);
	bool createNewVecStat(FString itsCalled, FVector Value, FVector spoof, float chance, float obsc, bool staticp);
	bool createNewFloatStat(FString itsCalled, float Value, float spoof, float chance, float obsc, bool staticp);
	uint8 getEnumStat(FString itsCalled, float dynLvl, float statLvl, int32& noInfo);
	FVector getVecStat(FString itsCalled, float dynLvl, float statLvl, int32& noInfo);
	float getFloatStat(FString itsCalled, float dynLvl, float statLvl, int32& noInfo);
	bool updateVecStat(FString statName, FVector NewValue);
	bool updateEnumStat(FString statName, uint8 NewValue);
	bool updateFloatStat(FString statName, float NewValue);
	void Timer();
};
