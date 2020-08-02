package Algorithms;

public abstract class Sort /*implements Sort_Interface */{
		int[] data;
		int arrSize;
		// 한 바퀴 돌때마다
		int cnt_Stack;
		// 한번 바뀔 때마다
		int cnt_Swap;
		
	Sort(){
//		System.out.println("construct of Sort()");
		cnt_Stack = 0;
		cnt_Swap = 0;
		
	}
	
	Sort(int[] data){
		this();
		this.data = data;
		this.arrSize = data.length;
		
//		System.out.println("construct of Sort(int[] data)");
	}
	
	// auto-increasement by array
	Sort(int lenOfArr){
		this();
		this.data = new int[lenOfArr];
		this.arrSize = data.length;
		
		for(int i=0; i< lenOfArr ; i++) {
			data[i] = i+1;
		}
	}
		
	// sort의 기능은 각 항목마다 다를 거야.
	abstract void sort() ;
	
	void re() {
		reArrange();
	}
	
	private void reArrange() {
		for (int i=0 ; i<2*arrSize ; i++) {
			int t1 = (int)Math.floor(arrSize * Math.random());
//			System.out.print("t1 : " + t1);
			int t2 = (int)Math.floor(arrSize * Math.random());
//			System.out.printf("  t2 : %d \n", t2);
			
			swap(t1,t2);
		}
	}
	
	void print() {
		System.out.printf("\t print : ");
		for(int i=0; i< arrSize ; i++) {
			System.out.printf("%4d", data[i]);
		}
		System.out.println();
	}
	
	void print(String str) {
		System.out.printf(str + "\t print : ");
		for(int i=0; i< arrSize ; i++) {
			System.out.printf("%4d", data[i]);
		}
		System.out.println();
	}
	
	void print(int[] arr) {
		for(int i=0; i< arr.length ; i++) {
			System.out.printf("%4d", arr[i]);
		}
		System.out.println();
	}
	
	// 첨자값으로 배열의 원소를 바꾼다.
	// 이때 값/레퍼런스 성질에 따라 키는 유지, 배열의 값에는 변경이 얼어난다
	void swap(int i1, int i2) {
		int temp = this.data[i1];
		this.data[i1] = this.data[i2];
		this.data[i2] =  temp;
		cnt_Swap++;
	}
	
	void test() {
		re();
		System.out.printf("Test   ");
		print();

		sort();
		System.out.printf("Result ");
		print();
	}
	
	void testSortSpec(int trials, double calcNum) {
		double result = 0;
		for(int i=0; i<trials; i++) {
			cnt_Swap = 0;
			re();
			sort();
//			result += cnt_Stack;
			result += cnt_Swap;
		}
		result /= (double)trials;
		
		System.out.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		System.out.printf("+ 사이즈 %4d 의 배열에 대해 %4d 번 테스트하여 다음과 같은 결과를 얻었 습니다. \t +\n", arrSize, trials);
		System.out.printf("+ 결과 : %6.2f cycles    \t\t\t\t\t + \n", result);
		System.out.printf("+ 이상적인 결과 : %6.2f cycle \t\t\t\t + \n", calcNum);
		System.out.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	}
}


interface Sort_Interface {
	public void reArrange();
	public void sort();
	public void print();
}

