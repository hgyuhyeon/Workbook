#include <iostream>
typedef int index;

void hamiltonian(index i);
bool promising(index i);

int n = 5; //n = 노드의 수
bool W[5][5] = { 0 }; //이음선 있으면 true, 그렇지 않으면 false
int vindex[5]; //경로상 i번째 노드의 인덱스
int cnt = 0; //생성되는 총 Node의 수

int main(void) {
    W[0][1] = true;
    W[0][4] = true;
    W[1][0] = true;
    W[1][2] = true;
    W[1][3] = true;
    W[1][4] = true;
    W[2][1] = true;
    W[2][3] = true;
    W[3][1] = true;
    W[3][2] = true;
    W[4][0] = true;
    W[4][1] = true;
    vindex[0] = 1;
    // test graph

    hamiltonian(0);
    std::cout << "생성되는 총 Node의 수: " << cnt << "개" << std::endl;
    return 0;
}

void hamiltonian(index i) {
    index j;
    if (promising(i))
        if (i == n - 1) {
            for (int i = 0; i < n - 1; i++)
                std::cout << i + 1 << "번째 Node의 index: " << vindex[i] << ", ";
            std::cout << std::endl;
        }
        else
            for (j = 1; j <= n - 1; j++) {
                vindex[i + 1] = j; //모든 노드의 다음 노드를 시도해 본다.
                hamiltonian(i + 1);
                cnt++;
            }
}

bool promising(index i) {
    index j = 1;
    bool switching = true;
    if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
        switching = false; //첫 번째 노드는 마지막 노드와 같아야 함
    else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
        switching = false; //i번째 노드는 i-1번째 노드와 인접해야 함
    else
        while (j < i && switching) {
            if (vindex[i] == vindex[j]) //이미 선택된 노드인지 검사
                switching = false;
            j++;
        }
    return switching;
}
