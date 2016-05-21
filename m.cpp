
#include <stdio.h>

void hanoi(int,int,int,int);
void move(int,int,int);

int pie[20][3];
int sp[3],N;

int main(void)
{
    int i;
    
    printf("枚数 ? ");
    scanf("%d",&N);
    
    //準備
    for(i=0;i<N;i++)
        pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;
    
    hanoi(N,0,1,2);
    return 0;
}

void hanoi(int n,int a,int b,int c)
{
    //nが0以上の時
    if(n>0) {
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}

void move(int n,int s,int d)
{
    int i,j;
    
    pie[sp[d]][d]=pie[sp[s]-1][s];
    sp[d]++;
    sp[s]--;
    
    printf("\nNo.%d %cから%cへ移動\n",n,'a'+s,'a'+d);
    for(i=N-1;i>=0;i--) {
        for(j=0;j<3;j++) {
            if(i<sp[j])
                printf("%8d",pie[i][j]);
            else
                printf("        ");
        }
        printf("\n");
    }
    printf("\n       a       b       c\n");

}



/*
#include <stdio.h>
#include <vector>

int count = 3;
int A[3], B[3], C[3];

void Hanoi(const int n, int from[], int work[], int dist[]);
void Move(const int n, int from[], int to[]);
void Initialize(const int size, int a[]);

//下から0 1 2
//円盤は大きい順で1 2 3

int main()
{
    
    Initialize(count, A);
    Initialize(count, B);
    Initialize(count, C);

    for(int i = 0; i < count; ++i)
    {
        A[i] = i + 1;
    }
    
    printf("%d %d %d\n", A[0], A[1], A[2]);

    Hanoi(count, A, B, C);

    return 0;
}

void Hanoi(const int n, int from[], int work[], int dist[])
{
    if(n > 0){
        Hanoi(n-1, from, dist, work);
        
        printf("A %d %d %d\n", from[2], from[1], from[0]);
        printf("B %d %d %d\n", work[2], work[1], work[0]);
        printf("C %d %d %d\n", dist[2], dist[1], dist[0]);
        printf("\n");
        
        Move(n, from, work);
        Hanoi(n-1, dist, work, from);
    }
}


void Move(const int n, int from[], int to[])
{
    const int a = 0;
    
    //from[n]の数字がtoより小さい場合はNG
    //大きい場合は、一つ上に入れる。もしそこに数字がある場合は同じ事をする。
    if(from[n] > to[0])
    {
        if(from[n] > to[1])
        {
            if(from[n] > to[2])
            {
                int tmp = from[n];
                from[n] = to[2];
                to[2] = tmp;
            }
            int tmp = from[n];
            from[n] = to[1];
            to[1] = tmp;
        }
        int tmp = from[n];
        from[n] = to[0];
        to[0] = tmp;
    }

    
}

void Trans(int from[])
{
    
}

void Initialize(const int size, int a[])
{
    for(int i = 0; i < size; ++i)
    {
        a[i] = 0;
    }

}
*/
/*
//円盤123 0は存在しない
int a[3], b[3], c[3];


void move(int n, int from[], int to[]);
 
 from->work
 from->to
 work->to
 
*/

