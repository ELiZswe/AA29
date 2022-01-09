// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AARoundButton/STY_AAMoviePlayer_ScrubberKnob/STY_AAMoviePlayer_ScrubberKnob.h"

USTY_AAMoviePlayer_ScrubberKnob::USTY_AAMoviePlayer_ScrubberKnob()
{
	KeyName = "MoviePlayer_ScrubberKnob";
	Images ={
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled
	};
	ImgWidths = {
		32,
		32,
		32,
		32,
		32
	};
	ImgHeights = {
		16,
		16,
		16,
		16,
		16
	};
}
