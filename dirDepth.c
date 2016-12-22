/* Program that will help calculate the depth of the current directory */


#include <dirent.h> 
#include <stdio.h> 
#include<string.h>
int max(int a, int b)
{
    if(b>a)return b;
    else return a;
}
int max_depth(char s[])
{
    struct dirent *dir;
    DIR *d;
    char name[1000];
    d = opendir(s);
    int depth = 0;
    if(d)
    {
       while ((dir = readdir(d)) != NULL)
       {
         if(strcmp(".",dir->d_name)==0 || strcmp("..", dir->d_name)==0)
         continue;
         if((int)dir->d_type == 4)
         {
            //printf("%s [%s]\n",s,dir->d_name);
            strcpy(name, s);
            strcat(name,"/");
            strcat(name,dir->d_name);
            depth = max(depth, max_depth(name));
         }
       }
       closedir(d);
     }
     return 1+ depth;
}
        
    
int main(void)
{
  printf("%d\n",max_depth("."));

  return(0);
}
