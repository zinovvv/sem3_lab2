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

MusicLibrary* InitMusicLibrary();

MusicLibrary* InitPlaylist(const char* title, MusicLibrary* ml, int num_tracks, int num_albums);

void OutputPlaylistTracks(MusicLibrary* ml);

void OutputPlaylistAlbums(MusicLibrary* ml);

MusicLibrary* InitPlaylistTrack(Track* tracks, MusicLibrary* ml, int num_tracks);

MusicLibrary* InitPlaylistAlbum(Album* albums, MusicLibrary* ml, int num_albums);

MusicLibrary* InputPlaylistTrack(MusicLibrary* ml);

MusicLibrary* InputPlaylistAlbum(MusicLibrary* ml);

MusicLibrary* DeletePlaylistTrack(MusicLibrary* ml);

MusicLibrary* DeletePlaylistAlbum(MusicLibrary* ml);

MusicLibrary* FreePlaylist(MusicLibrary* ml);

MusicLibrary* InitArtist(MusicLibrary* ml, const char* name, int num_albums, Album* albums);

void OutputArtist(MusicLibrary* ml);

MusicLibrary* DeleteArtistAlbum(MusicLibrary* ml);

MusicLibrary* FreeArtist(MusicLibrary* ml);

void FreeMusicLibrary(MusicLibrary* ml);