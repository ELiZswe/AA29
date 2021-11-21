// All the original content belonged to the US Army


#include "AA29/Object/Actor/GameSpyQR/GameSpyQR.h"

// Sets default values
AGameSpyQR::AGameSpyQR()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bNAT = true;
	//bHidden = true;
	//RemoteRole = ROLE_None;
}

// Called when the game starts or when spawned
void AGameSpyQR::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGameSpyQR::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	bool bIsPublic = false;
	bIsPublic = ((Level.IsAuthorizedServer() || Level.IsLeasedServer()) || Level.IsOfficialServer());
	QRSetIsPublic(bIsPublic);
	QRThink();
	*/
}

//native Function QRInit(FString IP, int32 Port, int32 IsPublic, int32 UseNAT);
void AGameSpyQR::QRInit(FString aIP, int32 Port, int32 IsPublic, int32 UseNAT)
{

}

//native Function QRThink();
void AGameSpyQR::QRThink()
{

}

//native Function QRStateChange();
void AGameSpyQR::QRStateChange()
{

}

//native Function QRShutdown();
void AGameSpyQR::QRShutdown()
{

}

//native Function QRSetIsPublic(bool bIsPublic);
void AGameSpyQR::QRSetIsPublic(bool bIsPublic)
{

}

void AGameSpyQR::PreBeginPlay()
{
}

void AGameSpyQR::PostBeginPlay()
{
	/*
	Log("GameSpyQR - IP:" @ IP @ "port:" $ string(Level.Game.GetServerPort()) @ "lan:" @ string(int(Level.IsLanOnlyServer())) @ "nat:" @ string(int(bNAT)));
	if (Level.IsLanOnlyServer())
	{
		QRInit(IP, 7778, int((!Level.IsLanOnlyServer())), 0);
	}
	else
	{
		QRInit(IP, Level.Game.GetServerPort(), int((!Level.IsLanOnlyServer())), 0);
	}
	SetTimer(0.1, true);
	*/
}

void AGameSpyQR::Destroyed()
{
	//QRShutdown();
}

void AGameSpyQR::Timer()
{
	//QRThink();
}