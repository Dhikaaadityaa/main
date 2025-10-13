#include <iostream>
#include <string>
#include <limits> 

using namespace std;

// --- Batasan & Data ---
// Ukuran maksimum tumpukan tugas
const int MAX = 7; 
string tugas[MAX]; 
// Indeks tumpukan teratas
int topIdx = -1;    

// --- Operasi Dasar Stack ---

bool isEmpty() { 
    return topIdx == -1; 
}

bool isFull() { 
    return topIdx == MAX - 1; 
}

// Menambah tugas ke tumpukan (PUSH)
void push(string namaTugas) {
    if (isFull()) {
        cout << "\n[❌ PUSH]: Meja tugas penuh! (Max: " << MAX << " tugas)\n";
        return;
    }
    // Naikkan indeks, lalu masukkan data
    tugas[++topIdx] = namaTugas; 
    cout << "\n[✅ PUSH]: Tugas '" << namaTugas << "' diletakkan di atas tumpukan.\n";
}

// Menyelesaikan tugas dari atas (POP)
void pop() {
    if (isEmpty()) {
        cout << "\n[❌ POP]: Tumpukan tugas kosong! Tidak ada yang bisa dikerjakan.\n";
        return;
    }
    // Selesaikan tugas paling atas, lalu turunkan indeks
    cout << "\n[📝 POP]: Menyelesaikan tugas '" << tugas[topIdx] << "' dari atas.\n";
    topIdx--; 
}

// Melihat tugas paling atas (PEEK)
void peek() {
    if (isEmpty()) {
        cout << "\n[❌ PEEK]: Tumpukan kosong.\n";
        return;
    }
    cout << "\n[👀 PEEK]: Tugas paling mendesak (atas): '" << tugas[topIdx] << "'.\n";
}

// Menampilkan seluruh tumpukan
void display() {
    if (isEmpty()) {
        cout << "\n[❌ DISPLAY]: Tumpukan tugas kosong.\n";
        return;
    }
    
    cout << "\n--- Tumpukan Tugas Mendesak (ATAS ke BAWAH) ---\n";
    for (int i = topIdx; i >= 0; i--) {
        cout << "Prioritas #" << i + 1 << ": " << tugas[i] << (i == topIdx ? " <-- SEKARANG" : "") << "\n";
    }
    cout << "------------------------------------------------\n";
}

// --- Fungsi Utama ---
int main() {
    int pilih;
    string namaTugas;
    
    do {
        cout << "\n======== SISTEM TUMPUKAN TUGAS MENDESAK (STACK) ========\n";
        cout << "1. Tugas Baru Datang (PUSH)\n2. Selesaikan Tugas (POP)\n3. Lihat Tugas Mendesak (PEEK)\n4. Tampilkan Daftar Tugas\n5. Keluar\n";
        cout << "Pilih: ";
        
        if (!(cin >> pilih)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilih = 0; 
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (pilih == 1) { 
            cout << "Nama Tugas (ex: Revisi Laporan A): "; 
            getline(cin, namaTugas); 
            push(namaTugas); 
        } else if (pilih == 2) {
            pop();
        } else if (pilih == 3) {
            peek();
        } else if (pilih == 4) {
            display();
        } else if (pilih != 5) {
            cout << "\n[⚠️ INFO]: Pilihan tidak valid!\n";
        }
    } while (pilih != 5);
    
    cout << "\nSimulasi selesai. Semangat bekerja!\n";
    return 0;
}