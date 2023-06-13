package Algorithms;

public class MergeSort extends Sort{
	
	int[] mergedArr = new int [arrSize];
	int divCnt = 0;
	
	MergeSort(int lenOfArr) {
		super(lenOfArr);
	}
	
	MergeSort(int[] data) {
		super(data);
	}
	
	@Override
	void sort() {
		// TODO Auto-generated method stub
		divide(0, arrSize-1);
	}
	
	void divide(int start, int end) {
		System.out.printf("%d �� divide �߽��ϴ�. \n", ++divCnt);
		
		// ũ�Ⱑ 1�̸� ������
		// ũ�Ⱑ 1�� �ƴ϶�� => ũ�Ⱑ 1�� �� �� ����
		if (start==end)
			return;
		
		int mid = (start + end) / 2;
		
		// int�� �� �� 1.5�� �Ҽ����� ������ ��.. �׷��� �� �� �κ��� �� �ֵ��� ����.
		divide(start, mid);
		divide(mid+1, end);
		merge(start, mid, end);
		
	}
	
	void merge(int start, int mid, int end) {
		// ���� �迭�� ���� ÷�ھ�
		int i = start;
		// ������
		int j = mid + 1;
		// ��� �迭�� ÷��
		int k = start;
		while(i<=mid && j <= end) {
			// ���� ���� �����͸� �־�
			if(data[i] < data[j]) {
				mergedArr[k++] = data[i++];
				print(mergedArr);
			} else {
				mergedArr[k++] = data[j++];
				print(mergedArr);
			}
		}
		// ���� �׿� �����Ͱ� ������ �־������.
		while(i<=mid) {
			mergedArr[k++] = data[i++];
			print(mergedArr);
		}
		
		while(j<=end) {
			mergedArr[k++] = data[j++];
			print(mergedArr);
		}
		
		for(int l = start ; l <= end ; l++) {
			data[l] = mergedArr[l];
		}
	}
}








