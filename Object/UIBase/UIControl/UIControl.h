// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIBase.h"
#include "UIControl.generated.h"

class UUIScreen;
class UUIFrame;
/**
 * 
 */
UCLASS()
class AA29_API UUIControl : public UUIBase
{
	GENERATED_BODY()
public:
	UUIControl();

	UPROPERTY()										bool bControlInitialized;				//var bool bControlInitialized;
	UPROPERTY()										int32 _iGroup;							//var int _iGroup;
	UPROPERTY()										FPosition _ScaledPos;					//var UIBase.Position _ScaledPos;
	UPROPERTY()										FString _sToolTip;						//var string _sToolTip;
	UPROPERTY()										bool _bEnabled;							//var bool _bEnabled;
	UPROPERTY()										bool _bButtonDown;						//var bool _bButtonDown;
	UPROPERTY()										bool _bCanHaveFocus;					//var bool _bCanHaveFocus;
	UPROPERTY()										bool _bFocus;							//var bool _bFocus;
	UPROPERTY()										int32 _iParams;							//var int _iParams;
	UPROPERTY()										int32 _iUIEvent;						//var int _iUIEvent;
	UPROPERTY()										UUIControl* cParentControl;				//var UIControl cParentControl;
	UPROPERTY()										UUIControl* cPrevControl;				//var UIControl cPrevControl;
	UPROPERTY()										UUIControl* cNextControl;				//var UIControl cNextControl;
	UPROPERTY()										UUIScreen* cScreen;						//var UIScreen cScreen;
	UPROPERTY()										UUIFrame* cFrame;						//var UIFrame cFrame;

	void Create(UUIFrame* frame, UUIScreen* screen, int32 pID, int32 pUIEvent, int32 pParams);
	void Destroyed();
	void CreateTexture();
	void ProcessParams();
	void Focus(bool bFocus);
	bool HasFocus();
	void CreateUIControl(FString ControlName);
	void ScaleControl(UCanvas* Canvas);
	void MouseMove(int32 mX, int32 mY);
	void NotifyParent(float Value);
	void ChildMessage(float Value);
	void SetParent(UUIControl* Control);
	void SetAllowScaling(bool Scaling);
	bool GetAllowScaling();
	void SetEnabled(bool Enabled);
	bool IsEnabled();
	void SetTooltip(FString sToolTip);
	FString GetToolTip();
	void SetGroupID(int32 Id);
	int32 GetGroupID();
	void Select(bool State);
	void IsSelected();
	void Tick(float DeltaTime);

};
