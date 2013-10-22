#include"state.h"

std::queue<char (*)[STATE_LENGTH]> stateQueue;
std::queue<int> stateTotalQueue;
bool stateRepeat = false;
int totalStep = 1;
int nowStep = 1;

char (*nowState)[STATE_LENGTH] = &stateInit;

void pushState(char (*state)[STATE_LENGTH],int total) {
    stateQueue.push(state); 
    stateTotalQueue.push(total);
}

void popAllState() {
    while(!stateQueue.empty()) stateQueue.pop();
    while(!stateTotalQueue.empty()) stateTotalQueue.pop();
    totalStep = nowStep = 1;
    stateRepeat = false;
}

void getNowState() {
    int i;
    char (*nstate)[STATE_LENGTH];
    if(nowStep >= totalStep) {
        if(!stateQueue.empty()) {
            nstate = stateQueue.front();
            stateQueue.pop();
            nowStep = 0;
            totalStep = stateTotalQueue.front();
            stateTotalQueue.pop();

            if(stateRepeat) {
                stateQueue.push(nstate); 
                stateTotalQueue.push(totalStep);
            }
            
            nowState = nstate;
        }
    }
}
