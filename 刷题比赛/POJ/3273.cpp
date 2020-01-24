        #include<iostream>
        #include<algorithm>
        using namespace std;
        const int N = 1e5+5;
        int n,m;
        int a[N];
        int solve(int x)
        {
            int tmp = 0;
            int ans = 1;   
            for(int i = 1;i<=n;i++)
            {
              if(tmp + a[i] > x)
              {
                 ans++;
                 tmp = a[i];
              }
              else tmp += a[i];
            }
            return ans <= m;
        } 
        int main ()
        {
            cin>>n>>m;
            int sum = 0;
            for(int i= 1;i<=n;i++)
              {cin>>a[i];sum += a[i];}
            int l = *max_element(a+1,a+n+1);
            int r = sum;
            while(l < r)
            {
                int mid = (l+r)>>1;
                if(solve(mid)) r = mid;
                else l = mid + 1;
            }
            cout<<l<<endl;
            return 0 ;
        }