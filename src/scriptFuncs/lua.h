#ifndef RNJ_SF_LUA_H
#define RNJ_SF_LUA_H

#include <math.h>
#include <stdlib.h>

#include BOOLLIB

#include "scripts.h"
#include "app.h"
#include "configfile.h"
#include "screen.h"
#include "draw.h"
#include "input.h"
#include "timer.h"
#include "sounds.h"
#include "images.h"
#include "physics.h"
#include "files.h"
#include "dialogs.h"
#include "log.h"

int SFInitApp(lua_State*);
int SFInitScreen(lua_State*);
int SFInitDraw(lua_State*);
int SFInitInput(lua_State*);
int SFInitTimer(lua_State*);
int SFInitSprites(lua_State*);
int SFInitFonts(lua_State*);
int SFInitSounds(lua_State*);
int SFInitImages(lua_State*);
int SFInitPhysics(lua_State*);

int SFConfigfileCreateConfig(lua_State*);
int SFConfigfileLoadConfig(lua_State*);
int SFConfigfileSaveConfig(lua_State*);
int SFConfigfileAddSection(lua_State*);
int SFConfigfileSetKeyValue(lua_State*);
int SFConfigfileGetKeyValue(lua_State*);

int SFFontLoad(lua_State*);
int SFSpriteLoad(lua_State*);
int SFSpriteCreateText(lua_State*);
int SFSpriteCreateTextWrapped(lua_State*);
int SFSpriteChangeText(lua_State*);
int SFSpriteChangeTextWrapped(lua_State*);
int SFSpriteGetClipWidthHeight(lua_State*);

int SFFlip(lua_State*);
int SFTimerStart(lua_State*);
int SFDelay(lua_State*);
int SFDelayForFPS(lua_State*);
int SFXed(lua_State*);
int SFKeyPress(lua_State*);
int SFKeyRelease(lua_State*);
int SFKeyPressed(lua_State*);
int SFKeystatesRefresh(lua_State*);
int SFMouseRefresh(lua_State*);
int SFMouseGetCoords(lua_State*);
int SFMousePressed(lua_State*);
int SFMousePress(lua_State*);
int SFMouseRelease(lua_State*);
int SFMouseCursorShow(lua_State*);
int SFMouseCursorHide(lua_State*);
int SFControllerRefresh(lua_State*);
int SFControllerPress(lua_State*);
int SFControllerRelease(lua_State*);
int SFControllerPressed(lua_State*);
int SFControllerGetAxis(lua_State*);

int SFDestroySprites(lua_State*);
int SFDestroyFonts(lua_State*);
int SFDestroySounds(lua_State*);
int SFDestroyImages(lua_State*);
int SFDestroyInput(lua_State*);
int SFDestroyPhysics(lua_State*);
int SFDestroyDraw(lua_State*);
int SFDestroyScreen(lua_State*);
int SFDestroyApp(lua_State*);

int SFDrawAddSprite(lua_State*);
int SFDrawAddSpriteSized(lua_State*);
int SFDrawAddSpriteAngled(lua_State*);
int SFDrawAddSpriteAlpha(lua_State*);
int SFDrawAddSpriteGeneral(lua_State*);
int SFDrawPoint(lua_State*);
int SFDrawPointAlpha(lua_State*);
int SFDrawLine(lua_State*);
int SFDrawLineAlpha(lua_State*);
int SFDrawRect(lua_State*);
int SFDrawRectAlpha(lua_State*);
int SFDrawFilledRect(lua_State*);
int SFDrawFilledRectAlpha(lua_State*);
int SFDrawFill(lua_State*);
int SFDrawFillAlpha(lua_State*);
int SFDrawOutput(lua_State*);

int SFAbs(lua_State*);
int SFSign(lua_State*);
int SFAcos(lua_State*);
int SFAsin(lua_State*);
int SFAtan(lua_State*);
int SFCeil(lua_State*);
int SFCos(lua_State*);
int SFRandom(lua_State*);
int SFRandomRange(lua_State*);
int SFFloor(lua_State*);
int SFLn(lua_State*);
int SFLg(lua_State*);
int SFLb(lua_State*);
int SFSin(lua_State*);
int SFSqrt(lua_State*);
int SFTan(lua_State*);
int SFCbrt(lua_State*);
int SFMax(lua_State*);
int SFMin(lua_State*);
int SFRound(lua_State*);
int SFVectorLength(lua_State*);
int SFVectorDirection(lua_State*);
int SFVectorXY(lua_State*);

int SFMusicLoad(lua_State*);
int SFSoundLoad(lua_State*);
int SFSoundPlay(lua_State*);
int SFSoundSetVolume(lua_State*);
int SFSoundSetChannelsVolume(lua_State*);
int SFSoundPause(lua_State*);
int SFSoundResume(lua_State*);
int SFSoundStop(lua_State*);
int SFMusicPlay(lua_State*);
int SFMusicPause(lua_State*);
int SFMusicResume(lua_State*);
int SFMusicStop(lua_State*);
int SFMusicSetVolume(lua_State*);

int SFPhysicsBlockCreate(lua_State*);
int SFPhysicsObjectCreate(lua_State*);
int SFPhysicsObjectRefreshStats(lua_State*);
int SFPhysicsStep(lua_State*);

int SFBitmapCreate(lua_State*);
int SFBitmapSave(lua_State*);
int SFBitmapSetPixel(lua_State*);

int SFFileOpen(lua_State*);
int SFFileClose(lua_State*);
int SFFileWriteLine(lua_State*);
int SFDialogShowSimpleMessageBox(lua_State*);
int SFDialogShowYesNoMessageBox(lua_State*);
int SFLogWrite(lua_State*);
int SFScriptRegisterNumericVariable(lua_State*);
int SFScriptRegisterStringVariable(lua_State*);

#endif
