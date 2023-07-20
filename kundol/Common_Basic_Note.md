# 공통 지식

## sort

원본 데이터를 바꾼다  
벡터, 배열 둘 다 사용 가능 (원본 조작)  
배열 문법이 못생김...

```c++
// 벡터
sort(v.begin(), v.end();
```

```c++
// 배열
sort(arr, arr + n);
// 0부터 n-1 인덱스의 값 변경
```


## swap

원본 자료구조의 a,b 인덱스의 값을 바꿈 (원본 조작)

```c++
// 벡터
swap(v[a], v[b]);
```

```c++
// 배열
swap(arr[a], arr[b]);
```

## reverse

```c++
string str = "abc";
reverse(str.begin(), str.end());
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

## map

map에서 첫번째 값 가져오기

```c++
mp.begin()->second
```


## Stack

```c++
if(stk.size() && stk.top())
```

stk.size() 등으로 스택에 원소 존재 유무를 먼저 체크하자.
그래야 뒷부분에 참조 에러를 막을 수 있다 

## Queue & Pair

주어진 코드
```c++
queue<pair<int, int>> q;
```

넣기

```c++
q.push({3, 4});
q.emplace(3, 4);
q.push(make_pair(3, 4));
```

꺼내기

```c++
tie(y, x) = q.front(); q.pop(); 
```

## 반례 찾기

- 최소 ~ 최대
  - 1 ~ 10
- 없거나 있거나