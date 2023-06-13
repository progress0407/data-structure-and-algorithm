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
		System.out.printf("%d 번 divide 했습니다. \n", ++divCnt);
		
		// 크기가 1이면 하지마
		// 크기가 1이 아니라면 => 크기가 1이 될 때 까지
		if (start==end)
			return;
		
		int mid = (start + end) / 2;
		
		// int로 할 시 1.5등 소수점은 절삭이 돼.. 그래서 앞 단 부분을 더 주도록 하자.
		divide(start, mid);
		divide(mid+1, end);
		merge(start, mid, end);
		
	}
	
	void merge(int start, int mid, int end) {
		// 왼쪽 배열의 시작 첨자야
		int i = start;
		// 오른이
		int j = mid + 1;
		// 결과 배열의 첨자
		int k = start;
		while(i<=mid && j <= end) {
			// 작은 쪽의 데이터를 넣어
			if(data[i] < data[j]) {
				mergedArr[k++] = data[i++];
				print(mergedArr);
			} else {
				mergedArr[k++] = data[j++];
				print(mergedArr);
			}
		}
		// 만일 잉여 데이터가 있으면 넣어줘야해.
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








