// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "GUIImageList.generated.h"

class UGUIComponent;
class UGUIController;
UCLASS()
class UGUIImageList : public UGUIImage
{
	GENERATED_BODY()
public:
	UGUIImageList();
	UPROPERTY(EditAnywhere)				bool						bWrap;			//var() bool bWrap;
	UPROPERTY(EditAnywhere)				int32						CurIndex;		//var() editconst int CurIndex;
	UPROPERTY(EditAnywhere)				TArray<UMaterialInstance*>	Materials;		//var() array<Material> Materials;
	UPROPERTY(EditAnywhere)				TArray<FString>				MatNames;		//var() TArray<FString> MatNames;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void AddMaterial(FString MatName, UMaterialInstance*& mat);
	FString GetCurMatName();
	void SetIndex(int32 Index);
	bool internalKeyEvent(uint8& Key, uint8& State, float Delta);
	void PrevImage();
	void NextImage();
	void FirstImage();
	void LastImage();
};
