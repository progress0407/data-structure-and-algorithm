# 공통 지식

## sort

원본 데이터를 바꾼다  
벡터, 배열 둘 다 사용 가능  
```c++
// 배열
sort(arr, arr + n);
// 벡터
sort(v.begin(), v.end();
```

## 숫자 스케일

연산량 계산시 1000만 정도는 나와야 많다고 할 수 있다


## Vector 에서 특정 원소 지우기

인덱스로 지우기
```c++
v.erase(b.begin() + 인덱스);
```

값으로 지우기 (하아..)
```c++
v.erase(remove(v.begin(), v.end(), 값),
        v.end());
```

## `exit(0);`

`return` 과 달리 main함수까지도 종료한다.  

