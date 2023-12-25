package io.philo.codingtest.ch_6__이분탐색._1__이론._2_보석상자

/**
 * N - 아이들 수
 *
 * M - 보석 수
 */
fun main() {

    val (n, m) = readln().split(" ").map { it.toInt() }

    var tot = 0
    repeat(m) {
        val num = readln().toInt()
        tot += num
    }

    println((tot / n) + 1)
}