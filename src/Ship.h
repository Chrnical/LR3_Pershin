#ifndef SHIP_H
#define SHIP_H

#include <bits/stdc++.h>


class Ship{
public:
    enum class SegmentState {intact, damaged, destroyed};
    enum class Orientation {vertical, horizontal};

    explicit Ship(short length, Orientation orientation = Orientation::horizontal);

    ~Ship() = default;

    bool isDestroyed();

    void setSegmentState(short segment, SegmentState segmentState);
    SegmentState getSegment(short segment);

    void shootShip(short segment, bool doubleDamage = false);
    Orientation getOrientation() const;
    short getLength() const;

    void outShip(std::ostream &buffer);
private:
    short length;
    Orientation orientation;
    std::vector <SegmentState> segmentStates;
};


#endif