#ifndef _ROTATION_H_
#define _ROTATION_H_

#include<GL/glut.h>
#include<GL/freeglut.h>

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

#endif
