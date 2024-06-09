#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>

 using namespace std;

class PersegiPanjang{
private:
    double xmin,ymin;
    double xmax,ymax;
    double Luas,Luas_Total;
    double titik_tengah_x,titik_tengah_y,vertikal,horizontal;
public:

    PersegiPanjang(double titik_tengah_xconst,double titik_tengah_yconst, double vertikalconst, double horizontalconst):titik_tengah_x(titik_tengah_xconst),titik_tengah_y(titik_tengah_yconst),vertikal(vertikalconst), horizontal(horizontalconst)
    {
        ymax = titik_tengah_yconst+(vertikalconst/2);
        ymin = titik_tengah_yconst-(vertikalconst/2);
        xmax = titik_tengah_xconst-(horizontalconst/2);
        xmin = titik_tengah_xconst+(horizontalconst/2);

        Luas = vertikal*horizontal;
        cout<< "Luas Persegi Panjang adalah "<<Luas<<endl;
    };


    bool operator ==(const PersegiPanjang &other){
        if(xmax>other.xmin || other.xmax> xmin){
            return false;
        } else if (ymin>other.ymax || other.ymin>ymax){
            return false;
        } else {
            return true;
        }
    };

    PersegiPanjang operator++(int){
        return PersegiPanjang(this->titik_tengah_x,this->titik_tengah_y,sqrt(2)*this->vertikal,sqrt(2)*this->horizontal);
    };

    PersegiPanjang operator--(int){
        return PersegiPanjang(this->titik_tengah_x,this->titik_tengah_y,sqrt(0.5)*this->vertikal,sqrt(0.5)*this->horizontal);
    };

    double operator[](const int){
        cout<<"xmin: "<<this->xmin<<endl;
        cout<<"xmax: "<<this->xmax<<endl;
        cout<<"ymin: "<<this->ymin<<endl;
        cout<<"ymax: "<<this->ymax<<endl;
    };


    double operator+(const PersegiPanjang&other){
        if(*this == other){
            double p=this->Luas + other.Luas;
            double Luas_Total= p - (*this-other);
            cout<<"Luas Jumlah Kedua Persegi Panjang (setelah dikurangi luas irisan) adalah "<<Luas_Total<<endl;
        }

    };

    double operator -(const PersegiPanjang&other){
        double Pojok_Kiri_Atas_x=max(this->xmax,other.xmax);
        double Pojok_Kiri_Atas_y=min(this->ymax,other.ymax);
        double Pojok_Kanan_Bawah_x=min(this->xmin,other.xmin);
        double Pojok_Kanan_Bawah_y=max(this->ymin,other.ymin);

        double Panjang_Irisan = abs(Pojok_Kiri_Atas_x-Pojok_Kanan_Bawah_x);
        double Lebar_Irisan= abs(Pojok_Kanan_Bawah_y-Pojok_Kanan_Bawah_x);
        double Luas_Irisan= Panjang_Irisan*Lebar_Irisan;

        cout<<"Luas Irisan Kedua Persegi Panjang adalah "<< Luas_Irisan<<endl;
        return Luas_Irisan;

    };

};

int main() {
    PersegiPanjang pp1(2,2,10,10);
    PersegiPanjang pp2(3,3,5,10);
    cout<<"------------------------------------------"<<endl;

    cout<<"Menampilkan Penjumlahan kedua Luas"<<endl;
    pp1+pp2;
    cout<<"------------------------------------------"<<endl;
    cout<<"Menampilkan 2X Luas Persegi Panjang"<<endl;
    cout<<"Persegi Panjang Pertama:"<<endl;
    pp1++;
    cout<<"Persegi Panjang Kedua:"<<endl;
    pp2++;
    cout<<"------------------------------------------"<<endl;

    cout<<"Menampilkan 1/2X Luas Persegi Panjang"<<endl;
    cout<<"Persegi Panjang Pertama:"<<endl;
    pp1--;
    cout<<"Persegi Panjang Kedua:"<<endl;
    pp2--;
    cout<<"------------------------------------------"<<endl;

    cout<<"menampilkan attribute xmin,ymin,xmax,ymax"<<endl;
    cout<<"Persegi Panjang Pertama:"<<endl;
    pp1[0];
    cout<<"Persegi Panjang Kedua:"<<endl;
    pp2[0];


    return 0;
}




