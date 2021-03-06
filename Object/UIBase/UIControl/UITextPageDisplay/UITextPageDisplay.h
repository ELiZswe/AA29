// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UITextPageDisplay.generated.h"

UCLASS()
class UUITextPageDisplay : public UUIControl
{
	GENERATED_BODY()
public:
	UUITextPageDisplay();

	UPROPERTY()				bool				_bPageDisplay;			//var bool _bPageDisplay;
	UPROPERTY()				int32				_iLinesPerPage;			//var int _iLinesPerPage;
	UPROPERTY()				int32				_iLastPage;				//var int _iLastPage;
	UPROPERTY()				int32				_iCurrPage;				//var int _iCurrPage;
	UPROPERTY()				FString				_sTitle;				//var string _sTitle;
	UPROPERTY()				TArray<FString>		_sStringList;			//var TArray<FString> _sStringList;

	void Destroyed();
	void Draw(UCanvas* Canvas);
	int32 SetTextFile(FString Filename);
	int32 SetStringList(TArray<FString> sStringList);
	TArray<FString> GetStringList();
	void AddLine(FString Line);
	void NextPage();
	void PrevPage();
	void SetTitle(FString Title);
	void SetLinesPerPage(int32 Lines);
	void SetPageDisplay(bool bState);
};
