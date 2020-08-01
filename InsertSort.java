package Algorithms;

public class InsertSort extends Sort {
	InsertSort(int[] data) {
		super(data);
	}
	
	InsertSort(int lenOfArr) {
		super(lenOfArr);
	}
	
	// ³ª ¤¾
	void sort() {
		for(int pick=0; pick < arrSize; pick++) {
			for(int i=0; i < arrSize; i++) {
				if(data[i] > data[pick]) {
					
					if(pick < i) {
						for(int j=pick; j<i; j++) {
							swap(j, j+1);
//							print();
						}
					}
					else {
						for(int j = pick ; j > i; j--) {
							swap(j, j - 1);
//							print();
						}
					}
				}
			}
		}
	}
	
	// ³ªµ¿ºó´Ô ¤¾
	void sort2() {
		for(int i=0; i < arrSize - 1 ; i++) {
			int j = i;
			while(data[j] > data[j+1]) {
				swap(j,j+1);
//				print();
				j--;
				if(j < 0)
					break;
			}
		}
	}
	
	void testSortSpec(int trials) {
		System.out.println("Insert Sort");
		super.testSortSpec(trials, arrSize * arrSize);
	}
}
