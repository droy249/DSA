import java.util.*;
import java.lang.*;
import java.io.*;

class SaddlePoint {
	public static void main(String[] args) throws java.lang.Exception{
		Scanner scn = new Scanner(System.in);
		
		System.out.print("Enter size of matrix: ");
		int n = scn.nextInt();
		
		int[][] arr = new int[n][n];
		
		System.out.println("Enter the matrix: ");
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				arr[i][j] = scn.nextInt();
		
		System.out.println(saddlePoint(arr));
	}
	
	private static String saddlePoint(int arr[][]){
		for(int i = 0; i < arr.length; ++i){
			int leastColumnIndex = 0;
			
			for(int j = 1; j < arr[i].length; ++j)
				if(arr[i][leastColumnIndex] > arr[i][j])
					leastColumnIndex = j;
				
			for(int k = 0; k < arr.length; ++k)
				if(arr[i][leastColumnIndex] < arr[k][leastColumnIndex])
					return "Invalid input";
			
			return "Saddle point is " + arr[i][leastColumnIndex];
		}
		
		return null;
	}
}
