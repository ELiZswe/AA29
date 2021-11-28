// All the original content belonged to the US Army


#include "AA2_Info.h"

// Sets default values
AAA2_Info::AAA2_Info()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RulesGroup = "Rules";
	GameGroup = "Game";
	ServerGroup = "Server";
	ChatGroup = "Chat";
	BotsGroup = "Bots";
	MapVoteGroup = "Map Voting";
	KickVoteGroup = "Kick Voting";
	//bHidden = true;
	//bSkipActorPropertyReplication = true;
	//bOnlyDirtyReplication = true;
	//RemoteRole = ROLE_None
	//NetUpdateFrequency = 10.000000;

}

// Called when the game starts or when spawned
void AAA2_Info::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAA2_Info::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


/*
// mc: Fill a PlayInfoData structure to allow easy access to
void AAA2_Info::FillPlayInfo(APlayInfo* PlayInfo)
{
	PlayInfo.AddClass(default.Class);
}
*/
bool AAA2_Info::AcceptPlayInfoProperty(FString PropertyName)
{
	return true;
}

//	rjp-- Can I remove a class from playinfo?
//	Called when PlayInfo.RemoveClass is called on this class
//	Only called if you have called PopClass() after calling FillPlayInfo() on this class
bool AAA2_Info::AllowClassRemoval()
{
	return true;
}

uint8 AAA2_Info::GetSecurityLevel(FString PropName)
{
	return 0;
}

FString AAA2_Info::GetDescriptionText(FString PropName)
{
	return "";
}