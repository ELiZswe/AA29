// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/MovieTrigger/MovieTrigger.h"
#include "AA29/Object/Actor/Keypoint/AmbientSound/TriggerSound/TriggerSound.h"

AMovieTrigger::AMovieTrigger()
{

}

void AMovieTrigger::DoTouch(AActor* Other)
{
	/*
	ASkinnableStaticMeshActor* SMA = nullptr;
	ATriggerSound* ts = nullptr;
	if (Cast<APawn>(Other) != nullptr)
	{
		if (!Pawn(Other).IsHumanControlled())
		{
			return;
		}
	}
	if (bTriggerOnceOnly)
	{
		SetCollision(false);
	}
	ForEach AllActors(Class'AGP.SkinnableStaticMeshActor', SMA)
	{
		if (SMA.Tag == StaticMeshTarget)
		{
			if (SMA.Skins.Num() > SkinSlot)
			{
				SMA.Skins[1] = MovieToPlay;
				MovieToPlay.Movie.StopNow();
				MovieToPlay.Movie.Play(MovieToPlay.MovieFilename, false, bRepeatMovie);
				UpdateMovieTextureList();
				if (!bRepeatMovie)
				{
					SetTimer(MovieToPlay.Movie.GetMovieDuration(), false);
				}
			}
		}
	}
	ForEach AllActors(ATriggerSound::StaticClass(), ts)
	{
		if (ts.Tag == TriggerSoundTarget)
		{
			ts.Trigger(Other, Pawn(Other));
		}
	}
	*/
}

void AMovieTrigger::Timer()
{
	/*
	ASkinnableStaticMeshActor* SMA = nullptr;
	ForEach AllActors(Class'AGP.SkinnableStaticMeshActor', SMA)
	{
		if (SMA.Tag == StaticMeshTarget)
		{
			if (SMA.Skins.Num() > SkinSlot)
			{
				SMA.Skins[1] = nullptr;
				UpdateMovieTextureList();
			}
		}
	}
	*/
}
