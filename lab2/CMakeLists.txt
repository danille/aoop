cmake_minimum_required(VERSION 3.12)
project(lab2)

set(CMAKE_CXX_STANDARD 98)

add_executable(lab2 main.cpp menu/CMenuItem.h menu/CMenuCommand.h commands/CCommand.h menu/CMenuCommand.cpp commands/CCommand.cpp menu/CMenu.cpp menu/CMenu.h menu/CMenuItemDelegate.h
        CTable.h CTable.cpp CTableManager.h CTableManager.cpp commands/CreateTablesCommand.cpp commands/CreateTablesCommand.h commands/PrintTablesInfoCommand.cpp commands/PrintTablesInfoCommand.h commands/TableCommand.cpp commands/TableCommand.h)