#include <iostream>

using namespace std;

void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    Long style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & (WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void exitGame(thread* t) {
    system(“cls”);
    IS_RUNNING = false;
    t->join();
}

void ThreadFunc1() {
    while (IS_RUNNING) {
        //…thực hiện in ra màn hình console những đối tượng trong trò chơi
    }
}

void SubThread()
{
    while (IS_RUNNING) {
        if (!cg.getPeople().isDead()) //Nếu người vẫn còn sống
        {
            cg.updatePosPeople(MOVING);//Cập nhật vị trí người theo thông tin từ main
        }
        MOVING = ' ';// Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
        cg.updatePosVehicle();//Cập nhật vị trí xe
        cg.updatePosAnimal(); //Cập nhật vị trí thú
        cg.drawGame();
        if (cg.getPeople().isImpact(cg.getVehicle() ||
            cg.getPeople().isImpact(cg.getAnimal())
        {
            // Xử lý khi đụng xe hay thú
        }
        if (cg.getPeople().isFinish()) {
            // Xử lý khi về đích
        }
        Sleep(100);
    }
}

void main() {
    //…
    thread t1(ThreadFunc1); //Tạo một thread phụ chạy song song với thread main
    while (1) {
        int temp = toupper(getch());
        //…
        if (temp == 27) {// người dùng muốn thoát
            exitGame(&t1);
            return;
        }
        //…
    }
}