package Algorithms;

public class Main {
	
	public static void main(String[] args) {
		long beforeTime = System.currentTimeMillis();
		DP dp = new DP(92);
		dp.getNumByDP();
		long afterTime = System.currentTimeMillis();
		long secDiffTime = (afterTime - beforeTime);
		System.out.println("시간차이(m): " + secDiffTime);
	}
}