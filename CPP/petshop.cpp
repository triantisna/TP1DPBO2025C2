#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Kelas PetShop untuk mengelola produk dalam petshop
class PetShop {
private:
    // Struktur untuk menyimpan informasi produk
    struct Product {
        int id;
        string name;
        string category;
        double price;
    };
    vector<Product> products; // Vektor untuk menyimpan daftar produk
    int nextId = 1; // ID unik untuk produk

public:
    // Setter dan getter untuk ID
    void setId(int newId) { nextId = newId; }
    int getId() const { return nextId; }

    // Menambahkan produk baru ke daftar
    void addProduct(const string& name, const string& category, double price) {
        products.push_back({nextId++, name, category, price});
    }
    
    // Setter dan getter untuk nama produk
    void setProductName(int id, const string& newName) {
        for (auto& p : products) {
            if (p.id == id) {
                p.name = newName;
                return;
            }
        }
    }
    string getProductName(int id) const {
        for (const auto& p : products) {
            if (p.id == id) {
                return p.name;
            }
        }
        return "";
    }
    
    // Setter dan getter untuk kategori produk
    void setProductCategory(int id, const string& newCategory) {
        for (auto& p : products) {
            if (p.id == id) {
                p.category = newCategory;
                return;
            }
        }
    }
    string getProductCategory(int id) const {
        for (const auto& p : products) {
            if (p.id == id) {
                return p.category;
            }
        }
        return "";
    }
    
    // Setter dan getter untuk harga produk
    void setProductPrice(int id, double newPrice) {
        for (auto& p : products) {
            if (p.id == id) {
                p.price = newPrice;
                return;
            }
        }
    }
    double getProductPrice(int id) const {
        for (const auto& p : products) {
            if (p.id == id) {
                return p.price;
            }
        }
        return 0.0;
    }
    
    // Menampilkan semua produk dalam bentuk tabel
    void displayProducts() {
        cout << "\nDaftar Peralatan PetShop:\n";
        cout << "+---------------------------------------------+\n";
        cout << "| Nama Produk        | Kategori       | Harga |\n";
        cout << "+---------------------------------------------+\n";
        for (const auto& p : products) {
            cout << "| " << setw(18) << left << p.name 
                 << "| " << setw(14) << left << p.category
                 << "| Rp " << setw(5) << right << p.price << " |\n";
        }
        cout << "+---------------------------------------------+\n";
    }
    
    // Memperbarui informasi produk berdasarkan nama produk
    void updateProduct(const string& name, const string& newCategory, double newPrice) {
        for (auto& p : products) {
            if (p.name == name) {
                p.category = newCategory;
                p.price = newPrice;
                return;
            }
        }
        cout << "Produk tidak ditemukan!\n";
    }
    
    // Menghapus produk berdasarkan nama produk
    void deleteProduct(const string& name) {
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i].name == name) {
                products.erase(products.begin() + i);
                return;
            }
        }
        cout << "Produk tidak ditemukan!\n";
    }
    
    // Mencari produk berdasarkan nama
    void searchProduct(const string& name) {
        for (const auto& p : products) {
            if (p.name == name) {
                cout << "\nDetail Produk:\n";
                cout << "Nama: " << p.name << "\nKategori: " << p.category << "\nHarga: Rp " << p.price << "\n";
                return;
            }
        }
        cout << "Produk tidak ditemukan!\n";
    }
};
