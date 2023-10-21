#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "MusicLibrary.h"

// Главная функция

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");
    MusicLibrary* ml = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    ml = InitMusicLibrary();

    printf("Инициализация и заполнение плейлиста\n");
    ml = InitPlaylist("Любимые треки", ml, 3, 2);
    Track tracks[3] = { {"Кукушка", "Виктор Цой", 400, 1986, "рок"}, {"Метель", "Би-2", 345, 1998, "рок"}, {"Лето в городе", "Иван Дорн", 328, 2012, "поп"} };
    Track* tracks_ptr = tracks;
    ml = InitPlaylistTrack(tracks_ptr, ml, 3);
    OutputPlaylistTracks(ml);
    ml = DeletePlaylistTrack(ml);
    //ml = TrackInputPlaylist(ml);
    OutputPlaylistTracks(ml);

    printf("Создание альбома и добавление в плейлист");
    Album albums[2] =
    { {"Метропол", "Би-2", 1999, 3,
    {{"Варвара", "Би-2", 423, 1999, "рок"},
    {"Метропол", "Би-2", 356, 1999, "рок"},
    {"Сердце", "Би-2", 510, 1999, "рок"}}},

    {"200 По Встречной", "Земфира", 2005, 3,
    {{"Ариведерчи", "Земфира", 431, 2005, "рок"},
    {"Бесконечность", "Земфира", 344, 2005, "рок"},
    {"Мачо", "Земфира", 315, 2005, "рок"}}}};
    Album* albums_ptr = albums;
    ml = InitPlaylistAlbum(albums_ptr,ml,2);
    OutputPlaylistAlbums(ml);
    ml = DeletePlaylistAlbum(ml);
    //ml = AlbumInputPlaylist(ml);
    OutputPlaylistAlbums(ml);
    ml = FreePlaylist(ml);

    Album albums_lsp[2] = { {"Magic City","ЛСП",2015,9,{ {"Bullet", "ЛСП", 130, 2015, "рэп"},
    {"Что-то ещё", "ЛСП", 423, 2015, "рэп"},
    {"Шест", "ЛСП", 412, 2015, "рэп"},
    {"Безумие", "ЛСП", 258, 2015, "рэп"},
    {"Синее", "ЛСП", 258, 2015, "рэп"},
    {"Фокус", "ЛСП", 258, 2015, "рэп"},
    {"Бигги", "ЛСП", 258, 2015, "рэп"},
    {"ОК", "ЛСП", 258, 2015, "рэп"},
    {"Уровни", "ЛСП", 258, 2015, "рэп"}}},
        {"Tragic City","ЛСП",2017,10,{ {"Воскресение", "ЛСП", 130, 2015, "рэп"},
    {"Монетка", "ЛСП", 423, 2015, "рэп"},
    {"Тело", "ЛСП", 412, 2015, "рэп"},
    {"Лабиринт отражений", "ЛСП", 258, 2015, "рэп"},
    {"Конец света", "ЛСП", 258, 2015, "рэп"},
    {"Белый танец", "ЛСП", 258, 2015, "рэп"},
    {"Ещё один день", "ЛСП", 258, 2015, "рэп"},
    {"Канкан", "ЛСП", 258, 2015, "рэп"},
    {"Ползать", "ЛСП", 258, 2015, "рэп"},
    {"Деньги не проблема", "ЛСП", 258, 2015, "рэп"}}} };
    Album* albums_lsp_ptr = albums_lsp;
    ml = InitArtist(ml, "ЛСП", 2, albums_lsp_ptr);
    OutputArtist(ml);
    ml = DeleteArtistAlbum(ml);
    OutputArtist(ml);
    FreeArtist(ml);
    FreeMusicLibrary(ml);
    return 0;
}