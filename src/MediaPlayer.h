#pragma once

#include <iostream>

#include <QFrame>
#include <QString>

#include "vlcpp/vlc.hpp"

namespace Ui { class MediaPlayer; }

class MediaPlayer {
public:
	MediaPlayer();
	~MediaPlayer();
	
	inline VLC::MediaPlayerEventManager* getEventManager() { return &vlc_mp.eventManager(); }
	
	inline float isPlaying() { return vlc_mp.isPlaying(); }
	
	inline float getPosition() { return vlc_mp.position(); }
	inline int64_t getPositionInMs() { return vlc_mp.time(); }
	inline int64_t getDuration() { return vlc_mp.media()->duration(); }
	
	inline float getVolume() { return vlc_mp.volume(); }
	
	inline bool hasMedia() { return vlc_mp.media() != NULL; }
	inline const QString& getMediaPath() { return loadedMedia; };
	
	inline bool isMuted() { return vlc_mp.mute(); }
	
	void SetVideoWidget(QFrame* widget);
	
	// Media actions
	void LoadMedia(const QString& filepath);
	void UnloadMedia();

	void Play();
	void Pause();
	void Stop();
	
	void ChangePosition(int64_t newPosition);
	
	// Subtitle specific
	bool AddSubtitlesFile(const QString& filepath);
	bool ReloadSubtitles(const QString& filepath);
	
	// Audio specific
	void Mute(bool mute);
	void ToggleMute();
	void ChangeVolume(int newVolume);
private:
	VLC::Instance vlc_instance;
	VLC::MediaPlayer vlc_mp;
	
	QString loadedMedia;
	QString loadedSubtitles;
	
	QFrame* videoWidget;
	WId currentWId;
};
