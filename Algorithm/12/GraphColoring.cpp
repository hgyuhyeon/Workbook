#include <iostream>
typedef int index;

void m_coloring(index i);
bool promising(index i);

int n = 4, m = 3; //n = 노드의 수, m = 색깔의 수
bool W[4][4] = { 0 }; //이음선 있으면 true, 그렇지 않으면 false
int vcolor[4]; //i번째 노드에 할당된 색(1~m)
int cnt = 0; //생성되는 총 Node의 수

int main(void) {
    W[0][1] = true;
    W[1][0] = true;
    W[1][2] = true;
    W[2][1] = true;
    W[2][3] = true;
    W[3][2] = true;
    W[3][0] = true;
    W[0][3] = true;
    W[0][2] = true;
    W[2][0] = true;
    vcolor[0] = 1;
    // test graph

    m_coloring(0);
    std::cout << "생성되는 총 Node의 수: " << cnt << "개" << std::endl;
    return 0;
}

void m_coloring(index i) {
    index color;

    if (promising(i)) //색깔을 채울 수 있으면(유망하면)
        if (i == n) {
            for (int i = 0; i < n; i++)
                std::cout << i+1 << "번째 Node의 색: " << vcolor[i] << ", ";
            std::cout << std::endl;
        } else
            for (color = 1; color <= m; color++) {
                vcolor[i  + 1] = color; //다음 노드에 모든 색을 시도한다
                m_coloring(i + 1);
                cnt++;
            }
}

bool promising(index i) {
    index j = 1;
    bool switching = true;
    while (j < i && switching) {
        if (W[i][j] && vcolor[i] == vcolor[j]) //ij가 연결되어있고 그 색이 같으면
            switching = false;
        j++;
    }
    return switching;
}
