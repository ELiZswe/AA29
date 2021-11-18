// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/FloatingWindow.h"
#include "ID3TagEditor.generated.h"

class UGUIPanel;
class UStreamInterface;
class UStreamInteraction;
class UGUIMultiOptionListBox;
class UGUIMultiOptionList;
class UAnimatedEditBox;
class UStream;
class UStreamTag;
class UGUIMenuOption;

UCLASS()
class AA29_API UID3TagEditor : public UFloatingWindow
{
	GENERATED_BODY()
public:
	UID3TagEditor();

	UPROPERTY(EditAnywhere)	UGUIPanel*					p_Main;				//var() automated XInterface.GUIPanel p_Main;
	UPROPERTY()				UStreamInterface*			FileManager;		//var StreamInterface FileManager;
	//UPROPERTY()				UStreamInteraction*			Handler;			//var StreamInteraction Handler;
	UPROPERTY()				UGUIMultiOptionListBox*		lb_Fields;			//var XInterface.GUIMultiOptionListBox lb_Fields;
	UPROPERTY()				UGUIMultiOptionList*		li_Fields;			//var XInterface.GUIMultiOptionList li_Fields;
	UPROPERTY()				UAnimatedEditBox*			ed_Fields;			//var TArray<AnimatedEditBox> ed_Fields;
	UPROPERTY()				FString						Filename;			//var FString Filename;
	UPROPERTY()				UStream*					Stream;				//var Stream Stream;
	UPROPERTY()				UStreamTag*					ID3Tag;				//var StreamTag ID3Tag;
	UPROPERTY()				FString						EditBoxHint;		//var localized FString EditBoxHint;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	bool SetFileManager();
	bool SetHandler();
	void HandleObject(UObject* obj, UObject* OptionalObject_1, UObject* OptionalObj_2);
	void HandleParameters(FString ParamA, FString ParamB);
	void InternalOnChange(UGUIComponent* Sender);
	int32 FindFieldIndex(FString Caption);
	void ReadTag();
	void SetPanelPosition(UCanvas* C);
	void ListCreateComponent(UGUIMenuOption* NewComp, UGUIMultiOptionList* Sender);
};
