#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 20;

class Piece {
public:
    char shape[4][4];
    int x, y;
    char type;

    Piece(char t) : type(t), x(3), y(0) {
        resetShape();
    }

    void resetShape() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                shape[i][j] = ' ';

        switch (type) {
            case 'I': shape[1][0] = shape[1][1] = shape[1][2] = shape[1][3] = '#'; break;
            case 'O': shape[0][0] = shape[0][1] = shape[1][0] = shape[1][1] = '#'; break;
            case 'T': shape[0][1] = shape[1][0] = shape[1][1] = shape[1][2] = '#'; break;
            case 'S': shape[0][1] = shape[0][2] = shape[1][0] = shape[1][1] = '#'; break;
            case 'Z': shape[0][0] = shape[0][1] = shape[1][1] = shape[1][2] = '#'; break;
            case 'J': shape[0][0] = shape[1][0] = shape[1][1] = shape[1][2] = '#'; break;
            case 'L': shape[0][2] = shape[1][0] = shape[1][1] = shape[1][2] = '#'; break;
        }
    }
};

class Game {
    char board[HEIGHT][WIDTH];
    Piece current;
    int score;
    bool isPaused;
    bool isRunning;
    HANDLE console;

    void resetGame() {
        score = 0;
        isPaused = false;
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
                board[i][j] = ' ';
        createNewPiece();
    }

public:
    Game() : current('I'), score(0), isPaused(false), isRunning(true) {
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        resetGame();
    }

    void draw() {
        SetConsoleCursorPosition(console, {0, 0});
        cout << "---------- TETRIS ----------\n";
        for (int i = 0; i < HEIGHT; i++) {
            cout << "|";
            for (int j = 0; j < WIDTH; j++) {
                bool isPiece = false;
                for (int pi = 0; pi < 4; pi++)
                    for (int pj = 0; pj < 4; pj++)
                        if (current.shape[pi][pj] != ' ' && 
                            current.x + pj == j && 
                            current.y + pi == i)
                            isPiece = true;

                cout << (isPiece ? '#' : board[i][j]);
            }
            cout << "|\n";
        }
        cout << "---------------------------\n";
        cout << "Score: " << score << "\n";
        cout << "Controls:\n";
        cout << "P: Pause  Q: Quit  R: Restart\n";
        cout << "Arrows: Move  Space: Drop\n";
    }

    void update() {
        if (isPaused) return;

        static int counter = 0;
        if (++counter > 20) {
            if (canMove(current.x, current.y + 1))
                current.y++;
            else
                lockPiece();
            counter = 0;
        }
    }

    void handleInput() {
        if (_kbhit()) {
            int key = _getch();
            
            if (key == 'p' || key == 'P') {
                isPaused = !isPaused;
                draw();
            }
            if (key == 'q' || key == 'Q') isRunning = false;
            if (key == 'r' || key == 'R') resetGame();

            if (!isPaused) {
                if (key == 224) {
                    key = _getch();
                    switch (key) {
                        case 75: if (canMove(current.x - 1, current.y)) current.x--; break;
                        case 77: if (canMove(current.x + 1, current.y)) current.x++; break;
                        case 72: rotate(); break;
                        case 80: if (canMove(current.x, current.y + 1)) current.y++; break;
                    }
                } 
                else if (key == 32) {
                    while (canMove(current.x, current.y + 1)) current.y++;
                    lockPiece();
                }
            }
        }
    }

    bool canMove(int newX, int newY) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (current.shape[i][j] == ' ') continue;
                int x = newX + j;
                int y = newY + i;
                if (x < 0 || x >= WIDTH || y >= HEIGHT) return false;
                if (y >= 0 && board[y][x] != ' ') return false;
            }
        }
        return true;
    }

    void lockPiece() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (current.shape[i][j] != ' ') {
                    int x = current.x + j;
                    int y = current.y + i;
                    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
                        board[y][x] = '#';
                }
        clearLines();
        createNewPiece();
    }

    void clearLines() {
        int linesCleared = 0;
        for (int row = HEIGHT - 1; row >= 0; row--) {
            bool full = true;
            for (int col = 0; col < WIDTH; col++) {
                if (board[row][col] == ' ') {
                    full = false;
                    break;
                }
            }

            if (full) {
                for (int r = row; r > 0; r--)
                    for (int c = 0; c < WIDTH; c++)
                        board[r][c] = board[r - 1][c];
                linesCleared++;
                row++;
            }
        }
        score += linesCleared * 100;
    }

    void createNewPiece() {
        char types[] = {'I','O','T','S','Z','J','L'};
        current = Piece(types[rand() % 7]);
        if (!canMove(current.x, current.y)) gameOver();
    }

    void rotate() {
        Piece temp = current;
        char rotated[4][4];
        
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                rotated[i][j] = temp.shape[3 - j][i];

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                temp.shape[i][j] = rotated[i][j];

        if (canMove(temp.x, temp.y))
            current = temp;
    }

    void gameOver() {
        system("cls");
        cout << "GAME OVER! Final Score: " << score << endl;
        cout << "Press R to restart or Q to quit\n";
    }

    void run() {
        while (isRunning) {
            draw();
            handleInput();
            update();
            Sleep(50);
        }
    }
};

int main() {
    srand(time(0));
    Game tetris;
    tetris.run();
    return 0;
}
