#include <iostream>
#include <vector>
using namespace std;

class B{
    int n;
    int* i;
    public:
    B(int n = 8): n(n), i(new int(55)){if(n == 0) throw n;}
    ~B(){cout << "DB"; }
};

class V{
    vector<int> v;
    public:
        V() {
            for(int i=0;i<10;i++) {
                v.push_back(i);
            }
        }
        int& operator [](int i) {
            return v[i];
        }

        int at(int i) const {
            return v[i];
        }
        friend ostream& operator<< (ostream& out, const V& v) {
            for(auto &x:v.v) {
                out<<x<<' ';
            }
            return out;
        }
};

int main()
{
   
   V v;
   v[5] = 100;
    cout<<v;
    cout<<v.at(5);
    return 0;
}
