#ifndef ARRTOSLL_H
#define ARRTOSLL_H
// #include "SpNRSLL.H"

typedef struct Orang {
    char nm[50];
    struct Orang* q;
} Orang;

typedef struct {
    char kt[50];
    Orang* p;
} Kota;

void initKota(Kota A[], int jumlah);
int cariKota(Kota A[], int n, const char* nama);
void tambahKota(Kota A[], int* n, int kapasitas, const char* namaKota);
void tambahOrang(Kota* kota, const char* namaOrang);
void hapusKota(Kota A[], int* n, const char* namaKota);
void tampilkanSemua(Kota A[], int n);
void tampilkanPerKota(Kota A[], int n, const char* namaKota);
void hapusSemuaOrang(Orang* head);

#endif