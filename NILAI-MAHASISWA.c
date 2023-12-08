#include <stdio.h>

char determineGrade(float nilai) {
    if (nilai <= 55) return 'E';
    if (nilai <= 65) return 'D';
    if (nilai <= 75) return 'C';
    if (nilai <= 85) return 'B';
    return 'A';
}

int main() {
    int jumlahMahasiswa;
    float nilaiQuis, nilaiTugas, nilaiAbsensi, nilaiPraktek, nilaiUAS, totalNilai = 0;

    printf("Masukkan jumlah mahasiswa: ");

    // Check if input is a valid number
    if (scanf("%d", &jumlahMahasiswa) != 1 || jumlahMahasiswa <= 0) {
        printf("Masukkan jumlah mahasiswa dengan benar.\n");
        return 1; // Exiting with an error code
    }

    for (int i = 1; i <= jumlahMahasiswa; i++) {
        printf("\nMahasiswa %d:\n", i);
        printf("Nilai Quis   : "); scanf("%f", &nilaiQuis);
        printf("Nilai Tugas  : "); scanf("%f", &nilaiTugas);
        printf("Nilai Absensi: "); scanf("%f", &nilaiAbsensi);
        printf("Nilai Praktek: "); scanf("%f", &nilaiPraktek);
        printf("Nilai UAS    : "); scanf("%f", &nilaiUAS);

        float nilaiRataRata = (nilaiQuis + nilaiTugas + nilaiAbsensi + nilaiPraktek + nilaiUAS) / 5;
        totalNilai += nilaiRataRata;

        char grade = determineGrade(nilaiRataRata);

        printf("Nilai Rata-rata: %.2f\nGrade: %c\n", nilaiRataRata, grade);

        if (grade == 'D' || grade == 'E') {
            printf("Tidak Lulus\n");
        }
    }

    printf("\nRata-rata Nilai Keseluruhan %d Mahasiswa: %.2f\n", jumlahMahasiswa, totalNilai / jumlahMahasiswa);

    return 0;
}
