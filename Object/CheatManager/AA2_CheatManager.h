// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA2_CheatManager.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAA2_CheatManager : public UObject
{
	GENERATED_BODY()
public:
	UAA2_CheatManager();

	UPROPERTY()								FRotator	LockedRotation;					//var Rotator LockedRotation;
	UPROPERTY()								bool		bCheatsEnabled;					//var bool bCheatsEnabled;


	void ReviewJumpSpots(FName TestLabel);
	void ListDynamicActors();
	void FreezeFrame(float Delay);
	void WriteToLog(FString Param);
	void SetFlash(float F);
	void SetFogR(float F);
	void SetFogG(float F);
	void SetFogB(float F);
	void KillViewedActor();
	void LogScriptedSequences();
	void Teleport();
	void ChangeSize(float F);
	void LockCamera();
	void SetCameraDist(float F);
	void EndPath();
	void FreeCamera(bool B);
	void CauseEvent(FName EventName);
	void Amphibious();
	void Fly();
	void Walk();
	void Ghost();
	void AllAmmo();
	void Invisible(bool B);
	void Phil();
	void God();
	void SloMo(float t);
	void SetJumpZ(float F);
	void SetGravity(float F);
	void SetSpeed(float F);
	void KillPawns();
	void Avatar(FString ClassName);
	void SummonNPCSoldier();
	void Summon(FString ClassName);
	void PlayersOnly();
	void FreezeAll();
	void ClearAllDebugLines();
	void RememberSpot();
	void ViewSelf(bool bQuiet);
	void ViewPlayer(FString S);
	void ViewActor(FName ActorName);
	void ViewFlag();
	void ViewBot();
	void ViewTurret();
	void EnableDebugView();
	void FocusOn(AActor* aClass, bool bQuiet);
	void FocusOnName(FName ActorName);
	void FocusOnTaggedPawn(FName TagName);
	void FocusOnNamedPawn(FName nameName);
	void FocusOnTargetedPawn(APawn* pawnTarget);
	void FocusOnTag(FName TagName);
	void FocusOnPawn();
	void FocusOnAIVehicle();
	void FocusClass(AActor* aClass, bool bQuiet, FName TagName, FName ActorName, bool bAIOnly);
	void FocusOff();
	void ViewClass(AActor* aClass, bool bQuiet, bool bCheat);
	void Loaded();
	void AllWeapons();
	void SkipMatch();
	void JumpMatch(int32 ladderrung);
	void WinMatch();
	void EnableCheats();
	bool areCheatsEnabled();
	void ReportCheat(FString cheat);
	void WeakObjectives();
	void DisableNextObjective();
	void ruler();
};
