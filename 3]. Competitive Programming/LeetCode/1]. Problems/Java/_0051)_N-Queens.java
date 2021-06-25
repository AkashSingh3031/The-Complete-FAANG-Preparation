// Link to Problem : https://leetcode.com/problems/n-queens/
class Solution {
    public List<List<String>> solveNQueens(int n) {
        // create n x n Board
        int[][] board = new int[n][n];
        List<List<String>> result = new ArrayList<>();
        solveNQueensHelper(board, 0, new ArrayList<String>(), result);
        return result;
    }

    private void solveNQueensHelper(int[][] board, int row, ArrayList<String> list, List<List<String>> result) {
        if(row == board.length) {
            result.add(new ArrayList<>(list));
            return;
        }

        for (int col = 0; col < board[0].length; col++) {
            if (isValid(board, row, col)) {

                board[row][col] = 1;
                String queenPosition = getQueenPosition(board[0].length, col);
                list.add(queenPosition);

                solveNQueensHelper(board, row + 1, list, result);

                list.remove(list.size() - 1);
                board[row][col] = 0;
            }
        }
    }

    private boolean isValid(int[][] board, int row, int col) {
        // check in all the boxes straight up the given row and column
        for(int i = row - 1, j = col; i>=0; i--) {
            if(board[i][j] == 1) {
                return false;
            }
        }

        // checking above left diagonal to see if there is any queen present already
        for(int i = row - 1, j = col-1; i>=0 && j >= 0; i--, j--) {
            if(board[i][j] == 1) {
                return false;
            }
        }

        // checking above right diagonal to see if there is any queen present already
        for(int i = row - 1, j = col + 1; i>=0 && j < board.length; i--,j++) {
            if(board[i][j] == 1) {
                return false;
            }
        }
        return true;
    }

    private String getQueenPosition(int stringLength, int queenPosition) {
        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < stringLength; i++) {
            if (queenPosition == i) {
                sb.append("Q");
            } else {
                sb.append(".");
            }
        }

        return sb.toString();
    }

    // Do not copy this method on to leetcode
    public static void main(String[] args) {
        NQueens obj = new NQueens();
        int n = 4;
        List<List<String>> result = obj.solveNQueens(n);
        System.out.println(result);
    }
}