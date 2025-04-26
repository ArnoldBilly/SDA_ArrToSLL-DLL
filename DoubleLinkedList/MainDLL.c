#include "DLL.c"

int main() {
    addrKota head = NULL;
    int pilihan;
    char namaKota[50], namaOrang[50];

    while (pilihan != 0)
    {
        printf("\n===== MENU =====\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Orang ke Kota\n");
        printf("3. Hapus Kota\n");
        printf("4. Tampilkan Data per Kota\n");        
        printf("5. Tampilkan Semua Data\n");
        printf("0. Keluar\n");
        printf("Pilihan: "); 
        scanf("%d", &pilihan); 
        getchar();

        switch (pilihan) {
            case 1:
                printf("Nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                tambahKota(&head, namaKota);
                break;
            case 2:

                break;
            case 3:
                printf("Nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                hapusKota(&head, namaKota);
                break;
            case 4:
                printf("Nama kota yang ingin dicari: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                tampilkanPerKota(head, namaKota);
                break;
            case 5:
                tampilkanSemua(head);
                break;
            case 0:
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    
    while (head != NULL) {
        addrKota tmp = head;
        head = head->next;
        hapusSemuaOrang(tmp->daftarOrang);
        free(tmp);
    }

    return 0;
}