#include "plate.h"

#include <iostream>

Plate::Plate(double x_, double y_, double thickness_, double radius_)
    : Item(x_, y_, thickness_) {
    if (radius_ > 0.0) {
        m_radius = radius_;
    } else {
        std::cerr << "Invalid radius; setting default value\n";
    }
}

double Plate::mass() const {
    return PI * m_radius * m_radius * thickness() * m_density;
}

bool Plate::isInside(double x_, double y_) const {
    auto x__ = x_ - x();
    auto y__ = y_ - y();
    return (x__ * x__ + y__ * y__) < (m_radius * m_radius);
}
