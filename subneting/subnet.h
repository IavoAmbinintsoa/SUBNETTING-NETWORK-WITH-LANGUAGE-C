#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

char *charIp(int ip);
unsigned int int_Ip(char *IP);
int *fillmasque(int netmask);
void test_adress();
bool validbytes(int byte);
int IPReseau(int octect,int *masque);
bool verify(char *IP);
int *to_binary(int a);
void divisionSR(char *IP,int netmask);
void detail_of_IP(char *IP);
int broadcast(int octect,int *masque);
char *cat(int a,int b,int c,int d);