// by oplta
#include <stdio.h>   // 📚 Giriş ve çıkış işlemleri için gerekli kütüphane
#include <stdlib.h>  // ⚙️ Genel amaçlı yardımcı fonksiyonlar için gerekli kütüphane
#include <locale.h>  // 🇹🇷 Türkçe karakterler için gerekli kütüphane
#include <string.h>  // 📝 Metinlerle (string) ilgili işlemler için gerekli kütüphane

// Bu fonksiyon, kullanıcıdan alınan metni şifreler. 🔒
void sifreLe(char *metin, int kaydirma) {
    int i; // 🔢 Döngü için bir sayaç
    for (i = 0; metin[i] != '\0'; i++) { // 🔄 Metindeki her karakteri döngüyle kontrol et
        if (metin[i] >= 'A' && metin[i] <= 'Z') { // 🅰️ Eğer büyük harf ise
            metin[i] = ((metin[i] - 'A' + kaydirma) % 26) + 'A'; // 🔑 Harfi kaydırarak şifrele
        } else if (metin[i] >= 'a' && metin[i] <= 'z') { // 🅰️ Eğer küçük harf ise
            metin[i] = ((metin[i] - 'a' + kaydirma) % 26) + 'a'; // 🔑 Harfi kaydırarak şifrele
        }
    }
}

// Bu fonksiyon, şifrelenmiş metni çözmek için kullanılır. 🔓
void sifreCoz(char *metin, int kaydirma) {
    int i; // 🔢 Döngü için bir sayaç
    for (i = 0; metin[i] != '\0'; i++) { // 🔄 Metindeki her karakteri döngüyle kontrol et
        if (metin[i] >= 'A' && metin[i] <= 'Z') { // 🅰️ Eğer büyük harf ise
            metin[i] = ((metin[i] - 'A' - kaydirma + 26) % 26) + 'A'; // 🔑 Harfi kaydırarak çöz
        } else if (metin[i] >= 'a' && metin[i] <= 'z') { // 🅰️ Eğer küçük harf ise
            metin[i] = ((metin[i] - 'a' - kaydirma + 26) % 26) + 'a'; // 🔑 Harfi kaydırarak çöz
        }
    }
}

int main() {
    setlocale(LC_ALL, "Turkish"); // 🇹🇷 Türkçe karakterler düzgün görünsün diye gerekli ayar
    int secim;                   // 🔘 Kullanıcının seçim yapması için bir değişken
    char metin[100];             // ✍️ Kullanıcının girdiği metni tutmak için bir dizi
    int kaydirma;                // 🔢 Kullanıcının belirleyeceği kaydırma miktarını tutacak değişken

    while (1) { // 🔄 Kullanıcı geçerli bir seçim yapana kadar döngü çalışır
        printf("Yapmak istediğiniz işlemi seçin:\n"); // 📋 Menü
        printf("(1) Şifrele\n");                      // 🔒 Seçenek 1: Şifrele
        printf("(2) Şifre Çöz\n");                   // 🔓 Seçenek 2: Şifre Çöz
        printf("Seçiminizi giriniz: ");              // 👆 Kullanıcıdan seçim yapmasını ister
        scanf("%d", &secim);                         // 📥 Kullanıcının seçimi alınır
        getchar(); // ⌨️ Klavyedeki "enter" tuşunu temizler (scanf'den sonra gereklidir)

        if (secim == 1) { // ✅ Eğer kullanıcı "1" seçtiyse
            printf("Şifrelemek istediğiniz metni giriniz: "); // ✍️ Şifrelemek için metin ister
            fgets(metin, sizeof(metin), stdin);              // 📥 Kullanıcıdan metni alır
            metin[strcspn(metin, "\n")] = '\0';              // 🧹 Metindeki "\n" karakterini siler

            // Kullanıcıdan kaydırma miktarını alırız. 🔢
            printf("Kaydırma miktarını giriniz: ");
            scanf("%d", &kaydirma); // 📥 Kullanıcıdan kaydırma miktarını alır

            sifreLe(metin, kaydirma);  // 🔒 Şifreleme fonksiyonunu çağır ve kaydırma ile birlikte çalıştır
            printf("Şifrelenmiş metin: %s\n", metin); // 📃 Şifrelenmiş metni ekrana yazar
            break;                      // 🛑 Döngüyü bitirir
        } else if (secim == 2) { // ✅ Eğer kullanıcı "2" seçtiyse
            printf("Çözmek istediğiniz metni giriniz: "); // 🔓 Çözmek için metin ister
            fgets(metin, sizeof(metin), stdin);          // 📥 Kullanıcıdan metni alır
            metin[strcspn(metin, "\n")] = '\0';          // 🧹 Metindeki "\n" karakterini siler

            // Kullanıcıdan kaydırma miktarını alırız. 🔢
            printf("Kaydırma miktarını giriniz: ");
            scanf("%d", &kaydirma); // 📥 Kullanıcıdan kaydırma miktarını alır

            sifreCoz(metin, kaydirma); // 🔓 Şifre çözme fonksiyonunu çağır ve kaydırma ile birlikte çalıştır
            printf("Çözülmüş metin: %s\n", metin); // 📃 Çözülmüş metni ekrana yazar
            break;                       // 🛑 Döngüyü bitirir
        } else { // ⚠️ Eğer kullanıcı 1 veya 2 dışında bir şey girdiyse
            printf("Geçerli bir seçim yapınız!\n"); // ❌ Hata mesajı verir
        }
    }

    return 0; // ✅ Programı başarıyla sonlandırır
}
