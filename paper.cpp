#include "paper.h"

#include <iostream>

Paper::Paper(double x_, double y_, double thickness_, double width_, double height_) : Item(x_, y_, thickness_) {
    if (width_ > 0.0) {
        m_width = width_;
    } else {
        std::cerr << "Invalid width; setting default value\n";
    }
    if (height_ > 0.0) {
        m_height = height_;
    } else {
        std::cerr << "Invalid height; setting default value\n";
    }
}

double Paper::mass() const {
    return m_width * m_height * thickness() * m_density;
}

bool Paper::isInside(double x_, double y_) const {
    auto x1 = x() - m_width / 2;
    auto x2 = x() + m_width / 2;
    auto y1 = y() - m_height / 2;
    auto y2 = y() + m_height / 2;
    return (x_ > x1) && (x_ < x2) && (y_ > y1) && (y_ < y2);
}
