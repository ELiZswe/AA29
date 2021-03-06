// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIListBase.h"
#include "GUICircularList.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UGUICircularList : public UGUIListBase
{
	GENERATED_BODY()
public:
	UGUICircularList();

	UPROPERTY()														bool bWrapItems;					//var() bool bWrapItems;
	UPROPERTY()														int32 FixedItemsPerPage;			//var() int FixedItemsPerPage;
	UPROPERTY()														bool bAllowSelectEmpty;				//var() bool bAllowSelectEmpty;
	UPROPERTY()														bool bIgnoreBackClick;				//var() bool bIgnoreBackClick;
	UPROPERTY()														bool bFillBounds;					//var() bool bFillBounds;
	UPROPERTY()														bool bCenterInBounds;				//var() bool bCenterInBounds;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	float CalculateOffset(float MouseX);
	int32 CalculateIndex(bool bRequireValidIndex);
	bool InternalOnClick(UGUIComponent* Sender);
	void WheelUp();
	void WheelDown();
	bool MoveLeft();
	bool MoveRight();
	void home();
	void End();
	void PgUp();
	void PgDown();
	bool IsValid();
	void InternalOnMousePressed(UGUIComponent* Sender, bool IsRepeat);
	void CheckDragSelect();
	void InternalOnDragOver(UGUIComponent* Sender);
};
