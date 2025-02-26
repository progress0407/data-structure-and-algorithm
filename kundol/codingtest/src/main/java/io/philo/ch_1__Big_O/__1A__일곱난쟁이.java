package io.philo.ch_1__Big_O;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class __1A__일곱난쟁이 { // Main으로 바꿀것
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] heights = new int[9];

		int total = 0;

		for (int i = 0; i < 9; i++) {
			heights[i] = sc.nextInt();
			total += heights[i];
		}

		Arrays.sort(heights);

		int totalOf7 = 0;
		boolean found = false;
		int found_i=0, found_j=0;
		for (int i = 0; i < 9 - 1; i++) {
			for (int j = i + 1; j < 9; j++) {
				totalOf7 = total - (heights[i] + heights[j]);
				if (totalOf7 == 100) {
					found = true;
					found_i = i;
					found_j = j;
				}
				if(found) break;
			}
			if(found) break;
		}

		ArrayList<Integer> result = new ArrayList<>();

		for (int i = 0; i < 9; i++) {
			if (i == found_i || i == found_j) {
				continue;
			}
			result.add(heights[i]);
		}

		for (int height : result) {
			System.out.println(height);
		}
	}
}
