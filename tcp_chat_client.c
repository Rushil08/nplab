#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
int main(){
char sendl[100];
char recvl[100];
int sockfd;
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_STREAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=htons(22000);
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
while(strncmp("exit",sendl,4)!=0 && strncmp("exit",recvl,4)!=0){
bzero(sendl,100);
bzero(recvl,100);
printf("\nTo server: ");
fgets(sendl,100,stdin);
send(sockfd,sendl,strlen(sendl),0);
recv(sockfd,recvl,100,0);
printf("From server: %s \n",recvl);


}}
