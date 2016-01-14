//Below program uses Precomputation to solve the problem in linear time 
//Related Problem : https://www.hackerrank.com/challenges/kundu-and-tree

long long int sum = 0;      //Final Answer
B[n-1] = ct[n];
for(i=n-2;i>=0;i--) B[i] = (B[i+1] + ct[i+1])%MOD;
for(i=1;i<n-1;i++) C[i] = (ct[i+1]*B[i+1])%MOD;

D[n-2] = C[n-2];
for(i=n-3;i>=1;i--) D[i] = (D[i+1] + C[i])%MOD;

for(i=0;i<n-2;i++) sum = (sum + ct[i+1]*D[i+1])%MOD;
cout<< ( MOD + sum )%MOD<<endl;
