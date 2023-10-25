#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "MusicLibrary.h"

MusicLibrary* InitMusicLibrary() {
    MusicLibrary* library_ptr = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    if (!library_ptr) {
        fprintf(stderr, "Неудачная аллокация памяти.\n");
        exit(1);
    }

    library_ptr->num_artists = 0;
    library_ptr->num_playlists = 0;

    return library_ptr;
}

MusicLibrary* InitPlaylist(const char* title, MusicLibrary* ml, int num_tracks, int num_albums) {
    Playlist* playlist_ptr = (Playlist*)malloc(sizeof(Playlist));
    if (!playlist_ptr) {
        fprintf(stderr, "Неудачная аллокация памяти.\n");
        exit(1);
    }

    playlist_ptr->title = _strdup(title);
    playlist_ptr->num_tracks = num_tracks;
    playlist_ptr->num_albums = num_albums;
    ml->all_playlists[ml->num_playlists] = playlist_ptr;
    return ml;
}

void OutputPlaylistTracks(MusicLibrary* ml)
{
    if (!ml) {
        fprintf(stderr, "Ошибка.\n");
        exit(1);
    }
    printf("Название плейлиста: %s\n\n", ml->all_playlists[ml->num_playlists - 1]->title);
    printf("Кол-во треков в плейлисте: %d\n\n", ml->all_playlists[ml->num_playlists - 1]->num_tracks);
    puts("Треки:\n");
    for (int i = 0; i < ml->all_playlists[ml->num_playlists - 1]->num_tracks; i++)
    {
        printf("Трек №%d: %s - %s\t", i+1,ml->all_playlists[ml->num_playlists - 1]->tracks[i].title, ml->all_playlists[ml->num_playlists - 1]->tracks[i].artist);
        printf("Длительность: %d с, Год выхода: %d\t", ml->all_playlists[ml->num_playlists - 1]->tracks[i].duration, ml->all_playlists[ml->num_playlists - 1]->tracks[i].year);
        printf("Жанр: %s\n\n", ml->all_playlists[ml->num_playlists - 1]->tracks[i].genre);
    }
}

void OutputPlaylistAlbums(MusicLibrary* ml)
{
    printf("\n\nКол-во альбомов в плейлисте: %d", ml->all_playlists[ml->num_playlists - 1]->num_albums);
    for (int j = 0; j < ml->all_playlists[ml->num_playlists - 1]->num_albums; j++)
    {
        puts("\nИнформация об альбоме:\n");
        printf("Альбом №%d: %s - %s\t",j+1, ml->all_playlists[ml->num_playlists - 1]->albums[j].title, ml->all_playlists[ml->num_playlists - 1]->albums[j].artist);
        printf("Год выхода: %d\tКоличество треков: %d", ml->all_playlists[ml->num_playlists - 1]->albums[j].year, ml->all_playlists[ml->num_playlists - 1]->albums[j].num_tracks);
        printf("\n\nТреки:\n");
        for (int k = 0; k < ml->all_playlists[ml->num_playlists - 1]->albums[j].num_tracks; k++)
        {
            printf("Трек: %s - %s\t", ml->all_playlists[ml->num_playlists - 1]->albums[j].tracks[k].title, ml->all_playlists[ml->num_playlists - 1]->albums[j].tracks[k].artist);
            printf("Длительность: %d с\t", ml->all_playlists[ml->num_playlists - 1]->albums[j].tracks[k].duration);
            printf("Жанр: %s\n\n", ml->all_playlists[ml->num_playlists - 1]->albums[j].tracks[k].genre);
        }
    }
}

MusicLibrary* SetPlaylistTrack(Track* tracks, MusicLibrary* ml, int num_tracks) {
    for (int i = 0; i < num_tracks; i++)
    {
        ml->all_playlists[ml->num_playlists]->tracks[i] = tracks[i];
    }
    ml->num_playlists++;
    return ml;
}

MusicLibrary* SetPlaylistAlbum(Album* albums, MusicLibrary* ml, int num_albums) {
    for (int i = 0; i < num_albums; i++) {
        ml->all_playlists[ml->num_playlists - 1]->albums[i] = albums[i];
    }
    return ml;
}

MusicLibrary* AddPlaylistTrack(MusicLibrary* ml) {
    do
    {
        char* title, * artist, * genre;
        int duration, year;
        title = (char*)calloc(30, sizeof(char));
        artist = (char*)calloc(30, sizeof(char));
        genre = (char*)calloc(30, sizeof(char));

        printf("\nНазвание трека: ");
        fgets(title, 30, stdin);
        if (strlen(title) == sizeof(title) - 1)
            while (getchar() != '\n');
        title[strlen(title) - 1] = '\0';

        printf("Имя исполнителя: ");
        fgets(artist, 30, stdin);
        if (strlen(artist) == sizeof(artist) - 1)
            while (getchar() != '\n');
        artist[strlen(artist) - 1] = '\0';

        printf("Жанр трека: ");
        fgets(genre, 30, stdin);
        genre[strlen(genre) - 1] = '\0';

        printf("Длительность трека: ");
        scanf("%d", &duration);
        while (getchar() != '\n');

        printf("Год выхода трека: ");
        scanf("%d", &year);
        while (getchar() != '\n');

        Track track = InitTrack(title, artist, duration, year, genre);
        ml->all_playlists[ml->num_playlists - 1]->tracks[ml->all_playlists[ml->num_playlists - 1]->num_tracks] = track;
        ml->all_playlists[ml->num_playlists - 1]->num_tracks++;
        free(title);
        free(artist);
        free(genre);
        printf("Любая клавиша - создать еще\nesc - закончить");
    } while (_getch() != 27);
    return ml;
}

MusicLibrary* AddPlaylistAlbum(MusicLibrary* ml) {
    do
    {
        Track tracks[MAX_ALBUM_TRACKS];
        char* title, * artist;
        int year, num_tracks;
        title = (char*)calloc(30, sizeof(char));
        artist = (char*)calloc(30, sizeof(char));

        printf("\nНазвание альбома: ");
        fgets(title, 30, stdin);
        if (strlen(title) == sizeof(title) - 1)
            while (getchar() != '\n');
        title[strlen(title) - 1] = '\0';

        printf("Имя исполнителя: ");
        fgets(artist, 30, stdin);
        if (strlen(artist) == sizeof(artist) - 1)
            while (getchar() != '\n');
        artist[strlen(artist) - 1] = '\0';

        printf("Кол-во треков в альбоме: ");
        scanf("%d", &num_tracks);

        printf("Год выхода альбома: ");
        scanf("%d", &year);
        while (getchar() != '\n');

        for (int i = 0; i < num_tracks; i++) {
            tracks[i] = InputTrack();
        }

        Album album = InitAlbum(title, artist, year, num_tracks, tracks);
        ml->all_playlists[ml->num_playlists - 1]->albums[ml->all_playlists[ml->num_playlists - 1]->num_albums] = album;
        ml->all_playlists[ml->num_playlists - 1]->num_albums++;
        free(title);
        free(artist);
        printf("Любая клавиша - создать еще\nesc - закончить");
    } while (_getch() != 27);
    return ml;
}

MusicLibrary* DeletePlaylistTrack(MusicLibrary* ml) {
    printf("\n\nВведите номер трека который хотите удалить: ");
    int number;
    scanf("%d", &number);
    while (getchar() != '\n');
    for (int i = number - 1; i < ml->all_playlists[ml->num_playlists - 1]->num_tracks - 1; i++) {
        ml->all_playlists[ml->num_playlists - 1]->tracks[i] = ml->all_playlists[ml->num_playlists - 1]->tracks[i + 1];
    }
    ml->all_playlists[ml->num_playlists - 1]->num_tracks--;
    return ml;
}

MusicLibrary* DeletePlaylistAlbum(MusicLibrary* ml) {
    printf("\n\nВведите номер альбома который хотите удалить: ");
    int number;
    scanf("%d", &number);
    while (getchar() != '\n');
    for (int i = number - 1; i < ml->all_playlists[ml->num_playlists - 1]->num_albums - 1; i++) {
        ml->all_playlists[ml->num_playlists - 1]->albums[i] = ml->all_playlists[ml->num_playlists - 1]->albums[i + 1];
    }
    ml->all_playlists[ml->num_playlists - 1]->num_albums--;
    return ml;
}

MusicLibrary* FreePlaylist(MusicLibrary* ml) {
    free(ml->all_playlists[ml->num_playlists - 1]);
    return ml;
}

MusicLibrary* InitArtist(MusicLibrary* ml, const char* name, int num_albums, Album* albums) {
    Artist* artist_ptr = (Artist*)malloc(sizeof(Artist));
    if (!artist_ptr) {
        fputs("Ошибка", stderr);
        return NULL;
    }

    artist_ptr->name = _strdup(name);
    artist_ptr->num_albums = num_albums;
    ml->all_artists[ml->num_artists] = artist_ptr;
    for (int i = 0; i < num_albums; i++) {
        ml->all_artists[ml->num_artists]->albums[i] = albums[i];
    }
    return ml;
}

void OutputArtist(MusicLibrary* ml)
{
    puts("\n\nВЫВОД АРТИСТА\n");
    printf("\nИмя артиста: %s\n\n", ml->all_artists[ml->num_artists]->name);
    for (int j = 0; j < ml->all_artists[ml->num_artists]->num_albums; j++)
    {
        puts("Информация об альбоме");
        printf("Альбом: %s - %s\t", ml->all_artists[ml->num_artists]->albums[j].title, ml->all_artists[ml->num_artists]->albums[j].artist);
        printf("Год выхода: %d\tКол-во треков в альбоме: %d", ml->all_artists[ml->num_artists]->albums[j].year, ml->all_artists[ml->num_artists]->albums[j].num_tracks);
        printf("\nТреки:\n");
        for (int k = 0; k < ml->all_artists[ml->num_artists]->albums[j].num_tracks; k++)
        {
            puts("Информация о треке:");
            printf("Трек: %s - %s\t", ml->all_artists[ml->num_artists]->albums[j].tracks[k].title, ml->all_artists[ml->num_artists]->albums[j].tracks[k].artist);
            printf("Длительность: %d с\t", ml->all_artists[ml->num_artists]->albums[j].tracks[k].duration);
            printf("Жанр: %s\n\n", ml->all_artists[ml->num_artists]->albums[j].tracks[k].genre);
        }
    }
}

MusicLibrary* DeleteArtistAlbum(MusicLibrary* ml) {
    printf("\n\nВведите номер альбома который хотите удалить: ");
    int number;
    scanf("%d", &number);
    for (int i = number - 1; i < ml->all_artists[ml->num_artists]->num_albums - 1; i++) {
        ml->all_artists[ml->num_artists]->albums[i] = ml->all_artists[ml->num_artists]->albums[i + 1];
    }
    ml->all_artists[ml->num_artists]->num_albums--;
    return ml;
}

MusicLibrary* FreeArtist(MusicLibrary* ml) {
    free(ml->all_artists[ml->num_artists]);
    return ml;
}

void FreeMusicLibrary(MusicLibrary* ml) {
    free(ml);
}