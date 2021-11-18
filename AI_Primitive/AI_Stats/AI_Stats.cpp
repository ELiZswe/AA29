// All the original content belonged to the US Army


#include "AA29/AI_Primitive/AI_Stats/AI_Stats.h"

AAI_Stats::AAI_Stats()
{

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
void AAI_Stats::setSource(AActor* informationSource)
{
	/*
	local FVector zeroVec;
	if (informationSource.IsA('Pawn'))
	{
		alive = true;
	}
	else
	{
		alive = False;
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
	createNewVecStat("position", Source.Location, zeroVec, 0, 0.05, False);
	createNewVecStat("velocity", Source.Velocity, zeroVec, 0, 0.1, False);
	if (alive)
	{
		createNewFloatStat("condition", Pawn(Source).Health, 0, 0, 0.5, False);
	}
	SetTimer(1, False);
	*/
}
bool AAI_Stats::createNewEnumStat(FString itsCalled, uint8 Value, uint8 spoof, float chance, float obsc, bool staticp)
{
	/*
	local int i;
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
	local int i;
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
	local int i;
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
void AAI_Stats::getEnumStat(FString itsCalled, float dynLvl, float statLvl, int32 &noInfo)
{
	/*
	local int i;
	local EnumStat thisStat;
	local uint8 Response;
	local float spoofPoss;
	local float infoLevel;
	Response = -1;
	noInfo = 0;
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
	Return Response;
	*/
}
void AAI_Stats::getVecStat(FString itsCalled, float dynLvl, float statLvl, int32& noInfo)
{
	/*
	local int i;
	local VectorStat thisStat;
	local FVector Response;
	local float spoofPoss;
	local float infoLevel;
	Response.X = -1;
	Response.Y = -1;
	Response.Z = -1;
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
	Return Response;
	*/
}
void AAI_Stats::getFloatStat(FString itsCalled, float dynLvl, float statLvl, int32& noInfo)
{
	/*
	local int i;
	local FloatStat thisStat;
	local float Response;
	local float spoofPoss;
	local float infoLevel;
	Response = -1;
	noInfo = 0;
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
	Return Response;
	*/
}
bool AAI_Stats::updateVecStat(FString statName, FVector NewValue)
{	
	/*
	local int i;
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
	local int i;
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
	local int i;
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
	if (Source == None)
	{
		Return;
	}
	updateVecStat("position", Source.Location);
	updateVecStat("velocity", Source.Velocity);
	if (alive)
	{
		updateFloatStat("condition", Pawn(Source).Health);
		if (Pawn(Source).Health > 0)
		{
			SetTimer(1, False);
		}
	}
	*/
}
