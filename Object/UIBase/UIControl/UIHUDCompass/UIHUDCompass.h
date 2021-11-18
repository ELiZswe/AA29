// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIHUDCompass.generated.h"

class UUIControl;
class UUIHUDCompassPointV;
class UUIHUDCompassPointObj;
class UUIHUDCompassPoint;

UCLASS()
class AA29_API UUIHUDCompass : public UUIControl
{
	GENERATED_BODY()
public:
	UUIHUDCompass();

	//const kMaxObjectives = 8;
	//const kArrowDeadRange = 132;
	//const kObjectiveArrowScaleX = 0.5;
	//const kObjectiveSize = 16;
	//const kObjectiveTextY = 112;
	//const kObjectiveTextX = 786;
	//const kLocationTextY = 82;
	//const kLocationTextX = 786;
	//const kCompassTextureWidth = 1024;
	//const kCompassY = 16;
	//const kCompassHeight = 32;
	//const kCompassWidth = 512;


	UPROPERTY()										bool _bIsSettingTarget;						//var bool _bIsSettingTarget;
	UPROPERTY()										UMaterialInstance* _tTeamIF;				//var Texture _tTeamIF;
	UPROPERTY()										UMaterialInstance* _tTeamSSG1st;			//var Texture _tTeamSSG1st;
	UPROPERTY()										UMaterialInstance* _tTeamSFCapt;			//var Texture _tTeamSFCapt;
	UPROPERTY()										UMaterialInstance* _tTeamIFVIP;				//var Texture _tTeamIFVIP;
	UPROPERTY()										TArray<UMaterialInstance*> _tFT;					//var Texture _tFT;
	UPROPERTY()										UMaterialInstance* _tTeamBleed;				//var Material _tTeamBleed;
	UPROPERTY()										UMaterialInstance* _tTeamMedic;				//var Texture _tTeamMedic;
	UPROPERTY()										UMaterialInstance* _tTeamPVT;				//var Texture _tTeamPVT;
	UPROPERTY()										UMaterialInstance* _tTeamSGT;				//var Texture _tTeamSGT;
	UPROPERTY()										UMaterialInstance* _tTeamSSG;				//var Texture _tTeamSSG;
	UPROPERTY()										UUIHUDCompassPointV* _TeamPoint;			//var UIHUDCompassPointV _TeamPoint;
	UPROPERTY()										UUIHUDCompassPointObj* _Objectives;			//var UIHUDCompassPointObj _Objectives;
	UPROPERTY()										UMaterialInstance* _tObjectiveLevel;		//var Texture _tObjectiveLevel;
	UPROPERTY()										UMaterialInstance* _tObjectiveDown;			//var Texture _tObjectiveDown;
	UPROPERTY()										UMaterialInstance* _tObjectiveUp;			//var Texture _tObjectiveUp;
	UPROPERTY()										TArray<FString> _sObjectiveSymbols;					//var string _sObjectiveSymbols;
	UPROPERTY()										TArray<UMaterialInstance*> _tObjectiveSymbols;		//var Texture _tObjectiveSymbols;
	UPROPERTY()										bool _InitializedObjectives;				//var bool _InitializedObjectives;
	UPROPERTY()										UUIControl* _ElementList;					//var UIControl _ElementList;
	UPROPERTY()										UMaterialInstance* _BracketTexture;			//var Texture _BracketTexture;
	UPROPERTY()										UMaterialInstance* _tRight;					//var Texture _tRight;
	UPROPERTY()										UMaterialInstance* _tLeft;					//var Texture _tLeft;
	UPROPERTY()										int32 ScaledObjectiveTextY;					//var int ScaledObjectiveTextY;
	UPROPERTY()										int32 ScaledObjectiveTextX;					//var int ScaledObjectiveTextX;


	void Destroyed();
	bool IsSettingTarget();
	void SetTarget(bool E);
	void Draw(UCanvas* Canvas);
	void InitializeObjectives();
	void DrawCompass(UCanvas* Canvas);
	void DrawLocation(UCanvas* Canvas);
	void DrawObjectives(UCanvas* Canvas);
	void ScaleControl(UCanvas* Canvas);
	void DrawObjectiveList(UCanvas* Canvas);
	void DrawCompassPoint(UUIHUDCompassPoint* currentpoint, UCanvas* Canvas);
	void DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* Player, UMaterialInstance* Icon);
	void GetPlayerIcon(AAA2_PlayerState* myPRI, AAA2_PlayerState* otherPRI);
	void DrawTeam(UCanvas* Canvas);
	void SetTexture(UMaterialInstance* pleft);
	void SetBracketTexture(UMaterialInstance* Tex);
	bool ShouldDrawCompass();
	bool ShouldDrawLocation();
	void ShouldDrawObjectiveList();
	UUIControl* GetLastControl();
	void AddControlToTail(UUIControl* Control);
	UUIControl* GetControl(int32 Id);
	bool EnableControl(int32 Id, bool State);

};
