#include "MediaPlayer.h"

MediaPlayer::MediaPlayer(QFrame* parent): QFrame(parent) {
	const char * const vlc_args[] = {
				  "-vv" };
	
	vlc_instance = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);
	if (vlc_instance == NULL) {
		std::cout << "Error occured while initializing vlc." << std::endl;
		std::cout << libvlc_printerr("%s") << std::endl;
		return;
	}
	
	vlc_mp = libvlc_media_player_new(vlc_instance);
	
#if defined(Q_OS_WIN)
	libvlc_media_player_set_xwindow(vlc_mp, reinterpret_cast<unsigned int>(parent->winId()));
#else
	libvlc_media_player_set_xwindow(vlc_mp, parent->winId());
#endif
}

MediaPlayer::~MediaPlayer() {
	if (vlc_instance == NULL) return;
	libvlc_media_player_stop(vlc_mp);
	libvlc_media_player_release(vlc_mp);
	libvlc_release(vlc_instance);
}

void MediaPlayer::LoadMedia(const QString& filepath) {
	libvlc_media_t* media = libvlc_media_new_path(vlc_instance, filepath.toStdString().c_str());
	libvlc_media_player_set_media(vlc_mp, media);
}

void MediaPlayer::Play() {
	libvlc_media_player_play(vlc_mp);
}

void MediaPlayer::Pause() {
	libvlc_media_player_pause(vlc_mp);
}

void MediaPlayer::Stop() {
	libvlc_media_player_stop(vlc_mp);
}

void MediaPlayer::ChangePosition(float newPosition) {
	float pos = newPosition / (float) POSITION_RESOLUTION;
	libvlc_media_player_set_position(vlc_mp, pos);
}

// Audio specific
void MediaPlayer::Mute(bool mute) {
	libvlc_audio_set_mute(vlc_mp, mute);
}

void MediaPlayer::ToggleMute() {
	libvlc_audio_toggle_mute(vlc_mp);
}

void MediaPlayer::ChangeVolume(int newVolume) {
	libvlc_audio_set_volume(vlc_mp, newVolume);
}
