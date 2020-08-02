package Algorithms;

import java.util.Arrays;

public class CountingSort extends Sort{
	final static int categoryMax = 5;
	final static int categoryMin = 1;  
	static int[] categoryArr;
	
	CountingSort(int[] data){
		super(data);
	}
	
	CountingSort(int lenOfArr){
		super(lenOfArr);
	}
	
	@Override
	void sort() {
		// category 초기화
		/*
		 * 무식한 방법이긴 하지만, 예를 들어 11~20이라면
		 * 1~10은 0으로 초기홛되고 미사용된다.
		 * 공간복잡도는 거의 신경쓰지 않는다고 가정하면.. 이렇게 짜보자.. 직관적이고 좋을 것 같다.
		 */
		categoryArr = new int[categoryMax + 1];
		
		// val은 index, 키값이 아닌 value값이야.
		for(int val : data) {
			for(int cnt = categoryMin ; cnt <= categoryMax ; cnt++) {
				if(val == cnt) {
					categoryArr[cnt]++;
					cnt_Swap++;
					continue;
				}
			}
		}
		
//		int[] result =  new int[categoryMax - categoryMin + 1];
//		result = Arrays.copyOfRange(data, categoryMin, categoryMax + 1);
		
		int[] result = new int[data.length];
		
		int i=0;
		for(int cnt = categoryMin ; cnt <= categoryMax ; cnt++) {
			for(int c=1 ; c <= categoryArr[cnt] ; c++) {
				result[i++] = cnt;
			}
		}
		data = result;
	}
	
	void testSortSpec(int trials) {
		System.out.println("Counting Sort");
		super.testSortSpec(trials, arrSize);
	}
}
