package Algorithms;

public class BubbleSort extends Sort {
	BubbleSort(int[] data) {
		super(data);
	}
	
	BubbleSort(int lenOfArr) {
		super(lenOfArr);
	}
	
	void sort() {
		for(int i=0; i < arrSize - 1; i++) {
			for(int j=0; j < arrSize - 1; j++) {
				if(data[j] > data[j + 1]) {
					swap(j, j+1);
				}
			}
		}
	}
	
	void testSortSpec(int trials) {
		System.out.println("Bubble Sort");
		super.testSortSpec(trials, arrSize * arrSize);
	}
}
