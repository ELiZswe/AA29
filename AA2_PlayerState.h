// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/PlayerState.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA2_PlayerState.generated.h"

class AInventory;
class ADecoration;
class ATeamInfo;
class AGP_Weapon;
class AZoneInfo;
class AVehicleReplicationInfo;
class AVoiceChatRoom;
class ALinkedReplicationInfo;
class AVoicePack;
class AVoiceChatReplicationInfo;
class AVehicle;

UCLASS()
class AA29_API AAA2_PlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	AAA2_PlayerState();

	//myOwn
	UPROPERTY(Replicated)				TArray<TSubclassOf<AInventory>>		My_Pawn_Inventory;
	UPROPERTY(Replicated)				FString								MyState;
	UPROPERTY(Replicated)				int32								TeamID;											//var int TeamID;
	UPROPERTY(Replicated)				TSubclassOf <class ASoldierClass>	SpawnClass;
	UPROPERTY(Replicated)				TSubclassOf <class AAGP_Weapon>		CurrentWeapon;
	UPROPERTY()				float fLastConnectionResponseTimeLimit;					//var const float fLastConnectionResponseTimeLimit;
	UPROPERTY()				float fLastConnectionResponseTime;						//var const float fLastConnectionResponseTime;
	UPROPERTY()				bool bPlayerAdmin;										//var bool bPlayerAdmin;
	UPROPERTY()				FString sCurrentWeaponClass;							//var string sCurrentWeaponClass;
	UPROPERTY()				FString LastLocationString;								//var string LastLocationString;
	UPROPERTY()				AVolume* LastCommVol;									//var Volume LastCommVol;
	UPROPERTY()				AVolume* CommVol;										//var Volume CommVol;
	UPROPERTY()				bool bTournamentRestartTournamentRequest;				//var bool bTournamentRestartTournamentRequest;
	UPROPERTY()				bool bTournamentMatchPauseRequest;						//var bool bTournamentMatchPauseRequest;
	UPROPERTY()				bool bTournamentTeamSwapRequest;						//var bool bTournamentTeamSwapRequest;
	UPROPERTY()				bool bTournamentRestartRequest;							//var bool bTournamentRestartRequest;
	UPROPERTY()				bool bTournamentWarmupRequest;							//var bool bTournamentWarmupRequest;
	UPROPERTY()				bool bTournamentStartRequest;							//var bool bTournamentStartRequest;
	UPROPERTY()				bool bTournamentTeamCaptain;							//var bool bTournamentTeamCaptain;
	UPROPERTY()				bool bTournamentTeamRosterLocked;						//var bool bTournamentTeamRosterLocked;
	UPROPERTY()				bool bTournamentTeamReady;								//var bool bTournamentTeamReady;
	UPROPERTY()				bool bTournamentSquadLeader;							//var bool bTournamentSquadLeader;
	UPROPERTY()				uint8 bIsQualified;										//var const byte bIsQualified;
	UPROPERTY()				AActor* requiredClass;									//var class<Actor> requiredClass;
	UPROPERTY()				bool bMuted;											//var bool bMuted;
	UPROPERTY()				bool bSUEnabled;										//var bool bSUEnabled;
	UPROPERTY()				uint8 _Group;											//var byte _Group;
	UPROPERTY()				int32 _ExperienceDelta;									//var int _ExperienceDelta;
	UPROPERTY()				int32 _Experience;										//var int _Experience;
	UPROPERTY()				int32 _prevROE;											//var int _prevROE;
	UPROPERTY()				int32 _prevKills;										//var int _prevKills;
	UPROPERTY()				int32 _prevDeaths;										//var int _prevDeaths;
	UPROPERTY()				int32 _prevObjectives;									//var int _prevObjectives;
	UPROPERTY()				int32 _prevWins;										//var int _prevWins;
	UPROPERTY()				int32 _prevLeadership;									//var int _prevLeadership;
	UPROPERTY()				int32 _prevTotal;										//var int _prevTotal;
	UPROPERTY()				int32 _cumROE;											//var int _cumROE;
	UPROPERTY()				int32 _cumKills;										//var int _cumKills;
	UPROPERTY()				int32 _cumDeaths;										//var int _cumDeaths;
	UPROPERTY()				int32 _cumObjectives;									//var int _cumObjectives;
	UPROPERTY()				int32 _cumWins;											//var int _cumWins;
	UPROPERTY()				int32 _cumLeadership;									//var int _cumLeadership;
	UPROPERTY()				int32 _cumTotal;										//var int _cumTotal;
	UPROPERTY()				int32 _LastTimeUpdate;									//var int _LastTimeUpdate;
	UPROPERTY()				int32 _cumRounds;										//var int _cumRounds;
	UPROPERTY()				float _fWeight;											//var float _fWeight;
	UPROPERTY()				int32 _iTrust;											//var int _iTrust;
	UPROPERTY()				bool _bSoldiersCharacter;								//var bool _bSoldiersCharacter;
	UPROPERTY()				FString SquadName;										//var string SquadName;
	UPROPERTY()				FString votekick;										//var string votekick;
	UPROPERTY()				float tNextVoteAllowed;									//var float tNextVoteAllowed;
	UPROPERTY()				bool bIsUAVPilot;										//var bool bIsUAVPilot;
	UPROPERTY()				bool bIsUAVNavigator;									//var bool bIsUAVNavigator;
	UPROPERTY()				bool bIsMortarSpotter;									//var bool bIsMortarSpotter;
	UPROPERTY()				bool bQualifiedUAVPilot;								//var bool bQualifiedUAVPilot;
	UPROPERTY()				bool bQualifiedUAVNavigator;							//var bool bQualifiedUAVNavigator;
	UPROPERTY()				bool bQualifiedMortarSpotter;							//var bool bQualifiedMortarSpotter;
	UPROPERTY()				bool bQualifiedES2;										//var bool bQualifiedES2;
	UPROPERTY()				bool bQualifiedUseCROWS;								//var bool bQualifiedUseCROWS;
	UPROPERTY()				bool bQualifiedDriveHMMWV;								//var bool bQualifiedDriveHMMWV;
	UPROPERTY()				bool bQualifiedJavelin;									//var bool bQualifiedJavelin;
	UPROPERTY()				bool bQualifiedSF;										//var bool bQualifiedSF;
	UPROPERTY()				bool bQualifiedMedic;									//var bool bQualifiedMedic;
	UPROPERTY()				bool bQualifiedRanger;									//var bool bQualifiedRanger;
	UPROPERTY()				bool bQualifiedAirborne;								//var bool bQualifiedAirborne;
	UPROPERTY()				bool bQualifiedSniper;									//var bool bQualifiedSniper;
	UPROPERTY()				bool bQualifiedBCT;										//var bool bQualifiedBCT;
	UPROPERTY()				bool bQualifiedViaInstantAction;						//var bool bQualifiedViaInstantAction;
	UPROPERTY()				bool bCallForMedic;										//var bool bCallForMedic;
	UPROPERTY()				bool bIsMedic;											//var bool bIsMedic;
	UPROPERTY()				bool bLostMedic;										//var bool bLostMedic;
	UPROPERTY()				bool bWillBeMedic;										//var bool bWillBeMedic;
	UPROPERTY()				bool bWantsMedic;										//var bool bWantsMedic;
	UPROPERTY()				bool bAvoidLeaderRole		;							//var bool bAvoidLeaderRole;
	UPROPERTY()				bool bWantsSquadLeader;									//var bool bWantsSquadLeader;
	UPROPERTY()				bool bWantsFTLeader;									//var bool bWantsFTLeader;
	UPROPERTY()				bool LinkedToSquadLeader;								//var bool LinkedToSquadLeader;
	UPROPERTY()				bool LinkedToFTLeader;									//var bool LinkedToFTLeader;
	UPROPERTY()				int32 LinkedTo;											//var int LinkedTo;
	UPROPERTY()				int32 LinkedToMe;										//var int LinkedToMe;
	UPROPERTY()				int32 TempLinked;										//var int TempLinked;
	UPROPERTY()				int32 PawnYaw;											//var int PawnYaw;
	UPROPERTY()				uint8 FT;												//var byte FT;
	UPROPERTY()				AVehicleReplicationInfo* VehicleReplicationInfo;		//var VehicleReplicationInfo VehicleReplicationInfo;
	UPROPERTY()				int32 SwapRequest;										//var int SwapRequest;
	UPROPERTY()				AAA2_PlayerState* PRI_WaitingForPawn;					//var PlayerReplicationInfo PRI_WaitingForPawn;
	UPROPERTY()				float fpTimeSinceLastPingCalculation;					//var float fpTimeSinceLastPingCalculation;
	UPROPERTY()				int32 LocationZ;										//var int LocationZ;
	UPROPERTY()				int32 LocationY;										//var int LocationY;
	UPROPERTY()				int32 LocationX;										//var int LocationX;
	UPROPERTY()				APawn* myPawn;											//var Pawn myPawn;
	UPROPERTY()				bool bDead;												//var bool bDead;
	UPROPERTY()				bool bVIPPS;											//var bool bVIPPS;
	UPROPERTY()				bool bSpecialForcesPS;									//var bool bSpecialForcesPS;
	UPROPERTY()				bool bGuerrillaPS;										//var bool bGuerrillaPS;
	UPROPERTY()				int32 _Credited_Leadership;								//var int _Credited_Leadership;
	UPROPERTY()				int32 _Credited_Wins;									//var int _Credited_Wins;
	UPROPERTY()				int32 Score_ROE;										//var int Score_ROE;
	UPROPERTY()				int32 Score_Kills;										//var int Score_Kills;
	UPROPERTY()				int32 Score_Deaths;										//var int Score_Deaths;
	UPROPERTY()				int32 Score_Objectives;									//var int Score_Objectives;
	UPROPERTY()				int32 Score_Wins;										//var int Score_Wins;
	UPROPERTY()				int32 Score_Leadership;									//var int Score_Leadership;
	UPROPERTY()				int32 Score_Total;										//var int Score_Total;
	UPROPERTY()				uint8 DesiredTeam;										//var byte DesiredTeam;
	UPROPERTY()				float RadarBlinkEndTime;								//var float RadarBlinkEndTime;
	UPROPERTY()				float RadarBlinkStartTime;								//var float RadarBlinkStartTime;
	UPROPERTY()				float BlinkLatency;										//var float BlinkLatency;
	UPROPERTY()				float LastRadarBlinkEndTime;							//var float LastRadarBlinkEndTime;
	UPROPERTY()				float LastRadarBlinkStartTime;							//var float LastRadarBlinkStartTime;
	UPROPERTY()				int32 RadarDrawOpacity;									//var int RadarDrawOpacity;
	UPROPERTY()				bool bVisibleLastTick;									//var bool bVisibleLastTick;
	UPROPERTY()				uint8 VoiceID;											//var byte VoiceID;
	UPROPERTY()				int32 VoiceMemberMask;									//var int VoiceMemberMask;
	UPROPERTY()				int32 ActiveChannel;									//var int ActiveChannel;
	UPROPERTY()				AVoiceChatRoom* PrivateChatRoom;						//var VoiceChatRoom PrivateChatRoom;
	UPROPERTY()				bool bRegisteredChatRoom;								//var bool bRegisteredChatRoom;
	UPROPERTY()				AVoiceChatReplicationInfo* VoiceInfo;					//var VoiceChatReplicationInfo VoiceInfo;
	UPROPERTY()				ALinkedReplicationInfo* CustomReplicationInfo;			//var LinkedReplicationInfo CustomReplicationInfo;
	UPROPERTY()				AVehicle* CurrentVehicle;								//var Vehicle CurrentVehicle;
	UPROPERTY()				int32 Kills;											//var int Kills;
	UPROPERTY()				int32 GoalsScored;										//var int GoalsScored;
	UPROPERTY()				FString StringUnknown;									//var localized string StringUnknown;
	UPROPERTY()				FString StringSpectating;								//var localized string StringSpectating;
	UPROPERTY()				FString StringDead;										//var localized string StringDead;
	UPROPERTY()				uint8 PacketLoss;										//var byte PacketLoss;
	UPROPERTY()				bool bTeamNotified;										//var bool bTeamNotified;
	UPROPERTY()				bool bNoTeam;											//var bool bNoTeam;
	UPROPERTY()				bool bReceivedPing;										//var bool bReceivedPing;
	UPROPERTY()				bool bWelcomed;											//var bool bWelcomed;
	UPROPERTY()				bool bBot;												//var bool bBot;
	UPROPERTY()				bool bOutOfLives;										//var bool bOutOfLives;
	UPROPERTY()				bool bReadyToPlay;										//var bool bReadyToPlay;
	UPROPERTY()				bool bWaitingPlayer;									//var bool bWaitingPlayer;
	UPROPERTY()				bool bIsFemale;											//var bool bIsFemale;
	UPROPERTY()				bool bAdmin;											//var bool bAdmin;
	UPROPERTY()				FString VoiceTypeName;									//var string VoiceTypeName;
	UPROPERTY()				AVoicePack* VoiceType;									//var class<VoicePack> VoiceType;
	UPROPERTY()				ATeamInfo* Team;										//var TeamInfo Team;
	UPROPERTY()				FString PlayerMAC;										//var string PlayerMAC;
	UPROPERTY()				FString PreviousName;									//var string PreviousName;
	UPROPERTY()				FString OldName;										//var string OldName;
	UPROPERTY()				FString OldCharacterName;								//var string OldCharacterName;
	UPROPERTY()				FString				CharacterName;									//var string CharacterName;
	UPROPERTY()				FString				AuthUserName;									//var string AuthUserName;
	UPROPERTY()				FString				PlayerName;										//var string PlayerName;
	UPROPERTY()				int32				NumLives;											//var int NumLives;
	UPROPERTY()				int32				LastPlayerZone;									//var ZoneInfo LastPlayerZone;
	UPROPERTY()				AZoneInfo*			PlayerZone;									//var ZoneInfo PlayerZone;
	UPROPERTY()				AVolume*			LastPlayerVolume;								//var Volume LastPlayerVolume;
	UPROPERTY()				AVolume*			PlayerVolume;									//var Volume PlayerVolume;
	UPROPERTY()				ADecoration*		HasFlag;									//var Decoration HasFlag;

	//Already in PlayerState:
	//UPROPERTY()				int32 StartTime;										//var int StartTime;
	//UPROPERTY()				bool bOnlySpectator;									//var bool bOnlySpectator;
	//UPROPERTY()				bool bIsSpectator;										//var bool bIsSpectator;
	//UPROPERTY()				int32 PlayerID;											//var int PlayerID;
	//UPROPERTY()				uint8 Ping;												//var byte Ping;


	UFUNCTION(BlueprintCallable)		void Set_My_Pawn_Inventory(TArray<TSubclassOf<AInventory>> this_inventory);
	UFUNCTION(BlueprintCallable)		TArray<TSubclassOf<AInventory>> Get_My_Pawn_Inventory();
	//	UFUNCTION()							void Set_Weapon(TSubclassOf<AAGP_Weapon> Weapon);
	UFUNCTION(BlueprintCallable)		FString GetHumanReadableName() const;

	void PostAuthComplete();
	void BlinkCharacterOnRadar(float BlinkDuration);
	TWeakObjectPtr < class AActor > GetPlayerStart();
	virtual void PostBeginPlay();
	virtual void PostNetBeginPlay();
	virtual bool NeedNetNotify();
	virtual void PostNetReceive();
	virtual void Destroyed();
	void SetCharacterVoice(FString S);
	void SetCharacterName(FString S);
	void Reset();
	void Tick(float DeltaTime);
	virtual void GetPortrait();
	void UpdateCharacter();
	virtual void UpdatePlayerLocation();
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void ClientNameChange();
	void SetPlayerName(const FString& S);
	void SetWaitingPlayer(bool B);
	void SetChatPassword(FString InPassword);
	void SetVoiceMemberMask(int32 NewMask);
	virtual FString GetCallSign();
	virtual FString GetNameCallSign();
	//virtual void ContainedInBox(ABox* BBox);
	virtual void UpdateCommVolume();
	virtual AVolume* GetCommVolume();
	virtual AAGP_Objective* GetNearbyObjective(AVolume* C, bool bDefender);
	virtual void GetLocationName(AVolume* C);
	virtual FString GetSquadName();
	virtual bool EquivalentName(FString Name);
	void NotifyPromotion(bool bFTL, uint8 yFT);
	void NotifyNoScore(FName Reason);
	void NotifyClientMessage(FString Message);
	void CalculateWeight(float maxScore);
	float GetWeight();
	virtual int32 GetHonor();
	virtual bool HasGroupIcon();
	uint8 GetGroup();
	virtual void SetGroup(uint8 newgroup);
	void SUToggle();
	virtual bool SuperUser(bool bCheckEnabled);
	bool Administrator();
	virtual bool IsPlayerAdmin();
	int32 GetExperience();
	int32 GetCumRounds();
	float GetPlayTime();
	void GetController();
	void ResetPerRound();
	int32 GetRoundScore_Total();
	int32 GetRoundScore_Leadership();
	int32 GetRoundScore_Wins();
	int32 GetRoundScore_Objectives();
	int32 GetRoundScore_Deaths();
	int32 GetRoundScore_Kills();
	int32 GetRoundScore_ROE();
	virtual void ClientNotifyLostMedic();
	virtual int32 GetGoalScore();
	void UpdateScore();
	void PScoreKill();
	void PScoreAIVehicleKill();
	void PScoreDeath();
	void PScoreFF(int32 newscore);
	float CheckROE();
	void ScoreDecoMesh(int32 DestroyPoints);
	void PScoreObjective(int32 newscore);
	void ScoreRound(bool bWon);
	float GetMultiplier();
	int32 GetSLBonus();
	int32 GetFTLBonus();
	void CalculateLeaderScore();
	void CalculateLeaderPenalty();
	void IncrementCumulativeScores();
	int32 CalculateExperience();
	void TotalExperience(bool bShowUserDetail);
	void ResetScores();
	virtual bool hasSoldiersCharacter();
	virtual bool IsFriend(AAA2_PlayerState* Other, ATeamInfo* otherTeam);
	virtual bool IsEnemy(AAA2_PlayerState* Other, ATeamInfo* otherTeam);
	virtual void Timer();
	//void ServerUpdateVolumeZone(AVolume* volNewPlayerVolume, AZoneInfo* volNewPlayerZone, AVolume* volNewCommVol);
	void TeamReset();
	FVector GetPawnLocation();
	virtual void GetPawnYaw();
	void UpdatePawnYaw();
	void ServerSetMyPawn(APawn* new_pawn);
	virtual void WaitingForPawn(AAA2_PlayerState* PRI);
	virtual void FoundWaitingForPawn(APawn* p);
	virtual APawn* GetMyPawn();
	virtual bool isDead();
	virtual bool isSpectator();
	virtual bool IsSquadLeader();
	virtual bool isTeamLeader();
	AAA2_PlayerState* GetSquadLeader();
	AAA2_PlayerState* GetFTLeader();
	void SubmitPlayerRequest(int32 UnitID, int32 Index);
	void RemovePlayerRequest(AAA2_PlayerState* PRI);
	void CanScore();


};
