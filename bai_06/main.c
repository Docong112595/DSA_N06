int ktra(int n){
  if(n<=0) return 0;
  int s=0;
  for(int i=0; i<n/2; i++){
    if(n%i==0)
      s+=i;
  }
  if(s==n) return 1;
  return 0;
}
