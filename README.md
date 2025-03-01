# 🎮 Tetris Game in C++ - The Ultimate Console Challenge!

A **classic Tetris game** built using **C++** and the Windows Console.  
This ain't just a game, it's **a test of speed, reflexes, and strategic thinking!** 🧠💡

---

## 📌 **Project Overview**
- **Language:** C++  
- **Platform:** Windows Console  
- **Features:**  
  ✅ Randomly generated Tetris pieces  
  ✅ Real-time keyboard controls  
  ✅ Score tracking  
  ✅ Game pause & restart  
  ✅ Smooth animations & instant drop feature  
  ✅ Classic game mechanics with a nostalgic console touch! 🎮  

---

## 🚀 **Step 1: Prerequisites**
Before you dive into this **epic battle of blocks**, make sure you have:

- **A C++ compiler** (like **g++ from MinGW** or **Microsoft Visual Studio**)  
- **A Windows operating system** (since we use `windows.h`)  
- **Git installed** (for cloning the repository)  

---

## 🛠 **Step 2: Setup and Installation**

### **Method 1: Download the Source Code Manually**
1. **Download the ZIP**  
   - Click on the **"Code"** button above.  
   - Select **"Download ZIP"** and extract the files to a folder.  

2. **Open the project folder**  
   - Navigate to the extracted files.  

---

### **Method 2: Clone the Repository via Git (Recommended)**
1. **Open the terminal (Command Prompt or Git Bash).**  
2. **Run the following command to clone the repository:**  
   ```sh
   git clone https://github.com/your-username/Tetris-Game.git
   ```
3. **Navigate to the project directory:**  
   ```sh
   cd Tetris-Game
   ```

---

## ⚙️ **Step 3: Compilation and Execution**
1. **Open the terminal or command prompt inside the project folder.**
2. **Compile the game using g++:**  
   ```sh
   g++ tetris.cpp -o tetris.exe
   ```
3. **Run the game:**  
   ```sh
   tetris.exe
   ```
4. **Enjoy the Tetris madness!** 🚀💥

---

## 🎮 **Game Controls**
| Key | Action |
|------|--------------|
| ←    | Move left    |
| →    | Move right   |
| ↓    | Soft drop    |
| ↑    | Rotate piece |
|Space | Hard drop    |
| P    | Pause/Resume |
| R    | Restart game |
| Q    | Quit game    |

**Remember:** Every block you place **matters**—plan wisely, or you’ll be buried under a digital avalanche! ⏳⚡

---

## 🏆 **Scoring System**
- 1 line cleared = **100 points**  
- 2 lines cleared = **300 points**  
- 3 lines cleared = **500 points**  
- 4 lines cleared (TETRIS!) = **800 points** 🔥🔥🔥  
- Hard drop bonus for instant placement!  

---

## 🔍 **Function Breakdown**
Here’s what makes the magic happen behind the scenes:

### **🎲 `Piece` Class**
Manages individual Tetris blocks and their rotations.
- `resetShape()`: Initializes piece shape.
- `rotate()`: Rotates the current piece if space allows.

### **🕹️ `Game` Class**
Handles the game logic, drawing, and user input.
- `draw()`: Renders the game board.
- `update()`: Moves the block down automatically.
- `handleInput()`: Detects and responds to user key presses.
- `canMove()`: Checks if a piece can move to a new position.
- `lockPiece()`: Locks a piece when it lands and spawns a new one.
- `clearLines()`: Removes completed lines and updates the score.
- `gameOver()`: Ends the game if no space remains.

---



### 🚀 **Now go stack those blocks and chase the high score!** 🎮🔥
