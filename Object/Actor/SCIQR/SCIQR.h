// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "SCIQR.generated.h"

class ATcpLinkSCI;


UCLASS()
class ASCIQR : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ASCIQR();

protected:
	
	virtual void BeginPlay() override;

public:	

	UPROPERTY()							ESCIQRState sciqrState;							//var ESCIQRState sciqrState;
	UPROPERTY()							bool bRegistered;								//var bool bRegistered;
	UPROPERTY()							FString myGuid;									//var string myGuid;
	UPROPERTY(globalconfig)				FString IP;										//var globalconfig string IP;
	UPROPERTY()							ATcpLinkSCI* link;								//var TcpLinkSCI link;



	
	virtual void Tick(float DeltaTime) override;

	void PreBeginPlay();
	void Destroyed();
	void doRegistration();
	void parseRegistrationResponse(FString responseString);
	void doHeartbeat();
	void Timer();
};
