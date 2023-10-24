//� ���� ���� ���� ������ ��� �� ������������ �����������, ��� � � �������������

#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "MusicLibrary.h"

// ������� �������

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");

    //������� ������ � ��������������� ����������� ����������, ������ ��������� �� ������� InitMusicLibrary() � �������� ml
    MusicLibrary* ml = InitMusicLibrary();

    printf("������������� � ���������� ���������\n");

    //��������������� �������� ������ ����������� ���������� ������ ��������� �� ���
    ml = InitPlaylist("������� �����", ml, 3, 2);

    //������ ������ ��� ���������
    Track tracks[3] = {
        {"�������", "������ ���", 400, 1986, "���"},
        {"������", "��-2", 345, 1998, "���"},
        {"���� � ������", "���� ����", 328, 2012, "���"}
    };

    //���������� ��������� �������
    ml = SetPlaylistTrack(tracks, ml, 3);
    
    //����� ������ �� ���������
    OutputPlaylistTracks(ml);
    
    //�������� ����� �� ���������
    ml = DeletePlaylistTrack(ml);
    OutputPlaylistTracks(ml);

    //���������� ������ ����� � ��������
    //ml = AddPlaylistTrack(ml);
    //OutputPlaylistTracks(ml);

    printf("�������� ������� � ���������� � ��������");

    //������ �������� ��� ���������
    Album albums[2] ={
        {"��������", "��-2", 1999, 3,{

            {"�������", "��-2", 423, 1999, "���"},
            {"��������", "��-2", 356, 1999, "���"},
            {"������", "��-2", 510, 1999, "���"}}},

        {"200 �� ���������", "�������", 2005, 3,{

            {"����������", "�������", 431, 2005, "���"},
            {"�������������", "�������", 344, 2005, "���"},
            {"����", "�������", 315, 2005, "���"}}}
    };

    //����������� ����� �������, ��� � ��� ������
    ml = SetPlaylistAlbum(albums,ml,2);
    OutputPlaylistAlbums(ml);

    ml = DeletePlaylistAlbum(ml);
    OutputPlaylistAlbums(ml);

    ml = AddPlaylistAlbum(ml);
    OutputPlaylistAlbums(ml);

    //������������ ������ ��� ���������
    ml = FreePlaylist(ml);

    //������ �������� ��� �������
    Album albums_lsp[2] = {
        {"Magic City","���",2015,9,{

            {"Bullet", "���", 130, 2015, "���"},
            {"���-�� ���", "���", 423, 2015, "���"},
            {"����", "���", 412, 2015, "���"},
            {"�������", "���", 258, 2015, "���"},
            {"�����", "���", 258, 2015, "���"},
            {"�����", "���", 258, 2015, "���"},
            {"�����", "���", 258, 2015, "���"},
            {"��", "���", 258, 2015, "���"},
            {"������", "���", 258, 2015, "���"}}},

        {"Tragic City","���",2017,10,{

            {"�����������", "���", 130, 2015, "���"},
            {"�������", "���", 423, 2015, "���"},
            {"����", "���", 412, 2015, "���"},
            {"�������� ���������", "���", 258, 2015, "���"},
            {"����� �����", "���", 258, 2015, "���"},
            {"����� �����", "���", 258, 2015, "���"},
            {"��� ���� ����", "���", 258, 2015, "���"},
            {"������", "���", 258, 2015, "���"},
            {"�������", "���", 258, 2015, "���"},
            {"������ �� ��������", "���", 258, 2015, "���"}}}
    };

    //����������� ����� �������
    ml = InitArtist(ml, "���", 2, albums_lsp);
    OutputArtist(ml);

    ml = DeleteArtistAlbum(ml);
    OutputArtist(ml);

    //������������ ������ ��� ������� � ����������� ����������
    FreeArtist(ml);
    FreeMusicLibrary(ml);
    return 0;
}