#pragma once

#include "Track.h"

#define MAX_ALBUM_TRACKS 50

typedef struct {
    const char* title;
    const char* artist;
    int year;
    int num_tracks;
    Track tracks[MAX_ALBUM_TRACKS];
}Album;

//Инициализация альбома
Album InitAlbum(const char* title, const char* artist, int year, int num_tracks, Track tracks[MAX_ALBUM_TRACKS]);