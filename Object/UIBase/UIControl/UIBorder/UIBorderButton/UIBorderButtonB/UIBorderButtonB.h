// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorderButton/UIBorderButton.h"
#include "UIBorderButtonB.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIBorderButtonB : public UUIBorderButton
{
	GENERATED_BODY()
public:
	UUIBorderButtonB();

	UPROPERTY()						FString _sLabel2;						//var FString _sLabel2;
	UPROPERTY()						int32 _iLabel2X;						//var int32 _iLabel2X;
	UPROPERTY()						int32 _iLabel2Y;						//var int32 _iLabel2Y;
	UPROPERTY()						int32 _iLabelState;						//var int32 _iLabelState;
	UPROPERTY()						int32 _iUIEvent2;						//var int32 _iUIEvent2;

	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void ScaleControl(UCanvas* Canvas);
	void SetLabel2(FString Label);
	void SetEvent2(int32 event2);
};
