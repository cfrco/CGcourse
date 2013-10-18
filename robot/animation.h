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

GLfloat gangnam_style1[JOINT_LENGTH][5] = {
    {},
    {},
    {},
    {},
    {},
    {},
    {},
    {50, 0, 15},
    {},
    {-45},
};


GLfloat gangnam_style3[JOINT_LENGTH][5] = {
    {},
    {},
    {-60},
    {80},
    {0, 0, -70},
    {70, 0, 20},
    {-50, 0, 15},
    {},
    {45},
    {},
};

GLfloat gangnam_style4[JOINT_LENGTH][5] = {
    {},
    {},
    {-75},
    {90, 0, 20},
    {0, 0, -90},
    {90, 0},
    {},
    {},
    {},
    {},
};

GLfloat gentle_man1[JOINT_LENGTH][5] = {
    {},
    {},
    {0, 0, 90},
    {0, 0, 90},
    {0, 0, 90},
    {0, 0, 90},
    {0, 0, 30},
    {0, 0, 30},
    {0, 0, -20},
    {0, 0, -20},
};

GLfloat gentle_man2[JOINT_LENGTH][5] = {
    {},
    {},
    {0, 0, 80},
    {0, 0, 80},
    {0, 0, 80},
    {0, 0, 80},
    {0, 0, 20},
    {0, 0, 20},
    {0, 0, -10},
    {0, 0, -10},
};

GLfloat HeadRotation[5] = {30};
////Gangnam style
GLfloat style_right_hand1[][5] = {
	{90, 0, 20},
	{90, 0, 40}
};

GLfloat style_right_hand2[][5] = {
	{90, -90, 20},
	{90, -180, 20},
	{90, -270, 20},
	{90, -360, 20},
	{90, 0, 20}
};

GLfloat style_left_hand1[][5] = {
	{-75},
	{-60}
};

GLfloat style_left_hand2[][5] = {
	{0, 0, -80},
	{0, 0, -60}
};

GLfloat style_left_leg1[][5] = {
	{-90, 0, 20},
	{0}
};

GLfloat style_left_leg2[][5] = {
	{90},
	{0}
};


GLfloat style_right_leg1[][5] = {
	{90, 0, 20},
	{0}
};

GLfloat style_right_leg2[][5] = {
	{-90, 0, 20},
	{0}
};
////Gangnam style
void Gangnam_style(joint_t *joints){
	pushRotation(&joints[JOINT_ARM_RIGHT1], &style_right_hand1[0],20);
    
	pushRotation(&joints[JOINT_ARM_RIGHT2], &style_right_hand2[0],10);
    pushRotation(&joints[JOINT_ARM_RIGHT2], &style_right_hand2[1],10);
    
	pushRotation(&joints[JOINT_ARM_RIGHT1], &style_right_hand1[1],20);
    
	pushRotation(&joints[JOINT_ARM_RIGHT2], &style_right_hand2[2],10);
    pushRotation(&joints[JOINT_ARM_RIGHT2], &style_right_hand2[3],10);
    pushRotation(&joints[JOINT_ARM_RIGHT2], &style_right_hand2[4],1);
    
	pushRotation(&joints[JOINT_ARM_LEFT1], &style_left_hand1[0],20);
    pushRotation(&joints[JOINT_ARM_LEFT1], &style_left_hand1[1],20);
    pushRotation(&joints[JOINT_ARM_LEFT2], &style_left_hand2[0],20);
    pushRotation(&joints[JOINT_ARM_LEFT2], &style_left_hand2[1],20);
	
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[0],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[0],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[0],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT1], &style_left_leg1[1],20);
    
	pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[0],20);
    pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[1],20);
	pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[0],20);
    pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[1],20);
	pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[0],20);
    pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_LEFT2], &style_left_leg2[1],20);
	
	
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[0],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[0],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[0],20);
    pushRotation(&joints[JOINT_LEG_RIGHT1], &style_right_leg1[1],20);
    
	pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
	pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[0],20);
    pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
	pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
	pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
	pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[0],20);
    pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
	pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[0],20);
    pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);


}
