package Algorithms;

public class HeapSort extends Sort {
	
	HeapSort(int arrSize) {
		super(arrSize);
	}
	
	HeapSort(int[] data) {
		super(data);
	}
	
	@Override
	void sort() {
		// TODO Auto-generated method stub
		heafify(arrSize-1);
	}
	
	void sort2_NDB() {
		for (int i=1; i< arrSize; i++) {
			int c=i;
			do {
				int root = (c-1)/2;
				if(data[root] < data[c]) {
					swap(root, c);
				}
				c=root;
			} while(c!=0);
		}
		
		for(int i=arrSize-1; i>=0; i--) {
			swap(0,i);
			int root=0;
			int c=1;
			do {
				c=2*root+1;
				
				if(c < i-1 && data[c] < data[c+1] ) {
					c++;
				}
				
				if(c<i && data[root] < data[c]) {
					swap(root, c);
				}
				
				root=c;
			} while(c<i);
		}
	}
	
	void heafify(int toHere) {
		if(toHere < 0)
			return;
		
		int parent;
		for(int i = toHere ; i > 0 ; i -= 2) {
			parent = (i-1)/2;
			if(i%2==1) {
				if(data[parent] < data[i]) {
					swap(parent, i);
					// print();
				}
				i--;
			}
			if(i==0)
				break;
			parent = (i-1)/2;
			if(data[i] > data[i-1]) {
				if(data[i] > data[parent]) {
					swap(i, parent);
					// print();
				}
			}
			
			else {
				if(data[i-1] > data[parent]) {
					swap(i-1, parent);
					// print();
				}
			}
		}
		
		
		swap(toHere, 0);
		// print();
		heafify(--toHere);
	}
	
	void testSortSpec(int trials) {
		double calcNum = (arrSize/2) * (Math.log(arrSize)/Math.log(2));
		System.out.println("Heap Sort");
		super.testSortSpec(trials, calcNum);
	}
	
	void testSortSpec2(int trials) {
		double result = 0;
		double calcNum = (arrSize/2) * (Math.log(arrSize)/Math.log(2));
		for(int i=0; i<trials; i++) {
			cnt_Swap = 0;
			re();
			sort2_NDB();
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









