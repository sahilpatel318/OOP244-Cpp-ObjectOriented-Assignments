
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"

namespace seneca {
    MenuItem::MenuItem(const char* content, unsigned int indent, unsigned int indentSize, int row) {
        m_content = nullptr;
        m_indent = indent;
        m_indentSize = indentSize;
        m_row = row;
        if (content) {
            m_content = new char[ut.strlen(content) + 1];
            ut.strcpy(m_content, content);
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        return m_content != nullptr;
    }

    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (m_content) {
            if (ut.strlen(m_content) == 0 || strcmp(m_content, "> ") != 0) {
                for (unsigned int i = 0; i < m_indent * m_indentSize; i++) {
                    ostr << ' ';
                }
                if (m_row >= 0) {
                    if (m_row < 10) {
                        ostr << " ";
                    }
                    ostr << m_row << "- ";
                }
                ostr << m_content << std::endl;
            }
            else {
                for (unsigned int i = 0; i < m_indent * m_indentSize; i++) {
                    ostr << ' ';
                }
                ostr << m_content;
            }
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const MenuItem& item) {
        return item.display(ostr);
    }

    Menu::Menu(const char* title, const char* exitOption, unsigned int indent, unsigned int indentSize)
        : m_indentation(indent)
        , m_indentationSize(indentSize)
        , m_selectionPrompt("> ", indent, indentSize, -1)
        , m_title_item(title, indent, indentSize, -1)
        , m_exitOption_item(exitOption, indent, indentSize, 0) {
        m_title = nullptr;
        m_exitOption = nullptr;
        m_numMenuItems = 0;

        if (title) {
            m_title = new char[ut.strlen(title) + 1];
            ut.strcpy(m_title, title);
        }
        if (exitOption) {
            m_exitOption = new char[ut.strlen(exitOption) + 1];
            ut.strcpy(m_exitOption, exitOption);
        }

        for (size_t i = 0; i < MaximumNumberOfMenuItems; i++) {
            m_menuItems[i] = nullptr;
        }
    }

    Menu::~Menu() {
        deallocate();
    }

    void Menu::copy(const char* src, char** dst) {
        if (src) {
            *dst = new char[ut.strlen(src) + 1];
            ut.strcpy(*dst, src);
        }
        else {
            *dst = nullptr;
        }
    }

    void Menu::deallocate() {
        delete[] m_title;
        delete[] m_exitOption;
        for (size_t i = 0; i < m_numMenuItems; i++) {
            delete m_menuItems[i];
            m_menuItems[i] = nullptr;
        }
        m_title = nullptr;
        m_exitOption = nullptr;
        m_numMenuItems = 0;
    }

    bool Menu::isMenuFull() const {
        return m_numMenuItems >= MaximumNumberOfMenuItems;
    }

    Menu& Menu::operator<<(const char* menuItem) {
        if (!isMenuFull()) {
            m_menuItems[m_numMenuItems] = new MenuItem(menuItem, m_indentation, m_indentationSize,
                static_cast<int>(m_numMenuItems + 1));
            m_numMenuItems++;
        }
        return *this;
    }

    size_t Menu::select() const {
        if (m_title) {
            std::cout << m_title_item;
        }
        for (size_t i = 0; i < m_numMenuItems; i++) {
            std::cout << *m_menuItems[i];
        }
        std::cout << m_exitOption_item;
        std::cout << m_selectionPrompt;
        return static_cast<size_t>(ut.getInt(0, static_cast<int>(m_numMenuItems)));
    }

    size_t operator<<(std::ostream& ostr, const Menu& menu) {
        return (&ostr == &std::cout) ? menu.select() : 0;
    }
}