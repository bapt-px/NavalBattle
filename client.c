#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

int main() {
	struct sockaddr_in servsocket;
	int filedesc;
	int conn;
	char message[100] = "";

	filedesc = socket(AF_INET, SOCK_STREAM, 0);
	servsocket.sin_family = AF_INET;
	servsocket.sin_port = htons(8096);

	inet_pton(AF_INET, "127.0.0.1", &servsocket.sin_addr);

	connect(filedesc, (struct sockaddr *)&servsocket, sizeof(servsocket));

	while(1) {
		printf("Enter a message: ");
		fgets(message, 100, stdin);
		send(filedesc, message, strlen(message), 0);
	}

	return 0;
}
