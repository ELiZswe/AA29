// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIContentPanel/GUIContentPanel.h"
#include "AAGUIBadgeDescription.generated.h"

class UAAGUILabel;
class UGUIContentBox;
class UGUIImage;

UCLASS()
class AA29_API UAAGUIBadgeDescription : public UGUIContentPanel
{
	GENERATED_BODY()
public:
	UAAGUIBadgeDescription();

	UPROPERTY()								int32					CurrentBadgeIndex;				//var int CurrentBadgeIndex;
	UPROPERTY()								int32					InitialBadgeIndex;				//var int InitialBadgeIndex;
	UPROPERTY()								TArray<FBadge>			Badges;							//var array<Badge> Badges;
	UPROPERTY()								FString					MenuParam2;						//var string MenuParam2;
	UPROPERTY()								FString					MenuParam1;						//var string MenuParam1;
	UPROPERTY()								FString					MenuPath;						//var string MenuPath;
	UPROPERTY()								UAAGUILabel*			l_BadgeDescription;				//var AAGUILabel l_BadgeDescription;
	UPROPERTY()								UAAGUILabel*			l_BadgeName;					//var AAGUILabel l_BadgeName;
	UPROPERTY()								UGUIContentBox*			DescriptionBox;					//var GUIContentBox DescriptionBox;
	UPROPERTY()								UGUIImage*				i_BadgeImage;					//var XInterface.GUIImage i_BadgeImage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void ShowMenu();
	bool MyPreDraw(UCanvas* Canvas);
	int32 FindBadgeIndex(FString BadgeToDescribe);
	void DescribeBadge(FString BadgeToDescribe, bool bForceLoad);
	FString RemoveArrows(FString InputName);
	void DescribeBadgeByIndex(int32 BadgeIndex, bool bForceLoad);
};
