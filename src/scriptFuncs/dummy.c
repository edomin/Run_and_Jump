#include "scriptFuncs/dummy.h"

int SFInitApp(void *l)
{
    return 0;
}

int SFInitScreen(void *l)
{
    return 0;
}

int SFInitDraw(void *l)
{
	return 0;
}

int SFInitInput(void *l)
{
    return 0;
}

int SFInitTimer(void *l)
{
    return 0;
}

int SFInitSprites(void *l)
{
    return 0;
}

int SFInitFonts(void *l)
{
    return 0;
}

int SFInitSounds(void *l)
{
    return 0;
}

int SFInitImages(void *l)
{
    return 0;
}

int SFInitPhysics(void *l)
{
    return 0;
}

int SFConfigfileCreateConfig(void *l)
{
    return 0;
}

int SFConfigfileLoadConfig(void *l)
{
    return 0;
}

int SFConfigfileSaveConfig(void *l)
{
    return 0;
}

int SFConfigfileAddSection(void *l)
{
    return 0;
}

int SFConfigfileSetKeyValue(void *l)
{
    return 0;
}

int SFConfigfileGetKeyValue(void *l)
{
    return 1;
}

int SFFontLoad(void *l)
{
    return 1;

}

int SFSpriteLoad(void *l)
{
    return 1;
}

int SFSpriteCreateText(void *l)
{
    return 1;
}

int SFSpriteCreateTextWrapped(void *l)
{
    return 1;
}

int SFSpriteChangeText(void *l)
{
    return 0;
}

int SFSpriteChangeTextWrapped(void *l)
{
    return 0;
}

int SFSpriteGetClipWidthHeight(void *l)
{
    return 2;
}

int SFFlip(void *l)
{
    return 0;
}

int SFTimerStart(void *l)
{
    return 0;
}

int SFXed(void *l)
{
    return 1;
}

int SFKeyPress(void *l)
{
    return 1;
}

int SFKeyRelease(void *l)
{
    return 1;
}

int SFKeyPressed(void *l)
{
    return 1;
}

int SFKeystatesRefresh(void *l)
{
    return 0;
}

int SFMouseRefresh(void *l)
{
    return 0;
}

int SFMouseGetCoords(void *l)
{
    return 2;
}

int SFMousePressed(void *l) /* 1 - left; 2 - middle; 3 - right; */
{
    return 1;
}

int SFMousePress(void *l) /* 1 - left; 2 - middle; 3 - right; */
{
    return 1;
}

int SFMouseRelease(void *l) /* 1 - left; 2 - middle; 3 - right; */
{
    return 1;
}

int SFMouseCursorShow(void *l)
{
    return 0;
}

int SFMouseCursorHide(void *l)
{
    return 0;
}

int SFControllerRefresh(void *l)
{
    return 0;
}

int SFControllerPress(void *l)
{
    return 1;
}

int SFControllerRelease(void *l)
{
    return 1;
}

int SFControllerPressed(void *l)
{
    return 1;
}

int SFControllerGetAxis(void *l)
{
    return 1;
}

int SFDestroySprites(void *l)
{
    return 0;
}

int SFDestroyFonts(void *l)
{
    return 0;
}

int SFDestroySounds(void *l)
{
    return 0;
}

int SFDestroyImages(void *l)
{
    return 0;
}

int SFDestroyInput(void *l)
{
    return 0;
}

int SFDestroyPhysics(void *l)
{
    return 0;
}

int SFDestroyApp(void *l)
{
    return 0;
}

int SFDestroyDraw(void *l)
{
    return 0;
}

int SFDestroyScreen(void *l)
{
    return 0;
}

int SFDelay(void *l)
{
    return 1;
}

int SFDelayForFPS(void *l)
{
    return 1;
}

int SFDrawAddSprite(void *l)
{
    return 0;
}

int SFDrawAddSpriteSized(void *l)
{
    return 0;
}

int SFDrawAddSpriteAngled(void *l)
{
    return 0;
}

int SFDrawAddSpriteAlpha(void *l)
{
    return 0;
}

int SFDrawAddSpriteGeneral(void *l)
{
    return 0;
}

int SFDrawPoint(void *l)
{
    return 0;
}

int SFDrawPointAlpha(void *l)
{
    return 0;
}

int SFDrawLine(void *l)
{
    return 0;
}

int SFDrawLineAlpha(void *l)
{
    return 0;
}

int SFDrawRect(void *l)
{
    return 0;
}

int SFDrawRectAlpha(void *l)
{
    return 0;
}

int SFDrawFilledRect(void *l)
{
    return 0;
}

int SFDrawFilledRectAlpha(void *l)
{
    return 0;
}

int SFDrawFill(void *l)
{
    return 0;
}

int SFDrawFillAlpha(void *l)
{
    return 0;
}

int SFDrawOutput(void *l)
{
    return 1;
}

int SFAbs(void *l)
{
    return 1;
}

int SFSign(void *l)
{
    return 1;
}

int SFAcos(void *l)
{
    return 1;
}

int SFAsin(void *l)
{
    return 1;
}

int SFAtan(void *l)
{
    return 1;
}

int SFCeil(void *l)
{
    return 1;
}

int SFCos(void *l)
{
    return 1;
}

int SFRandom(void *l)
{
    return 1;
}

int SFRandomRange(void *l)
{
    return 1;
}

int SFFloor(void *l)
{
    return 1;
}

int SFLn(void *l)
{
    return 1;
}

int SFLg(void *l)
{
    return 1;
}

int SFLb(void *l)
{
    return 1;
}

int SFSin(void *l)
{
    return 1;
}

int SFSqrt(void *l)
{
    return 1;
}

int SFTan(void *l)
{
    return 1;
}

int SFCbrt(void *l)
{
    return 1;
}

int SFMax(void *l)
{
    return 1;
}

int SFMin(void *l)
{
    return 1;
}

int SFRound(void *l)
{
    return 1;
}

int SFVectorLength(void *l)
{
    return 1;
}

int SFVectorDirection(void *l)
{
    return 1;
}

int SFVectorXY(void *l)
{
    return 2;
}

int SFMusicLoad(void *l)
{
    return 1;
}

int SFSoundLoad(void *l)
{
    return 1;
}

int SFSoundPlay(void *l)
{
    return 0;
}

int SFSoundSetVolume(void *l)
{
    return 0;
}

int SFSoundSetChannelsVolume(void *l)
{
    return 0;
}

int SFSoundPause(void *l)
{
    return 0;
}

int SFSoundResume(void *l)
{
    return 0;
}

int SFSoundStop(void *l)
{
    return 0;
}

int SFMusicPlay(void *l)
{
    return 0;
}

int SFMusicPause(void *l)
{
    return 0;
}

int SFMusicResume(void *l)
{
    return 0;
}

int SFMusicStop(void *l)
{
    return 0;
}

int SFMusicSetVolume(void *l)
{
    return 0;
}

int SFPhysicsBlockCreate(void *l)
{
    return 1;
}

int SFPhysicsObjectCreate(void *l)
{
    return 1;
}

int SFPhysicsObjectRefreshStats(void *l)
{
    return 0;
}

int SFPhysicsStep(void *l)
{
    return 0;
}

int SFBitmapCreate(void *l)
{
    return 1;
}

int SFBitmapSave(void *l)
{
    return 0;
}

int SFBitmapSetPixel(void *l)
{
    return 0;
}

int SFFileOpen(void *l)
{
    return 0;
}

int SFFileClose(void *l)
{
    return 0;
}

int SFFileWriteLine(void *l)
{
    return 0;
}

int SFDialogShowSimpleMessageBox(void *l)
{
    return 0;
}

int SFDialogShowYesNoMessageBox(void *l)
{
    return 1;
}

int SFLogWrite(void *l)
{
    return 0;
}

int SFScriptRegisterNumericVariable(void *l)
{
	return 0;
}

int SFScriptRegisterStringVariable(void *l)
{
	return 0;
}

