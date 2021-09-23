#include <unistd.h>
#include <getopt.h> 
/*
      关于getopt()函数的几点说明
      int getopt(int argc, char * const argv[], const char *optstring);
          对于输入命令行参数的处理，可以采用有限状态机来处理
      当返回值为-1时，退出循环。否则返回具体参数值
          optstring = "da:b:c::";
          d代表后面没有参数
          a后边必须存在参数，且格式必须为 ./a.out -a xin（关键是空格）
          c后面的参数可选， 若存在参数必须为 ./a.out -cxin (无空格)
          采用optarg全局变量可以获取到 参数后面的内容
      opterr关闭显示错误信息
*/

int main(int argc, char *argv[])
{
  int opt;
  
  opterr = 0; //不显示getopt的错误信息
  while((opt = getopt(argc, argv, "ab:c::") != 1) {
    switch(opt) {
      case: 'a': printf("a = %s\n", optarg);
        break;
      case: 'b': printf("b = %s\n", optarg);
        break;
      case: 'c': printf("c = %s\n", optarg);
        break;
      defalut:
        break;
    }
  }
  
  return 0;
}
