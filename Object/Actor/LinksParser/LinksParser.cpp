// All the original content belonged to the US Army

#include "AA29/Object/Actor/LinksParser/LinksParser.h"

// Sets default values
ALinksParser::ALinksParser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
	//bAcceptsProjectors = false;
	//bMovable = false;
	//CollisionHeight = 49;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
}


void ALinksParser::BeginPlay()
{
	Super::BeginPlay();
	
}


void ALinksParser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALinksParser::Init(FString FilePath)
{
	GetHeaders(FilePath);
	GetSections(FilePath);
}
void ALinksParser::GetHeaders(FString FilePath)
{
	/*
	int32 i = 0;
	FString Header;
	Sections.Num() = 0;
	Header = GetPrivateProfileString(FilePath, "Sections", "Section" + i);
	if (Header != "")
	{
		Sections.Num() = i + 1;
		Sections[i].Header = Header;
		i++;
		Header = GetPrivateProfileString(FilePath, "Sections", "Section" + i);
	}
	*/
}
void ALinksParser::GetSections(FString FilePath)
{
	/*
	int32 i = 0;
	FString Header;
	for (i = 0; i < Sections.Num(); i++)
	{
		Header = Sections[i].Header;
		Sections[i].Id = GetPrivateProfileString(FilePath, Header, "ID");
		Sections[i].Display = GetPrivateProfileString(FilePath, Header, "Display");
		Sections[i].Caption = GetPrivateProfileString(FilePath, Header, "Caption");
		Sections[i].URL = GetPrivateProfileString(FilePath, Header, "URL");
	}
	*/
}
int32 ALinksParser::GetHeaderIndex(FString Header)
{
	int32 i = 0;
	if (Header == "")
	{
		return - 1;
	}
	for (i = 0; i < Sections.Num(); i++)
	{
		//if (Sections[i].Header ~= Header)
		//{
		//	return i;
		//}
	}
	return - 1;
}
int32 ALinksParser::GetIDIndex(FString Id)
{
	
	int32 i = 0;
	if (Id == "")
	{
		return - 1;
	}
	for (i = 0; i < Sections.Num(); i++)
	{
		//if (Sections[i].Id ~= Id)
		//{
		//	return i;
		//}
	}
	return - 1;
}
