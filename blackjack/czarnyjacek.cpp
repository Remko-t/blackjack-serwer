//#include <iostream>
//#include <string>
//#include <ctime>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Karta {
//private:
//	int warto��;
//	string nazwa;
//	string kolor;
//public:
//	Karta(int x, string y, string z) : warto��(x), nazwa(y), kolor(z)
//	{}
//	void nazwakarty() {
//		cout << kolor << " " << nazwa <<" ";
//	};
//	int punkty() {
//		return warto��;
//	};
//};
//
//class Talia {
//private:
//	vector<Karta> Karty;
//public:
//	Talia() {
//		int warto�ci[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };
//		string nazwy[] = { "Dwa", "Trzy", "Cztery", "Piec", "Szczesc", "Siedem", "Osiem", "Dziewiec", "Dziesiec", "Walet", "Krolowa", "Krol", "As" };
//		string kolory[] = { "Pik", "Trefl", "Karo", "Kier"};
//		for (int i = 0; i < 13; i++) {
//			for (int j = 0; j < 4; j++) {
//				Karta Card(warto�ci[i], nazwy[i], kolory[j]);
//				Karty.push_back(Card);
//			}
//		}
//	};
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
//class R�ka {
//private:
//	vector<Karta> reka;
//	int razem=0;
//public:
//	int suma() {
//		razem = 0;
//		for (int i = 0; i < reka.size(); i++) {
//			razem += reka[i].punkty();
//		}
//		return razem;
//	}
//	void dodaj(Karta Card) {
//		reka.push_back(Card);
//	}
//	void wy�wietl() {
//		for (int i = 0; i <reka.size();i++) {
//			
//			reka[i].nazwakarty();
//			cout << reka[i].punkty()<<endl;
//		}
//
//	}
//};
//
//int main() {
//
//	string opcja;
//	Talia talia;
//	talia.tasowanie();
//	R�ka klient;
//	R�ka serwer;
//
//
//	serwer.dodaj(talia.rozdaj());
//	klient.dodaj(talia.rozdaj());
//	serwer.dodaj(talia.rozdaj());
//	klient.dodaj(talia.rozdaj());
//
//
//	cout << "Twoja reka: " << endl;
//	klient.wy�wietl();
//	cout << "Suma punktow: " << klient.suma() << endl;
//	if (serwer.suma() < 16) {
//		serwer.dodaj(talia.rozdaj());
//		cout << endl << "Reka krupiera: " << endl;
//		serwer.wy�wietl();
//		cout << "Suma punktow: " << serwer.suma() << endl << endl;
//	}
//	else {
//		cout << endl << "Reka krupiera: " << endl;
//		serwer.wy�wietl();
//		cout << "Suma punktow: " << serwer.suma() << endl << endl;
//	}
//	do {
//		cout << "Hit or stand (h/s)" << endl;
//		cin >> opcja;
//		cout << endl;
//
//	} while (opcja != "h" && opcja != "s");
//
//	if (opcja == "h") {
//		klient.dodaj(talia.rozdaj());
//		klient.wy�wietl();
//		cout << "Suma punktow: " << klient.suma() << endl;
//		if (klient.suma() > 21) {
//			cout << endl << "Przegrales es";
//		}
//		else if (klient.suma() > serwer.suma() && klient.suma() < 21) {
//			cout << "Winek";
//		}
//		else if (klient.suma() < serwer.suma() && serwer.suma() < 21) {
//			cout << "Przegrales";
//		}
//		else
//			cout << "Remis";
//	}
//	else if (opcja == "s") {
//		if (klient.suma() > serwer.suma()) {
//			cout << "Wygrales";
//		}
//		else if (klient.suma() < serwer.suma()) {
//			cout << "Przegrales";
//		}
//		else if (klient.suma() == serwer.suma())
//			cout << "Remis";
//	}
//
//}

