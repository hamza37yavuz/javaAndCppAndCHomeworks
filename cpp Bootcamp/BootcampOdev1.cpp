#include <iostream>
#include <cstdio>
using namespace std;
template<typename T>
struct Odev{
public:
    Odev(int tekrar){
        this->tekrar = tekrar;
    }
    int tekrar;
    T dizi[5] = {1,2,3,4,5}; //int deðer için
    //T dizi[5] = {1.0,2.4,3.8,4.7,5.8}; //float deðer için
    //T dizi[5] = {1.0,2.4,3.8,4.7,5.8}; //double deðer için
    void carp(T a){
        T carpim=0.0;
        for (T &b :dizi){
            carpim += b*a;
        }
        cout <<carpim<< endl;
    }
    void tekrarla(int e){
        for (int i =0;i<=e;i++){
            for (T &b :dizi) {
                cout <<b<< endl;
            }
        }
    }
};
int main() {
    int a = 4;
    Odev<int> odev {a};//int deðer için
    odev.carp(2);

    //Odev<float> odev {a};//float deðer için
    //odev.carp(2,5);

    //Odev<double> odev {a};//double deðer için
    //odev.carp(2,4999);
    
    odev.tekrarla(2);
    return 0;
}
