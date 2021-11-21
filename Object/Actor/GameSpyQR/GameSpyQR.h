// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameSpyQR.generated.h"

UCLASS(Config = Game)
class AA29_API AGameSpyQR : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
