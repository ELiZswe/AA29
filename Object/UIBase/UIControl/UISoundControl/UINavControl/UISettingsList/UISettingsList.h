// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UISettingsList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUISettingsList : public UUINavControl
{
	GENERATED_BODY()
public:
	UUISettingsList();

	//const kMaxPages = 4;
	//const kMaxSettingsVisible = 16;
	//const kMaxSettings = 64;
	//const kDoubleClickTime = 0.3;


	UPROPERTY()										int32 iCurrPage;					//var int iCurrPage;
	UPROPERTY()										int32 Type;							//var int Type;
	UPROPERTY()										FString Value;						//var string Value;
	UPROPERTY()										FString Setting;					//var string Setting;
	UPROPERTY()										FString Section;					//var string Section;
	UPROPERTY()										UMaterialInstance* _tSelected;		//var Texture _tSelected;
	UPROPERTY()										UMaterialInstance* _tBackground;	//var Texture _tBackground;
	UPROPERTY()										int32 _iSelected;					//var int _iSelected;
	UPROPERTY()										int32 iNumSettings;					//var int iNumSettings;
	UPROPERTY()										int32 _iNumOver;					//var int _iNumOver;
	UPROPERTY()										bool _bFirstOver;					//var bool _bFirstOver;
	UPROPERTY()										int32 _iState;						//var int _iState;


	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void CreateTexture();
	int32 GetSelected();
	void ClearList();
	void SetSetting(int32 Index, FString szSection, FString szSetting, FString szValue, int32 iType);
	void UpdateSettingValue(int32 Index, FString szValue);
	void SetSelectedSetting(int32 iSetting);
	FString GetSelectedSection();
	FString GetSelectedSetting();
	void NextPage();
	void PrevPage();
	int32 GetSelectedIndex();
};
