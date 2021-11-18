// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIListItems/UIListItems.h"
#include "StringListItems.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UStringListItems : public UUIListItems
{
	GENERATED_BODY()
public:
	UStringListItems();


	UPROPERTY()										int32 nSelection;						//var int nSelection;
	UPROPERTY()										int32 nTopLine;							//var int nTopLine;
	UPROPERTY()										int32 iTextHeight;						//var int iTextHeight;
	UPROPERTY()										bool bButtonDown;						//var bool bButtonDown;
	UPROPERTY()										FString sTexSelName;					//var string sTexSelName;
	UPROPERTY()										UMaterialInstance* _TexSel;				//var Texture _TexSel;
	UPROPERTY()										FString sTexName;						//var string sTexName;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;
	UPROPERTY()										bool bSorted;							//var bool bSorted;
	UPROPERTY()										int32 iNumStrings;						//var int iNumStrings;
	UPROPERTY()										TArray<FString> sStringList;			//var array<String> sStringList;


	void AddString(FString sString, int32 iPos);
	void Sort();
	void Draw(UCanvas* Canvas);
	void addItem(UObject* obj);
	int32 GetNumItems();
	void DrawItem(UCanvas* Canvas, int32 Position, int32 x_pos, int32 y_pos);
	int32 GetWidth(int32 Index);
	int32 GetHeight(int32 Index);
	void ScaleControl(UCanvas* Canvas);
	FString GetString(int32 Index);
};
