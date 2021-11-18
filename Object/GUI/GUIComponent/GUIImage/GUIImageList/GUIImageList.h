// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "GUIImageList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIImageList : public UGUIImage
{
	GENERATED_BODY()
public:
	UGUIImageList();
	UPROPERTY()										bool bWrap;									//var() bool bWrap;
	UPROPERTY()										int32 CurIndex;								//var() editconst int CurIndex;
	UPROPERTY()										TArray<UMaterialInstance*> Materials;		//var() array<Material> Materials;
	UPROPERTY()										TArray<FString> MatNames;					//var() array<String> MatNames;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void AddMaterial(FString MatName, UMaterialInstance* mat);
	void GetCurMatName();
	void SetIndex(int32 Index);
	void internalKeyEvent(uint8& Key, uint8& State, float Delta);
	void PrevImage();
	void NextImage();
	void FirstImage();
	void LastImage();

};
