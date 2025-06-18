    #include <iostream>
    #include <conio.h>
    #include <random>
    #include <vector>
    #include <algorithm>

    using namespace std;

    void sequentialSearch(const vector<int> &nums, int target){
        vector<int> indices;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                indices.push_back(i);
            }
        }

        cout << "\n== Hasil Sequential Search ==\n";
        if (indices.empty()) {
            cout << "Angka " << target << " tidak ditemukan dalam data.\n";
        } else {
            cout << "Angka " << target << " ditemukan sebanyak " << indices.size() << " kali.\n";
            cout << "Ditemukan pada indeks: ";
            for (int i = 0; i < indices.size(); ++i) {
                cout << indices[i];
                if (i != indices.size() - 1) cout << ", ";
            }
            cout << ".\n";
        }
    }

    void binarySearch(const vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1;
        int index = -1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                index = mid;
                break;
            }
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        cout << "\n== Hasil Binary Search ==\n";
        if (index == -1)
            cout << "Angka " << target << " tidak ditemukan dalam data.\n";
        else
            cout << "Angka " << target << " ditemukan pada indeks ke-" << index << ".\n";
    }

    void clearScreen(){
        system("cls");
    }

    void explain(){
        cout << "\n== Penjelasan Teori Searching ==\n";
        cout << "1. Sequential Search (Linear Search):\n";
        cout << "- Mengecek elemen satu per satu dari awal.\n";
        cout << "- Tidak memerlukan data terurut.\n";
        cout << "- Cocok untuk data kecil.\n";
        cout << "- Kompleksitas waktu: O(n)\n";
        cout << "- Kompleksitas ruang: O(1)\n\n";

        cout << "2. Binary Search:\n";
        cout << "- Membagi array menjadi dua bagian berdasarkan indeks tengah.\n";
        cout << "- Data harus diurutkan terlebih dahulu.\n";
        cout << "- Kompleksitas waktu: O(log n)\n";
        cout << "- Kompleksitas ruang: O(1)\n";
        cout << "- Lebih cepat untuk dataset besar.\n";
    }

    int main() {
        int opt, target;
        do {
            cout << "Pilih menu\n";
            cout << "1. Sequential Searching\n";
            cout << "2. Binary Searching\n";
            cout << "3. Jelaskan Perbedaan Sequential dan Binary Searching\n";
            cout << "4. Exit\n";
            cout << "Pilih: ";
            cin >> opt;

            switch (opt) {
                case 1: {
                    vector<int> nums(100);
                    mt19937_64 rng(random_device{}());
                    uniform_int_distribution<int> dist(1, 50);
                    for (auto &val: nums) val = dist(rng);

                    cout << "\nData (100 angka acak):\n";
                    for (int i = 0; i < nums.size(); ++i)
                        cout << nums[i] << "[" << i << "] ";
                    cout << "\n\nMasukkan angka yang ingin dicari: ";
                    cin >> target;

                    sequentialSearch(nums, target);
                    break;
                }

                case 2: {
                    int size;
                    cout << "Masukkan ukuran data: ";
                    cin >> size;
                    if (size <= 0) {
                        cout << "Ukuran data harus lebih dari 0.\n";
                        break;
                    }

                    vector<int> nums(size);
                    mt19937_64 rng(random_device{}());
                    uniform_int_distribution<int> dist(1, 100);
                    for (auto &val: nums) val = dist(rng);

                    sort(nums.begin(), nums.end());
                    cout << "\nData terurut:\n";
                    for (int i = 0; i < nums.size(); ++i)
                        cout << nums[i] << "[" << i << "] ";
                    cout << "\n\nMasukkan angka yang ingin dicari: ";
                    cin >> target;

                    binarySearch(nums, target);
                    break;
                }

                case 3:
                    explain();
                    break;

                case 4:
                    cout << "\nTERIMA KASIH\n";
                    cout << "Program dibuat oleh Muhammad Rakha Athallah (2410817310002)\n";
                    break;

                default:
                    cout << "Opsi tidak valid, silakan ulangi.\n";
                    break;
            }

            if (opt != 4) {
                cout << "\nTekan sembarang tombol untuk melanjutkan...";
                getch();
                clearScreen();
            }

        } while (opt != 4);

        return 0;
    }
