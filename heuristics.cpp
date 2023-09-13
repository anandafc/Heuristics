#include <bits/stdc++.h>
using namespace std;
const int N = 500;
char grid[N][N]; // grid
pair <int, int> par[N][N];
int dis[N][N];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
class Search {
int n, m; // number of rows and columns
public:
// Constructor
void input() {
cout << "Enter number of row:" << '\n';
cin >> n;
cout << "Enter number of columns:" << '\n';
cin >> m;
for(int i = 0; i < n; i++) {
for(int j = 0; j < m; j++) {
cin >> grid[i][j];
}

}
}
// Function to check whether a position is valid
bool valid(int x, int y) {
return 0 <= x and x < n and 0 <= y and y < m ;
}
int heuristics(pair <int, int> x, pair <int, int> y) {
return abs(x.first - y.first) + abs(x.second - y.second);
}
void work(pair <int, int> x, pair <int, int> y) {
bool vis[N][N]; memset(vis, 0, sizeof vis);
memset(dis, 0, sizeof dis);
priority_queue < pair <int, pair <int, int> > > pq;
pq.push({0, {x.first, x.second}});
vis[x.first][x.second] = 1;
par[x.first][x.second] = {-1, -1};
while(!pq.empty()) {
auto cur = pq.top(); pq.pop();
int xx = cur.second.first, yy = cur.second.second;
for(int i = 0; i < 4; i++) {
int nx = xx + dx[i];
int ny = yy + dy[i];
if(!vis[nx][ny] and valid(nx, ny) and grid[nx][ny] == '.') {
dis[nx][ny] = dis[xx][yy] + 1;
vis[nx][ny] = 1;
pq.push({dis[nx][ny] + heuristics({nx, ny}, y), {nx, ny}});
par[nx][ny] = {xx, yy};
}
}
}
}
void printpath(pair <int, int> x, pair <int, int> y) {
cout << "The time needed to go from source to destination is " <<
dis[y.first][y.second] << '\n';
char cur[N][N];
for(int i = 0; i < n; i++) {
for(int j = 0; j < m; j++) {
cur[i][j] = grid[i][j];
}
}
pair <int, int> c = y;
pair <int, int> q = {-1, -1};
while(par[c.first][c.second] != q) {

cur[c.first][c.second] = '@';
c = par[c.first][c.second];
}
cur[x.first][x.second] = '@';
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
cout << cur[i][j];
}
puts("");
}
}
};
int main() {
Search x;
x.input();
x.work({0, 0}, {4, 4});
x.printpath({0, 0}, {4, 4});
}
