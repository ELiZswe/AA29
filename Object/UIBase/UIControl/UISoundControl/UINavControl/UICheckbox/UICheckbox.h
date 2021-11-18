// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UICheckbox.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUICheckbox : public UUINavControl
{
	GENERATED_BODY()
public:
	UUICheckbox();


	UPROPERTY()										int32 _iState;							//var int _iState;
	UPROPERTY()										FString _sPropertyName;					//var string _sPropertyName;
	UPROPERTY()										FString _sClassName;					//var string _sClassName;
	UPROPERTY()										bool _bChecked;							//var bool _bChecked;
	UPROPERTY()										int32 _iLabelY;							//var int _iLabelY;
	UPROPERTY()										int32 _iLabelX;							//var int _iLabelX;
	UPROPERTY()										FString _sLabel;						//var string _sLabel;
	UPROPERTY()										FPosition _iTexDim;						//var UIBase.Position _iTexDim;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;


	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTextureDimensions(FPosition dim);
	void SetLabel(FString Label);
	void SetTexture(FString Tex);
	void Select(bool State);
	void SetClassName(FString ClassName);
	void SetPropertyName(FString PropName);
	bool IsSelected();
	void SetState(bool Checked);
	void Refresh();
	void Accept();
};
