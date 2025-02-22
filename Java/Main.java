import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        PetShop shop = new PetShop(); // Membuat objek dari kelas PetShop
        Scanner scanner = new Scanner(System.in);
        int choice; // Variabel untuk menyimpan pilihan menu

        do {
            // Menampilkan menu utama kepada pengguna
            System.out.println("\n===== MENU PETSHOP =====");
            System.out.println("1. Tampilkan Produk");
            System.out.println("2. Tambah Produk");
            System.out.println("3. Perbarui Produk");
            System.out.println("4. Hapus Produk");
            System.out.println("5. Cari Produk");
            System.out.println("0. Keluar");
            System.out.print("Pilihan: ");
            
            while (!scanner.hasNextInt()) { // Validasi input harus angka
                System.out.println("Harap masukkan angka!");
                scanner.next();
            }
            choice = scanner.nextInt();
            scanner.nextLine(); // Membersihkan buffer

            switch (choice) {
                case 1:
                    shop.displayProducts();
                    break;
                case 2:
                    System.out.print("Masukkan Nama Produk: ");
                    String name = scanner.nextLine();
                    System.out.print("Masukkan Kategori Produk: ");
                    String category = scanner.nextLine();
                    System.out.print("Masukkan Harga Produk: ");
                    
                    while (!scanner.hasNextDouble()) {
                        System.out.println("Harga harus berupa angka!");
                        scanner.next();
                    }
                    double price = scanner.nextDouble();
                    
                    shop.addProduct(name, category, price);
                    System.out.println("✅ Produk berhasil ditambahkan!");
                    break;
                case 3:
                    System.out.print("Masukkan Nama Produk yang ingin diperbarui: ");
                    String oldName = scanner.nextLine();
                    System.out.print("Masukkan Nama Baru: ");
                    String newName = scanner.nextLine();
                    System.out.print("Masukkan Kategori Baru: ");
                    String newCategory = scanner.nextLine();
                    System.out.print("Masukkan Harga Baru: ");
                    
                    while (!scanner.hasNextDouble()) {
                        System.out.println("Harga harus berupa angka!");
                        scanner.next();
                    }
                    double newPrice = scanner.nextDouble();
                    
                    shop.updateProduct(oldName, newName, newCategory, newPrice);
                    break;
                case 4:
                    System.out.print("Masukkan Nama Produk yang ingin dihapus: ");
                    String deleteName = scanner.nextLine();
                    shop.deleteProduct(deleteName);
                    break;
                case 5:
                    System.out.print("Masukkan Nama Produk yang dicari: ");
                    String searchName = scanner.nextLine();
                    shop.searchProduct(searchName);
                    break;
                case 0:
                    System.out.println("👋 Keluar dari program... Sampai jumpa!");
                    break;
                default:
                    System.out.println("❌ Pilihan tidak valid! Coba lagi.");
            }
        } while (choice != 0);

        scanner.close();
    }
}
