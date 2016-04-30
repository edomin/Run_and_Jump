include Config.mk

#IA32
ARCH = IA32
#Win32, DOS, KolibriOS
PLATFORM = DOS

CFLAGS =
LDFLAGS =
INCLUDE_DIRS = -Isrc -I$(DIR_PROJECT)/Include
DEFINES =

RNJ_VERSION ="1.3.2"

#sdl12, sdl2, allegro42, allegro5
LAPP = allegro42
#allegro5, iniparser, dummy
LCONFIGFILE = dummy
#sdl12, sdl2, allegro42, allegro5
LSCREEN = allegro42
#sdl12, sdl2, allegro42, allegro5, dummy
LDRAW = allegro42
#sdl12_image, sdl2_image, allegro42, allegro5_image, dummy
LSPRITES = allegro42
#sdl12_ttf, sdl2_ttf, allegro42font, allegro5, dummy
LFONTS = allegro42font
#lua, squirrel, dummy
LS = lua
#sdl2, windows_h, allegro5_nd, native, dummy
LDIALOGS = dummy
#sdl12, sdl2, allegro42, allegro5, native, dummy
LINPUT = allegro42
#sdl2, dummy
LSPEC = dummy
#sdl12, sdl2, time_h, allegro42, allegro5, native
LTIMER = allegro42
#sdl2_mixer, allegro42, dummy
LSOUNDS = allegro42
#freeimage, sdl2_image, allegro5_image, dummy
LIMAGES = dummy
#ode, dummy
LPHYSICS = dummy
#Если ни в одном из подключаемых модулей нет типа bool, то надо включить эту директиву для подключения специальной библиотеки
LBOOL_DEF =

SRC_APP = app/$(LAPP).c
H_APP = app/$(LAPP).h
OBJ_APP = app/$(LAPP).o

SRC_CONFIGFILE = configfile/$(LCONFIGFILE).c
H_CONFIGFILE = configfile/$(LCONFIGFILE).h
OBJ_CONFIGFILE = configfile/$(LCONFIGFILE).o

SRC_SCREEN = screen/$(LSCREEN).c
H_SCREEN = screen/$(LSCREEN).h
OBJ_SCREEN = screen/$(LSCREEN).o

SRC_DRAW = draw/$(LDRAW).c
H_DRAW = draw/$(LDRAW).h
OBJ_DRAW = draw/$(LDRAW).o

SRC_SPRITES = sprites/$(LSPRITES).c
H_SPRITES = sprites/$(LSPRITES).h
OBJ_SPRITES = sprites/$(LSPRITES).o

SRC_FONTS = fonts/$(LFONTS).c
H_FONTS = fonts/$(LFONTS).h
OBJ_FONTS = fonts/$(LFONTS).o

SRC_SCRIPTS = scripts/$(LS).c
H_SCRIPTS = scripts/$(LS).h
OBJ_SCRIPTS = scripts/$(LS).o

SRC_SF = scriptFuncs/$(LS).c
H_SF = scriptFuncs/$(LS).h
OBJ_SF = scriptFuncs/$(LS).o

SRC_DIALOGS = dialogs/$(LDIALOGS).c
H_DIALOGS = dialogs/$(LDIALOGS).h
OBJ_DIALOGS = dialogs/$(LDIALOGS).o

SRC_INPUT = input/$(LINPUT).c
H_INPUT = input/$(LINPUT).h
OBJ_INPUT = input/$(LINPUT).o

SRC_SPEC = specification/$(LSPEC).c
H_SPEC = specification/$(LSPEC).h
OBJ_SPEC = specification/$(LSPEC).o

SRC_TIMER = timer/$(LTIMER).c
H_TIMER = timer/$(LTIMER).h
OBJ_TIMER = timer/$(LTIMER).o

SRC_SOUNDS = sounds/$(LSOUNDS).c
H_SOUNDS = sounds/$(LSOUNDS).h
OBJ_SOUNDS = sounds/$(LSOUNDS).o

SRC_IMAGES = images/$(LIMAGES).c
H_IMAGES = images/$(LIMAGES).h
OBJ_IMAGES = images/$(LIMAGES).o

SRC_PHYSICS = physics/$(LPHYSICS).c
H_PHYSICS = physics/$(LPHYSICS).h
OBJ_PHYSICS = physics/$(LPHYSICS).o

OBJTARGETS = main.o \
	$(OBJ_APP) \
	$(OBJ_CONFIGFILE) \
	$(OBJ_DIALOGS) \
	$(OBJ_DRAW) \
	error.o \
	files.o \
	$(OBJ_FONTS) \
	$(OBJ_IMAGES) \
	$(OBJ_INPUT) \
	log.o \
	$(OBJ_PHYSICS) \
	$(OBJ_SCREEN) \
	scriptFuncs.o \
	$(OBJ_SF) \
	$(OBJ_SCRIPTS) \
	$(OBJ_SOUNDS) \
	$(OBJ_SPEC) \
	$(OBJ_SPRITES) \
	$(OBJ_TIMER) \
	utils.o

OBJS = $(OBJSDIR)/main.o \
	$(OBJSDIR)/$(OBJ_APP) \
	$(OBJSDIR)/$(OBJ_CONFIGFILE) \
	$(OBJSDIR)/$(OBJ_DIALOGS) \
	$(OBJSDIR)/$(OBJ_DRAW) \
	$(OBJSDIR)/error.o \
	$(OBJSDIR)/files.o \
	$(OBJSDIR)/$(OBJ_FONTS) \
	$(OBJSDIR)/$(OBJ_IMAGES) \
	$(OBJSDIR)/$(OBJ_INPUT) \
	$(OBJSDIR)/log.o \
	$(OBJSDIR)/$(OBJ_PHYSICS) \
	$(OBJSDIR)/$(OBJ_SCREEN) \
	$(OBJSDIR)/scriptFuncs.o \
	$(OBJSDIR)/$(OBJ_SF) \
	$(OBJSDIR)/$(OBJ_SCRIPTS) \
	$(OBJSDIR)/$(OBJ_SOUNDS) \
	$(OBJSDIR)/$(OBJ_SPEC) \
	$(OBJSDIR)/$(OBJ_SPRITES) \
	$(OBJSDIR)/$(OBJ_TIMER) \
	$(OBJSDIR)/utils.o

.PHONY: all defines FORCE clean remake copy_utils mk_out_dir build path

all: defines path mk_out_dir RnJ1

#Настроить переменные и параметры сборки
defines: FORCE
vpath %.c $(SRCDIR)
vpath %.h $(SRCDIR)
vpath %.o $(OBJSDIR)
LIBS =
DLLS =
RNJ_SPEC = -DRNJ_VERSION=\"$(RNJ_VERSION)\" \
	-DRNJ_APP=\"$(LAPP)\" \
	-DRNJ_CONFIGFILE=\"$(LCONFIGFILE)\" \
	-DRNJ_SCREEN=\"$(LSCREEN)\" \
	-DRNJ_DRAW=\"$(LDRAW)\" \
	-DRNJ_SPRITES=\"$(LSPRITES)\" \
	-DRNJ_FONTS=\"$(LFONTS)\" \
	-DRNJ_SCRIPT=\"$(LS)\" \
	-DRNJ_DIALOGS=\"$(LDIALOGS)\" \
	-DRNJ_INPUT=\"$(LINPUT)\" \
	-DRNJ_SPEC=\"$(LSPEC)\" \
	-DRNJ_TIMER=\"$(LTIMER)\" \
	-DRNJ_SOUNDS=\"$(LSOUNDS)\" \
	-DRNJ_IMAGES=\"$(LIMAGES)\" \
	-DRNJ_PHYSICS=\"$(LPHYSICS)\"
############ = FONTS = ########
ifeq ($(LFONTS), sdl12_ttf)
  LFONTS_DEF = -DLFONTS_SDL12_TTF
  LIBS += -lSDL_ttf
  ifeq ($(CC), $(CC_KOS))
    LIBS += -lfreetype
  endif
  ifeq ($(CC), $(CC_MINGW))
    DLLS += $(DLL_SDL12_TTF) \
	  $(DLL_FREE_TYPE)
  endif
endif
ifeq ($(LFONTS), sdl2_ttf)
  LFONTS_DEF = -DLFONTS_SDL2_TTF
  LIBS += -lSDL2_ttf
  DLLS += $(DLL_SDL2_TTF) \
	$(DLL_FREE_TYPE)
endif
ifeq ($(LFONTS), allegro42font)
  LFONTS_DEF = -DLFONTS_ALLEGRO42_FONT
  LIBS += -lalfont
endif
ifeq ($(LFONTS), allegro5)
  LFONTS_DEF = -DLFONTS_ALLEGRO5
  LIBS += -lallegro_ttf-5.0.10-md \
	-lallegro_font-5.0.10-md
  DLLS += $(DLL_ALLEGRO5_TTF) \
	$(DLL_ALLEGRO5_FONT)
endif
ifeq ($(LFONTS), dummy)
  LFONTS_DEF = -DLFONTS_DUMMY
endif
############ = SPRITES = ########
ifeq ($(LSPRITES), sdl12_image)
  LSPRITES_DEF = -DLSPRITES_SDL12_IMAGE
  LIBS += -lSDL_image
  ifeq ($(CC), $(CC_KOS))
    LIBS += -lpng \
      -ljpeg \
      -lz
  endif
  ifeq ($(CC), $(CC_MINGW))
    DLLS += $(DLL_SDL12_IMAGE) \
	  $(DLL_JPEG_8) \
	  $(DLL_PNG_15) \
	  $(DLL_TIFF) \
	  $(DLL_WEBP_2)
  endif
endif
ifeq ($(LSPRITES), sdl2_image)
  LSPRITES_DEF = -DLSPRITES_SDL2_IMAGE
  LIBS += -lSDL2_image
  DLLS += $(DLL_SDL2_IMAGE) \
	$(DLL_JPEG_9) \
	$(DLL_PNG_16) \
	$(DLL_TIFF) \
	$(DLL_WEBP_4)
endif
ifeq ($(LSPRITES), allegro42)
  LSPRITES_DEF = -DLSPRITES_ALLEGRO42
  LIBS += -lldpng \
    -lpng \
    -lz
endif
ifeq ($(LSPRITES), allegro5_image)
  LSPRITES_DEF = -DLSPRITES_ALLEGRO5_IMAGE
  LIBS += -lallegro_image-5.0.10-md
  DLLS += $(DLL_ALLEGRO5_IMAGE)
endif
ifeq ($(LSPRITES), dummy)
  LSPRITES_DEF = -DLSPRITES_DUMMY
endif
############ = SOUNDS = ########
ifeq ($(LSOUNDS), sdl2_mixer)
  LSOUNDS_DEF = -DLSOUNDS_SDL2_MIXER
  LIBS += -lSDL2_mixer
  DLLS += $(DLL_SDL2_MIXER) \
	$(DLL_FLAC) \
	$(DLL_MODPLUG) \
	$(DLL_OGG) \
	$(DLL_VORBIS) \
	$(DLL_VORBISFILE) \
	$(DLL_SMPEG2)
endif
ifeq ($(LSOUNDS), allegro42)
  LSOUNDS_DEF = -DLSOUNDS_ALLEGRO42
  LIBS += -llogg \
	-lvorbisfile \
	-lvorbis \
	-logg
endif
ifeq ($(LSOUNDS), dummy)
  LSOUNDS_DEF = -DLSOUNDS_DUMMY
endif
############ = APP = ########
ifeq ($(LAPP), sdl12)
  LAPP_DEF = -DLAPP_SDL12
  DLLS += $(DLL_README_SDL_TXT)
  ifeq ($(CC), $(CC_KOS))
    LIBS += -lSDL12
  endif
  ifeq ($(CC), $(CC_MINGW))
    LIBS += -lmingw32 \
      -lSDLmain \
      -lSDL.dll
    DLLS += $(DLL_SDL12) \
      $(DLL_ZLIB)
  endif
endif
ifeq ($(LAPP), sdl2)
  LAPP_DEF = -DLAPP_SDL2
  LIBS += -lmingw32 \
	  -lSDL2main \
	  -lSDL2
  DLLS += $(DLL_SDL2) \
	$(DLL_ZLIB) \
	$(DLL_README_SDL_TXT)
endif
ifeq ($(LAPP), allegro42)
  LAPP_DEF = -DLAPP_ALLEGRO42
  LIBS += -lalleg42
  INCLUDE_DIRS += -I$(DIR_PROJECT)/Include/allegro42
  ifeq ($(PLATFORM), DOS)
    CFLAGS += -UALLEGRO_MINGW32 -DALLEGRO_DJGPP -DALLEGRO_HAVE_INTTYPES_H
  endif
endif
ifeq ($(LAPP), allegro5)
  LAPP_DEF = -DLAPP_ALLEGRO5
  LIBS += -lallegro-5.0.10-md
  DLLS += $(DLL_ALLEGRO5)
  INCLUDE_DIRS += -I$(DIR_PROJECT)/Include/allegro5
  LBOOL_DEF = -DBOOLLIB=\"allegro5/allegro.h\"
endif
############ = CONFIGFILE = ########
ifeq ($(LCONFIGFILE), allegro5)
  LCONFIGFILE_DEF = -DLCONFIGFILE_ALLEGRO5
endif
ifeq ($(LCONFIGFILE), iniparser)
  LCONFIGFILE_DEF = -DLCONFIGFILE_INIPARSER
  LIBS += -liniparser
  INCLUDE_DIRS += -I$(DIR_PROJECT)/Include/iniparser
endif
ifeq ($(LCONFIGFILE), dummy)
  LCONFIGFILE_DEF = -DLCONFIGFILE_DUMMY
endif
############ = SCREEN = ########
ifeq ($(LSCREEN), sdl12)
  LSCREEN_DEF = -DLSCREEN_SDL12
endif
ifeq ($(LSCREEN), sdl2)
  LSCREEN_DEF = -DLSCREEN_SDL2
endif
ifeq ($(LSCREEN), allegro42)
  LSCREEN_DEF = -DLSCREEN_ALLEGRO42
endif
ifeq ($(LSCREEN), allegro5)
  LSCREEN_DEF = -DLSCREEN_ALLEGRO5
endif
############ = DRAW = ########
ifeq ($(LDRAW), sdl12)
  LDRAW_DEF = -DLDRAW_SDL12
endif
ifeq ($(LDRAW), sdl2)
  LDRAW_DEF = -DLDRAW_SDL2
endif
ifeq ($(LDRAW), allegro42)
  LDRAW_DEF = -DLDRAW_ALLEGRO42
endif
ifeq ($(LDRAW), allegro5)
  LDRAW_DEF = -DLDRAW_ALLEGRO5
  LIBS += -lallegro_primitives-5.0.10-md
  DLLS += $(DLL_ALLEGRO5_PRIMITIVES)
endif
ifeq ($(LDRAW), dummy)
  LDRAW_DEF = -DLDRAW_DUMMY
endif
############ = SCRIPTS = ########
ifeq ($(LS), lua)
  LS_DEF = -DLS_LUA
  LIBS += -llua52
  ifeq ($(PLATFORM), Win32)
    DLLS += $(DLL_LUA)
  endif
  INCLUDE_DIRS += -I$(DIR_PROJECT)/Include/lua
endif
ifeq ($(LS), squirrel)
  LS_DEF = -DLS_SQUIRREL
  LIBS += -lsquirrel
  DLLS += $(DLL_SQUIRREL)
  INCLUDE_DIRS += -I$(DIR_PROJECT)/Include/squirrel
endif
ifeq ($(LS), dummy)
  LS_DEF = -DLS_DUMMY
endif
############ = DIALOGS = ########
ifeq ($(LDIALOGS), sdl2)
  LDIALOGS_DEF = -DLDIALOGS_SDL2
endif
ifeq ($(LDIALOGS), allegro5_nd)
  LDIALOGS_DEF = -DLDIALOGS_ALLEGRO5_ND
  LIBS += -lallegro_dialog-5.0.10-md
  DLLS += $(DLL_ALLEGRO5_DIALOG)
endif
ifeq ($(LDIALOGS), windows_h)
  LDIALOGS_DEF = -DLDIALOGS_WINDOWS_H
endif
ifeq ($(LDIALOGS), native)
  LDIALOGS_DEF = -DLDIALOGS_NATIVE
endif
ifeq ($(LDIALOGS), dummy)
  LDIALOGS_DEF = -DLDIALOGS_DUMMY
endif
############ = INPUT = ########
ifeq ($(LINPUT), sdl12)
  LINPUT_DEF = -DLINPUT_SDL12
endif
ifeq ($(LINPUT), sdl2)
  LINPUT_DEF = -DLINPUT_SDL2
  DLLS += $(DLL_GAME_CONTROLLER_DB_TXT)
endif
ifeq ($(LINPUT), allegro42)
  LINPUT_DEF = -DLINPUT_ALLEGRO42
endif
ifeq ($(LINPUT), allegro5)
  LINPUT_DEF = -DLINPUT_ALLEGRO5
endif
ifeq ($(LINPUT), native)
  LINPUT_DEF = -DLINPUT_NATIVE
endif
ifeq ($(LINPUT), dummy)
  LINPUT_DEF = -DLINPUT_DUMMY
endif
############ = SPEC = ########
ifeq ($(LSPEC), sdl2)
  LSPEC_DEF = -DLSPEC_SDL2
endif
ifeq ($(LSPEC), dummy)
  LSPEC_DEF = -DLSPEC_DUMMY
endif
############ = TIMER = ########
ifeq ($(LTIMER), sdl12)
  LTIMER_DEF = -DLTIMER_SDL12
endif
ifeq ($(LTIMER), sdl2)
  LTIMER_DEF = -DLTIMER_SDL2
endif
ifeq ($(LTIMER), time_h)
  LTIMER_DEF = -DLTIMER_TIME_H
endif
ifeq ($(LTIMER), allegro42)
  LTIMER_DEF = -DLTIMER_ALLEGRO42
endif
ifeq ($(LTIMER), allegro5)
  LTIMER_DEF = -DLTIMER_ALLEGRO5
endif
ifeq ($(LTIMER), native)
  LTIMER_DEF = -DLTIMER_NATIVE
endif
############ = IMAGES = ########
ifeq ($(LIMAGES), freeimage)
  LIMAGES_DEF = -DLIMAGES_FREEIMAGE
  LIBS += -lFreeImage
  DLLS += $(DLL_FREE_IMAGE)
  INCLUDE_DIRS += -I$(DIR_PROJECT)/Include/FreeImage
endif
ifeq ($(LIMAGES), sdl2_image)
  LIMAGES_DEF = -DLIMAGES_SDL2_IMAGE
endif
ifeq ($(LIMAGES), allegro5_image)
  LIMAGES_DEF = -DLIMAGES_ALLEGRO5_IMAGE
endif
ifeq ($(LIMAGES), dummy)
  LIMAGES_DEF = -DLIMAGES_DUMMY
endif
############ = PHYSICS = ########
ifeq ($(LPHYSICS), ode)
  LPHYSICS_DEF = -DLPHYSICS_ODE
  LIBS += -lode_single
  DLLS += $(DLL_ODE)
  INCLUDE_DIRS += -I$(DIR_PROJECT)/Include/ode
endif
ifeq ($(LPHYSICS), dummy)
  LPHYSICS_DEF = -DLPHYSICS_DUMMY
endif
############ = BOOL = ########
ifeq ($(strip $(LBOOL_DEF)),)
  LBOOL_DEF = -DBOOLLIB=\"bool.h\"
  INCLUDE_DIRS += -I$(DIR_PROJECT)/Include/bool
endif
########## = PLATFORM = #########
#Compiler, Linker and options
ifeq ($(PLATFORM), Win32)
  TOOLCHAIN = $(TC_MINGW_4_8_1)
  CC = $(DIR_TOOLCHAINS)/$(TOOLCHAIN)/bin/$(CC_MINGW)
  LD = $(DIR_TOOLCHAINS)/$(TOOLCHAIN)/bin/$(LD_MINGW)
endif
ifeq ($(PLATFORM), DOS)
  TOOLCHAIN = $(TC_DJGPP_MINGW_5_1_0)
  CC = $(DIR_TOOLCHAINS)/$(TOOLCHAIN)/bin/$(CC_DJGPP_MINGW)
  LD = $(DIR_TOOLCHAINS)/$(TOOLCHAIN)/bin/$(LD_DJGPP_MINGW)
endif
ifeq ($(PLATFORM), KolibriOS)
  TOOLCHAIN = $(TC_KOS_4_8_2)
  CC = $(DIR_TOOLCHAINS)/$(TOOLCHAIN)/bin/$(CC_KOS)
  LD = $(DIR_TOOLCHAINS)/$(TOOLCHAIN)/bin/$(LD_KOS)
endif

ifeq ($(PLATFORM), Win32)
  CFLAGS += -c -Wall
  LDFLAGS += -s -mwindows
  DEFINES += -DPLATFORM_WIN32
endif
ifeq ($(PLATFORM), DOS)
  CFLAGS += -c -Wall
  LIBS += -lc -lgcc
  DEFINES += -DPLATFORM_DOS
endif
ifeq ($(PLATFORM), KolibriOS)
  CFLAGS += -c -O2 -fomit-frame-pointer -U__WIN32__ -U_Win32 -U_WIN32 -U__MINGW32__ -UWIN32 -Wall
  LDFLAGS += -static -S -nostdlib -Tapp.lds -Map test.map --image-base 0 -L$(DIR_TOOLCHAINS)/$(TOOLCHAIN)/mingw32/lib \
    -L$(DIR_TOOLCHAINS)/$(TOOLCHAIN)/libc
  LIBS += -lmenuet_os_h -lgcc -lapp -lc.dll
  INCLUDE_DIRS += -I$(DIR_TOOLCHAINS)/$(TOOLCHAIN)/libc/include
  DEFINES += -DPLATFORM_KOLIBRIOS
endif
DEFINES += $(LBOOL_DEF) \
	$(LAPP_DEF) \
	$(LCONFIGFILE_DEF) \
	$(LSCREEN_DEF) \
	$(LDRAW_DEF) \
	$(LSPRITES_DEF) \
	$(LFONTS_DEF) \
	$(LS_DEF) \
	$(LDIALOGS_DEF) \
	$(LINPUT_DEF) \
	$(LSPEC_DEF) \
	$(LTIMER_DEF) \
	$(LSOUNDS_DEF) \
	$(LIMAGES_DEF) \
	$(LPHYSICS_DEF)
PATH += :$(DIR_TOOLCHAINS)/$(TOOLCHAIN)/bin

#Устанавливаем директории поиска исполняемых файлов (компилятора и т. д.)
path: FORCE
ifneq ($(PLATFORM), DOS)
	export PATH
endif

#Создать директории для объектных файлов
mk_out_dir: FORCE
	-mkdir obj/$(ARCH)
	-mkdir obj/$(ARCH)/$(PLATFORM)
	-mkdir obj/$(ARCH)/$(PLATFORM)/$(TOOLCHAIN)

#Очистка директории объектных файлов
clean: FORCE
	-rm -f -r $(OBJSDIR)/*

#Перекомпиляция
remake: clean defines RnJ1

#Копирование скомпилированной программы, длл-ок, игровых модулей и дополнительных утилит в папку билда
full_build: build copy_utils

#Копирование дополнительных утилит в папку билда (только для Win32)
copy_utils: FORCE
ifeq ($(PLATFORM), DOS)
	-cp $(DIR_PROJECT)/Utils/*.* $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(PLATFORM)/
else
	-cp -t $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(PLATFORM)/ $(DIR_PROJECT)/Utils/*.*
endif

#Копирование скомпилированной программы, длл-ок и игровых модулей в папку билда
build: defines RnJ1 FORCE
	-rm -f -r $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(ARCH)/$(PLATFORM)/*
	-mkdir $(DIR_ROOT)/Builds
	-mkdir $(DIR_ROOT)/Builds/$(RNJ_VERSION)
	-mkdir $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(ARCH)
	-mkdir $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(ARCH)/$(PLATFORM)
ifeq ($(PLATFORM), DOS)
	-cp bin/RNJ1.exe $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(ARCH)/$(PLATFORM)/
	-cp $(DLLS) $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(ARCH)/$(PLATFORM)/
	-cp -R $(DIR_PROJECT)/Mods/* $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(ARCH)/$(PLATFORM)/
else
	-cp -t $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(ARCH)/$(PLATFORM)/ bin/RNJ1.exe
	-cp -t $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(ARCH)/$(PLATFORM)/ $(DLLS)
	-cp -R -t $(DIR_ROOT)/Builds/$(RNJ_VERSION)/$(ARCH)/$(PLATFORM)/ $(DIR_PROJECT)/Mods/*
endif

RnJ1: $(OBJTARGETS)
	$(LD) -o bin/RnJ1 $(LDFLAGS) $(OBJS) -L$(DIR_PROJECT)/Lib/$(TOOLCHAIN) $(LIBS)
  ifeq ($(CC), $(CC_KOS))
	$(OBJCOPY) bin/RnJ1 -O binary
#	$(KPACK) bin/RnJ1
  endif

main.o: main.c defines.h scripts.h log.h error.h specification.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) $(RNJ_SPEC) -o $(OBJSDIR)/main.o $(SRCDIR)/main.c

$(OBJ_APP): $(SRC_APP) $(H_APP) log.h error.h defines.h
	-mkdir $(OBJSDIR)/app
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/app/$(LAPP).o $(SRCDIR)/$(SRC_APP)

$(OBJ_CONFIGFILE): $(SRC_CONFIGFILE) $(H_CONFIGFILE)
	-mkdir $(OBJSDIR)/configfile
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/configfile/$(LCONFIGFILE).o $(SRCDIR)/$(SRC_CONFIGFILE)

$(OBJ_DIALOGS): $(SRC_DIALOGS) $(H_DIALOGS) screen.h defines.h
	-mkdir $(OBJSDIR)/dialogs
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/dialogs/$(LDIALOGS).o $(SRCDIR)/$(SRC_DIALOGS)

$(OBJ_DRAW): $(SRC_DRAW) $(H_DRAW) screen.h sprites.h defines.h
	-mkdir $(OBJSDIR)/draw
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/draw/$(LDRAW).o $(SRCDIR)/$(SRC_DRAW)

error.o: error.c error.h dialogs.h log.h defines.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/error.o $(SRCDIR)/error.c

files.o: files.c files.h defines.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/files.o $(SRCDIR)/files.c

$(OBJ_FONTS): $(SRC_FONTS) $(H_FONTS) log.h error.h defines.h
	-mkdir $(OBJSDIR)/fonts
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/fonts/$(LFONTS).o $(SRCDIR)/$(SRC_FONTS)

$(OBJ_IMAGES): $(SRC_IMAGES) $(H_IMAGES) log.h error.h defines.h
	-mkdir $(OBJSDIR)/images
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/images/$(LIMAGES).o $(SRCDIR)/$(SRC_IMAGES)

$(OBJ_INPUT): $(SRC_INPUT) $(H_INPUT) log.h app.h defines.h
	-mkdir $(OBJSDIR)/input
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/input/$(LINPUT).o $(SRCDIR)/$(SRC_INPUT)

log.o: log.c log.h files.h utils.h defines.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/log.o $(SRCDIR)/log.c

$(OBJ_PHYSICS): $(SRC_PHYSICS) $(H_PHYSICS) log.h
	-mkdir $(OBJSDIR)/physics
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/physics/$(LPHYSICS).o $(SRCDIR)/$(SRC_PHYSICS)

$(OBJ_SCREEN): $(SRC_SCREEN) $(H_SCREEN) log.h error.h defines.h
	-mkdir $(OBJSDIR)/screen
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/screen/$(LSCREEN).o $(SRCDIR)/$(SRC_SCREEN)

scriptFuncs.o: scriptFuncs.c scriptFuncs.h scripts.h app.h configfile.h screen.h draw.h input.h timer.h sounds.h \
  images.h physics.h files.h dialogs.h log.h utils.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/scriptFuncs.o $(SRCDIR)/scriptFuncs.c

$(OBJ_SF): $(SRC_SF) $(H_SF) scripts.h app.h configfile.h screen.h draw.h input.h timer.h sounds.h images.h physics.h \
  files.h dialogs.h log.h
	-mkdir $(OBJSDIR)/scriptFuncs
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/scriptFuncs/$(LS).o $(SRCDIR)/$(SRC_SF)

$(OBJ_SCRIPTS): $(SRC_SCRIPTS) $(H_SCRIPTS) log.h error.h scriptFuncs.h defines.h
	-mkdir $(OBJSDIR)/scripts
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/scripts/$(LS).o $(SRCDIR)/$(SRC_SCRIPTS)

$(OBJ_SOUNDS): $(SRC_SOUNDS) $(H_SOUNDS) log.h error.h defines.h
	-mkdir $(OBJSDIR)/sounds
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/sounds/$(LSOUNDS).o $(SRCDIR)/$(SRC_SOUNDS)

$(OBJ_SPEC): $(SRC_SPEC) $(H_SPEC) utils.h log.h
	-mkdir $(OBJSDIR)/specification
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/specification/$(LSPEC).o $(SRCDIR)/$(SRC_SPEC)

$(OBJ_SPRITES): $(SRC_SPRITES) $(H_SPRITES) app.h draw.h fonts.h error.h log.h defines.h
	-mkdir $(OBJSDIR)/sprites
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/sprites/$(LSPRITES).o $(SRCDIR)/$(SRC_SPRITES)

$(OBJ_TIMER): $(SRC_TIMER) $(H_TIMER) defines.h log.h error.h
	-mkdir $(OBJSDIR)/timer
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/timer/$(LTIMER).o $(SRCDIR)/$(SRC_TIMER)

utils.o: utils.c utils.h defines.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(DEFINES) -o $(OBJSDIR)/utils.o $(SRCDIR)/utils.c

$(H_APP):

$(H_CONFIGFILE):

$(H_SCREEN):

$(H_DRAW):

$(H_SPRITES):

$(H_FONTS):

$(H_SCRIPTS):

$(H_SF):

$(H_DIALOGS):

$(H_INPUT):

$(H_SPEC):

$(H_TIMER):

$(H_SOUNDS):

$(H_IMAGES):

$(H_PHYSICS):

FORCE:
