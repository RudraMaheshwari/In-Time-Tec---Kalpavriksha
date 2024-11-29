#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    char s[100];
    printf("Enter the expression for evaluation: ");
    scanf("%[^\n]",s);

    int arr_num[100],index_num=0,index_op=0;
    char arr_op[100];
    int digit=0;
    int i,j,k;
    for(i=0;s[i]!='\0';i++)
    {
        char ch=s[i];
        if(isspace(ch))
        {
            continue;
        }
        if(isdigit(ch))
        {
            digit=digit*10+(ch-'0');
        }
        else
        {
            arr_num[index_num++]=digit;
            digit=0;
            if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
            {
                arr_op[index_op++]=ch;
            }
            else
            {
                printf("Error: Invalid expression.\n");
                return 1;
            }
        }
    }
    arr_num[index_num++]=digit;

    for(i=0;i<index_op;i++)
    {
        if(arr_op[i]=='/')
        {
            if(arr_num[i+1]==0)
            {
                printf("Error: Division by zero.\n");
                return 1;
            }
            arr_num[i]=arr_num[i]/arr_num[i+1];
            for(j=i+1;j<index_num-1;j++)
            {
                arr_num[j]=arr_num[j+1];
            }
            for(k=i;k<index_op-1;k++)
            {
                arr_op[k]=arr_op[k+1];
            }
            index_num--;
            index_op--;
            i--;
        }
    }

    for(i=0;i<index_op;i++)
    {
        if(arr_op[i]=='*')
        {
            arr_num[i]=arr_num[i]*arr_num[i+1];
            for(j=i+1;j<index_num-1;j++)
            {
                arr_num[j]=arr_num[j+1];
            }
            for(k=i;k<index_op-1;k++)
            {
                arr_op[k]=arr_op[k+1];
            }
            index_num--;
            index_op--;
            i--;
        }
    }

    int result=arr_num[0];
    for(i=0;i<index_op;i++)
    {
        if(arr_op[i]=='+')
        {
            result+=arr_num[i+1];
        }
        else if(arr_op[i]=='-')
        {
            result-=arr_num[i+1];
        }
    }

    printf("Result: %d\n",result);
    return 0;
}