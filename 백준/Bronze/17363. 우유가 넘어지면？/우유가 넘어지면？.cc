#include<stdio.h>
int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    char a[100][100],b[100][100];
    for(i=0;i<n;i++)scanf("%s",a[i]);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            b[m-j-1][i]=a[i][j];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            switch(b[i][j]){
            case '-':
                b[i][j]='|';
                break;
            case '|':
                b[i][j]='-';
                break;
            case '/':
                b[i][j]='\\';
                break;
            case '\\':
                b[i][j]='/';
                break;
            case '^':
                b[i][j]='<';
                break;
            case '<':
                b[i][j]='v';
                break;
            case 'v':
                b[i][j]='>';
                break;
            case '>':
                b[i][j]='^';
                break;
            default:
                break;
            }
        }
    }
    for(i=0;i<m;i++,printf("\n"))for(j=0;j<n;j++)printf("%c",b[i][j]);
}
