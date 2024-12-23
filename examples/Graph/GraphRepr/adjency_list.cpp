#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>


using namespace std;


class Graph {
    public:
        map<int, set<int>> adj_list;

        void add_edge(int a, int b) {
            if(adj_list.count(a) <= 0) adj_list[a] = {};
            if(adj_list.count(b) <= 0) adj_list[b] = {};

            adj_list[a].insert(b);
            adj_list[b].insert(a);
        }

        void show() {
            for(auto el: adj_list) 
            {
                cout<<el.first<<": ";
                for(auto x: el.second) cout<<x<<", ";
                cout<<endl;
            }
        }

};


int main() {
    Graph g, g1;

    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(4, 5);
    g.add_edge(5, 3);
    g.add_edge(4, 3);
    g.add_edge(4, 3);
    g.add_edge(2, 3);
    g.show();

    g1.show();

    return 0;
}
