// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "StudentController.generated.h"

class ANPCPathNodeBuilder;
class ANPCVAERecruiterController;
class ALadderVolume;
class AAGP_UseTrigger;

UCLASS()
class AStudentController : public AHumanController
{
	GENERATED_BODY()
public:
	AStudentController();

	UPROPERTY()			bool							bUsedCheats;							//var bool bUsedCheats;
	UPROPERTY()			bool							bSeated;								//var bool bSeated;
	UPROPERTY()			bool							bForceSit;								//var bool bForceSit;
	UPROPERTY()			AActor*							_AutoTraceHitActor;						//var Actor _AutoTraceHitActor;
	UPROPERTY()			bool							bFieldSkipIntro;						//var config bool bFieldSkipIntro;
	UPROPERTY()			AActor*							MyExam;									//var Actor MyExam;
	UPROPERTY()			bool							bPossiblyCheating;						//var bool bPossiblyCheating;
	UPROPERTY()			FName							SittingState;							//var FName SittingState;
	UPROPERTY()			bool							bSkipSlides;							//var bool bSkipSlides;
	UPROPERTY(config)	int32							GDC;									//var config int32 GDC;
	UPROPERTY()			int32							iLastRealHeroVisited;					//var int32 iLastRealHeroVisited;
	UPROPERTY()			ANPCPathNodeBuilder*			npcpnbPathNodeBuilder;					//var NPCPathNodeBuilder npcpnbPathNodeBuilder;
	UPROPERTY()			uint8							bNPCPBForceDrop;						//var input uint8 bNPCPBForceDrop;
	UPROPERTY()			uint8							bNPCPBMenuToggle;						//var input uint8 bNPCPBMenuToggle;
	UPROPERTY()			bool							bHasLanyard;							//var bool bHasLanyard;
	UPROPERTY()			float							fpVAETimeLanyardTaken;					//var float fpVAETimeLanyardTaken;
	UPROPERTY()			float							fpVAETimeLanyardReturned;				//var float fpVAETimeLanyardReturned;
	UPROPERTY()			float							fpVAETotalLevelTime;					//var float fpVAETotalLevelTime;
	UPROPERTY()			float							fpVAETimeEnteredAAR;					//var float fpVAETimeEnteredAAR;
	UPROPERTY()			float							fpVAETimeExitedAAR;						//var float fpVAETimeExitedAAR;
	UPROPERTY()			float							fpVAETimeEnteredFloor;					//var float fpVAETimeEnteredFloor;
	UPROPERTY()			float							fpVAETimeExitedFloor;					//var float fpVAETimeExitedFloor;
	UPROPERTY()			float							fpVAETimeStartedViewingPoster;			//var float fpVAETimeStartedViewingPoster;
	UPROPERTY()			float							fpVAETimeStoppedViewingPoster;			//var float fpVAETimeStoppedViewingPoster;
	UPROPERTY()			ANPCVAERecruiterController*		npcvrcActive;							//var NPCVAERecruiterController npcvrcActive;
	UPROPERTY()			AActor*							actVAELastViewed;						//var Actor actVAELastViewed;
	UPROPERTY()			UMaterialInstance*				matVAELastViewed;						//var Material matVAELastViewed;
	UPROPERTY()			TArray<FVAEPosterViewingInfo>	avaepviPosterTracking;					//var TArray<VAEPosterViewingInfo> avaepviPosterTracking;

	UMaterialInstance* LoadVRSPosterTextureFromDDS(FString FilePath);
	bool IsCheating();
	bool IsSeated();
	bool IsPossiblyCheating();
	bool SkipSlides();
	void Grenade(uint8 Index);
	void DevMode(bool bSet);
	void MPCheat(FString cheat);
	void PreBeginPlay();
	void PostBeginPlay();
	void CustomSetupTimer();
	void Suicide();
	void Timer();
	void ETAJoinServer(FString sServerIP, FString sSurName, FString sNickName, FString sPassword);
	void ETARestoreUserName();
	void ClientMessage(FString S, FName Type);
	void FieldSkipIntro();
	void TrainingSkipSlides();
	void DebugSpawnNodeTester(bool bShowPathMarkers, FString sNavTag);
	void Help();
	void NPCPathBuilderHelp();
	void StartNPCPathBuilder();
	void PNBTogglePaths();
	void SavePaths(FString sFileName);
	void BuildMapWithPaths(FString sFileName);
	void TestPaths();
	void LoadPaths(FString sFileName);
	void SetCurrentPlayerStartName(FString sNewName);
	void SetCurrentNodeTag(FString sNewTag);
	void StopNPCPathBuilder();
	void DropPathNode();
	void DropRoadNode();
	void DropCustomPathNode(FString sType);
	void StartPatrolPath(FString sWaypointNavTag);
	void EndPatrolPath();
	void DropWaypointPathNode();
	void DeletePathNode();
	void StartAutoDropMode();
	void ToggleAutoDropMode();
	void StopAutoDropMode();
	void EditPathNode();
	void Fire(float F);
	void ManNodePosition();
	void ImportPaths();
	void Action();
	void ChangePostureAndRotation();
	void ResetPaths();
	void ForceConnection();
	void EditSelected();
	void StartClimbingLadder(ALadderVolume* lvLadder);
	void EndClimbingLadder(ALadderVolume* lvLadder);
	void ClientCloseMenu(bool bCloseAll, bool bCancel);
	void PNB();
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void AutoTrace();
	void VAEUpdatePoster(FString sPosterMaterial, float fpTimeViewed);
	void ShowMenu();
	void SwapAllPosters();
	void SwapPoster(AAGP_UseTrigger* agpturl);

};
