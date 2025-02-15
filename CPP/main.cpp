#include <iostream>
#include "petshop.cpp"

using namespace std;

int main() {
    PetShop shop; // Membuat objek dari kelas PetShop
    int choice;   // Variabel untuk menyimpan pilihan menu
    string name, category; // Variabel untuk menyimpan nama dan kategori produk
    double price;  // Variabel untuk menyimpan harga produk

    // Loop utama untuk menampilkan menu hingga user memilih keluar
    do {
        // Menampilkan menu utama kepada pengguna
        cout << "\n=== MENU PETSHOP ===\n";
        cout << "1. Tampilkan Produk\n";
        cout << "2. Tambah Produk\n";
        cout << "3. Perbarui Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Cari Produk\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice; // Menerima input pilihan dari user
        cin.ignore(); // Menghindari masalah pada getline() setelah cin

        switch (choice) {
            case 1:
                // Menampilkan daftar produk dalam bentuk tabel
                shop.displayProducts();
                break;
            case 2:
                // Menambahkan produk baru dengan meminta input dari user
                cout << "Masukkan Nama Produk: ";
                getline(cin, name);
                cout << "Masukkan Kategori Produk: ";
                getline(cin, category);
                cout << "Masukkan Harga Produk: ";
                cin >> price;
                shop.addProduct(name, category, price); // Menambahkan produk ke dalam daftar
                break;
            case 3:
                // Memperbarui data produk berdasarkan nama produk yang diinput user
                cout << "Masukkan Nama Produk yang ingin diperbarui: ";
                getline(cin, name);
                cout << "Masukkan Kategori Baru: ";
                getline(cin, category);
                cout << "Masukkan Harga Baru: ";
                cin >> price;
                shop.updateProduct(name, category, price); // Memperbarui produk
                break;
            case 4:
                // Menghapus produk berdasarkan nama yang diinput user
                cout << "Masukkan Nama Produk yang ingin dihapus: ";
                getline(cin, name);
                shop.deleteProduct(name); // Menghapus produk dari daftar
                break;
            case 5:
                // Mencari produk berdasarkan nama
                cout << "Masukkan Nama Produk yang dicari: ";
                getline(cin, name);
                shop.searchProduct(name); // Mencari produk dalam daftar
                break;
            case 0:
                // Keluar dari program jika user memilih opsi 0
                cout << "Keluar dari program...\n";
                break;
            default:
                // Jika input pilihan tidak valid
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (choice != 0); // Loop akan terus berjalan sampai user memilih 0 (Keluar)

    return 0;
}
