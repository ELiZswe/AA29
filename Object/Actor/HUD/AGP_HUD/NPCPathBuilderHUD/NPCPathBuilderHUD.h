// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "NPCPathBuilderHUD.generated.h"

class ANPCPathNodeBuilder;

class ANavigationPoint;
UCLASS()
class ANPCPathBuilderHUD : public AAGP_HUD
{
	GENERATED_BODY()
public:
	ANPCPathBuilderHUD(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()			ANPCPathNodeBuilder*		npcpnbActivePathBuilder;				//var NPCPathNodeBuilder npcpnbActivePathBuilder;
	UPROPERTY()			ANavigationPoint*			npCachedForcedPathsSourceNode;			//var NavigationPoint npCachedForcedPathsSourceNode;
	UPROPERTY()			TArray<ANavigationPoint*>	anpCachedForcedPathNodes;				//var TArray<NavigationPoint> anpCachedForcedPathNodes;
	UPROPERTY()			FColor						colorTitle;								//var Color colorTitle;
	UPROPERTY()			FColor						 colorActiveOption;						//var Color colorActiveOption;
	UPROPERTY()			FColor						 colorInactiveOption;					//var Color colorInactiveOption;
	UPROPERTY()			FColor						 colorMenuFlyover;						//var Color colorMenuFlyover;
	UPROPERTY()			FColor						 colorPathTestLeft;						//var Color colorPathTestLeft;
	UPROPERTY()			FColor						 colorPathTestMiddle;					//var Color colorPathTestMiddle;
	UPROPERTY()			FColor						 colorPathTestRight;					//var Color colorPathTestRight;
	UPROPERTY()			TArray<int32>				 aiLineTestLeftValid;					//var int32 aiLineTestLeftValid[50];
	UPROPERTY()			TArray<int32>				 aiLineTestRightValid;					//var int32 aiLineTestRightValid[50];
	UPROPERTY()			TArray<FVector>				 avMenuItems;							//var Vector avMenuItems[20];
	UPROPERTY()			TArray<FVector>				 avMenuItemsDimensions;					//var Vector avMenuItemsDimensions[20];
	UPROPERTY()			TArray<FString>				 asMenuIconDescriptions;				//var FString asMenuIconDescriptions[20];

	void DrawHUD();
	void DrawIconMenu(UCanvas* Canvas);
	void WorldSpaceOverlays();
	ANavigationPoint* GetNavigationPointFromName(FName nameToFind);
	void DrawHUDText(UCanvas* Canvas, FString sText, float fpScaledX, float fpScaledY, FColor colorText, ETextHorzAlignment thaAlignment);
	void DrawHUDTextUnscaled(UCanvas* Canvas, FString sText, float fpX, float fpY, FColor colorText);
	void DrawHUDMenuIcon(UCanvas* Canvas, UMaterialInstance* txtToDraw, float fpScaledX, float fpScaledY, int32 iMenuItemIndex);
	int32 DetermineIconIndexClicked(int32 ix, int32 iY);
};
