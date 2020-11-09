#ifndef TABLE_H
#define TABLE_H

#include "stack.h"
#include "item.h"

class Table {
public:
    Table() = default;
    Table(const Table& other_) = default;
    Table(Table&& other_) = default;
    Table& operator=(const Table& other_) = default;
    Table& operator=(Table&& other_) = default;
    ~Table() = default;
    void addPaper(double x_, double y_, double thickness_, double width_, double height_);
    void addPlate(double x_, double y_, double thickness_, double radius_);
    void clear();
    bool isBalanced() const;
    size_t size() const;
private:
    Stack<std::shared_ptr<Item> > m_items;
};

#endif // TABLE_H
