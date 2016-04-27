#include "sounds/sdl2_mixer.h"

void SoundsInit(int maxSounds, int maxMusic, unsigned int freq, int channels,
                int chunksize)
{
    int flags;

    int frequency;
    Uint16 format;
    int channelsCount;

    int i;

    SDL_version ctVersion;
    const SDL_version *dllVersion;

    LogWrite("Initializing Sound Manager", 0, MT_INFO, NULL);

    SDL_MIXER_VERSION(&ctVersion)
    LogWrite("Checking SDL_mixer compile-time version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, ctVersion.major);
    LogWrite2("Minor:", 2, MT_INFO, ctVersion.minor);
    LogWrite2("Patch:", 2, MT_INFO, ctVersion.patch);

    dllVersion = Mix_Linked_Version();
    LogWrite("Checking SDL_mixer dll version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, dllVersion->major);
    LogWrite2("Minor:", 2, MT_INFO, dllVersion->minor);
    LogWrite2("Patch:", 2, MT_INFO, dllVersion->patch);

    LogWrite("Checking audio device parameters", 1, MT_INFO, NULL);
    Mix_QuerySpec(&frequency, &format, &channelsCount);
    LogWrite2("Frequency", 2, MT_INFO, freq);
    LogWrite2("Format", 2, MT_INFO, format);
    LogWrite2("Channels count", 2, MT_INFO, channels);

    Sound = malloc(sizeof(Mix_Chunk*) * maxSounds);
    if (Sound == NULL)
        ErrorGive("Can not allocate memory for Sounds", 1);
    Music = malloc(sizeof(Mix_Music*) * maxMusic);
    if (Music == NULL)
        ErrorGive("Can not allocate memory for Music", 1);

    if (SDL_InitSubSystem(SDL_INIT_AUDIO) == 0)
    {
        LogWrite("Audio initialized", 1, MT_INFO, NULL);
    }
    else
    {
        ErrorGive("Can not initialize Audio", 1);
    }

    flags = (MIX_INIT_MP3 | MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MOD);
    if((Mix_Init(flags) & flags) != flags)
        LogWrite("Can not initialize loading of all supported formats", 1,
                 MT_WARNING, NULL);
    else
        LogWrite("Loading of all supported formats initialized", 1,
                 MT_INFO, NULL);

    if (Mix_OpenAudio(freq, MIX_DEFAULT_FORMAT, channels, chunksize) == 0)
    {
        LogWrite("SDL_mixer initialized", 1, MT_INFO, NULL);

        LogWrite("Checking built in SDL_mixer chunk decoders", 1, MT_INFO,
                 NULL);
        for (i = 0; i < Mix_GetNumChunkDecoders(); i++)
        {
            LogWrite((char *)SDLCALL Mix_GetChunkDecoder(i), 2, MT_INFO, NULL);
        }
        LogWrite("Checking built in SDL_mixer music decoders", 1, MT_INFO,
                 NULL);
        for (i = 0; i < Mix_GetNumMusicDecoders(); i++)
        {
            LogWrite((char *)SDLCALL Mix_GetMusicDecoder(i), 2, MT_INFO, NULL);
        }
    }
    else
        ErrorGive("Can not initialize SDL_mixer", 1);
    LogWrite("Sound Manager initialized", 0, MT_INFO, NULL);
}

int SoundsMusicLoad(char *filename)
{
    Sounds.musicCount += 1;
    Music[Sounds.musicCount - 1] = Mix_LoadMUS(filename);
    if (Music[Sounds.musicCount - 1] != NULL)
        LogWrite("Music Loaded", 0, MT_INFO, NULL);
    else
        ErrorGive("Can not load music", 0);
    return Sounds.musicCount - 1;
}

int SoundsSoundLoad(char *filename)
{
    Sounds.soundsCount += 1;
    Sound[Sounds.soundsCount - 1] = Mix_LoadWAV(filename);
    if (Sound[Sounds.soundsCount - 1] != NULL)
        LogWrite("Sound loaded", 0, MT_INFO, NULL);
    else
        ErrorGive("Can not load sound", 0);
    return Sounds.soundsCount - 1;
}

void SoundsSoundPlay(int soundNumber)
{
    Mix_PlayChannel(-1, Sound[soundNumber], 0);
}

void SoundsSoundSetVolume(int soundNumber, int volume) /* volume 0..100 */
{
    Mix_VolumeChunk(Sound[soundNumber], MIX_MAX_VOLUME / 100 * volume);
}

void SoundsSoundSetChannelsVolume(int volume) /* volume 0..100 */
{
    Mix_Volume(-1, MIX_MAX_VOLUME / 100 * volume);
}

void SoundsSoundPause(void)
{
    if (Mix_Playing(-1) > 0)
    {
        Mix_Pause(-1);
    }
}

void SoundsSoundResume(void)
{
    if (Mix_Paused(-1) > 0)
    {
        Mix_Resume(-1);
    }
}

void SoundsSoundStop(void)
{
    Mix_HaltChannel(-1);
}

void SoundsMusicPlay(int musicNumber)
{
    if(Mix_PlayingMusic() == 0)
    {
        Mix_PlayMusic(Music[musicNumber], -1);
    }
    else
    {
        Mix_HaltMusic();
        Mix_PlayMusic(Music[musicNumber], -1);
    }
}

void SoundsMusicPause(void)
{
    if(Mix_PausedMusic() == 0)
    {
        Mix_PauseMusic();
    }
}

void SoundsMusicResume(void)
{
    if(Mix_PausedMusic() == 1)
    {
        Mix_ResumeMusic();
    }
}

void SoundsMusicStop(void)
{
    if (Mix_PlayingMusic() == 1)
    {
        Mix_HaltMusic();
    }
}

void SoundsMusicSetVolume(int volume)
{
    Mix_VolumeMusic(MIX_MAX_VOLUME / 100 * volume);
}

void SoundsDestroy(void)
{
    int i;
    LogWrite("Destroying Sound Manager", 0, MT_INFO, NULL);
    for (i = 0; i < Sounds.soundsCount; i++)
    {
        LogWrite("Freeing sound", 1, MT_INFO, NULL);
        Mix_FreeChunk(Sound[i]);
    }
    for (i = 0; i < Sounds.musicCount; i++)
    {
        LogWrite("Freeing music", 1, MT_INFO, NULL);
        Mix_FreeMusic(Music[i]);
    }
    LogWrite("Closing mixer", 1, MT_INFO, NULL);
    Mix_CloseAudio();
    LogWrite("Unloading libraries", 1, MT_INFO, NULL);
    Mix_Quit();

    LogWrite("Sound Manager destroyed", 0, MT_INFO, NULL);
}

