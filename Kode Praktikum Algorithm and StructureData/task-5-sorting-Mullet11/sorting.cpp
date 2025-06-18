#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <iomanip>
#include <conio.h>
#include <algorithm>

using namespace std;

string name = "Muhammad Rakha' Athallah";
string id = "2410817310002";

void timeSort(const function<void()> &sortFunc, const string &sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << fixed << setprecision(10);
    cout << sortName << " took " << duration.count() << " seconds\n";
}

void insertionSort(string &str) {
    for (int i = 1; i < (int)str.size(); i++) {
        auto key = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
}

void merge(string &str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char *tempL = new char[n1];
    char *tempR = new char[n2];

    for (int i = 0; i < n1; i++) tempL[i] = str[left + i];
    for (int j = 0; j < n2; j++) tempR[j] = str[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (tempL[i] <= tempR[j]) {
            str[k] = tempL[i++];
        } else {
            str[k] = tempR[j++];
        }
        k++;
    }
    while (i < n1) str[k++] = tempL[i++];
    while (j < n2) str[k++] = tempR[j++];

    delete[] tempL;
    delete[] tempR;
}

void mergeSort(string &str, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(str, left, mid);
        mergeSort(str, mid + 1, right);
        merge(str, left, mid, right);
    }
}

void shellSort(string &str, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            auto temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

void bubbleSort(string &str) {
    for (int i = 0; i < (int)str.size() - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < (int)str.size() - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int partition(string &str, int low, int high) {
    auto pivot = str[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (str[j] <= pivot) {
            i++;
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[high]);
    return (i + 1);
}

void quickSort(string &str, int low, int high) {
    if (low < high) {
        int p_idx = partition(str, low, high);
        quickSort(str, low, p_idx - 1);
        quickSort(str, p_idx + 1, high);
    }
}

void selectionSort(string &str) {
    for (int i = 0; i < (int)str.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < (int)str.size(); j++) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }
        swap(str[i], str[minIndex]);
    }
}

int main() {
    int ch;
    string temp;

    do {
        cout << "+====================================================+" << endl;
        cout << "|                     Sorting                        |" << endl;
        cout << "+====================================================+" << endl;
        cout << "| Pilihan Sorting Algoritma:                         |" << endl;
        cout << "| 1. Insertion Sort (Name)                           |" << endl;
        cout << "| 2. Merge Sort (Name)                               |" << endl;
        cout << "| 3. Shell Sort (Name)                               |" << endl;
        cout << "| 4. Bubble Sort (ID)                                |" << endl;
        cout << "| 5. Quick Sort (ID)                                 |" << endl;
        cout << "| 6. Selection Sort (ID)                             |" << endl;
        cout << "| 7. Exit                                            |" << endl;
        cout << "+====================================================+" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> ch;
        if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ch = -1;
        }

        switch (ch) {
        case 1:
        case 2:
        case 3:
            temp.clear();
            for (char c : name) {
                if (isalpha(c)) temp += c;
            }
            cout << "Data Sebelum Diurutkan: " << name << endl;
            if (ch == 1)
                timeSort([&]() { insertionSort(temp); }, "Insertion Sort");
            else if (ch == 2)
                timeSort([&]() { mergeSort(temp, 0, temp.size() - 1); }, "Merge Sort");
            else
                timeSort([&]() { shellSort(temp, temp.size()); }, "Shell Sort");
            cout << "Data Setelah Diurutkan: " << temp << endl;
            break;

        case 4:
            temp = id;
            cout << "Data Sebelum Diurutkan: " << temp << endl;
            timeSort([&]() { bubbleSort(temp); }, "Bubble Sort");
            cout << "Data Setelah Diurutkan: " << temp << endl;
            break;

        case 5:
            temp = id;
            cout << "Data Sebelum Diurutkan: " << temp << endl;
            timeSort([&]() { quickSort(temp, 0, temp.size() - 1); }, "Quick Sort");
            cout << "Data Setelah Diurutkan: " << temp << endl;
            break;

        case 6:
            temp = id;
            cout << "Data Sebelum Diurutkan: " << temp << endl;
            timeSort([&]() { selectionSort(temp); }, "Selection Sort");
            cout << "Data Setelah Diurutkan: " << temp << endl;
            break;

        case 7:
            cout << "Terima kasih telah menggunakan program ini." << endl;
            cout << "Program dibuat oleh MUHAMMAD RAKHA' ATHALLAH" << endl;
            break;

        default:
            cout << "Opsi tidak valid, silakan coba lagi." << endl;
        }

        if (ch != 7) {
            cout << "\nTekan tombol apa saja untuk melanjutkan!!!" << endl;
            getch();
            system("cls");
        }

    } while (ch != 7);

    return 0;
}