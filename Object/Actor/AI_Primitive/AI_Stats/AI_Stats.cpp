// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/AI_Stats/AI_Stats.h"

AAI_Stats::AAI_Stats()
{
	_enumStats.SetNum(10);
	_floatStats.SetNum(5);
	_vecStats.SetNum(5);

}

void AAI_Stats::SetTeam(ETeam new_team)
{
	Team = new_team;
}

ETeam AAI_Stats::GetTeam()
{
	return Team;
}

void AAI_Stats::BeginPlay()
{
	vecStatIdx = 0;
	floatStatIdx = 0;
	enumStatIdx = 0;
}

bool AAI_Stats::setSource(AActor* informationSource)
{
	FVector zeroVec = FVector(0,0,0);
	/*
	if (informationSource->IsA(APawn::StaticClass()))
	{
		alive = true;
	}
	else
	{
		alive = false;
	}
	if (vecStatIdx > 5 - 3)
	{
		Log("dnback:: AI_Stats.setSource(); vecStat array overflow for posit/velocity");
		return false;
	}
	else
	{
		if (alive)
		{
			if (enumStatIdx > 10 - 1)
			{
				Log("dnback:: AI_Stats.setSource(); enumStat array overflow for condition");
				return false;
			}
		}
	}
	Source = informationSource;
	zeroVec.X = 0;
	zeroVec.Y = 0;
	zeroVec.Z = 0;
	createNewVecStat("position", Source->GetActorLocation(), zeroVec, 0, 0.05, false);
	createNewVecStat("velocity", Source.Velocity, zeroVec, 0, 0.1, false);
	if (alive)
	{
		createNewFloatStat("condition", Pawn(Source).Health, 0, 0, 0.5, false);
	}
	SetTimer(1, false);
	*/

	return false;   //FAKE   /ELiZ
}

bool AAI_Stats::createNewEnumStat(FString itsCalled, uint8 Value, uint8 spoof, float chance, float obsc, bool staticp)
{
	/*
	int32 i = 0;
	if (enumStatIdx > 10 - 2)
	{
		return false;
	}
	for (i = 0; i < enumStatIdx; i++)
	{
		if (_enumStats[i].statName == itsCalled)
		{
			return false;
		}
	}
	_enumStats[enumStatIdx].statName = itsCalled;
	_enumStats[enumStatIdx].trueValue = Value;
	_enumStats[enumStatIdx].spoofValue = spoof;
	_enumStats[enumStatIdx].spoofChance = chance;
	_enumStats[enumStatIdx].obscurity = obsc;
	_enumStats[enumStatIdx].isStatic = staticp;
	enumStatIdx++;
	*/
	return true;
}

bool AAI_Stats::createNewVecStat(FString itsCalled, FVector Value, FVector spoof, float chance, float obsc, bool staticp)
{
	/*
	int32 i = 0;
	if (vecStatIdx > 5 - 2)
	{
		return false;
	}
	for (i = 0; i < vecStatIdx; i++)
	{
		if (_vecStats[i].statName == itsCalled)
		{
			return false;
		}
	}
	_vecStats[vecStatIdx].statName = itsCalled;
	_vecStats[vecStatIdx].trueValue = Value;
	_vecStats[vecStatIdx].spoofValue = spoof;
	_vecStats[vecStatIdx].spoofChance = chance;
	_vecStats[vecStatIdx].obscurity = obsc;
	_vecStats[vecStatIdx].isStatic = staticp;
	vecStatIdx++;
	*/
	return true;
}

bool AAI_Stats::createNewFloatStat(FString itsCalled, float Value, float spoof, float chance, float obsc, bool staticp)
{
	/*
	int32 i = 0;
	if (floatStatIdx > 5 - 2)
	{
		return false;
	}
	for (i = 0; i < floatStatIdx; i++)
	{
		if (_floatStats[i].statName == itsCalled)
		{
			return false;
		}
	}
	_floatStats[floatStatIdx].statName = itsCalled;
	_floatStats[floatStatIdx].trueValue = Value;
	_floatStats[floatStatIdx].spoofValue = spoof;
	_floatStats[floatStatIdx].spoofChance = chance;
	_floatStats[floatStatIdx].obscurity = obsc;
	_floatStats[floatStatIdx].isStatic = staticp;
	floatStatIdx++;
	*/
	return true;
}

uint8 AAI_Stats::getEnumStat(FString itsCalled, float dynLvl, float statLvl, int32 &noInfo)
{
	int32 i = 0;
	FEnumStat thisStat;
	uint8 Response = 0;
	float spoofPoss = 0;
	float infoLevel = 0;
	Response = -1;
	noInfo = 0;
	/*
	for (i = 0; i < enumStatIdx; i++)
	{
		thisStat = _enumStats[i];
		if (thisStat.statName == itsCalled)
		{
			if (thisStat.isStatic)
			{
				infoLevel = statLvl;
			}
			else
			{
				infoLevel = dynLvl;
			}
			spoofPoss = thisStat.spoofChance;
			if (infoLevel < spoofPoss)
			{
				Response = 0;
				noInfo = 1;
			}
			else
			{
				if (infoLevel < thisStat.obscurity)
				{
					Response = thisStat.spoofValue;
				}
				else
				{
					Response = thisStat.trueValue;
				}
			}
		}
	}
	*/
	return Response;
}

FVector AAI_Stats::getVecStat(FString itsCalled, float dynLvl, float statLvl, int32& noInfo)
{
	int32 i = 0;
	FVectorStat thisStat;
	FVector Response = FVector(0,0,0);
	float spoofPoss = 0;
	float infoLevel = 0;
	Response.X = -1;
	Response.Y = -1;
	Response.Z = -1;
	/*
	noInfo = 0;
	for (i = 0; i < vecStatIdx; i++)
	{
		if (_vecStats[i].statName == itsCalled)
		{
			thisStat = _vecStats[i];
			if (thisStat.isStatic)
			{
				infoLevel = statLvl;
			}
			else
			{
				infoLevel = dynLvl;
			}
			spoofPoss = thisStat.spoofChance;
			if (infoLevel < spoofPoss)
			{
				Response.X = 0;
				Response.Y = 0;
				Response.Z = 0;
				noInfo = 1;
			}
			else
			{
				if (infoLevel < thisStat.obscurity)
				{
					Response = thisStat.spoofValue;
				}
				else
				{
					Response = thisStat.trueValue;
				}
			}
		}
	}
	*/
	return Response;
}

float AAI_Stats::getFloatStat(FString itsCalled, float dynLvl, float statLvl, int32& noInfo)
{
	int32 i = 0;
	FFloatStat thisStat;
	float Response = 0;
	float spoofPoss = 0;
	float infoLevel = 0;
	Response = -1;
	noInfo = 0;
	/*
	for (i = 0; i < floatStatIdx; i++)
	{
		if (_floatStats[i].statName == itsCalled)
		{
			thisStat = _floatStats[i];
			if (thisStat.isStatic)
			{
				infoLevel = statLvl;
			}
			else
			{
				infoLevel = dynLvl;
			}
			spoofPoss = thisStat.spoofChance;
			if (infoLevel < spoofPoss)
			{
				Response = 0;
				noInfo = 1;
			}
			else
			{
				if (infoLevel < thisStat.obscurity)
				{
					Response = thisStat.spoofValue;
				}
				else
				{
					Response = thisStat.trueValue;
				}
			}
		}
	}
	*/
	return Response;
}

bool AAI_Stats::updateVecStat(FString statName, FVector NewValue)
{	
	/*
	int32 i = 0;
	for (i = 0; i < vecStatIdx; i++)
	{
		if (_vecStats[i].statName == statName)
		{
			_vecStats[i].trueValue = NewValue;
			return true;
		}
	}
	*/
	return false;
}

bool AAI_Stats::updateEnumStat(FString statName, uint8 NewValue)
{
	/*
	int32 i = 0;
	for (i = 0; i < enumStatIdx; i++)
	{
		if (_enumStats[i].statName == statName)
		{
			_enumStats[i].trueValue = NewValue;
			return true;
		}
	}
	*/
	return false;
}

bool AAI_Stats::updateFloatStat(FString statName, float NewValue)
{
	/*
	int32 i = 0;
	for (i = 0; i < floatStatIdx; i++)
	{
		if (_floatStats[i].statName == statName)
		{
			_floatStats[i].trueValue = NewValue;
			return true;
		}
	}
	*/
	return false;
}

void AAI_Stats::Timer()
{
	/*
	if (Source == nullptr)
	{
		return;
	}
	updateVecStat("position", Source.Location);
	updateVecStat("velocity", Source.Velocity);
	if (alive)
	{
		updateFloatStat("condition", Pawn(Source).Health);
		if (Cast<APawn>(Source).Health > 0)
		{
			SetTimer(1, false);
		}
	}
	*/
}
