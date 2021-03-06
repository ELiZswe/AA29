// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AARoundButton/STY_AAMoviePlayer_VolumeKnob/STY_AAMoviePlayer_VolumeKnob.h"

USTY_AAMoviePlayer_VolumeKnob::USTY_AAMoviePlayer_VolumeKnob()
{
	KeyName = "MoviePlayer_VolumeKnob";
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_slider_Mat.t_ui_movieplayer_volume_slider_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_Scaled;
	ImgStyle[1] = EImgStyle::ISTY_Scaled;
	ImgStyle[2] = EImgStyle::ISTY_Scaled;
	ImgStyle[3] = EImgStyle::ISTY_Scaled;
	ImgStyle[4] = EImgStyle::ISTY_Scaled;
	ImgWidths[0] = 16;
	ImgWidths[1] = 16;
	ImgWidths[2] = 16;
	ImgWidths[3] = 16;
	ImgWidths[4] = 16;
	ImgHeights[0] = 32;
	ImgHeights[1] = 32;
	ImgHeights[2] = 32;
	ImgHeights[3] = 32;
	ImgHeights[4] = 32;
}
