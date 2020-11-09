#include "table.h"

#include "paper.h"
#include "plate.h"

void Table::addPaper(double x_, double y_, double thickness_, double width_, double height_) {
    m_items.push(std::make_shared<Paper>(x_, y_, thickness_, width_, height_));
}

void Table::addPlate(double x_, double y_, double thickness_, double radius_) {
    m_items.push(std::make_shared<Plate>(x_, y_, thickness_, radius_));
}

void Table::clear() {
    m_items.clear();
}

bool Table::isBalanced() const {
    auto temp = m_items;
    double x{0.0}, y{0.0}, mass{0.0};
    while (!temp.empty()) {
        auto t = temp.top();
        if ((mass > 0.0) && (!t->isInside(x, y))) {
            return false;
        }
        auto m = t->mass();
        auto oldMass = mass;
        mass += m;
        auto k = m / mass;
        auto oldK = oldMass / mass;
        x = x * oldK + t->x() * k;
        y = y * oldK + t->y() * k;
        temp.pop();
    }
    return true;
}

size_t Table::size() const {
    return m_items.size();
}
