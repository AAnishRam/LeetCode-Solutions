/**
 * @param {number[][]} grid1
 * @param {number[][]} grid2
 * @return {number}
 */
const directions = [
  [-1, 0], // up
  [0, 1], // right
  [1, 0], // down
  [0, -1], //left
];

function dfs(matrix1, matrix2, row, col, isValid) {
  matrix2[row][col] = 0;

  for (let direction of directions) {
    const nextRow = row + direction[0];
    const nextCol = col + direction[1];

    if (
      nextRow >= 0 &&
      nextRow <= matrix2.length - 1 &&
      nextCol >= 0 &&
      nextCol <= matrix2[0].length - 1 &&
      matrix2[nextRow][nextCol] === 1
    ) {
      // check matrix1/grid1 (if at matrix2 we found land and at matrix1 we found water then we say it invalid because it's not the subisland)
      if (matrix1[nextRow][nextCol] === 0) {
        isValid[0] = false;
      }

      dfs(matrix1, matrix2, nextRow, nextCol, isValid);
    }
  }
}

var countSubIslands = function (grid1, grid2) {
  let count = 0;

  for (let row = 0; row < grid2.length; row++) {
    for (let col = 0; col < grid2[0].length; col++) {
      if (grid2[row][col] === 1 && grid1[row][col] === 1) {
        const isValid = [true]; // since boolean is value type we use array (reference type), in lower level programming language we can have more elegant solution. I try to make this solution as similar possible to my number islands solution that's why we see this a little bit ugly line of code.
        dfs(grid1, grid2, row, col, isValid);
        if (isValid[0]) {
          count++;
        }
      }
    }
  }

  return count;
};