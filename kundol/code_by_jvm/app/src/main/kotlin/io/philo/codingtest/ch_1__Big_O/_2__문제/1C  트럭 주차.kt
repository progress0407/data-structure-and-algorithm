package io.philo.codingtest.ch_1__Big_O._2__문제

fun main(args: Array<String>) {

    val (A, B, C) = readln().split(" ").map { it.toInt() }
    val fn = mapOf(Pair(0, 0), Pair(1, A), Pair(2, B * 2), Pair(3, C * 3))

    val times = mutableListOf<Time>()
    repeat(3) {
        val (st, ed) = readln().split(" ").map { it.toInt() }
        times.add(Time(st, ed - 1))
    }
    val maxIndex = times.map { it.ed }.max()

    val nums = Array<Int>(maxIndex + 1) { 0 }

    for (time in times) {
        for (i in time.st..time.ed) {
            nums[i]++
        }
    }

    val result = nums.sumOf { x -> fn[x]!! }
    println(result)
}

data class Time(val st: Int, val ed: Int)
