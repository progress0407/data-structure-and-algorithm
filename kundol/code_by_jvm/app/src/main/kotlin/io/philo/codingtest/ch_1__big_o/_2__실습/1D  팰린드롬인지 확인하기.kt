package io.philo.codingtest.ch_1__big_o._2__실습

fun main() {

    val origin = readln()
    val reversed = origin.reversed()

    val res = if(origin == reversed) 1 else 0
    println(res)
}