#ifndef ITEM_H
#define ITEM_H


class Item {
public:
    Item() = default;
    Item(double x_, double y_, double thickness_);
    Item(const Item& other_) = default;
    Item(Item&& other_) = default;
    Item& operator=(const Item& other_) = default;
    Item& operator=(Item&& other_) = default;
    ~Item() = default;
    double x() const;
    double y() const;
    virtual double mass() const = 0;
    virtual bool isInside(double x_, double y_) const = 0;
protected:
    double m_density{1.0};
    double thickness() const;
private:
    double m_x{0.0};
    double m_y{0.0};
    double m_thickness{0.1};
};

#endif // ITEM_H
