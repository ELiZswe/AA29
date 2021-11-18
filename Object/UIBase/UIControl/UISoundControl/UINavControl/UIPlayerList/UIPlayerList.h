// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UIPlayerList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIPlayerList : public UUINavControl
{
	GENERATED_BODY()
public:
	UUIPlayerList();

	//const kMaxPages = 4;
	//const kMaxPlayersVisible = 16;
	//const kDoubleClickTime = 0.3;


	UPROPERTY()										float fDevColorGreen;						//var float fDevColorGreen;
	UPROPERTY()										float fDevColorGreenDelta;					//var float fDevColorGreenDelta;
	UPROPERTY()										int32 iCurrPage;							//var int iCurrPage;
	UPROPERTY()										int32 PlayerCount;							//var int PlayerCount;
	UPROPERTY()										float fLastPlayerUpdateTime;				//var float fLastPlayerUpdateTime;
	UPROPERTY()										AAA2_PlayerState* Ordered;					//var PlayerReplicationInfo Ordered;
	UPROPERTY()										float fLastClickTime;						//var float fLastClickTime;
	UPROPERTY()										UMaterialInstance* _tBackground;			//var Texture _tBackground;
	UPROPERTY()										UMaterialInstance* _tSelected;				//var Texture _tSelected;
	UPROPERTY()										TArray<UMaterialInstance*> DevIcons;		//var() array<Material> DevIcons;
	UPROPERTY()										int32 _iSelected;							//var int _iSelected;
	UPROPERTY()										int32 _iNumPlayers;							//var int _iNumPlayers;
	UPROPERTY()										int32 _iFirstPlayer;						//var int _iFirstPlayer;
	UPROPERTY()										int32 _iNumOver;							//var int _iNumOver;
	UPROPERTY()										bool _bFirstOver;							//var bool _bFirstOver;
	UPROPERTY()										int32 _iState;								//var int _iState;


	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void UpdatePlayerList();
	void Draw(UCanvas* Canvas);
	void CreateTexture();
	int32 GetSelected();
	void SetSelectedPlayer(int32 selected);
	FString GetSelectedPlayer();
	void PrevPage();
	void NextPage();

};
