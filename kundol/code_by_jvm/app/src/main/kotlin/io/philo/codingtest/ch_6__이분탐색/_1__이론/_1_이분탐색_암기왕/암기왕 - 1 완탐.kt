package io.philo.codingtest.ch_6__이분탐색._1__이론._1_이분탐색_암기왕

/**
 * 이분 탐색을 이용한 풀이
 *
 * 메모리 초과
 */
fun main() {
    val t = readln().toInt()

    repeat(t) {
        readln().toInt() // 수첩 1
        val s1 = readln().split(" ").map { it.toInt() }.sorted()

        readln().toInt() // 수첩 2
        var s2 = readln().split(" ").map { it.toInt() }
//        s2 = listOf(9)

        for (target in s2) {
            // search
            val res = biSearch(s1, target, 0, s1.size - 1)
            println(res)
        }
    }
}

private fun biSearch(s1: List<Int>, target: Int, st: Int, ed: Int): Int {

    var m = (st + ed) / 2

    return if (s1[m] == target) {
        1
    } else if (st == ed) { // 더 이상 찾을 것이 없을때
        0
    } else if (s1[m] > target) {
        biSearch(s1, target, st, m - 1)
    } else {
        biSearch(s1, target, m + 1, ed)
    }
}
