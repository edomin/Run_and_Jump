#ifdef LS_SQUIRREL
#include "scriptFuncs/squirrel.h"

SQInteger SFInitApp(HSQUIRRELVM v)
{
    AppInit();
    return 0;
}

SQInteger SFInitScreen(HSQUIRRELVM v)
{
    int w;
    int h;
    const char *title;
    bool fullscreen;
    sq_getinteger(Scripts.vm, 2, &w);    /* получаем 1-ый */
                                         /* переданный параметр */
    sq_getinteger(Scripts.vm, 3, &h);
    sq_getstring(Scripts.vm, 4, &title);
    sq_getbool(Scripts.vm, 5, &fullscreen);
    ScreenInit(w, h, title, fullscreen);
    return 0;
}

SQInteger SFInitDraw(HSQUIRRELVM v)
{
    int driver;
    int filtering;
    sq_getinteger(Scripts.vm, 2, &driver);
    sq_getinteger(Scripts.vm, 3, &filtering);
    DrawInit(driver, filtering);

    return 0;
}

SQInteger SFInitInput(HSQUIRRELVM v)
{
    InputInit();
    return 0;
}

SQInteger SFInitTimer(HSQUIRRELVM v)
{
    InitTimer();
    return 0;
}

SQInteger SFInitSprites(HSQUIRRELVM v)
{
    int sprites;
    sq_getinteger(Scripts.vm, 2, &sprites);
    SpritesInit(sprites);
    return 0;
}

SQInteger SFInitFonts(HSQUIRRELVM v)
{
    int fonts;
    sq_getinteger(Scripts.vm, 2, &fonts);
    FontsInit(fonts);
    return 0;
}

SQInteger SFInitSounds(HSQUIRRELVM v)
{
    int maxSounds;
    int maxMusic;
    int freq;
    sq_getinteger(Scripts.vm, 2, &maxSounds);
    sq_getinteger(Scripts.vm, 3, &maxMusic);
    sq_getinteger(Scripts.vm, 4, &freq);
    SoundsInit(maxSounds, maxMusic, freq, 2, 1024);
    return 0;
}

SQInteger SFInitImages(HSQUIRRELVM v)
{
    int maxImages;
    sq_getinteger(Scripts.vm, 2, &maxImages);
    ImagesInit(maxImages);
    return 0;
}

SQInteger SFInitPhysics(HSQUIRRELVM v)
{
    int maxBlocks;
    int maxObjects;
    SQFloat xGrav;
    SQFloat yGrav;
    SQFloat cfm;
    SQFloat stepSize;
    sq_getinteger(Scripts.vm, 2, &maxBlocks);
    sq_getinteger(Scripts.vm, 3, &maxObjects);
    sq_getfloat(Scripts.vm, 4, &xGrav);
    sq_getfloat(Scripts.vm, 5, &yGrav);
    sq_getfloat(Scripts.vm, 6, &cfm);
    sq_getfloat(Scripts.vm, 7, &stepSize);
    PhysicsInit(xGrav, yGrav, cfm, stepSize, maxBlocks, maxObjects);
    return 0;
}

SQInteger SFConfigfileCreateConfig(HSQUIRRELVM v)
{
    ConfigfileCreateConfig();
    return 0;
}

SQInteger SFConfigfileLoadConfig(HSQUIRRELVM v)
{
    char *filename;
    sq_getstring(Scripts.vm, 2, (const char **)&filename);
    ConfigfileLoadConfig(filename);
    return 0;
}

SQInteger SFConfigfileSaveConfig(HSQUIRRELVM v)
{
    char *filename;
    sq_getstring(Scripts.vm, 2, (const char **)&filename);
    ConfigfileSaveConfig(filename);
    return 0;
}

SQInteger SFConfigfileAddSection(HSQUIRRELVM v)
{
    char *section;
    sq_getstring(Scripts.vm, 2, (const char **)&section);
    ConfigfileAddSection(section);
    return 0;
}

SQInteger SFConfigfileSetKeyValue(HSQUIRRELVM v)
{
    char *section;
    char *key;
    char *value;
    sq_getstring(Scripts.vm, 2, (const char **)&section);
    sq_getstring(Scripts.vm, 3, (const char **)&key);
    sq_getstring(Scripts.vm, 4, (const char **)&value);
    ConfigfileSetKeyValue(section, key, value);
    return 0;
}

SQInteger SFConfigfileGetKeyValue(HSQUIRRELVM v)
{
    char *section;
    char *key;
    char *value;
    sq_getstring(Scripts.vm, 2, (const char **)&section);
    sq_getstring(Scripts.vm, 3, (const char **)&key);
    value = ConfigfileGetKeyValue(section, key);
    sq_pushstring(Scripts.vm, value);
    return 1;
}

SQInteger SFFontLoad(HSQUIRRELVM v)
{
    char *filename;
    int size;
    int font;
    sq_getstring(Scripts.vm, 2, (const char **)&filename);
    sq_getinteger(Scripts.vm, 3, &size);

    font = FontsLoadFont(filename, size);

    sq_pushinteger(Scripts.vm, font);
    return 1;
}

SQInteger SFSpriteLoad(HSQUIRRELVM v)
{
    char *filename;
    int clips;
    int sprite;
    sq_getstring(Scripts.vm, 2, (const char **)&filename);
    sq_getinteger(Scripts.vm, 3, &clips);

    sprite = SpritesCreateSprite(filename, clips);
    sq_pushinteger(Scripts.vm, sprite);
    return 1;
}

SQInteger SFSpriteCreateText(HSQUIRRELVM v)
{
    char *text;
    int fontnum;
    int text_r;
    int text_g;
    int text_b;
    int sprite;
    sq_getstring(Scripts.vm, 2, (const char **)&text);
    sq_getinteger(Scripts.vm, 3, &fontnum);
    sq_getinteger(Scripts.vm, 4, &text_r);
    sq_getinteger(Scripts.vm, 5, &text_g);
    sq_getinteger(Scripts.vm, 6, &text_b);

    sprite = SpritesCreateText(text, fontnum, text_r, text_g, text_b,
                               WRAP_NOWRAP);
    sq_pushinteger(Scripts.vm, sprite);
    return 1;
}

SQInteger SFSpriteCreateTextWrapped(HSQUIRRELVM v)
{
    char *text;
    int fontnum;
    int textR;
    int textG;
    int textB;
    int wrapLength;
    int sprite;
    sq_getstring(Scripts.vm, 2, (const char **)&text);
    sq_getinteger(Scripts.vm, 3, &fontnum);
    sq_getinteger(Scripts.vm, 4, &textR);
    sq_getinteger(Scripts.vm, 5, &textG);
    sq_getinteger(Scripts.vm, 6, &textB);
    sq_getinteger(Scripts.vm, 7, &wrapLength);

    sprite = SpritesCreateText(text, fontnum, textR, textG, textB, wrapLength);
    sq_pushinteger(Scripts.vm, sprite);
    return 1;
}

SQInteger SFSpriteChangeText(HSQUIRRELVM v)
{
    int spriteNum;
    char *text;
    int fontNum;
    int textR;
    int textG;
    int textB;
    sq_getinteger(Scripts.vm, 2, &spriteNum);
    sq_getstring(Scripts.vm, 3, (const char **)&text);
    sq_getinteger(Scripts.vm, 4, &fontNum);
    sq_getinteger(Scripts.vm, 5, &textR);
    sq_getinteger(Scripts.vm, 6, &textG);
    sq_getinteger(Scripts.vm, 7, &textB);

    SpritesChangeText(spriteNum, text, fontNum, textR, textG, textB,
                      WRAP_NOWRAP);
    return 0;
}

SQInteger SFSpriteChangeTextWrapped(HSQUIRRELVM v)
{
    int spriteNum;
    char *text;
    int fontNum;
    int textR;
    int textG;
    int textB;
    int wrapLength;
    sq_getinteger(Scripts.vm, 2, &spriteNum);
    sq_getstring(Scripts.vm, 3, (const char **)&text);
    sq_getinteger(Scripts.vm, 4, &fontNum);
    sq_getinteger(Scripts.vm, 5, &textR);
    sq_getinteger(Scripts.vm, 6, &textG);
    sq_getinteger(Scripts.vm, 7, &textB);
    sq_getinteger(Scripts.vm, 8, &wrapLength);

    SpritesChangeText(spriteNum, text, fontNum, textR, textG, textB,
                      wrapLength);
    return 0;
}

SQInteger SFSpriteGetClipWidthHeight(HSQUIRRELVM v)
{
    int spriteNum;
    sq_getinteger(Scripts.vm, 2, &spriteNum);

    sq_pushinteger(Scripts.vm, (Sprite[spriteNum].clip[0].w));
    sq_pushinteger(Scripts.vm, (Sprite[spriteNum].clip[0].h));
    return 2;
}

SQInteger SFFlip(HSQUIRRELVM v)
{
    DrawFlip();
    return 0;
}

SQInteger SFTimerStart(HSQUIRRELVM v)
{
    TimerStart();
    return 0;
}

SQInteger SFXed(HSQUIRRELVM v)
{
    if (AppXed())
    {
        sq_pushbool(Scripts.vm, SQTrue);
    }
    else
    {
        sq_pushbool(Scripts.vm, SQFalse);
    }
    return 1;
}

SQInteger SFKeyPress(HSQUIRRELVM v)
{
    int key;
    sq_getinteger(Scripts.vm, 2, &key);
    if (InputKeyPress(key))
    {
        sq_pushbool(Scripts.vm, SQTrue);
    }
    else
    {
        sq_pushbool(Scripts.vm, SQFalse);
    }
    return 1;
}

SQInteger SFKeyRelease(HSQUIRRELVM v)
{
    int key;
    sq_getinteger(Scripts.vm, 2, &key);
    if (InputKeyRelease(key))
    {
        sq_pushbool(Scripts.vm, SQTrue);
    }
    else
    {
        sq_pushbool(Scripts.vm, SQFalse);
    }
    return 1;
}

SQInteger SFKeyPressed(HSQUIRRELVM v)
{
    int key;
    sq_getinteger(Scripts.vm, 2, &key);
    if (InputKeyPressed(key))
    {
        sq_pushbool(Scripts.vm, SQTrue);
    }
    else
    {
        sq_pushbool(Scripts.vm, SQFalse);
    }
    return 1;
}

SQInteger SFKeystatesRefresh(HSQUIRRELVM v)
{
    InputKeystatesRefresh();
    return 0;
}

SQInteger SFMouseRefresh(HSQUIRRELVM v)
{
    InputMouseRefresh();
    return 0;
}

SQInteger SFMouseGetCoords(HSQUIRRELVM v)
{
    sq_pushinteger(Scripts.vm, App.mouseX);
    sq_pushinteger(Scripts.vm, App.mouseY);
    return 2;
}

SQInteger SFMousePressed(HSQUIRRELVM v) /* 1 - left; 2 - middle; 3 - right; */
{
    int button;
    sq_getinteger(Scripts.vm, 2, &button);
    switch (button)
    {
        case 1: /* left */
        {
            if (Input.currentMouseLeft)
            {
                sq_pushbool(Scripts.vm, SQTrue);
            }
            else
            {
                sq_pushbool(Scripts.vm, SQFalse);
            }
            break;
        }
        case 2: /* middle */
        {
            if (Input.currentMouseMiddle)
            {
                sq_pushbool(Scripts.vm, SQTrue);
            }
            else
            {
                sq_pushbool(Scripts.vm, SQFalse);
            }
            break;
        }
        case 3: /* right */
        {
            if (Input.currentMouseRight)
            {
                sq_pushbool(Scripts.vm, SQTrue);
            }
            else
            {
                sq_pushbool(Scripts.vm, SQFalse);
            }
            break;
        }
    }
    return 1;
}

SQInteger SFMousePress(HSQUIRRELVM v) /* 1 - left; 2 - middle; 3 - right; */
{
    int button;
    sq_getinteger(Scripts.vm, 2, &button);
    switch (button)
    {
        case 1: /* left */
        {
            if (Input.currentMouseLeft && !(Input.previousMouseLeft))
            {
                sq_pushbool(Scripts.vm, SQTrue);
            }
            else
            {
                sq_pushbool(Scripts.vm, SQFalse);
            }
            break;
        }
        case 2: /* middle */
        {
            if (Input.currentMouseMiddle && !(Input.previousMouseMiddle))
            {
                sq_pushbool(Scripts.vm, SQTrue);
            }
            else
            {
                sq_pushbool(Scripts.vm, SQFalse);
            }
            break;
        }
        case 3: /* right */
        {
            if (Input.currentMouseRight && !(Input.previousMouseRight))
            {
                sq_pushbool(Scripts.vm, SQTrue);
            }
            else
            {
                sq_pushbool(Scripts.vm, SQFalse);
            }
            break;
        }
    }
    return 1;
}

SQInteger SFMouseRelease(HSQUIRRELVM v) /* 1 - left; 2 - middle; 3 - right; */
{
    int button;
    sq_getinteger(Scripts.vm, 2, &button);
    switch (button)
    {
        case 1: /* left */
        {
            if (Input.previousMouseLeft && !(Input.currentMouseLeft))
            {
                sq_pushbool(Scripts.vm, SQTrue);
            }
            else
            {
                sq_pushbool(Scripts.vm, SQFalse);
            }
            break;
        }
        case 2: /* middle */
        {
            if (Input.previousMouseMiddle && !(Input.currentMouseMiddle))
            {
                sq_pushbool(Scripts.vm, SQTrue);
            }
            else
            {
                sq_pushbool(Scripts.vm, SQFalse);
            }
            break;
        }
        case 3: /* right */
        {
            if (Input.previousMouseRight && !(Input.currentMouseRight))
            {
                sq_pushbool(Scripts.vm, SQTrue);
            }
            else
            {
                sq_pushbool(Scripts.vm, SQFalse);
            }
            break;
        }
    }
    return 1;
}

SQInteger SFMouseCursorShow(HSQUIRRELVM v)
{
    ScreenCursorShow();
    return 0;
}

SQInteger SFMouseCursorHide(HSQUIRRELVM v)
{
    ScreenCursorHide();
    return 0;
}

SQInteger SFControllerRefresh(HSQUIRRELVM v)
{
    InputControllersRefresh();
    return 0;
}

SQInteger SFControllerPress(HSQUIRRELVM v)
{
    int controllerNum;
    Uint8 button;
    sq_getinteger(Scripts.vm, 2, &controllerNum);
    sq_getinteger(Scripts.vm, 3, (SQInteger *)&button);
    if (InputControllerButtonPress(controllerNum, button))
    {
        sq_pushbool(Scripts.vm, SQTrue);
    }
    else
    {
        sq_pushbool(Scripts.vm, SQFalse);
    }
    return 1;
}

SQInteger SFControllerRelease(HSQUIRRELVM v)
{
    int controllerNum;
    Uint8 button;
    sq_getinteger(Scripts.vm, 2, &controllerNum);
    sq_getinteger(Scripts.vm, 3, (SQInteger *)&button);
    if (InputControllerButtonRelease(controllerNum, button))
    {
        sq_pushbool(Scripts.vm, SQTrue);
    }
    else
    {
        sq_pushbool(Scripts.vm, SQFalse);
    }
    return 1;
}

SQInteger SFControllerPressed(HSQUIRRELVM v)
{
    int controllerNum;
    Uint8 button;
    sq_getinteger(Scripts.vm, 2, &controllerNum);
    sq_getinteger(Scripts.vm, 3, (SQInteger *)&button);
    if (InputControllerButtonPressed(controllerNum, button))
    {
        sq_pushbool(Scripts.vm, SQTrue);
    }
    else
    {
        sq_pushbool(Scripts.vm, SQFalse);
    }
    return 1;
}

SQInteger SFControllerGetAxis(HSQUIRRELVM v)
{
    Sint16 axisValue;
    int controllerNum;
    Uint8 axis;
    sq_getinteger(Scripts.vm, 2, &controllerNum);
    sq_getinteger(Scripts.vm, 3, (SQInteger *)&axis);
    axisValue = InputControllerGetAxis(controllerNum, axis);
    sq_pushinteger(Scripts.vm, axisValue);
    return 1;
}

SQInteger SFDestroySprites(HSQUIRRELVM v)
{
    SpritesQuit();
    return 0;
}

SQInteger SFDestroyFonts(HSQUIRRELVM v)
{
    FontsQuit();
    return 0;
}

SQInteger SFDestroySounds(HSQUIRRELVM v)
{
    SoundsDestroy();
    return 0;
}

SQInteger SFDestroyImages(HSQUIRRELVM v)
{
    ImagesQuit();
    return 0;
}

SQInteger SFDestroyInput(HSQUIRRELVM v)
{
    InputQuit();
    return 0;
}

SQInteger SFDestroyPhysics(HSQUIRRELVM v)
{
    PhysicsDestroy();
    return 0;
}

SQInteger SFDestroyApp(HSQUIRRELVM v)
{
    AppDestroy();
    return 0;
}

SQInteger SFDestroyDraw(HSQUIRRELVM v)
{
    DrawDestroy();
    return 0;
}

SQInteger SFDestroyScreen(HSQUIRRELVM v)
{
    ScreenDestroy();
    return 0;
}

SQInteger SFDelay(HSQUIRRELVM v)
{
    int ms;
    int currentFps;

    sq_getinteger(Scripts.vm, 2, &ms);
    currentFps = TimerDelay(ms);
    sq_pushinteger(Scripts.vm, currentFps);
    return 1;
}

SQInteger SFDelayForFPS(HSQUIRRELVM v)
{
    int fps;
    int currentFps;

    sq_getinteger(Scripts.vm, 2, &fps);
    currentFps = TimerDelayForFPS(fps);
    sq_pushinteger(Scripts.vm, currentFps);
    return 1;
}

SQInteger SFDrawAddSprite(HSQUIRRELVM v)
{
    int spriteNum;
    int clipNum;
    int x;
    int y;
    sq_getinteger(Scripts.vm, 2, &spriteNum);
    sq_getinteger(Scripts.vm, 3, &clipNum);
    sq_getinteger(Scripts.vm, 4, &x);
    sq_getinteger(Scripts.vm, 5, &y);

    DrawAddSprite(spriteNum, clipNum, x, y);

    return 0;
}

SQInteger SFDrawAddSpriteSized(HSQUIRRELVM v)
{
    int spriteNum;
    int clipNum;
    int x;
    int y;
    int width;
    int height;
    sq_getinteger(Scripts.vm, 2, &spriteNum);
    sq_getinteger(Scripts.vm, 3, &clipNum);
    sq_getinteger(Scripts.vm, 4, &x);
    sq_getinteger(Scripts.vm, 5, &y);
    sq_getinteger(Scripts.vm, 6, &width);
    sq_getinteger(Scripts.vm, 7, &height);

    DrawAddSpriteSized(spriteNum, clipNum, x, y, width, height);

    return 0;
}

SQInteger SFDrawAddSpriteAngled(HSQUIRRELVM v)
{
    int spriteNum;
    int clipNum;
    int x;
    int y;
    int centerX;
    int centerY;
    SQFloat angle;
    sq_getinteger(Scripts.vm, 2, &spriteNum);
    sq_getinteger(Scripts.vm, 3, &clipNum);
    sq_getinteger(Scripts.vm, 4, &x);
    sq_getinteger(Scripts.vm, 5, &y);
    sq_getinteger(Scripts.vm, 6, &centerX);
    sq_getinteger(Scripts.vm, 7, &centerY);
    sq_getfloat(Scripts.vm, 8, &angle);

    DrawAddSpriteAngled(spriteNum, clipNum, x, y, centerX, centerY, angle);

    return 0;
}

SQInteger SFDrawAddSpriteAlpha(HSQUIRRELVM v)
{
    int spriteNum;
    int clipNum;
    int x;
    int y;
    int alpha;
    sq_getinteger(Scripts.vm, 2, &spriteNum);
    sq_getinteger(Scripts.vm, 3, &clipNum);
    sq_getinteger(Scripts.vm, 4, &x);
    sq_getinteger(Scripts.vm, 5, &y);
    sq_getinteger(Scripts.vm, 6, &alpha);

    DrawAddSpriteAlpha(spriteNum, clipNum, x, y, alpha);

    return 0;
}

SQInteger SFDrawAddSpriteGeneral(HSQUIRRELVM v)
{
    int spriteNum;
    int clipNum;
    int x;
    int y;
    int width;
    int height;
    int centerX;
    int centerY;
    SQFloat angle;
    int alpha;
    int flip;
    sq_getinteger(Scripts.vm, 2, &spriteNum);
    sq_getinteger(Scripts.vm, 3, &clipNum);
    sq_getinteger(Scripts.vm, 4, &x);
    sq_getinteger(Scripts.vm, 5, &y);
    sq_getinteger(Scripts.vm, 6, &width);
    sq_getinteger(Scripts.vm, 7, &height);
    sq_getinteger(Scripts.vm, 8, &centerX);
    sq_getinteger(Scripts.vm, 9, &centerY);
    sq_getfloat(Scripts.vm, 10, &angle);
    sq_getinteger(Scripts.vm, 11, &alpha);
    sq_getinteger(Scripts.vm, 12, &alpha);

    DrawAddSpriteGeneral(spriteNum, clipNum, x, y, width, height, centerX,
                         centerY, angle, alpha, flip);

    return 0;
}

SQInteger SFDrawPoint(HSQUIRRELVM v)
{
    int x;
    int y;
    int r;
    int g;
    int b;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_getinteger(Scripts.vm, 3, &y);
    sq_getinteger(Scripts.vm, 4, &r);
    sq_getinteger(Scripts.vm, 5, &g);
    sq_getinteger(Scripts.vm, 6, &b);

    DrawAddPoint(x, y, r, g, b, 255);

    return 0;
}

SQInteger SFDrawPointAlpha(HSQUIRRELVM v)
{
    int x;
    int y;
    int r;
    int g;
    int b;
    int a;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_getinteger(Scripts.vm, 3, &y);
    sq_getinteger(Scripts.vm, 4, &r);
    sq_getinteger(Scripts.vm, 5, &g);
    sq_getinteger(Scripts.vm, 6, &b);
    sq_getinteger(Scripts.vm, 7, &a);

    DrawAddPoint(x, y, r, g, b, a);

    return 0;
}

SQInteger SFDrawLine(HSQUIRRELVM v)
{
    int x1;
    int y1;
    int x2;
    int y2;
    int r;
    int g;
    int b;
    sq_getinteger(Scripts.vm, 2, &x1);
    sq_getinteger(Scripts.vm, 3, &y1);
    sq_getinteger(Scripts.vm, 4, &x2);
    sq_getinteger(Scripts.vm, 5, &y2);
    sq_getinteger(Scripts.vm, 6, &r);
    sq_getinteger(Scripts.vm, 7, &g);
    sq_getinteger(Scripts.vm, 8, &b);

    DrawAddLine(x1, y1, x2, y2, r, g, b, 255);

    return 0;
}

SQInteger SFDrawLineAlpha(HSQUIRRELVM v)
{
    int x1;
    int y1;
    int x2;
    int y2;
    int r;
    int g;
    int b;
    int a;
    sq_getinteger(Scripts.vm, 2, &x1);
    sq_getinteger(Scripts.vm, 3, &y1);
    sq_getinteger(Scripts.vm, 4, &x2);
    sq_getinteger(Scripts.vm, 5, &y2);
    sq_getinteger(Scripts.vm, 6, &r);
    sq_getinteger(Scripts.vm, 7, &g);
    sq_getinteger(Scripts.vm, 8, &b);
    sq_getinteger(Scripts.vm, 9, &a);

    DrawAddLine(x1, y1, x2, y2, r, g, b, a);

    return 0;
}

SQInteger SFDrawRect(HSQUIRRELVM v)
{
    int x;
    int y;
    int w;
    int h;
    int r;
    int g;
    int b;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_getinteger(Scripts.vm, 3, &y);
    sq_getinteger(Scripts.vm, 4, &w);
    sq_getinteger(Scripts.vm, 5, &h);
    sq_getinteger(Scripts.vm, 6, &r);
    sq_getinteger(Scripts.vm, 7, &g);
    sq_getinteger(Scripts.vm, 8, &b);

    DrawAddRect(x, y, w, h, r, g, b, 255);

    return 0;
}

SQInteger SFDrawRectAlpha(HSQUIRRELVM v)
{
    int x;
    int y;
    int w;
    int h;
    int r;
    int g;
    int b;
    int a;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_getinteger(Scripts.vm, 3, &y);
    sq_getinteger(Scripts.vm, 4, &w);
    sq_getinteger(Scripts.vm, 5, &h);
    sq_getinteger(Scripts.vm, 6, &r);
    sq_getinteger(Scripts.vm, 7, &g);
    sq_getinteger(Scripts.vm, 8, &b);
    sq_getinteger(Scripts.vm, 8, &a);

    DrawAddRect(x, y, w, h, r, g, b, a);

    return 0;
}

SQInteger SFDrawFilledRect(HSQUIRRELVM v)
{
    int x;
    int y;
    int w;
    int h;
    int r;
    int g;
    int b;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_getinteger(Scripts.vm, 3, &y);
    sq_getinteger(Scripts.vm, 4, &w);
    sq_getinteger(Scripts.vm, 5, &h);
    sq_getinteger(Scripts.vm, 6, &r);
    sq_getinteger(Scripts.vm, 7, &g);
    sq_getinteger(Scripts.vm, 8, &b);

    DrawAddFilledRect(x, y, w, h, r, g, b, 255);

    return 0;
}

SQInteger SFDrawFilledRectAlpha(HSQUIRRELVM v)
{
    int x;
    int y;
    int w;
    int h;
    int r;
    int g;
    int b;
    int a;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_getinteger(Scripts.vm, 3, &y);
    sq_getinteger(Scripts.vm, 4, &w);
    sq_getinteger(Scripts.vm, 5, &h);
    sq_getinteger(Scripts.vm, 6, &r);
    sq_getinteger(Scripts.vm, 7, &g);
    sq_getinteger(Scripts.vm, 8, &b);
    sq_getinteger(Scripts.vm, 9, &a);

    DrawAddFilledRect(x, y, w, h, r, g, b, a);

    return 0;
}

SQInteger SFDrawFill(HSQUIRRELVM v)
{
    int r;
    int g;
    int b;
    sq_getinteger(Scripts.vm, 2, &r);
    sq_getinteger(Scripts.vm, 3, &g);
    sq_getinteger(Scripts.vm, 4, &b);

    DrawAddFill(r, g, b, 255);

    return 0;
}

SQInteger SFDrawFillAlpha(HSQUIRRELVM v)
{
    int r;
    int g;
    int b;
    int a;
    sq_getinteger(Scripts.vm, 2, &r);
    sq_getinteger(Scripts.vm, 3, &g);
    sq_getinteger(Scripts.vm, 4, &b);
    sq_getinteger(Scripts.vm, 5, &a);

    DrawAddFill(r, g, b, a);

    return 0;
}

SQInteger SFDrawOutput(HSQUIRRELVM v)
{
    int roundLength = DrawOutput();
    sq_pushinteger(Scripts.vm, roundLength);
    return 1;
}

SQInteger SFAbs(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, fabs(x));
    return 1;
}

SQInteger SFSign(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    if (x < 0)
    {
        sq_pushinteger(Scripts.vm, -1);
    }
    if (x == 0)
    {
        sq_pushinteger(Scripts.vm, 0);
    }
    if (x > 0)
    {
        sq_pushinteger(Scripts.vm, 1);
    }
    return 1;
}

SQInteger SFAcos(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, acos(x));
    return 1;
}

SQInteger SFAsin(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, asin(x));
    return 1;
}

SQInteger SFAtan(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, atan(x));
    return 1;
}

SQInteger SFCeil(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, ceil(x));
    return 1;
}

SQInteger SFCos(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, cos(x));
    return 1;
}

SQInteger SFRandom(HSQUIRRELVM v)
{
    int x;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_pushinteger(Scripts.vm, fmod(rand(), x));
    return 1;
}

SQInteger SFRandomRange(HSQUIRRELVM v)
{
    int x;
    int y;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_getinteger(Scripts.vm, 3, &y);
    sq_pushinteger(Scripts.vm, x + fmod(rand(), (y - x)));
    return 1;
}

SQInteger SFFloor(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, floor(x));
    return 1;
}

SQInteger SFLn(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, log(x));
    return 1;
}

SQInteger SFLg(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, log10(x));
    return 1;
}

SQInteger SFLb(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, log2(x));
    return 1;
}

SQInteger SFSin(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, sin(x));
    return 1;
}

SQInteger SFSqrt(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, sqrt(x));
    return 1;
}

SQInteger SFTan(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, tan(x));
    return 1;
}

SQInteger SFCbrt(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_pushfloat(Scripts.vm, cbrt(x));
    return 1;
}

SQInteger SFMax(HSQUIRRELVM v)
{
    SQFloat x;
    SQFloat y;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_getfloat(Scripts.vm, 3, &y);
    #ifndef CC_DJGPP
        sq_pushfloat(Scripts.vm, fmax(x, y));
    #else
        if (x > y)
            sq_pushfloat(Scripts.vm, x);
        else
            sq_pushfloat(Scripts.vm, y);
    #endif
    return 1;
}

SQInteger SFMin(HSQUIRRELVM v)
{
    SQFloat x;
    SQFloat y;
    sq_getfloat(Scripts.vm, 2, &x);
    sq_getfloat(Scripts.vm, 3, &y);
    #ifndef CC_DJGPP
        sq_pushfloat(Scripts.vm, fmin(x, y));
    #else
        if (x < y)
            sq_pushfloat(Scripts.vm, x);
        else
            sq_pushfloat(Scripts.vm, y);
    #endif
    return 1;
}

SQInteger SFRound(HSQUIRRELVM v)
{
    SQFloat x;
    sq_getfloat(Scripts.vm, 2, &x);
    #ifndef CC_DJGPP
        sq_pushfloat(Scripts.vm, round(x));
    #else
        if (floor(x) < x - 0.5)
            sq_pushfloat(Scripts.vm, ceil(x));
        else
            sq_pushfloat(Scripts.vm, floor(x));
    #endif
    return 1;
}

SQInteger SFVectorLength(HSQUIRRELVM v)
{
    SQFloat x1;
    SQFloat y1;
    SQFloat x2;
    SQFloat y2;
    SQFloat length;
    sq_getfloat(Scripts.vm, 2, &x1);
    sq_getfloat(Scripts.vm, 3, &y1);
    sq_getfloat(Scripts.vm, 4, &x2);
    sq_getfloat(Scripts.vm, 5, &y2);

    length = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    sq_pushfloat(Scripts.vm, length);
    return 1;
}

SQInteger SFVectorDirection(HSQUIRRELVM v)
{
    SQFloat x1;
    SQFloat y1;
    SQFloat x2;
    SQFloat y2;
    SQFloat dir;
    sq_getfloat(Scripts.vm, 2, &x1);
    sq_getfloat(Scripts.vm, 3, &y1);
    sq_getfloat(Scripts.vm, 4, &x2);
    sq_getfloat(Scripts.vm, 5, &y2);

    dir = acos((x2 - x1) / sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));

    if (y2 > y1)
    {
        dir = M_PI * 2 - dir;
    }

    sq_pushfloat(Scripts.vm, dir);
    return 1;
}

SQInteger SFVectorXY(HSQUIRRELVM v)
{
    SQFloat length;
    SQFloat dir;
    SQFloat x;
    SQFloat y;
    sq_getfloat(Scripts.vm, 2, &length);
    sq_getfloat(Scripts.vm, 3, &dir);

    x = -(length * cos(M_PI - dir));
    y = -(length * sin(M_PI - dir));

    sq_pushfloat(Scripts.vm, x);
    sq_pushfloat(Scripts.vm, y);
    return 2;
}

SQInteger SFMusicLoad(HSQUIRRELVM v)
{
    char *filename;
    sq_getstring(Scripts.vm, 2, (const char **)&filename);
    sq_pushinteger(Scripts.vm, SoundsMusicLoad(filename));
    return 1;
}

SQInteger SFSoundLoad(HSQUIRRELVM v)
{
    char *filename;
    sq_getstring(Scripts.vm, 2, (const char **)&filename);
    sq_pushinteger(Scripts.vm, SoundsSoundLoad(filename));
    return 1;
}

SQInteger SFSoundPlay(HSQUIRRELVM v)
{
    int num;
    sq_getinteger(Scripts.vm, 2, &num);
    SoundsSoundPlay(num);
    return 0;
}

SQInteger SFSoundSetVolume(HSQUIRRELVM v)
{
    int num;
    int volume;
    sq_getinteger(Scripts.vm, 2, &num);
    sq_getinteger(Scripts.vm, 3, &volume);
    SoundsSoundSetVolume(num, volume);
    return 0;
}

SQInteger SFSoundSetChannelsVolume(HSQUIRRELVM v)
{
    int volume;
    sq_getinteger(Scripts.vm, 2, &volume);
    SoundsSoundSetChannelsVolume(volume);
    return 0;
}

SQInteger SFSoundPause(HSQUIRRELVM v)
{
    SoundsSoundPause();
    return 0;
}

SQInteger SFSoundResume(HSQUIRRELVM v)
{
    SoundsSoundResume();
    return 0;
}

SQInteger SFSoundStop(HSQUIRRELVM v)
{
    SoundsSoundStop();
    return 0;
}

SQInteger SFMusicPlay(HSQUIRRELVM v)
{
    int num;
    sq_getinteger(Scripts.vm, 2, &num);
    SoundsMusicPlay(num);
    return 0;
}

SQInteger SFMusicPause(HSQUIRRELVM v)
{
    SoundsMusicPause();
    return 0;
}

SQInteger SFMusicResume(HSQUIRRELVM v)
{
    SoundsMusicResume();
    return 0;
}

SQInteger SFMusicStop(HSQUIRRELVM v)
{
    SoundsMusicStop();
    return 0;
}

SQInteger SFMusicSetVolume(HSQUIRRELVM v)
{
    int volume;
    sq_getinteger(Scripts.vm, 2, &volume);
    SoundsMusicSetVolume(volume);
    return 0;
}

SQInteger SFPhysicsBlockCreate(HSQUIRRELVM v)
{
    int x;
    int y;
    int width;
    int height;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_getinteger(Scripts.vm, 3, &y);
    sq_getinteger(Scripts.vm, 4, &width);
    sq_getinteger(Scripts.vm, 5, &height);
    sq_pushinteger(Scripts.vm, PhysicsPlaceBlock(x, y, width, height));
    return 1;
}

SQInteger SFPhysicsObjectCreate(HSQUIRRELVM v)
{
    int x;
    int y;
    int width;
    int height;
    SQFloat mass;
    sq_getinteger(Scripts.vm, 2, &x);
    sq_getinteger(Scripts.vm, 3, &y);
    sq_getinteger(Scripts.vm, 4, &width);
    sq_getinteger(Scripts.vm, 5, &height);
    sq_getfloat(Scripts.vm, 6, &mass);
    sq_pushinteger(Scripts.vm, PhysicsPlaceObject(x, y, width, height, mass));
    return 1;
}

SQInteger SFPhysicsObjectRefreshStats(HSQUIRRELVM v)
{
    int object;
    sq_getinteger(Scripts.vm, 2, &object);
    PhysicsBodyRefreshStats(object);
    return 0;
}

SQInteger SFPhysicsStep(HSQUIRRELVM v)
{
    PhysicsStep();
    return 0;
}

SQInteger SFBitmapCreate(HSQUIRRELVM v)
{
    int width;
    int height;
    int bpp;
    sq_getinteger(Scripts.vm, 2, &width);
    sq_getinteger(Scripts.vm, 3, &height);
    sq_getinteger(Scripts.vm, 4, &bpp);
    sq_pushinteger(Scripts.vm, ImagesCreateBitmap(width, height, bpp));
    return 1;
}

SQInteger SFBitmapSave(HSQUIRRELVM v)
{
    int num;
    char *filename;
    sq_getinteger(Scripts.vm, 2, &num);
    sq_getstring(Scripts.vm, 3, (const char **)&filename);
    ImagesSaveBitmap(num, filename);
    return 0;
}

SQInteger SFBitmapSetPixel(HSQUIRRELVM v)
{
    int num;
    int x;
    int y;
    int r;
    int g;
    int b;
    int a;
    sq_getinteger(Scripts.vm, 2, &num);
    sq_getinteger(Scripts.vm, 3, &x);
    sq_getinteger(Scripts.vm, 4, &y);
    sq_getinteger(Scripts.vm, 5, &r);
    sq_getinteger(Scripts.vm, 6, &g);
    sq_getinteger(Scripts.vm, 7, &b);
    sq_getinteger(Scripts.vm, 8, &a);
    ImagesSetPixel(num, x, y, r, g, b, a);
    return 0;
}

SQInteger SFFileOpen(HSQUIRRELVM v)
{
    char *filename;
    sq_getstring(Scripts.vm, 2, (const char **)&filename);
    FileOpenForWrite(filename);
    return 0;
}

SQInteger SFFileClose(HSQUIRRELVM v)
{
    FileClose();
    return 0;
}

SQInteger SFFileWriteLine(HSQUIRRELVM v)
{
    char *text;
    sq_getstring(Scripts.vm, 2, (const char **)&text);
    FileWriteLine(text);
    return 0;
}

SQInteger SFDialogShowSimpleMessageBox(HSQUIRRELVM v)
{
    int type;
    char *title;
    char *message;
    sq_getinteger(Scripts.vm, 2, &type);
    sq_getstring(Scripts.vm, 3, (const char **)&title);
    sq_getstring(Scripts.vm, 4, (const char **)&message);
    DialogsShowSimpleMessageBox(type, title, message);
    return 0;
}

SQInteger SFDialogShowYesNoMessageBox(HSQUIRRELVM v)
{
    char *title;
    char *message;
    sq_getstring(Scripts.vm, 2, (const char **)&title);
    sq_getstring(Scripts.vm, 3, (const char **)&message);

    sq_pushbool(Scripts.vm, DialogsShowYesNoMessageBox(title, message));
    return 1;
}

SQInteger SFLogWrite(HSQUIRRELVM v)
{
    char *text;
    int level;
    int messageType;
    char *argument;
    sq_getstring(Scripts.vm, 2, (const char **)&text);
    sq_getinteger(Scripts.vm, 3, &level);
    sq_getinteger(Scripts.vm, 4, &messageType);
    sq_getstring(Scripts.vm, 5, (const char **)&argument);
    LogWriteFromScript(text, level, messageType, argument);
    return 0;
}

SQInteger SFScriptRegisterNumericVariable(HSQUIRRELVM v)
{
    char *name;
    SQFloat value;
    sq_getstring(Scripts.vm, 2, (const char **)&name);
    sq_getfloat(Scripts.vm, 3, &value);
    ScriptsRegisterNumericVariable(name, value);
    return 0;
}

SQInteger SFScriptRegisterStringVariable(HSQUIRRELVM v)
{
    char *name;
    char *value;
    sq_getstring(Scripts.vm, 2, (const char **)&name);
    sq_getstring(Scripts.vm, 3, (const char **)&value);
    ScriptsRegisterStringVariable(name, value);
    return 0;
}

#endif
