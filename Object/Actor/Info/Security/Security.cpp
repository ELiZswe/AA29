// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/Security/Security.h"

ASecurity::ASecurity()
{
	LastParams.SetNum(2);

}

/*
State Probation
{
	Function Timer()
	{
		BadClient(LastType,LastParams[0] + "," + LastParams[1]);
	}
}
*/

//native Function NativePerform(int32 SecType, string Param1, string Param2);
void ASecurity::NativePerform(int32 SecType, FString Param1, FString Param2)
{

}

//native Function LocalPerform(int32 SecType, string Param1, string Param2, out TArray<FString> Results);
void ASecurity::LocalPerform(int32 SecType, FString Param1, FString Param2, TArray<FString> &Results)
{

}

void ASecurity::ClientPerform(int32 SecType, FString Param1, FString Param2)
{
	//NativePerform(SecType, Param1, Param2);
}

void ASecurity::ServerCallback(int32 SecType, FString Data)
{
	//SetTimer(0, false);
	//GotoState("None");
}

void ASecurity::Perform(int32 SecType, FString Param1, FString Param2, float TimeOut)
{
	/*
	LastType = SecType;
	LastParams[0] = Param1;
	LastParams[1] = Param2;
	ClientPerform(SecType, Param1, Param2);
	SetTimer(TimeOut, false);
	GotoState('Probation');
	*/
}

void ASecurity::BadClient(int32 Code, FString Data)
{
	/*
	ClientMessage("The Server has determined that your client is illegal and you have been removed! Code: " + Code + " [" + Data + "]");
	Owner.Destroy();
	Destroy();
	*/
}

void ASecurity::ClientMessage(FString S)
{
	//Log(S, 'Security');
}
