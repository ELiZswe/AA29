// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA2_Info.generated.h"

UCLASS()
class AAA2_Info : public AActor
{
	GENERATED_BODY()

public:	
	AAA2_Info();

	// Standard PlayInfo groups
	UPROPERTY()			FString KickVoteGroup;						//var const localized string KickVoteGroup;
	UPROPERTY()			FString MapVoteGroup;						//var const localized string MapVoteGroup;
	UPROPERTY()			FString BotsGroup;							//var const localized string BotsGroup;
	UPROPERTY()			FString ChatGroup;							//var const localized string ChatGroup;
	UPROPERTY()			FString ServerGroup;						//var const localized string ServerGroup;
	UPROPERTY()			FString GameGroup;							//var const localized string GameGroup;
	UPROPERTY()			FString RulesGroup;							//var const localized string RulesGroup;

	//void FillPlayInfo(APlayInfo* PlayInfo);
	bool AcceptPlayInfoProperty(FString PropertyName);
	bool AllowClassRemoval();
	uint8 GetSecurityLevel(FString PropName);
	FString GetDescriptionText(FString PropName);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
