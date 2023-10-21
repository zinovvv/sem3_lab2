#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "Track.h"

Track InitTrack(const char* title, const char* artist, int duration, int year, const char* genre) {
    Track track;

    track.title = _strdup(title);
    track.artist = _strdup(artist);
    track.duration = duration;
    track.year = year;
    track.genre = _strdup(genre);

    return track;
}

Track InputTrack() {
    Track track;

    char* title, * artist, * genre;
    int duration, year;
    title = (char*)calloc(30, sizeof(char));
    artist = (char*)calloc(30, sizeof(char));
    genre = (char*)calloc(30, sizeof(char));

    printf("\n�������� �����: ");
    fgets(title, 30, stdin);
    if (strlen(title) == sizeof(title) - 1)
        while (getchar() != '\n');
    title[strlen(title) - 1] = '\0';

    printf("��� �����������: ");
    fgets(artist, 30, stdin);
    if (strlen(artist) == sizeof(artist) - 1)
        while (getchar() != '\n');
    artist[strlen(artist) - 1] = '\0';

    printf("���� �����: ");
    fgets(genre, 30, stdin);
    genre[strlen(genre) - 1] = '\0';

    printf("������������ �����: ");
    scanf("%d", &duration);
    while (getchar() != '\n');

    printf("��� ������ �����: ");
    scanf("%d", &year);
    while (getchar() != '\n');
    track = InitTrack(title, artist, duration, year, genre);

    free(title);
    free(artist);
    free(genre);

    return track;
}
