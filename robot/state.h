#ifndef _STATE_H_
#define _STATE_H_

#include<queue>

enum Sate {
    STATE_ATTACK_CONE,
    STATE_BACKGROUND,
    STATE_BODY_CONE,
    STATE_FIRE,
    STATE_RUN_FIRE,
    STATE_FIRE_BALL,
    STATE_LENGTH
};

extern bool stateRepeat;

void pushState(char (*state)[STATE_LENGTH],int total);
void popAllState();
void getNowState();

static char stateInit[STATE_LENGTH] = {};
static char stateAttack[STATE_LENGTH] = {1};
static char stateFire[STATE_LENGTH] = {1, 0, 0, 1};
static char stateRunFire[STATE_LENGTH] = {1, 0, 0, 0, 1};
static char stateFireBall[STATE_LENGTH] = {1, 0, 0, 0, 0, 1};
extern char (*nowState)[STATE_LENGTH];

#endif
