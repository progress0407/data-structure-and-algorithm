package Algorithms;

public abstract class Sort /*implements Sort_Interface */{
		int[] data;
		int arrSize;
		// �� ���� ��������
		int cnt_Stack;
		// �ѹ� �ٲ� ������
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
		
	// sort�� ����� �� �׸񸶴� �ٸ� �ž�.
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
	
	// ÷�ڰ����� �迭�� ���Ҹ� �ٲ۴�.
	// �̶� ��/���۷��� ������ ���� Ű�� ����, �迭�� ������ ������ ����
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
		System.out.printf("+ ������ %4d �� �迭�� ���� %4d �� �׽�Ʈ�Ͽ� ������ ���� ����� ��� ���ϴ�. \t +\n", arrSize, trials);
		System.out.printf("+ ��� : %6.2f cycles    \t\t\t\t\t + \n", result);
		System.out.printf("+ �̻����� ��� : %6.2f cycle \t\t\t\t + \n", calcNum);
		System.out.println("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	}
}


interface Sort_Interface {
	public void reArrange();
	public void sort();
	public void print();
}

