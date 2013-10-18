#include "rotation.h"

void DoRotate(GLfloat rots[]) {
    glRotatef(rots[0],1,0,0);
    glRotatef(rots[1],0,1,0);
    glRotatef(rots[2],0,0,1);
    glRotatef(rots[3],0,1,0);
    glRotatef(rots[4],1,0,0);
}

void jointInit(joint_t *joints,int len) {
    int i;
    for(i=0;i<len;++i) {
        joints[i].now  = &initRotation; 
        joints[i].next = &initRotation; 
        joints[i].nowStep = joints[i].totalStep = 0;
    }
}

void calculateRotation(joint_t *joint) {
    if(!(joint->next == NULL || 
         joint->now == joint->next || 
         joint->nowStep > joint->totalStep))
    {
        int i;
        GLfloat diff,ratio = (GLfloat)joint->nowStep/(GLfloat)joint->totalStep;
        for(i=0;i<5;++i){
            diff = (*joint->next)[i]-(*joint->now)[i];
            joint->rotation[i] = (*joint->now)[i]+diff*ratio;
        } 

        joint->nowStep++;
    }
    if(joint->nowStep >= joint->totalStep) joint->now = joint->next;
    
    if(joint->now == joint->next) {
        if(!joint->rqueue.empty()) {
            GLfloat (*rp)[5] = joint->rqueue.front();
            joint->next = rp;
            joint->totalStep = joint->tqueue.front();
            joint->rqueue.pop();
            joint->tqueue.pop();
            joint->nowStep = 0;
        }
    }
}

void pushRotation(joint_t *joint,GLfloat (*state)[5],int total) {
    joint->rqueue.push(state);
    joint->tqueue.push(total);
}

void popAll(joint_t *joints) {
    int i;
    for(i=0;i<JOINT_LENGTH;++i) {
        while(!joints[i].rqueue.empty()) joints[i].rqueue.pop();
        while(!joints[i].tqueue.empty()) joints[i].tqueue.pop();
    }
}

void pushFullState(joint_t *joints,GLfloat (*rotations)[JOINT_LENGTH][5],
                   int total) {
    int i;
    for(i=0;i<JOINT_LENGTH;++i) {
        joints[i].rqueue.push(&(*rotations)[i]);
        joints[i].tqueue.push(total);
    }
}
