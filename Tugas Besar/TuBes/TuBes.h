#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct elemenLevel *adrLevel;
typedef struct elemenKursus *adrKursus;
const int MAXMODUL = 100;

struct Level{
    string namaLevel;
};

struct Kursus{
    string kode;
    string judul;
    int durasi;
    int jumlahModul;
    string modul[MAXMODUL];
};

struct elemenKursus{
    Kursus info;
    adrKursus next;
    adrKursus prev;
};

struct elemenLevel{
    Level info;
    adrLevel next;
    adrLevel prev;
    adrKursus firstKursus;
};

struct ListLevel{
    adrLevel first;
    adrLevel last;
};

void createListLevel(ListLevel &L);
bool isEmptyLevel(ListLevel L);
adrLevel createElemenLevel(string namaLevel);
adrKursus createElemenKursus(string kode, string judul, int durasi, int jumlahModul, string Modul[]);
void insertLevel(ListLevel &L, adrLevel p);
void insertKursus(adrLevel p, adrKursus q);
adrLevel searchLevel(ListLevel L, string namaLevel);
adrKursus searchKursusByKode(ListLevel L, string kode);
void searchKursusByJudul(ListLevel L, string judul);
void deleteKursus(adrLevel p, string kode);
void displayList(ListLevel L);
void displayListSortedByDurasi(ListLevel L);
void updateKursus(ListLevel L, string kode);
void hitungKursusPerLevel(ListLevel L);
void kursusModulTerbanyakDanDurasiTerlama(ListLevel L);

#endif
