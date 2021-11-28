// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA2_Info.generated.h"

UCLASS()
class AA29_API AAA2_Info : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
