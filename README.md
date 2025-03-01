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
3. **Navigate to the project directory:**  
   ```sh
   cd Tetris-Game
   ```

---

## 🔧 **Step 3: Compile and Run the Game**

### **Using g++ (MinGW on Windows)**
1. **Open the terminal in the project directory.**
2. **Compile the program:**  
   ```sh
   g++ -o tetris tetris.cpp -std=c++11 -static-libstdc++ -static-libgcc
   ```
3. **Run the game:**  
   ```sh
   tetris
   ```

### **Using Microsoft Visual Studio**
1. **Open Visual Studio.**  
2. **Create a new C++ project and add `tetris.cpp`.**  
3. **Build and run the project.**  

---

## 🔍 **Step 4: Game Controls**
- **Left Arrow (←):** Move the piece left  
- **Right Arrow (→):** Move the piece right  
- **Down Arrow (↓):** Drop the piece faster  
- **Up Arrow (↑):** Rotate the piece  
- **Spacebar:** Drop the piece instantly  
- **P:** Pause the game  
- **R:** Restart the game  
- **Q:** Quit the game  

---

## 🔮 **Step 5: Understanding the Code**
Below is a breakdown of the main components of the game:

### **1. `class Piece`**
- Represents the Tetris pieces.
- Defines the different shapes and their movement.
- Handles rotation of the pieces.

### **2. `class Game`**
- Manages the game board and controls.
- Handles the movement of pieces and collision detection.
- Implements score tracking and line clearing.

### **3. `void draw()`**
- Renders the game board and current piece on the console.
- Displays the score and available controls.

### **4. `void update()`**
- Moves the piece down periodically.
- Checks for collisions and locks pieces into place.

### **5. `void handleInput()`**
- Reads user input for movement, rotation, and pausing the game.

### **6. `void clearLines()`**
- Checks for and removes completed rows.
- Updates the score based on cleared lines.

### **7. `void gameOver()`**
- Ends the game if a piece cannot spawn.
- Displays the final score and prompts restart.

---


Happy coding! ✨

