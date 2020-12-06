#include <iostream>
typedef int index;

void knapsack(index i, int profit, int weight);
bool promising(index i, int profit, int weight);

int W = 16, n = 4; //W = 배낭의 총 부피, n = 노드의 수
struct node {
    int p; //i번째 아이템의 profit
    int w; //i번째 아이템의 weight
};
node nd[4];

bool include[4] = { false }; //배낭 포함 여부
int maxprofit = 0;
/* maxprofit = 지금까지 찾은 최선의 해답이 주는 가치 */
int cnt = 0; //생성되는 총 Node의 수

int main(void) {
    nd[0].p = 40;
    nd[0].w = 2;
    nd[1].p = 30;
    nd[1].w = 5;
    nd[2].p = 50;
    nd[2].w = 10;
    nd[3].p = 10;
    nd[3].w = 5;
    // test

    knapsack(0, nd[0].p, nd[0].w);
    std::cout << "최선 해답의 최대 가치: " << maxprofit << std::endl;
    std::cout << "생성되는 총 Node의 수: " << cnt << "개" << std::endl;
    //예상 result: 80/12
    return 0;
}

void knapsack(index i, int profit, int weight) { 
    /* profit = 현재 노드까지 포함된 가치의 합
       weight = 현재 노드까지 포함된 무게의 합 */
    cnt++;
    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;
    }
    if (promising(i, profit, weight)) {
        include[i + 1] = true;
        //std::cout << "current profit: " << profit << ", ";
        //std::cout << "current weight: " << weight << std::endl;
        knapsack(i + 1, profit + nd[i + 1].p, weight + nd[i + 1].w);

        include[i + 1] = false;
        knapsack(i + 1, profit, weight);
    }
}

bool promising(index i, int profit, int weight) {
    index j, k;
    int totweight; float bound;
    /* totweight = 해당 노드까지 얻었을 때 구할 수 있는 무게의 합
       (단, W를 넘을 수 없음)
       bound = 해당 노드까지 얻었을 때 구할 수 있는 가치의 상한선 */
    
    if (weight >= W)
        return false;
    else {
        j = i + 1;
        bound = profit;
        totweight = weight;
        while ((j <= n) && (totweight + nd[j].w <= W)) {
            totweight += nd[j].w;
            bound += nd[j].p;
            j++;
        }
        k = j;
        if (k < n) {
            bound = bound + (W - totweight) * (nd[j].p / nd[j].w);
            //std::cout << "current totweight: " << totweight << ", ";
            //std::cout << "current bound: " << bound << std::endl;
        }
        //std::cout << "current maxprofit: " << maxprofit << std::endl;

        return bound > maxprofit;
    }
}
