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
 int listen_fd;
 struct sockaddr_in servaddr,caddr;
listen_fd=socket(AF_INET,SOCK_DGRAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(22000);
socklen_t len=sizeof(caddr);
bind(listen_fd,(struct sockaddr *)&servaddr,sizeof(servaddr));
while(strncmp("exit",recvl,4)!=0 && strncmp("exit",sendl,4)!=0){
bzero(sendl,100);
bzero(recvl,100);
recvfrom(listen_fd,recvl,sizeof(recvl),0,(struct sockaddr*)&caddr,&len);
printf("From client: %s\n",recvl);
printf("\n To Client: ");
fgets(sendl,100,stdin);
sendto(listen_fd,sendl,sizeof(sendl),0,(struct sockaddr*)&caddr,len);
}
}
