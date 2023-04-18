#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Karta {
private:
	Sprite wartoœæ;
public:
	Karta(Sprite x) : wartoœæ(x)
	{}
	Sprite punkty() {
		return wartoœæ;
	};
};





class Talia {
private:
	vector<Karta> Karty;
public:
	int i = 0;
	Talia talia(Sprite s1) {
		Sprite wartoœci[52];

		wartoœci[i] = s1;
		Karta Card(wartoœci[i]);
		Karty.push_back(Card);
		i++;
	};
	void tasowanie() {
		srand(time(NULL));
		random_shuffle(Karty.begin(), Karty.end());
	};
	Karta rozdaj() {
		Karta Card = Karty.back();
		Karty.pop_back();
		return Card;
	}
};

class Rêka {
private:
	vector<Karta> reka;
	int razem = 0;
public:
	void dodaj(Karta Card) {
		reka.push_back(Card);
	}
};

int main() {

	Talia talia;
	talia.tasowanie();


	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, t50, t51, t52;
	
	
	t1.loadFromFile("grafika/assehartowe.png");
	t2.loadFromFile("grafika/assehartowe.png");
	t3.loadFromFile("grafika/assehartowe.png");
	t4.loadFromFile("grafika/assehartowe.png");

	t5.loadFromFile("grafika/assehartowe.png");
	t6.loadFromFile("grafika/assehartowe.png");
	t7.loadFromFile("grafika/assehartowe.png");
	t8.loadFromFile("grafika/assehartowe.png");
	
	t9.loadFromFile("grafika/assehartowe.png");
	t10.loadFromFile("grafika/assehartowe.png");
	t11.loadFromFile("grafika/assehartowe.png");
	t12.loadFromFile("grafika/assehartowe.png");
	
	t13.loadFromFile("grafika/assehartowe.png");
	t14.loadFromFile("grafika/assehartowe.png");
	t15.loadFromFile("grafika/assehartowe.png");
	t16.loadFromFile("grafika/assehartowe.png");
	
	t17.loadFromFile("grafika/assehartowe.png");
	t18.loadFromFile("grafika/assehartowe.png");
	t19.loadFromFile("grafika/assehartowe.png");
	t20.loadFromFile("grafika/assehartowe.png");
	
	t21.loadFromFile("grafika/assehartowe.png");
	t22.loadFromFile("grafika/assehartowe.png");
	t23.loadFromFile("grafika/assehartowe.png");
	t24.loadFromFile("grafika/assehartowe.png");
	
	t25.loadFromFile("grafika/assehartowe.png");
	t26.loadFromFile("grafika/assehartowe.png");
	t27.loadFromFile("grafika/assehartowe.png");
	t28.loadFromFile("grafika/assehartowe.png");
	
	t29.loadFromFile("grafika/assehartowe.png");
	t30.loadFromFile("grafika/assehartowe.png");
	t31.loadFromFile("grafika/assehartowe.png");
	t32.loadFromFile("grafika/assehartowe.png");
	
	t33.loadFromFile("grafika/assehartowe.png");
	t34.loadFromFile("grafika/assehartowe.png");
	t35.loadFromFile("grafika/assehartowe.png");
	t36.loadFromFile("grafika/assehartowe.png");
	
	t37.loadFromFile("grafika/assehartowe.png");
	t38.loadFromFile("grafika/assehartowe.png");
	t39.loadFromFile("grafika/assehartowe.png");
	t40.loadFromFile("grafika/assehartowe.png");
	
	t41.loadFromFile("grafika/assehartowe.png");
	t42.loadFromFile("grafika/assehartowe.png");
	t43.loadFromFile("grafika/assehartowe.png");
	t44.loadFromFile("grafika/assehartowe.png");
	
	t45.loadFromFile("grafika/assehartowe.png");
	t46.loadFromFile("grafika/assehartowe.png");
	t47.loadFromFile("grafika/assehartowe.png");
	t48.loadFromFile("grafika/assehartowe.png");
	
	t49.loadFromFile("grafika/assehartowe.png");
	t50.loadFromFile("grafika/assehartowe.png");
	t51.loadFromFile("grafika/assehartowe.png");
	t52.loadFromFile("grafika/assehartowe.png");


	Sprite s1(t1), s2(t2), s3(t3), s4(t4), s5(t5), s6(t6), s7(t7), s8(t8), s9(t9), s10(t10), s11(t11), s12(t12), s13(t13), s14(t14), s15(t15), s16(t16), s17(t17), s18(t18), s19(t19), s20(t20), s21(t21), s22(t22), s23(t23), s24(t24), s25(t25), s26(t26), s27(t27), s28(t28), s29(t29), s30(t30), s31(t31), s32(t32), s33(t33), s34(t34), s35(t35), s36(t36), s37(t37), s38(t38), s39(t39), s40(t40), s41(t41), s42(t42), s43(t43), s44(t44), s45(t45), s46(t46), s47(t47), s48(t48), s49(t49), s50(t50), s51(t51), s52(t52);

	RenderWindow okno(VideoMode(200, 200), "Czarny jacek");
	

	while (okno.isOpen()) {
		Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == Event::Closed)
				okno.close();
		}

		okno.clear();
		okno.draw(s1);
		okno.display();
	}
}