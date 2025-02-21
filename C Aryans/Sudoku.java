import java.util.Random;
import java.util.Scanner;

public class Sudoku {
    private static final int SIZE = 9;
    private int[][] board;

    public Sudoku() {
        board = new int[SIZE][SIZE];
    }

    // Function to print the Sudoku board
    public void printBoard(boolean showSolution) {
        for (int r = 0; r < SIZE; r++) {
            for (int d = 0; d < SIZE; d++) {
                if (showSolution) {
                    System.out.print(board[r][d] + " ");
                } else {
                    System.out.print((board[r][d] == 0 ? "X" : board[r][d]) + " ");
                }
            }
            System.out.println();
        }
    }

    // Check if a number can be placed in a given cell
    private boolean isSafe(int row, int col, int num) {
        for (int x = 0; x < SIZE; x++) {
            if (board[row][x] == num || board[x][col] == num) {
                return false;
            }
        }
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int r = 0; r < 3; r++) {
            for (int d = 0; d < 3; d++) {
                if (board[r + startRow][d + startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    // Recursive function to solve the board
    private boolean solve() {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (board[row][col] == 0) {
                    for (int num = 1; num <= SIZE; num++) {
                        if (isSafe(row, col, num)) {
                            board[row][col] = num;
                            if (solve()) {
                                return true;
                            }
                            board[row][col] = 0; // backtrack
                        }
                    }
                    return false; //  backtracking triggereing just cuz why not
                }
            }
        }
        return true; 
    }

    // Fill the board with a valid Sudoku solution
    public void fillBoard() {
        Random rand = new Random();
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int num = rand.nextInt(SIZE) + 1;
                if (isSafe(i, j, num)) {
                    board[i][j] = num;
                }
            }
        }
        solve(); // Solve the board
    }

    // Remove numbers to create the puzzle
    public void createPuzzle(int clues) {
        Random rand = new Random();
        for (int i = 0; i < SIZE * SIZE - clues; i++) {
            int row = rand.nextInt(SIZE);
            int col = rand.nextInt(SIZE);
            while (board[row][col] == 0) { // make sure that we're removing a number
                row = rand.nextInt(SIZE);
                col = rand.nextInt(SIZE);
            }
            board[row][col] = 0; // removing the number
        }
    }

    public static void main(String[] args) {
        Sudoku sudoku = new Sudoku();
        sudoku.fillBoard();
        sudoku.createPuzzle(40); // number of clues to keep

        System.out.println("Sudoku Puzzle:");
        sudoku.printBoard(false); // the puzzle with 'X' for empty cells

        Scanner scanner = new Scanner(System.in);
        System.out.println("Type 'SHOW' to see the solution:");
        String input = scanner.nextLine();
        if (input.equalsIgnoreCase("SHOW")) {
            System.out.println("Sudoku Solution:");
            sudoku.printBoard(true); // full board with solution
        }

        scanner.close();
    }
}
