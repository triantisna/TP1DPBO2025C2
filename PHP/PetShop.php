<?php
session_start(); // Memulai sesi untuk menyimpan data produk secara sementara

// Kelas Product untuk menyimpan informasi produk
class Product {
    private $name;
    private $category;
    private $price;
    private $photo;

    // Konstruktor untuk inisialisasi produk
    public function __construct($name, $category, $price, $photo) {
        $this->setName($name);
        $this->setCategory($category);
        $this->setPrice($price);
        $this->setPhoto($photo);
    }

    // Getter dan Setter untuk atribut produk
    public function getName() { return $this->name; }
    public function setName($name) { $this->name = $name; }

    public function getCategory() { return $this->category; }
    public function setCategory($category) { $this->category = $category; }

    public function getPrice() { return $this->price; }
    public function setPrice($price) { $this->price = $price; }

    public function getPhoto() { return $this->photo; }
    public function setPhoto($photo) { $this->photo = $photo; }
}

// Kelas PetShop untuk mengelola daftar produk
class PetShop {
    private $products;

    public function __construct() {
        if (!isset($_SESSION['products'])) {
            $_SESSION['products'] = [];
        }
        $this->products = &$_SESSION['products'];
    }

    // Fungsi untuk menambahkan produk baru
    public function addProduct($name, $category, $price, $photo) {
        $uploadDir = "upload/";

        // Pastikan folder upload tersedia
        if (!is_dir($uploadDir)) {
            mkdir($uploadDir, 0777, true);
        }

        // Simpan gambar ke folder upload
        $target = $uploadDir . basename($photo['name']);
        move_uploaded_file($photo['tmp_name'], $target);

        // Buat objek Product
        $product = new Product($name, $category, $price, $target);
        $_SESSION['products'][] = serialize($product);
    }

    // Mengambil daftar produk
    public function getProducts() {
        return array_map('unserialize', $_SESSION['products']);
    }

    // Memperbarui produk berdasarkan index
    public function updateProduct($index, $name, $category, $price, $photo) {
        if (isset($this->products[$index])) {
            $product = unserialize($this->products[$index]);
            $product->setName($name);
            $product->setCategory($category);
            $product->setPrice($price);

            // Jika ada gambar baru yang diunggah, perbarui foto produk
            if (!empty($photo['name'])) {
                $target = "upload/" . basename($photo['name']);
                move_uploaded_file($photo['tmp_name'], $target);
                $product->setPhoto($target);
            }

            $this->products[$index] = serialize($product);
        }
    }

    // Menghapus produk berdasarkan index
    public function deleteProduct($index) {
        if (isset($this->products[$index])) {
            array_splice($this->products, $index, 1);
        }
    }
}
?>
