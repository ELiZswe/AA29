// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "MissionResultsFrame.generated.h"

class AScoreKeeper;

UCLASS()
class AA29_API UMissionResultsFrame : public UUIFrame
{
	GENERATED_BODY()
public:
	UMissionResultsFrame();

	/*
	const UIE_None = 0;
	const UIE_Retry = 1;
	const UIE_OK = 2;
	const SID_Main = 0;
	const ID_None = 0;
	const ID_Border = 1;
	const ID_Retry = 2;
	const ID_OK = 3;
	const ID_Results = 4;
	*/

	UPROPERTY()										bool _bPass;						//var bool _bPass;
	UPROPERTY()										bool _bRestartScene;				//var bool _bRestartScene;
	UPROPERTY()										int32 temp_id;						//var int temp_id;

	void Notify(int32 pUIEvent);
	void Draw(UCanvas* Canvas);
	void Create(AHUD* pHUD);
	void SetMissionResultDisplay(FString mrd);
	void GetMissionResultDisplay();
	bool GetPlayerStatus();
	USoundBase* GetStatusSound();
	void SetScoreKeeper(AScoreKeeper* sk);
	bool ShouldRestartScene();
	bool DidPlayerPass();

};
