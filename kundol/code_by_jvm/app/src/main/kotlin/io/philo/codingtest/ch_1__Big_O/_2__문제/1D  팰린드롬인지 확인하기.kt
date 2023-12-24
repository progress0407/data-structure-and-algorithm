package io.philo.codingtest.ch_1__Big_O._2__문제

fun main() {

    val origin = readln()
    val reversed = origin.reversed()

    val res = if(origin == reversed) 1 else 0
    println(res)
}