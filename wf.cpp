#include<iostream>
#include<string.h>
#include<algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <io.h>
#include<cstdio>
#include<cstdlib>
#include<io.h>
using namespace std;
int mode;
int torf=1;
struct word
{
    long long cnt;
    char W[50];
} Word[100000];
bool cmp(word a,word b)
{
    if(a.cnt>b.cnt)
        return true;
    return false;
}
char str[50];
char str1[50];
FILE *fp;
void counter(char *strtemp)
{
    long long total=0;
    long long num=0;
    fp=fopen(strtemp,"r");
    //printf("1\n");
    //fscanf(fp,"%s",str);
    //printf("%s\n", str);
    //freopen(strtemp,"r",stdin);
    while(!feof(fp))
    {
        fscanf(fp,"%s",str);
        int len=strlen(str);
        int j=0;
        for(int i=0; i<len; i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]+=32;
            }
            if(str[i]>='a'&&str[i]<='z')
            {
                str1[j++]=str[i];
            }
            else
            {
                str1[j]='\0';
                if(str1[0]=='\0')
                    continue;
                else
                    total++;
                bool flag=true;
                for(int i=0; i<num; i++)
                {
                    if(strcmp(Word[i].W,str1)==0)
                    {
                        Word[i].cnt++;
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    strcpy(Word[num].W,str1);
                    Word[num].cnt=1;
                    num++;
                }
                j=0;
            }
        }
        str1[j]='\0';
        if(str1[0]=='\0')
        {
            continue;
        }
        //else
        //{
        //    total++;
        //}

        bool flag=true;
        for(int i=0; i<num; i++)
        {
            if(strcmp(Word[i].W,str1)==0)
            {
                Word[i].cnt++;
                flag=false;
                break;
            }
        }
        if(flag)
        {
            strcpy(Word[num].W,str1);
            Word[num].cnt=1;
            num++;
        }

    }
    sort(Word,Word+num,cmp);
    //printf("1");
    if(mode==2)
    {
        printf("%s\n",strtemp);
        printf("\n");
    }
    total=num;
    if(num>20)
        num=20;
    printf("total %ld\n",total);
    for(int i=0; i<num; i++)
    {
        printf("%s %d\n",Word[i].W,Word[i].cnt);
    }
}
void fcounter()
{
    long long total=0;
    long long num=0;
    char out[50];
    getcwd(out,sizeof(out));
    strcat(out,"\\");
    strcat(out,"out.txt");
    while(~scanf("%s",str))
    {
        int len=strlen(str);
        int j=0;
        for(int i=0; i<len; i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
            {
                str[i]+=32;
            }
            if(str[i]>='a'&&str[i]<='z')
            {
                str1[j++]=str[i];
            }
            else
            {
                str1[j]='\0';
                if(str1[0]=='\0')
                    continue;
                else
                    total++;
                bool flag=true;
                for(int i=0; i<num; i++)
                {
                    if(strcmp(Word[i].W,str1)==0)
                    {
                        Word[i].cnt++;
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    strcpy(Word[num].W,str1);
                    Word[num].cnt=1;
                    num++;
                }
                j=0;
            }
        }
        str1[j]='\0';
        if(str1[0]=='\0')
        {
            continue;
        }
        //else
        //{
        //    total++;
        //}

        bool flag=true;
        for(int i=0; i<num; i++)
        {
            if(strcmp(Word[i].W,str1)==0)
            {
                Word[i].cnt++;
                flag=false;
                break;
            }
        }
        if(flag)
        {
            strcpy(Word[num].W,str1);
            Word[num].cnt=1;
            num++;
        }
    }

    sort(Word,Word+num,cmp);
    //printf("2");
    freopen(out,"w",stdout);
    //printf("3");
    total=num;
    if(num>20)
        num=20;
    printf("total %ld\n",total);
    for(int i=0; i<num; i++)
    {
        printf("%s %d\n",Word[i].W,Word[i].cnt);
    }
}
int main(int argc, char *argv[])
{
    struct _finddata_t fa;
    long fHandle;
    char string3[30];
    mode=1;
    int id;
    if(argc==2)
    {
        id=1;
        strcpy(string3,argv[1]);
        if(string3[1]==':')
            mode=2;
        if(strcmp(string3,"-s")==0)
        {
            fcounter();
            mode=3;
        }

    }
    if(argc==3)
        id=2;
    char string1[30];
    char string2[30];
    if(mode==1)
    {
        strcpy(string1,argv[id]);
        int len=strlen(string1);
        strncpy(string2,&string1[len-4],4);
        string2[4]='\0';
        if(strcmp(string2,".txt")!=0)
        {
            strcat(string1,".txt");
        }
        //printf("%s\n", string1);
        counter(string1);
    }
    else if(mode==2)
    {
        char fileN[30];
        strcpy(fileN,argv[1]);
        strcat(fileN,"\\*.txt");
        if((fHandle=_findfirst(fileN,&fa))==-1L)
        {
            printf("当前目录下没有txt文件\n");
        }
        do
        {
            counter(fa.name);
        }
        while(_findnext(fHandle,&fa)==0);
        _findclose(fHandle);
    }
    fclose(fp);
    return 0;
}
