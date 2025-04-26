#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLL.h"

addrKota initKota(const char* nama) {
    addrKota baru = (addrKota)malloc(sizeof(struct Kota));
    if (baru != NULL) {
        strcpy(baru->nama, nama);
        baru->daftarOrang = NULL;
        baru->next = NULL;
    }
    return baru;
}

void tambahKota(addrKota* head, const char* nama) {
    addrKota baru = initKota(nama);
    if (*head == NULL) {
        *head = baru;
    } else {
        addrKota P = *head;
        while (P->next != NULL) P = P->next;
        P->next = baru;
    }
    printf("Kota %s berhasil ditambahkan.\n", nama);
}

addrKota cariKota(addrKota head, const char* nama) {
    while (head != NULL) {
        if (strcmp(head->nama, nama) == 0) return head;
        head = head->next;
    }
    return NULL;
}

void tambahOrang(addrKota kota, const char* namaOrang) {

}

void tampilkanSemua(addrKota head) {
    while (head != NULL) {
        printf("Kota: %s\n", head->nama);
        addrOrang orang = head->daftarOrang;
        while (orang != NULL) {
            printf("  - %s\n", orang->nama);
            orang = orang->next;
        }
        head = head->next;
    }
}

void hapusSemuaOrang(addrOrang head) {

}

void hapusKota(addrKota* head, const char* nama) {
    addrKota curr = *head;
    addrKota prev = NULL;

    while (curr != NULL && strcmp(curr->nama, nama) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }

    hapusSemuaOrang(curr->daftarOrang);

    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
    printf("Kota %s dan semua datanya berhasil dihapus.\n", nama);
}

void tampilkanPerKota(addrKota head, const char* nama) {
    addrKota kota = cariKota(head, nama);
    if (kota == NULL) {
        printf("Kota %s tidak ditemukan\n", nama);
        return;
    }

    printf("Kota: %s\n", kota->nama);
    addrOrang orang = kota->daftarOrang;
    while (orang != NULL) {
        printf("  - %s\n", orang->nama);
        orang = orang->next;
    }
}