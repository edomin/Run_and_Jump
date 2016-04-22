#ifndef RNJ_SF_SQUIRREL_H
#define RNJ_SF_SQUIRREL_H

#include <math.h>
#include <stdlib.h>

#include "bool.h"

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

SQInteger SFInitApp(HSQUIRRELVM);
SQInteger SFInitScreen(HSQUIRRELVM);
SQInteger SFInitDraw(HSQUIRRELVM);
SQInteger SFInitInput(HSQUIRRELVM);
SQInteger SFInitTimer(HSQUIRRELVM);
SQInteger SFInitSprites(HSQUIRRELVM);
SQInteger SFInitFonts(HSQUIRRELVM);
SQInteger SFInitSounds(HSQUIRRELVM);
SQInteger SFInitImages(HSQUIRRELVM);
SQInteger SFInitPhysics(HSQUIRRELVM);

SQInteger SFConfigfileCreateConfig(HSQUIRRELVM);
SQInteger SFConfigfileLoadConfig(HSQUIRRELVM);
SQInteger SFConfigfileSaveConfig(HSQUIRRELVM);
SQInteger SFConfigfileAddSection(HSQUIRRELVM);
SQInteger SFConfigfileSetKeyValue(HSQUIRRELVM);
SQInteger SFConfigfileGetKeyValue(HSQUIRRELVM);

SQInteger SFFontLoad(HSQUIRRELVM);
SQInteger SFSpriteLoad(HSQUIRRELVM);
SQInteger SFSpriteCreateText(HSQUIRRELVM);
SQInteger SFSpriteCreateTextWrapped(HSQUIRRELVM);
SQInteger SFSpriteChangeText(HSQUIRRELVM);
SQInteger SFSpriteChangeTextWrapped(HSQUIRRELVM);
SQInteger SFSpriteGetClipWidthHeight(HSQUIRRELVM);

SQInteger SFFlip(HSQUIRRELVM);
SQInteger SFTimerStart(HSQUIRRELVM);
SQInteger SFDelay(HSQUIRRELVM);
SQInteger SFDelayForFPS(HSQUIRRELVM);
SQInteger SFXed(HSQUIRRELVM);
SQInteger SFKeyPress(HSQUIRRELVM);
SQInteger SFKeyRelease(HSQUIRRELVM);
SQInteger SFKeyPressed(HSQUIRRELVM);
SQInteger SFKeystatesRefresh(HSQUIRRELVM);
SQInteger SFMouseRefresh(HSQUIRRELVM);
SQInteger SFMouseGetCoords(HSQUIRRELVM);
SQInteger SFMousePressed(HSQUIRRELVM);
SQInteger SFMousePress(HSQUIRRELVM);
SQInteger SFMouseRelease(HSQUIRRELVM);
SQInteger SFMouseCursorShow(HSQUIRRELVM);
SQInteger SFMouseCursorHide(HSQUIRRELVM);
SQInteger SFControllerRefresh(HSQUIRRELVM);
SQInteger SFControllerPress(HSQUIRRELVM);
SQInteger SFControllerRelease(HSQUIRRELVM);
SQInteger SFControllerPressed(HSQUIRRELVM);
SQInteger SFControllerGetAxis(HSQUIRRELVM);

SQInteger SFDestroySprites(HSQUIRRELVM);
SQInteger SFDestroyFonts(HSQUIRRELVM);
SQInteger SFDestroySounds(HSQUIRRELVM);
SQInteger SFDestroyImages(HSQUIRRELVM);
SQInteger SFDestroyInput(HSQUIRRELVM);
SQInteger SFDestroyPhysics(HSQUIRRELVM);
SQInteger SFDestroyDraw(HSQUIRRELVM);
SQInteger SFDestroyScreen(HSQUIRRELVM);
SQInteger SFDestroyApp(HSQUIRRELVM);

SQInteger SFDrawAddSprite(HSQUIRRELVM);
SQInteger SFDrawAddSpriteSized(HSQUIRRELVM);
SQInteger SFDrawAddSpriteAngled(HSQUIRRELVM);
SQInteger SFDrawAddSpriteAlpha(HSQUIRRELVM);
SQInteger SFDrawAddSpriteGeneral(HSQUIRRELVM);
SQInteger SFDrawPoint(HSQUIRRELVM);
SQInteger SFDrawPointAlpha(HSQUIRRELVM);
SQInteger SFDrawLine(HSQUIRRELVM);
SQInteger SFDrawLineAlpha(HSQUIRRELVM);
SQInteger SFDrawRect(HSQUIRRELVM);
SQInteger SFDrawRectAlpha(HSQUIRRELVM);
SQInteger SFDrawFilledRect(HSQUIRRELVM);
SQInteger SFDrawFilledRectAlpha(HSQUIRRELVM);
SQInteger SFDrawFill(HSQUIRRELVM);
SQInteger SFDrawFillAlpha(HSQUIRRELVM);
SQInteger SFDrawOutput(HSQUIRRELVM);

SQInteger SFAbs(HSQUIRRELVM);
SQInteger SFSign(HSQUIRRELVM);
SQInteger SFAcos(HSQUIRRELVM);
SQInteger SFAsin(HSQUIRRELVM);
SQInteger SFAtan(HSQUIRRELVM);
SQInteger SFCeil(HSQUIRRELVM);
SQInteger SFCos(HSQUIRRELVM);
SQInteger SFRandom(HSQUIRRELVM);
SQInteger SFRandomRange(HSQUIRRELVM);
SQInteger SFFloor(HSQUIRRELVM);
SQInteger SFLn(HSQUIRRELVM);
SQInteger SFLg(HSQUIRRELVM);
SQInteger SFLb(HSQUIRRELVM);
SQInteger SFSin(HSQUIRRELVM);
SQInteger SFSqrt(HSQUIRRELVM);
SQInteger SFTan(HSQUIRRELVM);
SQInteger SFCbrt(HSQUIRRELVM);
SQInteger SFMax(HSQUIRRELVM);
SQInteger SFMin(HSQUIRRELVM);
SQInteger SFRound(HSQUIRRELVM);
SQInteger SFVectorLength(HSQUIRRELVM);
SQInteger SFVectorDirection(HSQUIRRELVM);
SQInteger SFVectorXY(HSQUIRRELVM);

SQInteger SFMusicLoad(HSQUIRRELVM);
SQInteger SFSoundLoad(HSQUIRRELVM);
SQInteger SFSoundPlay(HSQUIRRELVM);
SQInteger SFSoundSetVolume(HSQUIRRELVM);
SQInteger SFSoundSetChannelsVolume(HSQUIRRELVM);
SQInteger SFSoundPause(HSQUIRRELVM);
SQInteger SFSoundResume(HSQUIRRELVM);
SQInteger SFSoundStop(HSQUIRRELVM);
SQInteger SFMusicPlay(HSQUIRRELVM);
SQInteger SFMusicPause(HSQUIRRELVM);
SQInteger SFMusicResume(HSQUIRRELVM);
SQInteger SFMusicStop(HSQUIRRELVM);
SQInteger SFMusicSetVolume(HSQUIRRELVM);

SQInteger SFPhysicsBlockCreate(HSQUIRRELVM);
SQInteger SFPhysicsObjectCreate(HSQUIRRELVM);
SQInteger SFPhysicsObjectRefreshStats(HSQUIRRELVM);
SQInteger SFPhysicsStep(HSQUIRRELVM);

SQInteger SFBitmapCreate(HSQUIRRELVM);
SQInteger SFBitmapSave(HSQUIRRELVM);
SQInteger SFBitmapSetPixel(HSQUIRRELVM);

SQInteger SFFileOpen(HSQUIRRELVM);
SQInteger SFFileClose(HSQUIRRELVM);
SQInteger SFFileWriteLine(HSQUIRRELVM);
SQInteger SFDialogShowSimpleMessageBox(HSQUIRRELVM);
SQInteger SFDialogShowYesNoMessageBox(HSQUIRRELVM);
SQInteger SFLogWrite(HSQUIRRELVM);
SQInteger SFScriptRegisterNumericVariable(HSQUIRRELVM);
SQInteger SFScriptRegisterStringVariable(HSQUIRRELVM);

#endif
