#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Queue {
    int Front, Rear, size;
    int Q[MAX];
};

Queue antrean;

int isEmpty(){
    if (antrean.Front == antrean.Rear){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if ((antrean.Rear + 1) % antrean.size == antrean.Front) {
        return 1;
    }
    else{
        return 0;
    }
}

void INSERT(int x){
    if (isFull() == 1){
        cout << "Queue Penuh" << endl;
    }
    else{
        antrean.Q[antrean.Rear] = x;
        cout << "Data: " << antrean.Q[antrean.Rear] << " Masuk ke dalam Queue " << endl;
        antrean.Rear = (antrean.Rear + 1) % antrean.size;
    }
}

void DELETE(){
    if (isEmpty() == 1){
        cout << "Queue kosong" << endl;
    }
    else{
        cout << "Data yang dihapus: " << antrean.Q[antrean.Front] << endl;
        antrean.Front = (antrean.Front + 1) % antrean.size;
    }
}

void CETAKLAYAR(){
    if(isEmpty()==1){
        cout << "Queue kosong" << endl;
    } else {
        int i = antrean.Front;
        while(i != antrean.Rear){
            cout << "Queue ke " << i << " = " << antrean.Q[i] << endl;
            i = (i + 1) % antrean.size;
        }
    }
}

void RESET(){
    antrean.Front = 0;
    antrean.Rear = 0;
    cout << "Queue telah di-reset" << endl;
}

void Inisialisasi(){
    antrean.Front = 0;
    antrean.Rear = 0;
    antrean.size = MAX; 
}

int PIL;

char PILIHAN[2];

int main(){
    Inisialisasi();
    do{
        cout << "\nQUEUE" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);
        switch (PIL)
        {
        case 1:
            int x;
            cout << "Masukkan Nilai: "; cin >> x;
            INSERT(x);
            break;
        
        case 2:
            DELETE();
            break;
            
        case 3:
            CETAKLAYAR();
            break;
        
        case 4:
            RESET();
            break;
        
        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }
        cout << "Tekan tombol apa saja untuk melanjutkan";
        getch();
        system("cls");
    }
    while (PIL < 5);
    return 0;
}