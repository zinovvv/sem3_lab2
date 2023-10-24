#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Album.h"

Album InitAlbum(const char* title, const char* artist, int year, int num_tracks, Track tracks[MAX_ALBUM_TRACKS]) {
    Album album;
    album.title = _strdup(title);
    album.artist = _strdup(artist);
    album.year = year;
    album.num_tracks = num_tracks;

    for (int i = 0; i < num_tracks; ++i) {
        album.tracks[i] = tracks[i];
    }
    return album;
}

