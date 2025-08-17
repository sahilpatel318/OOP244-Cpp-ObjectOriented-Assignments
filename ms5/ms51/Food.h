
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H
#include "Billable.h"

namespace seneca {
    class Food : public Billable {
        bool m_ordered{ false };
        bool m_child{ false };
        char* m_customize{ nullptr };
    public:
        Food();
        Food(const Food& src);
        Food& operator=(const Food& src);
        ~Food();
        std::ostream& print(std::ostream& ostr = std::cout) const override;
        bool order() override;
        bool ordered() const override;
        std::ifstream& read(std::ifstream& file) override;
        double price() const override;
    };
}
#endif