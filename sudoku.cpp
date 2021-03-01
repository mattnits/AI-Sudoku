#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "llist.cpp"

// To do:
// Change array to be dynamic (allow bigger/smaller boards)
// 
// 
// 
// 


class Sudoku {
    public:
        int puzzle[9][9];
        Sudoku() {
            int i = 0, j = 0, k = 0, val1;
            std::string text, temp;

            for (i = 0; i < 9; i++) {
                for (j = 0; j < 9; j++) {
                    puzzle[i][j] = 0;
                }
            }
            i = 0;
            j = 0;
            std::ifstream MyReadFile("test.txt");
            while (getline (MyReadFile, text)) {
                for (k = 0; k < text.length(); k++) {
                    temp = text[k];
                    val1 = atoi(temp.c_str());
                    puzzle[i][j] = val1;
                    //std::cout << "Puzzle " << puzzle[i][j] << " I " << i << " J " << j << std::endl;
                    j++;
                }
                j = 0;
                i++;
            }
        }

        void printBoard() {
            int i = 0, j = 0, k = 0, cntVert = 0, cntHor = 0, linecnt = 0;
            std::cout << "PUZZLE:" << std::endl;
            while (i < 9) {
                while (j < 9) {
                    if (cntHor == 3 || cntHor == 7) {
                        if (linecnt < 21) {
                            std::cout << "-";
                            linecnt++;
                        }
                        else {
                            cntHor++;
                            linecnt = 0;
                            std::cout << std::endl;
                        }
                        
                    }
                    else if (cntVert == 3 || cntVert == 7) {
                        std::cout << "| ";
                        cntVert++;
                    }
                    else {
                        std::cout << this->puzzle[i][j] << " ";
                        j++;
                        cntVert++;
                    }
                    
                }
                std::cout << std::endl;
                j = 0;
                i++;
                cntVert = 0;
                cntHor++;
            }
        }
};

class AI_Sudoku: public Sudoku {
    public:
        NODE ai_board[9];
        AI_Sudoku(Sudoku puzzle) {
            // int i = 0;
            // for (i = 0; i < 9; i++) {
            //     ai_board[i] = "1";
            // }
        }
};



int main() {
    //Sudoku s;
    //s.printBoard();

    // NODE *startp = NULL;
    
    // NODE ai_board[9];
    // ai_board[0] = *create_node(1);

    // std::cout << ai_board[0].val;

    // NODE *temp = NULL;
    // temp = &ai_board[0];
    // insert(&temp, 2);

    // display(&ai_board[0]);
    
    
    return 0;
}


