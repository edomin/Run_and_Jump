#include "sounds/dummy.h"

void SoundsInit(int maxSounds, int maxMusic, unsigned int freq, int channels, int chunksize)
{
    return;
}

int SoundsMusicLoad(char *filename)
{
    return 0;
}

int SoundsSoundLoad(char *filename)
{
    return 0;
}

void SoundsSoundPlay(int soundNumber)
{
    return;
}

void SoundsSoundSetVolume(int soundNumber, int volume) /* volume 0..100 */
{
    return;
}

void SoundsSoundSetChannelsVolume(int volume) /* volume 0..100 */
{
    return;
}

void SoundsSoundPause(void)
{
    return;
}

void SoundsSoundResume(void)
{
    return;
}

void SoundsSoundStop(void)
{
    return;
}

void SoundsMusicPlay(int musicNumber)
{
    return;
}

void SoundsMusicPause(void)
{
    return;
}

void SoundsMusicResume(void)
{
    return;
}

void SoundsMusicStop(void)
{
    return;
}

void SoundsMusicSetVolume(int volume)
{
    return;
}

void SoundsDestroy(void)
{
    return;
}


