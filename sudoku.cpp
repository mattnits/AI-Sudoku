#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "llist.cpp"

// To do:
// Change array to be dynamic (allow bigger/smaller boards)
// 
// Make it so list doesnt sort when adding
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

        int getValue(int i, int j) {
            return this->puzzle[i][j];
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
            int i = 0, j = 0, val = 0;
            NODE *temp = NULL;
            for (i = 0; i < 9; i++) {
                ai_board[i] = *create_node(i);
            }
            
            for (i = 0; i < 9; i++) {
                for (j = 0; j < 9; j++) {
                    val = getValue(i, j);
                    std::cout << val << " ";
                    if (j == 0) {
                        make_start(&ai_board[i], create_node(val));
                        temp = ai_board[i].start;
                    }
                    else {
                        //insert_unsorted(&temp, val);
                        display(temp);
                    }
                }
            }
        
        
        }

        void printBoard() {
            int i = 0, j = 0, k = 0, cntVert = 0, cntHor = 0, linecnt = 0;
            NODE *temp1 = NULL, *tempVal = NULL;
            std::cout << "AI PUZZLE:" << std::endl;
            while (i < 9) {
                temp1 = this->ai_board[i].start;
                while (temp1 != NULL) {
                    std::cout << temp1->val << "";
                    temp1 = temp1->next;
                }
                std::cout << std::endl;
                i++;
            }
        }
};



int main() {
    // Sudoku s;
    // s.printBoard();

    NODE *startp = NULL, *endp = NULL;
    insert_sorted(&startp, &endp, 5);
    insert_sorted(&startp, &endp, 3);
    insert_sorted(&startp, &endp, 2);
    insert_sorted(&startp, &endp, 8);
    
    NODE ai_board[9];
    ai_board[0] = *create_node(1);
    ai_board[1] = *create_node(2);

    make_start(&ai_board[0], startp);

    //std::cout << ai_board[0].val << std::endl;
    //std::cout << ai_board[1].val << std::endl;
    //std::cout << ai_board[0].start->val << std::endl;

    //NODE *temp = NULL;
    //temp = &ai_board[0];
    //insert_sorted(&temp, &endp, 2);

    display(startp);

    std::cout << endp->val;

    // AI_Sudoku ai(s);
    // ai.printBoard();
    
    
    return 0;
}


