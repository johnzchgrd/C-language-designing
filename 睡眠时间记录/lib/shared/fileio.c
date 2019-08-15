#include <local/sleep.h>

//打开文件
FILE *openfile(char filename[], char *openmode)
{
  FILE *fp;
  if ((fp = fopen(filename, openmode)) == NULL)
  {
    printf("Cannot open \"%s\" or file does not exist!\n", filename);
    exit(1);
  }
  else
    return fp;
}
void closefile(FILE *fp)
{
  if (fclose(fp))
  {
    printf("Cannot close data file!\n");
    exit(2);
  }
}
