#include <stdio.h>

int main() {
    while (1) {
        // Deklarasi variabel
        double jarakKm;

        // Input jarak dalam kilometer
        printf("Masukkan jarak dalam kilometer (atau masukkan 0 untuk keluar): ");
        scanf("%lf", &jarakKm);

        // Keluar dari loop jika input = 0
        if (jarakKm == 0) {
            break;
        }

        // Konversi jarak ke meter dan centimeter
        double jarakMeter = jarakKm * 1000;            // 1 kilometer = 1000 meter
        double jarakCentimeter = jarakKm * 100000;     // 1 kilometer = 100000 centimeter

        // Menampilkan hasil konversi
        printf("\nHasil Konversi:\n");
        printf("%.2f kilometer = %.2f meter\n", jarakKm, jarakMeter);
        printf("%.2f kilometer = %.2f centimeter\n", jarakKm, jarakCentimeter);

        printf("\n");
    }
    printf("Program selesai.\n");
    return 0;
}
