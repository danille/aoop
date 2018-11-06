//
// Created by Lebediev, Danylo on 15/10/2018.
//

#ifndef LAB2_CMENUITEM_H
#define LAB2_CMENUITEM_H

#define BACK_COMMAND "back"
#include "iostream"
#include "CMenuItemDelegate.h"


using namespace std;

class CMenuItem {
protected:
    string command;
    string name;
public:

    CMenuItem *parentItem;

    virtual void run() = 0;

    virtual void terminate() = 0;

    virtual bool isCommandValid(string command) = 0;

    virtual string getName() = 0;

    virtual string getCommand() = 0;

    virtual string getCommandFromUser() = 0;

    virtual string getPath() = 0;

};

#endif //LAB2_CMENUITEM_H
