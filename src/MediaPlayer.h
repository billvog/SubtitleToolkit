#pragma once

#include <iostream>

#include <QFrame>
#include <QString>

#include "vlc/vlc.h"

#define MP_POSITION_RESOLUTION 10000

namespace Ui { class MediaPlayer; }

class MediaPlayer {
public:
	MediaPlayer();
	~MediaPlayer();
	
	inline libvlc_event_manager_t* getEventManager() { return libvlc_media_player_event_manager(vlc_mp); }
	
	inline float isPlaying() { return libvlc_media_player_is_playing(vlc_mp); }
	inline float getPosition() { return libvlc_media_player_get_position(vlc_mp); }
	inline float getVolume() { return libvlc_audio_get_volume(vlc_mp); }
	inline bool hasMedia() { return loadedMedia.length() > 0; }
	
	void SetVideoWidget(QFrame* widget);
	
	// Media actions
	void LoadMedia(const QString& filepath);

	void Play();
	void Pause();
	void Stop();
	
	void ChangePosition(float newPosition);
	
	// Audio specific
	void Mute(bool mute);
	void ToggleMute();
	void ChangeVolume(int newVolume);
private:
	libvlc_instance_t* vlc_instance;
	libvlc_media_player_t* vlc_mp;
	libvlc_media_t* vlc_current_media;
	
	QString loadedMedia;
	QFrame* videoWidget;
	WId currentWId;
};
