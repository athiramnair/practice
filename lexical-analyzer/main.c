#include <stdio.h>
#include <stdlib.h>//identify identifiers and strings(decalred ones identifiers  separately using symtab ..strings contain white spaces function with parameteres space as delimiter,header file,comments,print staemnets strings,all operators,with or without space,symtab,literals and constants,a[0]=0
#include <string.h>
#include<ctype.h>
int isfunction(char buffer[])
{
    int flag=1,i=0;
    if((buffer[0]>='a'&& buffer[0]<='z')||(buffer[0]=='_')||(buffer[0]>='A'&& buffer[0]<='Z'))
    {
        while(buffer[i]!='\0')
        {
            if((buffer[i]>='0'&& buffer[i]<='9')||(buffer[i]>='a'&& buffer[i]<='z')||(buffer[i]=='_')||(buffer[i]>='A'&& buffer[i]<='Z')||buffer[i]=='('||buffer[i]==')')
                i++;
            else
            {
                flag=0;
                return flag;
            }
        }
    }
    else
    {
        flag=0;
        return flag;
    }
    return flag;
}
int isdelimiter(char ch)
{
    if (ch == ',' || ch == ';' ||  ch == '(' || ch == ')' ||  ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return 1;
    return 0;
}
int isidentifier(char buffer[])
{
    int flag=1,i=0;
    if((buffer[0]>='a'&& buffer[0]<='z')||(buffer[0]=='_')||(buffer[0]>='A'&& buffer[0]<='Z'))
    {
        while(buffer[i]!='\0')
        {
            if((buffer[i]>='0'&& buffer[i]<='9')||(buffer[i]>='a'&& buffer[i]<='z')||(buffer[i]=='_')||(buffer[i]>='A'&& buffer[i]<='Z'))
                i++;
            else
            {
                flag=0;
                return flag;
            }
        }
    }
    else
    {
        flag=0;
        return flag;
    }
    return flag;
}
int iskeyword(char buffer[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
    int i,flag=0;
    for(i=0;i<32;i++)
    {
        if(strcmp(keywords[i],buffer)==0)
    {
        flag=1;
    }
    }
    return flag;
}
int main()
{
    FILE *fptr;
    int i,j=0;
    char ch,filename[15],aoperators[] = "+-*/%=",buffer[15];
    printf("Enter the filename to be opened : ");
    scanf("%s",filename);
    fptr=fopen(filename,"r");
    if(fptr==NULL)
    {
        printf("cannot open the file");
        exit(0);
    }
    while((ch=fgetc(fptr))!=EOF)
    {
        for(i=0;i<6;i++)
            if(ch==aoperators[i])
        {
                printf("%c is a operator\t\t",ch);
                printf("Token : {%c, }\n",ch);
        }
        if(isalnum(ch)||(ch=='('||ch==')')){
            buffer[j]=ch;
            j++;
        }
        else if((ch==' '||ch=='\n')&&(j!=0))
        {
            buffer[j]='\0';
            j=0;
            if(iskeyword(buffer)==1)
            {
                printf("%s is a keyword\t",buffer);
                printf("Token : {%s, }\n",buffer);
            }
            else if(isidentifier(buffer)==1)
            {
                printf("%s is an identifier\t",buffer);
                printf("Token : {%s, }\n",buffer);
            }
            else if(isfunction(buffer)==1)
            {
                printf("%s is a function\t",buffer);
                printf("Token : {%s, }\n",buffer);
            }
            else{
                printf("%s is an string\t",buffer);
                printf("Token : {%s, }\n",buffer);
            }
        }
        else if(isdelimiter(ch)==1)
            {
                printf("%c is a delimiter\t",ch);
                printf("Token : {%c, }\n",ch);
            }
    }
    fclose(fptr);
    return 0;
}
