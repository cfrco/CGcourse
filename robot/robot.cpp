#include<GL/glut.h>
#include<GL/freeglut.h>

#include"catGL.h"

void GLInit(void);
void handle_reshape(int w,int h);
void handle_draw(void);
void handle_keyboard(unsigned char key,int x,int y);

int main(int argc, char *argv[]) {
    CGL_INIT_WINDOW(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH,
                    480,640,200,200,"Robot");

    glutReshapeFunc(handle_reshape);
    glutDisplayFunc(handle_draw);
    glutKeyboardFunc(handle_keyboard);
    glutIdleFunc(handle_draw);
    
    GLInit();

    glutMainLoop();
    return 0;
}


void GLInit(void) {
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

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
float pos_x = 0,pos_y = 5,pos_z = 10;

void drawRobotHead(void) {
    glPushMatrix();

    // Head
    glColor3f(0,0.2f,0.8f);
    glTranslatef(0,2.5,0); 
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

void drawRobotBody(void) {
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
    glPushMatrix();
    glTranslatef(0.1f,-0.15f,0); 
    glScalef(0.12f,0.12f,0.12f);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    
    // Upper
    glColor3f(0.1f,0.2f,0.8f);
    glPushMatrix();
    glTranslatef(0.25f,-0.65f,0); 
    glRotatef(15,0,0,1);
    glScalef(1,2.2f,1);
    glutSolidCube(0.4f);
    glPopMatrix();

    // Joint2
    glColor3f(0.1f,0.1f,0.1f);
    glPushMatrix();
    glTranslatef(0.4f,-1.1f,0);
    glScalef(0.12f,0.12f,0.12f);
    glutSolidSphere(1,10,10);
    glPopMatrix();
    
    // Lower
    glColor3f(0.1f,0.2f,0.8f);
    glPushMatrix();
    glTranslatef(0.43f,-1.6,0); 
    glScalef(1,2.2f,1);
    glutSolidCube(0.4f);
    glPopMatrix();
    
    // Hand
    glColor3f(0,0.2f,0.8f);
    glPushMatrix();
    glTranslatef(0.45f,-2.19f,0);
    glScalef(0.12f,0.12f,0.12f);
    glutSolidSphere(2.0f,10,10);
    glPopMatrix();
    
    glPopMatrix();
}

void drawRobotPelvis(void) {
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
    glPushMatrix();
    glTranslatef(0.4f,0,0); 
    glScalef(0.12f,0.12f,0.12f);
    glutSolidSphere(1.3f,10,10);
    glPopMatrix();

    // Upper
    glColor3f(0.1f,0.2f,0.8f);
    glPushMatrix();
    glTranslatef(0.55f,-0.5f,0); 
    glRotatef(15,0,0,1);
    glScalef(1,3.0f,1);
    glutSolidCube(0.32f);
    glPopMatrix();
    
    // Lower
    glPushMatrix();
    glTranslatef(0.64f,-2.3f,0);
    glRotatef(-90,1,0,0);
    glutSolidCylinder(0.3f,1.5f,20,5);
    glPopMatrix();
    
    // Foot
    glColor3f(0.2,0.6f,0.3f);
    glPushMatrix();
    glTranslatef(0.65f,-2.6f,0);
    if(factor < 0) {
        glTranslatef(0,0,-0.05f);
        glRotatef(180+85,1,0,0);
    }
    else {
        glTranslatef(0,0,0.05f);
        glRotatef(-85,1,0,0);
    }
    glutSolidCone(0.5f,1.0f,20,3);
    glPopMatrix();

    glPopMatrix();
}

void handle_draw(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    GLfloat ambientColor[] = {0.2f,0.2f,0.2f,1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientColor);
    
    gluLookAt(pos_x,pos_y,pos_z,0,0,0,0,1,0);
    glRotatef(fangle,0,1,0);
    
    glPushMatrix(); // global rotation
    
    drawRobotHead();
    drawRobotBody();
    drawRobotArm(0);
    drawRobotArm(-180);
    drawRobotPelvis();
    drawRobotLeg(0);
    drawRobotLeg(-180);

    glPopMatrix(); // pop global rotation

    /*
    glTranslatef(2,2.5,0);
    glRotatef(90,1,0,0);
    
    glutSolidCylinder(1.0f,5,20,5);
    glTranslatef(-4,0,0);
    glutSolidCylinder(1.0f,5,20,5);*/

    glutSwapBuffers();
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
    }
}
