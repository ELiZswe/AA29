// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "AA29/MyEnums.h"
#include "GUIScrollBarBase.generated.h"

class UGUIGripButtonBase;
class UGUIListBase;
class UGUIScrollZoneBase;
class UGUIScrollButtonBase;

UCLASS()
class AA29_API UGUIScrollBarBase : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIScrollBarBase();

	UPROPERTY(EditAnywhere)						EAA2Orientation				Orientation;				//var() GUI.EOrientation Orientation;
	UPROPERTY(EditAnywhere)						int32						Step;						//var() int32 Step;
	UPROPERTY()									float						GripPos;					//var float GripPos;
	UPROPERTY()									float						GripSize;					//var float GripSize;
	UPROPERTY()									float						GrabOffset;					//var float GrabOffset;
	UPROPERTY(EditAnywhere)						int32						MinGripPixels;				//var() int32 MinGripPixels;
	UPROPERTY()									UGUIListBase*				MyList;						//var GUIListBase MyList;
	UPROPERTY(EditAnywhere)						int32						BigStep;					//var() int32 BigStep;
	UPROPERTY(EditAnywhere)						int32						ItemCount;					//var() int32 ItemCount;
	UPROPERTY(EditAnywhere)						int32						ItemsPerPage;				//var() int32 ItemsPerPage;
	UPROPERTY()									int32						CurPos;						//var int32 CurPos;
	UPROPERTY(EditAnywhere)						UGUIScrollZoneBase*			MyScrollZone;				//var() automated GUIScrollZoneBase MyScrollZone;
	UPROPERTY(EditAnywhere)						UGUIScrollButtonBase*		MyIncreaseButton;			//var() automated GUIScrollButtonBase MyIncreaseButton;
	UPROPERTY(EditAnywhere)						UGUIScrollButtonBase*		MyDecreaseButton;			//var() automated GUIScrollButtonBase MyDecreaseButton;
	UPROPERTY(EditAnywhere)						UGUIGripButtonBase*			MyGripButton;				//var() automated  MyGripButton;

	void PositionChanged(int32 NewPos);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetList(UGUIListBase* List);
	void UpdateGripPosition(float NewPos);
	void MoveGripBy(int32 items);
	bool DecreaseClick(UGUIComponent* Sender);
	bool IncreaseClick(UGUIComponent* Sender);
	void WheelUp();
	void WheelDown();
	void AlignThumb();
	void Refocus(UGUIComponent* Who);
	bool GripPreDraw(UGUIComponent* Sender);
	void SetFriendlyLabel(UGUILabel* NewLabel);
};
