#pragma once

#include <iostream>

#include <QFrame>
#include <QString>

#include "vlcpp/vlc.hpp"

#define MP_POSITION_RESOLUTION 10000

namespace Ui { class MediaPlayer; }

class MediaPlayer {
public:
	MediaPlayer();
	~MediaPlayer();
	
	inline VLC::EventManager getEventManager() { return vlc_mp.eventManager(); }
	
	inline float isPlaying() { return vlc_mp.isPlaying(); }
	inline float getPosition() { return vlc_mp.position(); }
	inline float getVolume() { return vlc_mp.volume(); }
	inline bool hasMedia() { return vlc_mp.media() != NULL; }
	
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
	VLC::Instance vlc_instance;
	VLC::MediaPlayer vlc_mp;
	
	QString loadedMedia;
	QFrame* videoWidget;
	WId currentWId;
};
