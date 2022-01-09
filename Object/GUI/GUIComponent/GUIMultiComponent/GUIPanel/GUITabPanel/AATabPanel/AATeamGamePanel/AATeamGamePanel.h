// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATabPanel.h"
#include "AATeamGamePanel.generated.h"

class ATeamInfo;
class AAGP_TeamInfo;

UCLASS()
class UAATeamGamePanel : public UAATabPanel
{
	GENERATED_BODY()
public:
	UAATeamGamePanel();

	UPROPERTY()			AAGP_TeamInfo* Team;		//var AGP_Gameplay.AGP_TeamInfo Team;

	void SetTeam(ATeamInfo* TI);
};
