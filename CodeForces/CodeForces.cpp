#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <forward_list>
#include <map>
#include <iomanip>

using namespace std;
// << Mostafa_Shraief >> (:
#define ll long long
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


struct Kitchen
{

    ll nb, ns, nc;

};

struct Ingredients
{

    ll ib = 0, is = 0, ic = 0;

};

struct prices
{

    ll pb, ps, pc;

};

string Recipe; ll Money, m, l, r, ans, Total_Price;

prices Price; Kitchen I_Have; Ingredients Ingredient; Kitchen I_Need;

bool good(long long x)
{

    I_Need.nb = x * Ingredient.ib;
    I_Need.ns = x * Ingredient.is;
    I_Need.nc = x * Ingredient.ic;

    I_Need.nb -= I_Have.nb;
    I_Need.ns -= I_Have.ns;
    I_Need.nc -= I_Have.nc;

    if (I_Need.nb < 0)
        I_Need.nb = 0;
    if (I_Need.ns < 0)
        I_Need.ns = 0;
    if (I_Need.nc < 0)
        I_Need.nc = 0;

    Total_Price = I_Need.nb * Price.pb + I_Need.ns * Price.ps + I_Need.nc * Price.pc;

    return Total_Price <= Money;

}



int main()
{
    turbo;

    ci Recipe;

    ci I_Have.nb >> I_Have.ns >> I_Have.nc;

    ci Price.pb >> Price.ps >> Price.pc;

    ci Money;

    int len = Recipe.length();

    for (int ind = 0; ind < len; ++ind)
    {

        if (Recipe[ind] == 'B')
            ++Ingredient.ib;
        else if (Recipe[ind] == 'S')
            ++Ingredient.is;
        else
            ++Ingredient.ic;

    }
    
    ans = l = 0, r = Money + 100;

    while (l <= r)
    {
        
        m = (l + r) / 2;

        if (good(m))
            l = m + 1, ans = m;
        else
            r = m - 1;

    }

    co ans;

}