#include "rotation.h"

void DoRotate(GLfloat rots[]) {
    glRotatef(rots[0],1,0,0);
    glRotatef(rots[1],0,1,0);
    glRotatef(rots[2],0,0,1);
    glRotatef(rots[3],0,1,0);
    glRotatef(rots[4],1,0,0);
}
