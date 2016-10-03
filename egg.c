#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
int main(int argc, char *argv[])
{
int socket_desc , new_socket ,c;
struct sockaddr_in server , client;
char *message;
char *mt;
time_t mytime = time(NULL);
socket_desc = socket(AF_INET , SOCK_STREAM , 0);
if (socket_desc == -1)
{
printf("Could not create socket");
}
server.sin_addr.s_addr = INADDR_ANY;
server.sin_family = AF_INET;
server.sin_port = htons(1025);
//Connect to remote server
if (bind(socket_desc , (struct sockaddr *)&server , sizeof (server))< 0)
{
puts ("bind failed");
}
puts ("bind done");
//Listen
listen(socket_desc, 3);
//Accept and incoming connection
puts("Wating for incoming connections...");
c = sizeof(struct sockaddr_in);
new_socket = accept(socket_desc,(struct sockaddr *)&client, (socklen_t*)&c);
if(new_socket<0)
{
perror("accept failed");
}
puts("Connection accepted");



message = ctime(&mytime);
write(new_socket , message , strlen(message));
return 0;
}
