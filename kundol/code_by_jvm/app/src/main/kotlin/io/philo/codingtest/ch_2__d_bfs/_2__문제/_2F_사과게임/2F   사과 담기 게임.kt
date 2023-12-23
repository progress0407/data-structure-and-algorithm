package io.philo.codingtest.ch_2__d_bfs._2__문제._2F_사과게임

/**
 * n: 스크린 크기
 *
 * m: 바구니 크기
 *
 * k: 떨어지는 사과의 갯수
 */
fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val k = readln().toInt()

    var bs = 1 // 바구니 시작 위치, baguni start
    var be = m // 바구니 끝위치
    var totMoveCnt = 0 // 이동 횟수

    repeat(k) {
        val apple = readln().toInt()
        if (apple in bs..be) {
            // nothing
        } else {
            // 오른쪽에 있을 경우
            if (be < apple) {
                val moveCntToNeed = apple - be
                totMoveCnt += moveCntToNeed
                bs += moveCntToNeed
                be += moveCntToNeed
            }
            // 왼쪽에 있을 경우
            else if (bs > apple) {
                val moveCntToNeed = bs - apple
                totMoveCnt += moveCntToNeed
                bs -= moveCntToNeed
                be -= moveCntToNeed
            }
        }
    }

    println(totMoveCnt)
}