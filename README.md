# Smart Library Management System

Final Project Mata Kuliah Algoritma dan Pemrograman  
Teknik Elektro Universitas Indonesia

---

# Deskripsi Project

Smart Library Management System adalah aplikasi perpustakaan berbasis Client-Server yang mengimplementasikan:

- Object Oriented Programming (4 Pilar)
- Struktur Data Linked List Manual
- Searching Algorithm
- Sorting Algorithm
- TCP Socket Networking
- JSON Communication
- Multithreading
- JSON Persistence

Project ini dibuat untuk memenuhi tugas akhir mata kuliah Algoritma dan Pemrograman.

---

# Features

## OOP (4 Pilar)

- Abstraction
- Encapsulation
- Inheritance
- Polymorphism

---

## Data Structure

- Manual Generic Linked List

---

## Searching Algorithm

- Linear Search
- Binary Search

---

## Sorting Algorithm

- Quick Sort
- Merge Sort

---

## Networking

- TCP Socket
- Client-Server Architecture
- Multithreading Server

---

## JSON

- JSON Communication
- JSON File Persistence

---

# Technologies Used

- C++
- Winsock2
- TCP Socket
- Multithreading
- nlohmann/json

---

# Folder Structure

```plaintext
Finpro-Alprog/
│
├── Algorithms/
├── Client/
├── Data/
├── Managers/
├── Models/
├── Networking/
├── Server/
├── Structures/
│
├── RESULT/
│   ├── server.exe
│   ├── client.exe
│   ├── books.json
│   ├── users.json
│   ├── transactions.json
│   └── README_RESULT.txt
│
├── test_main.cpp
├── README.md
└── .gitignore
```

---

# Requirements

- Windows OS
- MinGW g++
- PowerShell / CMD
- C++17

---

# Compile Instruction

## Compile Server

```bash
g++ server/server.cpp -o server -lws2_32
```

## Compile Client

```bash
g++ client/client.cpp -o client -lws2_32
```

---

# Run Instruction

## Run Server

```bash
.\server.exe
```

## Run Client

```bash
.\client.exe
```

---

# Demo Flow

1. Jalankan server.exe
2. Jalankan client.exe
3. View books
4. Search books
5. Borrow books
6. Jalankan beberapa client untuk demo multithreading

---

# Default Login

## Admin

```plaintext
Username : admin
Password : 123
```

---

## Member

```plaintext
Username : member
Password : 123
```

---

# Networking Flow

```plaintext
CLIENT
   ↓
JSON Request
   ↓ TCP SOCKET ↓
SERVER
   ↓
Process Request
   ↓
LibraryManager
   ↓
JSON Response
```

---

# OOP Implementation

| OOP Concept | Implementation |
|---|---|
| Abstraction | User abstract class |
| Encapsulation | private data + getter/setter |
| Inheritance | Admin & Member inherit User |
| Polymorphism | showMenu() override |

---

# Data Persistence

Project menggunakan:

```plaintext
books.json
users.json
transactions.json
```

untuk menyimpan data secara persistent.

---

# Multithreading

Server menggunakan:

```cpp
thread clientThread(...)
```

agar dapat menangani banyak client secara bersamaan.

---

