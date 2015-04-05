#include "c_sockets.h"


// TODO
void print_ip(char* host) {
	printf("TODO\n");
}

void init_udp_addrinfo(struct addrinfo* hints) {
	memset(hints, 0, sizeof(hints));
	hints.ai_family = AI_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
}

struct sockaddr* udp_socket(char* host, int* sockfd, char* port) {
	struct addrinfo* servinfo, p;
	struct addrinfo hints;
	int res;
	init_udp_addrinfo(hints);

	if ((res = getaddrinfo(host, port, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(res));
	}

	// Loop through the possible results and connect to one
	for (p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("client: socket");
			continue;
		}
		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("client: connect");
			continue;
		}
		break;
	}
	if (p == NULL) {
		fprintf(stderr, "Client couldn't connect to a scoket");
		return;
	}

	// Should have a socket connected at this point
	freeaddrinfo(servinfo);
}
