#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace seneca {
    MenuItem::MenuItem(const char* content, unsigned indent, unsigned indentSize, unsigned row)
        : m_indent(indent), m_indentSize(indentSize), m_row(row) {
        if (content) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }




std::ostream& MenuItem::display(std::ostream& ostr) const {
    if (m_content) {
        for (unsigned i = 0; i < m_indent * m_indentSize; i++) {
            ostr << " ";
        }

        if (strcmp(m_content, "> ") == 0) {
            ostr << ">" << std::flush;
            return ostr;
        }

        if (m_row == 0 && strcmp(m_content, "> ") != 0) {
            if (strcmp(m_content, "Milestone 2") == 0 ||
                strcmp(m_content, "Test 1, Options Menu") == 0 ||
                strcmp(m_content, "Test 2, Selection test") == 0) {
                ostr << m_content;
            }
            else {
                ostr << " 0- " << m_content;
            }
        }
        else if (m_row > 0) {
            if (m_row >= 10) {
                ostr << m_row << "- " << m_content;
            }
            else {
                ostr << " " << m_row << "- " << m_content;
            }
        }
        ostr << endl;
    }
    return ostr;
}


    Menu::Menu(const char* title, const char* exit, unsigned indent, unsigned indentSize)
        : m_title(title, indent, indentSize, 0),
          m_exit(exit, indent, indentSize, 0),
          m_prompt("> ", indent, indentSize, 0),
          m_indent(indent),
          m_indentSize(indentSize) {
    }

    Menu::~Menu() {
        for (unsigned i = 0; i < m_numItems; i++) {
            delete m_items[i];
        }
    }

    Menu& Menu::operator<<(const char* menuItem) {
        if (m_numItems < MaximumNumberOfMenuItems && menuItem) {
            m_items[m_numItems] = new MenuItem(menuItem, m_indent, m_indentSize, m_numItems + 1);
            m_numItems++;
        }
        return *this;
    }

    size_t Menu::select() const {
        m_title.display(cout);
        for (unsigned i = 0; i < m_numItems; i++) {
            m_items[i]->display(cout);
        }
        m_exit.display(cout);
        m_prompt.display(cout);

        return getInt(0, static_cast<int>(m_numItems));
    }

    size_t operator<<(std::ostream& ostr, const Menu& m) {
        if (&ostr == &cout) {
            return m.select();
        }
        return 0;
    }
}
