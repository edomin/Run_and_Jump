#include "scriptFuncs.h"

void RegisterAll()
{
    /* В комментариях синтаксис скриптовых функций */
    ScriptsRegisterFunction(SFInitApp, "InitApp"); /* void InitApp() */
    ScriptsRegisterFunction(SFInitScreen, "InitScreen"); /* void InitScreen(int screenWidth, int screenHeight, char *title, bool fullscreen) */
    ScriptsRegisterFunction(SFInitDraw, "InitDraw"); /* void InitDraw(int driverNum, int filtering) */
    ScriptsRegisterFunction(SFInitInput, "InitInput"); /* void InitInput() */
    ScriptsRegisterFunction(SFInitTimer, "InitTimer"); /* void InitTimer() */
    ScriptsRegisterFunction(SFInitSprites, "InitSprites");  /* void InitSprites(int spritesCount) */
    ScriptsRegisterFunction(SFInitFonts, "InitFonts"); /* void InitFonts(int fontsCount) */
    ScriptsRegisterFunction(SFInitSounds, "InitSounds"); /* void InitSounds(int soundsCount, int musicCount, int freq) */
    ScriptsRegisterFunction(SFInitImages, "InitImages"); /* void InitImages(int imagesCount) */
    ScriptsRegisterFunction(SFInitPhysics, "InitPhysics"); /* void InitPhysics(int blocksCount, int objectsCount, double xGrav, double yGrav, double cfm, double stepSize) */

    ScriptsRegisterFunction(SFConfigfileCreateConfig, "ConfigCreate"); /* void ConfigCreate() */
    ScriptsRegisterFunction(SFConfigfileLoadConfig, "ConfigLoad"); /* void ConfigLoad(char *filename) */
    ScriptsRegisterFunction(SFConfigfileSaveConfig, "ConfigSave"); /* void ConfigSave(char *filename) */
    ScriptsRegisterFunction(SFConfigfileAddSection, "ConfigAddSection"); /* void ConfigAddSection(char *sectionname) */
    ScriptsRegisterFunction(SFConfigfileSetKeyValue, "ConfigSetValue"); /* void ConfigSetValue(char *sectionname, char *key, char *value) */
    ScriptsRegisterFunction(SFConfigfileGetKeyValue, "ConfigGetValue"); /* void ConfigGetValue(char *sectionname, char *key) */

    ScriptsRegisterFunction(SFFontLoad, "FontLoad"); /* int(fontNumber) FontLoad(char *filename, int size) */
    ScriptsRegisterFunction(SFSpriteLoad, "SpriteLoad"); /* int(spriteNumber) SpriteLoad(char *filename, int clipsCount) */
    ScriptsRegisterFunction(SFSpriteCreateText, "SpriteCreateText"); /* int(spriteNumber) SpriteCreateText(char *text, int fontNum, int r, int g, int b) */
    ScriptsRegisterFunction(SFSpriteCreateTextWrapped, "SpriteCreateTextWrapped"); /* int(spriteNumber) SpriteCreateTextWrapped(char *text, int fontNum, int r, int g, int b, int wrapLength) */
    ScriptsRegisterFunction(SFSpriteChangeText, "SpriteChangeText"); /* void SpriteChangeText(int spriteNum, char *text, int fontNum, int r, int g, int b) */
    ScriptsRegisterFunction(SFSpriteChangeTextWrapped, "SpriteChangeTextWrapped"); /* void SpriteChangeTextWrapped(int spriteNum, char *text, int fontNum, int r, int g, int b, int wrapLength) */
    ScriptsRegisterFunction(SFSpriteGetClipWidthHeight, "SpriteGetClipWidthHeight"); /* int (width), int(height) SpriteGetClipWidthHeight(int spriteNum) */

    ScriptsRegisterFunction(SFFlip, "Flip"); /* void Flip() */
    ScriptsRegisterFunction(SFTimerStart, "TimerStart"); /* void TimerStart() */
    ScriptsRegisterFunction(SFDelay, "Delay"); /* int(currentFps) Delay(int ms) */
    ScriptsRegisterFunction(SFDelayForFPS, "DelayForFPS"); /* int(currentFps) DelayForFPS(int fps) */
    ScriptsRegisterFunction(SFXed, "Xed"); /* bool Xed() */
    ScriptsRegisterFunction(SFKeyPress, "KeyPress"); /* bool KeyPress(int keycode) */
    ScriptsRegisterFunction(SFKeyRelease, "KeyRelease"); /* bool KeyRelease(int keycode) */
    ScriptsRegisterFunction(SFKeyPressed, "KeyPressed"); /* bool KeyPressed(int scancode) */
    ScriptsRegisterFunction(SFKeystatesRefresh, "KeystatesRefresh"); /* void KeystatesRefresh() */
    ScriptsRegisterFunction(SFMouseRefresh, "MouseRefresh"); /* void MouseRefresh() */
    ScriptsRegisterFunction(SFMouseGetCoords, "MouseGetCoords"); /* int (mouseX), int (MouseY) MouseGetCoords() */
    ScriptsRegisterFunction(SFMousePressed, "MousePressed"); /* bool MousePressed(int mouseButton) */
    ScriptsRegisterFunction(SFMousePress, "MousePress"); /* bool MousePress(int mouseButton) */
    ScriptsRegisterFunction(SFMouseRelease, "MouseRelease"); /* bool MouseRelease(int mouseButton) */
    ScriptsRegisterFunction(SFMouseCursorShow, "MouseCursorShow"); /* void MouseCursorShow() */
    ScriptsRegisterFunction(SFMouseCursorHide, "MouseCursorHide"); /* void MouseCursorHide() */
    ScriptsRegisterFunction(SFControllerRefresh, "ControllerRefresh"); /* void ControllerRefresh() */
    ScriptsRegisterFunction(SFControllerPress, "ControllerPress"); /* bool ControllerPress(int controllerNum, int buttonKey) */
    ScriptsRegisterFunction(SFControllerRelease, "ControllerRelease"); /* bool ControllerRelease(int controllerNum, int buttonCode) */
    ScriptsRegisterFunction(SFControllerPressed, "ControllerPressed"); /* bool ControllerPressed(int controllerNum, int buttonCode) */
    ScriptsRegisterFunction(SFControllerGetAxis, "ControllerGetAxis"); /* int ControllerGetAxis(int controllerNum, int axisCode) */

    ScriptsRegisterFunction(SFDestroySprites, "DestroySprites"); /* void DestroySprites() */
    ScriptsRegisterFunction(SFDestroyFonts, "DestroyFonts"); /* void DestroyFonts() */
    ScriptsRegisterFunction(SFDestroySounds, "DestroySounds"); /* void DestroySounds() */
    ScriptsRegisterFunction(SFDestroyImages, "DestroyImages"); /* void DestroyImages() */
    ScriptsRegisterFunction(SFDestroyInput, "DestroyInput"); /* void DestroyInput() */
    ScriptsRegisterFunction(SFDestroyPhysics, "DestroyPhysics"); /* void DestroyPhysics() */
    ScriptsRegisterFunction(SFDestroyDraw, "DestroyDraw"); /* void DestroyDraw() */
    ScriptsRegisterFunction(SFDestroyScreen, "DestroyScreen"); /* void DestroyScreen() */
    ScriptsRegisterFunction(SFDestroyApp, "DestroyApp"); /* void DestroyApp() */

    ScriptsRegisterFunction(SFDrawAddSprite, "DrawSprite"); /* void DrawSprite(int spriteNum, int clipNum, int x, int y) */
    ScriptsRegisterFunction(SFDrawAddSpriteSized, "DrawSpriteSized"); /* void DrawSpriteSized(int spriteNum, int clipNum, int x, int y, int width, int height) */
    ScriptsRegisterFunction(SFDrawAddSpriteAngled, "DrawSpriteAngled"); /* void DrawSpriteAngled(int spriteNum, int clipNum, int x, int y, int centerX, int centerY, double angle) */
    ScriptsRegisterFunction(SFDrawAddSpriteAlpha, "DrawSpriteAlpha"); /* void DrawSpriteAlpha(int spriteNum, int clipNum, int x, int y, int alpha) */
    ScriptsRegisterFunction(SFDrawAddSpriteGeneral, "DrawSpriteGeneral"); /* void DrawSpriteGeneral(int spriteNum, int clipNum, int x, int y, int width, int height, int centerX, int centerY, double angle, int alpha) */
    ScriptsRegisterFunction(SFDrawPoint, "DrawPoint"); /* void DrawPoint(int x, int y, int r, ing g, int b) */
    ScriptsRegisterFunction(SFDrawPointAlpha, "DrawPointAlpha"); /* void DrawPointAlpha(int x, int y, int r, ing g, int b, int alpha) */
    ScriptsRegisterFunction(SFDrawLine, "DrawLine"); /* void DrawLine(int x1, int y1, int x2, int y2, int r, ing g, int b) */
    ScriptsRegisterFunction(SFDrawLineAlpha, "DrawLineAlpha"); /* void DrawLineAlpha(int x1, int y1, int x2, int y2, int r, ing g, int b, int alpha) */
    ScriptsRegisterFunction(SFDrawRect, "DrawRect"); /* void DrawRect(int x, int y, int width, int height, int r, ing g, int b) */
    ScriptsRegisterFunction(SFDrawRectAlpha, "DrawRectAlpha"); /* void DrawRectAlpha(int x, int y, int width, int height, int r, ing g, int b, int alpha) */
    ScriptsRegisterFunction(SFDrawFilledRect, "DrawFilledRect"); /* void DrawFilledRect(int x, int y, int width, int height, int r, ing g, int b) */
    ScriptsRegisterFunction(SFDrawFilledRectAlpha, "DrawFilledRectAlpha"); /* void DrawFilledRectAlpha(int x, int y, int width, int height, int r, ing g, int b, int alpha) */
    ScriptsRegisterFunction(SFDrawFill, "DrawFill"); /* void DrawFill(int r, ing g, int b) */
    ScriptsRegisterFunction(SFDrawFillAlpha, "DrawFillAlpha"); /* void DrawFillAlpha(int r, ing g, int b, int alpha) */
    ScriptsRegisterFunction(SFDrawOutput, "DrawOutput"); /* int(roundLength) DrawOutput() */

    ScriptsRegisterFunction(SFAbs, "Abs"); /* double Abs(double num) */
    ScriptsRegisterFunction(SFSign, "Sign"); /* double Sign(double num) */
    ScriptsRegisterFunction(SFSin, "Sin"); /* double Sin(double radians) */
    ScriptsRegisterFunction(SFCos, "Cos"); /* double Cos(double radians) */
    ScriptsRegisterFunction(SFTan, "Tan"); /* double Tan(double radians) */
    ScriptsRegisterFunction(SFAsin, "Asin"); /* double(radians) Asin(double num) */
    ScriptsRegisterFunction(SFAcos, "Acos"); /* double(radians) Acos(double num) */
    ScriptsRegisterFunction(SFAtan, "Atan"); /* double(radians) Atan(double num) */
    ScriptsRegisterFunction(SFLn, "Ln"); /* double Ln(double num) */
    ScriptsRegisterFunction(SFLg, "Lg"); /* double Lg(double num) */
    ScriptsRegisterFunction(SFLb, "Lb"); /* double Lb(double num) */
    ScriptsRegisterFunction(SFSqrt, "Sqrt"); /* double Sqrt(double num) */
    ScriptsRegisterFunction(SFCbrt, "Cbrt"); /* double Cbrt(double num) */
    ScriptsRegisterFunction(SFFloor, "Floor"); /* double Floor(double num) */
    ScriptsRegisterFunction(SFCeil, "Ceil"); /* double Ceil(double num) */
    ScriptsRegisterFunction(SFRound, "Round"); /* double Round(double num) */
    ScriptsRegisterFunction(SFRandom, "Random"); /* int Random(double num) */
    ScriptsRegisterFunction(SFRandomRange, "RandomRange"); /* int RandomRange(double min, double max) */
    ScriptsRegisterFunction(SFMin, "Min"); /* double Min(double num1, double num2) */
    ScriptsRegisterFunction(SFMax, "Max"); /* double Max(double num1, double num2) */
    ScriptsRegisterFunction(SFVectorLength, "VectorLength"); /* double VectorLength(double x1, double y1, double x2, double y2) */
    ScriptsRegisterFunction(SFVectorDirection, "VectorDirection"); /* double(radians) VectorDirection(double x1, double y1, double x2, double y2) */
    ScriptsRegisterFunction(SFVectorXY, "VectorXY"); /* double(x), double(y) VectorXY(double length, double dirRadians) */

    ScriptsRegisterFunction(SFMusicLoad, "MusicLoad"); /* int(musicNum) MusicLoad(char *filename) */
    ScriptsRegisterFunction(SFSoundLoad, "SoundLoad"); /* int(soundNum) SoundLoad(char *filename) */
    ScriptsRegisterFunction(SFSoundPlay, "SoundPlay"); /* void SoundPlay(int soundNum) */
    ScriptsRegisterFunction(SFSoundSetVolume, "SoundSetVolume"); /* void SoundSetVolume(int soundNum, int volume) volume - 0..100 */
    ScriptsRegisterFunction(SFSoundSetChannelsVolume, "SoundSetChannelsVolume"); /* void SoundSetChannelsVolume(int volume) volume - 0..100 */
    ScriptsRegisterFunction(SFSoundPause, "SoundPause"); /* void SoundPause() */
    ScriptsRegisterFunction(SFSoundResume, "SoundResume"); /* void SoundResume() */
    ScriptsRegisterFunction(SFSoundStop, "SoundStop"); /* void SoundStop() */
    ScriptsRegisterFunction(SFMusicPlay, "MusicPlay"); /* void MusicPlay(int musicNum) */
    ScriptsRegisterFunction(SFMusicPause, "MusicPause"); /* void MusicPause() */
    ScriptsRegisterFunction(SFMusicResume, "MusicResume"); /* void MusicResume() */
    ScriptsRegisterFunction(SFMusicStop, "MusicStop"); /* void MusicStop() */
    ScriptsRegisterFunction(SFMusicSetVolume, "MusicSetVolume"); /* void MusicSetVolume(int volume) volume - 0..100 */

    ScriptsRegisterFunction(SFPhysicsBlockCreate, "PhysicsBlockCreate"); /* void PhysicsBlockCreate(int x, int y, int width, int height) */
    ScriptsRegisterFunction(SFPhysicsObjectCreate, "PhysicsObjectCreate"); /* void PhysicsObjectCreate(int x, int y, int width, int height, double mass) */
    ScriptsRegisterFunction(SFPhysicsObjectRefreshStats, "PhysicsObjectRefreshStats"); /* void PhysicsObjectRefreshStats(int objectNum) */
    ScriptsRegisterFunction(SFPhysicsStep, "PhysicsStep"); /* void PhysicsStep() */

    ScriptsRegisterFunction(SFBitmapCreate, "BitmapCreate"); /* int(bitmapNum) BitmapCreate(int width, int height, int bpp) */
    ScriptsRegisterFunction(SFBitmapSave, "BitmapSave"); /* void BitmapSave(int bitmapNum, char *filename) */
    ScriptsRegisterFunction(SFBitmapSetPixel, "BitmapSetPixel"); /* void BitmapSetPixel(int bitmapNum, int x, int y, int r, int g, int b, int a) */

    ScriptsRegisterFunction(SFFileOpen, "FileOpen"); /* void FileOpen(char *filename) */
    ScriptsRegisterFunction(SFFileClose, "FileClose"); /* void FileClose() */
    ScriptsRegisterFunction(SFFileWriteLine, "FileWriteLine"); /* void FileWriteLine(char *text) */
    ScriptsRegisterFunction(SFDialogShowSimpleMessageBox, "DialogShowSimpleMessageBox"); /* void DialogShowSimpleMessageBox(int type, char *title, char *message) */
    ScriptsRegisterFunction(SFDialogShowYesNoMessageBox, "DialogShowYesNoMessageBox"); /* bool DialogShowYesNoMessageBox(char *title, char *message) */
    ScriptsRegisterFunction(SFLogWrite, "LogWrite"); /* void LogWrite(char *text, int level, int messageType, char *argument) */
    ScriptsRegisterFunction(SFScriptRegisterNumericVariable, "GlobalNum"); /* void GlobalNum(char *name, double value) */
    ScriptsRegisterFunction(SFScriptRegisterStringVariable, "GlobalString"); /* void GlobalString(char *name, char *value) */

    ScriptsRegisterNumericVariable("KEY_UNKNOWN", RNJ_KEY_UNKNOWN);

    ScriptsRegisterNumericVariable("KEY_A", RNJ_KEY_A);
    ScriptsRegisterNumericVariable("KEY_B", RNJ_KEY_B);
    ScriptsRegisterNumericVariable("KEY_C", RNJ_KEY_C);
    ScriptsRegisterNumericVariable("KEY_D", RNJ_KEY_D);
    ScriptsRegisterNumericVariable("KEY_E", RNJ_KEY_E);
    ScriptsRegisterNumericVariable("KEY_F", RNJ_KEY_F);
    ScriptsRegisterNumericVariable("KEY_G", RNJ_KEY_G);
    ScriptsRegisterNumericVariable("KEY_H", RNJ_KEY_H);
    ScriptsRegisterNumericVariable("KEY_I", RNJ_KEY_I);
    ScriptsRegisterNumericVariable("KEY_J", RNJ_KEY_J);
    ScriptsRegisterNumericVariable("KEY_K", RNJ_KEY_K);
    ScriptsRegisterNumericVariable("KEY_L", RNJ_KEY_L);
    ScriptsRegisterNumericVariable("KEY_M", RNJ_KEY_M);
    ScriptsRegisterNumericVariable("KEY_N", RNJ_KEY_N);
    ScriptsRegisterNumericVariable("KEY_O", RNJ_KEY_O);
    ScriptsRegisterNumericVariable("KEY_P", RNJ_KEY_P);
    ScriptsRegisterNumericVariable("KEY_Q", RNJ_KEY_Q);
    ScriptsRegisterNumericVariable("KEY_R", RNJ_KEY_R);
    ScriptsRegisterNumericVariable("KEY_S", RNJ_KEY_S);
    ScriptsRegisterNumericVariable("KEY_T", RNJ_KEY_T);
    ScriptsRegisterNumericVariable("KEY_U", RNJ_KEY_U);
    ScriptsRegisterNumericVariable("KEY_V", RNJ_KEY_V);
    ScriptsRegisterNumericVariable("KEY_W", RNJ_KEY_W);
    ScriptsRegisterNumericVariable("KEY_X", RNJ_KEY_X);
    ScriptsRegisterNumericVariable("KEY_Y", RNJ_KEY_Y);
    ScriptsRegisterNumericVariable("KEY_Z", RNJ_KEY_Z);

    ScriptsRegisterNumericVariable("KEY_1", RNJ_KEY_1);
    ScriptsRegisterNumericVariable("KEY_2", RNJ_KEY_2);
    ScriptsRegisterNumericVariable("KEY_3", RNJ_KEY_3);
    ScriptsRegisterNumericVariable("KEY_4", RNJ_KEY_4);
    ScriptsRegisterNumericVariable("KEY_5", RNJ_KEY_5);
    ScriptsRegisterNumericVariable("KEY_6", RNJ_KEY_6);
    ScriptsRegisterNumericVariable("KEY_7", RNJ_KEY_7);
    ScriptsRegisterNumericVariable("KEY_8", RNJ_KEY_8);
    ScriptsRegisterNumericVariable("KEY_9", RNJ_KEY_9);
    ScriptsRegisterNumericVariable("KEY_0", RNJ_KEY_0);

    ScriptsRegisterNumericVariable("KEY_RETURN", RNJ_KEY_RETURN);
    ScriptsRegisterNumericVariable("KEY_ESCAPE", RNJ_KEY_ESCAPE);
    ScriptsRegisterNumericVariable("KEY_ESC", RNJ_KEY_ESC);
    ScriptsRegisterNumericVariable("KEY_BACKSPACE", RNJ_KEY_BACKSPACE);
    ScriptsRegisterNumericVariable("KEY_TAB", RNJ_KEY_TAB);
    ScriptsRegisterNumericVariable("KEY_SPACE", RNJ_KEY_SPACE);

    ScriptsRegisterNumericVariable("KEY_MINUS", RNJ_KEY_MINUS);
    ScriptsRegisterNumericVariable("KEY_EQUALS", RNJ_KEY_EQUALS);
    ScriptsRegisterNumericVariable("KEY_LEFTBRACKET", RNJ_KEY_LEFTBRACKET);
    ScriptsRegisterNumericVariable("KEY_RIGHTBRACKET", RNJ_KEY_RIGHTBRACKET);
    ScriptsRegisterNumericVariable("KEY_BACKSLASH", RNJ_KEY_BACKSLASH);
    ScriptsRegisterNumericVariable("KEY_NONUSHASH", RNJ_KEY_NONUSHASH);
    ScriptsRegisterNumericVariable("KEY_SEMICOLON", RNJ_KEY_SEMICOLON);
    ScriptsRegisterNumericVariable("KEY_APOSTROPHE", RNJ_KEY_APOSTROPHE);
    ScriptsRegisterNumericVariable("KEY_GRAVE", RNJ_KEY_GRAVE);
    ScriptsRegisterNumericVariable("KEY_TILDE", RNJ_KEY_TILDE);
    ScriptsRegisterNumericVariable("KEY_COMMA", RNJ_KEY_COMMA);
    ScriptsRegisterNumericVariable("KEY_PERIOD", RNJ_KEY_PERIOD);
    ScriptsRegisterNumericVariable("KEY_SLASH", RNJ_KEY_SLASH);

    ScriptsRegisterNumericVariable("KEY_CAPSLOCK", RNJ_KEY_CAPSLOCK);

    ScriptsRegisterNumericVariable("KEY_F1", RNJ_KEY_F1);
    ScriptsRegisterNumericVariable("KEY_F2", RNJ_KEY_F2);
    ScriptsRegisterNumericVariable("KEY_F3", RNJ_KEY_F3);
    ScriptsRegisterNumericVariable("KEY_F4", RNJ_KEY_F4);
    ScriptsRegisterNumericVariable("KEY_F5", RNJ_KEY_F5);
    ScriptsRegisterNumericVariable("KEY_F6", RNJ_KEY_F6);
    ScriptsRegisterNumericVariable("KEY_F7", RNJ_KEY_F7);
    ScriptsRegisterNumericVariable("KEY_F8", RNJ_KEY_F8);
    ScriptsRegisterNumericVariable("KEY_F9", RNJ_KEY_F9);
    ScriptsRegisterNumericVariable("KEY_F10", RNJ_KEY_F10);
    ScriptsRegisterNumericVariable("KEY_F11", RNJ_KEY_F11);
    ScriptsRegisterNumericVariable("KEY_F12", RNJ_KEY_F12);

    ScriptsRegisterNumericVariable("KEY_PRINTSCREEN", RNJ_KEY_PRINTSCREEN);
    ScriptsRegisterNumericVariable("KEY_SCROLLLOCK", RNJ_KEY_SCROLLLOCK);
    ScriptsRegisterNumericVariable("KEY_PAUSE", RNJ_KEY_PAUSE);
    ScriptsRegisterNumericVariable("KEY_INSERT", RNJ_KEY_INSERT);
    ScriptsRegisterNumericVariable("KEY_HOME", RNJ_KEY_HOME);
    ScriptsRegisterNumericVariable("KEY_PAGEUP", RNJ_KEY_PAGEUP);
    ScriptsRegisterNumericVariable("KEY_DELETE", RNJ_KEY_DELETE);
    ScriptsRegisterNumericVariable("KEY_END", RNJ_KEY_END);
    ScriptsRegisterNumericVariable("KEY_PAGEDOWN", RNJ_KEY_PAGEDOWN);

    ScriptsRegisterNumericVariable("KEY_RIGHT", RNJ_KEY_RIGHT);
    ScriptsRegisterNumericVariable("KEY_LEFT", RNJ_KEY_LEFT);
    ScriptsRegisterNumericVariable("KEY_DOWN", RNJ_KEY_DOWN);
    ScriptsRegisterNumericVariable("KEY_UP", RNJ_KEY_UP);

    ScriptsRegisterNumericVariable("KEY_NUMLOCK", RNJ_KEY_NUMLOCK);
    ScriptsRegisterNumericVariable("KEY_KP_DIVIDE", RNJ_KEY_KP_DIVIDE);
    ScriptsRegisterNumericVariable("KEY_KP_MULTIPLY", RNJ_KEY_KP_MULTIPLY);
    ScriptsRegisterNumericVariable("KEY_KP_MINUS", RNJ_KEY_KP_MINUS);
    ScriptsRegisterNumericVariable("KEY_KP_PLUS", RNJ_KEY_KP_PLUS);
    ScriptsRegisterNumericVariable("KEY_KP_ENTER", RNJ_KEY_KP_ENTER);
    ScriptsRegisterNumericVariable("KEY_KP_1", RNJ_KEY_KP_1);
    ScriptsRegisterNumericVariable("KEY_KP_2", RNJ_KEY_KP_2);
    ScriptsRegisterNumericVariable("KEY_KP_3", RNJ_KEY_KP_3);
    ScriptsRegisterNumericVariable("KEY_KP_4", RNJ_KEY_KP_4);
    ScriptsRegisterNumericVariable("KEY_KP_5", RNJ_KEY_KP_5);
    ScriptsRegisterNumericVariable("KEY_KP_6", RNJ_KEY_KP_6);
    ScriptsRegisterNumericVariable("KEY_KP_7", RNJ_KEY_KP_7);
    ScriptsRegisterNumericVariable("KEY_KP_8", RNJ_KEY_KP_8);
    ScriptsRegisterNumericVariable("KEY_KP_9", RNJ_KEY_KP_9);
    ScriptsRegisterNumericVariable("KEY_KP_0", RNJ_KEY_KP_0);
    ScriptsRegisterNumericVariable("KEY_KP_PERIOD", RNJ_KEY_KP_PERIOD);

    ScriptsRegisterNumericVariable("KEY_APPLICATION", RNJ_KEY_APPLICATION);
    ScriptsRegisterNumericVariable("KEY_CONTEXT", RNJ_KEY_CONTEXT);
    ScriptsRegisterNumericVariable("KEY_LCTRL", RNJ_KEY_LCTRL);
    ScriptsRegisterNumericVariable("KEY_LSHIFT", RNJ_KEY_LSHIFT);
    ScriptsRegisterNumericVariable("KEY_LALT", RNJ_KEY_LALT);
    ScriptsRegisterNumericVariable("KEY_LGUI", RNJ_KEY_LGUI);
    ScriptsRegisterNumericVariable("KEY_LWINDOWS", RNJ_KEY_LWINDOWS);
    ScriptsRegisterNumericVariable("KEY_RCTRL", RNJ_KEY_RCTRL);
    ScriptsRegisterNumericVariable("KEY_RSHIFT", RNJ_KEY_RSHIFT);
    ScriptsRegisterNumericVariable("KEY_RALT", RNJ_KEY_RALT);
    ScriptsRegisterNumericVariable("KEY_RGUI", RNJ_KEY_RGUI);
    ScriptsRegisterNumericVariable("KEY_RWINDOWS", RNJ_KEY_RWINDOWS);

    ScriptsRegisterNumericVariable("MOUSE_LEFT", 1);
    ScriptsRegisterNumericVariable("MOUSE_MIDDLE", 2);
    ScriptsRegisterNumericVariable("MOUSE_RIGHT", 3);

    /* Драйверы рендера */
    ScriptsRegisterNumericVariable("RD_FIRST_SUPPORTED", -1);

    /* Режимы фильтрации */
    ScriptsRegisterNumericVariable("FM_NEAREST", 0);
    ScriptsRegisterNumericVariable("FM_LINEAR", 1);
    ScriptsRegisterNumericVariable("FM_BEST", 2);

    return;
}
