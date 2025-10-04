#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk melakukan Sequential Search pada array NIS
int cariNIS(const int nisArray[], const string statusArray[], int ukuran, int nisCari) {
    // Loop melalui setiap elemen dalam array
    for (int i = 0; i < ukuran; ++i) {
        // Bandingkan NIS saat ini dengan NIS yang dicari
        if (nisArray[i] == nisCari) {
            // Jika ditemukan, kembalikan indeks
            return i;
        }
    }
    // Jika loop selesai tanpa menemukan, kembalikan -1
    return -1;
}

int main() {
    int maxSiswa = 5;
    
    // 1. Deklarasi Array untuk Data
    int nis[maxSiswa];
    string status[maxSiswa];
    
    // 2. Input Data Awal (Diisi oleh Pengguna)
    cout << "--- Input Data Kehadiran 5 Siswa ---" << endl;
    for (int i = 0; i < maxSiswa; ++i) {
        cout << "Siswa ke-" << i + 1 << endl;
        cout << "  Masukkan NIS: ";
        cin >> nis[i];
        cout << "  Status (Hadir/Absen/Izin): ";
        cin >> status[i];
    }

    int inputNIS;

    // 3. Input Pencarian
    cout << "\n--- Pencarian Status Siswa ---" << endl;
    cout << "Masukkan NIS siswa yang ingin diperiksa: ";
    cin >> inputNIS;

    // 4. Proses Pencarian (Sequential Search)
    int indeksDitemukan = cariNIS(nis, status, maxSiswa, inputNIS);

    // 5. Output Hasil
    cout << "\nHasil Status:" << endl;
    if (indeksDitemukan != -1) {
        // Jika ditemukan
        cout << "✅ NIS " << inputNIS << " tercatat dengan status: " << status[indeksDitemukan] << endl;
    } else {
        // Jika tidak ditemukan
        cout << "❌ NIS " << inputNIS << " tidak ditemukan dalam daftar kehadiran." << endl;
    }

    return 0;
}