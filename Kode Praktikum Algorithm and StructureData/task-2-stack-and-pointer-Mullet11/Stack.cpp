#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Stack {
    int atas;
    int data[MAX];  
};

Stack Tumpuk;

int kosong(){
    if (Tumpuk.atas == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int penuh(){
    if (Tumpuk.atas == MAX-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void input(int data){
    if (kosong()==1){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
            << " Masuk ke Stack " << endl;
    }
    else if (penuh()==0){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
            << " Masuk ke Stack " << endl;        
    }
    else {
        cout << "Tumpukan Penuh" << endl;
    }
}

void hapus(){
    if (kosong()==0){
        cout << "Data Teratas Sudah Terambil" << endl;
        Tumpuk.atas--;
    }
    else {
        cout << "Data Kosong" << endl;
    }
}

void tampil(){
    if (kosong()==0){
        for(int i = Tumpuk.atas; i >= 0; i--){
            cout << "\nTumpukan Ke " << i << " = " << Tumpuk.data[i];
        }
        cout << endl;
    }
    else {
        cout << "Tumpukan Kosong" << endl;
    }
}

void bersih(){
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !" << endl;
}

int ch;

char choice[2];

void init(){
    Tumpuk.atas = -1;
}

int main(){
    init();
    do{
        cout << "\nSTACK" << endl;
        cout << "==============" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. CETAK STACK" << endl;
        cout << "4. BERSIHKAN STACK" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> choice;
        ch = atoi(choice);
        switch (ch)
        {
        case 1:
            int data;
            cout << "Masukkan Nilai: "; cin >> data;
            input(data);
            break;
        
        case 2:
            hapus();
            break;
            
        case 3:
            tampil();
            break;

        case 4:            
            bersih();
            break;
        
        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }
        cout << "Tekan tombol apa saja untuk melanjutkan";
        getch();
        system("cls");
    }
    while (ch < 5);    
    return 0;
}