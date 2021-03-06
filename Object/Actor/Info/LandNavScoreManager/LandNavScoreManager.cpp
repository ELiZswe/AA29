// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LandNavScoreManager/LandNavScoreManager.h"

ALandNavScoreManager::ALandNavScoreManager()
{
	Objectives.SetNum(10);

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

int32 ALandNavScoreManager::GetObjectiveTime(int32 Index)
{
	if (Index <= 10)
	{
		return Objectives[Index];
	}
	else
	{
		//Log("LandNavScoreManager::GetObjectiveTime(): ERROR: Index out of range");
		return - 1;
	}
}

int32 ALandNavScoreManager::GetMaxIndex()
{
	return 10;
}

FString ALandNavScoreManager::FormatTime(int32 Time)
{
	int32 nMinutes = 0;
	int32 nSeconds = 0;
	FString sMinutes = "";
	FString sSeconds = "";
	nMinutes = (Time / 60);
	//nSeconds = int((float(Time) % float(60)));
	if (nMinutes < 10)
	{
		sMinutes = "0" + FString::FromInt(nMinutes);
	}
	else
	{
		sMinutes = FString::FromInt(nMinutes);
	}
	if (nSeconds < 10)
	{
		sSeconds = "0" + FString::FromInt(nSeconds);
	}
	else
	{
		sSeconds = FString::FromInt(nSeconds);
	}
	return sMinutes + ":" + sSeconds;
}
