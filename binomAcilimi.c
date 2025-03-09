#include <stdio.h>

// Faktöriyel hesaplayan fonksiyon
int faktoriyel(int sayi) {
    int sonuc = 1;
    for (int i = 1; i <= sayi; i++) {
        sonuc *= i;
    }
    return sonuc;
}

// Kombinasyon hesaplayan fonksiyon C(n, k) = n! / (k! * (n-k)!)
int kombinasyon(int n, int k) {
    return faktoriyel(n) / (faktoriyel(k) * faktoriyel(n - k));
}
// Binom acilimi fonksiyonu
void binom_acilimi(int a, int b, int n) {
    printf("(%d + %d)^%d açılımı:\n", a, b, n);
    for (int k = 0; k <= n; k++) {
        int katsayi = kombinasyon(n, k);
        int terim1 = 1, terim2 = 1;

        // a^(n-k) ve b^k hesaplayan dongu
        for (int i = 0; i < n - k; i++) terim1 *= a;
        for (int i = 0; i < k; i++) terim2 *= b;

        // Terimi ekrana yazdirma
        printf("%d", katsayi * terim1 * terim2);
         // x^üslü terimler
        if (n - k > 0) printf("x^%d", n - k);

         // Son terimden sonra "+" koyma
        if (k < n) printf(" + ");
    }
    printf("\n");
}

int main() {
    int a, b, n;
    
    printf("Binom acilimi icin a, b ve n değerlerini girin (a + b)^n: ");
    scanf("%d %d %d", &a, &b, &n);
    
    binom_acilimi(a, b, n);
    
}