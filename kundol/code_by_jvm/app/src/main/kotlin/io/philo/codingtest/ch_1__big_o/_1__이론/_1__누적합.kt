package io.philo.codingtest.ch_1__big_o._1__이론

class _1__누적합

//val arr: Array<IntRange> = arrayOf(1..10)
val arr: Array<Int> = arrayOf(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

fun main() {

    val result = sub_sum(1, 4)
    println("result = ${result}")
}

fun sub_sum(st: Int, ed: Int): Int {

    val sum_arr: Array<Int> = Array(11) { 0 }

    sum_arr[1] = arr[1]

    for (i in 2..ed) {
        sum_arr[i] += sum_arr[i-1] + arr[i]
    }

    return sum_arr[ed] - sum_arr[st]
}
