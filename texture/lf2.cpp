#include<GL/glut.h>
#include<GL/freeglut.h>
#include<iostream>

#include"catGL.h"
#include"catPng.h"

void GLInit(void);
void handle_reshape(int w,int h);
void handle_draw(void);
void handle_keyboard(unsigned char key,int x,int y);
void handle_timer(int value);
const int timer_tick = 100;

unsigned char *buffer;
unsigned char flip_buffer[80*80*4];
int width,height;
int pw,ph;

#define ROW_SLICES 7
#define COL_SLICES 10
GLuint textures[7][10];
int main(int argc, char *argv[])
{
    CGL_INIT_WINDOW(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH,
                    480,480,200,200,"Blending");
    
    glutReshapeFunc(handle_reshape);
    glutDisplayFunc(handle_draw);
    glutIdleFunc(handle_draw);
    glutTimerFunc(timer_tick,handle_timer,0);
    glutKeyboardFunc(handle_keyboard);

    GLInit();
    buffer = getPng("./woody2.png",&width,&height);
    glGenTextures(ROW_SLICES*COL_SLICES,(GLuint *)textures);
    pw = width / COL_SLICES;
    ph = height / ROW_SLICES;
    
    int r,c;
    for(r=0;r<ROW_SLICES;++r) {
        for(c=0;c<COL_SLICES;++c) {
            glBindTexture(GL_TEXTURE_2D,textures[r][c]);
            getFlip(buffer,width,height,r*pw,c*ph,pw,ph,(unsigned char *)flip_buffer);
            glTexImage2D(GL_TEXTURE_2D,0,4,pw,ph,0,GL_RGBA,
                         GL_UNSIGNED_BYTE,(unsigned char*)flip_buffer);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);// Linear Filtering
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);// Linear Filtering
        } 
    }

    glutMainLoop();
    freePng(buffer);
    return 0;
}

void GLInit(void) {
    //glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    // Texture Mapping
    glEnable(GL_TEXTURE_2D);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
    
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

int frame = 0,df = 0;
void handle_draw() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glBindTexture(GL_TEXTURE_2D,*(((GLuint*)textures)+frame));

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  -5.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f,  -5.0f);    
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  -5.0f);    
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  -5.0f);   
    glEnd();


    glutSwapBuffers();
}

void handle_timer(int value) {
    handle_draw();
    frame += df;
    frame %= ROW_SLICES*COL_SLICES;
    glutTimerFunc(timer_tick,handle_timer,0);
}

void handle_keyboard(unsigned char key,int x,int y) {
    switch(key) {
        case 'p':
            df = 1-df;
            break;
        case 'l':
            frame = (frame+1)%(ROW_SLICES*COL_SLICES);
            break;
        case 'h':
            frame = (frame-1+(ROW_SLICES*COL_SLICES))%(ROW_SLICES*COL_SLICES);
            break;
    }
}
