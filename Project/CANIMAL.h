#ifndef CROSSINGGAME_CANIMAL_H
#define CROSSINGGAME_CANIMAL_H


class CANIMAL {
private:
    int mX, mY;
public:
    virtual void Move(int, int);
    virtual void Tell();
};


#endif //CROSSINGGAME_CANIMAL_H

