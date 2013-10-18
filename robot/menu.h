#ifndef _MENU_H_
#define _MENU_H_

enum MenuEntry {
    ME_WALK = 1,
    ME_EXIT,
    ME_VIEW_SOLID,
    ME_VIEW_LINE,
};

void handle_menu(int menu);

static void GLMenu() {
    int menu_main = glutCreateMenu(handle_menu);
    int menu_view = glutCreateMenu(handle_menu);

    glutSetMenu(menu_main);
    glutAddSubMenu("View",menu_view);
    glutAddMenuEntry("Walk",ME_WALK);
    glutAddMenuEntry("Exit",ME_EXIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutSetMenu(menu_view);
    glutAddMenuEntry("Solid",ME_VIEW_SOLID);
    glutAddMenuEntry("Line",ME_VIEW_LINE);
}
#endif
