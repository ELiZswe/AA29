// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/aLocalMessage.h"
#include "CommoLocalMessage.generated.h"

UCLASS()
class ACommoLocalMessage : public AaLocalMessage
{
	GENERATED_BODY()
public:
	ACommoLocalMessage();

	UPROPERTY()			bool				bNo3D;						//var bool bNo3D;
	UPROPERTY()			ECommoType			_commotype;					//var Pawn.ECommoType _commotype;
	UPROPERTY()			TArray<FName>		_Animations;				//var name _Animations;
	UPROPERTY()			float				_fEnemyTravelDistance;		//var float _fEnemyTravelDistance;
	UPROPERTY()			float				_fTravelDistance;			//var float _fTravelDistance;
	UPROPERTY()			float				_fSoundVolume;				//var float _fSoundVolume;
	UPROPERTY()			TArray<USoundBase*> _Sounds3;					//var Sound _Sounds3;
	UPROPERTY()			TArray<USoundBase*> _Sounds2;					//var Sound _Sounds2;
	UPROPERTY()			TArray<USoundBase*> _Sounds1;					//var Sound _Sounds1;
	UPROPERTY()			FString				_messagename;				//var string _messagename;
	UPROPERTY()			int32				_iMaxMessages;				//var int _iMaxMessages;
	UPROPERTY()			TArray<FString>		_Messages;					//var string _Messages;
	UPROPERTY()			int32				_iNumMessages;				//var int _iNumMessages;
	UPROPERTY()			FString				Messaged;					//var localized string Messaged;
	UPROPERTY()			FString				Punctuation;				//var localized string Punctuation;

	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	float GetTravelDistance(AAA2_PlayerState* SenderPRI, AAA2_PlayerState* LocalPRI);
	int32 GetNumMessages();
	FString GetMessage(int32 Index);
	FString GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	bool IsBeepSound(USoundBase* SoundToTest);
	USoundBase* GetSound(int32 Switch, AAA2_PlayerState* SenderPRI, AAA2_PlayerState* LocalPRI);
	FName GetAnim(int32 Switch);
	FString GetMessageTypeName();
	ECommoType GetType();
};
