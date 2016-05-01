#ifndef RNJ_SOUNDS_ALLEGRO42_H
#define RNJ_SOUNDS_ALLEGRO42_H

#ifdef PLATFORM_WIN32
    #define ALLEGRO_NO_MAGIC_MAIN
#endif
#include "allegro42/allegro.h"
#include "allegro42/logg.h"

#include "log.h"
#include "error.h"
#include "defines.h"
#include "utils.h"

typedef struct {
    SAMPLE *sample;
    uint8_t volume;
} tSound;

typedef struct {
    SAMPLE *sample;
    uint8_t volume;
} tMusic;

tSound *Sound;
tMusic *Music;

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
