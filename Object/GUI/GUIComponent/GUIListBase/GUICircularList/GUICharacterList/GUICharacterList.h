// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICircularList.h"
#include "GUICharacterList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUICharacterList : public UGUICircularList
{
	GENERATED_BODY()
public:
	UGUICharacterList();

	UPROPERTY()								UMaterialInstance* DefaultPortrait;				//var() Material DefaultPortrait;
	UPROPERTY()								bool bLocked;									//var() bool bLocked;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitList();
	FString SelectedText();
	bool ValidIndex(int32 i);
	void Add(FString NewItem, UObject* obj);
	void Remove(int32 i, int32 Count);
	void Clear();
	void Find(FString Text, bool bExact);
	UMaterialInstance* GetPortrait();
	UMaterialInstance* GetPortraitAt(int32 i);
	FString GetName();
	FString GetNameAt(int32 i);
	FString GetGender();
	FString GetGenderAt(int32 i);
	FString GetDecoText();
	FString GetDecoTextAt(int32 AtIndex);
	USoundBase* GetSound();
	USoundBase* GetSoundAt(int32 i);
	void ScrollRight();
	void ScrollLeft();
	void MoveLeft();
	void MoveRight();
	void End();
	void ClearPendingElements();
	void InternalOnBeginDrag(UGUIComponent* Sender);
	void InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted);
	void InternalOnDragDrop(UGUIComponent* Sender);

};
