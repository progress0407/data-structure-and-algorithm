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
v.erase(remove(v.begin(), v.end(), 값), v.end());
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

## 참조 변경하기

[결론]

```c++
for (auto& r : table) {  // Note the & which means we are using a reference
    if (r.num == tmp) {
        r.cnt++;
    }
}
```

아래와 같은 코드가 있을때, 원본의 record는 수정되지 않는다

```cpp
struct Record {
    int num;
    int cnt;
    int order;
};

vector<Record> table;

    for (auto r: table) {
        if (r.num == tmp) {
            r.cnt++;
        }
    }
```

## 연속된 입력 + IO 초기화 로직

IO 초기화 로직이 있으면 정상 동작하지 않는다  

(아래 예시 코드)

```c++
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

while (true) {
    cin >> s;
    cout << s << "\n";
}
```

## `string.size() - 숫자` 는 조심해야 한다!!

underflow가 일어난다

## 알파벳인지?

```c++
isalpha(c)
```

위는 아래 코드와 같다

```c++
('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')
```

## ` ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);`

- 연속된 값을 입력 받을 때 사용하면 내 노트북에서 제대로 작동되지 않는 증상이 있다
- 그러나 코테 제출할 때는 위 코드가 있어야 정상 작동할 때가 있다
  - `https://www.acmicpc.net/problem/3474`

