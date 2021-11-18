// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "HUDCommoInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UHUDCommoInfo : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UHUDCommoInfo();


	UPROPERTY()										int32 _iMaxMessageSet;					//var int _iMaxMessageSet;
	UPROPERTY()										int32 _iMessageSet;						//var int _iMessageSet;
	UPROPERTY()										AAA2_WorldSettings* _Level;				//var LevelInfo _Level;
	UPROPERTY()										bool _bDrawMessages;					//var bool _bDrawMessages;
	UPROPERTY()										float _fEndTime;						//var float _fEndTime;
	UPROPERTY()										float _fStartTime;						//var float _fStartTime;
	UPROPERTY()										UMaterialInstance* _CommoTexture;		//var Texture _CommoTexture;

	void Destroyed();
	bool ShowingMessages();
	void ShowMessages(bool Show);
	void ShowNextMessageSet();
	int32 IndexToMessage(int32 Index);
	void DrawCommoAnswers(UCanvas* Canvas);
	void Draw(UCanvas* Canvas);
	void DrawIcon(UCanvas* Canvas);
	void DrawMessages(UCanvas* Canvas, float Alpha);

};
