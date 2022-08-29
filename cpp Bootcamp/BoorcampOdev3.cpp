// BU DOSYADA HATALAR VAR DUZELTILECEK
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <ctime>
// Turler
static const int KEDI   = 0;
static const int KOPEK  = 1;
static const int IGUANA = 2;
static const int KUS    = 3;

struct EvcilHayvan
{
    int yas,tur;
};

constexpr std::array<EvcilHayvan, 16> sokak {
        EvcilHayvan{10, IGUANA},
        EvcilHayvan{1,  KEDI},
        EvcilHayvan{3,  KOPEK},
        EvcilHayvan{7,  KOPEK},
        EvcilHayvan{4,  KOPEK},
        EvcilHayvan{3,  KEDI},
        EvcilHayvan{12, KEDI},
        EvcilHayvan{2,  KUS},
        EvcilHayvan{4,  KEDI},
        EvcilHayvan{15, KEDI},
        EvcilHayvan{4,  KUS},
        EvcilHayvan{3,  IGUANA},
        EvcilHayvan{7,  KOPEK},
        EvcilHayvan{4,  KEDI},
        EvcilHayvan{1,  IGUANA},
        EvcilHayvan{6,  KUS}
};

struct Barinak
{
    // Barinak vektörümüzdeki son hayvaný bize döndürür ve vektörden kaldýrýr.
    EvcilHayvan sahiplen()
    {
        EvcilHayvan eh = hayvanlar.back();
        hayvanlar.pop_back();
        return eh;
    }

    std::vector<EvcilHayvan> hayvanlar{};
};

/**
 * Kiþileri oluþtururken kullanýlmasý gereken id fonksiyonu
 * @return
 */
int idOlustur()
{
    static int id = 0;
    return id++;
}

/**
 * Random sayý oluþturmak için bu fonksiyonu kullanabilirsiniz.
 */
int random()
{
    return rand() % 4;
}

struct Kisi {
    int hayvan;
    int id;
    int kalanYil;
    std::vector<EvcilHayvan> e;
    // structed binding nasýl yapacaðýmý tam olarak bilemedim
    /*
    public:void yasArttir(int yas){
        EvcilHayvan d ;
        //auto&[yas,yas] = d;
        //yas=0;
        //k++;
   }*/
};


/*
 * PROJE ÝSTERLERÝ:
 *
 * 1 - Bir Kiþi struct'ý oluþturun.
 *     1.1 - Bu struct'ýn içerisinde yalnýzca kiþiye ait bir id, ve sahip
 *           olduðu evcil hayvanlarýn kaydýný tutabilmek için bir vector,
 *           ve sonraki evcil hayvan alabilme sürecini hesaplayabilmek için
 *           kalanYil isminde bir deðiþken olmalýdýr.
 *     1.2 - Kiþinin sahip olduðu tüm evcil hayvanlarýn yaþlarýný 1
 *           arttýran bir fonksiyon oluþturun. Bu fonksiyonun ismi hiç
 *           önemli deðil, fakat yasArttir() olabilir. STRUCTURED BINDING
 *           KULLANMANIZ ÖNEMLÝ.
 *
 * 2 - Main içerisinde yalnýzca tek bir barýnak objesi oluþturun. Bu obje
 *     içerisindeki hayvanlar vektörü içine, yukarýda tanýmlanan sokak array'i
 *     içindeki EvcilHayvan objelerini kopyalayýn.
 *
 * 3 - Bir std::array oluþturun ve bu array içerisinde 4 adet Kisi tutuyor olsun.
 *     Daha sonra array içerisinde Kisi objelerini teker teker oluþturun. (id
 *     leri için idOlustur fonksiyonunu kullanýn). Kiþilerin kalanYil deðiþkeninin
 *     ilk deðeri 2 olmalýdýr.
 *
 * 4 - Barýnaktaki tüm hayvanlar bitene kadar çalýþan bir döngü oluþturun. Bu
 *     döngü içerisinde, her cycle' da kiþiler dizisinen rastgele bir kiþi seçip
 *     bu kiþinin sahip olduðu evcil hayvanlarýna barinaktan, sahiplen fonksiyonu
 *     ile yeni bir hayvan ekleyin.
 *     4.1 - BÝR KÝÞÝNÝN MAKSÝMUM 4 HAYVANI OLABÝLÝR.
 *     4.2 - Kiþilerin hayvan sahiplenebilmesi için, kalanYil deðiþkenlerinin 0 olmasý
 *           gerekmektedir. 0 olduðu zaman tekrar 2'ye çýkartýlmalýdýr.
 *     4.3 - Döngünün sonunda Kiþilerin yeni hayvan sahiplenebilmek için kalan yýllarý
 *           bir azaltýlmadýr. Ayný zamanda hayvanlarýnýn yaþlarý da 1 arttýrýlmalýdýr.
 */

    int main() {
        srand(time(nullptr)); // bu satýrý silmeyin.
        Barinak b;
        std::copy(sokak.begin(), sokak.end(), b.hayvanlar.begin());
        std::array<Kisi, 4> kisiler;
        int x = 0;
        for (Kisi &i: kisiler) {
            i.hayvan = 0;
            i.id = idOlustur();
            i.kalanYil = 2;
        }
        while (x == 0) {
            if ((kisiler[rand()].kalanYil == 0) & (kisiler[rand()].hayvan != 4)) {
                kisiler[rand()].e.push_back(b.sahiplen());
                kisiler[rand()].kalanYil = 2;
                std::cout << "Yas:" << kisiler[rand()].kalanYil << std::endl;

            }
            for (Kisi &i: kisiler) {
                i.kalanYil -= 1;
                // i.yasArttir();
            }
            for (Kisi &i: kisiler) {
                if (i.hayvan == 4) {
                    x = 1;
                    continue;
                } else {
                    x = 0;
                    break;
                }
            }
        }


    }
