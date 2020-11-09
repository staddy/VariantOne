#ifndef PAPER_H
#define PAPER_H

#include "item.h"

class Paper : public Item {
public:
    Paper() = default;
    Paper(double x_, double y_, double thickness_, double width_, double height_);
    Paper(const Paper& other_) = default;
    Paper(Paper&& other_) = default;
    Paper& operator=(const Paper& other_) = default;
    Paper& operator=(Paper&& other_) = default;
    ~Paper() = default;
    double mass() const override;
    bool isInside(double x_, double y_) const override;
private:
    double m_width{1.0};
    double m_height{1.0};
};

#endif // PAPER_H
