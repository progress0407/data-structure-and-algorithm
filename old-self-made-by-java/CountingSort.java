package Algorithms;

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
		// { 1, 3, 2, 4, 3, 2, 5, 3, 1, 2, 3, 4, 4, 3, 5, 1, 2, 3, 5, 2, 3, 1, 4, 3, 5, 1, 2, 1, 1, 1 }
		// category �ʱ�ȭ
		/*
		 * ������ ����̱� ������, ���� ��� 11~20�̶��
		 * 1~10�� 0���� �ʱ��U�ǰ� �̻��ȴ�.
		 * �������⵵�� ���� �Ű澲�� �ʴ´ٰ� �����ϸ�.. �̷��� ¥����.. �������̰� ���� �� ����.
		 */
		categoryArr = new int[categoryMax + 1];
		
		// val�� index, Ű���� �ƴ� value���̾�.
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
