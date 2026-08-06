<div align="center">

# 🏧 ATM Management System

### C++ OOP ATM simulator with Money and Security classes

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)]()
[![OOP](https://img.shields.io/badge/OOP-Semester_Project-FF6B6B?style=for-the-badge)]()

</div>

> _This is an **academic project** developed as part of university coursework at the University of Lahore._


---

## 🎯 What This Does

An ATM simulator with two classes — `Money` (balance tracking, withdraw with insufficient funds check, deposit) and `Security` (PIN verification with 3-attempt lockout). Features colored console output via ANSI escape codes. **150 lines of C++.**

---

## 🏗️ Class Design (from actual code)

```cpp
class Money {
private:
    int cash = 1000;  // Starting balance
    int withdraw, deposit;
public:
    void check_balance();
    void money_withdraw();   // Validates against current balance
    void money_deposit();
};

class Security {
private:
    int pin = 1234;  // Default PIN
public:
    int password();  // 3 attempts, returns success/fail
};
```

---

## ✨ Features

- **PIN authentication** — 3-attempt lockout via Security class
- **Balance check / Withdraw / Deposit** — with insufficient funds validation
- **Colored console output** — `\033[31m` red for errors, `\033[32m` green for success
- **Cross-platform screen clear** — `cls` on Windows, `clear` on Linux/Mac

---

## 🚀 Getting Started

```bash
git clone https://github.com/MianDaniyalHassan/ATM_Project.git
cd ATM_Project

g++ -o atm ATM.cpp -std=c++17
./atm
```

Default PIN: `1234` | Starting balance: `$1000`


## 👨‍💻 Author

**Mian Daniyal Hassan** — _CS @ University of Lahore · Dean's Honor List_

[![Portfolio](https://img.shields.io/badge/🌐_Portfolio-00F7FF?style=for-the-badge)](https://daniyal-s-new-portfolio.vercel.app)
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/MianDaniyalHassan)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mian-daniyal-hassan-849971293)

<div align="center">⭐ Star this repo if you found it useful! ⭐</div>

