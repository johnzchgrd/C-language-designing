//选择操作
inputchoice(void){
  int mychoice;
  printf("Choose an option:\n");
  printf("1-New sleep time\n2-List all\n3-Correction\n0-Exit\n");
  scanf("%1d",&mychoice);
  return mychoice;
}
//获取文件记录总数
long getLogcount(FILE*cfptr){
  long begin,end,count;
  fseek(cfptr,0L,SEEK_SET);
  begin = ftell(cfptr);
  fseek(cfptr,size,SEEK_END);
  end = ftell(cfptr);
  count = (end - begin)/size - 1;
  return count;
}
