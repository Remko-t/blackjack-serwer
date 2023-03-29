#define WIN32_LEAN_AND_MEAN

#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>

using namespace std;

#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mswsock.lib")
#pragma comment(lib, "advapi32.lib")

int main1(int argc, char **argv) {
	
	int Wynik;
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	char recivebuf[DEFAULT_BUFLEN];
	int recivebuflen = DEFAULT_BUFLEN;
	const char *sendbuf = "Test";

	if (argc != 2) {
		cout << "cos" << argv[0];
	}
	
	//inicjalizacja winsock

	Wynik = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (Wynik != 0) {
		cout << "Startup error";
	}


	struct addrinfo *wyn = NULL, *wsk = NULL, hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	//adress i port servera

	Wynik = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &wyn);
	if (Wynik != 0) {
		cout << "getaddrinfo error";
		WSACleanup();
	}

	// próby po³¹czenia a¿ siê uda

	for (wsk = wyn; wsk != NULL; wsk->ai_next) {

		//Tworzenie socketu do po³¹czenia z serwerem

		ConnectSocket = socket(wsk->ai_family, wsk->ai_socktype, wsk->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			cout << "socket error" << WSAGetLastError();
			WSACleanup();
		}
		
		// Po³¹czenie

		Wynik = connect(ConnectSocket, wsk->ai_addr, (int)wsk->ai_addrlen);
		if (Wynik == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}
	freeaddrinfo(wyn);
	if (ConnectSocket == INVALID_SOCKET) {
		cout << "Nieuda³o siê po³¹czyæ";
		WSACleanup();
	}

	//Wysy³anie inicjalizera

	Wynik = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (Wynik == SOCKET_ERROR) {
		cout << "Send error" << WSAGetLastError();
		closesocket(ConnectSocket);
		WSACleanup();
	}

	cout << "Wys³ane: " << Wynik;

	//Zamykanie

	Wynik = shutdown(ConnectSocket, SD_SEND);
	if (Wynik == SOCKET_ERROR) {
		cout << "Shutdown error" << WSAGetLastError();
		closesocket(ConnectSocket);
		WSACleanup();
	}

	do {
		Wynik = recv(ConnectSocket, recivebuf, recivebuflen, 0);
		if (Wynik > 0) {
			cout << "Otrzymane: " << Wynik;
		}
		else if (Wynik == 0) {
			cout << "Zamkniêto po³¹czenie";
		}
		else
			cout << "Recive error";
	} while (Wynik > 0);

	closesocket(ConnectSocket);
	WSACleanup();
	return 1;
}
