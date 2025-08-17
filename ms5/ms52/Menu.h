
#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
#include "constants.h"
#include "Utils.h"

namespace seneca {
    class Menu; 

    class MenuItem {
        char* m_content{ nullptr };
        unsigned int m_indent{ 0 };
        unsigned int m_indentSize{ 0 };
        int m_row{ -1 };
        friend class Menu;  

        MenuItem(const char* content, unsigned int indent, unsigned int indentSize, int row);
        MenuItem(const MenuItem& other) = delete;
        MenuItem& operator=(const MenuItem& other) = delete;
        ~MenuItem();
        explicit operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
        friend std::ostream& operator<<(std::ostream& ostr, const MenuItem& item);
    };

    class Menu {
        static const size_t MaximumNumberOfMenuItems = 20;
        char* m_title{ nullptr };
        char* m_exitOption{ nullptr };
        unsigned int m_indentation{ 0 };
        unsigned int m_indentationSize{ 3 };
        MenuItem m_selectionPrompt;
        MenuItem m_title_item;
        MenuItem m_exitOption_item;
        MenuItem* m_menuItems[MaximumNumberOfMenuItems]{ nullptr };
        size_t m_numMenuItems{ 0 };

    public:
        Menu(const char* title, const char* exitOption = "Exit",
            unsigned int indentation = 0, unsigned int indentationSize = 3);
        Menu(const Menu& other) = delete;
        Menu& operator=(const Menu& other) = delete;
        ~Menu();
        Menu& operator<<(const char* menuItem);
        size_t select() const;
        friend size_t operator<<(std::ostream& ostr, const Menu& m);

    private:
        void copy(const char* src, char** dst);
        void deallocate();
        bool isMenuFull() const;
    };
}
#endif