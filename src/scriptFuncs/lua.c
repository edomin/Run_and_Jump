//#ifdef LS_LUA
#include "scriptFuncs/lua.h"

int SFInitApp(lua_State* l)
{
    AppInit();
    return 0;
}

int SFInitScreen(lua_State* l)
{
    int w = lua_tonumber(Scripts.vm, 1); /* получаем 1-ый */
                                         /* переданный параметр */
    int h = lua_tonumber(Scripts.vm, 2);
    const char *title = lua_tostring(Scripts.vm, 3);
    bool fullscreen = lua_toboolean(Scripts.vm, 4);
    ScreenInit(w, h, title, fullscreen);
    return 0;
}

int SFInitDraw(lua_State* l)
{
    int driver = lua_tonumber(Scripts.vm, 1);
    int filtering = lua_tonumber(Scripts.vm, 2);
    DrawInit(driver, filtering);

    return 0;
}

int SFInitInput(lua_State* l)
{
    InputInit();
    return 0;
}

int SFInitTimer(lua_State* l)
{
    InitTimer();
    return 0;
}

int SFInitSprites(lua_State* l)
{
    int sprites = lua_tonumber(Scripts.vm, 1);
    SpritesInit(sprites);
    return 0;
}

int SFInitFonts(lua_State* l)
{
    int fonts = lua_tonumber(Scripts.vm, 1);
    FontsInit(fonts);
    return 0;
}

int SFInitSounds(lua_State* l)
{
    int maxSounds = lua_tonumber(Scripts.vm, 1);
    int maxMusic = lua_tonumber(Scripts.vm, 2);
    unsigned int freq = lua_tonumber(Scripts.vm, 3);
    SoundsInit(maxSounds, maxMusic, freq, 2, 1024);
    return 0;
}

int SFInitImages(lua_State* l)
{
    int maxImages = lua_tonumber(Scripts.vm, 1);
    ImagesInit(maxImages);
    return 0;
}

int SFInitPhysics(lua_State* l)
{
    int maxBlocks = lua_tonumber(Scripts.vm, 1);
    int maxObjects = lua_tonumber(Scripts.vm, 2);
    double xGrav = lua_tonumber(Scripts.vm, 3);
    double yGrav = lua_tonumber(Scripts.vm, 4);
    double cfm = lua_tonumber(Scripts.vm, 5);
    double stepSize = lua_tonumber(Scripts.vm, 6);
    PhysicsInit(xGrav, yGrav, cfm, stepSize, maxBlocks, maxObjects);
    return 0;
}

int SFConfigfileCreateConfig(lua_State* l)
{
    ConfigfileCreateConfig();
    return 0;
}

int SFConfigfileLoadConfig(lua_State* l)
{
    char *filename = (char *)lua_tostring(Scripts.vm, 1);
    ConfigfileLoadConfig(filename);
    return 0;
}

int SFConfigfileSaveConfig(lua_State* l)
{
    char *filename = (char *)lua_tostring(Scripts.vm, 1);
    ConfigfileSaveConfig(filename);
    return 0;
}

int SFConfigfileAddSection(lua_State* l)
{
    char *section = (char *)lua_tostring(Scripts.vm, 1);
    ConfigfileAddSection(section);
    return 0;
}

int SFConfigfileSetKeyValue(lua_State* l)
{
    char *section = (char *)lua_tostring(Scripts.vm, 1);
    char *key = (char *)lua_tostring(Scripts.vm, 2);
    char *value = (char *)lua_tostring(Scripts.vm, 3);
    ConfigfileSetKeyValue(section, key, value);
    return 0;
}

int SFConfigfileGetKeyValue(lua_State* l)
{
    char *section = (char *)lua_tostring(Scripts.vm, 1);
    char *key = (char *)lua_tostring(Scripts.vm, 2);
    lua_pushstring(Scripts.vm, ConfigfileGetKeyValue(section, key));
    return 1;
}

int SFFontLoad(lua_State* l)
{
    char *filename = (char *)lua_tostring(Scripts.vm, 1); /* получаем 1-ый */
                                                               /* переданный параметр */
    int size = lua_tonumber(Scripts.vm, 2);

    int font = FontsLoadFont(filename, size);

    lua_pushnumber(Scripts.vm, font);
    return 1;

}

int SFSpriteLoad(lua_State* l)
{
    char *filename = (char *)lua_tostring(Scripts.vm, 1);
    int clips = lua_tonumber(Scripts.vm, 2);

    int sprite = SpritesCreateSprite(filename, clips);
    lua_pushnumber(Scripts.vm, sprite);
    return 1;

}

int SFSpriteCreateText(lua_State* l)
{
    char *text = (char *)lua_tostring(Scripts.vm, 1);
    int fontnum = lua_tonumber(Scripts.vm, 2);
    int text_r = lua_tonumber(Scripts.vm, 3);
    int text_g = lua_tonumber(Scripts.vm, 4);
    int text_b = lua_tonumber(Scripts.vm, 5);

    int sprite = SpritesCreateText(text, fontnum, text_r, text_g, text_b, WRAP_NOWRAP);
    lua_pushnumber(Scripts.vm, sprite);
    return 1;
}

int SFSpriteCreateTextWrapped(lua_State* l)
{
    char *text = (char *)lua_tostring(Scripts.vm, 1);
    int fontnum = lua_tonumber(Scripts.vm, 2);
    int textR = lua_tonumber(Scripts.vm, 3);
    int textG = lua_tonumber(Scripts.vm, 4);
    int textB = lua_tonumber(Scripts.vm, 5);
    int wrapLength = lua_tonumber(Scripts.vm, 6);

    int sprite = SpritesCreateText(text, fontnum, textR, textG, textB, wrapLength);
    lua_pushnumber(Scripts.vm, sprite);
    return 1;
}

int SFSpriteChangeText(lua_State* l)
{
    int spriteNum = lua_tonumber(Scripts.vm, 1);
    char *text = (char *)lua_tostring(Scripts.vm, 2);
    int fontNum = lua_tonumber(Scripts.vm, 3);
    int textR = lua_tonumber(Scripts.vm, 4);
    int textG = lua_tonumber(Scripts.vm, 5);
    int textB = lua_tonumber(Scripts.vm, 6);

    SpritesChangeText(spriteNum, text, fontNum, textR, textG, textB, WRAP_NOWRAP);
    return 0;
}

int SFSpriteChangeTextWrapped(lua_State* l)
{
    int spriteNum = lua_tonumber(Scripts.vm, 1);
    char *text = (char *)lua_tostring(Scripts.vm, 2);
    int fontNum = lua_tonumber(Scripts.vm, 3);
    int textR = lua_tonumber(Scripts.vm, 4);
    int textG = lua_tonumber(Scripts.vm, 5);
    int textB = lua_tonumber(Scripts.vm, 6);
    int wrapLength = lua_tonumber(Scripts.vm, 7);

    SpritesChangeText(spriteNum, text, fontNum, textR, textG, textB, wrapLength);
    return 0;
}

int SFSpriteGetClipWidthHeight(lua_State* l)
{
    #if !defined(LSPRITES_DUMMY)
    int spriteNum = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, (Sprite[spriteNum].clip[0].w));
    lua_pushnumber(Scripts.vm, (Sprite[spriteNum].clip[0].h));
    #else
    lua_pushnumber(Scripts.vm, 0);
    lua_pushnumber(Scripts.vm, 0);
    #endif
    return 2;
}

int SFFlip(lua_State* l)
{
    DrawFlip();
    return 0;
}

int SFTimerStart(lua_State* l)
{
    TimerStart();
    return 0;
}

int SFXed(lua_State* l)
{
    if (AppXed())
    {
        lua_pushboolean(Scripts.vm, 1);
    }
    else
    {
        lua_pushboolean(Scripts.vm, 0);
    }
    return 1;
}

int SFKeyPress(lua_State* l)
{
    int key = lua_tonumber(Scripts.vm, 1);
    if (InputKeyPress(key))
    {
        lua_pushboolean(Scripts.vm, 1);
    }
    else
    {
        lua_pushboolean(Scripts.vm, 0);
    }
    return 1;
}

int SFKeyRelease(lua_State* l)
{
    int key = lua_tonumber(Scripts.vm, 1);
    if (InputKeyRelease(key))
    {
        lua_pushboolean(Scripts.vm, 1);
    }
    else
    {
        lua_pushboolean(Scripts.vm, 0);
    }
    return 1;
}

int SFKeyPressed(lua_State* l)
{
    int key = lua_tonumber(Scripts.vm, 1);
    if (InputKeyPressed(key))
    {
        lua_pushboolean(Scripts.vm, 1);
    }
    else
    {
        lua_pushboolean(Scripts.vm, 0);
    }
    return 1;
}

int SFKeystatesRefresh(lua_State* l)
{
    InputKeystatesRefresh();
    return 0;
}

int SFMouseRefresh(lua_State* l)
{
    InputMouseRefresh();
    return 0;
}

int SFMouseGetCoords(lua_State* l)
{
    lua_pushnumber(Scripts.vm, App.mouseX);
    lua_pushnumber(Scripts.vm, App.mouseY);
    return 2;
}

int SFMousePressed(lua_State* l) /* 1 - left; 2 - middle; 3 - right; */
{
    int button = lua_tonumber(Scripts.vm, 1);
    switch (button)
    {
        case 1: /* left */
        {
            if (Input.currentMouseLeft)
            {
                lua_pushboolean(Scripts.vm, 1);
            }
            else
            {
                lua_pushboolean(Scripts.vm, 0);
            }
            break;
        }
        case 2: /* middle */
        {
            if (Input.currentMouseMiddle)
            {
                lua_pushboolean(Scripts.vm, 1);
            }
            else
            {
                lua_pushboolean(Scripts.vm, 0);
            }
            break;
        }
        case 3: /* right */
        {
            if (Input.currentMouseRight)
            {
                lua_pushboolean(Scripts.vm, 1);
            }
            else
            {
                lua_pushboolean(Scripts.vm, 0);
            }
            break;
        }
    }
    return 1;
}

int SFMousePress(lua_State* l) /* 1 - left; 2 - middle; 3 - right; */
{
    int button = lua_tonumber(Scripts.vm, 1);
    switch (button)
    {
        case 1: /* left */
        {
            if (Input.currentMouseLeft && !(Input.previousMouseLeft))
            {
                lua_pushboolean(Scripts.vm, 1);
            }
            else
            {
                lua_pushboolean(Scripts.vm, 0);
            }
            break;
        }
        case 2: /* middle */
        {
            if (Input.currentMouseMiddle && !(Input.previousMouseMiddle))
            {
                lua_pushboolean(Scripts.vm, 1);
            }
            else
            {
                lua_pushboolean(Scripts.vm, 0);
            }
            break;
        }
        case 3: /* right */
        {
            if (Input.currentMouseRight && !(Input.previousMouseRight))
            {
                lua_pushboolean(Scripts.vm, 1);
            }
            else
            {
                lua_pushboolean(Scripts.vm, 0);
            }
            break;
        }
    }
    return 1;
}

int SFMouseRelease(lua_State* l) /* 1 - left; 2 - middle; 3 - right; */
{
    int button = lua_tonumber(Scripts.vm, 1);
    switch (button)
    {
        case 1: /* left */
        {
            if (Input.previousMouseLeft && !(Input.currentMouseLeft))
            {
                lua_pushboolean(Scripts.vm, 1);
            }
            else
            {
                lua_pushboolean(Scripts.vm, 0);
            }
            break;
        }
        case 2: /* middle */
        {
            if (Input.previousMouseMiddle && !(Input.currentMouseMiddle))
            {
                lua_pushboolean(Scripts.vm, 1);
            }
            else
            {
                lua_pushboolean(Scripts.vm, 0);
            }
            break;
        }
        case 3: /* right */
        {
            if (Input.previousMouseRight && !(Input.currentMouseRight))
            {
                lua_pushboolean(Scripts.vm, 1);
            }
            else
            {
                lua_pushboolean(Scripts.vm, 0);
            }
            break;
        }
    }
    return 1;
}

int SFMouseCursorShow(lua_State* l)
{
    ScreenCursorShow();
    return 0;
}

int SFMouseCursorHide(lua_State* l)
{
    ScreenCursorHide();
    return 0;
}

int SFControllerRefresh(lua_State* l)
{
    InputControllersRefresh();
    return 0;
}

int SFControllerPress(lua_State* l)
{
    int controllerNum = lua_tonumber(Scripts.vm, 1);
    uint8_t button = (uint8_t)lua_tonumber(Scripts.vm, 2);
    if (InputControllerButtonPress(controllerNum, button))
    {
        lua_pushboolean(Scripts.vm, 1);
    }
    else
    {
        lua_pushboolean(Scripts.vm, 0);
    }
    return 1;
}

int SFControllerRelease(lua_State* l)
{
    int controllerNum = lua_tonumber(Scripts.vm, 1);
    uint8_t button = (uint8_t)lua_tonumber(Scripts.vm, 2);
    if (InputControllerButtonRelease(controllerNum, button))
    {
        lua_pushboolean(Scripts.vm, 1);
    }
    else
    {
        lua_pushboolean(Scripts.vm, 0);
    }
    return 1;
}

int SFControllerPressed(lua_State* l)
{
    int controllerNum = lua_tonumber(Scripts.vm, 1);
    uint8_t button = (uint8_t)lua_tonumber(Scripts.vm, 2);
    if (InputControllerButtonPressed(controllerNum, button))
    {
        lua_pushboolean(Scripts.vm, 1);
    }
    else
    {
        lua_pushboolean(Scripts.vm, 0);
    }
    return 1;
}

int SFControllerGetAxis(lua_State* l)
{
    int16_t axisValue;
    int controllerNum = lua_tonumber(Scripts.vm, 1);
    uint8_t axis = lua_tonumber(Scripts.vm, 2);
    axisValue = InputControllerGetAxis(controllerNum, axis);
    lua_pushnumber(Scripts.vm, axisValue);
    return 1;
}

int SFDestroySprites(lua_State* l)
{
    SpritesQuit();
    return 0;
}

int SFDestroyFonts(lua_State* l)
{
    FontsQuit();
    return 0;
}

int SFDestroySounds(lua_State* l)
{
    SoundsDestroy();
    return 0;
}

int SFDestroyImages(lua_State* l)
{
    ImagesQuit();
    return 0;
}

int SFDestroyInput(lua_State* l)
{
    InputQuit();
    return 0;
}

int SFDestroyPhysics(lua_State* l)
{
    PhysicsDestroy();
    return 0;
}

int SFDestroyApp(lua_State* l)
{
    AppDestroy();
    return 0;
}

int SFDestroyDraw(lua_State* l)
{
    DrawDestroy();
    return 0;
}

int SFDestroyScreen(lua_State* l)
{
    ScreenDestroy();
    return 0;
}

int SFDelay(lua_State* l)
{
    int ms = lua_tonumber(Scripts.vm, 1);

    int currentFps = TimerDelay(ms);
    lua_pushnumber(Scripts.vm, currentFps);
    return 1;
}

int SFDelayForFPS(lua_State* l)
{
    int fps = lua_tonumber(Scripts.vm, 1);

    int currentFps = TimerDelayForFPS(fps);
    lua_pushnumber(Scripts.vm, currentFps);
    return 1;
}

int SFDrawAddSprite(lua_State* l)
{
    int spriteNum = lua_tonumber(Scripts.vm, 1);
    int clipNum = lua_tonumber(Scripts.vm, 2);
    int x = lua_tonumber(Scripts.vm, 3);
    int y = lua_tonumber(Scripts.vm, 4);

    DrawAddSprite(spriteNum, clipNum, x, y);

    return 0;
}

int SFDrawAddSpriteSized(lua_State* l)
{
    int spriteNum = lua_tonumber(Scripts.vm, 1);
    int clipNum = lua_tonumber(Scripts.vm, 2);
    int x = lua_tonumber(Scripts.vm, 3);
    int y = lua_tonumber(Scripts.vm, 4);
    int width = lua_tonumber(Scripts.vm, 5);
    int height = lua_tonumber(Scripts.vm, 6);

    DrawAddSpriteSized(spriteNum, clipNum, x, y, width, height);

    return 0;
}

int SFDrawAddSpriteAngled(lua_State* l)
{
    int spriteNum = lua_tonumber(Scripts.vm, 1);
    int clipNum = lua_tonumber(Scripts.vm, 2);
    int x = lua_tonumber(Scripts.vm, 3);
    int y = lua_tonumber(Scripts.vm, 4);
    int centerX = lua_tonumber(Scripts.vm, 5);
    int centerY = lua_tonumber(Scripts.vm, 6);
    double angle = lua_tonumber(Scripts.vm, 7);

    DrawAddSpriteAngled(spriteNum, clipNum, x, y, centerX, centerY, angle);

    return 0;
}

int SFDrawAddSpriteAlpha(lua_State* l)
{
    int spriteNum = lua_tonumber(Scripts.vm, 1);
    int clipNum = lua_tonumber(Scripts.vm, 2);
    int x = lua_tonumber(Scripts.vm, 3);
    int y = lua_tonumber(Scripts.vm, 4);
    int alpha = lua_tonumber(Scripts.vm, 5);

    DrawAddSpriteAlpha(spriteNum, clipNum, x, y, alpha);

    return 0;
}

int SFDrawAddSpriteGeneral(lua_State* l)
{
    int spriteNum = lua_tonumber(Scripts.vm, 1);
    int clipNum = lua_tonumber(Scripts.vm, 2);
    int x = lua_tonumber(Scripts.vm, 3);
    int y = lua_tonumber(Scripts.vm, 4);
    int width = lua_tonumber(Scripts.vm, 5);
    int height = lua_tonumber(Scripts.vm, 6);
    int centerX = lua_tonumber(Scripts.vm, 7);
    int centerY = lua_tonumber(Scripts.vm, 8);
    double angle = lua_tonumber(Scripts.vm, 9);
    int alpha = lua_tonumber(Scripts.vm, 10);
    int flip = lua_tonumber(Scripts.vm, 11);

    DrawAddSpriteGeneral(spriteNum, clipNum, x, y, width, height, centerX, centerY, angle, alpha, flip);

    return 0;
}

int SFDrawPoint(lua_State* l)
{
    int x = lua_tonumber(Scripts.vm, 1);
    int y = lua_tonumber(Scripts.vm, 2);
    int r = lua_tonumber(Scripts.vm, 3);
    int g = lua_tonumber(Scripts.vm, 4);
    int b = lua_tonumber(Scripts.vm, 5);

    DrawAddPoint(x, y, r, g, b, 255);

    return 0;
}

int SFDrawPointAlpha(lua_State* l)
{
    int x = lua_tonumber(Scripts.vm, 1);
    int y = lua_tonumber(Scripts.vm, 2);
    int r = lua_tonumber(Scripts.vm, 3);
    int g = lua_tonumber(Scripts.vm, 4);
    int b = lua_tonumber(Scripts.vm, 5);
    int a = lua_tonumber(Scripts.vm, 6);

    DrawAddPoint(x, y, r, g, b, a);

    return 0;
}

int SFDrawLine(lua_State* l)
{
    int x1 = lua_tonumber(Scripts.vm, 1);
    int y1 = lua_tonumber(Scripts.vm, 2);
    int x2 = lua_tonumber(Scripts.vm, 3);
    int y2 = lua_tonumber(Scripts.vm, 4);
    int r = lua_tonumber(Scripts.vm, 5);
    int g = lua_tonumber(Scripts.vm, 6);
    int b = lua_tonumber(Scripts.vm, 7);

    DrawAddLine(x1, y1, x2, y2, r, g, b, 255);

    return 0;
}

int SFDrawLineAlpha(lua_State* l)
{
    int x1 = lua_tonumber(Scripts.vm, 1);
    int y1 = lua_tonumber(Scripts.vm, 2);
    int x2 = lua_tonumber(Scripts.vm, 3);
    int y2 = lua_tonumber(Scripts.vm, 4);
    int r = lua_tonumber(Scripts.vm, 5);
    int g = lua_tonumber(Scripts.vm, 6);
    int b = lua_tonumber(Scripts.vm, 7);
    int a = lua_tonumber(Scripts.vm, 8);

    DrawAddLine(x1, y1, x2, y2, r, g, b, a);

    return 0;
}

int SFDrawRect(lua_State* l)
{
    int x = lua_tonumber(Scripts.vm, 1);
    int y = lua_tonumber(Scripts.vm, 2);
    int w = lua_tonumber(Scripts.vm, 3);
    int h = lua_tonumber(Scripts.vm, 4);
    int r = lua_tonumber(Scripts.vm, 5);
    int g = lua_tonumber(Scripts.vm, 6);
    int b = lua_tonumber(Scripts.vm, 7);

    DrawAddRect(x, y, w, h, r, g, b, 255);

    return 0;
}

int SFDrawRectAlpha(lua_State* l)
{
    int x = lua_tonumber(Scripts.vm, 1);
    int y = lua_tonumber(Scripts.vm, 2);
    int w = lua_tonumber(Scripts.vm, 3);
    int h = lua_tonumber(Scripts.vm, 4);
    int r = lua_tonumber(Scripts.vm, 5);
    int g = lua_tonumber(Scripts.vm, 6);
    int b = lua_tonumber(Scripts.vm, 7);
    int a = lua_tonumber(Scripts.vm, 8);

    DrawAddRect(x, y, w, h, r, g, b, a);

    return 0;
}

int SFDrawFilledRect(lua_State* l)
{
    int x = lua_tonumber(Scripts.vm, 1);
    int y = lua_tonumber(Scripts.vm, 2);
    int w = lua_tonumber(Scripts.vm, 3);
    int h = lua_tonumber(Scripts.vm, 4);
    int r = lua_tonumber(Scripts.vm, 5);
    int g = lua_tonumber(Scripts.vm, 6);
    int b = lua_tonumber(Scripts.vm, 7);

    DrawAddFilledRect(x, y, w, h, r, g, b, 255);

    return 0;
}

int SFDrawFilledRectAlpha(lua_State* l)
{
    int x = lua_tonumber(Scripts.vm, 1);
    int y = lua_tonumber(Scripts.vm, 2);
    int w = lua_tonumber(Scripts.vm, 3);
    int h = lua_tonumber(Scripts.vm, 4);
    int r = lua_tonumber(Scripts.vm, 5);
    int g = lua_tonumber(Scripts.vm, 6);
    int b = lua_tonumber(Scripts.vm, 7);
    int a = lua_tonumber(Scripts.vm, 8);

    DrawAddFilledRect(x, y, w, h, r, g, b, a);

    return 0;
}

int SFDrawFill(lua_State* l)
{
    int r = lua_tonumber(Scripts.vm, 1);
    int g = lua_tonumber(Scripts.vm, 2);
    int b = lua_tonumber(Scripts.vm, 3);

    DrawAddFill(r, g, b, 255);

    return 0;
}

int SFDrawFillAlpha(lua_State* l)
{
    int r = lua_tonumber(Scripts.vm, 1);
    int g = lua_tonumber(Scripts.vm, 2);
    int b = lua_tonumber(Scripts.vm, 3);
    int a = lua_tonumber(Scripts.vm, 4);

    DrawAddFill(r, g, b, a);

    return 0;
}

int SFDrawOutput(lua_State* l)
{
    int roundLength = DrawOutput();
    lua_pushnumber(Scripts.vm, roundLength);
    return 1;
}

int SFAbs(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, fabs(x));
    return 1;
}

int SFSign(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    if (x < 0)
    {
        lua_pushnumber(Scripts.vm, -1);
    }
    if (x == 0)
    {
        lua_pushnumber(Scripts.vm, 0);
    }
    if (x > 0)
    {
        lua_pushnumber(Scripts.vm, 1);
    }
    return 1;
}

int SFAcos(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, acos(x));
    return 1;
}

int SFAsin(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, asin(x));
    return 1;
}

int SFAtan(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, atan(x));
    return 1;
}

int SFCeil(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, ceil(x));
    return 1;
}

int SFCos(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, cos(x));
    return 1;
}

int SFRandom(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, fmod(rand(), x));
    return 1;
}

int SFRandomRange(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    double y = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, x + fmod(rand(), (y - x)));
    return 1;
}

int SFFloor(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, floor(x));
    return 1;
}

int SFLn(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, log(x));
    return 1;
}

int SFLg(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, log10(x));
    return 1;
}

int SFLb(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, log2(x));
    return 1;
}

int SFSin(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, sin(x));
    return 1;
}

int SFSqrt(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, sqrt(x));
    return 1;
}

int SFTan(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, tan(x));
    return 1;
}

int SFCbrt(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, cbrt(x));
    return 1;
}

int SFMax(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    double y = lua_tonumber(Scripts.vm, 2);
    #ifndef CC_DJGPP
		lua_pushnumber(Scripts.vm, fmax(x, y));
    #else
		if (x > y)
			lua_pushnumber(Scripts.vm, x);
		else
			lua_pushnumber(Scripts.vm, y);
    #endif
    return 1;
}

int SFMin(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    double y = lua_tonumber(Scripts.vm, 2);
    #ifndef CC_DJGPP
		lua_pushnumber(Scripts.vm, fmin(x, y));
	#else
		if (x < y)
			lua_pushnumber(Scripts.vm, x);
		else
			lua_pushnumber(Scripts.vm, y);
    #endif
    return 1;
}

int SFRound(lua_State* l)
{
    double x = lua_tonumber(Scripts.vm, 1);
    #ifndef CC_DJGPP
		lua_pushnumber(Scripts.vm, round(x));
    #else
		if (floor(x) < x - 0.5)
			lua_pushnumber(Scripts.vm, ceil(x));
		else
			lua_pushnumber(Scripts.vm, floor(x));
    #endif
    return 1;
}

int SFVectorLength(lua_State* l)
{
    double x1 = lua_tonumber(Scripts.vm, 1);
    double y1 = lua_tonumber(Scripts.vm, 2);
    double x2 = lua_tonumber(Scripts.vm, 3);
    double y2 = lua_tonumber(Scripts.vm, 4);

    double length = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    lua_pushnumber(Scripts.vm, length);
    return 1;
}

int SFVectorDirection(lua_State* l)
{
    double x1 = lua_tonumber(Scripts.vm, 1);
    double y1 = lua_tonumber(Scripts.vm, 2);
    double x2 = lua_tonumber(Scripts.vm, 3);
    double y2 = lua_tonumber(Scripts.vm, 4);

    double dir = acos((x2 - x1) / sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));

    if (y2 > y1)
    {
        dir = M_PI * 2 - dir;
    }

    lua_pushnumber(Scripts.vm, dir);
    return 1;
}

int SFVectorXY(lua_State* l)
{
    double length = lua_tonumber(Scripts.vm, 1);
    double dir = lua_tonumber(Scripts.vm, 2);

    double x = 0;
    double y = 0;

    x = -(length * cos(M_PI - dir));
    y = -(length * sin(M_PI - dir));

    lua_pushnumber(Scripts.vm, x);
    lua_pushnumber(Scripts.vm, y);
    return 2;
}

int SFMusicLoad(lua_State* l)
{
    char *filename = (char *)lua_tostring(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, SoundsMusicLoad(filename));
    return 1;
}

int SFSoundLoad(lua_State* l)
{
    char *filename = (char *)lua_tostring(Scripts.vm, 1);
    lua_pushnumber(Scripts.vm, SoundsSoundLoad(filename));
    return 1;
}

int SFSoundPlay(lua_State* l)
{
    int num = lua_tonumber(Scripts.vm, 1);
    SoundsSoundPlay(num);
    return 0;
}

int SFSoundSetVolume(lua_State* l)
{
    int num = lua_tonumber(Scripts.vm, 1);
    int volume = lua_tonumber(Scripts.vm, 2);
    SoundsSoundSetVolume(num, volume);
    return 0;
}

int SFSoundSetChannelsVolume(lua_State* l)
{
    int volume = lua_tonumber(Scripts.vm, 1);
    SoundsSoundSetChannelsVolume(volume);
    return 0;
}

int SFSoundPause(lua_State* l)
{
    SoundsSoundPause();
    return 0;
}

int SFSoundResume(lua_State* l)
{
    SoundsSoundResume();
    return 0;
}

int SFSoundStop(lua_State* l)
{
    SoundsSoundStop();
    return 0;
}

int SFMusicPlay(lua_State* l)
{
    int num = lua_tonumber(Scripts.vm, 1);
    SoundsMusicPlay(num);
    return 0;
}

int SFMusicPause(lua_State* l)
{
    SoundsMusicPause();
    return 0;
}

int SFMusicResume(lua_State* l)
{
    SoundsMusicResume();
    return 0;
}

int SFMusicStop(lua_State* l)
{
    SoundsMusicStop();
    return 0;
}

int SFMusicSetVolume(lua_State* l)
{
    int volume = lua_tonumber(Scripts.vm, 1);
    SoundsMusicSetVolume(volume);
    return 0;
}

int SFPhysicsBlockCreate(lua_State* l)
{
    int x = lua_tonumber(Scripts.vm, 1);
    int y = lua_tonumber(Scripts.vm, 2);
    int width = lua_tonumber(Scripts.vm, 3);
    int height = lua_tonumber(Scripts.vm, 4);
    lua_pushnumber(Scripts.vm, PhysicsPlaceBlock(x, y, width, height));
    return 1;
}

int SFPhysicsObjectCreate(lua_State* l)
{
    int x = lua_tonumber(Scripts.vm, 1);
    int y = lua_tonumber(Scripts.vm, 2);
    int width = lua_tonumber(Scripts.vm, 3);
    int height = lua_tonumber(Scripts.vm, 4);
    double mass = lua_tonumber(Scripts.vm, 5);
    lua_pushnumber(Scripts.vm, PhysicsPlaceObject(x, y, width, height, mass));
    return 1;
}

int SFPhysicsObjectRefreshStats(lua_State* l)
{
    int object = lua_tonumber(Scripts.vm, 1);
    PhysicsBodyRefreshStats(object);
    return 0;
}

int SFPhysicsStep(lua_State* l)
{
    PhysicsStep();
    return 0;
}

int SFBitmapCreate(lua_State* l)
{
    int width = lua_tonumber(Scripts.vm, 1);
    int height = lua_tonumber(Scripts.vm, 2);
    int bpp = lua_tonumber(Scripts.vm, 3);
    lua_pushnumber(Scripts.vm, ImagesCreateBitmap(width, height, bpp));
    return 1;
}

int SFBitmapSave(lua_State* l)
{
    int num = lua_tonumber(Scripts.vm, 1);
    char *filename = (char *)lua_tostring(Scripts.vm, 2);
    ImagesSaveBitmap(num, filename);
    return 0;
}

int SFBitmapSetPixel(lua_State* l)
{
    int num = lua_tonumber(Scripts.vm, 1);
    int x = lua_tonumber(Scripts.vm, 2);
    int y = lua_tonumber(Scripts.vm, 3);
    int r = lua_tonumber(Scripts.vm, 4);
    int g = lua_tonumber(Scripts.vm, 5);
    int b = lua_tonumber(Scripts.vm, 6);
    int a = lua_tonumber(Scripts.vm, 7);
    ImagesSetPixel(num, x, y, r, g, b, a);
    return 0;
}

int SFFileOpen(lua_State* l)
{
    char *filename = (char *)lua_tostring(Scripts.vm, 1);
    FileOpenForWrite(filename);
    return 0;
}

int SFFileClose(lua_State* l)
{
    FileClose();
    return 0;
}

int SFFileWriteLine(lua_State* l)
{
    char *text = (char *)lua_tostring(Scripts.vm, 1);
    FileWriteLine(text);
    return 0;
}

int SFDialogShowSimpleMessageBox(lua_State* l)
{
    int type = lua_tonumber(Scripts.vm, 1);
    char *title = (char *)lua_tostring(Scripts.vm, 2);
    char *message = (char *)lua_tostring(Scripts.vm, 3);
    DialogsShowSimpleMessageBox(type, title, message);
    return 0;
}

int SFDialogShowYesNoMessageBox(lua_State* l)
{
    char *title = (char *)lua_tostring(Scripts.vm, 1);
    char *message = (char *)lua_tostring(Scripts.vm, 2);
	lua_pushboolean(Scripts.vm, DialogsShowYesNoMessageBox(title, message));
    return 1;
}

int SFLogWrite(lua_State* l)
{
    char *text = (char *)lua_tostring(Scripts.vm, 1);
    int level = lua_tonumber(Scripts.vm, 2);
    int messageType = lua_tonumber(Scripts.vm, 3);
    char *argument = (char *)lua_tostring(Scripts.vm, 4);
    LogWriteFromScript(text, level, messageType, argument);
    return 0;
}

int SFScriptRegisterNumericVariable(lua_State* l)
{
	char *name = (char *)lua_tostring(Scripts.vm, 1);
	double value = lua_tonumber(Scripts.vm, 2);
	ScriptsRegisterNumericVariable(name, value);
	return 0;
}

int SFScriptRegisterStringVariable(lua_State* l)
{
	char *name = (char *)lua_tostring(Scripts.vm, 1);
	char *value = (char *)lua_tostring(Scripts.vm, 2);
	ScriptsRegisterStringVariable(name, value);
	return 0;
}
