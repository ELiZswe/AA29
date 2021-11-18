// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_ServerInfo.generated.h"

class UGUIButton;
class UGUILabel;
class UGUIImage;

UCLASS()
class AA29_API UAAGameMenu_ServerInfo : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_ServerInfo();

	UPROPERTY(EditAnywhere)					UGUIImage* i_Background;						//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)					UGUIImage* i_Info;								//var() automated XInterface.GUIImage i_Info;
	UPROPERTY(EditAnywhere)					UGUILabel* l_ServerName;						//var() automated XInterface.GUILabel l_ServerName;
	UPROPERTY(EditAnywhere)					UGUILabel* l_AdminName;							//var() automated XInterface.GUILabel l_AdminName;
	UPROPERTY(EditAnywhere)					UGUILabel* l_AdminEmail;						//var() automated XInterface.GUILabel l_AdminEmail;
	UPROPERTY(EditAnywhere)					UGUILabel* l_MOTDLine1;							//var() automated XInterface.GUILabel l_MOTDLine1;
	UPROPERTY(EditAnywhere)					UGUILabel* l_MOTDLine2;							//var() automated XInterface.GUILabel l_MOTDLine2;
	UPROPERTY(EditAnywhere)					UGUILabel* l_MOTDLine3;							//var() automated XInterface.GUILabel l_MOTDLine3;
	UPROPERTY(EditAnywhere)					UGUILabel* l_MOTDLine4;							//var() automated XInterface.GUILabel l_MOTDLine4;
	UPROPERTY(EditAnywhere)					UGUILabel* l_Game;								//var() automated XInterface.GUILabel l_Game;
	UPROPERTY(EditAnywhere)					UGUILabel* l_Time;								//var() automated XInterface.GUILabel l_Time;
	UPROPERTY(EditAnywhere)					UGUILabel* l_Map;								//var() automated XInterface.GUILabel l_Map;
	UPROPERTY(EditAnywhere)					TArray<UGUILabel*> l_Teams;						//var() automated XInterface.GUILabel l_Teams[2];
	UPROPERTY(EditAnywhere)					UGUIButton* b_Hidden;							//var() automated XInterface.GUIButton b_Hidden;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	int32 RoundNumber();
	FString TwoDigitString(int32 Num);
	bool InternalOnPreDraw(UCanvas* C);
	bool InternalOnClick(UGUIComponent* Sender);
	
};
