// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoLocalMessage.h"
#include "CommoEventRadio.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACommoEventRadio : public ACommoLocalMessage
{
	GENERATED_BODY()
public:
	ACommoEventRadio();

	UPROPERTY()			int32 MsgStatic;						//var int MsgStatic;
	UPROPERTY()			int32 MsgMissionImpossible;				//var int MsgMissionImpossible;
	UPROPERTY()			int32 MsgTimeLimit;						//var int MsgTimeLimit;
	UPROPERTY()			int32 MsgEnemyDead;						//var int MsgEnemyDead;
	UPROPERTY()			int32 MsgSquadDead;						//var int MsgSquadDead;
	UPROPERTY()			int32 MsgMissionFailed;					//var int MsgMissionFailed;
	UPROPERTY()			int32 MsgMissionCompleted;				//var int MsgMissionCompleted;
	UPROPERTY()			int32 MsgFriendlyFire;					//var int MsgFriendlyFire;

	void GetAnim(int32 Switch);
	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
};
