#ifndef _MENU_H_
#define _MENU_H_

enum MenuEntry {
    ME_WALK = 1,
    ME_EXIT,
    ME_RUN,
    ME_VIEW_SOLID,
    ME_VIEW_LINE,
    ME_DANCE_GANSTYLE1,
    ME_DANCE_GANSTYLE2,
    ME_ACTION_PUSHUP,
    ME_ACTION_ATTACK1,
    ME_ACTION_SUPER,
    ME_EQU_CONE,
};

void handle_menu(int menu);

static void GLMenu() {
    int menu_main = glutCreateMenu(handle_menu);
    int menu_view = glutCreateMenu(handle_menu);
    int menu_dance = glutCreateMenu(handle_menu);
    int menu_action = glutCreateMenu(handle_menu);
    int menu_equ = glutCreateMenu(handle_menu);

    glutSetMenu(menu_main);
    glutAddSubMenu("View",menu_view);
    glutAddSubMenu("Dance",menu_dance);
    glutAddSubMenu("Action",menu_action);
    glutAddSubMenu("Equipment",menu_equ);
    glutAddMenuEntry("Walk",ME_WALK);
    glutAddMenuEntry("Run",ME_RUN);
    glutAddMenuEntry("Exit",ME_EXIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutSetMenu(menu_view);
    glutAddMenuEntry("Solid",ME_VIEW_SOLID);
    glutAddMenuEntry("Line",ME_VIEW_LINE);
    
    glutSetMenu(menu_dance);
    glutAddMenuEntry("GangnamStyle 1",ME_DANCE_GANSTYLE1);
    glutAddMenuEntry("GangnamStyle 2",ME_DANCE_GANSTYLE2);

    glutSetMenu(menu_action);
    glutAddMenuEntry("Push Up",ME_ACTION_PUSHUP);
    glutAddMenuEntry("AttackMode",ME_ACTION_ATTACK1);
    glutAddMenuEntry("SuperMode",ME_ACTION_SUPER);
    
    glutSetMenu(menu_equ);
    glutAddMenuEntry("Cone",ME_EQU_CONE);
}
#endif
