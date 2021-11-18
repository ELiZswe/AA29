// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyStructs.h"
#include "AA29/PSSet/PSSet.h"
#include "GameFramework/Actor.h"
#include "AA29/Inventory/Inventory.h"
#include "GameFramework/PlayerStart.h"
#include "AGP_PlayerStart.generated.h"

class USkeletalMesh;
class UMaterialInstance;
class APSProxy;

UCLASS()
class AA29_API AAGP_PlayerStart : public APlayerStart
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	AAGP_PlayerStart(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()																	uint8 _NumSpawned;											//var byte _NumSpawned;									// number of times this start has been used this round
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									uint8 MaxSpawns;											//var() byte MaxSpawns;									// number of times this start can be used in a round
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bGiveParachute;										//var() bool bGiveParachute;							// Player spawns in this point with a parachute
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									TSubclassOf <class ASoldierClass>  SpawnClass;				//var() class<SoldierClass> SpawnClass;					// team class to spawn for players starting here.
																																																	// if none, use game default
	UPROPERTY()																	bool bExtraSpecialForces;									//var bool bExtraSpecialForces;
	UPROPERTY()																	FString ExtraSpecialForcesLetter;							//var string ExtraSpecialForcesLetter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bOnlySpawnAtProxies;									//var() bool bOnlySpawnAtProxies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bNoPLFDamage;											//var() bool bNoPLFDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bNoParaFallDamage;										//var() bool bNoParaFallDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									EInitialParaState InitialParaState;							//var() EInitialParaState InitialParaState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bUserSetMesh;											//var() bool bUserSetMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									USkeletalMesh* SetMesh;										//var() Mesh SetMesh;

//User set Skin
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									UMaterialInstance* setPants;								//var() Material setPants;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									UMaterialInstance* setShirt;								//var() Material setShirt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									UMaterialInstance* setHands;								//var() Material setHands;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									UMaterialInstance* setFace;									//var() Material setFace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bUserSetSkin;											//var() bool bUserSetSkin;
	UPROPERTY()																	TSubclassOf<class AAGP_PlayerStart> nextPS;					//var AGP_PlayerStart nextPS;							//agp [cmb] Used by Team for assigning to PSs to Players at start of match [6/19/2002]
	UPROPERTY()																	int32 StartIndex;											//var int StartIndex;
	UPROPERTY()																	bool bIFVIP;												//var bool bIFVIP;
	UPROPERTY()																	bool bSpecialForces;										//var bool bSpecialForces;
	UPROPERTY()																	bool bGuerrilla;											//var bool bGuerrilla;
	UPROPERTY()																	int32 RemoveNum;											//var int RemoveNum;
	UPROPERTY()																	TArray<uint8> Removed;										//var byte Removed[16];
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									TArray<TSubclassOf<AInventory>> RemoveClassInventory;		//var() class<Inventory> RemoveClassInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									FName MyLeader;												//var() name MyLeader;									// tag of a playerstart for spawned player's leader
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									TArray<TSubclassOf<AInventory>> AddedInventory;				//var() class<Inventory> AddedInventory;				// inventory items added after items
																																																	// normally received by this class, or by this team
	//From PlayerStart(AA2)
	UPROPERTY()																	TArray<APSProxy*> ProxyList;								//var const array<PSProxy> ProxyList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Proxy")				FName SetTag;												//var(Proxy) const name SetTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Proxy")				FName ProxyTag;												//var(Proxy) const name ProxyTag;
	UPROPERTY()																	FName PrevProxyTag;											//var const transient name PrevProxyTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AGP_PlayerStart")		EFireTeam FireTeam;											//var(AGP_PlayerStart) EFireTeam FireTeam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP_PlayerStart")	uint8 nInitialHealth;										//var(AGP_PlayerStart) int nInitialHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AGP_PlayerStart")	bool bFTLeader;												//var(AGP_PlayerStart) bool bFTLeader;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AGP_PlayerStart")	bool bSquadLeader;											//var(AGP_PlayerStart) bool bSquadLeader;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									uint8 fBaseScore;											//var() float fBaseScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bPrimaryStart;											//var() bool bPrimaryStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bEnabled;												//var() bool bEnabled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bCoopStart;											//var() bool bCoopStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)									bool bSinglePlayerStart;									//var() bool bSinglePlayerStart;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)									uint8 TeamNumber;											//var() byte TeamNumber;

	bool bUsed;


	// A UBillboardComponent to hold Icon sprite
	//UPROPERTY(EditAnywhere, BlueprintReadOnly)									UBillboardComponent* SpriteComponent;
	class UBillboardComponent* SpriteComponent;
	//from Actor:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float DrawScale;

	// Icon sprite
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* Texture;

	//Functions:
	virtual uint8 GetInitialParaState();							//GetInitialParaState
	virtual bool SkipInventory(FString AddName);					//SkipInventory
	virtual bool ShouldSetInitialParaState();						//ShouldSetInitialParaState

	virtual TSubclassOf <class ASoldierClass> GetSpawnClass();		//simulated function Class<SoldierClass> GetSpawnClass()
	virtual int32 GetInitialHealth();								//simulated function int GetInitialHealth()
	virtual float GetScore();										//function float GetScore()
	virtual bool CanSpawn();										//function bool CanSpawn()
	virtual int32 NumSpawnsRemaining();								//function int NumSpawnsRemaining()
	virtual int32 NumSpawnsUsed();									//function int NumSpawnsUsed()
	virtual uint8 GetTeamID();										//function byte GetTeamID()
	virtual bool IsEnabled();										//function bool IsEnabled()
	virtual void UsePlayerStart();									//Function UsePlayerStart ()
	virtual uint8 getFT();											//function byte GetFT()
	virtual FString toString();										//function string toString(){
	virtual void FindNewStartIndex(APSSet* UseSet);								//Function FindNewStartIndex (optional PSSet UseSet)
	virtual FVector GetStartLocation();								//function vector GetStartLocation()
	virtual FRotator GetStartRotation();							//function rotator GetStartRotation()


	virtual void LoadEditorIcon();
	//virtual void SetClass();

};
