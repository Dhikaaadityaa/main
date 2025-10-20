#include <iostream>
#include <string>
#include <limits> // Diperlukan untuk membersihkan buffer cin

using namespace std;

// Struktur Node BST
struct Node {
    int key;    // ID Anggota (kunci BST)
    string nama; // Data yang disimpan
    Node* left;
    Node* right;

    Node(int k, string d): key(k), nama(d), left(nullptr), right(nullptr)
    {};
};

// Fungsi Insert: Menyisipkan Node baru ke BST (rekursif)
Node* insertNode(Node* root, int key, string nama) {
    if (!root) return new Node(key, nama);
    if (key < root->key) root->left = insertNode(root->left, key, nama);
    else if (key > root->key) root->right = insertNode(root->right, key, nama);
    // Duplikat ID diabaikan
    return root;
}

// Fungsi Search: Mencari Anggota berdasarkan ID (rekursif)
string searchNode(Node* root, int key) {
    if (!root) return "ID tidak terdaftar.";
    if (root->key == key) return root->nama; 
    if (key < root->key) return searchNode(root->left, key);
    return searchNode(root->right, key);
}

// Fungsi Inorder: Menampilkan seluruh anggota secara terurut berdasarkan ID (rekursif)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << "  [ID: " << root->key << "] Nama: " << root->nama << "\n";
    inorder(root->right);
}

// Fungsi findMin: Mencari ID Anggota terkecil (iteratif)
int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->key;
}

// Fungsi findMax: Mencari ID Anggota terbesar (iteratif)
int findMax(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->key;
}

int main() {
    Node* perpustakaan_root = nullptr;
    int pilih, id_input;
    string nama_input;

    cout << "=== Sistem Manajemen Anggota Perpustakaan (BST) ===\n";
    cout << "ID Anggota yang dimasukkan akan terurut otomatis.\n";

    do {
        // Tampilan Menu
        cout << "\n-----------------------------------------\n";
        cout << "1. Daftar Anggota Baru (Insert)\n";
        cout << "2. Cari Anggota berdasarkan ID (Search)\n";
        cout << "3. Tampilkan Daftar Anggota Terurut (Inorder)\n";
        cout << "4. Tampilkan ID Anggota Terkecil (Min)\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        
        // Membersihkan buffer cin setelah input angka, penting sebelum cin >> string
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pilih == 1) {
            cout << "Masukkan ID Anggota (Angka): ";
            cin >> id_input;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer lagi
            cout << "Masukkan Nama Anggota: ";
            getline(cin, nama_input); // Menggunakan getline agar nama bisa mengandung spasi
            perpustakaan_root = insertNode(perpustakaan_root, id_input, nama_input);
            cout << "✅ Anggota " << nama_input << " dengan ID " << id_input << " berhasil didaftarkan.\n";
            
        } else if (pilih == 2) {
            cout << "Masukkan ID Anggota yang dicari: ";
            cin >> id_input;
            string hasil_cari = searchNode(perpustakaan_root, id_input);
            if (hasil_cari.find("tidak terdaftar") == string::npos) {
                cout << "✅ Anggota Ditemukan: ID " << id_input << ", Nama: " << hasil_cari << "\n";
            } else {
                cout << "❌ " << hasil_cari << "\n";
            }

        } else if (pilih == 3) {
            cout << "\n[Daftar Anggota Terurut Berdasarkan ID]\n";
            inorder(perpustakaan_root);

        } else if (pilih == 4) {
            int min_id = findMin(perpustakaan_root);
            if (min_id != -1) {
                 cout << "ID Anggota Terkecil Saat Ini: " << min_id << "\n";
            } else {
                cout << "Pohon kosong. Tidak ada anggota terdaftar.\n";
            }
            
        } 
    } while (pilih != 5);

    cout << "Program selesai. Sistem ditutup.\n";
    return 0;
}