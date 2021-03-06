// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "ComponentGroup.generated.h"

class UGUISectionBackground;

class UGUIComponent;
class UGUIController;
UCLASS()
class UComponentGroup : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UComponentGroup();


	UPROPERTY()						FString					Caption;						//var localized string Caption;
	UPROPERTY(EditAnywhere)			UGUISectionBackground*	i_Background;					//var() XInterface.GUISectionBackground i_Background;

	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	UGUIComponent* ManageComponent(UGUIComponent* C);
	UGUIComponent* AppendComponent(UGUIComponent* NewComp, bool bSkipRemap);
	UGUIComponent* InsertComponent(UGUIComponent* NewComp, int32 Index, bool bSkipRemap);
	bool RemoveComponent(UGUIComponent* Comp, bool bSkipRemap);
	void SetCaption(FString NewCaption);
};
