#pragma once

#include<string>
using std::string;

#include<map>
using std::map;

class GamePiece;

class GameState 
{
    private:
        struct Player_Info
        {
            int warrior_count;
            int scout_count;
            int wizard_count;
        };
        // map to hold players name and piece information
        map<string,Player_Info> player_data; 
    public:
        GameState() = default;
        
        int NumPieces();
        int NumPieces(string);
        int NumPieces(string,string);

        void AddPiece(GamePiece &);
        void AddPiece(string,string);

        void RemovePiece(GamePiece &);
        void RemovePiece(string,string);

        int WizardCount(string);
        int TotalWizards();
};
