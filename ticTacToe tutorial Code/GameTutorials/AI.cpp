#include "AI.h"

void AI::init(int aiPlayer) {
    _aiPlayer = aiPlayer;
    if (_aiPlayer == X_VAL) {
        _humanPlayer = O_VAL;
    } else {
        _humanPlayer = X_VAL;
    }
}

void AI::performMove(Board& board) {
   // TODO: Implement
}

