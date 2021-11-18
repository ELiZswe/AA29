// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARecordBriefSubPanel/AARecordBriefSubPanel.h"
#include "AARecordBrief_Badges.generated.h"

class UAAGUILabel;
class UGUIImageButton;
class UGUILabel;

UCLASS()
class AA29_API UAARecordBrief_Badges : public UAARecordBriefSubPanel
{
	GENERATED_BODY()
public:
	UAARecordBrief_Badges();

	UPROPERTY(EditAnywhere)			UAAGUILabel* lXPLabel;						//var() automated AAGUILabel lXPLabel;
	UPROPERTY(EditAnywhere)			UAAGUILabel* lTogo;							//var() automated AAGUILabel lTogo;
	UPROPERTY(EditAnywhere)			UGUIImageButton* ibRifleBadge;				//var() automated GUIImageButton ibRifleBadge;
	UPROPERTY(EditAnywhere)			UGUILabel* lRifleLabel;						//var() automated XInterface.GUILabel lRifleLabel;
	UPROPERTY(EditAnywhere)			UGUIImageButton* ibExpertInfantryBadge;		//var() automated GUIImageButton ibExpertInfantryBadge;
	UPROPERTY(EditAnywhere)			UGUILabel* lExpertInfantryLabel;			//var() automated XInterface.GUILabel lExpertInfantryLabel;
	UPROPERTY(EditAnywhere)			UGUIImageButton* ibDriverBadge;				//var() automated GUIImageButton ibDriverBadge;
	UPROPERTY(EditAnywhere)			UGUILabel* lDriverLabel;					//var() automated XInterface.GUILabel lDriverLabel;
	UPROPERTY(EditAnywhere)			UGUIImageButton* ibCombatMedicBadge;		//var() automated GUIImageButton ibCombatMedicBadge;
	UPROPERTY(EditAnywhere)			UGUILabel* lCombatMedicLabel;				//var() automated XInterface.GUILabel lCombatMedicLabel;
	UPROPERTY(EditAnywhere)			UGUIImageButton* ibAirborneBadge;			//var() automated GUIImageButton ibAirborneBadge;
	UPROPERTY(EditAnywhere)			UGUILabel* lAirborneLabel;					//var() automated XInterface.GUILabel lAirborneLabel;
	UPROPERTY(EditAnywhere)			UGUIImageButton* ibSFBadge;					//var() automated GUIImageButton ibSFBadge;
	UPROPERTY(EditAnywhere)			UGUILabel* lSFLabel;						//var() automated XInterface.GUILabel lSFLabel;
	UPROPERTY()						int32 iRifleQualification;					//var int32 iRifleQualification;
	UPROPERTY()						int32 iExpertInfantryQualification;			//var int32 iExpertInfantryQualification;
	UPROPERTY()						int32 iDriverQualification;					//var int32 iDriverQualification;
	UPROPERTY()						int32 iCombatMedicQualification;			//var int32 iCombatMedicQualification;
	UPROPERTY()						int32 iAirborneQualification;				//var int32 iAirborneQualification;
	UPROPERTY()						int32 iSFQualification;						//var int32 iSFQualification;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	int32 RifleQualification();
	int32 BCTQualification();
	int32 AdvMarksmanQualification();
	int32 EIBQualification();
	int32 DriverQualification();
	int32 MedicQualification();
	int32 AirborneQualification();
	int32 SFQualification();
	void CreateBadges();
	bool BadgeClick(UGUIComponent* Sender);
};
