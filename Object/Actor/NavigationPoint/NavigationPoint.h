// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "NavigationPoint.generated.h"

UCLASS()
class AA29_API ANavigationPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANavigationPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY()															ADebugNavigation* dnpcnDebugNavigationMarker;		//var DebugNavigation dnpcnDebugNavigationMarker;
	UPROPERTY()																TArray<ANavigationPoint*>	IgnoredList;			//var array<NavigationPoint> IgnoredList;
	UPROPERTY(EditAnywhere)													bool bVehiclesCanUse;								//var() bool bVehiclesCanUse;
	UPROPERTY()																bool bQuerySpecialCost;								//var bool bQuerySpecialCost;
	UPROPERTY(EditAnywhere, Category = "PostureCost")						float CrawlCost;									//var(PostureCost) float CrawlCost;
	UPROPERTY(EditAnywhere, Category = "PostureCost")						bool bCrawlOnly;									//var(PostureCost) bool bCrawlOnly;
	UPROPERTY(EditAnywhere, Category = "PostureCost")						float CrouchCost;									//var(PostureCost) float CrouchCost;
	UPROPERTY(EditAnywhere, Category = "PostureCost")						bool bCrouchOnly;									//var(PostureCost) bool bCrouchOnly;
	UPROPERTY(EditAnywhere)													float ScoutExtentMultiplier;						//var() float ScoutExtentMultiplier;
	UPROPERTY(EditAnywhere)													bool bScoutExtentTrace;								//var() bool bScoutExtentTrace;
	UPROPERTY()																FVector vFloor;										//var FVector vFloor;
	UPROPERTY()																FVector MaxPathSize;								//var FVector MaxPathSize;
	UPROPERTY()																TArray<float> BaseDist;								//var float BaseDist;
	UPROPERTY()																TArray<uint8> BaseVisible;							//var byte BaseVisible;
	UPROPERTY()																float LastDetourWeight;								//var const float LastDetourWeight;
	UPROPERTY()																float InventoryDist;								//var float InventoryDist;
	UPROPERTY()																APickup* InventoryCache;							//var Pickup InventoryCache;
	UPROPERTY()																int32 FearCost;										//var transient int FearCost;
	UPROPERTY()																int32 TransientCost;								//var transient int TransientCost;
	UPROPERTY(EditAnywhere)													int32 ExtraCost;									//var() int ExtraCost;
	UPROPERTY()																int32 cost;											//var int cost;
	UPROPERTY()																ANavigationPoint* previousPath;						//var const NavigationPoint previousPath;
	UPROPERTY()																ANavigationPoint* prevOrdered;						//var const NavigationPoint prevOrdered;
	UPROPERTY()																ANavigationPoint* nextOrdered;						//var const NavigationPoint nextOrdered;
	UPROPERTY()																ANavigationPoint* nextNavigationPoint;				//var const NavigationPoint nextNavigationPoint;
	UPROPERTY()																int32 bestPathWeight;								//var const int bestPathWeight;
	UPROPERTY()																int32 visitedWeight;								//var int visitedWeight;
	UPROPERTY(EditAnywhere)													TArray<FName> ForcedPaths;							//var() array<name> ForcedPaths;
	UPROPERTY(EditAnywhere)													TArray<FName> ProscribedPaths;						//var() array<name> ProscribedPaths;
	//UPROPERTY()															TArray<AReachSpec> PathList;						//var const array<ReachSpec> PathList;
	UPROPERTY()																bool bForcedOnly;									//var bool bForcedOnly;
	UPROPERTY(EditAnywhere)													bool bNoSuperSize;									//var() bool bNoSuperSize;
	UPROPERTY(EditAnywhere)													bool bMakeSourceOnly;								//var() bool bMakeSourceOnly;
	UPROPERTY(EditAnywhere)													bool bVehicleDestination;							//var() bool bVehicleDestination;
	UPROPERTY()																bool bAlreadyVisited;								//var bool bAlreadyVisited;
	UPROPERTY()																bool bReceivePlayerToucherDiedNotify;				//var bool bReceivePlayerToucherDiedNotify;
	UPROPERTY()																bool bMayCausePain;									//var bool bMayCausePain;
	UPROPERTY()																bool bFlyingPreferred;								//var bool bFlyingPreferred;
	UPROPERTY()																bool bBlockable;									//var bool bBlockable;
	UPROPERTY()																bool bMustBeReachable;								//var bool bMustBeReachable;
	UPROPERTY()																bool bSpecialForced;								//var bool bSpecialForced;
	UPROPERTY()																bool bSourceOnly;									//var bool bSourceOnly;
	UPROPERTY()																bool bDestinationOnly;								//var bool bDestinationOnly;
	UPROPERTY()																bool bPathsChanged;									//var const bool bPathsChanged;
	UPROPERTY()																bool bNotBased;										//var const bool bNotBased;
	UPROPERTY(EditAnywhere)													bool bNoAutoConnect;								//var() bool bNoAutoConnect;
	UPROPERTY()																bool bSpecialMove;									//var bool bSpecialMove;
	UPROPERTY()																bool bAutoBuilt;									//var const bool bAutoBuilt;
	UPROPERTY()																bool bForceNoStrafing;								//var const bool bForceNoStrafing;
	UPROPERTY(EditAnywhere)													bool bAlwaysUseStrafing;							//var() bool bAlwaysUseStrafing;
	UPROPERTY(EditAnywhere)													bool bNeverUseStrafing;								//var() bool bNeverUseStrafing;
	UPROPERTY(EditAnywhere)													bool bOneWayPath;									//var() bool bOneWayPath;
	UPROPERTY(EditAnywhere)													bool bPropagatesSound;								//var() bool bPropagatesSound;
	UPROPERTY(EditAnywhere)													bool bBlocked;										//var() bool bBlocked;
	UPROPERTY()																bool taken;											//var bool taken;
	UPROPERTY()																bool bCanReach;										//var transient bool bCanReach;
	UPROPERTY()																bool bHideEditorPaths;								//var transient bool bHideEditorPaths;
	UPROPERTY()																bool bTransientEndPoint;							//var transient bool bTransientEndPoint;
	UPROPERTY()																bool bEndPoint;										//var transient bool bEndPoint;

	UPROPERTY()																USceneComponent* Root;
	UPROPERTY()																UTexture2D* Texture;
	UPROPERTY()																UBillboardComponent* SpriteComponent;


	void PostBeginPlay();
	//int32 SpecialCost(APawn* Seeker, AReachSpec* Path);
	void SetBaseDistance(int32 BaseNum);
	void SetBaseVisibility(int32 BaseNum);
	bool Accept(AActor* Incoming, AActor* Source);
	float DetourWeight(APawn* Other, float PathWeight);
	bool SuggestMovePreparation(APawn* Other);
	bool ProceedWithMove(APawn* Other);
	void MoverOpened();
	void MoverClosed();
	void PlayerToucherDied(APawn* p);
	FVector GetStartLocation();
	FRotator GetStartRotation();
	void DebugNavMarker(bool bShowMarker, bool bFinalGoalMarker);

	void LoadEditorIcon();

	//From Actor:
	AActor* SpecialHandling(APawn* Other);
};
