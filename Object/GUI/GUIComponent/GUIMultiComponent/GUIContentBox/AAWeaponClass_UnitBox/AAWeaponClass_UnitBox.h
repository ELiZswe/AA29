// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AAWeaponClass_UnitBox.generated.h"

class AAGP_TeamInfo;
class UAAWeaponClass_FireTeamList;
class UAAWeaponClass_UnitBoxHeader;

UCLASS()
class AA29_API UAAWeaponClass_UnitBox : public UGUIContentBox
{
	GENERATED_BODY()
public:
	UAAWeaponClass_UnitBox();

	UPROPERTY(EditAnywhere)			AAGP_TeamInfo*							Team;					//var AGP_Gameplay.AGP_TeamInfo Team;
	UPROPERTY(EditAnywhere)			TArray<UAAWeaponClass_FireTeamList*>	FireTeams;				//var array<AAWeaponClass_FireTeamList> FireTeams;
	UPROPERTY(EditAnywhere)			FString									FireTeamListClass;		//var() string FireTeamListClass;
	UPROPERTY(EditAnywhere)			UAAWeaponClass_UnitBoxHeader*			Header;					//var() AAWeaponClass_UnitBoxHeader Header;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Timer();
	void InitFireTeams(AAGP_TeamInfo* NewTeam);

};
