// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDCompassPoint/UIHUDCompassPoint.h"
#include "UIHUDCompassPointObj.generated.h"

class ABaseObjective;


UCLASS()
class AA29_API UUIHUDCompassPointObj : public UUIHUDCompassPoint
{
	GENERATED_BODY()
public:
	UUIHUDCompassPointObj();


	UPROPERTY()										FString _sSymbol;							//var string _sSymbol;
	UPROPERTY()										ABaseObjective* _Objective;					//var BaseObjective _Objective;


	void Destroyed();
	void setObjective(ABaseObjective* obj);
	void GetLocation();
	void IsOnCompass(AController* ctrlRequesting);
	void IsEnabled();
	void IsSquadTarget(int32 iTeamIndex);
	FString GetString();
	void isPriority();
	void SetText(FString txt);

};
