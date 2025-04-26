#ifndef DLL_H
#define DLL_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Orang {
    char nama[50];
    struct Orang* next;
};

struct Kota {
    char nama[50];
    struct Orang* daftarOrang;
    struct Kota* next;
};

typedef struct Kota* addrKota;
typedef struct Orang* addrOrang;

addrKota initKota(const char* nama);
void tambahKota(addrKota* head, const char* nama);
addrKota cariKota(addrKota head, const char* nama);
void tambahOrang(addrKota kota, const char* namaOrang);
void tampilkanSemua(addrKota head);
void hapusSemuaOrang(addrOrang head);
void hapusKota(addrKota* head, const char* nama);
void tampilkanPerKota(addrKota head, const char* nama);
#endif