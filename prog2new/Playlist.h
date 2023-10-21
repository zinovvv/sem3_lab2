#pragma once


#define MAX_PLAYLIST_TRACKS 50
#define MAX_PLAYLIST_ALBUMS 10

typedef struct {
    char* title;
    int num_tracks;
    int num_albums;
    Track tracks[MAX_PLAYLIST_TRACKS];
    Album albums[MAX_PLAYLIST_ALBUMS];
}Playlist;

