package io.philo.ch_1__Big_O;

import static java.lang.Math.*;

import java.util.Scanner;

public class __1C__트럭주차 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();

		int A_st = sc.nextInt();
		int A_ed = sc.nextInt();

		int B_st = sc.nextInt();
		int B_ed = sc.nextInt();

		int C_st = sc.nextInt();
		int C_ed = sc.nextInt();

		int max_ed = max(max(A_ed, B_ed), C_ed);

		int[] parking_weight_arr = new int[max_ed+1];

		for (int i = A_st; i < A_ed; i++) parking_weight_arr[i]++;
		for (int i = B_st; i < B_ed; i++) parking_weight_arr[i]++;
		for (int i = C_st; i < C_ed; i++) parking_weight_arr[i]++;

		int fare = 0;
		for (int i = 0; i <= max_ed; i++) {
			int current_parking_car_cnt = parking_weight_arr[i];

			switch (current_parking_car_cnt) {
				case 1:
					fare += A * 1;
					break;
				case 2:
					fare += B * 2;
					break;
				case 3:
					fare += C * 3;
					break;
			}
		}

		System.out.println(fare);
	}
}
