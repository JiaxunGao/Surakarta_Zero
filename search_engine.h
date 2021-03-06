#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H
#include "ArrayList.h"
#include "chessboard.h"
#include "search_engine.h"
#include "Boardstack.h"
#include <iostream>
#include <climits>
#include <cmath>
#include <time.h>

#define tiny 1e-6

void generateData();

class MCTSNode{
public:
    double value;
    double travelNum;
    int subNum;
    MCTSNode *subMCTS;
    MCTSNode *parent;
    ArrayList moveList;
    MCTSNode();
};

class MCTS{
public:
    MCTS(Chessboard gameBoard);
    singleMove search(int currentPlayer);
    ~MCTS();
private:
    Chessboard gameBoard;
    Chessboard oriBoard;
    MCTSNode root;
    bool expand(MCTSNode *currentNode,int currentPlayer);
    int rollout(MCTSNode *currentNode,int currentPlayer);
    //int ran();
    void Backpropagation(MCTSNode *currentNode,int rolloutValue);
    void destory(MCTSNode *node);
    void fwrite();
};

#endif