#ifndef RNJ_SF_DUMMY_H
#define RNJ_SF_DUMMY_H

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

int SFInitApp(void *);
int SFInitScreen(void *);
int SFInitDraw(void *);
int SFInitInput(void *);
int SFInitTimer(void *);
int SFInitSprites(void *);
int SFInitFonts(void *);
int SFInitSounds(void *);
int SFInitImages(void *);
int SFInitPhysics(void *);

int SFConfigfileCreateConfig(void *);
int SFConfigfileLoadConfig(void *);
int SFConfigfileSaveConfig(void *);
int SFConfigfileAddSection(void *);
int SFConfigfileSetKeyValue(void *);
int SFConfigfileGetKeyValue(void *);

int SFFontLoad(void *);
int SFSpriteLoad(void *);
int SFSpriteCreateText(void *);
int SFSpriteCreateTextWrapped(void *);
int SFSpriteChangeText(void *);
int SFSpriteChangeTextWrapped(void *);
int SFSpriteGetClipWidthHeight(void *);

int SFFlip(void *);
int SFTimerStart(void *);
int SFDelay(void *);
int SFDelayForFPS(void *);
int SFXed(void *);
int SFKeyPress(void *);
int SFKeyRelease(void *);
int SFKeyPressed(void *);
int SFKeystatesRefresh(void *);
int SFMouseRefresh(void *);
int SFMouseGetCoords(void *);
int SFMousePressed(void *);
int SFMousePress(void *);
int SFMouseRelease(void *);
int SFMouseCursorShow(void *);
int SFMouseCursorHide(void *);
int SFControllerRefresh(void *);
int SFControllerPress(void *);
int SFControllerRelease(void *);
int SFControllerPressed(void *);
int SFControllerGetAxis(void *);

int SFDestroySprites(void *);
int SFDestroyFonts(void *);
int SFDestroySounds(void *);
int SFDestroyImages(void *);
int SFDestroyInput(void *);
int SFDestroyPhysics(void *);
int SFDestroyDraw(void *);
int SFDestroyScreen(void *);
int SFDestroyApp(void *);

int SFDrawAddSprite(void *);
int SFDrawAddSpriteSized(void *);
int SFDrawAddSpriteAngled(void *);
int SFDrawAddSpriteAlpha(void *);
int SFDrawAddSpriteGeneral(void *);
int SFDrawPoint(void *);
int SFDrawPointAlpha(void *);
int SFDrawLine(void *);
int SFDrawLineAlpha(void *);
int SFDrawRect(void *);
int SFDrawRectAlpha(void *);
int SFDrawFilledRect(void *);
int SFDrawFilledRectAlpha(void *);
int SFDrawFill(void *);
int SFDrawFillAlpha(void *);
int SFDrawOutput(void *);

int SFAbs(void *);
int SFSign(void *);
int SFAcos(void *);
int SFAsin(void *);
int SFAtan(void *);
int SFCeil(void *);
int SFCos(void *);
int SFRandom(void *);
int SFRandomRange(void *);
int SFFloor(void *);
int SFLn(void *);
int SFLg(void *);
int SFLb(void *);
int SFSin(void *);
int SFSqrt(void *);
int SFTan(void *);
int SFCbrt(void *);
int SFMax(void *);
int SFMin(void *);
int SFRound(void *);
int SFVectorLength(void *);
int SFVectorDirection(void *);
int SFVectorXY(void *);

int SFMusicLoad(void *);
int SFSoundLoad(void *);
int SFSoundPlay(void *);
int SFSoundSetVolume(void *);
int SFSoundSetChannelsVolume(void *);
int SFSoundPause(void *);
int SFSoundResume(void *);
int SFSoundStop(void *);
int SFMusicPlay(void *);
int SFMusicPause(void *);
int SFMusicResume(void *);
int SFMusicStop(void *);
int SFMusicSetVolume(void *);

int SFPhysicsBlockCreate(void *);
int SFPhysicsObjectCreate(void *);
int SFPhysicsObjectRefreshStats(void *);
int SFPhysicsStep(void *);

int SFBitmapCreate(void *);
int SFBitmapSave(void *);
int SFBitmapSetPixel(void *);

int SFFileOpen(void *);
int SFFileClose(void *);
int SFFileWriteLine(void *);
int SFDialogShowSimpleMessageBox(void *);
int SFDialogShowYesNoMessageBox(void *);
int SFLogWrite(void *);
int SFScriptRegisterNumericVariable(void *);
int SFScriptRegisterStringVariable(void *);

#endif

