#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
         char write[100];
   
        system( "shutdown -s -t 60");      //关机命令,这个60是秒数,可根据情况设定.
 gt:
        printf( "快说你是猪!不然就关机!\n" );
        scanf( "%s", write);                
         if (strcmp(write, "我是猪" ) == 0)     //strcmp是字符串比较函数
        {
                printf( "哈哈,你是猪~\n" );
                system( "shutdown -a");
        }
        else
        {
                printf( "还不说是吧?不说就等关机!\n" );
                goto gt;         //goto语句，程序会跳转到带有gt标志的地方进行执行
        }
        return 0;
}