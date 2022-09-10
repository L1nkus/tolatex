#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is " << x << endl;

/* vector<array<int,5>> vec; //{a,b,floor(a,b),x,y} */
/* vector<vector<int64_t>> vec; //{a,b,floor(a,b),x,y} */
vector<vector<string>> vec; //{a,b,floor(a,b),x,y}

int64_t powmod(int64_t a, int64_t b, int64_t mod){
    if(b == 0){
        return 1;
    }
    /* vec.push_back({a, b}); */
    if(b & 1){
        int64_t prev = powmod(a,b^1,mod);
        int64_t res = (a * prev) % mod;
        /* int64_t res = (a * powmod(a,b^1,mod)) % mod; */
        /* vec.push_back({res, b^1}); */
        /* vec.push_back({a, b, res}); */
        vec.push_back({to_string(a), to_string(b), "$"+to_string(a) + " \\cdot " + to_string(prev) + " \\mod " + to_string(mod) + " = " + to_string(res)+"$"});
        return res;
    }
    int64_t origa = a;
    a = powmod(a,b >> 1,mod);
    int64_t res = a*a % mod;
    /* vec.push_back({origa, b, res}); */
    vec.push_back({to_string(origa), to_string(b), "$"+to_string(a) + " \\cdot " + to_string(a) + " \\mod " + to_string(mod) + " = " + to_string(res)+"$"});
    /* vec.push_back({a*a,b >> 1}); */
    return (a*a)%mod;
}

int64_t poww(int64_t a, int64_t b){
    if(b == 0){
        return 1;
    }
    /* vec.push_back({a, b}); */
    if(b & 1){
        int64_t prev = poww(a,b^1);
        int64_t res = a * prev;
        /* int64_t res = a * poww(a,b^1); */
        /* vec.push_back({a, b, res}); */
        vec.push_back({to_string(a), to_string(b), "$" + to_string(a) + " \\cdot " + to_string(prev) + " = " + to_string(res)+"$"});
        return res;
    }
    int64_t origa = a;
    a = poww(a,b >> 1);
    /* vec.push_back({a*a,b >> 1}); */
    /* vec.push_back({origa, b, a*a}); */
    vec.push_back({to_string(origa), to_string(b), "$"+to_string(a) + " \\cdot " + to_string(a) + " = " + to_string(a*a) + "$"});
    return a*a;
}

//-> a * y = 1 (mod b) // gdy a < b
string to_table(){
    string ret;
    ret += "\\providecommand{\\floor}[1]{\\lfloor #1\\rfloor}\n";
    ret += "\\begin{tabular}{*{3}{r}}\n";
    ret += " a & b & $a^b$ \\\\\n"; // dodaj mod if cza
    ret += "\\hline\n";
    for(auto &i: vec){
        bool isnf = 0;
        for(auto &x: i){
            if(isnf){
                ret += " &";
            }
            /* ret += " " + to_string(x); */
            ret += " " + x;
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
    int a, b, m;
    cin >> a >> b >> m;
    /* if(argc == 3){ */
    /*     a = stoi(argv[1]); */
    /*     b = stoi(argv[2]); */
    /* } */
    /* else{ */
    /*     cin >> a >> b; */
    /* } */
    powmod(a,b,m);
    /* poww(a,b); */
    reverse(vec.begin(), vec.end());
    whatis(vec.size())
    whatis(to_table())
}

