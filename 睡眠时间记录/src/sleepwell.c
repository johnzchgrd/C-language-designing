/*程序实现功能：
 *1、新建睡眠时间记录*
 *2、查询所有睡眠时间记录*
 *3、判断最近一周的睡眠时间是否达标   <35?  flag
 *4、数据加密保护->加密算法 
 *5、对日期进行排序
 *6、支持修改特定编号的记录* 
 *7、刷新数据*
 *8、自动计算睡眠时间(可借鉴之前的代码--一天之内两时间之差，输入两个4位数，不过需要优化)
 *9、智能识别输入格式（日期是否存在等） 
 *11、生成创建时间和修改时间 getdate函数，返回20190304（int类型）
 *12、支持重载文件 
 *13、支持更改周期
 *15、将数据保存到数据库中  --使用SQlite3
 */

/*
 *author: Johnzchgrd
 *
 *create-date: 2019/03/05
 *recent modification:
 *2019-08-15 Johnzchgrd: 
 *  change to 'Makefile' & correct sum7days error(actually it'sprev 6days)
 *
*/

#include <local/sleep.h>

int main()
{
  FILE *fp;
  int choice;    //选项
  char filename[MAXFILENAMELEN], today_in_hhmmss[20];
  printf("Today is:%s\n", getTimenow_str(today_in_hhmmss));
  printf("Enter file for data storage:\n");
  scanf("%s", filename);

  while ((choice = inputchoice()) != 0)
  {
    switch (choice)
    {
    case 1:
      fp = openfile(filename, "ab+");// won't open null file
      newlog(fp);
      closefile(fp);
      break;
    case 2:
      fp = openfile(filename, "rb");
      listall(fp);
      closefile(fp);
      break;
    case 3:
      fp = openfile(filename, "rb+"); //need to change open mode for merging
      correction(fp);
      closefile(fp);
      break;
    case 4:
      fp = openfile(filename, "rb");
      fresh(fp);
      closefile(fp);
      break;
    case 5:
      printf("Enter new filename:\n");
      scanf("%s", filename);
      break;
    default:
      printf("Invalid input!\n");
      break;
    }
  }

  return 0;
}
