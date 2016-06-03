#pragma once

#include "Board.h"

class AI {
public:
    // Initializes the AI player
    void init(int aiPlayer);
    // Performs the AI move
    void performMove(Board& board);
private:
    int _aiPlayer; ///< Index of the AI
    int _humanPlayer; ///< Index of the player
};

