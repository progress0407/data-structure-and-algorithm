package Algorithms;

import java.util.Arrays;

public class Main {
	final static int categoryMax = 5;
	final static int categoryMin = 1;
	final static int categorySize = categoryMax - categoryMin + 1;  
	static int[] categoryArr;
	
	public static void main(String[] args) {
		int[] data = { 1, 3, 2, 4, 3, 2, 5, 3, 1, 2, 3, 4, 4, 3, 5, 1, 2, 3, 5, 2, 3, 1, 4, 3, 5, 1, 2, 1, 1, 1 };
		CountingSort cs = new CountingSort(data);
		cs.testSortSpec(50);
	}
}