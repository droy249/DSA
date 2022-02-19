// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/goldmine-official/ojquestion
// Video Link: https://youtu.be/hs0lilfJ7C0?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
import java.util.Scanner;

class PathWithMaximumGold {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);
		
		System.out.print("Enter number of rows and columns: ");
		int row = scn.nextInt();
		int col = scn.nextInt();
		
		System.out.println("Enter value of each cell in matrix: ");
		int[][] arr = new int[row][col];
		for(int i = 0; i < row; ++i)
			for(int j = 0; j < col; ++j)
				arr[i][j] = scn.nextInt();
		
		System.out.println("The maximum amount of gold possible to take is: " + maxGold(arr));

		scn.close();
	}
	
	private static int maxGold(int[][] arr){
		for(int j = arr[0].length - 2; j >= 0; --j)
			for(int i = 0; i < arr.length; ++i)
				if(i == 0 && arr.length == 1)
					arr[i][j] += arr[i][j+1];
				else if(i == 0)
					arr[i][j] += Math.max(arr[i][j+1], arr[i+1][j+1]);
				else if(i == arr.length - 1)
					arr[i][j] += Math.max(arr[i][j+1], arr[i-1][j+1]);
				else 
					arr[i][j] += Math.max(arr[i][j+1], Math.max(arr[i+1][j+1], arr[i-1][j+1]));
		
		int maxGold = arr[0][0];
		for(int i = 1; i < arr.length; ++i)
			maxGold = Math.max(maxGold, arr[i][0]);
		
		return maxGold;	
	}
}
