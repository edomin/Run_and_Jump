#include "sounds/allegro42.h"

void SoundsInit(int maxSounds, int maxMusic, unsigned int freq, int channels,
                int chunksize)
{
    int voices;

    LogWrite("Initializing Sound Manager", 0, MT_INFO, NULL);

    LogWrite("Detects available sound device", 1, MT_INFO, NULL);
    voices = detect_digi_driver(DIGI_AUTODETECT);
    if (voices > 0)
        LogWrite2("Audio device detected. Maximum voices that driver can provide",
                  2, MT_INFO, voices);
    else
        LogWrite("Audio hardware is not present", 2, MT_WARNING, NULL);
    #ifdef PLATFORM_WIN32
    reserve_voices(32, -1);
        LogWrite2("Voices reserved", 1, MT_INFO, 32);
    #endif
    LogWrite("Initialising Allegro sound module", 1, MT_INFO, NULL);
    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL) == 0)
        LogWrite("Allegro sound module initialised", 2, MT_INFO, NULL);
    else
        ErrorGive("Unable to initialise Allegro sound module", 2);
    set_mixer_quality(2);

    Sound = malloc(sizeof(tSound *) * maxSounds);
    if (Sound == NULL)
        ErrorGive("Unable to allocate memory for Sounds", 1);
    Music = malloc(sizeof(tMusic *) * maxMusic);
    if (Music == NULL)
        ErrorGive("Unable to allocate memory for Music", 1);

    LogWrite("Sound Manager initialized", 0, MT_INFO, NULL);
}

int SoundsMusicLoad(char *filename)
{
    Sounds.musicCount += 1;
    Music[Sounds.musicCount - 1].sample = logg_load((const char *)filename);
    Music[Sounds.musicCount - 1].volume = 127;
    if (Sound[Sounds.musicCount - 1].sample != NULL)
        LogWrite("Sound loaded", 0, MT_INFO, NULL);
    else
        ErrorGive("Unable to load sound", 0);
    return Sounds.musicCount - 1;
}

int SoundsSoundLoad(char *filename)
{
    Sounds.soundsCount += 1;
    Sound[Sounds.soundsCount - 1].sample = load_sample((const char *)filename);
    Sound[Sounds.soundsCount - 1].volume = 127;
    if (Sound[Sounds.soundsCount - 1].sample != NULL)
        LogWrite("Sound loaded", 0, MT_INFO, NULL);
    else
        ErrorGive("Unable to load sound", 0);
    return Sounds.soundsCount - 1;
}

void SoundsSoundPlay(int soundNumber)
{
    play_sample((const SAMPLE*)(Sound[soundNumber].sample),
                Sound[soundNumber].volume, 127, 1000, 0);
}

void SoundsSoundSetVolume(int soundNumber, int volume) /* volume 0..100 */
{
    Sound[soundNumber].volume = 255 / 100 * volume;
}

void SoundsSoundSetChannelsVolume(int volume) /* volume 0..100 */
{
    set_volume(255 / 100 * volume, 255 / 100 * volume);
}

void SoundsSoundPause(void)
{
    /* Not supported */
}

void SoundsSoundResume(void)
{
    /* Not supported */
}

void SoundsSoundStop(void)
{
    int i;
    for (i = 0; i < Sounds.soundsCount; i++)
        stop_sample((const SAMPLE*)(Sound[i].sample));
}

void SoundsMusicPlay(int musicNumber)
{
    play_sample((const SAMPLE*)(Music[musicNumber].sample),
                Music[musicNumber].volume, 127, 1000, 0);
}

void SoundsMusicPause(void)
{
    /* Not supported */
}

void SoundsMusicResume(void)
{
    /* Not supported */
}

void SoundsMusicStop(void)
{
    int i;
    for (i = 0; i < Sounds.musicCount; i++)
        stop_sample((const SAMPLE*)(Music[i].sample));
}

void SoundsMusicSetVolume(int volume)
{
    int i;
    for (i = 0; i < Sounds.musicCount; i++)
    {
        Music[i].volume = 255 / 100 * volume;
    }
}

void SoundsDestroy(void)
{
    int i;
    LogWrite("Destroying Sound Manager", 0, MT_INFO, NULL);
    for (i = 0; i < Sounds.soundsCount; i++)
    {
        LogWrite("Freeing sound", 1, MT_INFO, NULL);
        destroy_sample(Sound[i].sample);
    }
    free(Sound);
    for (i = 0; i < Sounds.musicCount; i++)
    {
        LogWrite("Freeing music", 1, MT_INFO, NULL);
        destroy_sample(Music[i].sample);
    }
    free(Music);
    LogWrite("Sound Manager destroyed", 0, MT_INFO, NULL);
}
