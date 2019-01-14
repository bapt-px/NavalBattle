#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {

	struct sockaddr_in servsocket;
	int filedesc;
	int conn;
	char message[100] = "";

	servsocket.sin_family = AF_INET;
	servsocket.sin_port = htons(8096);
	servsocket.sin_addr.s_addr = INADDR_ANY;

	filedesc = socket(AF_INET, SOCK_STREAM, 0);

	bind(filedesc, (struct sockaddr *)&servsocket, sizeof(servsocket));
	listen(filedesc,5);
	printf("connected");

	while(conn = accept(filedesc, (struct sockaddr *) NULL, NULL)) {
		int pid;
		if((pid = fork()) == 0) {
			while(recv(conn, message, 100, 0)>0) {
				printf("Message Received from %d: %s\n", conn, message);
				message[0] = '\0';
			}
			exit(0);
		}
	}

	return 0;
}
