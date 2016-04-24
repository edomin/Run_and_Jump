#Directories
DIR_ROOT = ../..
DIR_PROJECT = $(DIR_ROOT)/Project
DIR_TOOLCHAINS = $(DIR_ROOT)/Toolchains
DLLPATH = $(DIR_PROJECT)/Additional/$(ARCH)/$(PLATFORM)
SRCDIR = src
OBJSDIR = obj/$(ARCH)/$(PLATFORM)/$(TOOLCHAIN)
MTOOLS = $(DIR_ROOT)/Utils/mtools

#Toolchains
TC_MINGW_4_8_1 = MinGW_4.8.1
TC_DJGPP_2_03 = DJGPP_2.03
TC_KOS_4_8_2 = KOS_4.8.2

#Compilers
CC_MINGW = mingw32-gcc
CC_DJGPP = gcc
CC_KOS = kos32-gcc

#Linkers
LD_MINGW = mingw32-gcc
LD_DJGPP = gcc
LD_KOS = kos32-ld

#Utils
OBJCOPY = $(DIR_TOOLCHAINS)/$(TOOLCHAIN)/bin/kos32-objcopy
MCOPY = $(MTOOLS)/mcopy
KPACK = $(DIR_TOOLCHAINS)/$(TOOLCHAIN)/bin/kpack

#Dll's
DLL_ALLEGRO5 = $(DLLPATH)/allegro-5.0.10-md.dll
DLL_ALLEGRO5_DIALOG = $(DLLPATH)/allegro_dialog-5.0.10-md.dll
DLL_ALLEGRO5_FONT = $(DLLPATH)/allegro_font-5.0.10-md.dll
DLL_ALLEGRO5_TTF = $(DLLPATH)/allegro_ttf-5.0.10-md.dll
DLL_ALLEGRO5_IMAGE = $(DLLPATH)/allegro_image-5.0.10-md.dll
DLL_ALLEGRO5_PRIMITIVES = $(DLLPATH)/allegro_primitives-5.0.10-md.dll

DLL_FREE_IMAGE = $(DLLPATH)/FreeImage.dll

DLL_SDL12 = $(DLLPATH)/SDL.dll
DLL_SDL12_IMAGE = $(DLLPATH)/SDL_image.dll
DLL_SDL12_TTF = $(DLLPATH)/SDL_ttf.dll

DLL_SDL2 = $(DLLPATH)/SDL2.dll
DLL_SDL2_IMAGE = $(DLLPATH)/SDL2_image.dll
DLL_SDL2_MIXER = $(DLLPATH)/SDL2_mixer.dll
DLL_SDL2_TTF = $(DLLPATH)/SDL2_ttf.dll
DLL_README_SDL_TXT = $(DLLPATH)/README-SDL.txt
DLL_GAME_CONTROLLER_DB_TXT = $(DLLPATH)/gamecontrollerdb.txt

DLL_INIPARSER = $(DLLPATH)/iniparser.dll

DLL_FLAC = $(DLLPATH)/libFLAC-8.dll
DLL_MODPLUG = $(DLLPATH)/libmodplug-1.dll
DLL_OGG = $(DLLPATH)/libogg-0.dll
DLL_VORBIS = $(DLLPATH)/libvorbis-0.dll
DLL_VORBIS_FILE = $(DLLPATH)/libvorbisfile-3.dll
DLL_SMPEG = $(DLLPATH)/smpeg2.dll

DLL_FREE_TYPE = $(DLLPATH)/libfreetype-6.dll

DLL_JPEG_8 = $(DLLPATH)/libjpeg-8.dll
DLL_JPEG_9 = $(DLLPATH)/libjpeg-9.dll
DLL_PNG_15 = $(DLLPATH)/libpng15-15.dll
DLL_PNG_16 = $(DLLPATH)/libpng16-16.dll
DLL_TIFF = $(DLLPATH)/libtiff-5.dll
DLL_WEBP_2 = $(DLLPATH)/libwebp-2.dll
DLL_WEBP_4 = $(DLLPATH)/libwebp-4.dll

DLL_OPEN_INPUT = $(DLLPATH)/libopeninput-0-2-1.dll

DLL_LUA = $(DLLPATH)/lua52.dll

DLL_SQUIRREL = $(DLLPATH)/squirrel.dll

DLL_ODE = $(DLLPATH)/ode_single.dll

DLL_ZLIB = $(DLLPATH)/zlib1.dll
