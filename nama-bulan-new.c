#include <stdio.h>
#include <ctype.h>

int main() {
    char huruf;

    // Meminta pengguna memasukkan satu huruf
    printf("Masukkan satu huruf: ");
    scanf(" %c", &huruf); // Notice the space before %c to consume any leading whitespace

    // Mengambil hanya karakter pertama jika user memasukkan lebih dari satu karakter
    // Ini akan mengabaikan karakter tambahan dalam input
    while (getchar() != '\n'); 

    // Inisialisasi array bulan
    const char *bulan[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Mengubah huruf menjadi huruf kapital jika huruf kecil
    huruf = toupper(huruf);

    // Menyimpan indeks bulan dengan awalan huruf yang sesuai
    int matchingMonths[12];
    int count = 0;

    // Mencari bulan-bulan dengan awalan huruf yang sesuai
    for (int i = 0; i < 12; ++i) {
        if (bulan[i][0] == huruf) {
            matchingMonths[count++] = i;
        }
    }

    // Jika tidak ada bulan dengan awalan huruf tersebut
    if (count == 0) {
        printf("Tidak ada bulan dengan awalan huruf tersebut\n");
    } else {
        // Menampilkan bulan-bulan dengan awalan huruf yang sesuai
        printf("Bulan dengan awalan huruf tersebut:\n");

        // Memilih satu bulan jika lebih dari satu yang sesuai
        int choice;
        if (count > 1) {
            for (int i = 0; i < count; ++i) {
                printf("%d. %s\n", i + 1, bulan[matchingMonths[i]]);
            }
            printf("Pilih nomor bulan yang diinginkan: ");
            scanf("%d", &choice);

            if (choice < 1 || choice > count) {
                printf("Pilihan tidak valid.\n");
                return 0;
            }
        } else {
            choice = 1; // If there's only one month, automatically select it
        }

        printf("%s\n", bulan[matchingMonths[choice - 1]]);

        // Menghitung jumlah vokal dan konsonan dari nama bulan yang dipilih
        const char *selectedMonth = bulan[matchingMonths[choice - 1]];
        int vowelCount = 0;
        int consonantCount = 0;

        for (int j = 0; selectedMonth[j] != '\0'; ++j) {
            char ch = toupper(selectedMonth[j]);
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowelCount++;
            } else if ((ch >= 'A' && ch <= 'Z')) {
                consonantCount++;
            }
        }

        printf("Jumlah vokal: %d\n", vowelCount);
        printf("Jumlah konsonan: %d\n", consonantCount);
    }

    return 0;
}
