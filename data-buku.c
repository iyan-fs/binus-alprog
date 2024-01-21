#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUKU 100
#define MAX_HISTORY 100

// Struktur data buku
typedef struct {
    char kode[10];
    char nama[50];
    char jenis[20];
    double harga;
} Buku;

// Struktur data transaksi history
typedef struct {
    char namaBuku[50];
    double hargaBuku;
} History;

// Fungsi untuk menampilkan menu
void printMenu() {
    printf("\nMenu:\n");
    printf("1. Input Data Buku\n");
    printf("2. View History\n");
    printf("3. View Data Buku\n");
    printf("4. Delete History\n");
    printf("5. Delete Buku\n");
    printf("6. Exit\n");
    printf("Pilihan Anda (1-6): ");
}

// Fungsi untuk membaca data buku dari file
int bacaDataBuku(Buku buku[]) {
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL) {
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%s %s %s %lf", buku[i].kode, buku[i].nama, buku[i].jenis, &buku[i].harga) != EOF) {
        i++;
    }

    fclose(file);
    return i;
}

// Fungsi untuk menyimpan data buku ke file
void simpanDataBuku(Buku buku[], int jumlahBuku) {
    FILE *file = fopen("databuku.txt", "w");
    for (int i = 0; i < jumlahBuku; i++) {
        fprintf(file, "%s %s %s %.2lf\n", buku[i].kode, buku[i].nama, buku[i].jenis, buku[i].harga);
    }
    fclose(file);
}

// Fungsi untuk menampilkan data buku
void viewDataBuku(Buku buku[], int jumlahBuku) {
    printf("\nData Buku:\n");
    printf("No\t\tNama\t\tJenis\tHarga\n");
    for (int i = 0; i < jumlahBuku; i++) {
        printf("%d\t%s\t%s\t\t%s\t%.2lf\n", i + 1, buku[i].kode, buku[i].nama, buku[i].jenis, buku[i].harga);
    }
}

// Fungsi untuk menampilkan history penjualan
void viewHistory(History history[], int jumlahHistory) {
    printf("\nHistory Penjualan:\n");
    printf("No\tNama Buku\tHarga\n");
    for (int i = 0; i < jumlahHistory; i++) {
        printf("%d\t%s\t\t%.2lf\n", i + 1, history[i].namaBuku, history[i].hargaBuku);
    }
}

// Fungsi untuk menghapus history penjualan
void deleteHistory(History history[], int *jumlahHistory) {
    if (*jumlahHistory == 0) {
        printf("\nTidak ada data penjualan.\n");
        return;
    }

    int index;
    printf("\nData History Penjualan:\n");
    viewHistory(history, *jumlahHistory);

    do {
        printf("Masukkan index data yang ingin dihapus (1-%d): ", *jumlahHistory);
        scanf("%d", &index);
    } while (index < 1 || index > *jumlahHistory);

    // Menggeser data setelah index yang dihapus
    for (int i = index - 1; i < *jumlahHistory - 1; i++) {
        history[i] = history[i + 1];
    }

    (*jumlahHistory)--;
    printf("Data Successfully deleted.\n");
}

// Fungsi untuk menghapus data buku
void deleteBuku(Buku buku[], int *jumlahBuku) {
    if (*jumlahBuku == 0) {
        printf("\nTidak ada data buku.\n");
        return;
    }

    int index;
    printf("\nData Buku:\n");
    viewDataBuku(buku, *jumlahBuku);

    do {
        printf("Masukkan index data yang ingin dihapus (1-%d): ", *jumlahBuku);
        scanf("%d", &index);
    } while (index < 1 || index > *jumlahBuku);

    // Menggeser data setelah index yang dihapus
    for (int i = index - 1; i < *jumlahBuku - 1; i++) {
        buku[i] = buku[i + 1];
    }

    (*jumlahBuku)--;
    printf("Data Successfully deleted.\n");
}

int main() {
    Buku buku[MAX_BUKU];
    History history[MAX_HISTORY];
    int jumlahBuku = 0;
    int jumlahHistory = 0;

    // Membaca data buku dari file
    jumlahBuku = bacaDataBuku(buku);

    char pilihan;
    do {
        printMenu();
        scanf(" %c", &pilihan);

        switch (pilihan) {
            case '1': // Input Data Buku
                printf("\nInput Data Buku:\n");
                printf("Nama Buku: ");
                scanf(" %[^\n]", buku[jumlahBuku].nama);
                printf("Jenis Buku: ");
                scanf(" %[^\n]", buku[jumlahBuku].jenis);
                printf("Harga Buku: ");
                scanf("%lf", &buku[jumlahBuku].harga);

                // Menambah jumlah buku
                jumlahBuku++;
                break;

            case '2': // View History
                viewHistory(history, jumlahHistory);
                break;

            case '3': // View Data Buku
                viewDataBuku(buku, jumlahBuku);
                break;

            case '4': // Delete History
                deleteHistory(history, &jumlahHistory);
                break;

            case '5': // Delete Buku
                deleteBuku(buku, &jumlahBuku);
                break;

            case '6': // Exit
                // Menyimpan data buku ke file sebelum keluar
                simpanDataBuku(buku, jumlahBuku);
                printf("Data berhasil disimpan. Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }

    } while (pilihan != '6');

    return 0;
}
