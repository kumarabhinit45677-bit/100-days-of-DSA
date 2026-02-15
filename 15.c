#include <stdio.h>

int main() {
    int m, n;
    
    // Read matrix dimensions
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    // Read matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Calculate primary diagonal sum
    int diagonal_sum = 0;
    for(int i = 0; i < m && i < n; i++) {
        diagonal_sum += matrix[i][i];
    }
    
    // Print result
    printf("%d\n", diagonal_sum);
    
    return 0;
}
