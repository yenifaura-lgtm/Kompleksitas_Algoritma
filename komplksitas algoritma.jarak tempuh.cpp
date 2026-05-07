#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits.h>

using namespace std;

typedef pair<int, string> Pair;

map<string, vector<Pair> > graph;

int dijkstra(string start, string end) {
    map<string, int> dist;
    priority_queue<Pair, vector<Pair>, greater<Pair> > pq;

    // Inisialisasi
    for (map<string, vector<Pair> >::iterator it = graph.begin(); it != graph.end(); ++it) {
        dist[it->first] = INT_MAX;
    }

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int jarak = pq.top().first;
        string kota = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[kota].size(); i++) {
            int jarakBaru = jarak + graph[kota][i].first;
            string kotaTujuan = graph[kota][i].second;

            if (jarakBaru < dist[kotaTujuan]) {
                dist[kotaTujuan] = jarakBaru;
                pq.push(make_pair(jarakBaru, kotaTujuan));
            }
        }
    }

    return dist[end];
}

int main() {
    graph["Jakarta"].push_back(make_pair(150, "Bandung"));
    graph["Jakarta"].push_back(make_pair(200, "Cirebon"));

    graph["Bandung"].push_back(make_pair(150, "Jakarta"));
    graph["Bandung"].push_back(make_pair(100, "Cirebon"));
    graph["Bandung"].push_back(make_pair(250, "Semarang"));

    graph["Cirebon"].push_back(make_pair(200, "Jakarta"));
    graph["Cirebon"].push_back(make_pair(100, "Bandung"));
    graph["Cirebon"].push_back(make_pair(150, "Semarang"));

    graph["Semarang"].push_back(make_pair(250, "Bandung"));
    graph["Semarang"].push_back(make_pair(150, "Cirebon"));

    string asal, tujuan;

    cout << "Masukkan Kota Asal: ";
    cin >> asal;

    cout << "Masukkan Kota Tujuan: ";
    cin >> tujuan;

    int hasil = dijkstra(asal, tujuan);

    if (hasil == INT_MAX) {
        cout << "Tidak ada jalur ditemukan." << endl;
    } else {
        cout << "Jarak terpendek: " << hasil << " km" << endl;
    }

    return 0;
}
