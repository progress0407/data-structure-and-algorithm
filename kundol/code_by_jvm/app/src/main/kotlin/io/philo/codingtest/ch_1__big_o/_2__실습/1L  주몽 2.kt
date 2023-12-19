package io.philo.codingtest.ch_1__big_o._2__실습

fun main() {

    val N = readln().toInt()
    val M = readln().toInt()

    val arr = readln().split(" ").map { it.toInt() }.toTypedArray()

    var cnt: Int = 0
    for (i in 0..N - 2) {
        for (j in i + 1..N - 1) {
            if (arr[i] + arr[j] == M) {
                cnt++
            }
        }
    }
    println(cnt)
}
