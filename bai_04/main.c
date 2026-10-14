x = a;
y = b;
while(y!=0){
    r = x % y;
    x = y;
    y = r;
}
printf("%d", a / x * b);
