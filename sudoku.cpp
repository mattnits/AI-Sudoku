#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

class Sudoku {
    public:
        int puzzle[9][9];
        Sudoku() {
            int i = 0, j = 0, k = 0;
            std::string text, temp;

            for (i = 0; i < 9; i++) {
                for (j = 0; j < 9; j++) {
                    puzzle[i][j] = 0;
                }
            }

            std::ifstream MyReadFile("test.txt");
            while (getline (MyReadFile, text)) {
                for (k = 0; k < text.length(); k = k + 2) {
                    temp = text[k];
                    puzzle[i][j] = atoi(temp.c_str());
                    j++;
                }
                j = 0;
                i++;
            }
        }

        void printBoard() {
            int i = 0, j = 0, k = 0;
            std::cout << "PUZZLE:" << std::endl;
            for (i = 0; i < 9; i++) {
                for (j = 0; j < 9; j++) {
                    std::cout << this->puzzle[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
};



int main() {
    int size = 9;
    int i = 0;
    int j = 0;
    int k = 0;
    std::string text, temp;
    int puzzle[size][size];

    /*for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            puzzle[i][j] = 0;
        }
    }
    j = 0;
    i = 0;
    std::ifstream MyReadFile("test.txt");
    while (getline (MyReadFile, text)) {
        for (k = 0; k < text.length(); k = k + 2) {
            temp = text[k];
            puzzle[i][j] = atoi(temp.c_str());
            j++;
        }
        j = 0;
        i++;
    }

    std::cout << "PUZZLE:" << std::endl;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            std::cout << puzzle[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    Sudoku s;
    s.printBoard();
    
    return 0;
}


