package Algorithms;

public class DP {
	int index;
	long[] dpArr = new long[110];
	
	public DP(int index) {
		this.index = index;
	}
	
	private long calc(long n) {
		if(n==1) return 1;
		if(n==2) return 1;
		return 0;
	}
	
	private long calcByDP(int n) {
		if(n==1) {
			dpArr[1] = 1L;
			return dpArr[1];
		}
		if(n==2) {
			dpArr[2] = 1L;
			return dpArr[2];
		}
		if(dpArr[n] != 0)
			return dpArr[n];
		dpArr[n] = calcByDP(n-1) + calcByDP(n-2);
		return dpArr[n];
	}
	
	void getNum() {
		long result = calc(index);
		System.out.println("result: "+ result);
	}
	
	void getNumByDP() {
		long result = calcByDP(index);
		System.out.println("result: "+ result);
	}

}
