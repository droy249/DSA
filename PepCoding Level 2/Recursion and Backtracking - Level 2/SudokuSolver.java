public class SudokuSolver {
    public static void main(String[] args) {
        char[][] board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };

        solveSudoku(board, 0 ,0);
        for (char[] row : board) {
            for (char cell : row) {
                System.out.print(cell + " ");
            }
            System.out.println();
        }
    }

    private static void solveSudoku(char[][] board, int i, int j) {
        if (j == board[0].length) {
            i = i + 1;
            j = 0;
        } else {
            // i = i;
            j = j + 1;
        }

        if (board[i][j] != '.') {
            solveSudoku(board, i, j);
        } else {
            for (char po = '1'; po <= '9'; po++) {
                if (isValid(board, i, j, po)) {
                    board[i][j] = po;
                    solveSudoku(board, i, j);
                    board[i][j] = '.';
                }
            }
        }
    }

    private static boolean isValid(char[][] board, int r, int c) {
        if (r < 0 || r >= 9 || c < 0 || c >= 9) {
            return;
        }

        for (char ch = '1'; ch <= '9'; ch++) {
            
        }
    }
}
