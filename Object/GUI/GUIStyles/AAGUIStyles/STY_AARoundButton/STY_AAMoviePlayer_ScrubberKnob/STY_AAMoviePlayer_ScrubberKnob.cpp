// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AARoundButton/STY_AAMoviePlayer_ScrubberKnob/STY_AAMoviePlayer_ScrubberKnob.h"

USTY_AAMoviePlayer_ScrubberKnob::USTY_AAMoviePlayer_ScrubberKnob()
{
	KeyName = "MoviePlayer_ScrubberKnob";
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_video_slider_Mat.t_ui_movieplayer_video_slider_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_Scaled;
	ImgStyle[1] = EImgStyle::ISTY_Scaled;
	ImgStyle[2] = EImgStyle::ISTY_Scaled;
	ImgStyle[3] = EImgStyle::ISTY_Scaled;
	ImgStyle[4] = EImgStyle::ISTY_Scaled;
	ImgWidths[0] = 32;
	ImgWidths[1] = 32;
	ImgWidths[2] = 32;
	ImgWidths[3] = 32;
	ImgWidths[4] = 32;
	ImgHeights[0] = 16;
	ImgHeights[1] = 16;
	ImgHeights[2] = 16;
	ImgHeights[3] = 16;
	ImgHeights[4] = 16;
}
