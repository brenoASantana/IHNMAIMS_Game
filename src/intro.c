#include "raylib.h"
#include "../include/text.h"
#include "../include/intro.h"

static char *fileText1 = NULL;
static char *fileText2 = NULL;
static int charCount1 = 0;
static int charCount2 = 0;
static Music music;

void IntroInit(void)
{
    music = LoadMusicStream("../assets/musics/in_the_black_lake.mp3");
    PlayMusicStream(music);

    fileText1 = ReadTextFile("../assets/texts/intro1.txt");
    fileText2 = ReadTextFile("../assets/texts/intro2.txt");

    if (!fileText1 || !fileText2) {
        printf("Failed to read one of the intro files.\n");
        return;
    }

    charCount1 = 0;
    charCount2 = 0;
}

void IntroUpdate(void)
{
    UpdateMusicStream(music);
}

void IntroDraw(void)
{
    DrawText("F11 para Tela Cheia", 10, 10, 20, GREEN);
    DrawText("ESC para Sair", 10, 40, 20, GREEN);
    DrawFPS(10, 70);

    DrawTextWithDelay(fileText1, 10, 100, 20, GREEN, &charCount1, 1);
    if (charCount1 >= strlen(fileText1))
    {
        DrawTextWithDelay(fileText2, 10, 200, 20, GREEN, &charCount2, 1);
    }

    if (IsKeyPressed(KEY_F11)) {
        ToggleFullscreen();
    }
}

void IntroUnload(void)
{
    free(fileText1);
    free(fileText2);
    UnloadMusicStream(music);
}