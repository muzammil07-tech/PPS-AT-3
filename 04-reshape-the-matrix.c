int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int rows = matSize;
    int cols = matColSize[0];
    if (rows * cols != r * c) {
        *returnSize = rows;
        *returnColumnSizes = (int*)malloc(rows * sizeof(int));
        for (int i = 0; i < rows; i++) (*returnColumnSizes)[i] = cols;
        return mat;
    }
    int** ans = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    int k = 0;
    for (int i = 0; i < r; i++) {
        ans[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
        for (int j = 0; j < c; j++) {
            ans[i][j] = mat[k / cols][k % cols];
            k++;
        }
    }
    *returnSize = r;
    return ans;
}
