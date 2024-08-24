
/*编写一个计算器的页面
第一面 选择计算器计算形状的种类 在点击不同的形状后跳转到不同的页面
第二页计算正方形的面积 并画出正方形
第三页计算长方形的面积 并画出长方形
第四页计算圆的面积 并画出圆
存在的问题：
1没有具体的计算公式
2存在没有使用的代码，后续需要删除保持精确简洁
3没有丰富的交互
4文字排版是乱排的，需要后续重新排版
5还没有实现计算完后按空格或者其他键回到第一面
6还没有计算按键的位置，没有设置捕捉鼠标点击按键进行跳转即isinrect函数
7具体的跳转操作是没有调试的，只是提供设计ui的思路，需要在完成调试后重新debug
8没有调试一定存在大量bug---汪家怡第一版


*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<easyx.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include <iomanip>
#include <string>
#include <conio.h>
#include <sstream>
#include <cstring>

using namespace std;



char unit[20];
char dcha1[20];
char dcha2[20];
char judge[20] = "in";

struct Resourse { IMAGE img_start[2]; }res;//这里存放要使用当作背景的图片
struct square {
    double d;
    double s;
    char const* dcha1;
    char scha[20];

}squ;
struct rectangle {
    double d1;
    double d2;
    double s;
    char const* dcha1;
    char const* dcha2;
    char scha[20];
}rec;
struct triangle {
    double h;
    double d;
    double s;
}tri;
struct circle {
    double r;
    double s;

}cir;//导入公式
void calculatesquare(struct square) {
    squ.s = squ.d * squ.d;
}
void calculaterectangle(struct rectangle)
{
    rec.s = rec.d1 * rec.d2;

}
void calculatetriangle(struct triangle)
{
    tri.s = 0.5 * tri.h * tri.d;
}
void calculatecircle(struct circle)
{
    cir.s = cir.r * cir.r * 3.1415926535 * 0.25;
}

void button(int x, int y, int w, int h, const char* text)
{

    setbkmode(TRANSPARENT);//设置字体背景透明
    setfillcolor(BROWN);//设置填充颜色
    fillroundrect(x, y, x + w, y + h, 10, 10);//设置按钮

    char text_[50] = { 0 };//按钮内容物
    strcpy_s(text_, text);//复制
    settextstyle(40, 0, "黑体");
    int tx = x + (w - textwidth(text_)) / 2;
    int ty = y + (h - textheight(text_)) / 2;
    outtextxy(tx, ty, text_);
}





void res_init(struct Resourse* res) {
    loadimage(res->img_start + 0, "resourse/image/01.png", getwidth(), getheight());

    loadimage(res->img_start + 1, "resourse/image/02.png", getwidth(), getheight());


}//导入图片,记得改属性高级字符集，不然会报错

void displayResults(struct square) {
    cout << fixed << setprecision(3);
    cout << "Square side length: " << squ.d << " cm\n";
    cout << "Square area: " << squ.s << " square cm\n";


    outtextxy(50, 50, "选择的图形是正方形");

    outtextxy(50, 150, "边长为");
    outtextxy(50, 250, "面积为");

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << squ.s;
    std::string str_number = oss.str();
    const char* char_array = str_number.c_str();
    outtextxy(250, 250, char_array);

    std::ostringstream oss1;
    oss1 << std::fixed << std::setprecision(3) << squ.d;
    std::string str_number1 = oss1.str();
    const char* char_array1 = str_number1.c_str();
    outtextxy(250, 150, char_array1);
}

void displayResults(struct rectangle) {
    cout << fixed << setprecision(3);
    cout << "Rectangle length: " << rec.d1 << " cm\n";
    cout << "Rectangle width: " << rec.d2 << " cm\n";
    cout << "Rectangle area: " << rec.s << " square cm\n";


    outtextxy(50, 50, "选择的图形是长方形");

    outtextxy(50, 150, "长为");
    outtextxy(50, 200, "宽为");
    outtextxy(50, 300, "面积为");


    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << rec.s;
    std::string str_number = oss.str();
    const char* char_array = str_number.c_str();
    outtextxy(250, 300, char_array);

    std::ostringstream oss1;
    oss1 << std::fixed << std::setprecision(3) << rec.d1;
    std::string str_number1 = oss1.str();
    const char* char_array1 = str_number1.c_str();
    outtextxy(250, 150, char_array1);

    std::ostringstream oss2;
    oss2 << std::fixed << std::setprecision(3) << rec.d2;
    std::string str_number2 = oss2.str();
    const char* char_array2 = str_number2.c_str();
    outtextxy(250, 200, char_array2);
}

void displayResults(struct triangle) {
    cout << fixed << setprecision(3);
    cout << "Triangle base: " << tri.d << " cm\n";
    cout << "Triangle height: " << tri.h << " cm\n";
    cout << "Triangle area: " << tri.s << " square cm\n";

    outtextxy(50, 150, "底为");
    outtextxy(50, 200, "高为");
    outtextxy(50, 300, "面积为");


    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << tri.s;
    std::string str_number = oss.str();
    const char* char_array = str_number.c_str();
    outtextxy(250, 300, char_array);

    std::ostringstream oss1;
    oss1 << std::fixed << std::setprecision(3) << tri.d;
    std::string str_number1 = oss1.str();
    const char* char_array1 = str_number1.c_str();
    outtextxy(250, 150, char_array1);

    std::ostringstream oss2;
    oss2 << std::fixed << std::setprecision(3) << tri.h;
    std::string str_number2 = oss2.str();
    const char* char_array2 = str_number2.c_str();
    outtextxy(250, 200, char_array2);
}

void displayResults(struct circle) {
    cout << fixed << setprecision(3);
    cout << "Circle diameter: " << cir.r << " cm\n";
    cout << "Circle area: " << cir.s << " square cm\n";

    outtextxy(50, 150, "半径为");
    outtextxy(50, 250, "面积为");

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << cir.s;
    std::string str_number = oss.str();
    const char* char_array = str_number.c_str();
    outtextxy(250, 250, char_array);

    std::ostringstream oss1;
    oss1 << std::fixed << std::setprecision(3) << cir.r;
    std::string str_number1 = oss1.str();
    const char* char_array1 = str_number1.c_str();
    outtextxy(250, 150, char_array1);
}

void handleSquare() {
    squ.dcha1 = dcha1;
    squ.d = strtod(squ.dcha1, NULL);
    cout << squ.d;
    cout << unit;
    if (strcmp(unit, judge) == 0) { squ.d = squ.d * 2.54; };
    cout << squ.d;
    calculatesquare(squ);
    displayResults(squ);
    stringstream ss;
    ss << squ.s;
    ss >> squ.scha;









}

void handleRectangle() {
    rec.dcha1 = dcha1;
    rec.d1 = strtod(rec.dcha1, NULL);
    rec.dcha2 = dcha2;
    rec.d2 = strtod(rec.dcha2, NULL);

    cout << rec.d1;
    cout << unit;
    if (strcmp(unit, judge) == 0) {
        rec.d1 = rec.d1 * 2.54;
        rec.d2 = rec.d2 * 2.54;
    };

    calculaterectangle(rec);
    displayResults(rec);
    stringstream ss1;
    ss1 << rec.s;
    ss1 >> rec.scha;
}

void handleTriangle() {
    triangle tri;
    string unit;
    cout << "You chose Triangle. Enter the base and height: ";
    cin >> tri.d >> tri.h;
    cout << "Is the length in cm or inches? ";
    cin >> unit;

    calculatetriangle(tri);
    displayResults(tri);
}


void handleCircle() {
    circle;cir;
    string unit;
    cout << "You chose Circle. Enter the diameter: ";
    cin >> cir.r;
    cout << "Is the diameter in cm or inches? ";
    cin >> unit;

    calculatecircle(cir);
    displayResults(cir);

}

void addpage1() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/02.png");
    putimage(0, 0, &img);
    button(630, 50, 150, 50, "返回");

    InputBox(unit, 1000, "单位,请输入cm或in");

    InputBox(dcha1, 1000, "输入边长");
}

void addpage2() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/02.png");
    putimage(0, 0, &img);
    button(630, 50, 150, 50, "返回");

    InputBox(unit, 1000, "单位,请输入cm或in");

    InputBox(dcha1, 1000, "输入长");
    InputBox(dcha2, 1000, "输入宽");














}
void addpage3() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/02.png");
    putimage(0, 0, &img);
    button(630, 50, 150, 50, "返回");

    InputBox(unit, 1000, "单位,请输入cm或in");

    InputBox(dcha1, 1000, "输入边长");
}


void back() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/01.png");
    putimage(0, 0, &img);

    button(40, 250, 150, 50, "正方形");
    button(250, 250, 150, 50, "长方形");
    button(450, 250, 150, 50, "圆形");
    button(630, 250, 150, 50, "三角形");

}
void addpage4() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/02.png");
    putimage(0, 0, &img);
    button(630, 50, 150, 50, "返回");

    InputBox(unit, 1000, "单位,请输入cm或in");

    InputBox(dcha1, 1000, "输入边长");
}


















//判断鼠标的位置是否在所需要的区域 



int main() {

    back();

    //第一个画面 选择要计算的类型
    ExMessage msg;
    while (1)
    {
        if (peekmessage(&msg, EM_MOUSE))//有鼠标消息返回真，没有返回假
        {

            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
                if (msg.x >= 40 && msg.x <= 40 + 150 && msg.y >= 250 && msg.y <= 250 + 50)
                {
                    void

                        closegraph();

                    addpage1();
                    handleSquare();


                }

                if (msg.x >= 250 && msg.x <= 250 + 150 && msg.y >= 250 && msg.y <= 250 + 50)
                {
                    void

                        closegraph();

                    addpage2();
                    handleRectangle();



                }

                if (msg.x >= 450 && msg.x <= 450 + 150 && msg.y >= 250 && msg.y <= 250 + 50)
                {
                    void handleTriangle();
                    closegraph();
                    addpage3();
                }
                if (msg.x >= 630 && msg.x <= 630 + 150 && msg.y >= 250 && msg.y <= 250 + 50)
                {
                    void handleCircle();
                    closegraph();
                    addpage4();
                }
                if (msg.x >= 630 && msg.x <= 630 + 150 && msg.y >= 50 && msg.y <= 50 + 50)
                {
                    closegraph();
                    back();
                }

            default:
                break;



            }
        }
    }

    getchar();
    closegraph();
    return 0;
}








