// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UISliderSeg.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUISliderSeg : public UUINavControl
{
	GENERATED_BODY()
public:
	UUISliderSeg();


	//const kSliderSize = 244;

	UPROPERTY()										TArray<FString> _sVideoLevel;		//var string _sVideoLevel;
	UPROPERTY()										int32 _iCurrSegment;				//var int _iCurrSegment;
	UPROPERTY()										int32 _iSegSize;					//var int _iSegSize;
	UPROPERTY()										int32 _iMaxSegment;					//var int _iMaxSegment;
	UPROPERTY()										int32 _iNumSegments;				//var int _iNumSegments;
	UPROPERTY()										int32 _iState;						//var int _iState;
	UPROPERTY()										int32 _iMouseDragOffset;			//var int _iMouseDragOffset;
	UPROPERTY()										FString _sPropertyName;				//var string _sPropertyName;
	UPROPERTY()										FString _sClassName;				//var string _sClassName;
	UPROPERTY()										FString _sLabel;					//var string _sLabel;
	UPROPERTY()										FPosition _TexDimThumb;				//var UIBase.Position _TexDimThumb;
	UPROPERTY()										FPosition _TexDimBack;				//var UIBase.Position _TexDimBack;
	UPROPERTY()										UMaterialInstance* _Texture;		//var Texture _Texture;
	UPROPERTY()										int32 _iThumbSize;					//var int _iThumbSize;
	UPROPERTY()										int32 _iThumbPos;					//var int _iThumbPos;
	UPROPERTY()										FPosition _ScaledThumbPos;			//var UIBase.Position _ScaledThumbPos;
	UPROPERTY()										FPosition _iGro_ThumbPosup;			//var UIBase.Position _ThumbPos;


	void Create(UUIFrame* frame, UUIScreen* screen, int32 pID, int32 pUIEvent, int32 pParams);
	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTexture(FString Tex);
	void SetTexDimBack(FPosition dim);
	void SetTexDimThumb(FPosition dim);
	void SetLabel(FString Label);
	void Inc();
	void Dec();
	void SetClassName(FString ClassName);
	void SetPropertyName(FString PropName);
	void Refresh();
	void Accept();
	void UpdateValue();
	int32 GetCurrentSegment();
	void SetCurrentSegment(int32 seg);
	void SetNumSegments(int32 seg);
	void UpdatePosition(int32 pos);
	FString GetVideoLevelString();
	int32 GetVideoLevelInt();
	void SetVideoLevelString(FString sLevel);
	void SetVideoLevelInt(int32 iLevel);

};
