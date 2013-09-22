#include<GL/glut.h>
#include<math.h>

void handle_draw(void);
void handle_reshape(int w,int h);
void GLInit(void);

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("hello openGL");

    glutDisplayFunc(handle_draw);
    glutReshapeFunc(handle_reshape);
    glutIdleFunc(handle_draw);

    GLInit();

    glutMainLoop();
    return 0;
}

void GLInit(void) {
    glDisable(GL_LIGHTING);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.0f,0.0f,0.0f,1.0f);

    glShadeModel(GL_SMOOTH);
}

void handle_reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Draw_Points()
{
    const float GL_PI = 3.1415926f;
    GLfloat x,y,z;
    float angle;
    z = -5.0f;
    glBegin(GL_POINTS); // Start drawing points
    glColor3f(0.0,0.0,0.0);
    for(angle = 0.0f; angle <= (2.0f*GL_PI)*3.0f; angle += 0.1f)
    {
        x = sin(angle);
        y = cos(angle);
        // Specify the point and move the Z value up a little
        glVertex3f(x, y, z);
        z += 0.01f;
    }
    glEnd(); // End drawing points
}
float fangle = 0;
void handle_draw(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    // Set the camera
    gluLookAt(	10.0f, 0.0f, 10.0f,
                    0.0f, 0.0f,  0.0f,
                    0.0f, 1.0f,  0.0f);
    //glRotatef(50, 0.0f, 0.0f, 0.0f);
    /* 
    glTranslatef(1.0,0.0,-5.0f);
    */
    //glutWireTeapot(0.2f);
    //glLoadIdentity();
    /*
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.5f,0.0f,-5.0f);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-0.5f,0.0f,-5.0f);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0f,-0.5f,-5.0f);
    
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.5f,0.5f,-6.0f);
    glVertex3f(-0.5f,0.5f,-6.0f);
    glVertex3f(0.0f,-0.5f,-6.0f);
    glEnd();
    */ 
    //Draw_Points();

    GLUquadricObj *p;
    p = gluNewQuadric();
    gluQuadricDrawStyle(p,GLU_LINE);
    /*glColor3f(1.0,0.0,0.0);
    gluQuadricDrawStyle(p,GLU_LINE);
    gluCylinder(p,0.5f,0.5f,1,10,5);

    glLoadIdentity();
    gluLookAt(	0.0f, 0.0f, 10.0f,
                    0.0f, 0.0f,  0.0f,
                    0.0f, 1.0f,  0.0f);
    glColor3f(0.0,0.0,1.0);
    gluCylinder(p,0.5f,0.5f,1,10,5);*/
    glLoadIdentity();
    gluLookAt(	fangle, 0.0f, 10.0f,
                    0.0f, 0.0f,  0.0f,
                    0.0f, 1.0f,  0.0f);
    glColor3f(0.0,1.0,0.0);
    gluCylinder(p,1.5f,1.5f,5,10,5);
    glColor3f(0.0,0.0,1.0);
    glutWireTeapot(2.0f);
    fangle += 0.01;

    //fangle += 0.5;

    glLoadIdentity();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.5f,0.0f,-9.9f);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-0.5f,0.0f,-9.9f);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0f,-0.5f,-9.9f);
    glEnd();
    glutSwapBuffers();
}
