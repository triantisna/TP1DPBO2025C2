#include <iostream>
#include "petshop.cpp"

using namespace std;

int main() {
    PetShop shop;
    int choice;
    string name, category;
    double price;

    do {
        cout << "\n=== MENU PETSHOP ===\n";
        cout << "1. Tampilkan Produk\n";
        cout << "2. Tambah Produk\n";
        cout << "3. Perbarui Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Cari Produk\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                shop.displayProducts();
                break;
            case 2:
                cout << "Masukkan Nama Produk: ";
                getline(cin, name);
                cout << "Masukkan Kategori Produk: ";
                getline(cin, category);
                cout << "Masukkan Harga Produk: ";
                cin >> price;
                shop.addProduct(name, category, price);
                break;
            case 3:
                cout << "Masukkan Nama Produk yang ingin diperbarui: ";
                getline(cin, name);
                cout << "Masukkan Kategori Baru: ";
                getline(cin, category);
                cout << "Masukkan Harga Baru: ";
                cin >> price;
                shop.updateProduct(name, category, price);
                break;
            case 4:
                cout << "Masukkan Nama Produk yang ingin dihapus: ";
                getline(cin, name);
                shop.deleteProduct(name);
                break;
            case 5:
                cout << "Masukkan Nama Produk yang dicari: ";
                getline(cin, name);
                shop.searchProduct(name);
                break;
            case 0:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (choice != 0);

    return 0;
}
