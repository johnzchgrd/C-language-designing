#include"sleep.h" 
long getDatenow(void) {
	time_t now;
	long date;
	struct tm* datenow;//define struct to store time information
	time(&now);
	datenow = localtime(&now);
	date = (datenow->tm_year + 1900)*10000 + (datenow->tm_mon + 1) * 100 + datenow->tm_mday;
	return date;
}
long getTimenow_long(void) {
	time_t now;
	long Time;
	struct tm* timenow;//define struct to store time information
	time(&now);
	timenow = localtime(&now);
	Time = timenow->tm_hour*10000 + timenow->tm_min*100 + timenow->tm_sec;
	return Time;
}
char* getTimenow_str(char Time[]) {
	time_t now;
	struct tm* timenow;//define struct to store time information
	time(&now);
	timenow = localtime(&now);
	//yyyy-mm-dd hh-mm-ss\0
	sprintf(Time,"%04d-%02d-%02d %02d:%02d:%02d",
		timenow->tm_year + 1900,
		timenow->tm_mon + 1,
		timenow->tm_mday,
		timenow->tm_hour, 
		timenow->tm_min, 
		timenow->tm_sec);
	return Time;
}