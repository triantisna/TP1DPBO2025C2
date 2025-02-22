# JANJI

Saya Trian Tisna Athalla dengan NIM 2001408 mengerjakan Tugas Praktikum 1 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

# Desain Program

Program ini merupakan sistem manajemen produk untuk toko hewan peliharaan (PetShop) yang dapat dijalankan dalam tiga bahasa pemrograman: Python, Java, dan PHP. Program ini mendukung fitur CRUD (Create, Read, Update, Delete) untuk produk dalam toko.

Program terdiri dari beberapa class dan fungsi utama:

1. Class/Product

   - Merepresentasikan sebuah produk dengan atribut:
     - ID
     - Nama Produk
     - Kategori
     - Harga
     - Foto (Khusus PHP) -> Menggunakan SESSION untuk penyimpanan sementara
   - Memiliki metode untuk mendapatkan dan memperbarui data produk

2. Class/PetShop

   - Menyimpan daftar produk
   - Memiliki metode untuk:
     - Menambah produk
     - Menampilkan daftar produk
     - Memperbarui produk
     - Menghapus produk
     - Mencari produk

3. Main Program
   - Menampilkan menu interaktif kepada pengguna untuk memilih aksi yang ingin dilakukan.
   - Menggunakan input dari pengguna untuk menjalankan fitur CRUD pada toko.

# Alur Program

1. Program Dimulai
2. Menampilkan Menu Utama dengan opsi (CRUD)
3. Pengguna memilih opsi Menu
   - (Jika memilih 1) Menampilkan Semua Produk.
   - (Jika memilih 2) Menambahkan Produk, pengguna diminta memasukkan:
     - Nama Produk
     - Kategori
     - Harga
   - (Jika memilih 3) Memperbarui Produk, pengguna memasukkan nama produk yang ingin diperbarui, lalu memasukan data baru.
   - (Jika memilih 4) Menghapus Produk, pengguna memasukkan nama produk yang ingin di haapus.
   - (Jika memilih 5) Pengguna memasukkan nama produk yang ingin dicari, Informasi Produk ditampilkan.
   - (Jika memilih 0) Program dihentikan (keluar).
4. Validasi Input (Program memastikan input harga harus berupa angka)
5. Program berjalan hingga pengguna memilih keluar.

# Dokumentasi

Dokumentasi CPP

![Image](https://github.com/user-attachments/assets/9345f607-850f-4515-b0b2-4bf3a8e79458)

Dokumentasi Java

![Image](https://github.com/user-attachments/assets/80988dd9-95eb-44e4-87f0-65c37efdda85)

Dokumentasi Python

![Image](https://github.com/user-attachments/assets/88967837-cefa-4e00-919d-5d8399f94835)

Dokumentasi PHP

![Image](https://github.com/user-attachments/assets/9f394e8f-cf24-46a3-b524-4b6529a093e1)
