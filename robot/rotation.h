#ifndef _ROTATION_H_
#define _ROTATION_H_

#include<GL/glut.h>
#include<GL/freeglut.h>

#include<queue>

void DoRotate(GLfloat rots[5]);

enum eJoint {
    JOINT_BODY,
    JOINT_HEAD,
    JOINT_ARM_LEFT1,
    JOINT_ARM_RIGHT1,
    JOINT_ARM_LEFT2,
    JOINT_ARM_RIGHT2,
    JOINT_LEG_LEFT1,
    JOINT_LEG_RIGHT1,
    JOINT_LEG_LEFT2,
    JOINT_LEG_RIGHT2,
    JOINT_LENGTH
};

typedef struct joint{
    int nowStep,totalStep; 
    GLfloat rotation[5];
    GLfloat (*now)[5];
    GLfloat (*next)[5];
    std::queue<GLfloat (*)[5]> rqueue;
    std::queue<int> tqueue;
    bool repeat;
}joint_t;

void jointInit(joint_t *joints,int len);

static GLfloat initRotation[5] = {};
static GLfloat initFullRotation[JOINT_LENGTH][5] = {};
void calculateRotation(joint_t *joint);

void pushRotation(joint_t *joint,GLfloat (*state)[5],int total);
void pushRotationIndex(joint_t *joint,GLfloat (*state)[5],
                       int index[],int len,int total);
void pushRotationList(joint_t *joint,GLfloat (*state)[5],
                      int len,int total);

void clearState(joint_t *joints);
void popAll(joint_t *joints);
void pushFullState(joint_t *joints,GLfloat (*rotations)[JOINT_LENGTH][5],int total);

void repeatAll(joint_t *joints,bool rep);
void stopAll(joint_t *joints);
#endif
