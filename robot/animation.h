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

static void Gangnam_style(joint_t *joints){
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

// Gangnam style2
GLfloat style2_1[JOINT_LENGTH][5] = {
    {0, 0, 5},
    {-30, -70},
    {0, 0, 35},
    {0, 0, 35},
    {0, 0, -80},
    {0, 0, -80},
    {0, 0, 20},
    {},
    {0, 0, 40},
    {},
};

GLfloat style2_2[JOINT_LENGTH][5] = {
    {0, 0, -5},
    {-30, -70},
    {0, 0, 30},
    {0, 0, 30},
    {0, 0, -75},
    {0, 0, -75},
    {},
    {0, 0, 20},
    {},
    {0, 0, 40},
};

GLfloat style2_3[JOINT_LENGTH][5] = {
    {},
    {},
    {0, 0, 35},
    {0, 0, 35},
    {0, 0, -80},
    {0, 0, -80},
    {},
    {},
    {},
    {},
};

GLfloat style2_4[JOINT_LENGTH][5] = {
    {-5},
    {-5},
    {-60, 90, -30},
    {60, 90},
    {80},
    {80},
    {-50, 0, 30},
    {},
    {60},
    {},
};

GLfloat style2_5[JOINT_LENGTH][5] = {
    {-5},
    {-5},
    {-60, 90, -30},
    {60, 90},
    {80},
    {80},
    {},
    {50, 0, 30},
    {},
    {-60},
};

GLfloat style2_6[JOINT_LENGTH][5] = {
    {5},
    {5},
    {-40, 90, -30},
    {40, 90},
    {60},
    {60},
    {},
    {},
    {},
    {},
};

static void Gangnam_style2(joint_t *joints){
    for(int i = 0; i < 6;i++) {
        pushFullState(joints,&style2_1,15);
        pushFullState(joints,&style2_2,15);
    }

    pushFullState(joints,&style2_3,60);
    
    pushFullState(joints,&style2_4,15);
    pushFullState(joints,&style2_6,15);
    pushFullState(joints,&style2_5,15);
    pushFullState(joints,&style2_6,15);
    pushFullState(joints,&style2_4,15);
    pushFullState(joints,&style2_6,15);
    pushFullState(joints,&style2_4,15);
    pushFullState(joints,&style2_6,15);
    pushFullState(joints,&style2_5,15);
    pushFullState(joints,&style2_6,15);
    pushFullState(joints,&style2_4,15);
    pushFullState(joints,&style2_6,15);
    pushFullState(joints,&style2_5,15);
    pushFullState(joints,&style2_6,20);
    pushFullState(joints,&style2_5,20);
    pushFullState(joints,&style2_6,20);
}

// pushup
GLfloat pushup_right_hand1[][5] = { {90, 0, 90}, {90, 0, 0} };
GLfloat pushup_right_hand2[][5] = { {0, 0, -90}, {0, 0, 0} };
GLfloat pushup_left_hand1[][5] = { {-90, 0, 90}, {-90, 0, 0} };
GLfloat pushup_left_hand2[][5] = { {0, 0, -90}, {0, 0, 0} };
GLfloat pushup_body[][5] = { {90, 0, 0}, {50, 0, 0} };

static void pushup(joint_t *joints){
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

// run
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

static void run(joint_t *joints) {
    pushFullState(joints,&run_rotation1,20);
    pushFullState(joints,&run_rotation2,20);
}

// attack1
GLfloat attack1_rotation1[JOINT_LENGTH][5] = {
    {1},
    {0, 1},
    {-45, 0, -20},
    {45, 0, -20},
    {-80, 0},
    {80, 0},
    {0, 0, 30},
    {0, 0, 30},
    {0, 0, -20},
    {0, 0, -20}
};

GLfloat attack1_rotation2[JOINT_LENGTH][5] = {
    {},
    {0, -1},
    {-45, 0, -20},
    {45, 0, -20},
    {-80, 360},
    {80, 360},
    {0, 0, 30},
    {0, 0, 30},
    {0, 0, -20},
    {0, 0, -20}
};

static void attack1(joint_t *joints) {
    pushFullState(joints,&attack1_rotation1,10);
    pushFullState(joints,&attack1_rotation2,10);
}

// attack2
GLfloat attack2_rotation1[JOINT_LENGTH][5] = {
    {-2},
    {-2},
    {-90, 0, -40},
    {90, 0, -10},
    {0, 0, -50},
    {},
    {30},
    {60},
    {45},
    {-45}
};

GLfloat attack2_rotation2[JOINT_LENGTH][5] = {
    {2},
    {2},
    {-90, 0, -35},
    {90, 0, -10},
    {0, 0, -50},
    {0, 360},
    {-60},
    {-30},
    {45},
    {-45}
};

static void attack2(joint_t *joints) {
    pushFullState(joints,&attack2_rotation1,15);
    pushFullState(joints,&attack2_rotation2,15);
}

// attack 3
GLfloat attack3_rotation1[JOINT_LENGTH][5] = {
    {10},
    {10},
    {-40, 0, -10},
    {40, 0, -10},
    {0, 0, -10},
    {0, 0, -10},
    {-12, 0, 10},
    {12, 0, 10},
    {0, 0, -10},
    {0, 0, -10}
};

GLfloat attack3_rotation2[JOINT_LENGTH][5] = {
    {-10},
    {-10},
    {-160, 0, 30},
    {160, 0, 30},
    {},
    {},
    {12, 0, 10},
    {-12, 0, 10},
    {0, 0, -10},
    {0, 0, -10}
};

GLfloat attack3_rotation3[JOINT_LENGTH][5] = {
    {30},
    {15},
    {-10, 0, 30},
    {10, 0, 30},
    {},
    {},
    {-20, 0, 20},
    {60, 0, 20},
    {20, 0, -20},
    {-40, 0, -20}
};

static void attack3(joint_t *joints) {
    pushFullState(joints,&attack3_rotation1,20);
    pushFullState(joints,&attack3_rotation2,200);
    pushFullState(joints,&attack3_rotation3,20);
    pushFullState(joints,&attack3_rotation3,20);
}

// SuperMode
char super_state1[STATE_LENGTH] = {0,0,1};
char super_state2[STATE_LENGTH] = {0,1,1};
char super_cone_state[STATE_LENGTH] = {};
GLfloat super_rotation[JOINT_LENGTH][5] = {
    {0, 0, 180},
    {},
    {0, 0, 80},
    {0, 0, 80},
    {0, 0, 15},
    {0, 0, 15},
    {0, 0, 30},
    {0, 0, 30},
    {},
    {},
};
GLfloat super_body_rotation[][5] = { {0, 0, 360},{0, 0, 0} };

static void super_mode(joint_t *joints) {
    pushFullState(joints,&super_rotation,25);
    pushRotation(&joints[JOINT_BODY],&(super_body_rotation[0]),25);
    pushRotation(&joints[JOINT_BODY],&(super_body_rotation[1]),0);
}
