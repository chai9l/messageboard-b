#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;

namespace ariel {

    class Board {
        
        public:
        // Attributes:
        unsigned int row;
        unsigned int coll;
        unsigned int maxRow = 0;
        unsigned int maxColl = 0;
        vector<vector<char>> board;
        
        //Given Functions:
        void post(unsigned int,unsigned int,Direction,string);
        void insertWordToRow(unsigned int, unsigned int, string);
        string read(unsigned int,unsigned int,Direction,unsigned int);
        string readHorizontal(unsigned int, unsigned int, unsigned int);
        string readVertical(unsigned int, unsigned int, unsigned int);
        void show();   

        // Getters & Setters:
        unsigned int getRow() {return this->row;}
        void setRow(unsigned int new_row) {this->row = new_row;}
        unsigned int getColl() {return this->coll;}
        void setColl(unsigned int new_coll) {this->coll = new_coll;}
        unsigned int getMaxRow() {return this->maxRow;}
        void setMaxRow(unsigned int new_max_row) {this->maxRow = new_max_row;}
        unsigned int getMaxColl() {return this->maxColl;}
        void setMaxColl(unsigned int new_max_coll) {this->maxColl = new_max_coll;}

        Board() {row = 0; coll = 0;}
        ~Board();
    };
};