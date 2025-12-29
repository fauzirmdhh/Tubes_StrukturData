#include <iostream>
#include "TuBes.h"

using namespace std;

int main() {
    ListLevel L;
    adrLevel p;
    adrKursus q;

    int pilihan;
    string level;
    string kode, judul;
    int durasi, jumlahModul;
    string modul[MAXMODUL];
    int x;

    createListLevel(L);

    do {
        cout << "========================================" << endl;
        cout << "SISTEM MANAJEMEN KURSUS / PELATIHAN" << endl;
        cout << "========================================" << endl;
        cout << "1. Tambah Level Kursus" << endl;
        cout << "2. Tambah Kursus" << endl;
        cout << "3. Tampilkan Semua Kursus" << endl;
        cout << "4. Cari Kursus Berdasarkan Kode" << endl;
        cout << "5. Cari Kursus Berdasarkan Judul" << endl;
        cout << "6. Hitung Jumlah Kursus per Level" << endl;
        cout << "7. Kursus dengan Modul Terbanyak & Durasi Terlama" << endl;
        cout << "8. Tampilkan Kursus Terurut Berdasarkan Durasi " << endl;
        cout << "9. Update Data Kursus" << endl;
        cout << "10. Hapus Kursus" << endl;
        cout << "0. Keluar" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            cout << "Masukkan Nama Level: ";
            cin >> level;
            p = createElemenLevel(level);
            insertLevel(L, p);
            cout << endl;
            break;

        case 2:
            cout << "Masukkan Level Kursus: ";
            cin >> level;

            p = searchLevel(L, level);
            if (p != NULL) {
                cout << "Kode Kursus   : ";
                cin >> kode;
                cout << "Judul Kursus  : ";
                cin >> judul;
                cout << "Durasi (jam)  : ";
                cin >> durasi;
                cout << "Jumlah Modul (1-12) : ";
                cin >> jumlahModul;

                if (jumlahModul >= 1 && jumlahModul <= MAXMODUL) {
                    for (int i = 0; i < jumlahModul; i++) {
                        cout << "Modul ke-" << i + 1 << " : ";
                        cin >> modul[i];
                    }

                    q = createElemenKursus(kode, judul, durasi, jumlahModul, modul);
                    insertKursus(p, q);
                    cout << "Kursus berhasil ditambahkan." << endl;
                } else {
                    cout << "Jumlah modul tidak valid." << endl;
                }

            } else {
                cout << "Level tidak ditemukan." << endl;
            }
            cout << endl;
            break;

        case 3:
            displayList(L);
            cout << endl;
            break;

        case 4:
            cout << "Masukkan Kode Kursus: ";
            cin >> kode;
            q = searchKursusByKode(L, kode);
            if (q != NULL) {
                cout << "Kode   : " << q->info.kode << endl;
                cout << "Judul  : " << q->info.judul << endl;
                cout << "Durasi : " << q->info.durasi << " jam" << endl;
                cout << "Modul  : " << q->info.jumlahModul << endl;
            } else {
                cout << "Kursus tidak ditemukan." << endl;
            }
            cout << endl;
            break;

        case 5:
            cout << "Masukkan Judul Kursus: ";
            cin >> judul;
            searchKursusByJudul(L, judul);
            cout << endl;
            break;

        case 6:
            hitungKursusPerLevel(L);
            cout << endl;
            break;

        case 7:
            kursusModulTerbanyakDanDurasiTerlama(L);
            cout << endl;
            break;

        case 8:
            displayListSortedByDurasi(L);
            cout << endl;
            break;

        case 9:
            cout << "Masukkan Kode Kursus yang akan diupdate" << endl;
            cin >> kode;
            updateKursus(L, kode);
            cout << endl;
            break;

        case 10:
            cout << "Masukkan Level Kursus: ";
            cin >> level;
            p = searchLevel(L, level);
            if (p != NULL) {
                cout << "Masukkan Kode Kursus: ";
                cin >> kode;
                deleteKursus(p, kode);
            } else {
                cout << "Level tidak ditemukan." << endl;
            }

            cout << endl;
            break;

        case 0:
            cout << "Program selesai. Terima kasih." << endl;
            cout << endl;
            break;

        default:
            cout << "Menu tidak valid." << endl;
            cout << endl;
        }

    } while (pilihan != 0);

    return 0;
}
