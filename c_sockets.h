/*
	A library to create easy functions to connect to sockets
	in C

	Author: Kyle Aisho
	Copyright 2015
	Licensed under the MIT Open Source license
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

/*
 * Prints the IP address for a host on the command line
 */
 void print_ip(char* hostname);
 
 /*
  * Initialize addrinfo to UDP and passive
  */
 void init_udp_adrinfo(struct addrinfo*);

  /*
   * Connect to UDP scoket and listen
   */ 
 struct addrinfo* udp_socket(char*, int*, char*);

