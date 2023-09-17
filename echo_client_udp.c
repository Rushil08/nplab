#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
int main(){
char sendl[100],recvl[100];
int sockfd=socket(AF_INET,SOCK_DGRAM,0);
struct sockaddr_in servaddr;
bzero(&servaddr,sizeof(servaddr));
socklen_t len=sizeof(servaddr);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=htons(22000);
while(1){
bzero(sendl,100);
bzero(recvl,100);
printf("To server: ");
fgets(sendl,100,stdin);
sendto(sockfd,sendl,sizeof(sendl),0,(struct sockaddr*)&servaddr,len);
recvfrom(sockfd,recvl,sizeof(recvl),0,(struct sockaddr*)&  servaddr,&len);
printf("received: %s",recvl);
}
}
