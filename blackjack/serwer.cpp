#define WIN32_LEAN_AND_MEAN

#include <SFML/Graphics.hpp>
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <ctime>
#include <vector>
#include <algorithm>


using namespace std;
using namespace sf;

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

class Karta {
private:
	int warto��;
	string nazwa;
	string kolor;
public:
	Karta(int x, string y, string z) : warto��(x), nazwa(y), kolor(z)
	{}
	string nazwakarty() {
		return kolor + " " + nazwa;
	};
	int punkty() {
		return warto��;
	};
};

class Talia {
private:
	vector<Karta> Karty;
public:
	Talia() {
		int warto�ci[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };
		string nazwy[] = { "Dwa", "Trzy", "Cztery", "Piec", "Szesc", "Siedem", "Osiem", "Dziewiec", "Dziesiec", "Walet", "Krolowa", "Krol", "As" };
		string kolory[] = { "Pik", "Trefl", "Karo", "Kier" };
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 4; j++) {
				Karta Card(warto�ci[i], nazwy[i], kolory[j]);
				Karty.push_back(Card);
			}
		}
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
class R�ka {
private:
	vector<Karta> reka;
	int razem = 0;
public:
	int suma() {
		razem = 0;
		for (int i = 0; i < reka.size(); i++) {
			razem += reka[i].punkty();
		}
		return razem;
	}
	void dodaj(Karta Card) {
		reka.push_back(Card);
	}
	int pkt() {
		int j = 0;
		for (int i = 0; i < reka.size(); i++) {
			j += reka[i].punkty();
		}
		return j;
	}
	void nazwy() {
		for (int i = 0; i < reka.size();i++) {
			cout<<reka[i].nazwakarty()<<endl;
		};
		}
		
};

class Klient {
private:
	SOCKET socket;
public:
	Klient(SOCKET x) : socket(x) {}

	void wyslstr(string wiadomosc) {
		send(socket, wiadomosc.c_str(), size(wiadomosc), 0);
	}
	string odbstr() {
		char odbior[4096];
		ZeroMemory(odbior, 4096);
		recv(socket, odbior, size(odbior), 0);
		return odbior;
	}
	void wyslint(int wartosc) {
		send(socket, (char*)&wartosc, sizeof(wartosc), 0);
	}
	int odbint() {
		int wartosc;
		recv(socket, (char*)&wartosc, sizeof(wartosc), 0);
		return wartosc;
	}
	void wyslijkarte(R�ka reka) {
		
	}
};

void gra(Klient *kl) {

	Talia talia;
	talia.tasowanie();
	R�ka klient;
	R�ka serwer;
 
	

		klient.dodaj(talia.rozdaj());	
		serwer.dodaj(talia.rozdaj());
		klient.dodaj(talia.rozdaj());
		serwer.dodaj(talia.rozdaj());
		serwer.nazwy();
		klient.nazwy();

		cout<<klient.suma()<<endl;
		int sm=klient.suma();
		sm = ntohl(sm);
		kl->wyslint(sm);
		sm = serwer.suma();
		sm = ntohl(sm);
		kl->wyslint(sm);

		string odb = kl->odbstr();
		cout << odb;

		if (odb == "h") {

		}
		else if (odb == "s") {

		}
		


		

}
int main() {

		int Wynik, wyslijwynik;
		char odbbuf [DEFAULT_BUFLEN];
		int odbbuflen = DEFAULT_BUFLEN;
		SOCKET ListenSocket = INVALID_SOCKET;
		SOCKET ClientSocket = INVALID_SOCKET;

		//Inicjalizacja winsock

		WSADATA wsaData;
		Wynik = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (Wynik != 0) {
			cout << "Startup error";
		}

		//Tworzenie socketu serwera

		struct addrinfo* result = NULL, hints;
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		//adres i port kt�ry b�dzie u�ywany przez serwer

		Wynik = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
		if (Wynik != 0) {
			cout << "getaddrinfo error";
			WSACleanup();
		}


		//Tworzenie socektu serwera do szukania po��cze� klienta

		ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if (ListenSocket == INVALID_SOCKET) {
			cout << "Socket error" << WSAGetLastError();
			freeaddrinfo(result);
			WSACleanup();
		}

		//TCP listen socket

		Wynik = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
		if (Wynik == SOCKET_ERROR) {
			cout << "Binding error" << WSAGetLastError();
			freeaddrinfo(result);
			closesocket(ListenSocket);
			WSACleanup();
		}

		freeaddrinfo(result);
		//szukanie socketu

		Wynik = listen(ListenSocket, SOMAXCONN);
		if (Wynik == SOCKET_ERROR) {
			cout << "Listen error" << WSAGetLastError();
			closesocket(ListenSocket);
			WSACleanup();
		}

		//akceptowanie socketu klienta


		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			cout << "Accept error" << WSAGetLastError();
			closesocket(ListenSocket);
			WSACleanup();
		}

		//odbieranie i wysy�anie sygna�u


		Klient klient(ClientSocket);
		gra(&klient);


		// Wy��czanie serwera

		Wynik = shutdown(ClientSocket, SD_BOTH);
		if (Wynik == SOCKET_ERROR) {
			cout << "Shutdown error" << WSAGetLastError();
			closesocket(ClientSocket);
			WSACleanup();
		}
		// Czyszczenie

		closesocket(ClientSocket);
		WSACleanup();

	
}