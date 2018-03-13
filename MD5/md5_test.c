/*************************************************************************
	> File Name: md5_test.c
	> Author: crazycuo
	> Mail: crazycuo@cisco.com 
	> Created Time: Wed Jan 31 21:13:04 2018
 ************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "md5.h"

int main(int argc, char *argv[])
{
	int i;
	unsigned char encrypt[] ="d131dd02c5e6eec4693d9a0698aff95c 2fcab58712467eab4004583eb8fb7f89 55ad340609f4b30283e488832571415a 085125e8f7cdc99fd91dbdf280373c5b d8823e3156348f5bae6dacd436c919c6 dd53e2b487da03fd02396306d248cda0 e99f33420f577ee8ce54b67080a80d1e c69821bcb6a8839396f9652b6ff72a70";
	unsigned char decrypt[16];    
	MD5_CTX md5;
	MD5Init(&md5);         		
	MD5Update(&md5,encrypt,strlen((char *)encrypt));
	MD5Final(&md5,decrypt);        
	printf("加密前:%s\n加密后:",encrypt);
	for(i=0;i<16;i++)
	{
		printf("%02x",decrypt[i]);
	}
	
	getchar();
	
	return 0;
}

