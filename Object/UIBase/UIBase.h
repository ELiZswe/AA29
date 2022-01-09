// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "UIBase.generated.h"

class AAA2_WorldSettings;

UCLASS()
class UUIBase : public UObject
{
	GENERATED_BODY()
public:
	UUIBase();

	UPROPERTY()				bool		_bAllowScaling;			//var bool _bAllowScaling;
	UPROPERTY()				FPosition	_Pos;					//var UIBase.Position _Pos;
	UPROPERTY()				int32		_iID;					//var int _iID;
	UPROPERTY()				bool		_bDebug;				//var bool _bDebug;

	void StaticUpdatePrecacheMaterials(AAA2_WorldSettings* L);
	FPosition GetPos();
	void SetPos(FPosition p);
	UObject* CreateUIObject(FString ObjectName);
	void SetDebug(bool Debug);
	int32 GetID();
	void Draw(UCanvas* Canvas);
	bool KeyType(int32 Key);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Destroyed();
};
