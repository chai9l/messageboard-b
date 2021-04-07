#include <string>
#include <iostream>
#include "Direction.hpp"
#include "Board.hpp"
#include <vector>
using namespace std;
using ariel::Board;

namespace ariel {
    void Board::post(unsigned int row, unsigned int coll, Direction direction, string word) {
        //Direction is Horizontal
        if(direction == Direction::Horizontal) {
            //Checks if the current board collumn size is suffiecient
            insertWordToRow(row, coll, word);
        }
        // Direction is Vertical
        else {
            //Checks if the current board row size is suffiecient
            for(uint i = 0; i < word.length(); i++) {
                string temp;
                insertWordToRow(row++, coll, temp+word[i]);
            }
        }
    }

    void Board::insertWordToRow(unsigned int row, unsigned int coll, string word) {
        if(row >= this->board.size()) {
            this->board.resize(row+1);   
        }
        if(word.length() + coll > this->board[row].size()) {
            this->board[row].resize(word.length() + coll, '_');
        }
        for(uint i = 0; i < word.length(); i++) {
            this->board[row][coll++] = word[i];
        }
    }
    string Board::readHorizontal(unsigned int row, unsigned int coll, unsigned int toRead) {
        int counter = 0;
        string ret;
        if(row >= this->board.size()) {
            for(uint i = 0; i < toRead; i++ ) {
                ret += '_';
            }
            return ret;
        }
        while(coll < this->board[row].size() && counter < toRead) {
            ret += this->board[row][coll++];
            counter++;
        }
        while(counter < toRead) {
            ret += '_';
            counter++;
        }
        return ret;
    }

    string Board::readVertical(unsigned int row, unsigned int coll, unsigned int toRead) {
        string ret;
        int counter = 0;

        while(row < this->board.size() && counter < toRead) {
            if(coll < this->board[row].size()) {
                ret += this->board[row][coll];
            }
            else {
                ret += '_';
            }
            counter++;
            row++;
        }
        while(counter < toRead) {
            ret += '_';
            counter++;
        }
        return ret;
    }

    string Board::read(unsigned int row, unsigned int coll, Direction direction, unsigned int toRead){
        
        switch (direction)
        {
        case Direction::Horizontal :
            return readHorizontal(row, coll, toRead);
        case Direction::Vertical :
            return readVertical(row, coll, toRead);
        }
    }
        
    void Board::show(){
        for(uint i = 0; i < this->board.size(); i++) {
            cout << "[";
            for(uint j = 0; j < this->board[i].size(); j++) {
                cout << board[i][j];
            }
            cout << "]" << endl;
        }
    }

    Board::~Board(){}

};