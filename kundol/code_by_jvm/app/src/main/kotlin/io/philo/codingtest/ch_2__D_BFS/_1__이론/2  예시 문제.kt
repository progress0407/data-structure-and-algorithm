package io.philo.codingtest.ch_2__D_BFS._1__이론

fun main() {

    /**
     * Q. 3 * 3 맵을 입력받아야 함.
     *
     * 이 맵은 1과 0으로 이루어져있고 {0, 0}은 무조건 1임을 보장한다.
     *
     * {0, 0}부터 4방향을 기준으로 한칸씩 탐색해나가며 방문한 정점은 다시 방문하지 않으며 방문하는 좌표를 출력하는 코드. 0은 갈 수 없는 지역.
     *
     * 1은 갈 수 있는 지역을 구현하시오.
     */

    val mapp = Array(3) { IntArray(3) }

    repeat(3) { index ->
        val intArr = readln().split(" ")
            .map { it.toInt() }
            .toIntArray()
        mapp[index] = intArr
    }

    println(mapp.contentDeepToString())
}
