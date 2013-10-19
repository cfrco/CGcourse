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
	for(int i = 0;i < 8;i++){
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
	}
		
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
	pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
    pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
	pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[0],20);
    pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
	pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[0],20);
    pushRotation(&joints[JOINT_LEG_RIGHT2], &style_right_leg2[1],20);
}

////pushup
GLfloat pushup_right_hand1[][5] = {
	{90, 0, 90},
	{90, 0, 0}
};

GLfloat pushup_right_hand2[][5] = {
	{0, 0, -90},
	{0, 0, 0}
};

GLfloat pushup_left_hand1[][5] = {
	{-90, 0, 90},
	{-90, 0, 0}
};

GLfloat pushup_left_hand2[][5] = {
	{0, 0, -90},
	{0, 0, 0}
};

GLfloat pushup_body[][5] = {
	{90, 0, 0},
	{50, 0, 0}
};
////pushup
void pushup(joint_t *joints){
    pushRotation(&joints[JOINT_BODY], &pushup_body[1],40);
    
    pushRotation(&joints[JOINT_BODY], &pushup_body[0],40);

	pushRotation(&joints[JOINT_ARM_RIGHT1], &pushup_right_hand1[1],40);
    pushRotation(&joints[JOINT_ARM_RIGHT1], &pushup_right_hand1[0],40);
    
	pushRotation(&joints[JOINT_ARM_RIGHT2], &pushup_right_hand2[1],40);
    pushRotation(&joints[JOINT_ARM_RIGHT2], &pushup_right_hand2[0],40);

    pushRotation(&joints[JOINT_ARM_LEFT1], &pushup_left_hand1[1],40);
    pushRotation(&joints[JOINT_ARM_LEFT1], &pushup_left_hand1[0],40);
	
	pushRotation(&joints[JOINT_ARM_LEFT2], &pushup_left_hand2[1],40);
    pushRotation(&joints[JOINT_ARM_LEFT2], &pushup_left_hand2[0],40);
}

////run
GLfloat run_rotation1[JOINT_LENGTH][5] = {
    {5},
    {},
    {-45},
    {-45},
    {-90},
    {90},
    {30},
    {60},
    {45},
    {-45},
};

GLfloat run_rotation2[JOINT_LENGTH][5] = {
    {-5},
    {},
    {45},
    {45},
    {-90},
    {90},
    {-60},
    {-30},
    {45},
    {-45},
};

////run
void run(joint_t *joints){
	pushFullState(joints,&run_rotation1,20);
	pushFullState(joints,&run_rotation2,20);
}

////attack1
GLfloat attack1_rotation1[JOINT_LENGTH][5] = {
    {},
    {},
    {-90, 0, -20},
    {0, 0, -20},
    {0, 0, 15},
    {90, 0, 15},
    {},
    {},
    {},
    {}
};

GLfloat attack1_rotation2[JOINT_LENGTH][5] = {
    {},
    {},
    {0, 0, -20},
    {90, 0, -20},
    {-90, 0, 15},
    {0, 0, 15},
    {},
    {},
    {},
    {}
};
////attack1
void attack1(joint_t *joints){
	pushFullState(joints,&attack1_rotation1,20);
	pushFullState(joints,&attack1_rotation2,20);
}
