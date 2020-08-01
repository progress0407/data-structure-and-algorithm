package Algorithms;

public class SelectionSort extends Sort{

	SelectionSort(int[] data){
		super(data);
	}
	
	SelectionSort(int lenOfArr){
		super(lenOfArr);
	}
	
	@Override
	void sort() {
		// TODO Auto-generated method stub
		int min_i;
		for (int i=0; i < arrSize - 1 ; i++) {
			for (int j = i+1; j < arrSize ; j++) {
				min_i = i;
				if(data[min_i] > data[j]) {
					min_i = j;
				}
				swap(min_i, i);
			}
		}
	}
	
	void testSortSpec(int trials) {
		System.out.println("Selection Sort");
		super.testSortSpec(trials, arrSize * arrSize);
	}
}
