#include "MediaPlayer.h"

MediaPlayer::MediaPlayer() {
	setenv("VLC_PLUGIN_PATH", "/Applications/VLC.app/Contents/MacOS/plugins", 1);
	vlc_instance = VLC::Instance(0, NULL);
	
	if (vlc_instance == NULL) {
		std::cout << libvlc_printerr("Error occured while initializing vlc: %s") << std::endl;
		return;
	}
	
	vlc_mp = VLC::MediaPlayer(vlc_instance);
}

MediaPlayer::~MediaPlayer() {
	if (vlc_instance == NULL) return;
	vlc_mp.stop();
	libvlc_media_player_release(vlc_mp);
	libvlc_release(vlc_instance);
}

void MediaPlayer::SetVideoWidget(QFrame* widget) {
	videoWidget = widget;
}

void MediaPlayer::LoadMedia(const QString& filepath) {
	VLC::Media media(vlc_instance, filepath.toStdString().c_str(), VLC::Media::FromPath);
	vlc_mp.setMedia(media);
	
	loadedMedia = filepath;
}

void MediaPlayer::Play() {
	if (videoWidget) {
		currentWId = videoWidget->winId();
	} else {
		currentWId = 0;
	}
	
	#if defined(Q_OS_WIN32)
			libvlc_media_player_set_hwnd(vlc_mp, (void *)currentWId);
	#elif defined(Q_OS_DARWIN)
			libvlc_media_player_set_nsobject(vlc_mp, (void *)currentWId);
	#elif defined(Q_OS_UNIX)
			libvlc_media_player_set_xwindow(vlc_mp, currentWId);
	#endif
	
	vlc_mp.play();
}

void MediaPlayer::Pause() {
	if (vlc_mp.canPause())
		vlc_mp.pause();
}

void MediaPlayer::Stop() {
	vlc_mp.stop();
}

void MediaPlayer::ChangePosition(int64_t newPosition) {
	float pos = ((float)newPosition / (float)getDuration());
	if (pos < 0) pos = 0;
	
	vlc_mp.setPosition(pos);
}

// Audio specific
void MediaPlayer::Mute(bool mute) {
	vlc_mp.setMute(mute);
}

void MediaPlayer::ToggleMute() {
	vlc_mp.toggleMute();
}

void MediaPlayer::ChangeVolume(int newVolume) {
	vlc_mp.setVolume(newVolume);
}
