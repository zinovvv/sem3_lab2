#pragma once

#include "Track.h"
#include "Album.h"
#include "Playlist.h"
#include "Artist.h"

#define MAX_LIBRARY_PLAYLISTS 50
#define MAX_LIBRARY_ARTISTS 50

typedef struct {
    int num_artists;
    int num_playlists;
    Artist *all_artists[MAX_LIBRARY_ARTISTS];
    Playlist* all_playlists[MAX_LIBRARY_PLAYLISTS];
}MusicLibrary;

//Инициализация музыкальной библиотеки
MusicLibrary* InitMusicLibrary();

//Инициализация плейлиста через структуру MusicLibrary
MusicLibrary* InitPlaylist(const char* title, MusicLibrary* ml, int num_tracks, int num_albums);

//Вывод треков из плейлиста
void OutputPlaylistTracks(MusicLibrary* ml);

//Вывод альбомов из плейлиста
void OutputPlaylistAlbums(MusicLibrary* ml);

//Заполнение плейлиста треками
MusicLibrary* SetPlaylistTrack(Track* tracks, MusicLibrary* ml, int num_tracks);

//Заполнение плейлиста альбомами
MusicLibrary* SetPlaylistAlbum(Album* albums, MusicLibrary* ml, int num_albums);

//Добавление трека в плейлист
MusicLibrary* AddPlaylistTrack(MusicLibrary* ml);

//Добавление альбома в плейлист
MusicLibrary* AddPlaylistAlbum(MusicLibrary* ml);

//Удаление трека из плейлиста
MusicLibrary* DeletePlaylistTrack(MusicLibrary* ml);

//Удаление альбома из плейлиста
MusicLibrary* DeletePlaylistAlbum(MusicLibrary* ml);

//Освобождение памяти для плейлиста
MusicLibrary* FreePlaylist(MusicLibrary* ml);

//Инициализация артиста
MusicLibrary* InitArtist(MusicLibrary* ml, const char* name, int num_albums, Album* albums);

//Вывод артиста
void OutputArtist(MusicLibrary* ml);

//Удаление альбома артиста
MusicLibrary* DeleteArtistAlbum(MusicLibrary* ml);

//Освобождение памяти для артиста
MusicLibrary* FreeArtist(MusicLibrary* ml);

//Освобождение памяти для музыкальной библиотеки
void FreeMusicLibrary(MusicLibrary* ml);