#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    int secim;

    setlocale(LC_ALL, "Turkish");
    printf("Yapmak �stedi�iniz ��lemi Se�in\n");
    printf("(1) �ifrele\n");
    printf("(2) �ifre ��z\n");
    printf("Se�ti�iniz De�eri Giriniz: ");
    scanf("%d", &secim);

    if (secim == 1) {
        printf("�ifreleme ��lemi Se�ildi\n");
    } else if (secim == 2) {
        printf("�ifre ��zme ��lemi Se�ildi\n");
    } else if (secim != 1,2){
        printf("Ge�erli bir de�er se�iniz!\n");
        printf("Se�ti�iniz De�eri Giriniz: ");
    }

    return 0;
}

