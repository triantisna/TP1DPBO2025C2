# Import kelas PetShop
from petshop import PetShop

# Import Scanner (input) untuk membaca data dari pengguna
def main():
    # Membuat objek dari kelas PetShop
    shop = PetShop()

    while True: # Loop utama
        # Menampilkan menu utama
        print("\n===== MENU PETSHOP =====")
        print("1. Tampilkan Produk")
        print("2. Tambah Produk")
        print("3. Perbarui Produk")
        print("4. Hapus Produk")
        print("5. Cari Produk")
        print("0. Keluar")
        
        # Validasi input agar hanya menerima angka
        try:
            choice = int(input("Pilihan: "))
        except ValueError:
            print("❌ Harap masukkan angka yang valid!")
            continue

        # Switch-case menggunakan if-elif-else
        if choice == 1:
            shop.display_products()
        elif choice == 2:
            name = input("Masukkan Nama Produk: ").strip()
            category = input("Masukkan Kategori Produk: ").strip()

            # Validasi input harga agar hanya menerima angka
            try:
                price = float(input("Masukkan Harga Produk: "))
                if price < 0:
                    print("❌ Harga tidak boleh negatif!")
                    continue
            except ValueError:
                print("❌ Harga harus berupa angka!")
                continue

            shop.add_product(name, category, price)
        elif choice == 3:
            old_name = input("Masukkan Nama Produk yang ingin diperbarui: ").strip()
            new_name = input("Masukkan Nama Baru: ").strip()
            new_category = input("Masukkan Kategori Baru: ").strip()

            try:
                new_price = float(input("Masukkan Harga Baru: "))
                if new_price < 0:
                    print("❌ Harga tidak boleh negatif!")
                    continue
            except ValueError:
                print("❌ Harga harus berupa angka!")
                continue

            shop.update_product(old_name, new_name, new_category, new_price)
        elif choice == 4:
            delete_name = input("Masukkan Nama Produk yang ingin dihapus: ").strip()
            shop.delete_product(delete_name)
        elif choice == 5:
            search_name = input("Masukkan Nama Produk yang dicari: ").strip()
            shop.search_product(search_name)
        elif choice == 0:
            print("👋 Keluar dari program... Sampai jumpa!")
            break
        else:
            print("❌ Pilihan tidak valid! Coba lagi.")

# Menjalankan program jika file ini dijalankan langsung
if __name__ == "__main__":
    main()
