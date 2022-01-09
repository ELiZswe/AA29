// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameSpyQR.generated.h"

UCLASS(Config = Game)
class AGameSpyQR : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AGameSpyQR();

	UPROPERTY(globalconfig)		FString		IP;				//var globalconfig FString IP;
	UPROPERTY(globalconfig)		bool		bNAT;			//var globalconfig bool bNAT;

	void QRInit(FString IP, int32 Port, int32 IsPublic, int32 UseNAT);
	void QRThink();
	void QRStateChange();
	void QRShutdown();
	void QRSetIsPublic(bool bIsPublic);
	void PreBeginPlay();
	void PostBeginPlay();
	void Destroyed();
	void Timer();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
