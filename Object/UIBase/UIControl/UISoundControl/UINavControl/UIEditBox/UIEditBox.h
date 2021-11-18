// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UIEditBox.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIEditBox : public UUINavControl
{
	GENERATED_BODY()
public:
	UUIEditBox();


	//const kBorderSize = 1;


	UPROPERTY()										int32 MaxLength;								//var int MaxLength;
	UPROPERTY()										int32 CaretOffset;								//var int CaretOffset;
	UPROPERTY()										bool _bShiftDown;								//var bool _bShiftDown;
	UPROPERTY()										bool _bSecret;									//var bool _bSecret;
	UPROPERTY()										bool _bShowCaret;								//var bool _bShowCaret;
	UPROPERTY()										bool _bEdit;									//var bool _bEdit;
	UPROPERTY()										float _fLastDrawTime;							//var float _fLastDrawTime;
	UPROPERTY()										int32 _iState;									//var int _iState;
	UPROPERTY()										int32 _iLabelY;									//var int _iLabelY;
	UPROPERTY()										int32 _iLabelX;									//var int _iLabelX;
	UPROPERTY()										FString _sSecret;								//var string _sSecret;
	UPROPERTY()										FString _sLabel;								//var string _sLabel;
	UPROPERTY()										bool _bDrawBack;								//var bool _bDrawBack;
	UPROPERTY()										FPosition _BorderBottom;						//var UIBase.Position _BorderBottom;
	UPROPERTY()										FPosition _BorderTop;							//var UIBase.Position _BorderTop;
	UPROPERTY()										FPosition _BorderRight;							//var UIBase.Position _BorderRight;
	UPROPERTY()										FPosition _BorderLeft;							//var UIBase.Position _BorderLeft;
	UPROPERTY()										FPosition _iTexDim;								//var UIBase.Position _iTexDim;
	UPROPERTY()										FPosition _BackDim;								//var UIBase.Position _BackDim;
	UPROPERTY()										UMaterialInstance* _BackTexture;				//var Texture _BackTexture;
	UPROPERTY()										UMaterialInstance* _BorderTexture;				//var Texture _BorderTexture;

	void Destroyed();
	void ProcessParams();
	void MouseMove(int32 mX, int32 mY);
	bool KeyType(int32 Key);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	bool Backspace();
	bool Insert(uint8 C);
	FString GetLowerCase(FString upper);
	void Focus(bool bFocus);
	void Draw(UCanvas* Canvas);
	void GetLastDrawTime();
	void SetLabel(FString Label);
	FString GetLabel();
	void SetMaxLength(int32 Len);

};
