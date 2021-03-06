#include<GL/glut.h>
#include<GL/freeglut.h>

#include<queue>
#include<iostream>

#include"catGL.h"
#include"rotation.h"
#include"state.h"
#include"animation.h"
#include"menu.h"


void GLInit(void);
void GLMenu(void);
void handle_reshape(int w,int h);
void handle_draw(void);
void handle_keyboard(unsigned char key,int x,int y);
void handle_timer(int value);

void drawBodyCone(int mod);
void drawCone();
float MoveCone(int s);
void drawBall(int s);

// parameters
float fangle = 0;
float pos_x = 0,pos_y = 5,pos_z = 10;
joint_t joints[JOINT_LENGTH];

int main(int argc, char *argv[]) {
    CGL_INIT_WINDOW(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH,
                    480,640,200,200,"Robot");

    glutReshapeFunc(handle_reshape);
    glutDisplayFunc(handle_draw);
    glutKeyboardFunc(handle_keyboard);
    glutTimerFunc(10,handle_timer,0);
    glutIdleFunc(handle_draw);
    
    jointInit(joints,JOINT_LENGTH);
    GLInit();
    GLMenu();

    glutMainLoop();
    return 0;
}

//char attackState = 0;

void GLInit(void) {
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    
    // Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}

void handle_menu(int menu) {
    switch(menu) {
        case ME_EXIT : exit(0); break;
        
        // View
        case ME_VIEW_SOLID : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break;
        case ME_VIEW_LINE  : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break;

        // Main
        case ME_WALK :
            popAllState();
            clearState(joints);
            pushFullState(joints,&aniWalkRotation1,50);
            pushFullState(joints,&aniWalkRotation2,50);
            repeatAll(joints,true);
        break;
        case ME_RUN :
            popAllState();
            clearState(joints);
            run(joints);
            repeatAll(joints,true);
        break;

        // Dance
        case ME_DANCE_GANSTYLE1 :
            popAllState();
            clearState(joints);
            Gangnam_style(joints);
            repeatAll(joints,true);
        break;
        case ME_DANCE_GANSTYLE2 :
            popAllState();
            clearState(joints);
            Gangnam_style2(joints);
            repeatAll(joints,true);
        break;
        
        // Action
        case ME_ACTION_PUSHUP :
            popAllState();
            clearState(joints);
            pushup(joints);
            repeatAll(joints,true);
        break;
        case ME_ACTION_ATTACK1 :
            popAllState(); //state
            pushState(&stateFire, 10);
            stateRepeat = true;
            clearState(joints); //rotation
            attack1(joints);
            repeatAll(joints,true);
        break;
        case ME_ACTION_ATTACK2 :
            popAllState(); //state
            pushState(&stateFireBall, 240);
            pushState(&stateAttack, 20);
            stateRepeat = true;
            drawBall(0); // animation init
            clearState(joints); // rotation
            attack3(joints);
            repeatAll(joints,true);
        break;	
        case ME_ACTION_ATTACK3 :
            popAllState(); //state
            pushState(&stateRunFire, 10);
            stateRepeat = true;
            MoveCone(0); // animation init
            clearState(joints); //rotation
            attack2(joints);
            repeatAll(joints,true);
        break;
        case ME_ACTION_SUPER :
            popAllState();
            pushState(&super_state2,10);
            pushState(&super_state1,10);
            stateRepeat = true;
            drawBodyCone(0);

            clearState(joints);
            super_mode(joints);
            joints[JOINT_BODY].repeat = true;
        break;

        // Equipment
        case ME_EQU_CONE :
            if(nowState != &stateAttack) {
                popAllState();
                pushState(&stateAttack,10);
            }
            else popAllState();
            stateRepeat = true;
        break;
    } 
}

void handle_reshape(int w,int h) {
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void handle_keyboard(unsigned char key,int x,int y) {
    switch(key) {
        // moving camera
        case 'l': fangle -= 5; break;
        case 'h': fangle += 5; break;
        
        case 'k': pos_y += 1; break;
        case 'j': pos_y -= 1; break;
         
        case 'd': pos_x += 1; break;
        case 'a': pos_x -= 1; break;
        case 'w': pos_z -= 1; break;
        case 's': pos_z += 1; break;

        case 'o': // zero
            fangle = 0;
            pos_x = 0;
            pos_y = 5;
            pos_z = 10;
            break;

        case 'p':
            stopAll(joints);
            break;
    }
}

void handle_timer(int value) {
    int i;
    for(i=0;i<JOINT_LENGTH;++i)
        calculateRotation(&joints[i]);

    getNowState();
    glutTimerFunc(10,handle_timer,0);
}

void drawRobotHead() {
    glPushMatrix();
    
    // position
    glTranslatef(0,2.5,0); 
    
    // rotation
    DoRotate(joints[JOINT_HEAD].rotation);

    // Head
    glColor3f(0,0.2f,0.8f);
    glutSolidCube(0.8f);
    
    // Decoration
    glColor3f(0.8f,0,0.2f);
    glPushMatrix();
    glTranslatef(0.35,0.15f,0);
    glRotatef(90,0,1,0);
    glRotatef(-30,1,0,0);
    glutSolidCone(0.1f,0.4f,20,3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.35f,0.15f,0);
    glRotatef(-90,0,1,0);
    glRotatef(-30,1,0,0);
    glutSolidCone(0.1f,0.4f,20,3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0.2f,0);
    glRotatef(-90,1,0,0);
    glutSolidCone(0.2f,0.5f,20,3);
    glPopMatrix();
    
    // Eye
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-0.18f,0.08f,0.35f);
    glutSolidSphere(0.1f,10,10);
    glTranslatef(0.18f*2,0,0);
    glutSolidSphere(0.1f,10,10);
    glPopMatrix();

    // Mouth
    glColor3f(0.8f,0.8f,0);
    glPushMatrix();
    glTranslatef(0,-0.25f,0.44f);
    glRotatef(180,0,1,0);
    glRotatef(90,0,0,1);
    glutSolidCone(0.1f,0.4f,3,3);
    glPopMatrix();
    
    glPopMatrix();
}

// mod = 0 do init
void drawBodyCone(int mod) {
    static float size = 0;
    static float cysize = 0;
    if(mod == 0) {
        size = 0; 
        cysize = 0;
    } else {
        glPushMatrix();
        glutSolidCone(0.7f,size,20,5);

        if(size < 2.0f) size += 0.05f;
        else {
            glColor4f(0.9f,0.9f,0.2f,0.8f);
            glTranslatef(0,0,1.0f);
            glutSolidCylinder(cysize,10,20,30); 
            if(cysize < 0.7f) cysize += 0.07f;
        }
                 
        glPopMatrix();
    }
}

void drawRobotBody() {
    glPushMatrix();

    glTranslatef(0,1.15f,0); 

    glColor3f(0.1f,0.2f,0.8f);
    glPushMatrix();
    glScalef(2,2.2f,0.8f);
    glutSolidCube(0.8f);
    glPopMatrix();
    
    glColor3f(0.8f,0,0.2f);
    glPushMatrix();
    glTranslatef(0,1,0); 
    glScalef(0.5f,2.0f,0.5f);
    glutSolidCube(0.4f);
    glPopMatrix();
    
    if((*nowState)[STATE_BODY_CONE])
        drawBodyCone(1);
    
    glPopMatrix();
}

void drawRobotArm(float factor) {
    glPushMatrix();
    glRotatef(factor,0,1,0);
    glTranslatef(0.9f,2.0f,0); 

    glColor3f(0.4f,0,0.2f);
    glPushMatrix();
    glRotatef(25,0,0,1);
    glScalef(0.5f,0.2f,0.2f);
    glutSolidIcosahedron();
    glPopMatrix();
    
    // Joint1
    glColor3f(0.1f,0.1f,0.1f);
    glTranslatef(0.1f,-0.15f,0); 
    glPushMatrix();
    glScalef(0.12f,0.12f,0.12f);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    
    // Joint1 rotation
    if(factor>=0) DoRotate(joints[JOINT_ARM_LEFT1].rotation);
    else DoRotate(joints[JOINT_ARM_RIGHT1].rotation);

    // Upper
    glColor3f(0.1f,0.2f,0.8f);
    glTranslatef(0.15f,-0.5f,0); 
    glPushMatrix();
    glRotatef(15,0,0,1);
    glScalef(1,2.2f,1);
    glutSolidCube(0.4f);
    glPopMatrix();
	
    // Joint2
    glColor3f(0.1f,0.1f,0.1f);
    glTranslatef(0.15f,-0.45f,0);
    glPushMatrix();
    glScalef(0.12f,0.12f,0.12f);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    
    // Joint2 rotation
    if(factor>=0) DoRotate(joints[JOINT_ARM_LEFT2].rotation);
    else DoRotate(joints[JOINT_ARM_RIGHT2].rotation);
  
    // Lower
    glColor3f(0.1f,0.2f,0.8f);
    glTranslatef(0.03f,-0.5f,0); 
    glPushMatrix();
    glScalef(1,2.2f,1);
    glutSolidCube(0.4f);
    glPopMatrix();

    // Hand
    glColor3f(0,0.2f,0.8f);
    glTranslatef(0.02f,-0.59f,0);
    glPushMatrix();
    glScalef(0.12f,0.12f,0.12f);
    glutSolidSphere(2.0f,10,10);
    glPopMatrix();

    if((*nowState)[STATE_ATTACK_CONE]) 
        drawCone();

    if((*nowState)[STATE_FIRE]) {
        glPushMatrix();
        glTranslatef(0, -MoveCone(40), 0);
        drawCone();
        glPopMatrix();
    }
	
    if((*nowState)[STATE_RUN_FIRE] && factor == -180.0f) {
        glPushMatrix();
        glTranslatef(0, -MoveCone(20), 0);
    	drawCone();
        glPopMatrix();
    }

    if((*nowState)[STATE_FIRE_BALL] && factor == -180.0f) {
        drawBall(240);
    }

    glPopMatrix();
}


void drawRobotPelvis() {
    glPushMatrix();
    glColor3f(0.5f,0.5f,0);
    glTranslatef(0,0.2f,0); 
    glScalef(1.3f,1,1);
    glutSolidCube(0.5f);
    glPopMatrix();
}

void drawRobotLeg(float factor) {
    glPushMatrix();
    glRotatef(factor,0,1,0);
    glTranslatef(0,0.05f,0); 

    // Joint1
    glColor3f(0.1f,0.1f,0.1f);
    glTranslatef(0.4f,0,0); 
    glPushMatrix();
    glScalef(0.12f,0.12f,0.12f);
    glutSolidSphere(1.3f,10,10);
    glPopMatrix();
    
    // Joint1 rotation
    if(factor>=0) DoRotate(joints[JOINT_LEG_LEFT1].rotation);
    else DoRotate(joints[JOINT_LEG_RIGHT1].rotation);

    // Upper
    glColor3f(0.1f,0.2f,0.8f);
    glTranslatef(0.15f,-0.6f,0); 
    glPushMatrix();
    glRotatef(15,0,0,1);
    glScalef(1,3.0f,1);
    glutSolidCube(0.32f);
    glPopMatrix();
    
    // Joint2
    glTranslatef(0.1f,-0.4f,0); 
    
    // Joint2 rotation
    if(factor>=0) DoRotate(joints[JOINT_LEG_LEFT2].rotation);
    else DoRotate(joints[JOINT_LEG_RIGHT2].rotation);

    // Lower
    glTranslatef(-0.01f,-1.4f,0);
    glPushMatrix();
    glRotatef(-90,1,0,0);
    glutSolidCylinder(0.3f,1.5f,20,5);
    glPopMatrix();
    
    // Foot
    glColor3f(0.2,0.6f,0.3f);
    glTranslatef(0.01f,-0.3f,0);
    glPushMatrix();
    if(factor < 0) {
        glTranslatef(0,0,-0.05f);
        glRotatef(180+85,1,0,0);
    } else {
        glTranslatef(0,0,0.05f);
        glRotatef(-85,1,0,0);
    }
    glutSolidCone(0.5f,1.0f,20,3);
    glPopMatrix();

    glPopMatrix();
}

void drawRobot() {
    glPushMatrix();
    DoRotate(joints[JOINT_BODY].rotation);
    
    drawRobotHead();
    drawRobotBody();
    drawRobotArm(0);
    drawRobotArm(-180);
    
    drawRobotPelvis();
    drawRobotLeg(0);
    drawRobotLeg(-180);
    
    glPopMatrix();
}

void background_color() {
    if((*nowState)[STATE_BACKGROUND] == 0) {
        glClearColor(0.0f,0.0f,0.0f,1.0f);
    } else {
        glClearColor(1.0f,1.0f,1.0f,1.0f);
    }
}

void handle_draw() {
    background_color();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    GLfloat ambientColor[] = {0.2f,0.2f,0.2f,1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientColor);

    gluLookAt(pos_x,pos_y,pos_z,0,0,0,0,1,0);
    glRotatef(fangle,0,1,0);
    
    glPushMatrix(); // global rotation
    drawRobot();
    glPopMatrix(); // pop global rotation

    glutSwapBuffers();
}

void drawCone(){
    glColor3f(0,0.2f,0.8f);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glutSolidCone(0.3f,1.0f,10,10);
    glPopMatrix();
    
    glColor3f(1, 1, 0);
    int ang;
    for(ang=0;ang<=270;ang+=90) {
        glRotatef(ang, 0, 1, 0);
        glPushMatrix();
        glRotatef(45, 1, 0, 0);
        glScalef(0.5, 0.5, 0.5);
        glutSolidCone(0.3f, 1.0f, 10, 10);
        glPopMatrix();
    }
}

float MoveCone(int s){
    static float move_amt;
    static int count;
    //initialize
    if(s == 0 || count >= s){
        count = 0;
        move_amt = 0.0f;
    }
    else{	
        count++;
        move_amt += 0.2f;
    }
    return move_amt;
}

void drawBall(int s){
    static float size;
    static int count;
    static float sht_amt;

    if(s == 0 || count >= s) {
        count = 0;
        size = 0.1f;
        sht_amt = 0.0f;
    } else {
        count++;
        glPushMatrix();
                
        if(count >= s - 15) {
            sht_amt += 1.0f;
            glTranslatef(1.4 * size, -1.4, sht_amt);
        } else {
            size += 0.01f;
            glTranslatef(1.4 * size, -1.4, 0);
        }
        glColor3f(1, 0, 0);
        glutSolidSphere(size, 30.0, 30.0);
        glPopMatrix();
    }
}
