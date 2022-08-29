#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;
struct Kisi
{
    Kisi() {}
    Kisi(int yas, int boy, std::string isim)
            : yas{yas}, boy{boy}, isim{std::move(isim)}
    {}
    int yas;
    int boy;
    std::string isim;
};
int main()
{
    //SORU 1

    //rastgele bir struct
    Kisi kisi;
    kisi.yas=5;
    kisi.boy=120;
    kisi.isim="mehmet";

    std::vector<Kisi> k(5);
    k.assign(5,kisi);
    cout<<k.capacity()<<endl;

/* // ekranda gösterme
    for (Kisi i:k)
    {
        cout<<"-----"<<endl;
        cout<<"Yas:"<<i.yas<<endl;
        cout<<"Boy:"<<i.boy<<endl;
        cout<<i.isim<<endl;
    }*/

    k.clear();
    cout<<"2. SORU icin temizlendi kapasitesi:"<<endl;

    //SORU 2


    //cout<<k.capacity()<<endl;

    std::array<Kisi, 5> kisiler 
    {
            Kisi{1, 33, "Ebubekir Siddik"},
            Kisi{40, 176, "Suleyman Cakir"},
            Kisi{48, 178, "Polat Alemdar"},
            Kisi{30, 180, "Willy Wonka"},
            Kisi{500, 1000, "Keloglandaki Dev"}
    };

    //2. SORU 1. COZUM

    cout<<k.capacity()<<endl;// k'nin baþlangic kapasitesi
    std::copy(kisiler.begin(), kisiler.end(),k.begin());

    /* // ekranda gösterme
    for (Kisi i: k)
     {
        cout<<"-----"<<endl;
        cout<<"Yas:"<<i.yas<<endl;
        cout<<"Boy:"<<i.boy<<endl;
        cout<<i.isim<<endl;
    }*/
    //2. SORU 2. COZUM

    std::vector<Kisi> k2(5);

    for(Kisi i:kisiler)
        k2.push_back(i);
    
   // ekrana yazdirma
    for (Kisi i: k2)
    {
        cout<<"-----"<<endl;
        cout<<"Yas:"<<i.yas<<endl;
        cout<<"Boy:"<<i.boy<<endl;
        cout<<i.isim<<endl;
    }

    //sorunun 2. kýsmý
    k2.resize(20);
    cout<<k2.capacity()<<endl;
    return 0;
}
