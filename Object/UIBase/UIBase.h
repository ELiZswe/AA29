// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "UIBase.generated.h"

class AAA2_WorldSettings;

UCLASS()
class AA29_API UUIBase : public UObject
{
	GENERATED_BODY()
public:
	UUIBase();

	//const kItemNone = -1;
	//const kStateMax = 4;
	//const kStateDisabled = 3;
	//const kStateClick = 2;
	//const kStateOver = 1;
	//const kStateNormal = 0;
	//const kBorderAlpha = 1;
	//const kBorderHollow = 0;
	//const kQuick = 4;
	//const kSizeBody = 2;
	//const kSizeLarge = 1;
	//const kSizeSmall = 0;
	//const kScrollH = 2;
	//const kScrollV = 1;
	//const F_Test = 8;
	//const F_Arial14 = 7;
	//const F_WebLink = 6;
	//const F_SuperExtraLarge = 5;
	//const F_ExtraLarge = 4;
	//const F_LargeBold = 3;
	//const F_Large = 2;
	//const F_Bold = 1;
	//const F_Normal = 0;



	UPROPERTY()										bool _bAllowScaling;			//var bool _bAllowScaling;
	UPROPERTY()										FPosition _Pos;					//var UIBase.Position _Pos;
	UPROPERTY()										int32 _iID;						//var int _iID;
	UPROPERTY()										bool _bDebug;					//var bool _bDebug;

	void StaticUpdatePrecacheMaterials(AAA2_WorldSettings* L);
	FPosition GetPos();
	void SetPos(FPosition p);
	void CreateUIObject(FString ObjectName);
	void SetDebug(bool Debug);
	int32 GetID();
	void Draw(UCanvas* Canvas);
	bool KeyType(int32 Key);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Destroyed();
};
