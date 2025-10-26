#include <iostream>
#include <string>

using namespace std;

// --- 1. Struktur Dasar dan Konstanta ---
const int SIZE = 5; // Jumlah slot Hash Table

// Struktur untuk Node dalam Linked List (rantai)
struct Node {
    int nim;          // Key (Kunci)
    string name;      // Value (Nilai)
    Node* next;       // Pointer ke node berikutnya
};

// Deklarasi array Hash Table (Array of Pointers)
Node* table[SIZE];

// --- 2. Fungsi Inisialisasi ---
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr; // Mengosongkan semua slot
    }
}

// --- 3. Fungsi Hash ---
int hashFunction(int key) {
    return key % SIZE;
}

// --- 4. Fungsi Insert ---
void insertData(int nim, string name) {
    int index = hashFunction(nim);
    
    // 1. Cek duplikasi/Update
    Node* cur = table[index];
    while (cur != nullptr) {
        if (cur->nim == nim) {
            cur->name = name; // Update nama jika NIM sudah ada
            cout << "Data NIM " << nim << " berhasil diupdate.\n";
            return;
        }
        cur = cur->next;
    }
    
    // 2. Sisipkan Node baru di kepala Linked List
    Node* newNode = new Node;
    newNode->nim = nim;
    newNode->name = name;
    
    // Sisipkan di depan (Separate Chaining)
    newNode->next = table[index];
    table[index] = newNode;
    
    cout << "Mahasiswa " << name << " (NIM " << nim << ") disisipkan di slot " << index << ".\n";
}

// --- 5. Fungsi Search ---
string searchData(int nim) {
    int index = hashFunction(nim);
    Node* cur = table[index];
    
    while (cur != nullptr) {
        if (cur->nim == nim) {
            return cur->name; // Ditemukan
        }
        cur = cur->next;
    }
    return "TIDAK DITEMUKAN"; // Tidak ditemukan
}

// --- 6. Fungsi Display ---
void displayTable() {
    cout << "\n--- ISI HASH TABLE MAHASISWA ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Slot " << i << ": ";
        Node* temp = table[i];
        
        while (temp != nullptr) {
            cout << "[" << temp->nim << "/" << temp->name << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    cout << "------------------------------------\n";
}

// --- 7. Fungsi Main ---
int main() {
    initTable(); // Inisialisasi
    
    // Aksi: Insert dengan Tabrakan (NIM 1, 6, 11 -> Index 1)
    insertData(120, "Ani");   // Index 0
    insertData(121, "Budi");  // Index 1
    insertData(126, "Cici");  // Index 1 (Tabrakan dengan 121)
    insertData(122, "Dani");  // Index 2
    
    displayTable(); // Tampilkan Hash Table

    // Aksi: Pencarian
    cout << "Cari NIM 126: " << searchData(126) << endl;
    cout << "Cari NIM 120: " << searchData(120) << endl;
    cout << "Cari NIM 999: " << searchData(999) << endl; 
    
    // Catatan: Untuk fungsi 'remove' (penghapusan manual Node),
    // kodenya akan sedikit lebih panjang dan kompleksitasnya setara
    // dengan fungsi removeKey di Kode 1.
    
    // Tambahkan pembersihan memori (good practice)
    for (int i = 0; i < SIZE; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        table[i] = nullptr;
    }

    return 0;
}