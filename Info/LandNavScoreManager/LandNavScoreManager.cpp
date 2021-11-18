// All the original content belonged to the US Army


#include "AA29/Info/LandNavScoreManager/LandNavScoreManager.h"

ALandNavScoreManager::ALandNavScoreManager()
{

}
//const MAXOBJ = 10;

void ALandNavScoreManager::SetObjectiveTime(int32 Index, int32 Time)
{
	/*
	if (Index <= 10)
	{
		Objectives[Index] = Time;
	}
	else
	{
		Log("LandNavScoreManager::SetObjectiveTime(): ERROR: Index out of range");
	}
	*/
}

void ALandNavScoreManager::GetObjectiveTime(int Index)
{
	/*
	if (Index <= 10)
	{
		Return Objectives[Index];
	}
	else
	{
		Log("LandNavScoreManager::GetObjectiveTime(): ERROR: Index out of range");
		Return - 1;
	}
	*/
}

int32 ALandNavScoreManager::GetMaxIndex()
{
	return 10;
}

void ALandNavScoreManager::FormatTime(int32 Time)
{
	/*
	local int nMinutes;
	local int nSeconds;
	local string sMinutes;
	local string sSeconds;
	nMinutes = Time / 60;
	nSeconds = Time % 60;
	if (nMinutes < 10)
	{
		sMinutes = "0" $ nMinutes;
	}
	else
	{
		sMinutes = nMinutes;
	}
	if (nSeconds < 10)
	{
		sSeconds = "0" $ nSeconds;
	}
	else
	{
		sSeconds = nSeconds;
	}
	Return sMinutes $ ":" $ sSeconds;
	*/
}