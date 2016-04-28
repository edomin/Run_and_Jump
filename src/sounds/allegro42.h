#ifndef RNJ_SOUNDS_ALLEGRO42_H
#define RNJ_SOUNDS_ALLEGRO42_H

#define ALLEGRO_NO_MAGIC_MAIN
#include "allegro42/allegro.h"

#include "log.h"
#include "error.h"
#include "defines.h"
#include "utils.h"

typedef struct {
    SAMPLE *sample;
    uint8_t volume;
} sound;

typedef struct {
    SAMPLE *sample;
    uint8_t volume;
} music;

sound *Sound;
music *Music;

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