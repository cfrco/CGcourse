#include"rotation.h"

GLfloat aniWalkRotation1[JOINT_LENGTH][5] = {
    {},
    {},
    {15},
    {15},
    {},
    {},
    {-30},
    {-15},
    {40},
    {},
};

GLfloat aniWalkRotation2[JOINT_LENGTH][5] = {
    {},
    {},
    {-15},
    {-15},
    {},
    {},
    {15},
    {30},
    {},
    {-40},
};

GLfloat HeadRotation[5] = {30};

// Gangnam style
GLfloat style_right_hand1[][5] = { {90, 0, 20}, {90, 0, 40} };
GLfloat style_right_hand2[][5] = {
    {90, -90, 20}, {90, -180, 20}, {90, -270, 20},
    {90, -360, 20}, {90, 0, 20} };
GLfloat style_left_hand1[][5] = { {-75}, {-60} };
GLfloat style_left_hand2[][5] = { {0, 0, -80}, {0, 0, -60} };
GLfloat style_left_leg1[][5] = { {-90, 0, 20}, {} };
GLfloat style_left_leg2[][5] = { {90}, {} };
GLfloat style_right_leg1[][5] = { {90, 0, 20}, {} };
GLfloat style_right_leg2[][5] = { {-90, 0, 20}, {} };

void Gangnam_style(joint_t *joints){
    for(int i=0;i<8;i++) {
        pushRotationList(&joints[JOINT_ARM_RIGHT1], style_right_hand1, 2, 20);
        
        pushRotationList(&joints[JOINT_ARM_RIGHT2], style_right_hand2, 4, 10);
        pushRotation(&joints[JOINT_ARM_RIGHT2], &style_right_hand2[4],1);
        
        pushRotationList(&joints[JOINT_ARM_LEFT1], style_left_hand1, 2, 20);
        pushRotationList(&joints[JOINT_ARM_LEFT2], style_left_hand2, 2, 20);
    }
    
    int leg_index1[] = {0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1};
    pushRotationIndex(&joints[JOINT_LEG_LEFT1], style_left_leg1,
                      leg_index1, sizeof(leg_index1)/4,20);
    pushRotationIndex(&joints[JOINT_LEG_LEFT2], style_left_leg2,
                      leg_index1, sizeof(leg_index1)/4,20);
	
    int leg_index2[] = {1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1};
    pushRotationIndex(&joints[JOINT_LEG_RIGHT1], style_right_leg1,
                      leg_index2, sizeof(leg_index2)/4,20);
    pushRotationIndex(&joints[JOINT_LEG_RIGHT2], style_right_leg2,
                      leg_index2, sizeof(leg_index2)/4,20);
}
