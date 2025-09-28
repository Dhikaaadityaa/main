#include <iostream>
#include <vector>
#include <iomanip> // Untuk memformat output mata uang

using namespace std;

// Fungsi Utama: Menerima input, mengurutkan, dan menampilkan hasil
int main() {
    int n;

    // Output Permintaan Input
    cout << "===== PROGRAM PENGURUTAN BIAYA PENGELUARAN (INSERTION SORT) =====" << endl;
    cout << "Masukkan jumlah pengeluaran yang ingin diurutkan: ";
    
    // Baris 1: Membaca jumlah elemen (n)
    cin >> n;

    // Memastikan input n valid
    if (n <= 0) {
        cout << "Jumlah pengeluaran harus lebih dari nol. Program selesai." << endl;
        return 0;
    }

    // Menggunakan vector agar lebih fleksibel dibanding array statis
    vector<double> pengeluaran(n); 
    
    cout << "Masukkan nilai setiap pengeluaran (misal: 55000.50):" << endl;

    // Baris 2: Loop untuk membaca input sebanyak n kali
    for (int i = 0; i < n; i++) {
        cout << "Pengeluaran ke-" << i + 1 << ": Rp ";
        cin >> pengeluaran[i];
    }

    // --- ALGORITMA INSERTION SORT ---
    // Baris 3: Perulangan luar: Mulai dari elemen kedua (indeks i=1)
    for (int i = 1; i < n; i++) {
        double temp = pengeluaran[i]; // Nilai yang akan disisipkan
        int j = i - 1;                // Indeks terakhir dari bagian yang sudah terurut
        
        // Baris 4: Perulangan dalam (while): Geser elemen lebih besar ke kanan
        // Ini mencari posisi yang tepat untuk 'temp'
        while (j >= 0 && pengeluaran[j] > temp) {
            pengeluaran[j + 1] = pengeluaran[j]; // Geser ke kanan
            j--;
        }
        
        // Baris 5: Sisipkan 'temp' ke posisi yang benar
        pengeluaran[j + 1] = temp;
    }
    // --- AKHIR ALGORITMA ---

    // --- OUTPUT HASIL ---
    cout << "\n=======================================================" << endl;
    cout << "           DAFTAR PENGELUARAN SETELAH DIURUTKAN        " << endl;
    cout << "=======================================================" << endl;
    
    // Mengatur output agar muncul dua angka di belakang koma (seperti mata uang)
    cout << fixed << setprecision(2); 

    // Baris 6: Loop untuk menampilkan semua elemen yang sudah terurut
    for (int i = 0; i < n; i++) {
        cout << "Rp " << pengeluaran[i] << endl;
    }
    
    cout << "\nTotal " << n << " pengeluaran berhasil diurutkan dari yang terkecil." << endl;

    return 0;
}