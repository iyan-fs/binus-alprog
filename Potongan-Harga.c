#include <stdio.h>

int main() {
    int jumlahTransaksi;
    float totalBelanja, diskon, totalHarga;

    while (1) {
        printf("Masukkan total belanja (atau ketik -1 untuk keluar): Rp. ");
        scanf("%f", &totalBelanja);

        if (totalBelanja == -1) {
            // Keluar dari loop jika pengguna memasukkan -1
            break;
        }

        printf("Masukkan jumlah transaksi dalam sebulan: ");
        scanf("%d", &jumlahTransaksi);

        if (totalBelanja < 200000) {
            diskon = 0;
        } else if (totalBelanja >= 200000 && totalBelanja < 500000) {
            diskon = 0.10;
        } else if (totalBelanja >= 500000 && totalBelanja < 1000000) {
            diskon = 0.20;
        } else {
            diskon = 0.30;
        }

        // Mengecek apakah pembeli melakukan transaksi 4 kali dalam sebulan
        if (jumlahTransaksi >= 4) {
            diskon += 0.20; // Menambah diskon 20% jika transaksi >= 4
        }

        // Menghitung total harga setelah diskon
        totalHarga = totalBelanja - (totalBelanja * diskon);

        // Menampilkan hasil
        printf("Total harga setelah diskon: Rp. %.2f\n\n", totalHarga);
    }

    printf("Program selesai.\n");

    return 0;
}
