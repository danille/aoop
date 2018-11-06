//
// Created by Lebediev, Danylo on 16/10/2018.
//

#ifndef LAB2_CMENU_H
#define LAB2_CMENU_H

#include "CMenuItem.h"
#include "vector"

using namespace std;

class CMenu : public CMenuItem {
    vector<CMenuItem *> *commands;
    bool *successor;
public:
    CMenu(string name, string command);

    void addMenuItem(CMenuItem *menuItem);

    bool isCommandValid(string command);

    void runMenuItem(CMenuItem *menuItem);

    void run();

    void terminate();

    string getName();

    string getCommand();

    string getCommandFromUser();

    CMenuItem *getMenuItemByCommand(string command);

    string getPath();

    ~CMenu();

};


#endif //LAB2_CMENU_H
