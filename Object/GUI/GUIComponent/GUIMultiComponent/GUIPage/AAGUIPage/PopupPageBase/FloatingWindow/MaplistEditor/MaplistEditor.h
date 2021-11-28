// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/FloatingWindow.h"
#include "MaplistEditor.generated.h"

class AMaplistManager;
class UGUITreeListBox;
class UGUIButton;
class UGUIEditBox;
class UGUIComboBox;
class UGUISectionBackground;
class UGUITreeList;
class UGUIListBase;

UCLASS()
class AA29_API UMaplistEditor : public UFloatingWindow
{
	GENERATED_BODY()
public:
	UMaplistEditor();

	UPROPERTY(EditAnywhere)		TArray<FMapItem>		Maps;						//var() editconst noexport TArray<MaplistRecord.MapItem> Maps;
	UPROPERTY(EditAnywhere)		FGameRecord				CurrentGameType;			//var() editconst noexport CacheManager.GameRecord CurrentGameType;
	UPROPERTY(EditAnywhere)		AMaplistManager*		MapHandler;					//var() editconst noexport MaplistManager MapHandler;
	UPROPERTY(EditAnywhere)		int32					GameIndex;					//var() editconst noexport int32 GameIndex;
	UPROPERTY(EditAnywhere)		int32					RecordIndex;				//var() editconst noexport int32 RecordIndex;
	UPROPERTY(EditAnywhere)		UGUITreeListBox*		lb_ActiveMaps;				//var() automated XInterface.GUITreeListBox lb_ActiveMaps;
	UPROPERTY(EditAnywhere)		UGUITreeListBox*		lb_AllMaps;					//var() automated XInterface.GUITreeListBox lb_AllMaps;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_Add;						//var() automated XInterface.GUIButton b_Add;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_AddAll;					//var() automated XInterface.GUIButton b_AddAll;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_Remove;					//var() automated XInterface.GUIButton b_Remove;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_RemoveAll;				//var() automated XInterface.GUIButton b_RemoveAll;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_MoveUp;					//var() automated XInterface.GUIButton b_MoveUp;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_MoveDown;					//var() automated XInterface.GUIButton b_MoveDown;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_New;						//var() automated XInterface.GUIButton b_New;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_Delete;					//var() automated XInterface.GUIButton b_Delete;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_Rename;					//var() automated XInterface.GUIButton b_Rename;
	UPROPERTY(EditAnywhere)		UGUIEditBox*			ed_MapName;					//var() automated XInterface.GUIEditBox ed_MapName;
	UPROPERTY(EditAnywhere)		UGUIComboBox*			co_Maplist;					//var() automated XInterface.GUIComboBox co_Maplist;
	UPROPERTY(EditAnywhere)		UGUISectionBackground*	sb_MapList;					//var() automated XInterface.GUISectionBackground sb_MapList;
	UPROPERTY(EditAnywhere)		UGUISectionBackground*	sb_Avail;					//var() automated XInterface.GUISectionBackground sb_Avail;
	UPROPERTY(EditAnywhere)		UGUISectionBackground*	sb_Active;					//var() automated XInterface.GUISectionBackground sb_Active;
	UPROPERTY(EditAnywhere)		UGUITreeList*			li_Active;					//var() editconst noexport XInterface.GUITreeList li_Active;
	UPROPERTY(EditAnywhere)		UGUITreeList*			li_Avail;					//var() editconst noexport XInterface.GUITreeList li_Avail;
	UPROPERTY()					bool					bOnlyShowCustom;			//var bool bOnlyShowCustom;
	UPROPERTY()					bool					bOnlyShowOfficial;			//var bool bOnlyShowOfficial;
	UPROPERTY(EditAnywhere)		FString					InvalidMaplistClassText;	//var() localized FString InvalidMaplistClassText;
	UPROPERTY(EditAnywhere)		FString					NewMaplistPageCaption;		//var() localized FString NewMaplistPageCaption;
	UPROPERTY(EditAnywhere)		FString					MaplistEditCaption;			//var() localized FString MaplistEditCaption;
	UPROPERTY(EditAnywhere)		FString					RenameMaplistPageCaption;	//var() localized FString RenameMaplistPageCaption;
	UPROPERTY(EditAnywhere)		FString					LinkText;					//var() localized FString LinkText;
	UPROPERTY(EditAnywhere)		FString					AutoSelectText;				//var() localized FString AutoSelectText;
	UPROPERTY(EditAnywhere)		FString					BonusVehicles;				//var() localized FString BonusVehicles;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetupSizingCaption();
	void Initialize(AMaplistManager* InHandler);
	bool InitGameType();
	bool OrigONSMap(FString MapName);
	void ReloadAvailable();
	void ReloadActive();
	void RefreshMaplistNames(FString CurrentMaplist);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	bool AddMap(FString MapName);
	bool RemoveMap();
	bool ButtonPreDraw(UCanvas* C);
	void RenameMaplist(bool bCancelled);
	void CreateNewMaplist(bool bCancelled);
	bool ModifyMapList(UGUIComponent* Sender);
	bool CustomMaplistClick(UGUIComponent* Sender);
	void MaplistSelectChange(UGUIComponent* Sender);
	bool AddDragDrop(UGUIComponent* Sender);
	bool RemoveDragDrop(UGUIComponent* Sender);
	void AddMapOption(FString MapName, FString OptionName, FString Value);
	void InternalCheckLinkedObj(UGUIListBase* List);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void StoreMaplists();
	void UpdateCustomMaplist(FString NewName);
	FString GetMapPrefix();
	FString GetMapListClass();
	int32 FindCacheRecordIndex(FString MapName);
	void Free();
};
