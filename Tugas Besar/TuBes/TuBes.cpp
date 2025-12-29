#include "TuBes.h"
#include <iostream>

using namespace std;

void createListLevel(ListLevel &L){
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyLevel(ListLevel L){
    return (L.first == nullptr && L.last == nullptr);
}

adrLevel createElemenLevel(string namaLevel){
    adrLevel p;

    p = new elemenLevel;
    p->info.namaLevel = namaLevel;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstKursus = nullptr;

    return p;
}
adrKursus createElemenKursus(string kode, string judul, int durasi, int jumlahModul, string Modul[]){
    adrKursus q;

    q = new elemenKursus;
    q->info.kode = kode;
    q->info.judul = judul;
    q->info.durasi = durasi;
    q->info.jumlahModul = jumlahModul;

    for (int i = 0; i < jumlahModul; i++) {
        q->info.modul[i] = Modul[i];
    }

    q->next = nullptr;
    q->prev = nullptr;

    return q;
}

void insertLevel(ListLevel &L, adrLevel p) {
    if (isEmptyLevel(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void insertKursus(adrLevel p, adrKursus q) {
    if (p->firstKursus == nullptr) {
        p->firstKursus = q;
    } else {
        adrKursus r;
        r = p->firstKursus;

        while (r->next != nullptr) {
            r = r->next;
        }

        r->next = q;
        q->prev = r;
    }
}

adrLevel searchLevel(ListLevel L, string namaLevel) {
    adrLevel p;

    p = L.first;

    while (p != nullptr) {
        if (p->info.namaLevel == namaLevel) {
            return p;
        }
        p = p ->next;
    }

    return nullptr;
}

adrKursus searchKursusByKode(ListLevel L, string kode){
    adrLevel p;

    p = L.first;

    while (p != nullptr) {
        adrKursus q;
        q = p->firstKursus;

        while (q != nullptr) {
            if (q->info.kode == kode) {
                return q;
            }
            q = q->next;
        }

        p = p->next;
    }
    return nullptr;
}

void searchKursusByJudul(ListLevel L, string judul){
    adrLevel p;
    p = L.first;

    bool found = false;

    while (p != nullptr) {
        adrKursus q;
        q = p->firstKursus;

        while (q != nullptr) {
            if (q->info.judul == judul) {
                cout << "Kode    : " << q->info.kode << endl;
                cout << "Judul   : " << q->info.judul << endl;
                cout << "Level   : " << p->info.namaLevel << endl;
                cout << "Durasi  : " << q->info.durasi << " jam" << endl;
                found = true;
            }
            q = q->next;
        }
        p = p->next;
    }
    if (!found) {
        cout << "Kursus tidak ditemukan" << endl;
    }
}

void deleteKursus(adrLevel p, string kode){
     bool ditemukan = false;
    adrKursus q = NULL;

    // Cek apakah list kursus kosong
    if (p->firstKursus != NULL) {

        // Cari kursus berdasarkan kode
        q = p->firstKursus;
        while (q != NULL && q->info.kode != kode) {
            q = q->next;
        }

        // Jika kursus ditemukan
        if (q != NULL) {

            // NODE PERTAMA
            if (q == p->firstKursus) {
                p->firstKursus = q->next;
                if (q->next != NULL) {
                    q->next->prev = NULL;
                }
            }
            // NODE TERAKHIR
            else if (q->next == NULL) {
                q->prev->next = NULL;
            }
            // KASUS 3: NODE TENGAH
            else {
                q->prev->next = q->next;
                q->next->prev = q->prev;
            }


            q->next = NULL;
            q->prev = NULL;

            ditemukan = true;
        }
    }

    if (ditemukan) {
        cout << "Kursus berhasil dihapus" << endl;
    } else {
        cout << "Kursus tidak ditemukan" << endl;
    }
}

void displayList(ListLevel L){
    adrLevel p;
    p = L.first;

    while (p != nullptr) {
        cout << "Level  : " << p->info.namaLevel << endl;
        adrKursus q;
        q = p->firstKursus;

        while (q != nullptr) {
                cout << "Kode    : " << q->info.kode << endl;
                cout << "Judul   : " << q->info.judul << endl;
                cout << "Durasi  : " << q->info.durasi << " jam" << endl;
                cout << "Modul: " << endl;
                for (int i = 0; i < q->info.jumlahModul; i++) {
                    cout << " - " << q->info.modul[i] << endl;
                }
                cout << "---------------------" << endl;
                q = q->next;
        }
        p = p->next;
    }
}

void hitungKursusPerLevel(ListLevel L){
    adrLevel p;
    p = L.first;

    while (p != nullptr) {
        int count = 0;

        adrKursus q;
        q = p->firstKursus;

        while (q != nullptr) {
            count++;
            q = q->next;
        }

        cout << p->info.namaLevel << " : " << count << " kursus" << endl;
        p = p->next;
    }
}

void kursusModulTerbanyakDanDurasiTerlama(ListLevel L) {
    adrLevel p;
    adrKursus q;
    adrKursus maxModul;
    adrKursus maxDurasi;

    bool ditemukan = false;

    if (L.first == NULL) {
        cout << "Data level masih kosong." << endl;
    } else {

        p = L.first;
        while (p != NULL && p->firstKursus == NULL) {
            p = p->next;
        }

        if (p == NULL) {
            cout << "Tidak ada kursus pada semua level." << endl;
        } else {
            maxModul = p->firstKursus;
            maxDurasi = p->firstKursus;
            ditemukan = true;

            while (p != NULL) {
                q = p->firstKursus;
                while (q != NULL) {
                    if (q->info.jumlahModul > maxModul->info.jumlahModul) {
                        maxModul = q;
                    }
                    if (q->info.durasi > maxDurasi->info.durasi) {
                        maxDurasi = q;
                    }
                    q = q->next;
                }
                p = p->next;
            }

            if (ditemukan) {
                cout << "\nKursus dengan Modul Terbanyak:" << endl;
                cout << "Kode   : " << maxModul->info.kode << endl;
                cout << "Judul  : " << maxModul->info.judul << endl;
                cout << "Modul  : " << maxModul->info.jumlahModul << endl;
                cout << "Durasi : " << maxModul->info.durasi << " jam" << endl;

                cout << "\nKursus dengan Durasi Terpanjang:" << endl;
                cout << "Kode   : " << maxDurasi->info.kode << endl;
                cout << "Judul  : " << maxDurasi->info.judul << endl;
                cout << "Modul  : " << maxDurasi->info.jumlahModul << endl;
                cout << "Durasi : " << maxDurasi->info.durasi << " jam" << endl;
            }
        }
    }
}

void updateKursus(ListLevel L, string kode) {
    adrLevel p;
    p = L.first;
    bool ditemukan;
    ditemukan = false;

    while (p != NULL && !ditemukan) {
        adrKursus q;
        q = p->firstKursus;

        while (q != NULL && !ditemukan) {
            if (q->info.kode == kode) {

                cout << "\nData lama:\n";
                cout << "Judul  : " << q->info.judul << endl;
                cout << "Durasi : " << q->info.durasi << endl;
                cout << "Modul  : " << q->info.jumlahModul << endl;

                cout << "\nMasukkan data baru\n";
                cout << "Judul Kursus  : ";
                cin >> q->info.judul;

                cout << "Durasi (jam)  : ";
                cin >> q->info.durasi;

                cout << "Jumlah Modul (1-12) : ";
                cin >> q->info.jumlahModul;

                if (q->info.jumlahModul >= 1 && q->info.jumlahModul <= MAXMODUL) {
                    for (int i = 0; i < q->info.jumlahModul; i++) {
                        cout << "Modul ke-" << i + 1 << " : ";
                        cin >> q->info.modul[i];
                    }
                } else {
                    q->info.jumlahModul = 0;
                }

                cout << "Data kursus berhasil diperbarui.\n";
                ditemukan = true;
            }
            q = q->next;
        }
        p = p->next;
    }

    if (!ditemukan) {
        cout << "Kursus tidak ditemukan.\n";
    }
}

void displayListSortedByDurasi(ListLevel L) {
    adrLevel p = L.first;

    while (p != NULL) {

        bool swapped = true;       // asumsi perlu sorting
        while (swapped != false) { // jalan selama ada pertukaran
            swapped = false;       // reset di awal
            adrKursus q = p->firstKursus;

            while (q != NULL && q->next != NULL) {
                if (q->info.durasi > q->next->info.durasi) {
                    Kursus temp;

                    temp = q->info;
                    q->info = q->next->info;
                    q->next->info = temp;
                    swapped = true; // ada pertukaran
                }
                q = q->next;
            }
        }

        cout << "Level : " << p->info.namaLevel << endl;
        adrKursus r = p->firstKursus;

        while (r != NULL) {
            cout << "Kode   : " << r->info.kode << endl;
            cout << "Judul  : " << r->info.judul << endl;
            cout << "Durasi : " << r->info.durasi << " jam" << endl;
            cout << "Modul : " << r->info.jumlahModul << endl;
            cout << "  ---------------------------" << endl;
            r = r->next;
        }

        p = p->next;
    }
}
