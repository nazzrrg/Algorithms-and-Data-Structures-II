#include <iostream>
#include <queue>

int map[100][100];

struct point{
    point(int i, int i1, int i2) {
        x = i1;
        y = i;
        d = i2;
    }

    int x;
    int y;
    int d;
};

int main() {
//    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);

    int m,n;
    std::cin >> n >> m;
    char c;
    struct point start(0,0,0), end(0,0,0);

    std::cin.get(c);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin.get(c);
            switch (c) {
                case '.':
                    map[i][j] = INT32_MAX;
                    break;
                case '#':
                    map[i][j] = -1;
                    break;
                case 'S':
                    map[i][j] = 0;
                    start.x = j;
                    start.y = i;
                    start.d = 0;
                    break;
                case 'T':
                    map[i][j] = INT32_MAX;
                    end.x = j;
                    end.y = i;
                    break;

                default: {

                }
            }
        }
        std::cin.get(c);
    }

    std::queue<point> q;
    q.push(start);

    while (!q.empty()) {
        struct point point = q.front();
        q.pop();

        if (point.x == end.x && point.y == end.y) {
            break;
        }

        if (point.x + 1 < m && map[point.y][point.x + 1] == INT32_MAX) {
            map[point.y][point.x + 1] = point.d + 1;
            struct point p(point.y, point.x + 1, point.d + 1);
            q.push(p);
        }
        if (point.x - 1 >= 0 && map[point.y][point.x - 1] == INT32_MAX) {
            map[point.y][point.x - 1] = point.d + 1;
            struct point p(point.y, point.x - 1, point.d + 1);
            q.push(p);
        }
        if (point.y + 1 < n && map[point.y + 1][point.x] == INT32_MAX) {
            map[point.y + 1][point.x] = point.d + 1;
            struct point p(point.y + 1, point.x, point.d + 1);
            q.push(p);
        }
        if (point.y - 1 >= 0 && map[point.y - 1][point.x] == INT32_MAX) {
            map[point.y - 1][point.x] = point.d + 1;
            struct point p(point.y - 1, point.x, point.d + 1);
            q.push(p);
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            std::cout << map[i][j] << ' ';
//        }
//        std::cout << std::endl;
//    }

    if (map[end.y][end.x] == INT32_MAX) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::cout << map[end.y][end.x] << std::endl;

    std::string s;
    int x = end.x, y = end.y;
    while (x != start.x || y != start.y) {
        if (x - 1 >= 0 && map[y][x-1] + 1 == map[y][x]) {
            s = 'R' + s;
            x--;
            continue;
        }
        if (y - 1 >= 0 && map[y-1][x] + 1 == map[y][x]) {
            s = 'D' + s;
            y--;
            continue;
        }
        if (y + 1 < n && map[y+1][x] + 1 == map[y][x]) {
            s = 'U' + s;
            y++;
            continue;
        }
        if (x + 1 < n && map[y][x+1] + 1 == map[y][x]) {
            s = 'L' + s;
            x++;
            continue;
        }
    }

    std::cout << s;

    return 0;
}
