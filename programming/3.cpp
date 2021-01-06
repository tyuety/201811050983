#include <iostream> 
 using namespace std;
  
  int main(int argc, char *argv[])
  {   
      int n,c[305]={0},m[305]={0},e[305]={0},i,j,s[305]={0},x[305]={0};
      cin>>n;
      for(i=1;i<=n;i++)
     {
         cin>>c[i];
         cin>>m[i];
         cin>>e[i];
         s[i]=c[i]+m[i]+e[i];
         x[i]=i;
     }
   for(i=1;i<n;i++)
     {
         for(j=i+1;j<=n;j++)
         {
             if(s[i]<s[j])
          {
                swap(s[i],s[j]);
                 swap(c[i],c[j]);
                 swap(x[i],x[j]);
             }
            else if(s[i]==s[j])
             {
                 if(c[i]<c[j])
                 {
                     swap(s[i],s[j]);
                     swap(c[i],c[j]);
                     swap(x[i],x[j]);
                   
                 }
                 else if(c[i]==c[j])
                 {
                     if(x[i]>=x[j])
                     {
                         swap(s[i],s[j]);
                         swap(c[i],c[j]);
                         swap(x[i],x[j]);
                     }
                 }
             }
         }
     }
     for(i=1;i<=5;i++)
     {
         cout<<x[i]<<" "<<s[i]<<endl;
     }
    return 0;
 }
