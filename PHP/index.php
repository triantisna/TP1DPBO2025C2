<?php
include 'PetShop.php'; // Menghubungkan dengan file PetShop.php

$shop = new PetShop(); // Membuat objek PetShop

// Jika ada data yang dikirim melalui form
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['add'])) {
        $shop->addProduct($_POST['name'], $_POST['category'], $_POST['price'], $_FILES['photo']);
    } elseif (isset($_POST['update'])) {
        $shop->updateProduct($_POST['index'], $_POST['name'], $_POST['category'], $_POST['price'], $_FILES['photo']);
    } elseif (isset($_POST['delete'])) {
        $shop->deleteProduct($_POST['index']);
    }
    header("Location: index.php"); // Redirect ke halaman utama setelah operasi
    exit;
}

$products = $shop->getProducts(); // Ambil daftar produk
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PetShop - Daftar Produk</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f8f9fa;
        }
        h2 {
            text-align: center;
            color: #343a40;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            background: white;
            box-shadow: 2px 2px 10px rgba(0, 0, 0, 0.1);
        }
        th, td {
            padding: 10px;
            text-align: center;
            border: 1px solid #ddd;
        }
        th {
            background: #007bff;
            color: white;
        }
        img {
            width: 80px;
            height: 80px;
            object-fit: cover;
            border-radius: 8px;
        }
        .action-buttons {
            display: flex;
            justify-content: flex-end;
            margin-top: -50px;
        }
        .btn-edit, .btn-delete {
            padding: 8px 12px;
            border: none;
            cursor: pointer;
            font-size: 14px;
            color: white;
            margin-left: 5px;
        }
        .btn-edit { background: #ffc107; }
        .btn-delete { background: #dc3545; }
        .form-container {
            background: white;
            padding: 15px;
            border-radius: 5px;
            width: 50%;
            margin: auto;
            box-shadow: 2px 2px 10px rgba(0, 0, 0, 0.1);
        }
        .form-container input, .form-container button {
            display: block;
            width: 100%;
            margin-bottom: 10px;
            padding: 8px;
        }
        .btn-add { background: #28a745; color: white; border: none; }
    </style>
</head>
<body>
    <h2>Daftar Produk PetShop</h2>

    <table border="1" cellspacing="0" cellpadding="8">
        <tr>
            <th>ID</th>
            <th>Nama Produk</th>
            <th>Kategori</th>
            <th>Harga</th>
            <th>Foto</th>
            <th>Aksi</th>
        </tr>
        <?php foreach ($products as $index => $product) : ?>
        <tr>
            <td><?= $index + 1; ?></td>
            <td><?= htmlspecialchars($product->getName()); ?></td>
            <td><?= htmlspecialchars($product->getCategory()); ?></td>
            <td>Rp <?= number_format($product->getPrice(), 2, ',', '.'); ?></td>
            <td>
                <img src="<?= htmlspecialchars($product->getPhoto()); ?>" alt="Foto Produk" 
                    style="width: 80px; height: 80px; object-fit: cover; border-radius: 8px;">
            </td>
            <td style="text-align: center;">
                <!-- Form untuk Edit -->
                <!-- <form method="POST" style="display: inline-block;">
                    <input type="hidden" name="edit_index" value="<?= $index; ?>">
                    <button class="btn btn-edit" type="submit" name="edit">Edit</button>
                </form> -->


                <!-- Form untuk Hapus -->
                <form method="POST" style="display: inline-block;">
                    <input type="hidden" name="index" value="<?= $index; ?>">
                    <button class="btn btn-delete" type="submit" name="delete">Hapus</button>
                </form>

            </td>
        </tr>
        <?php endforeach; ?>
    </table>


    <h2>Tambah Produk</h2>
    <div class="form-container">
        <form method="POST" enctype="multipart/form-data">
            <input type="text" name="name" placeholder="Nama Produk" required>
            <input type="text" name="category" placeholder="Kategori" required>
            <input type="number" name="price" placeholder="Harga" required>
            <input type="file" name="photo" accept="image/*" required>
            <button class="btn-add" type="submit" name="add">Tambah</button>
        </form>
    </div>
</body>
</html>
