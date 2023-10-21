#pragma once


#define MAX_ARTIST_ALBUMS 20

typedef struct {
    char* name;
    int num_albums;
    Album albums[MAX_ARTIST_ALBUMS];
}Artist;

