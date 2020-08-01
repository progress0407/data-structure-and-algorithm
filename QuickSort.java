package Algorithms;

public class QuickSort extends Sort{
	
	QuickSort(int[] data){
		super(data);
//		System.out.println("construct of QuickSort(int[] data)");
	}
	
	QuickSort(int lenOfArr) {
		super(lenOfArr);
	}
	
	void re() {
		super.re();
	}
	
	void sort() {
		recursive_quick(0, arrSize - 1);
	}
	
	void sort_NDB() {
		quickSort_byNDB(0, arrSize - 1);
	}
	
	private void recursive_quick(int start, int end) {
		// Index out of Bounds
		if(start < 0 || start >= arrSize || end <0 || end >= arrSize)
			return;
		
		// 최악의 경우가 N^2 야
		if(cnt_Stack > arrSize * arrSize)
			return;
		
		if(start == end)
			return;
		
		
		int pivot = data[start];
		int i = start + 1;
		int j = end;
		
		// 작은 것과 큰 것을 찾아
		int smaller = -1;
		int bigger = -1;
		
		cnt_Stack++;
		
		
		
		while(i <= end && j >= start) {
			// 큰 거 찾아
			while(bigger == -1) {
				if(data[i] >= pivot || i == end) {
					bigger = data[i];
					break;
				}
				else i++;
			}
			
			while(smaller == -1) {
				if(data[j] <= pivot || j == start) {
					smaller = data[j];
					break;
				}
				else j--;
			}
			
			if(i<j && smaller != -1 && bigger != -1) {
				swap(i, j);
				smaller = -1;
				bigger = -1;
//				print("chng");
			}
			// cross하면 pivot값을 작은값과 바꾸고 멈출거야.
			else if(!(i<j)) {
				swap(start, j);
//				print("pivCh");
//				System.out.printf("cnt : %d  \n", cnt_Stack);
//				break;
				recursive_quick(start, j - 1);
				recursive_quick(j + 1 , end);
				return;
			}
		}
	}
	
	void quickSort_byNDB(int start, int end) {
		if (start >= end) 
			return;
		
		int key = start;
		int i = start + 1, j = end, temp;
		
		while (i <= j) {
			while(i <= end && data[i] <= data[key]) 
				i++;
			while(j>start && data[j] >= data[key])
				j--;
			if(i>j) {
				temp = data[j];
				data[j] = data[key];
				data[key] = temp;
			}
			else {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
		quickSort_byNDB(start, j - 1);
		quickSort_byNDB(j + 1, end);
	}
	
	void testSortSpec(int trials) {
		double calcNum = arrSize * (Math.log(arrSize)/Math.log(2));
		System.out.println("Quick Sort");
		super.testSortSpec(trials, calcNum);
	}
	
	void testSortSpec2(int trials) {
		double result = 0;
		double calcNum = arrSize * (Math.log(arrSize)/Math.log(2));
		for(int i=0; i<trials; i++) {
			cnt_Swap = 0;
			re();
			sort();
			result += cnt_Swap;
		}
		result /= (double)trials;
		System.out.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		System.out.printf("+ 사이즈 %4d 의 배열에 대해 %4d 번 테스트하여 다음과 같은 결과를 얻었 습니다. \t +\n", arrSize, trials);
		System.out.printf("+ 결과 : %6.2f cycles \t\t\t\t\t + \n", result);
		System.out.printf("+ 이상적인 결과 : %6.2f cycle \t\t\t\t + \n", calcNum);
		System.out.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	}
}