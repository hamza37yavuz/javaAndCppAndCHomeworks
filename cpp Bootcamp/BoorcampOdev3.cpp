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
    // Barinak vekt�r�m�zdeki son hayvan� bize d�nd�r�r ve vekt�rden kald�r�r.
    EvcilHayvan sahiplen()
    {
        EvcilHayvan eh = hayvanlar.back();
        hayvanlar.pop_back();
        return eh;
    }

    std::vector<EvcilHayvan> hayvanlar{};
};

/**
 * Ki�ileri olu�tururken kullan�lmas� gereken id fonksiyonu
 * @return
 */
int idOlustur()
{
    static int id = 0;
    return id++;
}

/**
 * Random say� olu�turmak i�in bu fonksiyonu kullanabilirsiniz.
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
    // structed binding nas�l yapaca��m� tam olarak bilemedim
    /*
    public:void yasArttir(int yas){
        EvcilHayvan d ;
        //auto&[yas,yas] = d;
        //yas=0;
        //k++;
   }*/
};


/*
 * PROJE �STERLER�:
 *
 * 1 - Bir Ki�i struct'� olu�turun.
 *     1.1 - Bu struct'�n i�erisinde yaln�zca ki�iye ait bir id, ve sahip
 *           oldu�u evcil hayvanlar�n kayd�n� tutabilmek i�in bir vector,
 *           ve sonraki evcil hayvan alabilme s�recini hesaplayabilmek i�in
 *           kalanYil isminde bir de�i�ken olmal�d�r.
 *     1.2 - Ki�inin sahip oldu�u t�m evcil hayvanlar�n ya�lar�n� 1
 *           artt�ran bir fonksiyon olu�turun. Bu fonksiyonun ismi hi�
 *           �nemli de�il, fakat yasArttir() olabilir. STRUCTURED BINDING
 *           KULLANMANIZ �NEML�.
 *
 * 2 - Main i�erisinde yaln�zca tek bir bar�nak objesi olu�turun. Bu obje
 *     i�erisindeki hayvanlar vekt�r� i�ine, yukar�da tan�mlanan sokak array'i
 *     i�indeki EvcilHayvan objelerini kopyalay�n.
 *
 * 3 - Bir std::array olu�turun ve bu array i�erisinde 4 adet Kisi tutuyor olsun.
 *     Daha sonra array i�erisinde Kisi objelerini teker teker olu�turun. (id
 *     leri i�in idOlustur fonksiyonunu kullan�n). Ki�ilerin kalanYil de�i�keninin
 *     ilk de�eri 2 olmal�d�r.
 *
 * 4 - Bar�naktaki t�m hayvanlar bitene kadar �al��an bir d�ng� olu�turun. Bu
 *     d�ng� i�erisinde, her cycle' da ki�iler dizisinen rastgele bir ki�i se�ip
 *     bu ki�inin sahip oldu�u evcil hayvanlar�na barinaktan, sahiplen fonksiyonu
 *     ile yeni bir hayvan ekleyin.
 *     4.1 - B�R K���N�N MAKS�MUM 4 HAYVANI OLAB�L�R.
 *     4.2 - Ki�ilerin hayvan sahiplenebilmesi i�in, kalanYil de�i�kenlerinin 0 olmas�
 *           gerekmektedir. 0 oldu�u zaman tekrar 2'ye ��kart�lmal�d�r.
 *     4.3 - D�ng�n�n sonunda Ki�ilerin yeni hayvan sahiplenebilmek i�in kalan y�llar�
 *           bir azalt�lmad�r. Ayn� zamanda hayvanlar�n�n ya�lar� da 1 artt�r�lmal�d�r.
 */

    int main() {
        srand(time(nullptr)); // bu sat�r� silmeyin.
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
