 #include"sleep.h" 
long size = sizeof(struct sleepdata);
//ѡ�����
inputchoice(void){
  int mychoice;
  printf("Choose an option:\n");
  printf("1-New sleep time\n2-List all\n3-Correction\n4-Fresh(only the weekly periods sum)\n5-Reload data file\n0-Exit\n");
  scanf("%1d",&mychoice);
  return mychoice;
}
//��ȡ�ļ���¼����
long getLogcount(FILE* cfptr){
  long begin,end,count,position=ftell(cfptr);
  fseek(cfptr,0L,SEEK_SET);
  begin = ftell(cfptr);
  fseek(cfptr,size,SEEK_END);
  end = ftell(cfptr);
  count = (end - begin)/size - 1;
  fseek(cfptr,position,SEEK_SET);
  return count;
}
