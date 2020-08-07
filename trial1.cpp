#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define per(i,a,b) for (int i = (a); i >= (b); --i)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define debug(...) printf(__VA_ARGS__)
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define precise cout.precision(ldbl::max_digits10)
typedef std::numeric_limits<ld> ldbl;
main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    ll base[301][2],types[5][301][2];
    int temp;
    rep(i,1,300)
    {
        cin>>temp;
        cin>>base[i][0]>>base[i][1];
        types[0][i][0]=base[i][0];
        types[0][i][1]=base[i][1];
        rep(j,1,4)
            cin>>types[j][i][0]>>types[j][i][1];
    }
        
    int x=7;
    int y=20;
    ld reqd_xtra_rev = (x / (ld)100) * 5778972;
    ld reqd_xtra_units = (y / (ld)100) * 144328;
    vector<pair<ld,pii>> work;
    rep(i,1,300)
    {
        ll base_price=base[i][0];
        ll base_units=base[i][1];      
        rep(j,1,4)
        {
            ll xtra_rev=(types[j][i][0]*types[j][i][1])-(base_price*base_units);
            ll xtra_units=types[j][i][1]-base_units;
            ll hit=types[j][i][1]*(base_price-types[j][i][0]);
            ld parameter=xtra_rev*(ld)(xtra_units)/(ld)hit;
            work.push_back({parameter,{i,j}});
        }
    }
    sort(all(work));
    reverse(all(work));
    int used[301];
    memset(used,0,sizeof(used));
    for(auto x:work)
    {
        if(used[x.second.first])
            continue;
        int i=x.second.first;
        int j=x.second.second;
        used[i]=j;
        
        reqd_xtra_rev-=types[j][i][0]*types[j][i][1]-base[i][0]*base[i][1];
        reqd_xtra_units-=types[j][i][1]-base[i][1];
        if(reqd_xtra_rev<=0 || reqd_xtra_units<=0)
            break;    
    }




    if(reqd_xtra_rev>0)
    {
        //sort only by xtra_rev
        vector<pair<ld,pii>> work;
        rep(i,1,300)
        {
            if(used[i])
                continue;
            ll base_price=base[i][0];
            ll base_units=base[i][1];      
            rep(j,1,4)
            {
                ll xtra_rev=(types[j][i][0]*types[j][i][1])-(base_price*base_units);
                ll xtra_units=types[j][i][1]-base_units;
                ll hit=types[j][i][1]*(base_price-types[j][i][0]);
                ld parameter=xtra_rev/(ld)hit;
                work.push_back({parameter,{i,j}});
            }
        }
        sort(all(work));
        reverse(all(work));

        for(auto x:work)
        {
            if(used[x.second.first])
                continue;
            int i=x.second.first;
            int j=x.second.second;
            used[i]=j;
            
            reqd_xtra_rev-=types[j][i][0]*types[j][i][1]-base[i][0]*base[i][1];
            reqd_xtra_units-=types[j][i][1]-base[i][1];
            if(reqd_xtra_rev<=0)
                break;    
        }
        
    }



    if(reqd_xtra_units>0)
    {
        //sort only by xtra_rev
        vector<pair<ld,pii>> work;
        rep(i,1,300)
        {
            if(used[i])
                continue;
            ll base_price=base[i][0];
            ll base_units=base[i][1];      
            rep(j,1,4)
            {
                ll xtra_rev=(types[j][i][0]*types[j][i][1])-(base_price*base_units);
                ll xtra_units=types[j][i][1]-base_units;
                ll hit=types[j][i][1]*(base_price-types[j][i][0]);
                ld parameter=xtra_units/(ld)hit;
                work.push_back({parameter,{i,j}});
            }
        }
        sort(all(work));
        reverse(all(work));

        for(auto x:work)
        {
            if(used[x.second.first])
                continue;
            int i=x.second.first;
            int j=x.second.second;
            used[i]=j;
            
            reqd_xtra_rev-=types[j][i][0]*types[j][i][1]-base[i][0]*base[i][1];
            reqd_xtra_units-=types[j][i][1]-base[i][1];
            if(reqd_xtra_units<=0)
                break;    
        }
        
    }


    ll rev=0,units=0,hit=0;
    rep(i,1,300)
    {
        cout<<i<<" "<<used[i]<<endl;
        rev+=types[used[i]][i][0]*types[used[i]][i][1];
        units+=types[used[i]][i][1];
        hit+=types[used[i]][i][1]*(base[i][0]-types[used[i]][i][0]);
    }
    ld ansx=(ld)rev/5778972;
    ld ansy=(ld)units/144328;
    cerr<<100*ansx<<endl;
    cerr<<100*ansy<<endl;
    cerr<<hit<<endl;
    

}