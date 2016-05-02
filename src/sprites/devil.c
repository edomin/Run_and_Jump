#include "sprites/devil.h"

GLuint powerOfTwo(GLuint num)
{
    if (num != 0)
    {
        num--;
        num |= (num >> 1);
        num |= (num >> 2);
        num |= (num >> 4);
        num |= (num >> 8);
        num |= (num >> 16);
        num++;
    }
    return num;
}

void SpritesInit(int sprites)
{
    ILenum ilError;
    LogWrite("Initializing Sprite Manager", 0, MT_INFO, NULL);
    Sprites.spritesCount = 0; /* устанавливаем количество загруженных спрайтов в 0 */
    Sprite = malloc(sizeof(struct sprite) * sprites);
    if (Sprite == NULL)
        ErrorGive("Unable to allocate memory for Sprites", 1);

    ilInit();
    ilClearColour(255, 255, 255, 000);
    ilError = ilGetError();
    if (ilError != IL_NO_ERROR)
    {
        ErrorGive("Error of initializing DevIL!", 1);
    }
    LogWrite("Sprite Manager initialized", 0, MT_INFO, NULL);
}

void SpritesQuit(void)
{
    int i;
    LogWrite("Destroying Sprite Manager.", 0, MT_INFO, NULL);
    for (i = 0; i < Sprites.spritesCount; i++)
    {
        LogWrite("Destroying sprite", 1, MT_INFO, Sprite[i].name);
        SpritesDestroySprite(i);
    }
    free(Sprite);
    LogWrite("Sprite Manager Destroyed.", 0, MT_INFO, NULL);
}

int SpritesCreateSprite(char *filename, int clips)
{
    int i;
    int w;
    int h;
    bool textureLoaded;
    ILuint imgID;
    ILboolean success;
    GLenum error;

    LogWrite("Creating sprite", 0, MT_INFO, Sprite[Sprites.spritesCount].name);
    Sprite[Sprites.spritesCount].name = malloc(sizeof(char) * (strlen(filename) + 1));
    if (Sprite[Sprites.spritesCount].name == NULL)
        ErrorGive("Unable to allocate memory for sprite name", 1);
    Sprite[Sprites.spritesCount].name = strcpy(Sprite[Sprites.spritesCount].name, (const char *)filename);
    Sprites.spritesCount += 1; /* Увеличиваем кол-во спрайтов на 1 */
    /* Загружаем файл */
    Sprite[Sprites.spritesCount - 1].texture = 0;/* обнуляем поверхность спрайта */

    textureLoaded = false;
    imgID = 0;
    ilGenImages(1, &imgID);
    ilBindImage(imgID);
    success = ilLoadImage(filename);
    if (success == IL_TRUE)
    {
        success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
        if (success == IL_TRUE)
        {
            Sprite[Sprites.spritesCount - 1].width = (GLuint)ilGetInteger(IL_IMAGE_WIDTH);
            Sprite[Sprites.spritesCount - 1].height = (GLuint)ilGetInteger(IL_IMAGE_HEIGHT);
            glGenTextures(1, &(Sprite[Sprites.spritesCount - 1].texture));
            glBindTexture(GL_TEXTURE_2D, Sprite[Sprites.spritesCount - 1].texture);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Sprite[Sprites.spritesCount - 1].width, Sprite[Sprites.spritesCount - 1].height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLuint *)ilGetData());
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glBindTexture(GL_TEXTURE_2D, NULL);

            error = glGetError();
        }
        ilDeleteImages(1, &imgID);
    }
    if (error != GL_NO_ERROR)
        ErrorGive("Unable to load texture", 1);

    /* устанавливаем число кадров для спрайта */
    Sprite[Sprites.spritesCount - 1].clip = malloc(sizeof(Rect) * clips);
    if (Sprite[Sprites.spritesCount - 1].clip == NULL)
        ErrorGive("Unable to allocate memory for sprite clips", 1);
    /* разбиваем спрайтшит на кадры */
    for (i = 0; i <= clips - 1; i++)
    {
        Sprite[Sprites.spritesCount - 1].clip[i].x = i * Sprite[Sprites.spritesCount - 1].width / clips;
        Sprite[Sprites.spritesCount - 1].clip[i].y = 0;
        Sprite[Sprites.spritesCount - 1].clip[i].w = Sprite[Sprites.spritesCount - 1].width / clips;
        Sprite[Sprites.spritesCount - 1].clip[i].h = Sprite[Sprites.spritesCount - 1].height;
    }
    Sprite[Sprites.spritesCount - 1].clipsCount = clips;
    LogWrite("Sprite Created", 0, MT_INFO, NULL);
    return Sprites.spritesCount - 1;
}

int SpritesCreateText(char *text, int fontnum, int text_r, int text_g, int text_b, int wrapLength)
{
    // SDL_Color textcolor;
    // int w;
    // int h;
    // Sprite[Sprites.spritesCount].name = malloc(sizeof(char) * (strlen(text) + 1));
    // Sprite[Sprites.spritesCount].name = strcpy(Sprite[Sprites.spritesCount].name, (const char *)text);
    // LogWrite("Creating text sprite", 0, MT_INFO, Sprite[Sprites.spritesCount].name);

    // Sprites.spritesCount += 1; /* Увеличиваем кол-во спрайтов на 1 */

    // Sprites.loadedImage = NULL;

    // /* Переводим текст на поверхность спрайта */

    // textcolor.r = text_r;
    // textcolor.g = text_g;
    // textcolor.b = text_b;

    // if (wrapLength <= WRAP_NOWRAP)
        // Sprites.loadedImage = TTF_RenderUTF8_Blended(Fonts.font[fontnum], text, textcolor);
    // else
        // Sprites.loadedImage = TTF_RenderUTF8_Blended_Wrapped(Fonts.font[fontnum], text, textcolor, wrapLength);

    // if (Sprites.loadedImage != NULL)
        // LogWrite("Text surface created", 1, MT_INFO, NULL);
    // else
        // ErrorGive("Can not create text surface", 1);

    // w = Sprites.loadedImage->w;
    // h = Sprites.loadedImage->h;

    // Sprite[Sprites.spritesCount - 1].width = w;
    // Sprite[Sprites.spritesCount - 1].height = h;

    // Sprite[Sprites.spritesCount - 1].texture = NULL;/* обнуляем поверхность спрайта */
    // Sprite[Sprites.spritesCount - 1].texture = SDL_CreateTextureFromSurface(Draw.renderer, Sprites.loadedImage);

    // if (Sprite[Sprites.spritesCount-1].texture != NULL)
        // LogWrite("Text texture created", 1, MT_INFO, NULL);
    // else
        // ErrorGive("Can not create text texture", 1);

    // SDL_FreeSurface(Sprites.loadedImage); /* освобождаем временную поверхность */

    // /* устанавливаем число кадров для спрайта - для текста 1 кадр */
    // Sprite[Sprites.spritesCount - 1].clip = malloc(sizeof(SDL_Rect) * 1);
    // /* разбиваем спрайтшит на кадры */

    // Sprite[Sprites.spritesCount - 1].clip[0].x = 0;
    // Sprite[Sprites.spritesCount - 1].clip[0].y = 0;
    // Sprite[Sprites.spritesCount - 1].clip[0].w = w;
    // Sprite[Sprites.spritesCount - 1].clip[0].h = h;

    // Sprite[Sprites.spritesCount - 1].clipsCount = 1;

    // LogWrite("Text sprite created", 0, MT_INFO, NULL);

    return Sprites.spritesCount - 1;
}

void SpritesChangeText(int num, char *text, int fontnum, int text_r, int text_g, int text_b, int wrapLength)
{
    // SDL_Color textcolor;
    // int w;
    // int h;
    // textcolor.r = text_r;
    // textcolor.g = text_g;
    // textcolor.b = text_b;

    // if (wrapLength <= WRAP_NOWRAP)
    // {
        // Sprites.loadedImage = TTF_RenderUTF8_Blended(Fonts.font[fontnum], text, textcolor);
    // }
    // else
    // {
        // Sprites.loadedImage = TTF_RenderUTF8_Blended_Wrapped(Fonts.font[fontnum], text, textcolor, wrapLength);
    // }

    // w = Sprites.loadedImage->w;
    // h = Sprites.loadedImage->h;

    // Sprite[num].width = w;
    // Sprite[num].height = h;

    // SDL_DestroyTexture(Sprite[num].texture);
    // Sprite[num].texture = NULL;/* обнуляем поверхность спрайта */
    // Sprite[num].texture = SDL_CreateTextureFromSurface(Draw.renderer, Sprites.loadedImage);

    // SDL_FreeSurface(Sprites.loadedImage); /* освобождаем временную поверхность */


    // /* устанавливаем число кадров для спрайта - для текста 1 кадр */
    // /* Уже установлено */
    // /* разбиваем спрайтшит на кадры */

    // Sprite[num].clip[0].x = 0;
    // Sprite[num].clip[0].y = 0;
    // Sprite[num].clip[0].w = w;
    // Sprite[num].clip[0].h = h;

    Sprite[num].clipsCount = 1;
}

void SpritesBlitSprite(int num, int clip, int x, int y, int width, int height, int centerX, int centerY, double angle, int a, int flip)
{
    /* сдвиг спрайта */
    // SDL_Rect offset;
    // SDL_Point point;

    GLfloat texLeft;
    GLfloat texRight;
    GLfloat texTop;
    GLfloat texBottom;
    GLfloat quadWidth;
    GLfloat quadHeight;

    texLeft = (float)Sprite[num].clip[clip].x / (float)Sprite[num].width;
    texRight = (float)(Sprite[num].clip[clip].x + Sprite[num].clip[clip].w) / (float)Sprite[num].width;
    texTop = (float)Sprite[num].clip[clip].y / (float)Sprite[num].width;
    texBottom = (float)(Sprite[num].clip[clip].y + Sprite[num].clip[clip].h) / (float)Sprite[num].height;
    quadWidth = (float)Sprite[num].clip[clip].w;
    quadHeight = (float)Sprite[num].clip[clip].h;

    if (width != 0 & width != quadWidth)
        quadWidth = width;
    if (height != 0 & height != quadHeight)
        quadHeight = height;

    if (Sprite[num].texture != 0)
    {
        glLoadIdentity();
        glTranslatef(x, y, 0.0f);
        glBindTexture(GL_TEXTURE_2D, Sprite[num].texture);
        switch (flip)
        {
            case 0: /* Without flipping */
                glBegin(GL_QUADS);
                    glTexCoord2f(texLeft, texTop);      glVertex2f(0.0f, 0.0f);
                    glTexCoord2f(texRight, texTop);     glVertex2f(quadWidth, 0.0f);
                    glTexCoord2f(texRight, texBottom);  glVertex2f(quadWidth, quadHeight);
                    glTexCoord2f(texLeft, texBottom);   glVertex2f(0.0f, quadHeight);
                glEnd();
                break;
            case 1: /* Flip horizontally */
                glBegin(GL_QUADS);
                    glTexCoord2f(texLeft, texTop);      glVertex2f(quadWidth, 0.0f);
                    glTexCoord2f(texRight, texTop);     glVertex2f(0.0f, 0.0f);
                    glTexCoord2f(texRight, texBottom);  glVertex2f(0.0f, quadHeight);
                    glTexCoord2f(texLeft, texBottom);   glVertex2f(quadWidth, quadHeight);
                glEnd();
                break;
            case 2: /* Flip Vertically */
                glBegin(GL_QUADS);
                    glTexCoord2f(texLeft, texTop);      glVertex2f(0.0f, quadHeight);
                    glTexCoord2f(texRight, texTop);     glVertex2f(quadWidth, quadHeight);
                    glTexCoord2f(texRight, texBottom);  glVertex2f(quadWidth, 0.0f);
                    glTexCoord2f(texLeft, texBottom);   glVertex2f(0.0f, 0.0f);
                glEnd();
                break;
            case 3: /* Flip both axes */
                glBegin(GL_QUADS);
                    glTexCoord2f(texLeft, texTop);      glVertex2f(quadWidth, quadHeight);
                    glTexCoord2f(texRight, texTop);     glVertex2f(0.0f, quadHeight);
                    glTexCoord2f(texRight, texBottom);  glVertex2f(0.0f, 0.0f);
                    glTexCoord2f(texLeft, texBottom);   glVertex2f(quadWidth, 0.0f);
                glEnd();
                break;
            default:
                break;
        }

    }
}

void SpritesDestroySprite(int num)
{
    if (Sprite[num].texture != 0)
    {
        glDeleteTextures(1, &Sprite[num].texture);
        Sprite[num].texture = 0;
    }
    if (Sprite[num].name != NULL)
    {
        free(Sprite[num].name);
    }
    free(Sprite[num].clip);
}
