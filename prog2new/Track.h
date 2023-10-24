#pragma once


typedef struct {
    const char* title;
    const char* artist;
    int duration;
    int year;
    const char* genre;
}Track;

//Инициализация структуры трек
Track InitTrack(const char* title, const char* artist, int duration, int year, const char* genre);

//Ввод трека
Track InputTrack();