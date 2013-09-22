#ifndef _CATGL_H_
#define _CATGL_HL

GLUquadricObj *cgl_glu_qobj;
#define CGL_INIT_WINDOW(_dmode,_ws_w,_ws_h,_wp_x,_wp_y,_w_name) \
    glutInit(&argc,argv);\
    glutInitDisplayMode(_dmode);\
    glutInitWindowSize(_ws_w,_ws_h);\
    glutInitWindowPosition(_wp_x,_wp_y);\
    glutCreateWindow(_w_name);\
    cgl_glu_qobj = gluNewQuadric();

#endif
