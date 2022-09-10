#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is " << x << endl;

/* vector<array<int,5>> vec; //{a,b,floor(a,b),x,y} */
vector<vector<int>> vec; //{a,b,floor(a,b),x,y}

int gcd_extended(int a, int b, int *x, int *y){
    if(a < b)
        swap(a,b);
    cout << a << ' ' << b << endl;
    if(b == 0){
        *x = 0, *y = 1;
        vec.push_back({a,b});
        return a;
    }
    int x1, y1;
    int gcd = gcd_extended(b, a%b, &x1, &y1);
    *x = y1 - (a/b) * x1;
    *y = x1;
    /* vec.push_back({a,b,a/b,x1 ,y1}); */
    vec.push_back({a,b,a/b,*y,*x}); // why inversed hmm
    return gcd;
}

//-> a * y = 1 (mod b) // gdy a < b
string to_table(){
    string ret;
    ret += "\\providecommand{\\floor}[1]{\\lfloor #1\\rfloor}\n";
    ret += "\\begin{tabular}{*{5}{r}}\n";
    ret += " a & b & $\\floor{\\frac{a}{b}}$ & x & y \\\\\n";
    ret += "\\hline\n";
    for(auto &i: vec){
        bool isnf = 0;
        for(auto &x: i){
            if(isnf){
                ret += " &";
            }
            ret += " " + to_string(x);
            isnf = 1;
        }
        ret += "\\\\\n";
    }
    ret += "\\end{tabular}\n";
    return ret;
}

int main(int argc, char *argv[]){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y;
    int a, b;
    if(argc == 3){
        a = stoi(argv[1]);
        b = stoi(argv[2]);
    }
    else{
        cin >> a >> b;
    }
    cout << gcd_extended(a, b, &x, &y) << '\n';
    reverse(vec.begin(), vec.end());
    for(auto &i : vec){
        for(auto &x: i){
            cout << x << ' ';
        }
        cout << '\n';
    }
    whatis(to_table())
}

