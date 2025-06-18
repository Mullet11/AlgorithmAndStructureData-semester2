#include<iostream>

using namespace std;

int main(){
    char huruf;
    char kata[10];
    int angka;

    cout<< "Masukkan sebuah huruf : ";
    cin>>huruf; 
    cout<< "Masukkan sebuah kata  : ";
    cin>>kata; 
    cout<< "Masukkan angka        : ";
    cin>>angka;
    
    cout<< "Huruf yang anda masukkan adalah : "<<huruf<< endl;
    cout<< "Kata yang anda masukkan adalah  : "<<kata<< endl;
    cout<< "Angka yang anda masukkan adalah : "<<angka<< endl;

    return 0;
}