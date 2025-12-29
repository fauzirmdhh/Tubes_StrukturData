# 📚 Sistem Manajemen Kursus / Pelatihan Online

Program ini merupakan **Tugas Besar mata kuliah Struktur Data** yang dikembangkan menggunakan bahasa pemrograman **C++**. Aplikasi ini berbasis **Command Line Interface (CLI)** dan dirancang untuk mengelola data kursus atau pelatihan online secara terstruktur dengan memanfaatkan **struktur data Multi-Level Linked List (MLL)**.

Melalui sistem ini, setiap level kursus (misalnya Pemula, Menengah, dan Lanjutan) memiliki daftar kursus tersendiri. Setiap kursus menyimpan informasi penting seperti kode kursus, judul, durasi, serta daftar modul. Program dibuat secara modular agar mudah dipahami, dirawat, dan dikembangkan lebih lanjut.

---

## 🎯 Tujuan Program

- 📌 Mengimplementasikan struktur data **Multi-Level Linked List (MLL)**
- 🧠 Melatih pemahaman pointer dan linked list
- ✏️ Menerapkan operasi **CRUD (Create, Read, Update, Delete)**
- ⚙️ Mengelola data kursus secara dinamis
- 📈 Mengembangkan program CLI yang terstruktur

---

## 🗂️ Struktur Data

Program menggunakan **Multi-Level Linked List (MLL)** dengan konsep sebagai berikut:
- 🔹 Linked list utama menyimpan **Level Kursus**
- 🔹 Setiap level memiliki sub linked list berisi **Kursus**
- 🔹 Setiap kursus memiliki atribut:
  - 🆔 Kode kursus
  - 📖 Judul kursus
  - ⏱️ Durasi (jam)
  - 📦 Jumlah modul dan daftar modul

Struktur ini memungkinkan pengelolaan data yang fleksibel dan efisien.

---

## ✨ Fitur Program

- ➕ Menambah level kursus
- ➕ Menambah kursus pada level tertentu
- 📋 Menampilkan seluruh kursus
- 🔍 Mencari kursus berdasarkan:
  - 🆔 Kode
  - 📖 Judul
- 📊 Menghitung jumlah kursus per level
- 🏆 Menampilkan kursus dengan modul terbanyak
- ⌛ Menampilkan kursus dengan durasi terlama
- ✏️ Update data kursus
- 🗑️ Menghapus kursus
- 🔃 Menampilkan kursus terurut berdasarkan durasi

---

## 🧩 Struktur File


**Penjelasan File:**
- 🧠 `main.cpp`  
  Berisi menu utama dan alur interaksi pengguna  
- 📄 `TuBes.h`  
  Berisi deklarasi struktur data dan prototype fungsi  
- ⚙️ `TuBes.cpp`  
  Berisi implementasi seluruh fungsi program  

---

## ▶️ Cara Menjalankan Program

1. 💻 Buka project menggunakan **Code::Blocks**
2. 📁 Pastikan semua file berada dalam satu project
3. ▶️ Compile dan jalankan program
4. 📌 Gunakan menu untuk mengakses fitur yang tersedia

---

## 🛠️ Teknologi yang Digunakan

- 🧑‍💻 Bahasa Pemrograman : C++
- 🧬 Struktur Data       : Multi-Level Linked List
- 🧰 IDE                 : Code::Blocks
- 🖥️ Interface           : Command Line Interface (CLI)

---

## 👤 Author

- Nama   : **Muhammad Fauzi Ramadhan**
- Proyek : **Tugas Besar Struktur Data**
- Topik  : **Sistem Manajemen Kursus / Pelatihan Online**
