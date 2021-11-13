#ifndef CROSSINGGAME_CPEOPLE_H
#define CROSSINGGAME_CPEOPLE_H


class CPEOPLE {
private:
    int mX, mY;
    bool mState; //Trạng thái sống chết
public:
    CPEOPLE();
    void Up(int);
    void Left(int);
    void Right(int);
    void Down(int);
    bool isImpact(const CVEHICLE*&);
    bool isImpact(const CANIMAL*&);
    bool isFinish();
};


#endif //CROSSINGGAME_CPEOPLE_H

