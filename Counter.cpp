#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct word{
    int cnt;
    char W[25];
}Word[10000];
bool cmp(word a,word b){
    if(a.cnt>b.cnt)
        return true;
    return false;
}
int main()
{
    int num=0;
    char str[25];
    FILE *fp;
    fp=fopen("1.txt","r");
    //memset(Word,0,sizeof Word);
    while(!feof(fp)){
        fscanf(fp,"%s",str);
        int len=strlen(str);
        /*for(int i=0;i<len;i++){
            if(str[i]<'A'||(str[i]>'Z'&&str[i]<'a')||str[i]>'z'){
                if(i!=len-1){
                    for(int j=i;j<len-1;j++)
                        str[j]=str[j+1];
                    len--;
                }else {
                    str[i]='\0';
                }
            }

        }*/
        strcpy(Word[num].W,str);
        Word[num].cnt=1;
        num++;
        for(int i=0;i<num;i++){
            if(strcmp(Word[i].W,str)==0){
                Word[i].cnt++;
                num--;
                break;
            }
        }
    }
    sort(Word,Word+num,cmp);
    FILE *fp1;
    fp1=fopen("2.txt","w+");
    for(int i=0;i<num;i++){
        fprintf(fp1,"%s %d\n",Word[i].W,Word[i].cnt);
    }
}
