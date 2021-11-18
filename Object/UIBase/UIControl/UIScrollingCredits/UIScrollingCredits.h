// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIScrollingCredits.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIScrollingCredits : public UUIControl
{
	GENERATED_BODY()
public:
	UUIScrollingCredits();

	UPROPERTY()										float _fScrollRate;						//var float _fScrollRate;
	UPROPERTY()										float _fStartTime;						//var float _fStartTime;
	UPROPERTY()										float _fLastDrawTime;					//var float _fLastDrawTime;
	UPROPERTY()										int32 iNumLines;						//var int iNumLines;
	UPROPERTY()										int32 iTextHeight;						//var int iTextHeight;
	UPROPERTY()										int32 iTopLine;							//var int iTopLine;
	UPROPERTY()										int32 iNumStrings;						//var int iNumStrings;
	UPROPERTY()										TArray<FString> _sStringList;			//var array<String> _sStringList;


	void Destroyed();
	void Draw(UCanvas* Canvas);
	void ScaleControl(UCanvas* Canvas);
	void AddLine(FString sString);
	void SetTextFile(FString Filename);
};
