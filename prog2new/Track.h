#pragma once


typedef struct {
    const char* title;
    const char* artist;
    int duration;
    int year;
    const char* genre;
}Track;

Track InitTrack(const char* title, const char* artist, int duration, int year, const char* genre);

Track InputTrack();