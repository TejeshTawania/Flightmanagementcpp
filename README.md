# ✈️ Flight Reservation System

A lightweight, high-performance terminal-based flight reservation system written in modern C++. This project demonstrates foundational **Object-Oriented Programming (OOP)** practices, robust input handling, and clean database management using memory-efficient structures.

---

## 🚀 Features

*   **Encapsulated Data Model:** Safely protects flight variables (capacity, seats reserved) using private class attributes and explicit `const` read-only getters.
*   **Robust Input Sanitization:** Integrated failure-state checks (`cin.fail()`) that intercept and neutralize invalid user inputs (e.g., entering characters instead of integers), preventing infinite loops or application crashes.
*   **Dynamic Inventory Tracking:** Automatically tracks seat configurations and calculates accurate real-time availability on every single booking transaction.
*   **Cross-Platform UI Support:** Utilizes conditional preprocessor macro blocks to seamlessly execution screen-clearing commands (`cls` vs `clear`) across Windows, macOS, and Linux terminals.

---

## 🛠️ Tech Stack & Concepts

*   **Language:** C++ (compiled with C++11 standard or higher)
*   **Containers:** Standard Template Library (STL) `std::vector` for dynamic memory array allocation
*   **OOP Patterns:** Encapsulation, Single Responsibility, Separation of Concerns

---

## 📂 Project Structure

| Component | Responsibility | Key Mechanics |
| :--- | :--- | :--- |
| **`Flight` Class** | Core data model | Manages capacity, booking validation logic, and read-only attributes. |
| **`ReservationSystem` Class** | Controller database | Holds the collection vector, handles flight generation, and coordinates booking workflows. |
| **`main()` Function** | Interface driver | Seeds initial route data, handles the loop menu lifecycle, and sanitizes keyboard streams. |

---
