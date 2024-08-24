
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

struct Resourse { IMAGE img_start[2]; }res;//������Ҫʹ�õ���������ͼƬ
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
    char const* dcha1;
    char const* dcha2;
    char scha[20];
}tri;
struct circle {
    double r;
    double s;
    char const* dcha1;
    char scha[20];

}cir;//���빫ʽ
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

    setbkmode(TRANSPARENT);//�������屳��͸��
    setfillcolor(BROWN);//���������ɫ
    fillroundrect(x, y, x + w, y + h, 10, 10);//���ð�ť

    char text_[50] = { 0 };//��ť������
    strcpy_s(text_, text);//����
    settextstyle(40, 0, "����");
    int tx = x + (w - textwidth(text_)) / 2;
    int ty = y + (h - textheight(text_)) / 2;
    outtextxy(tx, ty, text_);
}





void res_init(struct Resourse* res) {
    loadimage(res->img_start + 0, "resourse/image/01.png", getwidth(), getheight());

    loadimage(res->img_start + 1, "resourse/image/02.png", getwidth(), getheight());


}//����ͼƬ,�ǵø����Ը߼��ַ�������Ȼ�ᱨ��

void displayResults(struct square) {
    cout << fixed << setprecision(3);
    cout << "Square side length: " << squ.d << " cm\n";
    cout << "Square area: " << squ.s << " square cm\n";


    outtextxy(50, 50, "ѡ���ͼ����������");

    outtextxy(50, 150, "�߳�Ϊ");
    outtextxy(50, 250, "���Ϊ");

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


    outtextxy(50, 50, "ѡ���ͼ���ǳ�����");

    outtextxy(50, 150, "��Ϊ");
    outtextxy(50, 200, "��Ϊ");
    outtextxy(50, 300, "���Ϊ");


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
    outtextxy(50, 50, "ѡ���ͼ����������");

    outtextxy(50, 150, "��Ϊ");
    outtextxy(50, 200, "��Ϊ");
    outtextxy(50, 300, "���Ϊ");


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
    outtextxy(50, 50, "ѡ���ͼ����Բ��");

    outtextxy(50, 150, "ֱ��Ϊ");
    outtextxy(50, 250, "���Ϊ");

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
    tri.dcha1 = dcha1;
    tri.d = strtod(tri.dcha1, NULL);
    tri.dcha2 = dcha2;
    tri.h = strtod(tri.dcha2, NULL);

    cout << tri.d;
    cout << unit;
    if (strcmp(unit, judge) == 0) {
        tri.d = tri.d * 2.54;
        tri.h = tri.h * 2.54;
    };

    calculatetriangle(tri);
    displayResults(tri);
    stringstream ss2;
    ss2 << tri.s;
    ss2 >> tri.scha;

}


void handleCircle() {
    cir.dcha1 = dcha1;
    cir.r = strtod(cir.dcha1, NULL);
    cout << cir.r;
    cout << unit;
    if (strcmp(unit, judge) == 0) { cir.r = cir.r * 2.54; };
    cout << cir.r;
    calculatecircle(cir);
    displayResults(cir);
    stringstream ss3;
    ss3 << cir.s;
    ss3 >> cir.scha;

}

void addpage1() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/02.png");
    putimage(0, 0, &img);
    button(630, 50, 150, 50, "����");

    InputBox(unit, 1000, "��λ,������cm��in");

    InputBox(dcha1, 1000, "����߳�");
}

void addpage2() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/02.png");
    putimage(0, 0, &img);
    button(630, 50, 150, 50, "����");

    InputBox(unit, 1000, "��λ,������cm��in");

    InputBox(dcha1, 1000, "���볤");
    InputBox(dcha2, 1000, "�����");
}

void addpage3() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/02.png");
    putimage(0, 0, &img);
    button(630, 50, 150, 50, "����");

    InputBox(unit, 1000, "��λ,������cm��in");

    InputBox(dcha1, 1000, "����ֱ��");
}


void back() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/01.png");
    putimage(0, 0, &img);

    button(40, 250, 150, 50, "������");
    button(250, 250, 150, 50, "������");
    button(450, 250, 150, 50, "Բ��");
    button(630, 250, 150, 50, "������");

}
void addpage4() {
    initgraph(800, 550, EW_SHOWCONSOLE);
    IMAGE img;
    loadimage(&img, "resourse/image/02.png");
    putimage(0, 0, &img);
    button(630, 50, 150, 50, "����");

    InputBox(unit, 1000, "��λ,������cm��in");

    InputBox(dcha1, 1000, "�����");
    InputBox(dcha2, 1000, "�����");
}


//�ж�����λ���Ƿ�������Ҫ������ 



int main() {

    back();

    //��һ������ ѡ��Ҫ���������
    ExMessage msg;
    while (1)
    {
        if (peekmessage(&msg, EM_MOUSE))//�������Ϣ�����棬û�з��ؼ�
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
                    void
                        closegraph();
                    addpage3();
                    handleCircle();
                }
                if (msg.x >= 630 && msg.x <= 630 + 150 && msg.y >= 250 && msg.y <= 250 + 50)
                {
                    void
                        closegraph();
                    addpage4();
                    handleTriangle();
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








