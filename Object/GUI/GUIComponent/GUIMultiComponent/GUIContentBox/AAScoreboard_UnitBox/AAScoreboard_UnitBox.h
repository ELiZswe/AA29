// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AAScoreboard_UnitBox.generated.h"

class AAGP_TeamInfo;
class UAAScoreboard_FireTeamList;
class UAAScoreboard_UnitBoxHeader;

UCLASS()
class AA29_API UAAScoreboard_UnitBox : public UGUIContentBox
{
	GENERATED_BODY()
public:
	UAAScoreboard_UnitBox();

	UPROPERTY()						AAGP_TeamInfo*							Team;						//var AGP_Gameplay.AGP_TeamInfo Team;
	UPROPERTY()						TArray<UAAScoreboard_FireTeamList*>		FireTeams;					//var array<AAScoreboard_FireTeamList> FireTeams;
	UPROPERTY(EditAnywhere)			FString									FireTeamListClass;			//var() string FireTeamListClass;
	UPROPERTY(EditAnywhere)			UAAScoreboard_UnitBoxHeader*			Header;						//var() AAScoreboard_UnitBoxHeader Header;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Timer();
	void InitFireTeams(AAGP_TeamInfo* NewTeam);
};
