#include <stdio.h>

int main() {
    // Deklarasi variabel
    float angka1, angka2, angka3, hasil;
    char operasi1, operasi2;

    // Input dari user
    printf("Masukkan ekspresi perhitungan (contoh: 5 + 3 * 2): ");
    scanf("%f %c %f %c %f", &angka1, &operasi1, &angka2, &operasi2, &angka3);

    // Hitung ekspresi
    switch (operasi1) {
        case '+':
            hasil = angka1 + ((operasi2 == '+') ? angka2 + angka3 :
                              (operasi2 == '-') ? angka2 - angka3 :
                              (operasi2 == '*') ? angka2 * angka3 :
                              (operasi2 == '/') ? angka2 / angka3 : 0);
            break;
        case '-':
            hasil = angka1 - ((operasi2 == '+') ? angka2 + angka3 :
                              (operasi2 == '-') ? angka2 - angka3 :
                              (operasi2 == '*') ? angka2 * angka3 :
                              (operasi2 == '/') ? angka2 / angka3 : 0);
            break;
        case '*':
            hasil = (operasi2 == '+') ? angka1 * angka2 + angka3 :
                    (operasi2 == '-') ? angka1 * angka2 - angka3 :
                    (operasi2 == '*') ? angka1 * angka2 * angka3 :
                    (operasi2 == '/') ? angka1 * angka2 / angka3 : 0;
            break;
        case '/':
            hasil = (operasi2 == '+') ? angka1 / angka2 + angka3 :
                    (operasi2 == '-') ? angka1 / angka2 - angka3 :
                    (operasi2 == '*') ? angka1 / angka2 * angka3 :
                    (operasi2 == '/') ? angka1 / angka2 / angka3 : 0;
            break;
        default:
            printf("Operasi tidak valid.\n");
            return 1;
    }

    // Output hasil perhitungan
    printf("Hasil perhitungan: %.2f\n", hasil);

    return 0;
}
