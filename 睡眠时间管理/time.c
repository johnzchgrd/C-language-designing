#include<time.h>
#include<stdio.h>
#include<windows.h>
main(){
	while(1){
		 time_t now ;
        struct tm *tm_now ;
        time(&now) ;
        tm_now = localtime(&now) ;
        printf("Time now: %04d-%02d-%02d %02d:%02d:%02d\r", tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec) ;
       sleep(1);
	}
