#include "GamePiece.hpp"
#include "GameState.hpp"

// constructor
GamePiece::GamePiece(string player_name, string piece_type, GameState *current_game)
{
    player_name_ = player_name;
    piece_type_ = piece_type;
    current_game_ = current_game;
    // calls AddPiece function to add pieces to the game when the constructor is called
    current_game_->AddPiece(*this);
}

// copy constructor
GamePiece::GamePiece(GamePiece const &gp)
{
    player_name_ = gp.player_name_;
    piece_type_ = gp.piece_type_;
    current_game_ = gp.current_game_;
    current_game_->AddPiece(*this);
}

// member functions

// no paramaters, returns the player name
string GamePiece::GetPlayer()
{
    return player_name_;
}

// no parameters, returns piece type
string GamePiece::GetType()
{
    return piece_type_;
}

// no parameters
// returns an int for a certain piece type
int GamePiece::GetPower() const
{
    if (piece_type_ == "Warrior")
    {
        return 5;
    }
    else if (piece_type_ == "Scout")
    {
        return 1;
    }
    else if (piece_type_ == "Wizard")
    {
        // calls WizardCount function which gets the count of wizard pieces for a specific player
        return current_game_->WizardCount(player_name_);
    }
}

// no parameters
// returns an int for a ceratin piece type
int GamePiece::GetSpeed() const
{
    if (piece_type_ == "Warrior")
    {
        return 2;
    }
    else if (piece_type_ == "Scout")
    {
        return 8;
    }
    else if (piece_type_ == "Wizard")
    {
        // calls TotalWizard to calculate the amount of enemy wizards
        int total_wizards = current_game_->TotalWizards();
        int player_wizards = current_game_->WizardCount(this->player_name_);
        int speed_reduction = total_wizards - player_wizards;
        int wizard_speed = 12 - speed_reduction;
        if (speed_reduction >= 12)
        {
            return 1;
        }
        else
        {
            return wizard_speed;
        }
    }
}

// 6 Comparison Operators
// all take a const gamepiece reference

// parameters are constant gampiece refernce
// returns a bool based of if the power and speed are equal
bool GamePiece::operator==(GamePiece const &gp) const
{
    if (this->GetPower() == gp.GetPower() and this->GetSpeed() == gp.GetSpeed())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// parameters are constant gampiece reference
// returns true if the power and speed are not equal
bool GamePiece::operator!=(GamePiece const &gp) const
{
    if (this->GetPower() != gp.GetPower())
    {
        return true;
    }
    else if (this->GetPower() == gp.GetPower())
    {
        if (this->GetSpeed() != gp.GetSpeed())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// parameters are constant gampiece reference
// returns true if the power and speed are less than the other
bool GamePiece::operator<(GamePiece const &gp) const
{
    if (this->GetPower() < gp.GetPower())
    {
        return true;
    }
    else if (this->GetPower() == gp.GetPower())
    {
        if (this->GetSpeed() < gp.GetSpeed())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// parameters are constant gampiece reference
// returns true if the power and speed are grater than the other
bool GamePiece::operator>(GamePiece const &gp) const
{
    if (this->GetPower() > gp.GetPower())
    {
        return true;
    }
    else if (this->GetPower() == gp.GetPower())
    {
        if (this->GetSpeed() > gp.GetSpeed())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// parameters are constant gampiece reference
// returns true if the power and speed are less than or equal to the other
bool GamePiece::operator<=(GamePiece const &gp) const
{
    if (this->GetPower() == gp.GetPower() and this->GetSpeed() == gp.GetSpeed())
    {
        return true;
    }
    else if (this->GetPower() > gp.GetPower())
    {
        return false;
    }
    else
    {
        return true;
    }
}

// parameters are constant gampiece reference
// returns true if the power and speed are greather than or equal to the other
bool GamePiece::operator>=(GamePiece const &gp) const
{
    if (this->GetPower() == gp.GetPower() and this->GetSpeed() == gp.GetSpeed())
    {
        return true;
    }
    else if (this->GetPower() > gp.GetPower())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// operator=
GamePiece &GamePiece::operator=(GamePiece const &gp)
{
    // calls RemovePiece function to remove the current pieces of the game
    current_game_->RemovePiece(player_name_, piece_type_);

    player_name_ = gp.player_name_;
    piece_type_ = gp.piece_type_;
    current_game_ = gp.current_game_;

    // calls AddPiece to add in the new made pieces into the game
    current_game_->AddPiece(player_name_, piece_type_);

    return *this;
}

// operator<<
ostream &operator<<(ostream &out, GamePiece const &gp)
{
    out << "(" << gp.player_name_ << "," << gp.piece_type_ << "," << gp.GetPower() << "," << gp.GetSpeed() << ")";
    return out;
}

// destructor
GamePiece::~GamePiece()
{
    // calls RemovePiece to delete the pieces from the game
    current_game_->RemovePiece(*this);
}