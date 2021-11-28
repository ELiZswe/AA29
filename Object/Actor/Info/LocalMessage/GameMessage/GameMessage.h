// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/aLocalMessage.h"
#include "GameMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGameMessage : public AaLocalMessage
{
	GENERATED_BODY()
public:
	AGameMessage();

	UPROPERTY()												FString SpecEnteredMessage;				//var localized string SpecEnteredMessage;
	UPROPERTY()												FString NewSpecMessage;					//var localized string NewSpecMessage;
	UPROPERTY()												FString KickWarning;					//var localized string KickWarning;
	UPROPERTY()												FString NewPlayerMessage;				//var localized string NewPlayerMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			FString BecameSpectator;				//var(Message) localized string BecameSpectator;
	UPROPERTY(EditAnywhere, Category = "Message")			FString CantBePlayer;					//var(Message) localized string CantBePlayer;
	UPROPERTY(EditAnywhere, Category = "Message")			FString CantBeSpectator;				//var(Message) localized string CantBeSpectator;
	UPROPERTY(EditAnywhere, Category = "Message")			FString MustHaveStats;					//var(Message) localized string MustHaveStats;
	UPROPERTY(EditAnywhere, Category = "Message")			FString VotePassed;						//var(Message) localized string VotePassed;
	UPROPERTY(EditAnywhere, Category = "Message")			FString VoteStarted;					//var(Message) localized string VoteStarted;
	UPROPERTY(EditAnywhere, Category = "Message")			FString NoNameChange;					//var(Message) localized string NoNameChange;
	UPROPERTY(EditAnywhere, Category = "Message")			FString NewTeamMessageTrailer;			//var(Message) localized string NewTeamMessageTrailer;
	UPROPERTY(EditAnywhere, Category = "Message")			FString NewTeamMessage;					//var(Message) localized string NewTeamMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			FString GlobalNameChange;				//var(Message) localized string GlobalNameChange;
	UPROPERTY(EditAnywhere, Category = "Message")			FString OvertimeMessage;				//var(Message) localized string OvertimeMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			FString MaxedOutMessage;				//var(Message) localized string MaxedOutMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			FString EnteredMessage;					//var(Message) localized string EnteredMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			FString FailedSpawnMessage;				//var(Message) localized string FailedSpawnMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			FString FailedPlaceMessage;				//var(Message) localized string FailedPlaceMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			FString FailedTeamMessage;				//var(Message) localized string FailedTeamMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			FString LeftMessage;					//var(Message) localized string LeftMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			FString SwitchLevelMessage;				//var(Message) localized string SwitchLevelMessage;

	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText); 
};
