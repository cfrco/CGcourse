#include<GL/glut.h>
#include<GL/freeglut.h>

#include"catGL.h"

void GLInit(void);
void handle_reshape(int w,int h);
void handle_draw(void);
void handle_keyboard(unsigned char key,int x,int y);

int main(int argc, char *argv[])
{
    CGL_INIT_WINDOW(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH,
                    480,480,200,200,"Blending");
    
    glutReshapeFunc(handle_reshape);
    glutDisplayFunc(handle_draw);

    GLInit();

    glutMainLoop();
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

    // Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
}


void handle_reshape(int w,int h) {
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void handle_draw() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // opaque 
    glBegin(GL_TRIANGLES);
    glColor4f(0.0,1.0,0.0,1.0f);
    glVertex3f(0.5f,0.5f,-6.0f);
    glVertex3f(-0.5f,0.5f,-6.0f);
    glVertex3f(0.0f,-0.5f,-6.0f);
    glEnd();
    
    glDepthMask(GL_FALSE); // depth buffer -> read-only
    // transparent
    glBegin(GL_TRIANGLES);
    glColor4f(1.0,0.0,0.0,0.8f);
    glVertex3f(0.5f,0.0f,-5.0f);
    glVertex3f(-0.5f,0.0f,-5.0f);
    glVertex3f(0.0f,-0.5f,-5.0f);
    glEnd();

    glDepthMask(GL_TRUE); // depth buffer -> read/write

    glutSwapBuffers();
}

