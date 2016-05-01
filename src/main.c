#include "defines.h"
#include "scripts.h"
#include "log.h"
#include "error.h"
#include "specification.h"

#if defined(LAPP_ALLEGRO42) && !defined(PLATFORM_WIN32)
    #include "allegro42/allegro.h"
#endif

int main(int argc, char* argv[])
{
    #ifdef CC_KOS /* В KolibriOS относительные пути поддерживаются только к текущей директории, которая по умолчанию */
                  /* равна "rd/1". Надо изменить текущую директорию таким вот образом */
    signed int i;
    signed int j;
    char *path;
    i = strlen(argv[0]); /* В argv[0] храниться полный путь с именем запущенного приложения */
    while (argv[0][i] != '/') /* нужно вырезать путь */
    {
        i--;
    }
    i--;
    path = (char *)malloc(sizeof(char) * (i + 1));
    for (j = 0; j <= i; j++)
    {
        path[j] = argv[0][j];
    }
    path[j + 1] = '\0';
    /* Подфункция 1 функции 30 изменяет текущую директорию с "rd/1" на что угодно */
    /* В данном случае меняем на путь к исполняемому файлу */
    __asm__ __volatile__(
    "int $0x40"
    :
    :"a"(30),"b"(1),"c"(path)
    :"memory");
    #endif
	LogInit();

	LogWrite("Reporting build specification:", 0, MT_INFO, NULL);
	LogWrite("RnJ version:", 1, MT_INFO, RNJ_VERSION);
	LogWrite("RnJ modules:", 1, MT_INFO, NULL);
	LogWrite("App:", 2, MT_INFO, RNJ_APP);
	LogWrite("Configfile:", 2, MT_INFO, RNJ_CONFIGFILE);
	LogWrite("Screen:", 2, MT_INFO, RNJ_SCREEN);
	LogWrite("Draw:", 2, MT_INFO, RNJ_DRAW);
	LogWrite("Sprites:", 2, MT_INFO, RNJ_SPRITES);
	LogWrite("Fonts:", 2, MT_INFO, RNJ_FONTS);
	LogWrite("Scripts:", 2, MT_INFO, RNJ_SCRIPT);
	LogWrite("Dialogs:", 2, MT_INFO, RNJ_DIALOGS);
	LogWrite("Input:", 2, MT_INFO, RNJ_INPUT);
	LogWrite("Specification:", 2, MT_INFO, RNJ_SPEC);
	LogWrite("Timer:", 2, MT_INFO, RNJ_TIMER);
	LogWrite("Sounds:", 2, MT_INFO, RNJ_SOUNDS);
	LogWrite("Images:", 2, MT_INFO, RNJ_IMAGES);
	LogWrite("Physics:", 2, MT_INFO, RNJ_PHYSICS);
	LogWrite("Finish report", 0, MT_INFO, NULL);

    SpecificationInit();
    SpecificationReport();
    ScriptsInit();
    LogWrite("Executing main script", 0, MT_INFO, NULL);
    if (ScriptsDoFile(SF_MAIN) == 1)
    {
        ErrorGive("Error(s) in the script(s) or main script file not found", 1);
    }
    ScriptsQuit();
    LogWrite("Finish logging", 0, MT_NONE, NULL);
    return 0;
}
#if defined(LAPP_ALLEGRO42) && !defined(PLATFORM_WIN32)
END_OF_MAIN()
#endif
