// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "MissionResultsFrame.generated.h"

class AScoreKeeper;
class UMissionResultDisplay;

UCLASS()
class UMissionResultsFrame : public UUIFrame
{
	GENERATED_BODY()
public:
	UMissionResultsFrame();

	UPROPERTY()			bool	_bPass;				//var bool _bPass;
	UPROPERTY()			bool	_bRestartScene;		//var bool _bRestartScene;
	UPROPERTY()			int32	temp_id;			//var int temp_id;

	void Notify(int32 pUIEvent);
	void Draw(UCanvas* Canvas);
	void Create(AAA2_HUD* pHUD);
	void SetMissionResultDisplay(FString mrd);
	UMissionResultDisplay* GetMissionResultDisplay();
	bool GetPlayerStatus();
	USoundBase* GetStatusSound();
	void SetScoreKeeper(AScoreKeeper* sk);
	bool ShouldRestartScene();
	bool DidPlayerPass();
};
