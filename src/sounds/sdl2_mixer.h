#ifndef RNJ_SOUNDS_SDL2_MIXER_H
#define RNJ_SOUNDS_SDL2_MIXER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#include "log.h"
#include "error.h"
#include "defines.h"

Mix_Chunk **Sound;
Mix_Music **Music;

struct {
    int soundsCount;
    int musicCount;
} Sounds;

void SoundsInit(int, int, unsigned int, int, int);
int SoundsMusicLoad(char *);
int SoundsSoundLoad(char *);
void SoundsSoundPlay(int);
void SoundsSoundSetVolume(int, int);
void SoundsSoundSetChannelsVolume(int);
void SoundsSoundPause(void);
void SoundsSoundResume(void);
void SoundsSoundStop(void);
void SoundsMusicPlay(int);
void SoundsMusicPause(void);
void SoundsMusicResume(void);
void SoundsMusicStop(void);
void SoundsMusicSetVolume(int);
void SoundsDestroy(void);

#endif

