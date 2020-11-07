1.stoi => string to int

2.substr(int start), substr(int start, int len)

3.find(string s) => find first index of s 
  find_last_of(string s) => find the last index of s

4.insert(str.begin(),string s) => str.push_front(s)





**Vector initialize
1.
int main()
{
    // Create an empty vector 
    vector<int> vect;

    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);

    for (int x : vect)
        cout << x << " ";

    return 0;
}

2.
int main()
{
    int n = 3;

    // Create a vector of size n with 
    // all values as 10. 
    vector<int> vect(n, 10);

    for (int x : vect)
        cout << x << " ";

    return 0;
}

3.
int main()
{
    vector<int> vect{ 10, 20, 30 };

    for (int x : vect)
        cout << x << " ";

    return 0;
}

4.
int main()
{
    int arr[] = { 10, 20, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> vect(arr, arr + n);

    for (int x : vect)
        cout << x << " ";

    return 0;
}

5.
int main()
{
    vector<int> vect1{ 10, 20, 30 };

    vector<int> vect2(vect1.begin(), vect1.end());

    for (int x : vect2)
        cout << x << " ";

    return 0;
}

**vector<vector<int>> initialize 
1.
int main()
{
    // Initializing 2D vector "vect" with 
    // values 
    vector<vector<int> > vect{ { 1, 2, 3 },
                               { 4, 5, 6 },
                               { 7, 8, 9 } };

    // Displaying the 2D vector 
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }

    return 0;
}

2.
int main() {
    int n = 3;
    int m = 4;

    // Create a vector containing n 
    //vectors of size m.  
    vector<vector<int> > vec(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

