#pragma once

#include "GameState.hpp"

#include<iostream>
using std::ostream;

#include<string>
using std::string;

class GamePiece 
{
    private:
        // data members
            string player_name_;
            string piece_type_;
            GameState* current_game_; // pointer to the current game
    public:
        // constructors
            GamePiece(string,string,GameState*);
            GamePiece(GamePiece const &); // copy constructor

        // member functions
            string GetPlayer();
            string GetType();

            int GetPower() const;
            int GetSpeed() const;

        // 6 comparison operators
            bool operator==(GamePiece const &)const;
            bool operator!=(GamePiece const &)const;
            bool operator<(GamePiece const &)const;
            bool operator>(GamePiece const &)const;
            bool operator<=(GamePiece const &)const;
            bool operator>=(GamePiece const &)const;  

        // operator=
            GamePiece &operator=(GamePiece const &);

        // friend for operator<<
            friend ostream &operator<<(ostream &, GamePiece const &);

        // destructor 
            ~GamePiece();
};
// << operator
ostream &operator<<(ostream &, GamePiece const &);