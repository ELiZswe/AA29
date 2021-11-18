// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "IngameChat.generated.h"

class UExtendedConsole;
class UGUIEditBox;

UCLASS()
class AA29_API UIngameChat : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UIngameChat();

	UPROPERTY()				UExtendedConsole*	MyConsole;					//var ExtendedConsole MyConsole;
	UPROPERTY()				UGUIEditBox*		MyEditBox;					//var GUIEditBox MyEditBox;
	UPROPERTY()				bool				bIgnoreChar;				//var bool bIgnoreChar;
	UPROPERTY()				int32				OldCMC;						//var int32 OldCMC;
	UPROPERTY()				uint8				CloseKey;					//var uint8 CloseKey;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Clear();
	void HandleParameters(FString Param1, FString Param2);
	void MyOnClose(bool bCanceled);
	bool InternalOnKeyType(uint8& Key, FString Unicode);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};
