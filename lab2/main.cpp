#include <iostream>
#include "table/CTableManager.h"
#include "menu/CMenu.h"
#include "menu/CMenuCommand.h"
#include "commands/CCommand.h"
#include "commands/CreateTablesCommand.h"
#include "commands/PrintTablesInfoCommand.h"
#include "application/Application.h"
#include "application/MenuApplication.h"

using namespace std;


int main() {
    MenuApplication application;
    application.run();
    return 0;
}