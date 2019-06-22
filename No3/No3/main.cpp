//
//  main.cpp
//  No3
//
//  Created by 高城友豪 on 2019/06/21.
//  Copyright © 2019 高城友豪. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <queue>

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    std::cin >> N ;
    std::queue<int> q;
    std::vector<int> directions(N+1);
    q.push(1);
    directions[1]=1;
    int state=1;
    
    while (state != N) {
        int bit = std::bitset<32>(state).count();
        int v1 = state +bit, v2 = state -bit;
        if (v1 <= N && directions[v1] == 0) {
            q.push(v1);
            directions[v1] = directions[state] + 1;
        }
        if (v2 > 0 && directions[v2] == 0) {
            q.push(v2);
            directions[v2] = directions[state] + 1;
        }
        if (q.size() == 0) {
            std::cout << -1 << std::endl;
            return 0;
        }

        state = q.front();
        q.pop();
    }
    std::cout  << directions[state] << std::endl;
    return 0;
}

//        std::bitset<8>bit = std::bitset<8>(i);
//        std::cout << std::bitset<8>(8).count() << std::endl;
//        std::cout << std::bitset<8>(i) << std::endl;
//        std::cout << bit.count() << std::endl;
//        state = q.front();
