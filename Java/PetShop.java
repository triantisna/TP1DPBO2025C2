import java.util.ArrayList;

// Kelas utama PetShop
public class PetShop {
    private class Product {
        private String name;
        private String category;
        private double price;

        // Constructor
        public Product(String name, String category, double price) {
            this.name = name;
            this.category = category;
            this.price = price;
        }

        // Getter dan Setter
        public String getName() { return name; }
        public void setName(String name) { this.name = name; }

        public String getCategory() { return category; }
        public void setCategory(String category) { this.category = category; }

        public double getPrice() { return price; }
        public void setPrice(double price) { this.price = price; }
    }

    private ArrayList<Product> products = new ArrayList<>();

    public void addProduct(String name, String category, double price) {
        products.add(new Product(name, category, price));
    }

    public void displayProducts() {
        if (products.isEmpty()) {
            System.out.println("🚫 Tidak ada produk dalam daftar.");
            return;
        }
        System.out.println("\n=== Daftar Produk ===");
        System.out.println("+---------------------------------------------------+");
        System.out.println("| Nama Produk        | Kategori       | Harga       |");
        System.out.println("+---------------------------------------------------+");
        for (Product p : products) {
            System.out.printf("| %-18s | %-14s | Rp %.2f |\n",
                    p.getName(), p.getCategory(), p.getPrice());
        }
        System.out.println("+---------------------------------------------------+");
    }

    public void updateProduct(String oldName, String newName, String newCategory, double newPrice) {
        for (Product p : products) {
            if (p.getName().equalsIgnoreCase(oldName)) {
                p.setName(newName);
                p.setCategory(newCategory);
                p.setPrice(newPrice);
                System.out.println("✅ Produk berhasil diperbarui!");
                return;
            }
        }
        System.out.println("❌ Produk tidak ditemukan!");
    }

    public void deleteProduct(String name) {
        for (int i = 0; i < products.size(); i++) {
            if (products.get(i).getName().equalsIgnoreCase(name)) {
                products.remove(i);
                System.out.println("🗑 Produk berhasil dihapus!");
                return;
            }
        }
        System.out.println("❌ Produk tidak ditemukan!");
    }

    public void searchProduct(String name) {
        for (Product p : products) {
            if (p.getName().equalsIgnoreCase(name)) {
                System.out.println("\n🔎 Detail Produk:");
                System.out.println("Nama    : " + p.getName());
                System.out.println("Kategori: " + p.getCategory());
                System.out.println("Harga   : Rp " + p.getPrice());
                return;
            }
        }
        System.out.println("❌ Produk tidak ditemukan!");
    }
}
