package io.philo.ch_1__Big_O;

import java.util.Scanner;

public class __1B__알파벳개수 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String inputStr = sc.nextLine();
		char[] charArray = inputStr.toCharArray();
		int[] alphabetArr = new int[26];

		for (char ch : charArray) {
			int ascii_idx = ch - 'a';
			alphabetArr[ascii_idx]++;
		}

		for (int alphabetCount : alphabetArr) {
			System.out.print(alphabetCount + " ");
		}
	}
}
