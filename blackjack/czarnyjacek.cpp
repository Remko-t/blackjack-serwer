//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>
//#include <time.h>
//
//using namespace std;
//using namespace sf;
//
//class Karta {
//private:
//	Sprite wartoœæ;
//	int xd;
//public:
//	Karta(Sprite x, int y) : wartoœæ(x), xd(y)
//	{}
//	int punkty() {
//		return xd;
//	};
//	Sprite grafa() {
//		return wartoœæ;
//	};
//};
//
//class Talia {
//private:
//	vector<Karta> Karty;
//public:
//
//	Talia(Sprite spr[]) {
//		for (int i = 0; i < 52; i++) {
//			Karta card(spr[i], i);
//			Karty.push_back(card);
//		};
//
//	}
//	void tasowanie() {
//		srand(time(NULL));
//		random_shuffle(Karty.begin(), Karty.end());
//	};
//	Karta rozdaj() {
//		Karta Card = Karty.back();
//		Karty.pop_back();
//		return Card;
//	}
//};
//
//class Rêka {
//private:
//	vector<Karta> reka;
//public:
//	
//	void dodaj(Karta Card) {
//		reka.push_back(Card);
//	}
//	int nazwy() {
//		for (int i = 0; i < reka.size(); i++) {
//			return reka[i].punkty();
//	}
//
//	};
//
//};
//
//
//int main() {
//
//
//	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32, t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47, t48, t49, t50, t51, t52;
//	
//
//	
//	
//	
//	t1.loadFromFile("grafika/asace.png");
//	t2.loadFromFile("grafika/asdiamond.png");
//	t3.loadFromFile("grafika/asspades.png");
//	t4.loadFromFile("grafika/asclub.png");
//
//	t5.loadFromFile("grafika/2ace.png");
//	t6.loadFromFile("grafika/2diamond.png");
//	t7.loadFromFile("grafika/2spades.png");
//	t8.loadFromFile("grafika/2club.png");
//	
//	t9.loadFromFile("grafika/3ace.png");
//	t10.loadFromFile("grafika/3diamond.png");
//	t11.loadFromFile("grafika/3spades.png");
//	t12.loadFromFile("grafika/3club.png");
//	
//	t13.loadFromFile("grafika/4ace.png");
//	t14.loadFromFile("grafika/4diamond.png");
//	t15.loadFromFile("grafika/4spades.png");
//	t16.loadFromFile("grafika/4club.png");
//	
//	t17.loadFromFile("grafika/5ace.png");
//	t18.loadFromFile("grafika/5diamond.png");
//	t19.loadFromFile("grafika/5spades.png");
//	t20.loadFromFile("grafika/5club.png");
//	
//	t21.loadFromFile("grafika/6ace.png");
//	t22.loadFromFile("grafika/6diamond.png");
//	t23.loadFromFile("grafika/6spades.png");
//	t24.loadFromFile("grafika/6club.png");
//	
//	t25.loadFromFile("grafika/7ace.png");
//	t26.loadFromFile("grafika/7diamond.png");
//	t27.loadFromFile("grafika/7spades.png");
//	t28.loadFromFile("grafika/7club.png");
//	
//	t29.loadFromFile("grafika/8ace.png");
//	t30.loadFromFile("grafika/8diamond.png");
//	t31.loadFromFile("grafika/8spades.png");
//	t32.loadFromFile("grafika/8club.png");
//	
//	t33.loadFromFile("grafika/9ace.png");
//	t34.loadFromFile("grafika/9diamond.png");
//	t35.loadFromFile("grafika/9spades.png");
//	t36.loadFromFile("grafika/9club.png");
//	
//	t37.loadFromFile("grafika/10ace.png");
//	t38.loadFromFile("grafika/10diamond.png");
//	t39.loadFromFile("grafika/10spades.png");
//	t40.loadFromFile("grafika/10club.png");
//	
//	t41.loadFromFile("grafika/2ace.png");
//	t42.loadFromFile("grafika/2diamond.png");
//	t43.loadFromFile("grafika/2spades.png");
//	t44.loadFromFile("grafika/2club.png");
//	
//	t45.loadFromFile("grafika/2ace.png");
//	t46.loadFromFile("grafika/2diamond.png");
//	t47.loadFromFile("grafika/2spades.png");
//	t48.loadFromFile("grafika/2club.png");
//	
//	t49.loadFromFile("grafika/2ace.png");
//	t50.loadFromFile("grafika/2diamond.png");
//	t51.loadFromFile("grafika/2spades.png");
//	t52.loadFromFile("grafika/2club.png");
//
//	Sprite s1(t1), s2(t2), s3(t3), s4(t4), s5(t5), s6(t6), s7(t7), s8(t8), s9(t9), s10(t10), s11(t11), s12(t12), s13(t13), s14(t14), s15(t15), s16(t16), s17(t17), s18(t18), s19(t19), s20(t20), s21(t21), s22(t22), s23(t23), s24(t24), s25(t25), s26(t26), s27(t27), s28(t28), s29(t29), s30(t30), s31(t31), s32(t32), s33(t33), s34(t34), s35(t35), s36(t36), s37(t37), s38(t38), s39(t39), s40(t40), s41(t41), s42(t42), s43(t43), s44(t44), s45(t45), s46(t46), s47(t47), s48(t48), s49(t49), s50(t50), s51(t51), s52(t52);
//
//	Sprite deck[] = { s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31, s32, s33, s34, s35, s36, s37, s38, s39, s40, s41, s42, s43, s44, s45, s46, s47, s48, s49, s50, s51, s52 };
//
//	Talia tal(&deck[52]);
//	tal.tasowanie();
//	Rêka serwer;
//	Rêka serwer2;
//	serwer.dodaj(tal.rozdaj());
//	Sprite wynik = deck[serwer.nazwy()];
//	serwer2.dodaj(tal.rozdaj());
//	Sprite wynik2 = deck[serwer2.nazwy()];
//
//	RenderWindow okno(VideoMode(500, 500), "Czarny jacek");
//	
//	RectangleShape guzik1(Vector2f(100,50));
//	RectangleShape guzik2(Vector2f(100,50));
//	guzik1.setFillColor(Color(0, 255, 0));
//	guzik2.setFillColor(Color(255, 0, 0));
//	guzik1.setPosition(50, 400);
//	guzik2.setPosition(350, 400);
//	wynik.setPosition(150, 100);
//	wynik2.setPosition(300, 100);
//	
//		
//		while (okno.isOpen()) {
//			Event event;
//			while (okno.pollEvent(event))
//			{
//				if (event.type == Event::Closed)
//					okno.close();		
//			}
//			
//			
//			okno.clear();
//			okno.draw(wynik);
//			okno.draw(wynik2);
//			okno.draw(guzik1);
//			okno.draw(guzik2);
//			
//			okno.display();
//			Vector2i pozmyszki = Mouse::getPosition(okno);
//			FloatRect sprawdzanie = guzik2.getGlobalBounds();
//			Vector2f sprawdzanie2 = okno.mapPixelToCoords(pozmyszki);
//			if (sprawdzanie.contains(sprawdzanie2) && Mouse::isButtonPressed(Mouse::Left)) {
//				okno.close();
//				}
//		}
//
//
//
//	}
