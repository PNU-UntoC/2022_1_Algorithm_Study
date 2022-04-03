#include <stdio.h>

int a,b;

int Rev(int x){
    int y,z,v,k;
    if(x<10){
        return x;
    }

    else if(x<100){
        y = x%10;
        x = y*10+x/10;
        return x;
    }
    else if(x<1000){
        y = x%10;
        z = (x%100)/10;
        v = x/100;
        x = v+ z*10 +y*100;
        return x;

    }
    else{
        y = x%10;
        z = (x%100)/10;
        v = (x%1000)/100;
        k = x/1000;
        x = k+10*v+ z*100 +y*1000;
        return x;

    }
}

int main()
{
    int c;
    scanf("%d %d",&a,&b);
    b = Rev(b);
    a = Rev(a);
    c = a+b;
    c = Rev(c);
    printf("%d",c);
}
