//Priority queue的預設是從大到小
//Comp裡面寫<時: 大排到小
//          > 時: 小排到大
class Comp {
public:
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    }
};

int main{
    priority_queue<pair<string,int>, vector<pair<string,int>>, Comp> pq; //priority queue define method
    return 0;
}
 