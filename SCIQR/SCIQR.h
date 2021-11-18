// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyStructs.h"
#include "SCIQR.generated.h"

class ATcpLinkSCI;


UCLASS()
class AA29_API ASCIQR : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASCIQR();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY()							ESCIQRState sciqrState;							//var ESCIQRState sciqrState;
	UPROPERTY()							bool bRegistered;								//var bool bRegistered;
	UPROPERTY()							FString myGuid;									//var string myGuid;
	UPROPERTY(globalconfig)				FString IP;										//var globalconfig string IP;
	UPROPERTY()							ATcpLinkSCI* link;								//var TcpLinkSCI link;



	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PreBeginPlay();
	void Destroyed();
	void doRegistration();
	void parseRegistrationResponse(FString responseString);
	void doHeartbeat();
	void Timer();
};
