# Kelas untuk merepresentasikan produk
class Product:
    def __init__(self, name, category, price):
        self._name = name
        self._category = category
        self._price = price

    # Getter dan Setter untuk nama produk
    @property
    def name(self):
        return self._name
    @name.setter
    def name(self, new_name):
        self._name = new_name

    # Getter dan Setter untuk kategori produk
    @property
    def category(self):
        return self._category
    @category.setter
    def category(self, new_category):
        self._category = new_category

    # Getter dan Setter untuk harga produk
    @property
    def price(self):
        return self._price
    @price.setter
    def price(self, new_price):
        self._price = new_price

# Kelas utama PetShop untuk mengelola produk
class PetShop:
    def __init__(self):
        # Constructor untuk inisialisasi daftar produk
        self.products = []

    def add_product(self, name, category, price):
        # Menambahkan produk baru ke dalam daftar
        self.products.append(Product(name, category, price))
        print("✅ Produk berhasil ditambahkan!")

    def display_products(self):
        # Menampilkan daftar produk dalam bentuk tabel
        if not self.products:
            print("🚫 Tidak ada produk dalam daftar.")
            return
        
        print("\n=== Daftar Produk ===")
        print("+-----------------------------------+")
        print("| Nama Produk    | Kategori | Harga |")
        print("+-----------------------------------+")
        for p in self.products:
            print(f"| {p.name:<14} | {p.category:<8} | Rp {p.price:.2f} |")
        print("+-----------------------------------+")

    def update_product(self, old_name, new_name, new_category, new_price):
        # Memperbarui produk berdasarkan nama produk
        for p in self.products:
            if p.name.lower() == old_name.lower():
                p.name = new_name
                p.category = new_category
                p.price = new_price
                print("✅ Produk berhasil diperbarui!")
                return
        print("❌ Produk tidak ditemukan!")

    def delete_product(self, name):
        # Menghapus produk berdasarkan nama produk
        for i, p in enumerate(self.products):
            if p.name.lower() == name.lower():
                del self.products[i]
                print("🗑 Produk berhasil dihapus!")
                return
        print("❌ Produk tidak ditemukan!")

    def search_product(self, name):
        # Mencari produk berdasarkan nama
        for p in self.products:
            if p.name.lower() == name.lower():
                print("\n🔎 Detail Produk:")
                print(f"Nama    : {p.name}")
                print(f"Kategori: {p.category}")
                print(f"Harga   : Rp {p.price:.2f}")
                return
        print("❌ Produk tidak ditemukan!")
