#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    int secim;

    setlocale(LC_ALL, "Turkish");
    printf("Yapmak Ýstediðiniz Ýþlemi Seçin\n");
    printf("(1) Þifrele\n");
    printf("(2) Þifre Çöz\n");
    printf("Seçtiðiniz Deðeri Giriniz: ");
    scanf("%d", &secim);

    if (secim == 1) {
        printf("Þifreleme Ýþlemi Seçildi\n");
    } else if (secim == 2) {
        printf("Þifre Çözme Ýþlemi Seçildi\n");
    } else if (secim != 1,2){
        printf("Geçerli bir deðer seçiniz!\n");
        printf("Seçtiðiniz Deðeri Giriniz: ");
    }

    return 0;
}

