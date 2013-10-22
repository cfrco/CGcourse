#ifndef _STATE_H_
#define _STATE_H_

#include<queue>

enum Sate {
    STATE_ATTACK_CONE,
    STATE_LENGTH
};

//extern std::queue<char (*)[STATE_LENGTH]> stateQueue;
//extern std::queue<int> stateTotalQueue;
extern bool stateRepeat;

void pushState(char (*state)[STATE_LENGTH],int total);
void popAllState();
void getNowState();

static char stateInit[STATE_LENGTH] = {};
static char stateAttack[STATE_LENGTH] = {1};
extern char (*nowState)[STATE_LENGTH];

#endif
