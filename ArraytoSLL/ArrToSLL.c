#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrToSLL.h"

void initKota(Kota A[], int jumlah) {
    for (int i = 0; i < jumlah; ++i) {
        A[i].kt[0] = '\0';
        A[i].p = NULL;
    }
}

int cariKota(Kota A[], int n, const char* nama) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(A[i].kt, nama) == 0) return i;
    }
    return -1;
}

void tambahKota(Kota A[], int* n, int kapasitas, const char* namaKota) {
    if (*n >= kapasitas) {
        printf("Kapasitas kota sudah penuh!\n");
        return;
    }
    if (cariKota(A, *n, namaKota) != -1) {
        printf("Kota sudah ada.\n");
        return;
    }
    strcpy(A[*n].kt, namaKota);
    A[*n].p = NULL;
    (*n)++;
}

void tambahOrang(Kota* kota, const char* namaOrang) {
    Orang* baru = (Orang*)malloc(sizeof(Orang));
    if (baru == NULL) {
        printf("Gagal mengalokasikan memori untuk orang.\n");
        return;
    }
    strcpy(baru->nm, namaOrang);
    baru->q = NULL;
    
    if (kota->p == NULL) {
        kota->p = baru;
    } else {
        Orang* temp = kota->p;
        while (temp->q != NULL) {
        temp = temp->q;
    }
    temp->q = baru;
        }
    }


void hapusSemuaOrang(Orang* head) {
    Orang* temp;
    while (head != NULL) {
        temp = head;
        head = head->q;
        free(temp);
    }
}

void hapusKota(Kota A[], int* n, const char* namaKota) {
    int idx = cariKota(A, *n, namaKota);
    if (idx == -1) {
        printf("Kota tidak ditemukan.\n");
        return;
    }
    hapusSemuaOrang(A[idx].p);
    for (int i = idx; i < *n - 1; ++i) {
        A[i] = A[i + 1];
    }
    (*n)--;
    printf("Kota %s dan datanya berhasil dihapus.\n", namaKota);
}

void tampilkanSemua(Kota A[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Kota: %s\n", A[i].kt);
        Orang* curr = A[i].p;
        while (curr) {
            printf("  - %s\n", curr->nm);
            curr = curr->q;
        }
    }
}

void tampilkanPerKota(Kota A[], int n, const char* namaKota) {
    int idx = cariKota(A, n, namaKota);
    if (idx == -1) {
        printf("Kota tidak ditemukan.\n");
        return;
    }
    printf("Kota: %s\n", A[idx].kt);
    Orang* curr = A[idx].p;
    while (curr) {
        printf("  - %s\n", curr->nm);
        curr = curr->q;
    }
}