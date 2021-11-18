// All the original content belonged to the US Army


#include "AA29/Object/Actor/Vignette/UT2LoadingPageBase/UT2SP_LadderLoading/UT2SP_LadderLoading.h"

AUT2SP_LadderLoading::AUT2SP_LadderLoading()
{
	White = FColor(255, 255, 255, 255);
	Yellow = FColor(0, 255, 255, 255);
	Blue = FColor(255, 64, 64, 255);
	Red = FColor(0, 0, 255, 255);
	StatNames = { "VS","Accuracy","Aggressiveness","Agility","Tactics" };
	LoadingMessage = "Loading...";
}

void AUT2SP_LadderLoading::Init()
{
}

void AUT2SP_LadderLoading::AddLoading()
{
	//AddJustifiedText(LoadingMessage, 1, 0, 0, 1, 1).FontName = "XInterface.UT2LargeFont";
}

void AUT2SP_LadderLoading::AddBackground()
{
	/*
	local Material Tex;
	Tex = DLOTexture("InterfaceContent.Backgrounds.bg10");
	if (Tex == None)
	{
		Tex = DLOTexture("InterfaceContent.Backgrounds.bg11");
	}
	*/
}

void AUT2SP_LadderLoading::AddTitle()
{
	/*
	FString Title = "";
	local class<GameInfo>  GIClass;
	GIClass = class<GameInfo>(DynamicLoadObject(myMatchInfo.GameType, Class'Class'));
	Title = LoadingMessage @ GIClass.Default.GameName;
	AddJustifiedText(Title, 1, 0, 0, 0.075, 1).FontName = "XInterface.UT2LargeFont";
	*/
}

void AUT2SP_LadderLoading::AddPlayerRoster()
{
}

void AUT2SP_LadderLoading::AddOpponentRoster()
{
}

void AUT2SP_LadderLoading::AddTeamBar(int32 TeamID, FString TeamIconName, TArray<FString>& Crew, float Top, FColor TeamColor, bool bNameUp)
{
}

void AUT2SP_LadderLoading::AddTeamCompare()
{
}
