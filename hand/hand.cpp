#include<GL/glut.h>
#include<GL/freeglut.h>
#include<iostream>

#include"catGL.h"

void GLInit(void);
void handle_reshape(int w,int h);
void handle_draw(void);
void handle_keyboard(unsigned char key,int x,int y);
void handle_timer(int value);

int main(int argc, char *argv[]) {
    CGL_INIT_WINDOW(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH,
                    480,480,200,200,"Hand");

    glutReshapeFunc(handle_reshape);
    glutDisplayFunc(handle_draw);
    glutKeyboardFunc(handle_keyboard);
    glutIdleFunc(handle_draw);
    glutTimerFunc(10,handle_timer,0);
    
    GLInit();

    glutMainLoop();
    return 0;
}

void GLInit(void) {
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    // Lighting
    GLfloat diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat ambient[] = {0.25,0.25,0.25,1.0};
    GLfloat specular[] = {0,1.0,1.0,1.0};
    GLfloat pos[] = {100,1.0,1.0,1.0};
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
    glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,0.8);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
}

void handle_reshape(int w,int h) {
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


float fangle = 0;
float pos_x = 0,pos_y = 0,pos_z = 10;

const float BaseSize = 0.7f;
int NowState = 2, NextState = 2;
int TotalStep = 0,NowStep = 1;

GLfloat RotationArray[][3][3] = {
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0} }
};

GLfloat RotationDefinition[][3][3] = {
    //
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,0,-20},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,0,0},{0,0,0} },
    // 
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,0,0},{0,0,0} },
    // 
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0},{0,0,0} },
    { {0,0,0},{0,0,0} },
    // 
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,90,0},{0,90,0},{0,90,0} },
    { {0,0,-120},{0,0,-15} },
};

#define GET_ROTATION(_j) RotationArray[_j]

#define LEN_ROTARR 6
int calculateRotation() {
    if(NowState == NextState || NowStep > TotalStep) 
        return 0;

    int i,j,k;
    int now = NowState*LEN_ROTARR, next = NextState*LEN_ROTARR;
    GLfloat diff,ratio = (GLfloat)NowStep/(GLfloat)TotalStep;

    for(i=0;i<LEN_ROTARR;++i) {
        for(j=0;j<3;++j){
            for(k=0;k<3;++k){
                diff = (RotationDefinition[next+i][j][k]-RotationDefinition[now+i][j][k]);
                RotationArray[i][j][k] = RotationDefinition[now+i][j][k]+diff*ratio;
            } 
        } 
    }
    
    return 1;
}

void handle_timer(int value) {
    if(calculateRotation()) NowStep++;

    glutTimerFunc(10,handle_timer,0);
}

void drawArmJoint(GLfloat x, GLfloat y, GLfloat z) {
    glTranslatef(x,y,z);
    glPushMatrix();
    glColor3f(1,0,0);
    glScalef(0.5f,0.5f,0.3f);
    glutSolidSphere(BaseSize,15,15);
    glPopMatrix();
}

void drawFingerJoint(GLfloat x, GLfloat y, GLfloat z,
                     GLfloat size, GLfloat factor) {
    glTranslatef(factor*x, factor*y, factor*z);
    glPushMatrix();
    glColor3f(1,0,0);
    glScalef(factor*size, factor*size, 0.3f);
    glutSolidSphere(BaseSize,15,15);
    glPopMatrix();
}

void drawFingerComp(GLfloat x, GLfloat y, GLfloat z, 
                    GLfloat length, GLfloat height, GLfloat factor) {

    glTranslatef(factor*x, factor*y, factor*z);
    glPushMatrix();
    glColor3f(0,0,1);
    glScalef(factor*length, factor*height, 0.3f);
    glutSolidSphere(BaseSize,10,10);
    glPopMatrix();
}

void doRotation(GLfloat rotarr[3]) {
    glRotatef(rotarr[0],1,0,0); 
    glRotatef(rotarr[1],0,1,0); 
    glRotatef(rotarr[2],0,0,1); 
}

void drawFinger(GLfloat x, GLfloat y, GLfloat rotate, GLfloat factor,
                GLfloat rotarr[3][3]) {
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(rotate,0,0,1);

    // Finger Joint1
    drawFingerJoint(0,0,0,0.2f,factor);
    doRotation(rotarr[0]);
    
    drawFingerComp(-0.3f,0,0,0.5f,0.18f,factor);
    
    // Finger Joint2
    drawFingerJoint(-0.25f,0,0,0.15f,factor);
    doRotation(rotarr[1]);
    
    drawFingerComp(-0.25f,0,0,0.4f,0.16f,factor);
    
    // Finger Joint3
    drawFingerJoint(-0.25f,0,0,0.15f,factor);
    doRotation(rotarr[2]);
    
    drawFingerComp(-0.20f,0,0,0.3f,0.12f,factor);
    
    glPopMatrix();
}

void drawHand(void) {
    // Palm
    glTranslatef(-0.9f,0,0);
    glPushMatrix();
    glColor3f(0,0,1);
    glScalef(1.2f,1,0.3f);
    glutSolidSphere(BaseSize,15,15);
    glPopMatrix();
    
    // Fingers
    drawFinger( 0.12f,  0.7f, -20.0f, 0.80f, GET_ROTATION(0)); // big
    drawFinger(-0.55f,  0.4f,   0.0f, 0.95f, GET_ROTATION(1)); // index
    drawFinger(-0.75f,  0.0f,   0.0f, 1.00f, GET_ROTATION(2)); // center
    drawFinger(-0.60f, -0.4f,   0.0f, 0.95f, GET_ROTATION(3)); // noname
    drawFinger(-0.36f, -0.6f,  15.0f, 0.70f, GET_ROTATION(4)); // small
}

void drawArm(void) {
    glPushMatrix();
    
    // start point
    
    // Arm Upper
    glTranslatef(2.5f,0,0);
    glPushMatrix();
    glColor3f(0,0,1);
    glScalef(2.7f,0.9f,0.3f);
    glutSolidCube(BaseSize);
    glPopMatrix();
    
    // Arm Joint1
    drawArmJoint(-1,0,0);
    doRotation(GET_ROTATION(5)[0]);
    //glRotatef(-30,0,0,1);
    
    // Arm Lower
    glTranslatef(-1.0f,0,0);
    glPushMatrix();
    glColor3f(0,0,1);
    glScalef(2.7f,0.9f,0.3f);
    glutSolidCube(BaseSize);
    glPopMatrix();

    // Arm Joint2
    drawArmJoint(-1,0,0);
    doRotation(GET_ROTATION(5)[1]);

    drawHand();
    
    glPopMatrix();
} 

void handle_draw(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Lighting
    GLfloat ambientColor[] = {0.2f,0.2f,0.2f,1.0f};
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientColor);
    
    // View
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    gluLookAt(pos_x,pos_y,pos_z,0,0,0,0,1,0);
    glRotatef(fangle,0,1,0);
    
    glPushMatrix(); // global rotation
    drawArm();
    glPopMatrix(); // pop global rotation

    glutSwapBuffers();
}

void changeState(int next,int steps) {
    if (NowStep > TotalStep) {
        if (NextState != next) {
            NowState = NextState;
            NextState = next;
            TotalStep = steps;
            NowStep = 0;
        }
    }
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
        
        case '1': changeState(0,50); break;
        case '2': changeState(1,50); break;
        case '3': changeState(2,50); break;
        case '4': changeState(3,50); break;

        case 'o': // zero
            fangle = 0;
            pos_x = 0;
            pos_y = 0;
            pos_z = 10;
            break;
    }
}
