// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/MyEnums.h"
#include "GameProfile.generated.h"

class AAA2_WorldSettings;
class ULadderInfo;
class UMatchInfo;

UCLASS()
class AA29_API UGameProfile : public UObject
{
	GENERATED_BODY()
public:
	UGameProfile();

	UPROPERTY(EditAnywhere)								FString PackageName;								//var() string PackageName;
	UPROPERTY(EditAnywhere)								int32 ManifestIndex;								//var() int ManifestIndex;
	UPROPERTY()											TArray<FString> PositionName;						//var localized string PositionName;			// text names of these positions
	UPROPERTY()											TArray<EPlayerPos> PlayerPositions;					//var EPlayerPos PlayerPositions;				// only need positions for AI team, so 7 max
	UPROPERTY(EditAnywhere)								TArray<FString> PlayerTeam;							//var() array<String> PlayerTeam;				// Player team members
	UPROPERTY()											TArray<int32> PlayerLineup;							//var int PlayerLineup;							// Lineup for current match.  Stores index into PlayerTeam array.
	UPROPERTY()											FString EnemyTeam;									//var string EnemyTeam;							// Opponent team name for pending/current match
	UPROPERTY()											FString TeamName;									//var string TeamName;							// Player team name
	UPROPERTY()											FString TeamSymbolName;								//var string TeamSymbolName;					// name of team symbol
	UPROPERTY(EditAnywhere)								float BaseDifficulty;								//var() float BaseDifficulty;					// configured at start of single player
	UPROPERTY(EditAnywhere)								float Difficulty;									//var() float Difficulty;
	UPROPERTY()											int32 SalaryCap;									//var int SalaryCap;							// allowable salary cap for team roster
	
	// stored here, but also passed separately on URL
	UPROPERTY()											FString PlayerName;									//var string PlayerName;
	UPROPERTY()											FString PlayerCharacter;							//var string PlayerCharacter;
	// player's stats - individual experience
	UPROPERTY(EditAnywhere)								int32 Kills;										//var() int Kills;
	UPROPERTY(EditAnywhere)								int32 Goals;										//var() int Goals;
	UPROPERTY(EditAnywhere)								int32 Wins;											//var() int Wins;
	UPROPERTY(EditAnywhere)								int32 Matches;										//var() int Matches;
	// Ladders:  -1 = Locked
	UPROPERTY()											TArray<int32> ladderrung;							//var int ladderrung;
	UPROPERTY()											FString SpecialEvent;								//var string SpecialEvent;
	UPROPERTY()											FString GameLadderName;								//var string GameLadderName;
	UPROPERTY()											ULadderInfo* GameLadder;							//var class<LadderInfo> GameLadder;
	
	// current match
	UPROPERTY()											int32 CurrentLadder;								//var int CurrentLadder;
	UPROPERTY()											int32 CurrentMenuRung;								//var transient int CurrentMenuRung;			// set by menu system, used for starting a match, in LadderInfo.  if -1, use next match in order
	UPROPERTY()											UObject* NextMatchObject;							//var transient Object NextMatchObject;			// Used by GUI SP Pages for holding the Button for Next Match
	UPROPERTY()											UObject* ChampBorderObject;							//var transient Object ChampBorderObject;		// Used by GUI SP Pages for holding the border for Championship.  
																																							// Sad hack, but easiest way to communicate GUI objects between Ladder and Qual tabs
	UPROPERTY()											bool bInLadderGame;									//var bool bInLadderGame;						// Used to see if we should return to the SP menu after the match has finished, 
	UPROPERTY()											bool bWonMatch;										//var bool bWonMatch;							// also used to check if we should use the LoadingClass vignette

	void Initialize(AGameModeBase* currentGame, FString pn);
	void CheatSkipMatch(AGameModeBase* currentGame);
	void CheatJumpMatch(AGameModeBase* currentGame, int32 Param);
	UMatchInfo* GetMatchInfo(int32 Ladder, int32 rung);
	void RegisterGame(AGameModeBase* currentGame, APlayerState* PRI);

	void StartNewMatch(int32 PickedLadder, AAA2_WorldSettings* CurrentLevel);

	void FindFirstUnfinishedLadder();
	void ContinueSinglePlayerGame(AAA2_WorldSettings* Level, bool bReplace);
	FString GetMatchDescription();
	int32 GetNumPositions();
	void GetNumTeammatesForMatch();
	void TextPositionDescription(int32 posnval);
	void EnumPositionDescription(FString posnval);
	void GetPositionDescription(int32 PlayerNum);
	void SetPosition(int32 lineupnum, FString posn);
	void SetLineup(int32 lineuppos, int32 teampos);
	void AddTeammate(FString botname);
	void ReleaseTeammate(FString botname);
	void ClearTeammates();
	void ReportCheat(APlayerController* Cheater, FString cheat);
	bool CanChangeTeam(AController* Other, int NewTeam);

};
