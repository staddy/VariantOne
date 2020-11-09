#ifndef PLATE_H
#define PLATE_H

#include "item.h"

class Plate : public Item {
public:
    Plate() = default;
    Plate(double x_, double y_, double thickness_, double radius_);
    Plate(const Plate& other_) = default;
    Plate(Plate&& other_) = default;
    Plate& operator=(const Plate& other_) = default;
    Plate& operator=(Plate&& other_) = default;
    ~Plate() = default;
    double mass() const override;
    bool isInside(double x_, double y_) const override;
private:
    double m_radius{1.0};
    static constexpr double PI = 3.141592653589793238;
};

#endif // PLATE_H
