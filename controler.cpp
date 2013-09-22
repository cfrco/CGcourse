#include<GL/glut.h>
#include<GL/freeglut.h>
#include<sstream>
#include<string>

void GLInit(void);
void handle_reshape(int w,int h);
void handle_draw(void);
void handle_keyboard(unsigned char key,int x,int y);

int main(int argc, char *argv[])
{
    glutInit (&argc,argv);

    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Controler");

    glutReshapeFunc(handle_reshape);
    glutDisplayFunc(handle_draw);
    glutKeyboardFunc(handle_keyboard);
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

void handle_reshape(int w,int h) {
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

std::string display_info = "hello";
GLfloat control_table[][3] = {
    {0,0,0}, // Lookat.Eye
    {0,0,0}, // Lookat.Center
    {0,1,0}, // Lookat.Up
    {1,1,1}, // Color
    {0,0,0}, // Rotate
    {0,2,0}, // Value(Rotate, Size , _ )
};
float interval = 0.1f;
int table_index = 0;
int pos_index = 0;

void handle_draw(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
     
    glLoadIdentity();
    gluLookAt(control_table[0][0],control_table[0][1],control_table[0][2],
              control_table[1][0],control_table[1][1],control_table[1][2],
              control_table[2][0],control_table[2][1],control_table[2][2]);
    glColor3f(control_table[3][0],control_table[3][1],control_table[3][2]);
    glRotatef(control_table[5][0],control_table[4][0],control_table[4][1],control_table[4][2]);
    glutWireTeapot(control_table[5][1]);

    // draw text
    glPushMatrix();
    glLoadIdentity();
    glColor4f(1.0f,0.0,0.0,10.f);
    glTranslatef(-7.3f,-7.2f,-18);
    glScalef(0.005f,0.005f,0.005f);
    glutStrokeString(GLUT_STROKE_ROMAN,(const unsigned char*)display_info.c_str());
    glPopMatrix();

    glutSwapBuffers();
}

std::string info_property = "Lookat.Eye";
std::string info_field = "x"; 
std::string info_value = "";
std::ostringstream sbuffer;

void handle_keyboard(unsigned char key,int x,int y) {
    //std::cout << key << std::endl;
    switch(key) {
        // Properties
        case 'e': 
            info_property = "Lookat.Eye";
            table_index = 0;
            break;
        case 'c': 
            info_property = "Lookat.Center";
            table_index = 1;
            break;
        case 'u': 
            info_property = "Lookat.Up";
            table_index = 2;
            break;
        case 'C':
            info_property = "Color";
            table_index = 3;
            break;
        case 'r':
            info_property = "Rotate";
            table_index = 4;
            break;
        case 'v':
            info_property = "Value";
            table_index = 5;
            break;
        
        // Fields
        case 'x': 
            info_field = "x";
            pos_index = 0;
            break;
        case 'y': 
            info_field = "y";

            pos_index = 1;
            break;
        case 'z': 
            info_field = "z";
            pos_index = 2;
            break;

        // Value
        case 'k': // up
            control_table[table_index][pos_index] += interval;
            break;
        case 'j': // down
            control_table[table_index][pos_index] -= interval;
            break;
        
        case 'l': // up(big)
            control_table[table_index][pos_index] += interval*10;
            break;
        case 'h': // down(big)
            control_table[table_index][pos_index] -= interval*10;
            break;
        
        case 'o': // zero
            control_table[table_index][pos_index]  = 0;
            break;
    }
    sbuffer << control_table[table_index][pos_index];
    info_value = sbuffer.str();
    sbuffer.str("");

    display_info = info_property+"["+info_field+"] = "+info_value;
}
