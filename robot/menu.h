#ifndef _MENU_H_
#define _MENU_H_

enum MenuEntry {
    ME_WALK = 1,
    ME_EXIT,
    ME_RUN,
    ME_VIEW_SOLID,
    ME_VIEW_LINE,
    ME_DANCE_GANSTYLE1,
    ME_DANCE_GANSTYLE2
};

void handle_menu(int menu);

static void GLMenu() {
    int menu_main = glutCreateMenu(handle_menu);
    int menu_view = glutCreateMenu(handle_menu);
    int menu_dance = glutCreateMenu(handle_menu);

    glutSetMenu(menu_main);
    glutAddSubMenu("View",menu_view);
    glutAddSubMenu("Dance",menu_dance);
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
}
#endif
