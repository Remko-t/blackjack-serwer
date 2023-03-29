#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int main() {
	int Wynik, wyslijwynik;
	char odbbuf[DEFAULT_BUFLEN];
	int odbbuflen = DEFAULT_BUFLEN;
	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	//Inicjalizacja winsock

	WSADATA wsaData;
	Wynik = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (Wynik != 0) {
		cout << "Startup error";
	}
	else
		cout << "Startup ok"<<endl;

	//Tworzenie socketu serwera

	struct addrinfo *result = NULL, hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	//adres i port który bêdzie u¿ywany przez serwer

	Wynik = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (Wynik != 0) {
		cout << "getaddrinfo error";
		WSACleanup();
	}
	else
		cout << "getaddrinfo ok"<<endl;

	//Tworzenie socektu serwera do szukania po³¹czeñ klienta

	
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		cout << "Socket error" << WSAGetLastError();
		freeaddrinfo(result);
		WSACleanup();
	}
	else
		cout << "Socket ok"<<endl;

	//TCP listen socket

	Wynik = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (Wynik == SOCKET_ERROR) {
		cout << "Binding error" << WSAGetLastError();
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
	}
	else
		cout << "Binding ok"<<endl;

	freeaddrinfo(result);
	//szukanie socketu

	Wynik = listen(ListenSocket, SOMAXCONN);
	if (Wynik == SOCKET_ERROR) {
		cout << "Listen error" << WSAGetLastError();
		closesocket(ListenSocket);
		WSACleanup();
	}
	else
		cout << "Listen ok"<<endl;

	//akceptowanie socketu klienta

	
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		cout << "Accept error" << WSAGetLastError();
		closesocket(ListenSocket);
		WSACleanup();
	}
	else
		cout << "Accept ok" << endl;
	closesocket(ListenSocket);
	//odbieranie i wysy³anie sygna³u

	do {

		Wynik = recv(ClientSocket, odbbuf, odbbuflen, 0);
		if (Wynik > 0) {
			cout << "Odebrane: " << Wynik;

			wyslijwynik = send(ClientSocket, odbbuf, Wynik, 0);
			if (wyslijwynik == SOCKET_ERROR) {
				cout << "Send error" << WSAGetLastError();
				closesocket(ClientSocket);
				WSACleanup();
			}
			cout << "Wyslane: " << wyslijwynik;
		}
		else if (Wynik == 0)
			cout << "Zamykanie po³¹czenia";
		else {
			cout << "Recive error" << WSAGetLastError();
			closesocket(ClientSocket);
			WSACleanup();
		}
	} while (Wynik > 0);

	// Wy³¹czanie serwera

	Wynik = shutdown(ClientSocket, SD_SEND);
	if (Wynik == SOCKET_ERROR) {
		cout << "Shutdown error" << WSAGetLastError();
		closesocket(ClientSocket);
		WSACleanup;
	}
	else
		cout << "zamykanie ok" << endl;

	// Czyszczenie

	closesocket(ClientSocket);
	WSACleanup();
	
}