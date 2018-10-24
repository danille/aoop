//
// Created by Lebediev, Danylo on 16/10/2018.
//

#ifndef LAB2_CMENUCOMMAND_H
#define LAB2_CMENUCOMMAND_H

#include "CMenuItem.h"
#include "iostream"
#include "../commands/CCommand.h"

class CMenuCommand : public CMenuItem {
    CCommand *commandToExecute;
public:
    CMenuCommand(string name, string command, CCommand* commandToExecute);

    void run();

    void terminate();

    bool isCommandValid(string command);

    string getCommandFromUser();

    string getPath();

    string getName();

    string getCommand();

    ~CMenuCommand();
};

#endif //LAB2_CMENUCOMMAND_H
