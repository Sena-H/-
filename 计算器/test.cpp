
/*��дһ����������ҳ��
��һ�� ѡ�������������״������ �ڵ����ͬ����״����ת����ͬ��ҳ��
�ڶ�ҳ���������ε���� 
����ҳ���㳤���ε���� 
����ҳ����Բ����� 
���ڵ����⣺

�󲿷ֹ�������ɣ���ʾ�����ȵ�������������
---�������ڶ���


*/
#define _CRT_SECURE_NO_WARNING
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
}tri;
struct circle {
    double r;
    double s;

}cir;//���빫ʽ
void calculatesquare(struct square) {
    squ.s = squ.d * squ.d;
    outtextxy(250, 250, squ.s);
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
}

void displayResults(struct rectangle) {
    cout << fixed << setprecision(3);
    cout << "Rectangle length: " << rec.d1 << " cm\n";
    cout << "Rectangle width: " << rec.d2 << " cm\n";
    cout << "Rectangle area: " << rec.s << " square cm\n";
}

void displayResults(struct triangle) {
    cout << fixed << setprecision(3);
    cout << "Triangle base: " << tri.d << " cm\n";
    cout << "Triangle height: " << tri.h << " cm\n";
    cout << "Triangle area: " << tri.s << " square cm\n";
}

void displayResults(struct circle) {
    cout << fixed << setprecision(3);
    cout << "Circle diameter: " << cir.r << " cm\n";
    cout << "Circle area: " << cir.s << " square cm\n";
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
    cout << rec.s;
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

    InputBox(dcha1, 1000, "����߳�");
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

    InputBox(dcha1, 1000, "����߳�");
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



                    outtextxy(50, 50, "ѡ���ͼ����������");

                    outtextxy(50, 150, "�߳�Ϊ");
                    outtextxy(50, 250, "���Ϊ");
                    outtextxy(50, 350, squ.scha);

                    cout << squ.scha;

                    cout << squ.s;
                }

                if (msg.x >= 250 && msg.x <= 250 + 150 && msg.y >= 250 && msg.y <= 250 + 50)
                {
                    void

                        closegraph();

                    addpage2();
                    handleRectangle();



                    outtextxy(50, 50, "ѡ���ͼ���ǳ�����");

                    outtextxy(50, 150, "�߳�Ϊ");
                    outtextxy(50, 250, "���Ϊ");
                    outtextxy(50, 350, rec.scha);

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








