# 섹션 2 메모

## 인접 연결 리스트 vs 인접 행렬 

- 대게의 경우 리스트를 사용하면 된다
- 출제자 입장에서 private TC 만드는데 정말 많은 수고로움이 든다

## DFS

아래 2가지의 경우를 외우자
- **먼저 확인**하고 방문
- **우선 방문** 후 나갈지

## BFS

- 동등한 가중치 계산할 때

## DFS vs BFS

- 대게의 경우 DFS를 사용하면 된다. 코드길이가 짧다
- 동등한 가중치가 나오고 계산이 필요하다? 그럼 이걸 쓰자

## Stack 풀이

- 크게 두 가지의 접근 법이 있는데
- 큰돌님 풀이도 좋다...
  - (괄호 풀이에 대한 가정) 스택에 쌓이는 괄호가 '(' 만 가정한다

## [ 문제 풀이 ]

## 2-A 유기농 배추

- 가중치가 모두 같은 거리 문제 -> BFS
- 따닥따닥 붙어있는거 입력받는 방법 2가지 (string, scanf)


## 2-B 유기농 배추

- 테스트 케이스 문제는, **초기화**가 중요하다
- Connected Component 문제!

## 2-C 안전 지역

- 계속 fail이 뜬다..

## 2-D 영역 구하기

- 문제와 예시가 해석이 안 된다...
- 우연히 풀고나니 큰돌님과 핵심 로직 풀이가 같다 !!

## 2-E 쿼드트리

- 분할 정보
- 재귀 돌리기

## 2-F 사과 담기 게임

- D,BFS, Div & Con 알고리즘은 딱히 아님
- 큰돌님 풀이도 나랑 같다

## 2-G 빈도 정렬

- Custom Comparator 를 이용해야 한다
- 나의 경우 구조체, 큰돌님은 Counting 배열을 이용했다

## 2-H 4659번 - 비밀번호 발음하기

- **`string.size() - 숫자`** 정말 조심해야 한다!
- 꼼꼼해야 하는 문제...

## 2-I 알파벳 개수

- 숫자로 100글자는 아주 크다!
  - int는 10글자에 블과함
  - long long -> 10^18, 19바이트 정도
- `big int` or `string` 
  - big int는 너무 번거롭다..

- public TC (O)
- private (X)

## 2-J 10709번 - 기상캐스터

- 나의 경우 prev로 풀었다
- 큰돌님은 for문 + while로 첨자값 증가로 풀었다

## 2-K 3474번 - 교수가 된 현우

- 문제풀이의 아이디어가 재미있다...
- 그림을 그리면서 찾으면 좋을 것 같다

## 2-L 2852번 - NBA 농구

- 문제가 해석이 안 된다...
- 큰 단위를 낮은 단위로 계산

## 2-M 1436번 - 영화감독 숌

- 연산 횟수가 1000만 이하라서 brute force가 가능하다
- 무식하게(브루트 포스) 풀 수 있는지 점검하자
  - 연산 수행이 천만~1억 이하
- N이 10,000이라 쳐도 660만에 불과하다

## 2-N 9012번 - 괄호

- 딱 봐도 스택인게 보인다!!
- 스택: 짝짓기, 폭발, 괄호 등

## 2-O 4949번 - 균형잡힌 세상

- 큰돌님 풀이보다 내 풀이가 더 나은 것 같다
- 앞 문제의 응용, 스택을 잘 이해하자
- 입력받는게 다소 어렵다

## 2-P 14502번 - 연구소

- 브루트 포스로 풀어도 될 것 같다는 생각이 들어야 한다
  - 64_C_3 * (64+64) 등 대강 계산했을때... 400만 천만 이하 -> 브루트 포스
- 조합의 r이 3개 이하 -> 3중 for문으로 접근
- 몇 단계를 거친다
  - 벽을 세운다
  - 바이러스를 퍼트린다
  - 남은 영역을 구한다 + 그것들의 max를 구한다

## 2-Q 2636번 - 치즈

- 개인적으로 정말 많은 코드를 작성하면서 풀었던 문제...
- 무슨 문제인지 계속 실패가 뜬다...

## 2-R 1068번 - 트리

- 행렬이 아닌 인접리스트를 떠올리면 좋다
- 지울 때 아래를 생각하자
  - 실제로 지운다
  - 실제로 지우지 않고 지웠다고 마킹하자
    - 이 문제를 이렇게 푸는게 이득인 것으로 보인다
    - (내풀이 너무 장황함)

## 2-S 1325번 - 효율적인 해킹

- 시간 복잡도가 애매하게 나온다는 것을 인지한 상태로 출발하는게 좋다
  - DFS를 생각하면 N^2, 즉 1억번 정도 나온다고 가정
  - 그러나 이 문제는 이렇게 푸는 방법 이외에는 없다고 한ㄷ
- 실수노트! visited 배열을 만들자!!

## 2-T 17298번 - 오큰수

- 내 기준에서는 외워야지 풀 수 있는 문제로 보인다... 담에는 넘어가자 ㅠ
- 스택에 값이 아닌 인덱스를 넣는게... 내가 파악하지 못한 요인 중 하나이다
  - 혼자힘으로 풀기 어려운 문제중 하나였던 듯..
- 첨엔 풀이를 봤는데 이해가 안됀다.. 하하
- O(N^2), 100만*100만 = 1조 ... 지금까지의 방법으로는 안됀다.