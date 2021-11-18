// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIListItems/StringListItems/StringListItems.h"
#include "IniStringListItems.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UIniStringListItems : public UStringListItems
{
	GENERATED_BODY()
public:
	UIniStringListItems();


	void Sort();
	void Draw(UCanvas* Canvas);
	void DrawItem(UCanvas* Canvas, int32 Position, int32 x_pos, int32 y_pos);
	void addItem(UObject* obj);
	void AddString(FString sString, int32 iCount);
	int32 GetNumItems();
	int32 GetWidth(int32 Index);
	int32 GetHeight(int32 Index);
	void ScaleControl(UCanvas* Canvas);
	void SetIniFile(FString Filename, FString Section);
};
