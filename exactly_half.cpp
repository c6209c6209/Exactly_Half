#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool partition_half (int w[], int total_sum, int n);

int main()
{
    int T, n;
    int w[1001];
    int total_sum = 0;
    bool ans = false;

    scanf("%d", &T);

    while(T--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &w[i]);
            total_sum += w[i];
        }
        ans = partition_half(w, total_sum, n);
        if(ans == true){
            printf("Yes\n");
        }
        else{
            printf("QAQ\n");
        }
        total_sum = 0;
        ans = false;
    }

    return 0;
}

bool partition_half (int w[], int total_sum, int n){
    if (total_sum % 2 != 0)
        return false;

    int x = total_sum/2 + 1;
    int y = n + 1;
    bool dynamic_half[x][y];

    for (int i = 1; i < x; i++){
        dynamic_half[i][0] = false;
    }
    for (int i = 0; i < y; i++){
        dynamic_half[0][i] = true;
    }

    for (int i = 1; i < y; i++){
        for (int j = 1; j < x; j++){
            if (j >= w[i-1]){
                dynamic_half[j][i] = dynamic_half[j][i-1] || dynamic_half[j-w[i-1]][i-1];
                if(j==x-1 && dynamic_half[j][i] == true){
                    return true;
                }
            }
            else{
                dynamic_half[j][i] = dynamic_half[j][i-1];
            }
        }
    }
    return dynamic_half[x-1][y-1];
}
