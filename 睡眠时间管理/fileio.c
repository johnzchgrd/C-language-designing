//´ò¿ªÎÄ¼þ
FILE* openfile(char filename[],char*openmode){
  FILE*fp;
  if((fp = fopen(filename, openmode))==NULL){
    printf("Cannot open \"%s\"!\n",filename);
    exit(1);
  }
  else return fp;
}
void closefile(FILE* fp){
	if(fclose(fp)){
        printf("Cannot close data file!\n");
        exit(2);
      }
}
