#include "item.h"

#include <iostream>

Item::Item(double x_, double y_, double thickness_) : m_x{x_}, m_y{y_} {
    if (thickness_ > 0.0) {
        m_thickness = thickness_;
    } else {
        std::cerr << "Invalid thickness; setting default value\n";
    }
}

double Item::x() const {
    return m_x;
}

double Item::y() const {
    return m_y;
}

double Item::thickness() const {
    return m_thickness;
}
