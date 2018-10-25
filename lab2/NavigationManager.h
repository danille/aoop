//
// Created by Lebediev, Danylo on 25/10/2018.
//

#ifndef LAB2_NAVIGATIONMANAGER_H
#define LAB2_NAVIGATIONMANAGER_H


#include "menu/CMenuItem.h"

class NavigationManager {
    CMenuItem* currentMenuItem;
public:

    void navigateUpTo(CMenuItem* menuItem);

    void navigateDownFrom(CMenuItem* menuItem);

};


#endif //LAB2_NAVIGATIONMANAGER_H
