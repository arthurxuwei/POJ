#include <stdio.h>  
#include <string.h>  
char s[16][85];  
int turn,k;  
void compress(int n,int t)  
{     
    int times[10]={0};
    int dec,sin;     
    size_t i;
    if(t<=15)
    {          
        for(i=0; i<strlen(s[n]); i++)          
        {            
            times[s[n][i]-'0']++;          
        }          
        k=0;          
        for(i=0; i<=9 ;i++)
        {             
            if(times[i]>9)
            {              
                dec=times[i]/10; 
                sin=times[i]%10;
                s[t][k++]=dec+'0';               
                s[t][k++]=sin+'0';                
                s[t][k++]=i+'0';             
            }  
            else if(times[i]>0)
            {  
                s[t][k++]=times[i]+'0';  
                s[t][k++]=i+'0';  
            }         
        }        
        s[t][k]='\0';
        compress(t,t+1);
    }      
}  
int main()  
{     
    int flag1,flag2,flag3,i,j;  
    while( scanf("%s",s[0])!=EOF && s[0][0]!='-')
    {         
        flag1=0;  
        flag2=0;  
        flag3=0;  
        i=0,j=0;  
        turn=1;  
        compress(0,turn);
        if(strcmp(s[0],s[1])==0)
        {          
            printf("%s is self-inventorying\n",s[0]);  
            flag1=1;
        }      
        if(!flag1)      
        {           
            for(i=1; i<15 ; i++)           
            {             
                if(strcmp(s[i],s[i+1])==0)             
                {                 
                    printf("%s is self-inventorying after %d steps\n",s[0],i);                
                    flag2=1;                
                    break;             
                }           
            }                    
            if(!flag2)           
            {                  
                for(j=1; j<16; j++)             
                {               
                    for(i=0; i<=j-2; i++)               
                    {                 
                        if(strcmp(s[j],s[i])==0)  
                        {                   
                            printf("%s enters an inventory loop of length %d\n",s[0],j-i);                   
                            flag3=1;                   
                            break;                 
                        }               
                    }                
                    if(flag3)                 
                    break;             
                }             
            }      
        }      
        if(!flag3 && !flag2 && !flag1)
        {            
            printf("%s can not be classified after 15 iterations\n",s[0]);       
        }         
        getchar();
    }    
    return 0;     
}  


