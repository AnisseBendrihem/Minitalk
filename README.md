# 📡 minitalk

> A 42 School project to implement a basic communication system using UNIX signals between a server and a client, without using sockets or pipes.

---

## 🧠 Objective

`minitalk` implements a one-way communication system between two programs:

- The **server** listens for signals (`SIGUSR1`, `SIGUSR2`)
- The **client** sends a string message, character by character, bit by bit, using those signals

This is a pure C implementation using `kill()` and `signal()` system calls.

---

## 🔧 Usage

### 🛠️ Compilation

```bash
make
