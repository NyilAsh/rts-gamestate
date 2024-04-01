#include "GameState.hpp"
#include "GamePiece.hpp"

// no parameters
// returns an int representing all the pieces in the current game
int GameState::NumPieces()
{
    int total_pieces = 0;
    for (auto&[name, count]: player_data)
    {
        // loops through map and adds the 3 pieces for a total count of the game
        total_pieces += player_data[name].warrior_count + player_data[name].scout_count + player_data[name].wizard_count;
    }
    return total_pieces;
}

// one paramter being a string 
// returns an int representing the total pieces for a specific player
int GameState::NumPieces(string player_name)
{
    // gets the count of the pieces for a specific player
    return player_data[player_name].scout_count+ player_data[player_name].warrior_count+ player_data[player_name].wizard_count;
}

// two string paramters representing a player and certain piece
// returns an int representng the amount a player has of a certain piece
int GameState::NumPieces(string player_name, string piece_type)
{
    // checks the map for a valid player name, if not found returns 0
    if (player_data.find(player_name) != player_data.end())
    {
        // retuurns the count of a speific piece of a player, if type is not found returns 0
        if (piece_type == "Warrior")
        {
            return player_data[player_name].warrior_count;
        }
        else if (piece_type == "Scout")
        {
            return player_data[player_name].scout_count;
        }
        else if (piece_type == "Wizard")
        {
            return player_data[player_name].wizard_count;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

// one parameter being a const gamepiece reference
// adds a count to each of the pieces
void GameState::AddPiece(GamePiece &gp)
{
    // increments the piece count for a player
    if (gp.GetType() == "Warrior")
    {
        player_data[gp.GetPlayer()].warrior_count++;
    }
    else if (gp.GetType() == "Scout")
    {
        player_data[gp.GetPlayer()].scout_count++;
    }
    else if (gp.GetType() == "Wizard")
    {
        player_data[gp.GetPlayer()].wizard_count++;
    }
}

// two parameters being a string and player name
// adds a count to the piece of a player
void GameState::AddPiece(string player_name, string piece)
{
    // same as function above, overloaded to take 2 strings to use in assignment operator in the gamepiece.cpp file
    if (piece == "Warrior")
    {
        player_data[player_name].warrior_count++;
    }
    else if (piece == "Scout")
    {
        player_data[player_name].scout_count++;
    }
    else if (piece == "Wizard")
    {
        player_data[player_name].wizard_count++;
    }
}

// one parameter being a const gamepiece reference
// removes a count of a piece of a player
void GameState::RemovePiece(GamePiece &gp)
{
    // decrements the piece count for a player
    if (gp.GetType() == "Warrior")
    {
        player_data[gp.GetPlayer()].warrior_count--;
    }
    else if (gp.GetType() == "Scout")
    {
        player_data[gp.GetPlayer()].scout_count--;
    }
    else if (gp.GetType() == "Wizard")
    {
        player_data[gp.GetPlayer()].wizard_count--;
    }
}

// two parameters being a string and player name
// removes a count to the piece of a player
void GameState::RemovePiece(string player_name, string piece)
{
    // same as function above, overloaded to take 2 strings to use in assignment operator in the gamepiece.cpp file
    if (piece == "Warrior")
    {
        player_data[player_name].warrior_count--;
    }
    else if (piece == "Scout")
    {
        player_data[player_name].scout_count--;
    }
    else if (piece == "Wizard")
    {
        player_data[player_name].wizard_count--;
    }
}

// one parameter being a string of a player
// returns an int representng the wizard count of a certain player
int GameState::WizardCount(string player_name)
{
    // returns the wizard count for a specfic player
    return player_data[player_name].wizard_count;
}

// no parameters
// returns an int of all the current wizard pieces in the game
int GameState::TotalWizards()
{
    // loops through the map and adds only the wizard counts for every player to get total wizards present in the game
    int total_wizards;
    for (auto& [name, count] : player_data)
    {
        total_wizards += player_data[name].wizard_count;
    }
    return total_wizards;
}