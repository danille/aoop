//
// Created by Lebediev, Danylo on 25/10/2018.
//

#include "NavigationManager.h"

void NavigationManager::navigateUpTo(CMenuItem *menuItem) {
    menuItem->parentItem = currentMenuItem;
    currentMenuItem = menuItem;
    currentMenuItem->run();
}

void NavigationManager::navigateDownFrom(CMenuItem *menuItem) {
    if (menuItem->parentItem == nullptr) {
        cout << "You are in root. Please press Ctrl+C to exit" << endl;
        menuItem->run();
    } else {
        currentMenuItem = menuItem->parentItem;
        currentMenuItem->run();
    }
}
