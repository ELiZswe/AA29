// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/MyEnums.h"
#include "aLocalMessage.generated.h"

class AAA2_PlayerState;
class AAA2_HUD;

UCLASS()
class AaLocalMessage : public AAA2_Info
{
	GENERATED_BODY()
public:
	AaLocalMessage();

	UPROPERTY(EditAnywhere, Category = "Message")			int32 FontSize;						//var(Message) int FontSize;
	UPROPERTY(EditAnywhere, Category = "Message")			float PosY;							//var(Message) float PosY;
	UPROPERTY(EditAnywhere, Category = "Message")			float PosX;							//var(Message) float PosX;
	UPROPERTY(EditAnywhere, Category = "Message")			EStackMode StackMode;				//var(Message) EStackMode StackMode;
	UPROPERTY(EditAnywhere, Category = "Message")			EDrawPivot DrawPivot;				//var(Message) Object.EDrawPivot DrawPivot;
	UPROPERTY(EditAnywhere, Category = "Message")			FColor DrawColor;					//var(Message) Object.Color DrawColor;
	UPROPERTY(EditAnywhere, Category = "Message")			AaLocalMessage* ChildMessage;		//var(Message) class<LocalMessage> ChildMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			int32 Lifetime;						//var(Message) int Lifetime;
	UPROPERTY(EditAnywhere, Category = "Message")			bool bBeep;							//var(Message) bool bBeep;
	UPROPERTY(EditAnywhere, Category = "Message")			bool bFadeMessage;					//var(Message) bool bFadeMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			bool bIsConsoleMessage;				//var(Message) bool bIsConsoleMessage;
	UPROPERTY(EditAnywhere, Category = "Message")			bool bIsPartiallyUnique;			//var(Message) bool bIsPartiallyUnique;
	UPROPERTY(EditAnywhere, Category = "Message")			bool bIsUnique;						//var(Message) bool bIsUnique;
	UPROPERTY(EditAnywhere, Category = "Message")			bool bIsSpecial;					//var(Message) bool bIsSpecial;
	UPROPERTY(EditAnywhere, Category = "Message")			bool bComplexString;				//var(Message) bool bComplexString

	void RenderComplexMessage(UCanvas* Canvas, float& XL, float& YL, FString MessageString, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject);
	void GetRelatedString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject);
	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	FString AssembleString(AAA2_HUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString);
	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void GetConsoleColor(AAA2_PlayerState* RelatedPRI_1);
	void GetColor(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2);
	void GetPos(int32 Switch, EDrawPivot& OutDrawPivot, EStackMode& OutStackMode, float& OutPosX, float& OutPosY);
	void GetFontSize(int32 Switch, AAA2_PlayerState* RelatedPRI1, AAA2_PlayerState* RelatedPRI2, AAA2_PlayerState* LocalPlayer);
	void GetLifeTime(int32 Switch);
	bool IsConsoleMessage(int32 Switch);
	void GetOffset(int32 Switch, float YL, float ClipY);
	void ReportLocation(int32 Switch);
};
