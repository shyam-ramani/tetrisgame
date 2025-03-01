# 🎮 Tetris Game in C++

A **classic Tetris game** built using **C++** and the Windows Console.  
This game allows the player to control falling blocks, clear rows, and score points.  

---

## 📌 **Project Overview**
- **Language:** C++  
- **Platform:** Windows Console  
- **Features:**  
  ✅ Randomly generated Tetris pieces  
  ✅ Real-time keyboard controls  
  ✅ Score tracking  
  ✅ Game pause & restart  

---

## 🚀 **Step 1: Prerequisites**
Before running the game, ensure you have:  

- **A C++ compiler** (like **g++ from MinGW** or **Microsoft Visual Studio**)  
- **A Windows operating system** (as the game uses `windows.h`)  
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
3. **Navigate to the project folder:**  
   ```sh
   cd Tetris-Game
   ```

---

## ▶️ **Step 3: Compilation and Execution**

1. **Compile the game using g++ (MinGW or any C++ compiler):**  
   ```sh
   g++ -o tetris tetris.cpp -std=c++11
   ```

2. **Run the game:**  
   ```sh
   ./tetris
   ```

---

## 🎮 **Controls**
| Key | Action |
|-----|--------|
| ⬅️  | Move Left |
| ➡️  | Move Right |
| ⬇️  | Move Down |
| ⬆️  | Rotate Piece |
| Space | Hard Drop |
| P | Pause |
| Q | Quit |
| R | Restart |

---

## 🔍 **Function Breakdown**

### 🎯 **1. `resetShape()`**
📌 **Purpose:** Initializes the shape of a new Tetris piece based on its type (I, O, T, S, Z, J, L).

🔹 **How it works:**
- Clears the 4x4 shape matrix by setting all values to `' '`.
- Fills in the matrix based on the type of the piece.

---

### 🖥 **2. `draw()`**
📌 **Purpose:** Displays the game board, current piece, score, and controls.

🔹 **How it works:**
- Moves the console cursor to prevent flickering.
- Loops through the board and prints characters.
- Displays the **current falling piece**.

---

### ⏳ **3. `update()`**
📌 **Purpose:** Moves the piece down every few frames and locks it if it can't move further.

🔹 **How it works:**
- Increments a counter.
- If the counter exceeds a threshold, the piece moves down.
- If it **can't move**, it gets **locked into place**.

---

### 🎮 **4. `handleInput()`**
📌 **Purpose:** Reads keyboard input and moves the piece accordingly.

🔹 **How it works:**
- Uses `_kbhit()` to check for key presses.
- `_getch()` captures the key.
- Handles movement, rotation, pausing, and quitting.

---

### ✅ **5. `canMove(int newX, int newY)`**
📌 **Purpose:** Checks if the piece can move to a new position.

🔹 **How it works:**
- Loops through the **4x4 shape matrix**.
- Checks if the new position is **within the board boundaries**.
- Ensures the position is **not occupied**.

---

### 🔐 **6. `lockPiece()`**
📌 **Purpose:** Places the piece permanently on the board after landing.

🔹 **How it works:**
- Copies the current shape into the **board matrix**.
- Calls `clearLines()` to remove full rows.
- Generates a **new random piece**.

---

### 🎆 **7. `rotate()`**
📌 **Purpose:** Rotates the piece 90 degrees clockwise.

🔹 **How it works:**
- Creates a **temporary rotated matrix**.
- Copies the rotated values into `current.shape`.
- Checks if the rotation is **valid** before applying.

---

## 🏆 **Score Calculation**
- **Single Line Clear** → +100 points  
- **Double Line Clear** → +300 points  
- **Triple Line Clear** → +500 points  
- **Tetris (4 lines cleared at once!)** → +800 points 🎉  

---


## 💡 **Future Enhancements**
🔹 **Add Sound Effects** 🎵  
🔹 **Implement Multiplayer Mode** 👥  
🔹 **Custom Themes & Skins** 🎨  



🚀 **Enjoy Tetris and keep coding!** 🎮🔥
