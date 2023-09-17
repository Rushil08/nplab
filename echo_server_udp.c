#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
int main(){
char sendline[100];
char str[100];
int listen_fd;
struct sockaddr_in servaddr,caddr;
listen_fd=socket(AF_INET,SOCK_DGRAM,0);
bzero(&servaddr,sizeof(servaddr));
socklen_t len;
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(22000);
bind(listen_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
while(1){
bzero(str,100);
len=sizeof(caddr);
recvfrom(listen_fd,str,sizeof(str),0,(struct sockaddr*)&caddr,&len);
printf("echoing back: %s",str);
strcpy(sendline,str);
sendto(listen_fd,sendline,sizeof(sendline),0,(struct sockaddr*)&caddr,sizeof(caddr));
printf("echo sent");
}
}
