# File Organizer in C

<img width="311" height="66" alt="image" src="https://github.com/user-attachments/assets/f73eb950-ca43-4fca-84ee-693b5cdb4ba8" />

---

### 🌐 Language / Bahasa

[English](#english) | [Bahasa Indonesia](#bahasa-indonesia)

---

## English

A simple utility written in C to keep your folders tidy. This program automatically moves files into specific folders based on their file extensions.

### ❓ FAQ

- **How does it work?**
  Simple! Just download the executable from the releases, or compile the C file yourself if you're familiar with C programming, then run it with a source and destination path.
- **How do I use it?**
  Run it with two arguments: `./organizer <source> <destination>`. Use `--help` or `-h` for usage details.
- **Does it filter files by date?**
  No, it currently only sorts by extension.
- **What happens if a folder already exists?**
  No problem! The program skips creating it and moves on.
- **What if a file fails to move?**
  The program reports the exact error using the system error message, continues with the rest, and shows a final summary of how many succeeded and how many failed.
- **Why did I make this?**
  My Downloads folder gets cluttered fast, and I'm far too lazy to organize it manually. So, I let the code do the work!

> **V1.00:** Dynamic Extension Detection  
> **V2.00:** Source & destination arguments — organize any folder, anywhere. Improved error reporting with system-level messages. New folder creation confirmation. Summary of moved and failed files.

---

## Bahasa Indonesia

Alat bantu sederhana yang dibuat dengan bahasa C untuk merapikan folder Anda. Program ini secara otomatis memindahkan file ke folder tujuan berdasarkan ekstensi filenya.

### ❓ Tanya Jawab

- **Bagaimana cara kerjanya?**
  Mudah! Cukup unduh file yang sudah dikompilasi (executable), atau kompilasi sendiri file C-nya jika Anda paham pemrograman C, lalu jalankan dengan dua argumen: path sumber dan tujuan.
- **Bagaimana cara menggunakannya?**
  Jalankan dengan dua argumen: `./organizer <sumber> <tujuan>`. Gunakan `--help` atau `-h` untuk panduan penggunaan.
- **Apakah ini bisa memfilter berdasarkan tanggal?**
  Tidak, untuk saat ini hanya berdasarkan ekstensi file saja.
- **Bagaimana jika folder tujuan sudah ada?**
  Tidak masalah! Program akan melewatinya dan melanjutkan ke file berikutnya.
- **Bagaimana jika ada file yang gagal dipindahkan?**
  Program akan menampilkan pesan error dari sistem, melanjutkan proses, lalu menampilkan ringkasan jumlah file yang berhasil dan gagal di akhir.
- **Kenapa membuat program ini?**
  Karena folder _Downloads_ saya sering berantakan dan saya terlalu malas untuk merapikannya secara manual, jadi saya buatkan program ini.

> **V1.00:** Deteksi Ekstensi Dinamis  
> **V2.00:** Argumen sumber & tujuan — atur folder mana saja, di mana saja. Pesan error lebih informatif. Konfirmasi pembuatan folder baru. Ringkasan file berhasil dan gagal dipindahkan.
