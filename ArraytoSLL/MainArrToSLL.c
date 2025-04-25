#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrToSLL.c"

int main() {
    Kota* A;
    int jumlahKota = 0, kapasitasKota = 0, pilihan, i = 0;
    char namaKota[50], namaOrang[50];

    printf("Masukkan kapasitas maksimum kota: ");
    scanf("%d", &kapasitasKota);
    getchar();
    A = (Kota*)malloc(kapasitasKota * sizeof(Kota));
    initKota(A, kapasitasKota);

    while (i < kapasitasKota)
    {
        printf("Masukkan nama kota ke-%d: ", i+1);
        fgets(namaKota, sizeof(namaKota), stdin);
        namaKota[strcspn(namaKota, "\n")] = '\0';
        tambahKota(A, &jumlahKota, kapasitasKota, namaKota);
        i++;
    }
    
    while (pilihan !=0)
    {
        printf("\n===== MENU =====\n");
        printf("1. Tambah Orang ke Kota\n");
        printf("2. Hapus Kota\n");
        printf("3. Tampilkan Semua Data\n");
        printf("4. Tampilkan Data per Kota\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                
                break;
            case 2:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                hapusKota(A, &jumlahKota, namaKota);
                break;
            case 3:
                tampilkanSemua(A, jumlahKota);
                break;
            case 4:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                tampilkanPerKota(A, jumlahKota, namaKota);
                break;
            case 0:
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    

    for (int i = 0; i < jumlahKota; ++i) {
        hapusSemuaOrang(A[i].p);
    }
    free(A);

    return 0;
}