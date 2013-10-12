#include<GL/glut.h>
#include<GL/freeglut.h>

#include"catGL.h"
#include"catPng.h"

void GLInit(void);
void handle_reshape(int w,int h);
void handle_draw(void);
void handle_keyboard(unsigned char key,int x,int y);

unsigned char *buffer;
int width,height;
int main(int argc, char *argv[])
{
    CGL_INIT_WINDOW(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH,
                    480,480,200,200,"Blending");
    
    glutReshapeFunc(handle_reshape);
    glutDisplayFunc(handle_draw);
    glutIdleFunc(handle_draw);

    GLInit();
    buffer = getPng("./robot.png",&width,&height);

    glutMainLoop();
    freePng(buffer);
    return 0;
}

void GLInit(void) {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    // Texture Mapping
    glEnable(GL_TEXTURE_2D);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}


void handle_reshape(int w,int h) {
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

GLfloat angle = 0;
void handle_draw() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // texture mapping
    glTexImage2D(GL_TEXTURE_2D,0,4,width,height,
                 0,GL_RGBA,GL_UNSIGNED_BYTE,buffer);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);// Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);// Linear Filtering

    glRotatef(angle,0,0,1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  -5.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f,  -8.0f);    
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  -3.0f);    
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  -3.0f);   
    glEnd();

    angle += 2;

    glutSwapBuffers();
}

