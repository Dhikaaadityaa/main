#include <iostream>
#include <string>
using namespace std;

int main() {
    string jadwal[5][3]; // [hari][0] = nama hari, [hari][1],[hari][2] = mata kuliah
    string hari[5] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"};

    cout << "===== Input Jadwal Mata Kuliah Teknik Informatika =====" << endl;

    // Input jadwal kuliah
    for (int i = 0; i < 5; i++) {
        jadwal[i][0] = hari[i]; // simpan nama hari
        cout << "\nMasukkan 2 mata kuliah untuk hari " << hari[i] << ":" << endl;
        for (int j = 1; j <= 2; j++) {
            cout << "Mata kuliah ke-" << j << ": ";
            getline(cin, jadwal[i][j]);
        }
    }

    // Tampilkan seluruh jadwal
    cout << "\n===== Jadwal Kuliah Teknik Informatika =====" << endl;
    for (int i = 0; i < 5; i++) {
        cout << jadwal[i][0] << ": " << jadwal[i][1] << ", " << jadwal[i][2] << endl;
    }

    // Pencarian berdasarkan hari
    string cariHari;
    cout << "\nMau lihat jadwal hari apa? ";
    getline(cin, cariHari);

    bool ketemu = false;
    for (int i = 0; i < 5; i++) {
        if (jadwal[i][0] == cariHari) {
            cout << "Jadwal " << cariHari << ": " 
                 << jadwal[i][1] << ", " << jadwal[i][2] << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Hari " << cariHari << " tidak ditemukan dalam jadwal." << endl;
    }

    return 0;
}
