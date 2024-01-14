#include <stdio.h>
#include <string.h>

// Fungsi untuk mengecek apakah karakter adalah vokal
int isVowel(char c) {
    c = tolower(c); // Ubah karakter menjadi huruf kecil
    return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

// Fungsi untuk menghitung jumlah vokal dan nonvokal dalam sebuah string
void countVowelAndNonvowel(char *s, int *vowelCount, int *nonvowelCount) {
    *vowelCount = 0; // Inisialisasi jumlah vokal
    *nonvowelCount = 0; // Inisialisasi jumlah nonvokal
    for (int i = 0; i < strlen(s); i++) {
        if (isVowel(s[i])) {
            (*vowelCount)++; // Tambahkan jumlah vokal
        } else if (s[i] != ' ') {
            (*nonvowelCount)++; // Tambahkan jumlah nonvokal
        }
    }
}

int main() {
    // Deklarasi variabel
    char input, choice;
    char *months[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    char *selectedMonth;
    int vowelCount, nonvowelCount, matchCount = 0;

    // Input huruf A-Z
    do {
        printf("Masukkan huruf A-Z: ");
        scanf(" %c", &input);
        input = toupper(input); // Ubah huruf menjadi kapital
    } while (input < 'A' || input > 'Z'); // Ulangi jika input tidak valid

    // Cari bulan yang memiliki huruf awalan yang sama dengan input
    printf("Bulan yang memiliki huruf awalan %c adalah:\n", input);
    for (int i = 0; i < 12; i++) {
        if (months[i][0] == input) {
            printf("%s\n", months[i]); // Tampilkan bulan yang sesuai
            matchCount++; // Tambahkan jumlah bulan yang cocok
            selectedMonth = months[i]; // Simpan nama bulan yang terakhir cocok
        }
    }

    // Jika ada lebih dari satu bulan yang cocok, pilih bulan yang diinginkan
    if (matchCount > 1) {
        do {
            printf("Pilih bulan yang diinginkan (y/n): ");
            scanf(" %c", &choice);
            choice = tolower(choice); // Ubah pilihan menjadi huruf kecil
        } while (choice != 'y' && choice != 'n'); // Ulangi jika pilihan tidak valid

        // Jika memilih ya, input nama bulan
        if (choice == 'y') {
            printf("Masukkan nama bulan: ");
            scanf(" %s", selectedMonth);
        }
    }

    // Hitung jumlah vokal dan nonvokal pada nama bulan
    countVowelAndNonvowel(selectedMonth, &vowelCount, &nonvowelCount);
    // Tampilkan jumlah vokal dan nonvokal
    printf("Jumlah vokal pada bulan %s adalah: %d\n", selectedMonth, vowelCount);
    printf("Jumlah nonvokal pada bulan %s adalah: %d\n", selectedMonth, nonvowelCount);

    return 0;
}
