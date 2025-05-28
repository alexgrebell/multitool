# multitool

A lightweight, cross-platform C-based console multitool that runs on both Windows and Linux terminals.  
Includes essential utilities like a timer, calculator, time calculator, percentage calculator, and random number generator.

---

## 🛠 Features

- **Timer** – Countdown timer with pause (`SPACE`) and quit (`q`) support
- **Basic Calculator** – Supports addition, subtraction, multiplication, division
- **Time Calculator** – Perform math on `hh:mm:ss` formatted time strings
- **Percentage Calculator** – Calculate percentage of any number
- **Randomizer** – Generate random number within a user-defined range

---

## 🧩 How to Build

### 🔷 On Linux / macOS

```bash
gcc media.c -o multitool
./multitool
```
### 🟦 On Windows (MinGW or similar)

bash
Copy
Edit
gcc media.c -o multitool.exe
multitool.exe

---

## 🧭 Navigation:

When you run the program, you'll see a menu

markdown
Copy
Edit
1. Timer  
2. Calculator  
3. Time calculation  
4. Percentage calculator  
5. Randomizer  
Press the corresponding number to use a tool. You can exit any tool using q (when prompted) or return to the main menu.

---

## 🔁 Controls

Timer:

SPACE to pause/resume

q to quit early

Other tools:

Enter q to return to the main menu

---

## 💡 Notes

Console-clearing is OS-dependent: uses cls (Windows) and clear (Linux/macOS)

Keyboard input handling (_kbhit, _getch) is emulated for Linux systems

---

## ℹ️ About the project
This program was written for personal practice, to remember the basics of the C language and experiment with creating a simple multi-tool for the terminal.

Some parts of the code were implemented using hints from ChatGPT or based on examples of working with system functions (such as kbhit or getch) for cross-platform support for Windows and Linux.

The project does not claim to be perfect - it is rather a learning tool and a reminder of C syntax, logic and structures.
