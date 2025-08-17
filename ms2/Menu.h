#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
#include "constants.h"

namespace seneca {
   class Menu;

   class MenuItem {
      friend class Menu;
      char* m_content{};
      unsigned m_indent{};
      unsigned m_indentSize{};
      unsigned m_row{};

      MenuItem(const char* content, unsigned indent, unsigned indentSize, unsigned row);
      MenuItem(const MenuItem&) = delete;
      MenuItem& operator=(const MenuItem&) = delete;
      ~MenuItem();
      std::ostream& display(std::ostream& ostr) const;
   };

   class Menu {
      MenuItem* m_items[MaximumNumberOfMenuItems]{};
      MenuItem m_title;
      MenuItem m_exit;
      MenuItem m_prompt;
      unsigned m_indent{};
      unsigned m_indentSize{};
      unsigned m_numItems{};

   public:
      Menu(const char* title, const char* exit = "Exit", unsigned indent = 0, unsigned indentSize = 3);
      Menu(const Menu&) = delete;
      Menu& operator=(const Menu&) = delete;
      ~Menu();

      Menu& operator<<(const char* menuItem);
      size_t select() const;
   };

   size_t operator<<(std::ostream& ostr, const Menu& m);
}
#endif // !SENECA_MENU_H
