// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UIKeymap.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIKeymap : public UUINavControl
{
	GENERATED_BODY()
public:
	UUIKeymap();

	UPROPERTY()										FString _sAltKey;						//var string _sAltKey;
	UPROPERTY()										FString _sKey;							//var string _sKey;
	UPROPERTY()										int32 _iAltKey;							//var int _iAltKey;
	UPROPERTY()										int32 _iKey;							//var int _iKey;
	UPROPERTY()										FString _sCommand;						//var string _sCommand;
	UPROPERTY()										FString _sLabel;						//var string _sLabel;
	UPROPERTY()										FPosition _iTexDim;						//var UIBase.Position _iTexDim;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;
	UPROPERTY()										bool _bShiftDown;						//var bool _bShiftDown;
	UPROPERTY()										bool _bEdit;							//var bool _bEdit;
	UPROPERTY()										int32 _iState;							//var int _iState;

	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void SetInputKey(int32 Index, int32 Key);
	void UnbindKeys();
	void SetInputKeyPrivate(int32 Key);
	int32 GetInputKey();
	FString GetLowerCase(FString upper);
	void Focus(bool bFocus);
	void Draw(UCanvas* Canvas);
	void SetTexture(FString Tex);
	void SetTextureDimensions(FPosition dim);
	void SetCommand(FString Command);
	void SetLabel(FString Label);
	void UnbindSpecificKey(int32 Key, FString Command);
	FString GetCommand();
};
