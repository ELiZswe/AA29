// All the original content belonged to the US Army


#include "AA29/Object/KeyGenerator/TimeLimitedKeyGenerator/TimeLimitedKeyGenerator.h"

UTimeLimitedKeyGenerator::UTimeLimitedKeyGenerator()
{
	TimeLimit = 60;
	PregeneratedKeyName = "Default.key";
}

//native static Function float GetTime();
float UTimeLimitedKeyGenerator::GetTime()
{
	return 0;    //FAKE   /ELiZ
}

//native static Function bool CopyFile(FString Dest, FString Source);
bool UTimeLimitedKeyGenerator::CopyFile(FString Dest, FString Source)
{
	return false;   //FAKE   /ELiZ
}

//native Function CancelKeyGeneration();
void UTimeLimitedKeyGenerator::CancelKeyGeneration()
{

}

void UTimeLimitedKeyGenerator::BeginKeyGeneration()
{
	/*
	StartTime = GetTime();
	Super::BeginKeyGeneration();
	*/
}

bool UTimeLimitedKeyGenerator::IsKeyGenerationComplete()
{
	/*
	KeyGenerationIsComplete = Super::IsKeyGenerationComplete();
	if ((!KeyGenerationIsComplete) && ((StartTime + TimeLimit) <= GetTime()))
	{
		Log("TimeLimitedKeyGenerator::IsKeyGenerationComplete() Failed to generate key in" @ string(TimeLimit) @ "seconds.");
		CancelKeyGeneration();
		InstallPregeneratedKey();
		KeyGenerationIsComplete = true;
	}
	*/
	return KeyGenerationIsComplete;
}

void UTimeLimitedKeyGenerator::InstallPregeneratedKey()
{
	/*
	Log("TimeLimitedKeyGenerator::InstallPregeneratedKey");
	Log("Copying" @ PregeneratedKeyName @ "to" @ class'DBAuth.DBAuth'.GetKeyFilename());
	CopyFile(class'DBAuth.DBAuth'.GetKeyFilename(), PregeneratedKeyName);
	*/
}