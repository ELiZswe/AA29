// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIListbox.generated.h"

class UUIScrollbar;

UCLASS()
class UUIListbox : public UUIControl
{
	GENERATED_BODY()
public:
	UUIListbox();

	UPROPERTY()				UUIScrollbar*		cScrollV;			//var UIScrollbar cScrollV;
	UPROPERTY()				UUIScrollbar*		cScrollH;			//var UIScrollbar cScrollH;
	UPROPERTY()				int32				nSelection;			//var int nSelection;
	UPROPERTY()				int32				nTopLine;			//var int nTopLine;
	UPROPERTY()				float				fTextHeight;		//var float fTextHeight;
	UPROPERTY()				FString				sTexSelName;		//var string sTexSelName;
	UPROPERTY()				UMaterialInstance*	_TexSel;			//var Texture _TexSel;
	UPROPERTY()				FString				sTexName;			//var string sTexName;
	UPROPERTY()				UMaterialInstance*	_Texture;			//var Texture _Texture;
	UPROPERTY()				bool				bSorted;			//var bool bSorted;
	UPROPERTY()				int32				iNumStrings;		//var int iNumStrings;
	UPROPERTY()				TArray<FString>		sStringList;		//var string sStringList;

	void Destroyed();
	void AddString(FString sString);
	void Sort();
	void CreateTexture();
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void AttachScrollbar(UUIScrollbar* cScrollbar, int32 Type);
	void ScaleControl(UCanvas* Canvas);
	void ChildMessage(float Value);
	FString GetSelectedString();
};
